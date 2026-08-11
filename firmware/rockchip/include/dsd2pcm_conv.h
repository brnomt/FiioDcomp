/* dsd2pcm_conv.h — DSD to PCM conversion. */
#ifndef DSD2PCM_CONV_H
#define DSD2PCM_CONV_H
#include "typedef.h"
typedef struct { uint32 state; } dsd2pcm_t;
API void dsd2pcm_init(dsd2pcm_t *c);
API void dsd2pcm_convert(dsd2pcm_t *c, const uint8 *dsd, int16 *pcm, uint32 nsamples);
#endif

#ifndef DSD_CONSTS
#define DSD_CONSTS
#define MAX_DSDBITS_INFRAME  8
#define MAX_CHANNELS         2
#endif
