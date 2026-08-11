/*
 * firmware/firmware/dsp/dsp_api.h
 * GOODE DSP — audio effects processor
 *
 * "GOODEFGHMP3" / "GOODEFGHMP3" — GOODE family DSP chip
 * "WOOOOONXDIC" / "WOOOOONXBIN" — likely DSP boot/firmware loading
 *
 * EQ presets (from UI bitmaps):
 *   NOR    — Normal (flat)
 *   RETRO  — Retro EQ
 *   BAS    — Bass boost
 *   HEAVY  — Heavy
 *   POP    — Pop
 *   JAZ    — Jazz
 *   MS     — ?
 *   USE    — Custom/User EQ (5-band adjustable)
 *
 * DSP functions:
 *   DSP_GOODEF_Init    @ 0x0300f7dc
 *   DSP_GOODEF_Process @ 0x0300fb0e
 *
 * DAC DRE parameter (from changelog V2.4.0):
 *   "Optimized DAC DRE parameters"
 */

#ifndef DSP_API_H
#define DSP_API_H

#include <stdint.h>
#include <stdbool.h>

/* EQ presets */
typedef enum {
    EQ_NORMAL = 0,
    EQ_RETRO  = 1,
    EQ_BASS   = 2,
    EQ_HEAVY  = 3,
    EQ_POP    = 4,
    EQ_JAZZ   = 5,
    EQ_MS     = 6,
    EQ_CUSTOM = 7,
} EQPreset;

/* 5-band EQ (custom mode) */
typedef struct {
    int8_t band_1;   /* low shelf */
    int8_t band_2;   /* low-mid */
    int8_t band_3;   /* mid */
    int8_t band_4;   /* high-mid */
    int8_t band_5;   /* high shelf */
} EQBandConfig;

/* Gain modes */
typedef enum {
    GAIN_LOW  = 0,
    GAIN_HIGH = 1,
} GainMode;

/* DAC filter types */
typedef enum {
    DAC_FILTER_FAST_ROLLOFF = 0,
    DAC_FILTER_SLOW_ROLLOFF = 1,
} DACFilter;

/* Volume: 0-120 levels (0 = mute, 120 = max) */

void DSP_GOODEF_Init(void);
void DSP_GOODEF_Process(int16_t *pcm_in, int16_t *pcm_out, uint32_t sample_count);

bool eq_set_preset(EQPreset preset);
bool eq_set_custom_bands(const EQBandConfig *bands);
EQBandConfig eq_get_bands(void);

bool gain_set(GainMode mode);
GainMode gain_get(void);

bool volume_set(uint8_t level);
uint8_t volume_get(void);

bool dac_filter_set(DACFilter filter);
DACFilter dac_filter_get(void);

#endif /* DSP_API_H */
