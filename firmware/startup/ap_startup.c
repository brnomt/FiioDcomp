/*
 * ReChord AP (fw1) startup — Cortex-M3 vector table for the A_CORE build.
 *
 * The Mask ROM scatter-loads fw1 (RKnanoFW header + memory-map table) and
 * jumps to the reset vector at SYS_CODE (0x03060000). This file provides the
 * vector table so the reset handler (Main) is found. The .data is loaded and
 * BSS is zero-filled by the ROM's scatter loader (pack_fw1.py Type A entry),
 * so Main only performs the SDK init (SysVariableInit/SysCpuInit/BoardInit...).
 *
 * Mirrors firmware/startup/startup.c (the BB equivalent) and the SDK's
 * Common/BootLoader/Start.s (START_VECT: [0]=SP, [1]=Main).
 */
#include <stdint.h>

typedef unsigned int uint32;

extern uint32 __stack_top;   /* firmware_ap.ld absolute symbol = 0x03050000 */
extern uint32 Main(void);

void Default_Handler(void) __attribute__((naked));
void Default_Handler(void)
{
    for (;;)
        __asm volatile("");
}

/* Cortex-M3 vector table (aligned 256 for VTOR). [0]=initial MSP, [1]=reset. */
const uint32_t ap_vectors[16]
    __attribute__((section(".vectors"), used, aligned(256))) = {
    (uint32_t)&__stack_top,             /* 0x00 initial MSP = 0x03050000 */
    (uint32_t)&Main,                    /* 0x04 Reset_Handler -> Main    */
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
