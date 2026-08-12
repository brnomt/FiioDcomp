/*
 * ReChord fault handler — real replacement for the stubbed
 * __CPU_IntDefaultHandler2 (which was a zeroed VARIABLE before).
 *
 * The SDK vector table (exceptions_table2 in bb_vect) routes every
 * core fault (NMI, HardFault, MemManage, BusFault, UsageFault) to
 * IntDefaultHandler2, which does `b __CPU_IntDefaultHandler2`.
 *
 * The Echo Mini LCD displays the UI framebuffer at 0x03024868 by
 * hardware/DMA (Lcd_BuferTranfer is #ifdef _FRAME_BUFFER_), so we can
 * render the fault info straight into that buffer and the user sees it.
 *
 * Render: RECHORD FAULT / VEC=nn / PC=0xXXXXXXXX / CFSR=0xXXXXXXXX
 * Then loop forever (no reset, no power-off) so the address can be read.
 */
#include <stdint.h>

#define FB_ADDR      (0x03024868u)
#define FB_BYTES     (0xFB20u)        /* 64,288 from segment table */
#define FB_WORDS     (FB_BYTES / 2)
#define LCD_W        320
#define LCD_H        100              /* visible area (estimate) */

#define ICSR         (*(volatile uint32_t *)0xE000ED04u)  /* VECTACTIVE bits 0..8 */
#define CFSR         (*(volatile uint32_t *)0xE000ED28u)  /* fault status */

/* ---- ReChord crash telemetry buffer ----
 * Fixed address 0x03000100 = zero padding in our entry_stubs.S (between
 * firmware_entry @ 0x10 and stub_03000162 @ 0x162). It is inside our
 * own code region (always loaded to RAM) and never written by the
 * stock app. Written by the fault handler on any hard fault; read by
 * rechord_app at the next boot (if the device watchdog-resets).
 * magic = 'RECH'. */
#define CRASH_LOG_ADDR 0x03000100u
#define crash_log      ((volatile uint32_t *)CRASH_LOG_ADDR)
#define CRASH_MAGIC    0x52454348u  /* 'RECH' */

static void crash_trigger_refresh(void)
{
    /* call the loader's LCD refresh (ROM 0x02feabea) so the fault text
     * MAY become visible even though the DMA framebuffer path is not
     * our display. Thumb indirect call. */
    typedef void (*fn)(uint32_t);
    ((fn)(0x02feabea | 1))(1);
}

/* ---- loader display API (the one that actually draws the menu) ---- */
typedef void (*rom_rect_fn)(uint32_t, uint32_t, uint32_t, uint32_t);
typedef void (*rom_fn1)(uint32_t);
#define ROM_DISP_COLOR  ((rom_fn1)(0x02feb0f6 | 1))   /* set fill colour   */
#define ROM_DISP_RECT   ((rom_rect_fn)(0x02fea8f4 | 1)) /* fill rect(x,y,w,h)*/
#define ROM_DISP_REFR   ((rom_fn1)(0x02feabea | 1))   /* refresh(1)         */

/* 16-colour palette (RGB565) chosen to be distinguishable by eye. */
static const uint16_t crash_palette[16] = {
    0x0000, 0xF800, 0x07E0, 0x001F,  /* 0 black 1 red 2 green 3 blue      */
    0xFFE0, 0x07FF, 0xF81F, 0xFFFF,  /* 4 yellow 5 cyan 6 magenta 7 white */
    0x7BEF, 0xFD20, 0x9FE0, 0x57FF,  /* 8 grey 9 orange A lime B sky      */
    0xFDFF, 0x8A20, 0x7FE0, 0x39E7,  /* C pink D brown E olive F dkgrey   */
};

/* Blink the whole screen through the loader's OWN draw sequence
 * (feb0f6 colour -> fea8f4 rect -> feabea refresh) — the one display
 * path we KNOW works (the loader draws the menu with it). If the user
 * sees blinking colours, we can encode the PC in the pattern. */
static void crash_blink_colours(void)
{
    volatile uint32_t d;
    int rep;
    for (rep = 0; rep < 12; rep++) {
        ROM_DISP_COLOR(rep & 0xF);
        ROM_DISP_RECT(0, 0, 320, 170);
        ROM_DISP_REFR(1);
        for (d = 0; d < 1500000; d++)
            ;
    }
}

/* Paint the 32-bit value as 8 vertical colour strips (one hex digit
 * each) into the framebuffer with our own RGB565 palette, then ask the
 * loader's refresh to push it. If the framebuffer is what the LCD
 * scans (or feabea transfers it), the user reads the strip colours
 * L->R and reports them; we decode the hex digits back to the value. */
static void crash_paint_strips(uint32_t value)
{
    int i, y;
    volatile uint16_t *fb = (volatile uint16_t *)FB_ADDR;
    for (i = 0; i < 8; i++) {
        uint32_t nib = (value >> (28 - i * 4)) & 0xF;
        uint16_t col = crash_palette[nib];
        for (y = 0; y < LCD_H; y++) {
            int x;
            for (x = i * 40; x < (i + 1) * 40; x++)
                fb[y * LCD_W + x] = col;
        }
    }
    crash_trigger_refresh();
}

/* ---- 5x7 font for hex digits ---- */
static const uint8_t font_hex[16][7] = {
    {0x0E,0x11,0x13,0x15,0x19,0x11,0x0E}, /* 0 */
    {0x04,0x0C,0x04,0x04,0x04,0x04,0x0E}, /* 1 */
    {0x0E,0x11,0x01,0x02,0x04,0x08,0x1F}, /* 2 */
    {0x1F,0x02,0x04,0x02,0x01,0x11,0x0E}, /* 3 */
    {0x02,0x06,0x0A,0x12,0x1F,0x02,0x02}, /* 4 */
    {0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E}, /* 5 */
    {0x06,0x08,0x10,0x1E,0x11,0x11,0x0E}, /* 6 */
    {0x1F,0x01,0x02,0x04,0x08,0x08,0x08}, /* 7 */
    {0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E}, /* 8 */
    {0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C}, /* 9 */
    {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11}, /* A */
    {0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E}, /* B */
    {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E}, /* C */
    {0x1C,0x12,0x11,0x11,0x11,0x12,0x1C}, /* D */
    {0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F}, /* E */
    {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10}, /* F */
};

