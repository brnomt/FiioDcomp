/*
 * firmware/apps/audio/audio_service.h
 * MusicService — main playback engine
 *
 * Init chain:
 *   firmware_entry → MusicInit (@ 0x0302b9d8)
 *     → audiocodec_open (@ 0x03029d0e) — I2S + DAC config via ROM
 *     → MusicService_Init (@ 0x0302a3e0) — start playback thread
 *       → AudioPlayback_Start (@ 0x0302a398)
 *
 * Duck-typed from Ghidra decompilation of section_3, firmware v3.7.0
 */

#ifndef AUDIO_SERVICE_H
#define AUDIO_SERVICE_H

#include <stdint.h>
#include <stdbool.h>
#include "../../codecs/codec_api.h"

/* Playback state machine */
typedef enum {
    STATE_IDLE       = 0,
    STATE_PLAYING    = 1,
    STATE_PAUSED     = 2,
    STATE_SEEKING    = 3,
    STATE_STOPPED    = 4,
    STATE_ERROR      = 5,
    STATE_EOF        = 8,
    STATE_TRANSITION = 10,
} PlaybackState;

/* Music service context (struct inferred from MusicInit decompilation) */
typedef struct MusicServiceCtx {
    CodecConfig  codec_cfg;        /* offset 0x00: audio format config */
    PlaybackState state;           /* offset 0x34: current state */
    uint32_t     current_time_ms;  /* offset 0x44: position in track */
    uint32_t     sample_count;     /* offset 0x50: samples decoded */
    uint32_t     buffer_pos;       /* offset 0x54: playback buffer index */
    uint16_t     track_index;      /* offset 0x66: playlist position */
    uint8_t      volume_level;     /* offset 0x6d: 0-120 */
    uint8_t      gain_mode;        /* offset 0x6f: 0=low, 1=high */
    uint8_t      eq_preset;        /* offset 0x74: EQ preset index */
    uint16_t     eq_bands[5];      /* offset 0x77: EQ gain per band */
    uint8_t      dac_filter;       /* offset 0x34a: DAC filter type */
    uint8_t      play_mode;        /* offset 0x354: repeat/shuffle */
} MusicServiceCtx;

/* MusicService API */
void MusicInit(void);
/*   @ 0x0302b9d8 — setup sample rate, I2S, DMA, codec IC */

void MusicService_Init(void *unused, MusicServiceCtx *ctx);
/*   @ 0x0302a3e0 — init playback, open audio codec */

bool audiocodec_open(uint32_t sample_rate);
/*   @ 0x03029d0e — configure DAC IC and I2S clock */

void AudioPlayback_Start(const char *path);
/*   @ 0x0302a398 — begin file playback */

/* DSP */
void DSP_GOODEF_Init(void);
/*   @ 0x0300f7dc — initialize GOODE DSP chip */
void DSP_GOODEF_Process(int16_t *in, int16_t *out, uint32_t samples);
/*   @ 0x0300fb0e — apply EQ/DSP effects */

/* Frequency change handling (called on sample rate switch) */
void FreqChange_Handler(void);
/*   string: "FreqChange timeout!!!" — called by all codecs */

#endif /* AUDIO_SERVICE_H */
