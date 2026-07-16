/*
 * firmware/firmware/power/power_api.h
 * Power management — battery, charging, sleep
 *
 * Battery: 6 levels shown via CHARGELEVEL0..5 BMPs
 *          5 levels on playback screen via MUSIC_BATTERY01..05 BMPs
 *
 * Power saving: defaults to 5 minutes (from changelog)
 * Charging: detected in power-off state, shows charging indicator
 *
 * Shutdown sequence: save settings, stop playback, power down DAC
 */

#ifndef POWER_API_H
#define POWER_API_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    BATT_LEVEL_0 = 0,   /* critical / empty */
    BATT_LEVEL_1 = 1,
    BATT_LEVEL_2 = 2,
    BATT_LEVEL_3 = 3,
    BATT_LEVEL_4 = 4,
    BATT_LEVEL_5 = 5,   /* full */
} BatteryLevel;

typedef enum {
    CHARGE_STATE_IDLE      = 0,
    CHARGE_STATE_CHARGING  = 1,
    CHARGE_STATE_FULL      = 2,
} ChargeState;

BatteryLevel battery_get_level(void);
uint32_t     battery_get_voltage_mv(void);
ChargeState  battery_get_charge_state(void);

/* Sleep / auto power-off */
void power_set_sleep_timer(uint32_t minutes);
uint32_t power_get_sleep_timer(void);
void power_reset_sleep_timer(void);

/* Shutdown */
void power_shutdown(void);

#endif /* POWER_API_H */
