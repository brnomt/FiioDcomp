/* backlight.h — Backlight control (Echo Mini LCD backlight via ROM API).
 * Auto-created for SDK build (Aug 2026);
 * signatures derived from firmware/rockchip usage.
 */
#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "typedef.h"

API void Backlight_Init(void);
API void Backlight_SetLevel(uint8 level);
API void Backlight_On(void);
API void Backlight_Off(void);
API uint8 Backlight_GetLevel(void);

#endif /* BACKLIGHT_H */

/* OsHook.c reads this global */
extern uint32 IsBackLightOn;

/* ---- Backlight PWM + globals (Backlight.c) ---- */
#ifndef BACKLIGHT_DEFS
#define BACKLIGHT_DEFS
#define BL_LEVEL_MAX         5
#define BL_PWM_CH            0
#define BL_PWM_RATE_MIN      0xFFFF
#define BL_PWM_RATE_STEP     0x4000
#define PWM_FREQ             20000

extern uint32 BacklightSystickCounterBack;
extern uint8  gSysSetBLTimeArray[BL_LEVEL_MAX];
#endif
