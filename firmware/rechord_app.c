/*
 * rechord_app.c — ReChord V0.15: stock-mirror boot + UI-event draw hooks.
 *
 * THE V0.15 FIX (root cause of V0.1-V0.14 "nothing custom ever shows"):
 * the stock firmware_entry @ 0x03000010 is an HW-init callback that
 * RETURNS to the ROM. Ghidra disasm of stock:
 *     push {r4,lr}; mov r4,r0; bl boot_param_layout; rom_alloc(0x1dc);
 *     [rom_hw_init(0x1dc/0x16f/0x16f) rom_hw_init2(0x171) rom_hw_init(0x170)]
 *     rom_early_init(); ldrh r0,[r4]; cmp r0,#0xb;
 *     pop {r4,lr}; movw r0,#0x18f; b.w rom_hw_init2      <- early path
 *     pop {r4,lr}; movw r0,#0x191; b.w rom_hw_init2      <- app path
 * Our V0.1-V0.14 entries did `b rechord_app` -> infinite loop -> the ROM
 * boot sequence stalled -> cassette stays, no text, no app, ~23s poweroff.
 *
 * V0.15: entry_stubs.S mirrors stock (pop {r4,lr}; b.w rom_hw_init2), so
 * rechord_firmware_entry() below is the C body: it runs the EXACT stock
 * init sequence and returns the rom_hw_init2 code (0x18f/0x191) that the
 * assembly tail-calls. Control returns to the ROM inside rom_hw_init2,
 * exactly like stock.
 *
 * rechord_ui_event() = the draw test, called from the application_start
 * stub (0x0300710a) whenever the ROM dispatches UI events. It paints the
 * screen through the loader's OWN display sequence (the one sec2 uses to
 * draw the cassette — disassembled from sec2 FUN_03000258):
 *     fef124(0x19b) wait-ready -> fea848(1)/fea824(2) save ctx ->
 *     feb0f6(color) -> fea8f4(x,y,w,h,a5,a6) rect -> feabea(1) refresh ->
 *     fea848(saved)/fea824(saved) restore ctx
 * NOTE: fea8f4 takes SIX args (r0=x,r1=y,r2=w,r3=h,sp+0=a5,sp+4=a6) — the
 * V0.10 packed-2-arg and V0.14 4-arg calls were wrong. The known-good
 * top-bar rect is (0,3,320,16,2,0x58).
 */
#include <stdint.h>
#include <stddef.h>

/* ---- ROM display services (the loader's draw sequence) ---- */
typedef uint32_t (*rom_ready_fn)(uint32_t);
typedef uint32_t (*rom_ctx_fn)(uint32_t);
typedef void (*rom_color_fn)(uint32_t);
typedef void (*rom_rect_fn)(uint32_t, uint32_t, uint32_t, uint32_t,
                            uint32_t, uint32_t);
typedef void (*rom_refresh_fn)(uint32_t);

#define ROM_DISP_WAIT   ((rom_ready_fn)(0x02fef124 | 1))  /* wait ready(code) -> 0 if ok */
#define ROM_DISP_CTX_A  ((rom_ctx_fn)(0x02fea848 | 1))    /* save/set A -> prev */
#define ROM_DISP_CTX_B  ((rom_ctx_fn)(0x02fea824 | 1))    /* save/set B -> prev */
#define ROM_DISP_COLOR  ((rom_color_fn)(0x02feb0f6 | 1))  /* set fill color */
#define ROM_DISP_RECT   ((rom_rect_fn)(0x02fea8f4 | 1))   /* fill rect(x,y,w,h,a5,a6) */
#define ROM_DISP_REFRESH ((rom_refresh_fn)(0x02feabea | 1)) /* refresh(1) */

/* ---- ROM HW services used by the stock firmware_entry mirror ---- */
#define ROM_ALLOC       ((void *(*)(uint32_t))0x02feeedc)  /* rom_alloc */
#define ROM_HW_INIT     ((void (*)(uint32_t))0x02feeebe)   /* rom_hw_init */
#define ROM_HW_INIT2    ((void (*)(uint32_t))0x02feee7c)   /* rom_hw_init2 */
#define ROM_EARLY_INIT  ((void (*)(void))0x02fe860e)       /* rom_early_init */

/* ---- telemetry RAM (inside our .text.boot padding; see entry_stubs.S) ---- */
#define crash_log ((volatile uint32_t *)0x03000100u)   /* fault.c crash log */
#define CRASH_MAGIC 0x52454348u
#define boot_log  ((volatile uint32_t *)0x03000118u)   /* boot markers */
#define BOOT_DONE 0xfeed0002u

/*
 * rechord_firmware_entry — C body of the stock firmware_entry mirror.
 * Called from entry_stubs.S with the boot params in r0; returns the
 * rom_hw_init2 code (0x18f or 0x191) that the assembly tail-calls so
 * control returns to the ROM exactly like stock.
 */
