/* QEMU mps2-an385 harness linker — test LCD drawing */
ENTRY(_start)
MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x100000
    RAM   (rwx): ORIGIN = 0x28000000, LENGTH = 0x40000
}
SECTIONS
{
    . = ORIGIN(FLASH);
    .text : { *(.vectors) *(.text*) *(.rodata*) } > FLASH
    .data : { *(.data*) } > RAM
    .bss  : { *(.bss*) *(COMMON) } > RAM
}
