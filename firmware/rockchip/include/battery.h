/* battery.h — Battery / charging (fuel gauge + charge state).
 * Auto-created for SDK build (Aug 2026);
 * signatures derived from firmware/rockchip usage.
 */
#ifndef BATTERY_H
#define BATTERY_H

#include "typedef.h"

API uint32 Battery_GetLevel(void);
API uint16 Battery_GetChargeState(void);
API void Battery_Init(void);
API uint16 Battery_GetVoltage(void);

#endif /* BATTERY_H */
