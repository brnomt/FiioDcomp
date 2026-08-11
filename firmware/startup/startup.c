/*
 * ReChord startup — Echo Mini (RKnanoC) boot entry.
 *
 * The RKnano bootloader loads section_3 to RAM, reads the 16-byte
 * RKnanoFW header, and jumps to firmware_entry @ 0x03000010 passing
 * boot parameters in r0.
 *
 * This file:
 *   1. Provides the RKnanoFW header placeholder (pack_img fills magic).
 *   2. Defines firmware_entry -> calls the SDK's Main2.
 *   3. Provides a minimal vector table + Default_Handler for Cortex-M3.
 */
#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint32;

extern void Main2(void *boot_params);

/* ---- 16-byte RKnanoFW header (magic + load-addr + count) ----
 * pack_img.py rewrites the magic; load address 0x03000000 and the
 * count/flags 0x52 match the stock firmware. */
const uint32_t fw_image_header[4]
    __attribute__((section(".fw_header"), used, aligned(16))) = {
    0x03000000,  /* load address (RKnanoFW field) */
    0x00000052,  /* count / flags (matches stock) */
    0x00000000,  /* reserved */
    0x00000000,  /* reserved */
};

/* ---- firmware_entry @ 0x03000010 (bootloader jumps here, r0 = params) ---- */
void firmware_entry(void *boot_params)
    __attribute__((section(".text.firmware_entry"), naked, used));

void firmware_entry(void *boot_params)
{
    __asm__ volatile(
        "mov r0, r0\n"   /* keep boot_params (no-op, safe) */
        "b Main2\n");    /* jump into the SDK entry */
}

/* ---- Minimal Cortex-M3 vector table (first two entries) ---- */
extern uint32 __stack_top;
void Default_Handler(void) __attribute__((naked));

void Default_Handler(void)
{
    for (;;)
        ;
}

const uint32_t vectors[8]
    __attribute__((section(".vectors"), used, aligned(256))) = {
    (uint32_t)&__stack_top,   /* initial MSP */
    (uint32_t)&firmware_entry, /* Reset_Handler -> firmware_entry */
    0, 0, 0, 0, 0, 0,
};
