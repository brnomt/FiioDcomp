/*
 * firmware/apps/bluetooth/bt_handler.h
 * Bluetooth subsystem — BT Music handler
 *
 * BT audio handling appears to be handled by a separate chip
 * (likely integrated in RKnano) with a thin firmware wrapper.
 * Only "BT Music" UI text found — no A2DP/HFP/AVRCP strings.
 */

#ifndef BT_HANDLER_H
#define BT_HANDLER_H

#include <stdint.h>

void BT_Music_Handler(void);
/*   @ 0x0300ddea — BT audio playback handler */

#endif /* BT_HANDLER_H */
