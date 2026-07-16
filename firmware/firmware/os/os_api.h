/*
 * firmware/firmware/os/os_api.h
 * RKnano OS primitives — event bitset, delays, debug
 *
 * Corrected labels (2026-07-16):
 *   event_set / event_clear     @ 0x03073840 / 0x03073882  (bit array)
 *   event_test_and_clear        @ 0x0307385c
 *   hifi_busy_delay             @ 0x0306c2e8  (real spin-wait)
 *   hifi_debug_printf           @ 0x0306c07e
 *   dac_gain_curve_apply        @ 0x030098e4  (was misnamed os_delay_ms)
 *   MediaLib_thunk_GetFiles     @ 0x03012838  (was misnamed debug_printf)
 *
 * Bogus mid-function labels retained as:
 *   shared_frame_epilogue_c6b4  @ 0x0300c6b4
 *   shared_mid_entry_c6f6       @ 0x0300c6f6
 */

#ifndef OS_API_H
#define OS_API_H

#include <stdint.h>

/*
 * Event IDs observed in decompiled code:
 *   0x23  - Audio init complete
 *   0x2a  - Music init start
 *   0x55  - Codec open timeout
 *   0x59  - Playback started
 *   0xf5  - BT/A2DP ready / USB mode
 *   0xf7  - USB mode change
 *   0x114 - System ready
 *   0x115 - AudioFile buffer switch
 *   0x159 - File scan complete
 *   0x1d4 - DAC filter change
 *   0x1d5 - Gain change
 *   0x1db - EQ preset change
 */

void event_set(uint32_t event_id);              /* @ 0x03073840 */
void event_clear(uint32_t event_id);            /* @ 0x03073882 */
uint32_t event_test_and_clear(uint32_t event_id); /* @ 0x0307385c */

void hifi_busy_delay(int ticks);                /* @ 0x0306c2e8 */
void hifi_debug_printf(const char *fmt, ...);   /* @ 0x0306c07e */

void dac_gain_curve_apply(void *src_pp, int mode, void *dst); /* @ 0x030098e4 */

void firmware_entry(uint16_t *param);           /* @ 0x03000010 */

#endif /* OS_API_H */