static void fb_px(int x, int y, uint16_t color)
{
    volatile uint16_t *fb = (volatile uint16_t *)FB_ADDR;
    if (x < 0 || x >= LCD_W || y < 0 || y >= LCD_H)
        return;
    fb[y * LCD_W + x] = color;
}

static void fb_clear(uint16_t color)
{
    volatile uint16_t *fb = (volatile uint16_t *)FB_ADDR;
    for (int i = 0; i < FB_WORDS; i++)
        fb[i] = color;
}

static void fb_char(int x, int y, char c, uint16_t color)
{
    uint8_t idx;
    if (c >= '0' && c <= '9')      idx = (uint8_t)(c - '0');
    else if (c >= 'A' && c <= 'F') idx = (uint8_t)(c - 'A' + 10);
    else return;
    for (int r = 0; r < 7; r++) {
        uint8_t row = font_hex[idx][r];
        for (int cc = 0; cc < 5; cc++) {
            if (row & (0x10 >> cc))
                fb_px(x + cc, y + r, color);
        }
    }
}

static void fb_text(int x, int y, const char *s, uint16_t color)
{
    while (*s) {
        fb_char(x, y, *s, color);
        x += 6;
        s++;
    }
}

static void fb_hex32(int x, int y, uint32_t v, uint16_t color)
{
    char buf[11];
    buf[0] = '0'; buf[1] = 'x';
    for (int i = 0; i < 8; i++) {
        uint8_t nib = (uint8_t)((v >> (28 - i * 4)) & 0xF);
        buf[2 + i] = (nib < 10) ? (char)('0' + nib) : (char)('A' + nib - 10);
    }
    buf[10] = 0;
    fb_text(x, y, buf, color);
}

static void fb_num(int x, int y, uint32_t v, uint16_t color)
{
    char buf[12];
    int i = 0;
    do {
        buf[i++] = (char)('0' + (v % 10));
        v /= 10;
    } while (v);
    /* reverse */
    for (int j = 0; j < i / 2; j++) {
        char t = buf[j]; buf[j] = buf[i - 1 - j]; buf[i - 1 - j] = t;
    }
    buf[i] = 0;
    fb_text(x, y, buf, color);
}

/* C entry: sp = fault stack frame, pc = faulting PC */
void FaultHandlerC(uint32_t sp, uint32_t pc)
{
    uint32_t vect = ICSR & 0x1FF;      /* VECTACTIVE: 3=HardFault 4=Mem 5=Bus 6=Usage */
    uint32_t cfsr = CFSR;
    uint32_t lr;

    __asm volatile("cpsid i" ::: "memory");   /* disable IRQ */

    /* --- crash telemetry: save to our own RAM buffer (survives a
     *     watchdog reset; read back by rechord_app on next boot) --- */
    __asm volatile("mov %0, lr" : "=r"(lr));
    crash_log[0] = CRASH_MAGIC;
    crash_log[1] = pc;
    crash_log[2] = lr;
    crash_log[3] = cfsr;
    crash_log[4] = sp;
    crash_log[5] = vect;

    fb_clear(0x0000);                  /* black background */
    fb_text(8,  8,  "RECHORD FAULT", 0xFFFF);
    fb_text(8,  24, "VEC=", 0xFFFF);   fb_num(56, 24, vect, 0xFFFF);
    fb_text(8,  40, "PC=", 0xFFFF);    fb_hex32(48, 40, pc, 0xFFE0);
    fb_text(8,  56, "CFSR=", 0xFFFF);  fb_hex32(64, 56, cfsr, 0x07FF);
    fb_text(8,  72, "SP=", 0xFFFF);    fb_hex32(48, 72, sp, 0x07FF);

    /* attempt to push the fault frame to the LCD via the loader's
     * refresh (the plain framebuffer may not be what the LCD scans) */
    crash_trigger_refresh();

    /* paint the PC as 8 colour strips via the loader's display API */
    crash_paint_strips(pc);
    crash_trigger_refresh();

    /* try the loader's own draw sequence (feb0f6 + fea8f4 + feabea) —
     * the display path that actually works on this device */
    crash_blink_colours();

    /* bonus: overwrite the displayed "Software:3.7.0" version string
     * (RAM copy @ 0x0301506C) with the PC so that IF any later build
     * shows the About screen, the PC is there. */
    {
        static const char hexd[] = "0123456789ABCDEF";
        volatile char *s = (volatile char *)0x0301506Cu;
        int i;
        s[0] = 'P'; s[1] = 'C'; s[2] = '='; s[3] = '0'; s[4] = 'x';
        for (i = 0; i < 8; i++) {
            uint32_t nib = (pc >> (28 - i * 4)) & 0xF;
            s[5 + i] = hexd[nib];
        }
    }

    for (;;)
        ;
}

/* naked trampoline: read PC from the Cortex-M3 exception frame.
 * Hardware-stacked frame at SP: R0 R1 R2 R3 R12 LR PC xPSR -> PC at +24. */
__attribute__((naked)) void __CPU_IntDefaultHandler2(void)
{
    __asm__ volatile(
        "mov r0, sp\n"
        "ldr r1, [r0, #24]\n"
        "b FaultHandlerC\n");
}
