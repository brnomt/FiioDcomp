/* QEMU echo-test linker — ReChord logic tests on mps2-an385.
 * FLASH/SSRAM @ 0x00000000 (code + vectors), SSRAM23 @ 0x20000000
 * (4MB: fb, logs, stack).
 *
 * Image$$BB_SYS_DATA$$ZI$$Base/Length = the region Main2's ScatterLoader2
 * zeroes at boot; pointed at QEMU RAM (0x20000000, 4KB). The telemetry
 * (0x20008000+) is outside this region so it survives. */
ENTRY(_start)
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x400000
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x400000
}
Image$$BB_SYS_DATA$$ZI$$Base = ORIGIN(RAM);
Image$$BB_SYS_DATA$$ZI$$Length = 0x1000;
SECTIONS
{
    . = ORIGIN(FLASH);
    .text : { *(.vectors) *(.text*) *(.rodata*) } > FLASH
    . = ORIGIN(RAM);
    .data : { *(.data*) } > RAM
    .bss  : { *(.bss*) *(COMMON) } > RAM
}
