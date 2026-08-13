/*
 * ReChord AP (fw1) linker script — the RKnanoD A_CORE build (UI + drivers).
 *
 * Layout mirrors the Keil BuildAll.sct reference map:
 *   - SYS_DATA @ 0x03000000 (data + bss)
 *   - SYS_CODE @ 0x03060000 (code + rodata)
 *
 * Data is emitted before code so the location counter only moves forward.
 */

ENTRY(PowerOn_Reset)

MEMORY
{
    /* Stock A_CORE layout (Scatter/BuildAll.sct): SYS_CODE @ 0x03060000,
       SYS_DATA @ 0x03000000 (384 KB). The flat build previously overflowed
       SYS_DATA, forcing code to 0x03200000; after slimming the AP to the
       resident A_CORE the stock layout fits again. */
    FW_CODE (rx) : ORIGIN = 0x03060000, LENGTH = 0x00040000
    FW_RAM  (rwx): ORIGIN = 0x03000000, LENGTH = 0x00060000
}

__stack_top = 0x03050000;   /* header #1 SP (bootloader-analysis) */

/* Keil scatter-file symbols the SDK references */
Image$$AP_MAIN_STACK$$ZI$$Limit = 0x03050000;
Image$$AP_SYS_DATA$$ZI$$Base  = ORIGIN(FW_RAM);
Image$$AP_SYS_DATA$$ZI$$Length = LENGTH(FW_RAM);

SECTIONS
{
    .data ORIGIN(FW_RAM) :
    {
        _data_start = .;
        *(.data*)
        *(*Data)
        _data_end = .;
    } > FW_RAM

    .bss ALIGN(4) (NOLOAD) :
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        *(*Bss)
        *(*BSS)
        _bss_end = .;
    } > FW_RAM

    .heap (NOLOAD) :
    {
        __heap_start = .;
        . = ORIGIN(FW_RAM) + LENGTH(FW_RAM);
        __heap_end = .;
    } > FW_RAM

    .text ORIGIN(FW_CODE) :
    {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
        *(.ARM.extab*)
        *(.ARM.exidx*)
        . = ALIGN(4);
        *(*Code)
        *(*Text)
        *(*TEXT)
    } > FW_CODE
}
