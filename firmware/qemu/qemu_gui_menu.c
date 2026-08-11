/* ReChord GUI dev — framebuffer menu renderer for QEMU lm3s6965evb.
 * Draws a mini ReChord menu (like the future device UI) into RAM fb
 * at 0x20000000. Python reads it via QEMU monitor -> PNG.
 * 128x64 logical, 2x upscaled. Simulates: title bar, menu items,
 * selection cursor, status bar.
 */
#define FB_ADDR 0x20000000u
#define FB_W 128
#define FB_H 64

/* RGB565 helpers */
#define C_BLACK   0x0000
#define C_WHITE   0xFFFF
#define C_RED     0xF800
#define C_GREEN   0x07E0
#define C_BLUE    0x001F
#define C_YELLOW  0xFFE0
#define C_CYAN    0x07FF
#define C_GRAY    0x8410
#define C_DKGRAY  0x4208

static void fb_px(int x, int y, unsigned short c) {
    volatile unsigned short *fb = (volatile unsigned short *)FB_ADDR;
    if (x < 0 || x >= FB_W || y < 0 || y >= FB_H) return;
    fb[y * FB_W + x] = c;
}
static void fb_rect(int x0, int y0, int x1, int y1, unsigned short c) {
    for (int y = y0; y < y1 && y < FB_H; y++)
        for (int x = x0; x < x1 && x < FB_W; x++)
            fb_px(x, y, c);
}

/* 5x7 font: only chars we need (letters, digits, basic punct) */
static unsigned char font[128][7] = {0};
static void init_font(void) {
    /* A B C D E F G H I J K L M N O P Q R S T U V W X Y Z */
    const unsigned char glyphs[26][7] = {
        {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11}, /* A */
        {0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E}, /* B */
        {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E}, /* C */
        {0x1C,0x12,0x11,0x11,0x11,0x12,0x1C}, /* D */
        {0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F}, /* E */
        {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10}, /* F */
        {0x0E,0x11,0x10,0x17,0x11,0x11,0x0F}, /* G */
        {0x11,0x11,0x11,0x1F,0x11,0x11,0x11}, /* H */
        {0x0E,0x04,0x04,0x04,0x04,0x04,0x0E}, /* I */
        {0x07,0x02,0x02,0x02,0x02,0x12,0x0C}, /* J */
        {0x11,0x12,0x14,0x18,0x14,0x12,0x11}, /* K */
        {0x10,0x10,0x10,0x10,0x10,0x10,0x1F}, /* L */
        {0x11,0x1B,0x15,0x15,0x11,0x11,0x11}, /* M */
        {0x11,0x19,0x15,0x13,0x11,0x11,0x11}, /* N */
        {0x0E,0x11,0x11,0x11,0x11,0x11,0x0E}, /* O */
        {0x1E,0x11,0x11,0x1E,0x10,0x10,0x10}, /* P */
        {0x0E,0x11,0x11,0x11,0x15,0x12,0x0D}, /* Q */
        {0x1E,0x11,0x11,0x1E,0x14,0x12,0x11}, /* R */
        {0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E}, /* S */
        {0x1F,0x04,0x04,0x04,0x04,0x04,0x04}, /* T */
        {0x11,0x11,0x11,0x11,0x11,0x11,0x0E}, /* U */
        {0x11,0x11,0x11,0x11,0x11,0x0A,0x04}, /* V */
        {0x11,0x11,0x11,0x15,0x15,0x1B,0x11}, /* W */
        {0x11,0x11,0x0A,0x04,0x0A,0x11,0x11}, /* X */
        {0x11,0x11,0x0A,0x04,0x04,0x04,0x04}, /* Y */
        {0x1F,0x01,0x02,0x04,0x08,0x10,0x1F}, /* Z */
    };
    for (int i = 0; i < 26; i++)
        for (int r = 0; r < 7; r++)
            font['A'+i][r] = glyphs[i][r];
    /* digits 0-9 */
    const unsigned char digits[10][7] = {
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
    };
    for (int i = 0; i < 10; i++)
        for (int r = 0; r < 7; r++)
            font['0'+i][r] = digits[i][r];
    /* common punct: space=0, . : - > */
    font[' '][0] = 0;
    font['.'][0] = 0x06; /* minimal */
    font[':'][0] = 0x0A; font[':'][1] = 0x00; font[':'][2] = 0x0A;
    font['-'][0] = 0x1F; font['-'][1] = 0x00;
    font['>'][0] = 0x02; font['>'][1] = 0x04; font['>'][2] = 0x08; font['>'][3] = 0x04; font['>'][4] = 0x02;
}

static void fb_char(int x, int y, char c, unsigned short fg) {
    unsigned char pat;
    if (c == ' ') return;
    if ((unsigned char)c >= 128) return;
    pat = font[(unsigned char)c][0];
    if (pat == 0 && c != ' ') return;  /* unset glyph */
    for (int r = 0; r < 7; r++) {
        unsigned char row = font[(unsigned char)c][r];
        for (int cc = 0; cc < 5; cc++)
            if (row & (0x10 >> cc))
                fb_px(x+cc, y+r, fg);
    }
}
static void fb_text(int x, int y, const char *s, unsigned short fg) {
    while (*s) { fb_char(x, y, *s, fg); x += 6; s++; }
}

void *memcpy(void *d, const void *s, unsigned int n) {
    unsigned char *dd = d; const unsigned char *ss = s;
    while (n--) *dd++ = *ss++;
    return d;
}
void _start(void)
{
    init_font();

    /* background */
    fb_rect(0, 0, FB_W, FB_H, C_BLACK);

    /* title bar */
    fb_rect(0, 0, FB_W, 10, C_BLUE);
    fb_text(40, 2, "ReChord", C_WHITE);

    /* menu items with cursor on item 2 */
    const char *items[4] = {"Music", "EQ", "Settings", "About"};
    for (int i = 0; i < 4; i++) {
        int y = 16 + i * 11;
        if (i == 2) {
            fb_rect(2, y-1, FB_W-2, y+7, C_GRAY);   /* selection */
            fb_text(6, y, items[i], C_BLACK);
            fb_text(2, y, ">", C_RED);
        } else {
            fb_text(6, y, items[i], C_WHITE);
        }
    }

    /* status bar */
    fb_rect(0, FB_H-8, FB_W, FB_H, C_DKGRAY);
    fb_text(2, FB_H-6, "EQ:Rock", C_GREEN);
    fb_text(60, FB_H-6, "Vol:20", C_YELLOW);
    fb_text(104, FB_H-6, "B:100%", C_CYAN);

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
