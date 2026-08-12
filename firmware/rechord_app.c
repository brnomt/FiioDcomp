/*
 * rechord_app.c — ReChord V0.9: minimal C app, no ROM init.
 *
 * V0.8 (ROM hw_init mirror) showed nothing — the hw_init ROM calls may
 * hang or the refresh expects app state. V0.9 tests a different theory:
 *
 *   The loader (sec2) ALREADY initialised the hardware (clocks, LCD,
 *   DMA) to draw the cassette screen before jumping to our
 *   firmware_entry. So we need NO init — just write the framebuffer
 *   (0x03024868) and trigger the refresh.
 *
 * Plus: entry_stubs.S now places trampolines at the ROM/loader dispatch
 * offsets (0x162/0x16c/0x24e/0x296/0x4f4/0x546/0xa72/0xa74/0xaba/0x710a)
 * which our earlier builds left as garbage -> the menu-press freeze.
 *
 * Display path (from Ghidra):
 *   - framebuffer 0x03024868 (64,288 B, 320x100 RGB565 DMA source)
 *   - refresh candidates:
 *       A) ROM service 0x02ff05f0(0x172)   (= stock ui_post_redraw)
 *       B) ROM 0x02feabea(1)               (= loader boot-screen refresh)
 *   We call both (belt and suspenders).
 */
#include <stdint.h>

/* ---- ROM service entry points (Thumb: |1 for indirect calls) ---- */
typedef void (*rom_fn1)(uint32_t);
typedef int  (*rom_fn0)(void);

#define ROM_UI_REFRESH  ((rom_fn1)(0x02ff05f0 | 1))  /* service(code)        */
#define ROM_LOADER_REFR ((rom_fn1)(0x02feabea | 1))  /* loader refresh(arg)  */
#define ROM_GET_INPUT   ((rom_fn0)(0x02ff813a | 1))  /* rom_get_input_event()*/

#define FB       ((volatile uint16_t *)0x03024868)
#define FB_WORDS (0xfb20 / 2)
#define WIDTH    320
#define HEIGHT   100

static void draw_pattern(void)
{
    uint32_t i;
    /* ReChord test pattern: top third red, middle green, bottom blue. */
    for (i = 0; i < FB_WORDS; i++) {
        FB[i] = (i < FB_WORDS / 3) ? 0xF800 :
                (i < 2 * FB_WORDS / 3) ? 0x07E0 : 0x001F;
    }
}

void rechord_app(void *boot_params)
{
    (void)boot_params;

    draw_pattern();
    ROM_UI_REFRESH(0x172);       /* push pattern to the LCD (candidate A) */
    ROM_LOADER_REFR(1);          /* loader-style refresh (candidate B)     */

    for (;;) {
        int key = ROM_GET_INPUT();
        (void)key;
        /* blink the centre pixel as a liveness proof */
        FB[WIDTH * (HEIGHT / 2) + WIDTH / 2] ^= 0xFFFF;
        ROM_UI_REFRESH(0x172);
        ROM_LOADER_REFR(1);
        {
            volatile uint32_t d;
            for (d = 0; d < 400000; d++)
                ;
        }
    }
}
