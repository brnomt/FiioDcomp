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
