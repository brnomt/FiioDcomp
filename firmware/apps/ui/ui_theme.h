/*
 * firmware/apps/ui/ui_theme.h
 * Display and theme system
 *
 * 5 themes supported (A/B/C/D/E) with 5 UI elements each:
 *   - Menu Text Colors: R1=Highlight, R2=Secondary, R3=Foreground
 *   - FLAC String Text: differs for Theme4 vs others (0429 0CBF pattern)
 *   - Progress Bar Background
 *   - Marquee Overlay
 *
 * Resources stored at 0x04F00000+ via ROCK26IMAGERES table:
 *   ~1200 BMPs in RGB565 format
 *   2 font sets (SMALL/LARGE)
 *
 * Theme color function (FLAC):
 *   FLAC_ThemeColor_Select @ 0x030055a0  (pattern: 04290CBF)
 *
 * Menu handler:
 *   BroMemSelKeyMenu_Handler @ 0x03013280  (Browse Memory/Select Key Menu)
 */

#ifndef UI_THEME_H
#define UI_THEME_H

#include <stdint.h>

/* Theme IDs */
typedef enum {
    THEME_A = 0,
    THEME_B = 1,
    THEME_C = 2,
    THEME_D = 3,
    THEME_E = 4,
} ThemeId;

/* UI Element types */
typedef enum {
    UI_POWERON_LOGO,        /* Z_POWERON0..16 */
    UI_BACKGROUND,          /* main background per theme */
    UI_MENU_ITEM,           /* PONIT_NOSEL, PONIT_NOSELBLUE, etc */
    UI_BUTTON_DIALOG,       /* DIALOGBOX_BUTTONYES/NO */
    UI_BATTERY_ICON,        /* CHARGELEVEL0..5, MUSIC_BATTERY01..05 */
    UI_VOLUME_ICON,         /* SM_COM_VOLUME_000..009 */
    UI_EQ_PRESET,           /* MUSIC_EQ_NOR/RETRO/BAS/HEAVY/POP/JAZ/MS/USE */
    UI_USB_MODE,            /* USB_DAC, USB_DATA, USB_PLAYER */
    UI_FLAC_STRING,         /* FLAC format label color */
    UI_PROGRESS_BAR,        /* playback progress bar */
    UI_MARQUEE,             /* scrolling text */
    UI_KEY_CHANGE,          /* button mode indicator */
    UI_RECORD_ICON,         /* recording status */
} UIElement;

/* Menu text colors per theme per register */
typedef struct {
    uint16_t highlight;     /* R1 */
    uint16_t secondary;     /* R2 */
    uint16_t foreground;    /* R3 */
} MenuThemeColors;

/* BMP resource descriptor (ROCK26IMAGERES table entry) */
typedef struct {
    char     name[64];      /* filename.BMP */
    uint32_t offset;        /* offset in resource section */
    uint32_t width;         /* pixels */
    uint32_t height;        /* pixels */
    uint32_t flags;         /* unknown */
} BMPResource;

/* UI API */
void FLAC_ThemeColor_Select(uint8_t theme_id);
/*   @ 0x030055a0 — select FLAC string color per theme */

void BroMemSelKeyMenu_Handler(void);
/*   @ 0x03013280 — browse memory / key selection menu */

void FormatList_Init(void);
/*   @ 0x03013c10 — initialize supported format list */

#endif /* UI_THEME_H */
