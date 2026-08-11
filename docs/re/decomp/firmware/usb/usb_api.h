/*
 * firmware/firmware/usb/usb_api.h
 * USB subsystem — DAC mode and mass storage
 *
 * USB DAC features (from changelog V2.4.0):
 *   - Driverless, 48kHz sampling rate
 *   - No exclusive mode
 *   - Phone/PC charges device while connected
 *
 * USB mode selection:
 *   USB_DAC   — audio output to host
 *   USB_DATA  — mass storage / file transfer
 *   USB_PLAYER — media device mode
 *
 * ROM calls for USB:
 *   func_0x02ffb2e0 — USB connect
 *   func_0x02ffb3e6 — USB disconnect
 */

#ifndef USB_API_H
#define USB_API_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    USB_MODE_NONE   = 0,
    USB_MODE_DAC    = 1,
    USB_MODE_DATA   = 2,
    USB_MODE_PLAYER = 3,
} USBMode;

typedef enum {
    USB_DAC_STATE_IDLE    = 0,
    USB_DAC_STATE_ACTIVE  = 1,
    USB_DAC_STATE_ERROR   = 2,
} USBDacState;

USBMode usb_detect_mode(void);
bool    usb_set_mode(USBMode mode);
USBMode usb_get_mode(void);

/* DAC mode */
bool usb_dac_start(void);
bool usb_dac_stop(void);
USBDacState usb_dac_get_state(void);

/* Data mode (mass storage) */
bool usb_data_start(void);
bool usb_data_stop(void);

#endif /* USB_API_H */
