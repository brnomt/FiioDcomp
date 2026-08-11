/* I2S.h — I2S audio interface (AudioControl.c). */
#ifndef I2S_H
#define I2S_H
#include "typedef.h"
API void I2S_Init(uint32 sample_rate, uint32 ch, uint32 width);
API void I2S_Start(void);
API void I2S_Stop(void);
API void I2S_Mute(uint8 mute);
API uint32 I2S_GetRxFIFOAddr(uint32 ch);
API uint32 I2S_GetTxFIFOAddr(uint32 ch);
#endif
