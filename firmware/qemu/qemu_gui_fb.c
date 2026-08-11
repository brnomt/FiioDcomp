/* ReChord GUI dev harness — framebuffer-in-RAM renderer.
 * Draws into RAM at 0x20000000 (lm3s6965evb). A Python script reads
 * it via QEMU monitor and renders to an image.
 */
#define FB_ADDR   0x20000000u
#define FB_W      128
#define FB_H      64

static void uart_putc(char c) {
    volatile unsigned int *dr = (volatile unsigned int *)0x4000C000u;
    volatile unsigned int *fr = (volatile unsigned int *)(0x4000C000u + 0x18);
    while (*fr & (1 << 5)) ;
    *dr = c;
}

static void fb_px(int x, int y, unsigned int color) {
    volatile unsigned short *fb = (volatile unsigned short *)FB_ADDR;
    if (x < 0 || x >= FB_W || y < 0 || y >= FB_H) return;
    fb[y * FB_W + x] = (unsigned short)color;
}
static void fb_rect(int x0, int y0, int x1, int y1, unsigned int color) {
    for (int y = y0; y < y1; y++)
        for (int x = x0; x < x1; x++)
            fb_px(x, y, color);
}
static const unsigned char font3x5[16] = {
    0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E, 0x00,
    0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E, 0x00,
};
static void fb_text(int x, int y, const char *s, unsigned int color) {
    while (*s) {
        unsigned char ch = (unsigned char)*s;
        if (ch >= '0' && ch <= '9') {
            unsigned char pat = font3x5[ch - '0'];
            for (int b = 0; b < 5; b++)
                if (pat & (1 << b))
                    fb_px(x, y + b, color);
        }
        x += 4; s++;
    }
}
void _start(void)
{
    uart_putc('R');

    fb_rect(0, 0, FB_W, FB_H, 0x0000);
    fb_rect(4, 4, 60, 60, 0xF800);
    fb_rect(64, 4, 124, 60, 0x07E0);
    fb_text(8, 30, "RCH", 0xFFFF);
    for (;;) ;
}
void _default_handler(void) { for (;;) ; }
__attribute__((section(".vectors")))
const unsigned int vector_table[8] = {
    0x2000FC00, (unsigned int)_start,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, (unsigned int)_default_handler,
    (unsigned int)_default_handler, 0,
};
