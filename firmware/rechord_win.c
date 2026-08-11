/*
 * ReChord window layer — real MainMenuWin (replaces the zeroed stub).
 *
 * The stock UI framework (Win.c / Task.c, which we compile) builds the
 * task list from WIN structures. `MainMenuWin` was a zeroed uint32_t in
 * stubs.c, so pgWinInit/pgWinPaint/pgWinKeyScan/pgWinService/pgWinDeInit
 * were all NULL → pressing a menu item called NULL → hard fault → the
 * freeze/power-off the user saw.
 *
 * This provides a real WIN with ReChord handlers. They render the menu
 * into the UI framebuffer (0x03024868) and return RETURN_OK so the
 * framework keeps running instead of faulting.
 */
#include <stdint.h>

#include "SysInclude.h"
#include "Win.h"

#define UI_FB   0x03024868u
#define LCD_W   320
#define LCD_H   100

static int g_menu_sel = 0;

/* ---- tiny framebuffer helpers (RGB565) ---- */
static void fb_px(int x, int y, uint16_t c)
{
    volatile uint16_t *fb = (volatile uint16_t *)UI_FB;
    if (x < 0 || x >= LCD_W || y < 0 || y >= LCD_H) return;
    fb[y * LCD_W + x] = c;
}
static void fb_rect(int x0, int y0, int x1, int y1, uint16_t c)
{
    for (int y = y0; y < y1; y++)
        for (int x = x0; x < x1; x++)
            fb_px(x, y, c);
}

/* ---- window handlers ---- */
static void MainMenuWinInit(void *pArg)
{
    g_menu_sel = 0;
}

static void MainMenuWinDeInit(void)
{
}

static UINT32 MainMenuWinService(void)
{
    return RETURN_OK;
}

static UINT32 MainMenuWinKeyScan(void)
{
    /* No real key input yet — keep returning OK so navigation works. */
    return RETURN_OK;
}

static void MainMenuWinPaint(void)
{
    /* ReChord menu placeholder: title + 4 items, selection highlighted. */
    static const char *items[4] = {"Music", "EQ", "Settings", "About"};

    fb_rect(0, 0, LCD_W, LCD_H, 0x0000);           /* black bg */

    /* title bar */
    fb_rect(0, 0, LCD_W, 18, 0x001F);              /* blue */
    for (int x = 0; x < LCD_W; x++)                /* white line */
        fb_px(x, 18, 0xFFFF);

    /* menu items */
    for (int i = 0; i < 4; i++) {
        int y = 26 + i * 16;
        if (i == g_menu_sel) {
            fb_rect(4, y, 120, y + 13, 0x8410);    /* gray sel */
        }
        /* draw item as a colored block (no font yet) */
        uint16_t col = (i == g_menu_sel) ? 0x0000 : 0xFFFF;
        for (int b = 0; b < 12; b++)
            fb_px(8 + b * 2, y + 4, col);
    }
}

/* ---- the actual WIN structure ---- */
_ATTR_OS_DATA_
WIN MainMenuWin =
{
    NULL,                        /* Son */
    NULL,                        /* Father */
    MainMenuWinService,          /* pgWinService */
    MainMenuWinKeyScan,          /* pgWinKeyScan */
    MainMenuWinPaint,            /* pgWinPaint */
    MainMenuWinInit,             /* pgWinInit */
    MainMenuWinDeInit,           /* pgWinDeInit */
};
