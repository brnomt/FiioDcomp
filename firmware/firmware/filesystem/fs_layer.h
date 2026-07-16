/*
 * firmware/firmware/filesystem/fs_layer.h
 * HifiFile I/O layer — RKnano FAT wrapper
 *
 * All codecs use HifiFile for file operations. The layer abstracts
 * the underlying FAT filesystem (Flash memory and SD card).
 *
 * Paths observed:
 *   U:\RECORD     - recording output
 *   Card Memory   - SD card
 *   Flash Memory  - internal NAND
 *
 * Timeout pattern: each HifiFile call has a timeout watchdog.
 * Error string: "HifiFile{Open,Read,Write,Seek,Close}: timeout!!"
 */

#ifndef FS_LAYER_H
#define FS_LAYER_H

#include <stdint.h>
#include <stdbool.h>

/* Storage media */
typedef enum {
    MEDIA_FLASH = 0,
    MEDIA_SDCARD = 1,
} StorageMedia;

/* File handle */
typedef struct {
    uint32_t sector_start;
    uint32_t file_size;
    uint32_t current_pos;
    uint8_t  media;
    uint8_t  fat_cache_id;
    uint8_t  file_name[64];
    uint32_t cluster_chain[16];
} FileInfo;

/* Filesystem API */
bool fs_init(void);
bool fs_mount(StorageMedia media);
bool fs_scan_media(void);          /* update media library */

/* File operations */
bool fs_open(const char *path);           /* Open — string present, fn TBD */
uint8_t  HifiFileSeek(uint32_t offset, uint32_t whence, uint8_t fd); /* @ 0x0306b8e6 */
uint32_t HifiFileRead(uint32_t buf, uint32_t len, uint8_t fd);       /* @ 0x0306b94c */
bool fs_write(int fd, const void *buf, uint32_t len); /* Write — string present, fn TBD */
bool fs_close(int fd);                    /* Close — string present, fn TBD */
uint32_t fs_size(int fd);
uint32_t fs_tell(int fd);

/* Media library */
typedef struct {
    char     file_name[256];
    char     title[128];
    char     artist[128];
    char     album[128];
    char     genre[64];
    uint32_t track_number;
    uint32_t cd_number;
    uint32_t duration_ms;
    uint32_t bitrate;
    uint32_t sample_rate;
    uint16_t year;
    uint8_t  codec_format;
    uint8_t  has_cover_art;
    uint32_t cover_art_offset;
    uint32_t cover_art_size;
} MediaLibraryEntry;

bool media_lib_build(StorageMedia media);
uint32_t media_lib_count(void);
MediaLibraryEntry *media_lib_get(uint32_t index);
bool media_lib_sort_by_album(void);
bool media_lib_sort_by_artist(void);
bool media_lib_sort_by_genre(void);

/* Favorites */
bool favorites_add(uint32_t media_index);
bool favorites_remove(uint32_t media_index);
bool favorites_is_favorite(uint32_t media_index);
uint32_t favorites_count(void);

#endif /* FS_LAYER_H */
