/*
 * firmware/startup/startup.c
 * Minimal Cortex-M3 bring-up for v3.7.0 section_3 link tests.
 *
 * Stock Fiio images place a 16-byte RKnanoFW header @ 0x03000000 and
 * jump to firmware_entry @ 0x03000010 (bootloader passes boot params).
 * This file mirrors that layout for future `make link` experiments.
 */

#include <stdint.h>
#include "decomp_support.h"
#include "decomp_globals.h"

extern void firmware_entry(uint16_t *param);

/* 16-byte image header placeholder (magic filled by pack_img later) */
const uint32_t fw_image_header[4] __attribute__((section(".fw_header"), used)) = {
    0x03000000, 0x00000000, 0x00000000, 0x00000000,
};

/* Bootloader calls firmware_entry directly — not Reset_Handler */
void firmware_entry_trampoline(uint16_t *param)
{
    firmware_entry(param);
}

void Default_Handler(void)
{
    for (;;)
        ;
}
