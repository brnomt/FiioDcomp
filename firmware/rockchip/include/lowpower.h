/* lowpower.h — the SDK's real low-power header now ships with the imported UI
 * tree (ui/dialog/LowPower.h, which declares LowPowerWin). This shim forwards to
 * it; the old hand-written approximation is gone because the real SDK wins. */
#ifndef LOWPOWER_H
#define LOWPOWER_H
#include "../ui/dialog/LowPower.h"
#endif /* LOWPOWER_H */
