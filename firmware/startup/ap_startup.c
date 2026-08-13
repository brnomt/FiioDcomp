/*
 * ReChord AP (fw1) startup — Cortex-M3 vector table + reset handler for the
 * A_CORE build.
 *
 * The Mask ROM scatter-loads fw1 (RKnanoFW header + memory-map table) and
 * jumps to the reset entry at SYS_CODE (0x03060000). This file mirrors the
 * SDK's Common/BootLoader/Start.s: a vector table (START_VECT) with [0]=MSP
 * and [1]=reset, plus a reset handler (PowerOn_Reset) that clears BSS and
 * hands control to Main. BSS is also zero-filled by the scatter table's
 * Type A entry, so the explicit clear here is defensive (idempotent).
 */
#include <stdint.h>

typedef unsigned int uint32;

extern uint32 __stack_top;   /* firmware_ap.ld absolute symbol = 0x03050000 */
extern uint32 Main(void);
extern uint32 _bss_start, _bss_end;

void Default_Handler(void) __attribute__((naked));
void Default_Handler(void)
{
    for (;;)
        __asm volatile("");
}

/* Reset handler: clear BSS, then jump to Main (never returns). */
void PowerOn_Reset(void) __attribute__((noreturn));
void PowerOn_Reset(void)
{
    uint32 *p = &_bss_start;
    while (p < &_bss_end)
        *p++ = 0;
    Main();
    for (;;)
        __asm volatile("");
}

/* Cortex-M3 vector table (aligned 256 for VTOR). [0]=initial MSP, [1]=reset. */
const uint32_t ap_vectors[16]
    __attribute__((section(".vectors"), used, aligned(256))) = {
    (uint32_t)&__stack_top,             /* 0x00 initial MSP = 0x03050000 */
    (uint32_t)&PowerOn_Reset,           /* 0x04 Reset_Handler             */
    (uint32_t)&Default_Handler,         /* 0x08 NMI                      */
    (uint32_t)&Default_Handler,         /* 0x0C HardFault                */
    (uint32_t)&Default_Handler,         /* 0x10 MemManage                */
    (uint32_t)&Default_Handler,         /* 0x14 BusFault                 */
    (uint32_t)&Default_Handler,         /* 0x18 UsageFault               */
    0, 0, 0, 0,                        /* 0x1C-0x28 reserved            */
    (uint32_t)&Default_Handler,         /* 0x2C SVCall                   */
    (uint32_t)&Default_Handler,         /* 0x30 DebugMon                 */
    0,                                  /* 0x34 reserved                 */
    (uint32_t)&Default_Handler,         /* 0x38 PendSV                   */
    (uint32_t)&Default_Handler,         /* 0x3C SysTick                  */
};
