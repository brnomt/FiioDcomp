/*
 * firmware/drivers/drivers.h
 * Hardware drivers — all I/O is through ROM (0x02FFxxxx)
 *
 * The RKnano SoC has a boot ROM that provides hardware abstraction.
 * Our firmware calls ROM for all peripheral access.
 *
 * ROM function address range: 0x02FE0000 - 0x02FFFFFF
 *
 * Known ROM call families (inferred from MusicInit + MusicService_Init):
 *   func_0x02ff5752 — I2S master config
 *   func_0x02ff5c30 — audio clock setup
 *   func_0x02ff55c0 — DAC IC init
 *   func_0x02ff55ba — DAC IC deinit
 *   func_0x02ff6814 — DMA channel config
 *   func_0x02ff68f0 — I2S/DMA start
 *   func_0x02ffa410 — sample rate set
 *   func_0x02ffa6f0 — audio path routing
 *   func_0x02ffa72a — audio path disable
 *   func_0x02ffa224 — audio buffer status
 *   func_0x02ff44ce — DAC mute
 *   func_0x02ff4580 — DAC unmute
 *   func_0x02ff952e — memcpy (hardware accelerated?)
 *   func_0x02ff957c — memset
 *   func_0x02ffb2e0 — USB connect
 *   func_0x02ffb3e6 — USB disconnect
 *   func_0x02ff44ce — GPIO/DMA control
 *   func_0x02fee544 — SPI command
 *   func_0x02feda18 — LCD update
 *   func_0x02feeedc — alloc
 *   func_0x02feeebe — free
 */

#ifndef DRIVERS_H
#define DRIVERS_H

#include <stdint.h>

/* LCD driver (likely ST7735/ILI9341 or similar SPI TFT) */
void lcd_init(void);
void lcd_set_window(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void lcd_write_pixels(const uint16_t *rgb565, uint32_t count);
void lcd_fill(uint16_t color);
void lcd_backlight(uint8_t brightness);

/* Keypad (ADC-based? 6 keys: Vol+, Vol-, Prev, Next, Menu, Power) */
typedef enum {
    KEY_NONE      = 0,
    KEY_VOL_UP    = 1,
    KEY_VOL_DOWN  = 2,
    KEY_PREV      = 3,
    KEY_NEXT      = 4,
    KEY_MENU      = 5,
    KEY_POWER     = 6,
} KeyCode;

typedef enum {
    KEY_PRESS_SHORT  = 0,
    KEY_PRESS_LONG   = 1,
    KEY_PRESS_DOUBLE = 2,
} KeyPressType;

KeyCode      key_scan(void);
KeyPressType key_get_press_type(KeyCode key);

/* Audio Codec IC (dedicated DAC chip controlled via I2C) */
void dac_write_reg(uint8_t reg, uint16_t value);
uint16_t dac_read_reg(uint8_t reg);

/* Flash storage */
void flash_init(void);
bool flash_read(uint32_t addr, void *buf, uint32_t len);
bool flash_write(uint32_t addr, const void *buf, uint32_t len);
bool flash_erase(uint32_t addr, uint32_t len);

/* SD card */
void sd_init(void);
bool sd_detect(void);
bool sd_read(uint32_t sector, void *buf, uint32_t count);
bool sd_write(uint32_t sector, const void *buf, uint32_t count);

#endif /* DRIVERS_H */
