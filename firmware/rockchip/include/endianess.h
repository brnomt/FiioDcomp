/* endianess.h — SACD endianness helpers. */
#ifndef ENDIANESS_H
#define ENDIANESS_H
#include "typedef.h"
static inline uint32 be32(const uint8 *p) { return ((uint32)p[0]<<24)|((uint32)p[1]<<16)|((uint32)p[2]<<8)|p[3]; }
static inline uint16 be16(const uint8 *p) { return (uint16)((p[0]<<8)|p[1]); }
#endif
