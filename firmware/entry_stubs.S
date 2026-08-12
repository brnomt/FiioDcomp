/* entry_stubs.S — ReChord boot entry + ROM-dispatch trampolines.
 *
 * The RKnano boot ROM / loader calls FIXED offsets in section_3 for
 * specific purposes (see docs/bootloader-analysis.md):
 *   0x03000010  firmware_entry       (boot, HW init, return)
 *   0x03000162  FUN_03000162         (USB/MSC misc)
 *   0x0300016c  WriteData_To_Flash   (USB MSC write)
 *   0x0300024e  MscTestUnitReady     (USB MSC)
 *   0x03000296  FUN_03000296
 *   0x030004f4  FUN_030004f4
 *   0x03000546  RKDev_Close
 *   0x03000a72  FUN_03000a72
 *   0x03000a74  DeleteDeviceListEmmcDataBase
 *   0x03000aba  main2_entry          (USB mass-storage mode)
 *   0x0300710a  application_start    (UI event callback)
 *
 * V0.1-V0.8 all crashed/froze on menu press because our binary had
 * GARBAGE at these offsets (the ROM/loader dispatches here). These
 * trampolines make every dispatch safe (return), and firmware_entry
 * starts our C app. All compiled from source — no binary patching.
 *
 * NOTE: stubs are 2-byte `bx lr` (0xa72 and 0xa74 are only 2 bytes
 * apart in stock — they cannot both hold 4-byte stubs).
 */
    .syntax unified
    .thumb

    .section .text.boot, "ax"
    .balign 2

    /* firmware_entry @ 0x03000010 — bootloader jumps here, r0 = boot params */
    .global firmware_entry
    .thumb_func
firmware_entry:
    push {r4}
    mov  r4, r0
    b    rechord_app

    /* --- ROM/loader dispatch trampolines (bx lr = return) --- */
    .org 0x152                    /* -> 0x03000162 */
    .thumb_func
stub_03000162:
    bx   lr

    .org 0x15c                    /* -> 0x0300016c */
    .thumb_func
stub_0300016c:
    bx   lr

    .org 0x23e                    /* -> 0x0300024e */
    .thumb_func
stub_0300024e:
    bx   lr

    .org 0x286                    /* -> 0x03000296 */
    .thumb_func
stub_03000296:
    bx   lr

    .org 0x4e4                    /* -> 0x030004f4 */
    .thumb_func
stub_030004f4:
    bx   lr

    .org 0x536                    /* -> 0x03000546 */
    .thumb_func
stub_03000546:
    bx   lr

    .org 0xa62                    /* -> 0x03000a72 */
    .thumb_func
stub_03000a72:
    bx   lr

    .org 0xa64                    /* -> 0x03000a74 (2 bytes after prev) */
    .thumb_func
stub_03000a74:
    bx   lr

    .org 0xaaa                    /* -> 0x03000aba */
    .thumb_func
stub_03000aba:
    bx   lr

    .org 0x70fa                   /* -> 0x0300710a */
    .thumb_func
stub_0300710a:
    bx   lr

    .org 0x7104                   /* pad to 0x03007114 */
    .section .text, "ax"          /* continue normal code layout after */
