/*
 * firmware/codecs/codec_api.h
 * Unified audio codec interface
 *
 * All codecs use HifiFile for I/O behind the "DICTDECODER" container layer:
 *   - DICTDECODER_InitStream() @ 0x0304fb44 - parse 'VaT '/'VAT ' container
 *     header, validate format, build the seek/frame index (see dict_decoder.c)
 *
 * NOTE: the functions once labeled DICTDECODER_OpenFile / DICTDECODER_DispatchFile
 * @ 0x0301020c / 0x0301022c were misnamed. They are the main-UI keypad handler
 * (MainUI_KeyHandler) and the GOODEF DSP reload path (DSP_GOODEF_Reload),
 * not codec dispatch. See docs/decompilation-plan.md audit notes.
 *
 * Codec library versions (from embedded strings):
 *   mp2_dec_lib   - 2012.3.31
 *   mp3_dec_lib   - 2012.3.23
 *   wma_dec_lib   - 2012.3.26
 *   aac_dec_lib   - 2012.3.28
 *   libMad        - MP3 (fixed-point MAD decoder)
 *   wmalib        - WMA/ASF
 *   pWAV_lib      - WAV/RIFF
 *   hifi_flacdec  - FLAC
 *   DSD/IFF       - DSD raw
 */

#ifndef CODEC_API_H
#define CODEC_API_H

#include <stdint.h>
#include <stdbool.h>
#include "../firmware.h"

/* Format IDs */
typedef enum {
    FORMAT_UNKNOWN = 0,
    FORMAT_MP1,
    FORMAT_MP2,
    FORMAT_MP3,
    FORMAT_WMA,
    FORMAT_WAV,
    FORMAT_APE,
    FORMAT_FLAC,
    FORMAT_AAC,
    FORMAT_M4A,
    FORMAT_OGG,
    FORMAT_MP43,  /* MPEG-4 Part 3 */
    FORMAT_GPD,   /* unknown */
    FORMAT_DFF,   /* DSD Interchange File Format */
    FORMAT_DSF,   /* DSD Stream File */
} CodecFormat;

/* Codec configuration (passed from MusicInit) */
typedef struct {
    uint32_t sample_rate;     /* 44100, 48000, 88200, 96000, 176400, 192000 */
    uint32_t num_channels;    /* 1 or 2 */
    uint32_t bits_per_sample; /* 16, 24 */
    uint32_t bitrate;         /* kbps */
    uint32_t total_samples;
    uint32_t duration_ms;
    uint8_t  dsd_mode;        /* 64, 128, 256 for DSD */
} CodecConfig;

/* HifiFile I/O layer (used by all codecs) */
typedef void* HifiFileHandle;

HifiFileHandle HifiFile_Open(const char *path);
bool HifiFile_Seek(HifiFileHandle h, uint32_t offset);
bool HifiFile_Read(HifiFileHandle h, void *buf, uint32_t len);
bool HifiFile_Write(HifiFileHandle h, const void *buf, uint32_t len);
bool HifiFile_Close(HifiFileHandle h);
uint32_t HifiFile_GetSize(HifiFileHandle h);
uint32_t HifiFile_Tell(HifiFileHandle h);

/* Dict Decoder — universal format dispatcher */
CodecFormat DICTDECODER_OpenFile(const char *path);  /* @ 0x0301020c */
bool DICTDECODER_InitStream(CodecFormat fmt);         /* @ 0x0304fb44 */
bool DICTDECODER_DispatchFile(CodecFormat fmt);      /* @ 0x0301022c */

/* Per-codec API */
/* MP3 (libMad) */
bool mp3_dec_internal(HifiFileHandle h, int16_t *out_buf, uint32_t *out_samples);
/*   @ 0x0306e5de  source: ../../Common/Codec/Audio/Mp3/libMad/mp3_decinternal.c */

/* WMA */
bool wma_audio_parse(HifiFileHandle h, CodecConfig *cfg);
/*   @ 0x0308cddc  source: ../../Common/Codec/Audio/Wma/wmalib/wmaudio_parse.c */

/* AAC/M4A */
bool aac_aac_dec(HifiFileHandle h, CodecConfig *cfg);
/*   @ 0x030ad690  source: ../../Common/Codec/Audio/AAC/lib/aac_aacdec.c */
bool aac_movfile_parser(HifiFileHandle h);
/*   @ 0x030aeb90  source: ../../Common/Codec/Audio/AAC/lib/aac_MovFile.c */
bool aac_movfile_seek(HifiFileHandle h, uint32_t ms);
/*   @ 0x030ae90c */
bool aac_dec_init(CodecConfig *cfg);
/*   @ 0x030af458 */

/* FLAC */
bool hifi_flac_dec(HifiFileHandle h, int32_t *out_buf, uint32_t *out_samples);
/*   @ 0x030df64c  source: ../../Common/Codec/Audio/HIFI/flac/hifi_flacdec.c */
bool hifi_flac_helper(HifiFileHandle h);
/*   @ 0x030df52a */

/* WAV/RIFF */
bool wav_lib_decode(HifiFileHandle h, CodecConfig *cfg);
/*   @ 0x030a42ee  source: ../../Common/Codec/Audio/Wav/WAV_LIB/pWAV_lib.c */
bool wav_lib_parse_header(HifiFileHandle h, CodecConfig *cfg);
/*   @ 0x030a46c8 */

/* OGG/Vorbis */
bool VorbisOGG_Parser(HifiFileHandle h);
/*   @ 0x03023be8 */
bool OGG_Picture_Metadata(HifiFileHandle h, void *picture_buf, uint32_t *size);
/*   @ 0x030059d6 */

/* APE (Monkey's Audio) */
bool APE_Codec_Open(HifiFileHandle h, CodecConfig *cfg);
/*   @ 0x030eef60 */

/* DSD (DSF/DFF/IFF) */
bool DSD_IFF_Open(HifiFileHandle h, CodecConfig *cfg);
/*   near 0x030ff7d8 */

/* ID3/APEv2 tag readers */
bool mp3_id3v2_handler(HifiFileHandle h, void *id3_buf);
/*   @ 0x0306fec4 */
bool ID3_Picture_Parser(HifiFileHandle h, void *picture_buf, uint32_t *size);
/*   @ 0x03023526 */

#endif /* CODEC_API_H */
