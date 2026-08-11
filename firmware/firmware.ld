/*
 * Linker script for Echo Mini v3.7.0 main firmware (section_3 code region).
 *
 * Load address 0x03000000 matches Ghidra / HIFIEC37.IMG section_3.
 * RAM layout follows segment table in docs/memory-map.md (simplified).
 */

ENTRY(firmware_entry)

MEMORY
{
    /* Code in SPI-loaded firmware window (first ~9.6 MB of section_3 code) */
    FW_CODE (rx)  : ORIGIN = 0x03000000, LENGTH = 0x00939000
    /* On-chip SRAM for data/stack (0x03005AFC .. 0x03060000) */
    FW_RAM  (rwx) : ORIGIN = 0x03005AFC, LENGTH = 0x0005A504
}

/* Main stack top — 16 KiB block @ 0x0301E794 per segment table */
__stack_top = 0x0301E794 + 0x4000;

SECTIONS
{
    . = ORIGIN(FW_CODE);

    .fw_header 0x03000000 :
    {
        KEEP(*(.fw_header))
    } > FW_CODE

    .text 0x03000010 :
    {
        KEEP(*(.text.firmware_entry))
        *(.text*)
        *(.rodata*)
    } > FW_CODE

    . = ORIGIN(FW_RAM);

    .data :
    {
        _data_start = .;
        *(.data*)
        _data_end = .;
    } > FW_RAM

    .bss :
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > FW_RAM

    /* Discard unwieldy SDK sections until overlay model is ported */
    /DISCARD/ :
    {
        *(.ARM.exidx*)
        *(.ARM.extab*)
    }
}
