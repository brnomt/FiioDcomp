/*
 * rechord_app.c — ReChord V0.10: EXACT loader display sequence.
 *
 * The loader (sec2) draws the cassette via ROM functions:
 *   func_0x02fef124(0x19b, ...)   wait for display ready
 *   func_0x02fea848(1)            lock display context
 *   func_0x02feb0f6(color)        set fill color
 *   func_0x02fea8f4(x,y,w,h)      fill rect
 *   func_0x02feabea(1)            refresh LCD
 *   func_0x02fea824(2)            unlock display context
 *
 * V0.10 calls EXACTLY that to fill the whole 320x100 screen with the
 * loader's status-bar color. If the screen changes -> our compiled C
 * runs AND the display path works. Then we know how to draw.
 */
#include <stdint.h>

/* ---- ROM service entry points (Thumb: |1 for indirect calls) ---- */
typedef void (*rom_fn2)(uint32_t, uint32_t);
typedef void (*rom_fn1)(uint32_t);
typedef int  (*rom_fn0)(void);

#define ROM_DISP_WAIT   ((rom_fn2)(0x02fef124 | 1))  /* wait/check(code,arg)*/
#define ROM_DISP_LOCK   ((rom_fn1)(0x02fea848 | 1))  /* lock(1)             */
#define ROM_DISP_COLOR  ((rom_fn1)(0x02feb0f6 | 1))  /* set color(code)     */
#define ROM_DISP_RECT   ((rom_fn2)(0x02fea8f4 | 1))  /* fill rect(x+y<<16?) */
#define ROM_DISP_REFRESH ((rom_fn1)(0x02feabea | 1))  /* refresh(1)          */
#define ROM_DISP_UNLOCK ((rom_fn1)(0x02fea824 | 1))  /* unlock(2)           */

#define FB       ((volatile uint16_t *)0x03024868)
#define FB_WORDS (0xfb20 / 2)

/* rect is (x, y, w, h): call as two packed args like the loader does */
static void fill_rect(int x, int y, int w, int h)
{
    ROM_DISP_RECT((uint32_t)((y << 16) | (x & 0xFFFF)),
                  (uint32_t)((h << 16) | (w & 0xFFFF)));
}

/* ---- ReChord crash telemetry (filled by fault.c on any hard fault) ---- */
#define crash_log ((volatile uint32_t *)0x03000100u)
#define CRASH_MAGIC 0x52454348u  /* 'RECH' */

static void paint_crash_color(void)
{
    /* Paint the framebuffer with a colour derived from the crash PC so
     * it can be read even if the fault text render is not visible.
     * Colour = RGB565 made from (pc>>16), (pc>>8), pc. */
    uint32_t pc = crash_log[1];
    uint16_t color = (uint16_t)(((pc >> 16) & 0xF8) << 8) |
                     (uint16_t)(((pc >> 8) & 0xFC) << 3) |
                     (uint16_t)((pc >> 3) & 0x1F);
    uint32_t i;
    for (i = 0; i < FB_WORDS; i++)
        FB[i] = color;
    ROM_DISP_REFRESH(1);
    ROM_DISP_REFRESH(1);
}

void rechord_app(void *boot_params)
{
    (void)boot_params;

    /* If a crash was recorded, show its PC colour first (then keep it
     * on screen) so the user can read it off. */
    if (crash_log[0] == CRASH_MAGIC) {
        paint_crash_color();
        crash_log[0] = 0;   /* consumed */
        for (;;) {
            volatile uint32_t d;
            for (d = 0; d < 2000000; d++)
                ;
            ROM_DISP_REFRESH(1);
            ROM_DISP_REFRESH(1);
        }
    }

    /* --- replicate the loader's display sequence exactly --- */
    ROM_DISP_WAIT(0x19b, 0xbd706008);
    ROM_DISP_LOCK(1);
    ROM_DISP_COLOR(0x94);          /* loader's top-bar color             */
    fill_rect(0, 0, 320, 100);     /* fill the WHOLE screen              */
    ROM_DISP_REFRESH(1);
    ROM_DISP_UNLOCK(2);

    for (;;) {
        /* blink the top bar color code between two values (liveness) */
        ROM_DISP_LOCK(1);
        ROM_DISP_COLOR(0x94);
        fill_rect(0, 0, 320, 50);
        ROM_DISP_COLOR(0x95);
        fill_rect(0, 50, 320, 50);
        ROM_DISP_REFRESH(1);
        ROM_DISP_UNLOCK(2);
        {
            volatile uint32_t d;
            for (d = 0; d < 2000000; d++)
                ;
        }
    }
}
