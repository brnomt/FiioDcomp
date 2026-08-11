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

#endif /* ARMCC_COMPAT_H */
