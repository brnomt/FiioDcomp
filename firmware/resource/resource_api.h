/*
 * firmware/resource/resource_api.h
 * ROCK26IMAGERES resource system — bitmaps, fonts, and UI assets
 *
 * In HIFIEC*.IMG, resources live in "part5" (u32 offset/size at IMG 0x14C).
 * Part5 begins with magic "ROCK26IMAGERES" + count, then 16-byte ROCK26
 * entries, pixel blobs, and a parallel 108-byte metadata catalog.
 *
 * V3.7 metadata entry (108 bytes) — note: table base is NOT 4-byte aligned:
 *   +0x00 name[64]   ASCII filename (.BMP), may have trailing spaces
 *   +0x60 offset     uint32 LE — byte offset within part5
 *   +0x64 width      uint32 LE
 *   +0x68 height     uint32 LE
 *
 * ROCK26 entry (16 bytes):
 *   +0x00 (height<<16)|width
 *   +0x04 flags
 *   +0x08 byte_size  (= width*height*2)
 *   +0x0C offset     within part5
 *
 * Image format: RGB565, big-endian (byte-swapped), uncompressed, row-major
 *
 * Font format: SMALL and LARGE per-character glyph bitmaps,
 *   organized by Unicode plane (from Flame Ocean extractor)
 *
 * Theme resource naming convention:
 *   {ThemePrefix}_{ElementName}_({X},{Y}).BMP
 *   Theme prefixes: "" (Theme A), "B" (Theme B), "C" (Theme C),
 *                   "D" (Theme D), "E" (Theme E)
 */

#ifndef RESOURCE_API_H
#define RESOURCE_API_H

#include <stdint.h>
#include <stdbool.h>

/* ROCK26IMAGERES table header */
#define ROCK26_MAGIC  "ROCK26IMAGERES"

typedef struct {
    char     magic[16];       /* "ROCK26IMAGERES" */
    uint32_t entry_count;     /* number of ROCK26 / BMP entries */
    uint32_t reserved0;
    uint32_t reserved1;
    uint32_t reserved2;
    /* followed by entry_count * 16-byte ROCK26Entry */
} ROCK26Header;

typedef struct {
    uint32_t dims;            /* (height << 16) | width */
    uint32_t flags;
    uint32_t byte_size;       /* width * height * 2 */
    uint32_t offset;          /* offset within part5 */
} ROCK26Entry;

/* Full BMP metadata (108-byte catalog entry, V3.7 layout) */
typedef struct {
    char     filename[64];
    uint8_t  runtime[32];     /* runtime / unused in stock image */
    uint32_t data_offset;     /* within part5 */
    uint32_t width;
    uint32_t height;
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
/*   IMG EOF trailer on V3.7.0: 0x1EA1C309 (last 4 bytes; not @ 0x200000) */

#endif /* RESOURCE_API_H */
