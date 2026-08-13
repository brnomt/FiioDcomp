/* DriverInclude.h — driver layer master include.
 * The SDK driver sources (cru2.c, dma2.c, interrupt2.c...) expect the
 * SoC register definitions here. */
#ifndef DRIVERINCLUDE_H
#define DRIVERINCLUDE_H

#ifdef RECHORD_AP_BUILD
#include "../driver/DriverInclude.h"
#else
#include "typedef.h"
#include "driverlib_def.h"
#endif

#endif /* DRIVERINCLUDE_H */
