/* backlight.h — the SDK's real backlight header now ships with the imported
 * driver tree (system/sysservice/backlight.h). This integration shim just
 * forwards to it; the old hand-written approximation (Backlight_* API, uint32
 * IsBackLightOn, BL_PWM_RATE_* values) is gone because the real SDK wins. */
#ifndef BACKLIGHT_H
#define BACKLIGHT_H
#include "../system/sysservice/backlight.h"
#endif /* BACKLIGHT_H */
