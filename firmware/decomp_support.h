/*
 * decomp_support.h — Type and symbol support for Ghidra-decompiled sources.
 *
 * The decompiled .c files (firmware/<subsystem>/<name>.c) use Ghidra's
 * pseudo-types and pseudo-symbols:
 *   - types: undefined, undefined1/2/4/8, uint, ushort, uchar, longlong
 *   - globals: DAT_xxxx, FUN_xxxx, s_xxxx (strings), thunk_*, LAB_*
 *   - helpers: SBORROW4, CARRY4, halt_baddata, rom_* functions
 *
 * This header makes them compile with arm-none-eabi-gcc (Cortex-M3, Thumb).
 * It is NOT a faithful reconstruction — it exists so the tree builds and
 * each function can be verified/improved incrementally.
 */
#ifndef DECOMP_SUPPORT_H
#define DECOMP_SUPPORT_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ---- Ghidra pseudo-types ---- */
typedef uint8_t  undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef uint32_t undefined;   /* ambiguous-size Ghidra type */

typedef uint8_t  uchar;
typedef uint8_t  byte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulonglong;
typedef int64_t  longlong;
typedef int32_t  int32;
typedef uint32_t uint32;
typedef int16_t  int16;
typedef uint16_t uint16;
typedef int8_t   int8;
typedef uint8_t  uint8;
typedef float    float32;
typedef double   float64;

/* Ghidra "code" type for function pointers — returns int so calls used
 * as values compile; unspecified params so any indirect call works. */
typedef int (*code)();

/* ---- carry/borrow helpers Ghidra emits ---- */
#define CARRY4(a, b)    ((uint)((a) + (b)) < (uint)(a))
#define SBORROW4(a, b)  ((int)((a) - (b)) > (int)(a))
#define CARRY8(a, b)    ((ulonglong)((a) + (b)) < (ulonglong)(a))
#define SBORROW8(a, b)  ((longlong)((a) - (b)) > (longlong)(a))

/* halt_baddata: Ghidra emits this at bad-instruction truncation points */
static inline void halt_baddata(void) { for (;;) { } }

/* ---- global symbols (RAM addresses, ROM API) ---- */
/* DAT_xxxx references are declared weak so the linker tolerates them;
 * real addresses come from the memory map when reconstructed. */
#define DECL_DAT(name, addr) \
    extern unsigned int name __attribute__((weak, section(".data")))

/* Placeholder for DAT_xxxx / FUN_xxxx / s_xxxx symbols used by the
 * decompiled code. Each .c that references them can #define the ones it
 * needs, or we rely on -Wl,--undefined. For compile-check only, provide
 * a generic catch-all via macros. */

#endif /* DECOMP_SUPPORT_H */
