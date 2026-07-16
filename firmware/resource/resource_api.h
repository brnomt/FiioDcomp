/*
 * firmware/resource/resource_api.h
 * ROCK26IMAGERES resource system — bitmaps, fonts, and UI assets
 *
 * Resource table found at ~0x04F14FA0+ in high memory.
 * Format: ROCK26IMAGERES header + array of BMP descriptors.
 *
 * Each descriptor (108 bytes):
 *   offset 0-3:   flags/magic
 *   offset 20-23: offset_in_firmware
 *   offset 24-27: width (pixels)
 *   offset 28-31: height (pixels)
 *   offset 32-95: filename (ASCII, null-terminated, .BMP suffix)
 *
 * Image format: RGB565, uncompressed, packed row-major
 *
 * Font format: SMALL and LARGE per-character glyph bitmaps,
 *   organized by Unicode plane (from Flame Ocean extractor)
 *
 * Theme resource naming convention:
 *   {ThemePrefix}_{ElementName}_({X},{Y}).BMP
 *   Theme prefixes: "" (Theme A), "B" (Theme B), "C" (Theme C),
 *                   "D" (Theme D), "E" (Theme E)
 *
 *   Element names observed:
 *     POWERON0..1, Z_POWERON0..16    - boot animation
 *     PONIT_NOSEL*, PONIT_NOSELBLUE* - menu items
 *     NOSEL00_ICON                   - icon placeholders
 *     SETMENU_USERNOSEL*             - settings menu items
 *     KEYCHANGE                      - key mode indicator
 *     MUSIC_BATTERY01..05            - battery icon
 *     CHARGELEVEL0..5                - charging indicator
 *     MUSIC_EQ_{NOR,RETRO,BAS,HEAVY,POP,JAZ,MS,USE} - EQ icons
 *     SM_COM_VOLUME_000..009         - volume digits
 *     VOLNUM_00..                    - volume number
 *     DIALOGBOX_BUTTON{YES,NO}       - dialog buttons
 *     USB_BACKGROUND, USB_DAC*, USB_DATA*, USB_PLAYER*
 *     MUSIC_EQ_*                     - EQ screen elements
 */

#ifndef RESOURCE_API_H
#define RESOURCE_API_H

#include <stdint.h>
#include <stdbool.h>

/* ROCK26IMAGERES table header */
#define ROCK26_MAGIC  "ROCK26IMAGERES"

typedef struct {
    char     magic[16];       /* "ROCK26IMAGERES" */
    uint32_t table_size;      /* total size */
    uint32_t entry_count;     /* number of BMP entries */
    uint32_t header_size;     /* = 32 */
    /* followed by entry_count * 16-byte entries */
} ROCK26Header;

typedef struct {
    char     name[8];         /* abbreviated BMP name */
    uint32_t flags;
    uint32_t offset;          /* in firmware binary */
} ROCK26Entry;

/* Full BMP metadata (from metadata table) */
typedef struct {
    char     filename[64];
    uint32_t data_offset;
    uint32_t width;
    uint32_t height;
    uint32_t flags;
    /* remaining bytes: padding/alignment */
} BMPDescriptor;

/* Resource API */
bool resource_init(void);
/*   Parse ROCK26IMAGERES table, load metadata descriptors */

uint32_t resource_count(void);
BMPDescriptor *resource_get(uint32_t index);
BMPDescriptor *resource_find(const char *name);

/* Pixel data access */
const uint16_t *resource_get_pixels(const BMPDescriptor *desc);
uint32_t resource_get_pixel_count(const BMPDescriptor *desc);

/* Font access */
typedef struct {
    uint8_t  width;
    uint8_t  height;
    uint16_t char_count;
    const uint8_t *glyph_data;   /* 1-bit per pixel, packed */
} FontInfo;

FontInfo *font_get_small(void);
FontInfo *font_get_large(void);

/* Resource patching (for theme modding) */
bool resource_replace_bitmap(uint32_t index, const uint16_t *new_pixels,
                              uint32_t new_width, uint32_t new_height);

/* Firmware packing */
bool firmware_calc_crc(uint32_t *crc);
/*   CRC at offset 0x200000 in IMG: 0x1EA1C309 */

#endif /* RESOURCE_API_H */
