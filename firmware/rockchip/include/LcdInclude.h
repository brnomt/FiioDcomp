/* LcdInclude.h — LCD driver includes (parallel 8080 interface).
 * Auto-created for SDK build (Aug 2026).
 */
#ifndef LCDINCLUDE_H
#define LCDINCLUDE_H

#include "typedef.h"

#include "lcd.h"
#include "LcdDriver.h"

API void Lcd_Write(uint16 data);
API void Lcd_Init(void);
API void Lcd_SetWindow(uint16 x0,uint16 y0,uint16 x1,uint16 y1);

#endif /* LCDINCLUDE_H */
