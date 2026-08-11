/*
 * firmware/firmware/media/media_api.h
 * Media library and tag parsing
 *
 * Supported tag formats:
 *   - ID3v2 (MP3, FLAC, DSD)
 *   - APEv2 (APE, WavPack)
 *   - Vorbis Comments (OGG, FLAC)
 *   - MP4 atoms (AAC/M4A)
 *   - RIFF INFO chunks (WAV)
 *   - ASF metadata (WMA)
 *
 * Album art support:
 *   - METADATA_BLOCK_PICTURE (FLAC)
 *   - APIC frames (ID3v2)
 *   - PICTURE OGG (Vorbis)
 *   - image/jpeg, image/jpg, image/peg, image/bmp
 */

#ifndef MEDIA_API_H
#define MEDIA_API_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char     title[128];
    char     artist[128];
    char     album[128];
    char     album_artist[128];
    char     genre[64];
    char     composer[64];
    uint32_t track_number;
    uint32_t disc_number;
    uint32_t total_tracks;
    uint32_t total_discs;
    uint32_t year;
    uint32_t duration_ms;
    uint32_t bitrate;
    uint32_t sample_rate;
    uint8_t  channels;
    uint8_t  bits_per_sample;
    uint8_t  codec_format;
    bool     has_cover_art;
    uint8_t  cover_mime_type[32];
    uint32_t cover_offset;      /* in file */
    uint32_t cover_size;
} TrackMetadata;

/* Tag parsing */
bool id3v2_parse(const char *path, TrackMetadata *meta);
/*   ID3V2 start string at 0x030ff6f8 */
bool apev2_parse(const char *path, TrackMetadata *meta);
/*   APETAGEX string at 0x03023f78, 0x0307463c, 0x030f0500 */
bool vorbis_comment_parse(const char *path, TrackMetadata *meta);
/*   "vorbis" string at 0x030243d0 */
bool mp4_atom_parse(const char *path, TrackMetadata *meta);
bool riff_info_parse(const char *path, TrackMetadata *meta);

/* Cover art extraction */
void *cover_art_extract(const char *path, uint32_t *size, char *mime_type);
bool  cover_art_to_bitmap(const void *jpeg_data, uint32_t jpeg_size,
                          void *bmp_buf, uint32_t bmp_buf_size);

/* Base64 decoder (for embedded images in tags) */
int base64_decode(const char *src, uint8_t *dst, uint32_t dst_size);
/*   "base64_decode error, ret: %d" string at 0x03023aec */

/* Format string generator for display:
 *   "FLAC:24bit/192kHz", "APE: 24bit/192kHz", "MP3/OGG/M4A/WMA"
 *   "DSD64,DSD128,DSD256", "WAV:24bit/192kHz"
 *   "NO support SACD and DTS"
 */
void media_format_string(char *buf, uint32_t buf_size, const TrackMetadata *meta);

#endif /* MEDIA_API_H */
