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

    __asm volatile("cpsid i" ::: "memory");   /* disable IRQ */

    fb_clear(0x0000);                  /* black background */
    fb_text(8,  8,  "RECHORD FAULT", 0xFFFF);
    fb_text(8,  24, "VEC=", 0xFFFF);   fb_num(56, 24, vect, 0xFFFF);
    fb_text(8,  40, "PC=", 0xFFFF);    fb_hex32(48, 40, pc, 0xFFE0);
    fb_text(8,  56, "CFSR=", 0xFFFF);  fb_hex32(64, 56, cfsr, 0x07FF);

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
