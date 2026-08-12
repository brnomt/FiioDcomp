/* qemu_fault_probe.c — verify our VTOR + UDF fault-routing logic on a real
 * Cortex-M3 core in QEMU (mps2-an385).
 *
 * Mirrors firmware/fault.c + the V0.16 probe (rechord_firmware_entry):
 *   - a 256-aligned vector table whose HardFault/UsageFault entries point
 *     to a naked handler that reads PC from the exception frame
 *   - set VTOR to our table
 *   - execute 'udf #0' (UsageFault -> HardFault)
 *   - the handler writes {magic, PC, SP} to a RAM log and loops
 *
 * On the DEVICE (V0.16) this probe showed "no change" — we need to know if
 * the LOGIC is correct (it should be) so we can conclude the ROM never
 * called our firmware_entry. In QEMU we can READ the log via the monitor.
 */
#include <stdint.h>

#define CRASH ((volatile uint32_t *)0x20008000u)
#define CRASH_MAGIC 0x52454348u   /* 'RECH' */
#define VTOR   (*(volatile uint32_t *)0xE000ED08u)

__attribute__((naked)) void hardfault_handler(void)
{
    __asm__ volatile(
        "mov r0, sp\n"          /* exception frame: r0,r1,r2,r3,r12,lr,pc,xpsr */
        "ldr r1, [r0, #24]\n"   /* PC at +24 */
        "b  fault_c\n");
}

void fault_c(uint32_t sp, uint32_t pc)
{
    CRASH[0] = CRASH_MAGIC;
    CRASH[1] = pc;
    CRASH[2] = sp;
    CRASH[3] = 0x0BADF00Du;
    for (;;) ;
}

void _start(void)
{
    /* show liveness: a write the monitor can see even if the fault fails */
    CRASH[0] = 0x44454144u;   /* 'DEAD' = start reached, probe not yet run */

    extern const uint32_t vectors[];
    VTOR = (uint32_t)vectors;   /* our 256-aligned table */
    __asm volatile("udf #0" ::: "memory");   /* deliberate fault */

    /* if we get here, the fault did NOT route to our handler */
    CRASH[0] = 0x4E4F4655u;   /* 'NOFU' = fault not routed */
    for (;;) ;
}

__attribute__((section(".vectors"), used, aligned(256)))
const uint32_t vectors[8] = {
    0x203FFFF0u,                     /* initial MSP (top of RAM) */
    (uint32_t)_start,                /* reset */
    (uint32_t)hardfault_handler + 1, /* NMI */
    (uint32_t)hardfault_handler + 1, /* HardFault */
    (uint32_t)hardfault_handler + 1, /* MemManage */
    (uint32_t)hardfault_handler + 1, /* BusFault */
    (uint32_t)hardfault_handler + 1, /* UsageFault */
    0,
};
