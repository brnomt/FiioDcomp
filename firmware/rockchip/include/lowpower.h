/* lowpower.h — Low-power / sleep entry.
 * Auto-created for SDK build (Aug 2026);
 * signatures derived from firmware/rockchip usage.
 */
#ifndef LOWPOWER_H
#define LOWPOWER_H

#include "typedef.h"

API void LowPower_Enter(void);
API void LowPower_Exit(void);
API void Sys_Sleep(void);
API void Sys_Wakeup(void);

#endif /* LOWPOWER_H */
