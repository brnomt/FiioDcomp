/*
 * armcc_compat.h — Keil/armcc keyword compatibility for arm-none-eabi-gcc.
 *
 * The Rockchip RKnanoD SDK was written for the Keil ARM compiler (armcc),
 * which has non-standard keywords that GCC does not provide. This header
 * maps them to GCC equivalents. Forced in via `-include armcc_compat.h`.
 */
#ifndef ARMCC_COMPAT_H
#define ARMCC_COMPAT_H

/* __packed — packed struct (GCC: __attribute__((packed))) */
#ifndef __packed
#define __packed __attribute__((packed))
#endif

/* __irq — interrupt handler (GCC: __attribute__((interrupt("IRQ")))) */
#ifndef __irq
#define __irq __attribute__((interrupt("IRQ")))
#endif

/* __align(n) — align to n bytes (GCC: __attribute__((aligned(n)))) */
#ifndef __align
#define __align(n) __attribute__((aligned(n)))
#endif

/* __forceinline — always inline (GCC: __attribute__((always_inline)) inline) */
#ifndef __forceinline
#define __forceinline __attribute__((always_inline)) inline
#endif

/* __weak — weak symbol */
#ifndef __weak
#define __weak __attribute__((weak))
#endif

/* __inline — inline */
#ifndef __inline
#define __inline inline
#endif

/* __noreturn — no return */
#ifndef __noreturn
#define __noreturn __attribute__((noreturn))
#endif

/* __value_in_regs — struct returns in registers (GCC default for ARM) */
#ifndef __value_in_regs
#define __value_in_regs
#endif

/* __svc — supervisor call (GCC: inline asm; used rarely) */
#ifndef __svc
#define __svc(n) __attribute__((naked))
#endif

/* __attribute__((used)) — prevent GC */
#ifndef __used
#define __used __attribute__((used))
#endif

/* __interwork — ARM/Thumb interworking (default on Cortex-M) */
#ifndef __interwork
#define __interwork
#endif

/* MSR/MRS intrinsics the SDK may use */
#ifndef __MRS
#define __MRS(reg)  ({ uint32_t __v; __asm__ volatile("mrs %0, " reg : "=r"(__v)); __v; })
#endif
#ifndef __MSR
#define __MSR(reg, val) __asm__ volatile("msr " reg ", %0" :: "r"(val))
#endif
/* ---- SDK section attributes (linker scatter files) ----
   The RKnanoD SDK places functions/data in named sections via _ATTR_*_CODE_
   /_ATTR_*_DATA_/_ATTR_*_BSS_ macros. For GCC build we map them to the
   matching named section so the linker script can place them later. */
