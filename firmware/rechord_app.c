/*
 * rechord_app.c — ReChord V0.8: ROM-based display test + ReChord app start.
 *
 * Strategy (see docs/bootloader-analysis.md): the chip ROM at
 * 0x02FE0000-0x03000000 provides ALL hardware services (init, LCD, DMA,
 * keys, audio). The stock section_3 app just calls them. So our compiled
 * C firmware can be a thin app over the ROM:
 *
 *   1. rom_hw_init / rom_early_init  — hardware init (codes mirror stock
 *      firmware_entry @ 0x03000010).
 *   2. Draw into the LCD framebuffer 0x03024868 (320x100 RGB565, DMA
 *      source; confirmed via memory-map entry 0x0478 + LCD struct
 *      0x030247ac with buffer pointers at +0x74/+0x78).
 *   3. Trigger the LCD refresh via ROM service 0x02ff05f0(0x172)
 *      (this is what the stock ui_post_redraw does).
 *   4. Loop: read keys (0x02ff813a) + keep refreshing.
 *
 * V0.8 goal: PROVE our compiled C runs on the device AND the display
 * path works — the screen must show a red/green/blue ReChord pattern.
 * No SDK, no Main2, no BSP_Init2 (which may hang) — pure ROM calls.
 */
#include <stdint.h>

/* ---- ROM service entry points (Thumb: |1 for indirect calls) ---- */
typedef void (*rom_fn1)(uint32_t);
typedef int  (*rom_fn0)(void);

#define ROM_HW_INIT     ((rom_fn1)(0x02feeebe | 1))  /* rom_hw_init(code)    */
#define ROM_HW_INIT2    ((rom_fn1)(0x02feee7c | 1))  /* rom_hw_init2(code)   */
#define ROM_EARLY_INIT  ((rom_fn1)(0x02fe860e | 1))  /* rom_early_init()     */
#define ROM_UI_REFRESH  ((rom_fn1)(0x02ff05f0 | 1))  /* service(code)        */
#define ROM_GET_INPUT   ((rom_fn0)(0x02ff813a | 1))  /* rom_get_input_event()*/

#define FB       ((volatile uint16_t *)0x03024868)
#define FB_WORDS (0xfb20 / 2)              /* 64,288 bytes / 2 = 32,144 */
#define WIDTH    320
#define HEIGHT   100

static void hw_init(void)
{
    /* Mirror the stock firmware_entry main path (rom_alloc != 0 branch):
     *   rom_hw_init(0x1dc); rom_hw_init(0x16f); rom_hw_init(0x16f);
     *   rom_hw_init2(0x171); rom_hw_init(0x170); rom_early_init();
     * NOTE: stock calls rom_alloc(0x1dc) first and branches; we take the
     * "alloc ok" branch directly. */
    ROM_HW_INIT(0x1dc);
    ROM_HW_INIT(0x16f);
    ROM_HW_INIT(0x16f);
    ROM_HW_INIT2(0x171);
    ROM_HW_INIT(0x170);
    ROM_EARLY_INIT(0);
}

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

    hw_init();

    draw_pattern();
    ROM_UI_REFRESH(0x172);       /* push pattern to the LCD */

    for (;;) {
        int key = ROM_GET_INPUT();
        (void)key;
        /* blink the centre pixel as a liveness proof */
        FB[WIDTH * (HEIGHT / 2) + WIDTH / 2] ^= 0xFFFF;
        ROM_UI_REFRESH(0x172);
        {
            volatile uint32_t d;
            for (d = 0; d < 400000; d++)
                ;
        }
    }
}