uint32_t rechord_firmware_entry(void *param)
{
    uint16_t *bp = (uint16_t *)param;
    volatile uint8_t  *lay = (volatile uint8_t *)0x03000164u;  /* boot layout */
    volatile uint16_t *bmode = (volatile uint16_t *)0x03000168u;
    uint16_t mode;
    uint32_t m, cols, pad;
    void *ctx;

    /* telemetry: firmware_entry was reached, with the boot params ptr */
    boot_log[0] = 0x424F4F54u;              /* 'BOOT' */
    boot_log[1] = (uint32_t)(uintptr_t)param;

    /* ---- boot_param_layout(param) — exact stock behavior ---- */
    *lay = 8;                               /* +0 base */
    mode = 0;
    switch (*bp) { case 0: case 1: case 2: case 3: case 4: case 5:
                   case 8: case 10: mode = *bp; }
    *bmode = mode;                          /* ushort @0x03000168 */
    mode = 0;
    switch (*bp) { case 0: case 1: case 2: case 3: case 4: case 5:
                   case 8: case 10: mode = *bp; }
    lay[5] = (uint8_t)mode;                 /* +5 mode_clamped */
    if (mode > 0x0c) lay[5] = 0x0d;
    if (*bmode > 0x0c) *bmode = 0x0d;
    m = lay[5];
    cols = ((m / 6) * 3 & 0x7f) * 2;
    lay[1] = (uint8_t)cols;                 /* +1 cols */
    if (m <= cols && cols - m != 0) { cols -= 6; lay[1] = (uint8_t)cols; }
    lay[2] = (uint8_t)(lay[5] - (uint8_t)cols);  /* +2 rem */
    pad = 8 - (cols & 0xff);
    if (pad > 6) pad = 6;
    lay[4] = (uint8_t)pad;                  /* +4 pad */
    lay[3] = 0;                             /* +3 zero */

    /* ---- rom_alloc(0x1dc) + rom_hw_init sequence (exact stock) ---- */
    ctx = ROM_ALLOC(0x1dc);
    if (ctx == NULL) {
        ROM_HW_INIT2(0x16f);
    } else {
        ROM_HW_INIT(0x1dc);
        ROM_HW_INIT(0x16f);
        ROM_HW_INIT(0x16f);
        ROM_HW_INIT2(0x171);
        ROM_HW_INIT(0x170);
    }
    ROM_EARLY_INIT();

    boot_log[2] = BOOT_DONE;                /* boot init complete */

    /* mode check: return the code entry_stubs.S must tail-call */
    return (*bp != 0x0b) ? 0x18f : 0x191;
}

/*
 * rechord_ui_event — draw test, called from the application_start stub
 * (0x0300710a) whenever the ROM dispatches UI events. Paints the screen
 * through the loader's OWN display sequence; the full screen alternates
 * red/blue per call (liveness) with a white top status bar over it. If a
 * crash was logged by fault.c, holds a stable PC-derived color instead.
 */
void rechord_ui_event(void)
{
    static uint32_t calls = 0;
    uint32_t n = calls++;
    uint32_t color;
    uint32_t ctx_a, ctx_b;

    /* don't draw before our boot init completes */
    if (boot_log[2] != BOOT_DONE)
        return;

    boot_log[3] = n;                        /* telemetry: call count */

    /* wait for the display to be ready, like the loader; bail if not */
    if (ROM_DISP_WAIT(0x19b) != 0)
        return;

    /* save display context, exactly like the loader */
    ctx_a = ROM_DISP_CTX_A(1);
    ctx_b = ROM_DISP_CTX_B(2);

    /* crash telemetry: if a fault was logged, hold a stable PC color */
    if (crash_log[0] == CRASH_MAGIC) {
        uint32_t pc = crash_log[1];
        color = (uint16_t)(((pc >> 16) & 0xF8) << 8) |
                (uint16_t)(((pc >> 8) & 0xFC) << 3) |
                (uint16_t)((pc >> 3) & 0x1F);
        crash_log[0] = 0;                   /* consumed */
    } else {
        color = (n & 1) ? 0x001F : 0xF800;  /* blue / red alternating */
    }

    ROM_DISP_COLOR(color);
    ROM_DISP_RECT(0, 0, 320, 170, 2, 0x58);        /* full screen */
    ROM_DISP_COLOR(0xFFFF);
    ROM_DISP_RECT(0, 3, 320, 16, 2, 0x58);         /* white top bar (known-good) */
    ROM_DISP_REFRESH(1);

    /* restore display context, exactly like the loader */
    ROM_DISP_CTX_A(ctx_a);
    ROM_DISP_CTX_B(ctx_b);
}