#ifndef _ATTR_OS_CODE_
#define _ATTR_OS_CODE_       __attribute__((section("os_code")))
#endif
#ifndef _ATTR_OS_DATA_
#define _ATTR_OS_DATA_       __attribute__((section("os_data")))
#endif
#ifndef _ATTR_OS_BSS_
#define _ATTR_OS_BSS_        __attribute__((section("os_bss")))
#endif
#ifndef _ATTR_SYS_CODE_
#define _ATTR_SYS_CODE_      __attribute__((section("sys_code")))
#endif
#ifndef _ATTR_SYS_DATA_
#define _ATTR_SYS_DATA_      __attribute__((section("sys_data")))
#endif
#ifndef _ATTR_SYS_BSS_
#define _ATTR_SYS_BSS_       __attribute__((section("sys_bss")))
#endif
#ifndef _ATTR_SYS_INIT_CODE_
#define _ATTR_SYS_INIT_CODE_ __attribute__((section("sys_init")))
#endif
#ifndef _ATTR_DRIVERLIB_CODE_
#define _ATTR_DRIVERLIB_CODE_ __attribute__((section("driver_code")))
#endif
#ifndef _ATTR_DRIVER_CODE_
#define _ATTR_DRIVER_CODE_   __attribute__((section("driver_code")))
#endif
#ifndef _ATTR_DRIVER_DATA_
#define _ATTR_DRIVER_DATA_   __attribute__((section("driver_data")))
#endif
#ifndef _ATTR_DRIVER_BSS_
#define _ATTR_DRIVER_BSS_    __attribute__((section("driver_bss")))
#endif
#ifndef _ATTR_BB_SYS_DATA_
#define _ATTR_BB_SYS_DATA_   __attribute__((section("bb_data")))
#endif
#ifndef _ATTR_AUDIO_BSS_
#define _ATTR_AUDIO_BSS_     __attribute__((section("audio_bss")))
#endif
#ifndef _ATTR_AUDIO_TEXT_
#define _ATTR_AUDIO_TEXT_    __attribute__((section("audio_code")))
#endif
#ifndef _ATTR_FLACDEC_TEXT_
#define _ATTR_FLACDEC_TEXT_  __attribute__((section("flac_code")))
#endif
#ifndef _ATTR_VECTTAB_BB_
#define _ATTR_VECTTAB_BB_    __attribute__((section("vecttab")))
#endif
#ifndef _ATTR_VECTTAB_
#define _ATTR_VECTTAB_       __attribute__((section("vecttab")))
#endif
#ifndef _ATTR_INTRRUPT_CODE_
#define _ATTR_INTRRUPT_CODE_ __attribute__((section("intr_code")))
#endif
#ifndef _ATTR_INTRRUPT_DATA_
#define _ATTR_INTRRUPT_DATA_ __attribute__((section("intr_data")))
#endif
#ifndef _ATTR_OVERLAY_CODE_
#define _ATTR_OVERLAY_CODE_  __attribute__((section("overlay_code")))
#endif
/* codec binary blob sections (bb_core.c) — placeholder names */
#define _ATTR_AACDEC_BIN_TEXT_   __attribute__((section("aac_code")))
#define _ATTR_AACDEC_BIN_DATA_   __attribute__((section("aac_data")))
#define _ATTR_FLACDEC_BIN_TEXT_  __attribute__((section("flac_code")))
#define _ATTR_FLACDEC_BIN_DATA_  __attribute__((section("flac_data")))
#define _ATTR_APEDEC_BIN_TEXT_   __attribute__((section("ape_code")))
#define _ATTR_APEDEC_BIN_DATA_   __attribute__((section("ape_data")))
#define _ATTR_OGGDEC_BIN_TEXT_   __attribute__((section("ogg_code")))
#define _ATTR_OGGDEC_BIN_DATA_   __attribute__((section("ogg_data")))
#define _ATTR_WAVDEC_BIN_TEXT_   __attribute__((section("wav_code")))
#define _ATTR_WAVDEC_BIN_DATA_   __attribute__((section("wav_data")))
#define _ATTR_DSFDEC_BIN_TEXT_   __attribute__((section("dsf_code")))
#define _ATTR_DSFDEC_BIN_DATA_   __attribute__((section("dsf_data")))
#define _ATTR_DSDIFFDEC_BIN_TEXT_ __attribute__((section("dsdiff_code")))
#define _ATTR_DSDIFFDEC_BIN_DATA_ __attribute__((section("dsdiff_data")))
#define _ATTR_HIFI_ALACDEC_BIN_TEXT_ __attribute__((section("alac_code")))
#define _ATTR_HIFI_ALACDEC_BIN_DATA_ __attribute__((section("alac_data")))
#define _ATTR_HIFI_APEDEC_BIN_TEXT_  __attribute__((section("hifi_ape_code")))
#define _ATTR_HIFI_APEDEC_BIN_DATA_  __attribute__((section("hifi_ape_data")))
#define _ATTR_HIFI_FLACDEC_BIN_TEXT_ __attribute__((section("hifi_flac_code")))
#define _ATTR_HIFI_FLACDEC_BIN_DATA_ __attribute__((section("hifi_flac_data")))

#endif /* ARMCC_COMPAT_H */
