/* Spectrum.h — audio spectrum (AudioControl.c). */
#ifndef SPECTRUM_H
#define SPECTRUM_H
#include "typedef.h"
API void Spectrum_Init(void);
API void Spectrum_Process(int16 *pcm, uint32 len);
API void Spectrum_GetLevel(uint8 *levels, uint32 num);
#endif
