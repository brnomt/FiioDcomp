/*
 * firmware/os/os_api.h
 * RKnano OS primitives — event system, delays, timer management
 *
 * The RKnano SDK uses a lightweight event-driven kernel.
 * No preemptive multitasking found — cooperative round-robin.
 *
 * Key functions (labeled in Ghidra):
 *   event_set(n)      @ 0x0300c6b4  - Signal event N
 *   event_clear(n)    @ 0x0300c6f6  - Clear event flag N
 *   os_delay_ms(n)    @ 0x030098e4  - Busy-wait delay (milliseconds)
 *   debug_printf(fmt) @ 0x03012838  - Serial debug output
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
 *   0xf5  - BT/A2DP ready
 *   0xf7  - USB mode change
 *   0x114 - System ready
 *   0x159 - File scan complete
 *   0x1d4 - DAC filter change
 *   0x1d5 - Gain change
 *   0x1db - EQ preset change
 */

/* ROM calls for hardware IO (0x02FFxxxx) */
void rom_i2s_config(uint32_t ch, uint32_t mode, uint32_t enable, uint32_t rate);
void rom_dma_start(uint32_t ch, uint32_t src, uint32_t dst, uint32_t len);
void rom_dma_stop(uint32_t ch);
void rom_gpio_write(uint32_t pin, uint32_t val);
uint32_t rom_gpio_read(uint32_t pin);
void rom_clk_set(uint32_t div);
void rom_adc_start(uint32_t ch);
uint32_t rom_adc_read(uint32_t ch);

/* OS primitives */
void event_set(uint32_t event_id);
void event_clear(uint32_t event_id);
uint32_t event_check(uint32_t event_id);
void os_delay_ms(uint32_t ms);
void debug_printf(const char *fmt, ...);

/* Task/event loop (entry point) */
void firmware_entry(uint16_t *param);  /* @ 0x03000010 */

#endif /* OS_API_H */
