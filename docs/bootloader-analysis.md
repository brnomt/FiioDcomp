# Bootloader & fw1/fw2 validation analysis (Echo Mini, V3.7.0 IMG)

**Date:** (stub-fix turn, after V0.6 failed identically to V0.1-V0.5)

**Why this doc exists:** V0.1-V0.6 (all our section_3 replacements) behave
IDENTICALLY on device: cassette UI + navigation works, no ReChord strings,
menu press → freeze + watchdog. That is consistent with EITHER (a) our BB
runs but the mailbox is stubbed, OR (b) **the bootloader rejects our
section_3 (fw2) during validation and the BB never loads**. This document
records what we proved about the boot side so the next agent can pick up
the UART test.

## IMG layout (3.7.0, 0x2000004 bytes = 32MB + 4 trailer)

| IMG offset | Content |
|---|---|
| 0x0001f8 | RKnanoFW header #1: SP=0x03050000, count=0x5b (91) + **memory-map table** (91 × 16B, 0x208-0x7B8) |
| 0x0007b8 | fw1/AP code region (0x7B8-0x57820) — contains the fw1/fw2 error-print code (refs @ 0x383xx-0x42cxx) |
| 0x00057820 | RKnanoFW header #2 (sec2 bootloader): SP=0x0301e2d4, "loadbase" 0x0301e2c0, then strings |
| 0x00057834 | `fw1 Sign error!` … `fw1valid = %d fw2valid = %d` (string table, ends ~0x578ac) |
| 0x000578cc | sec2 code: check function + LCD/status funcs (sec2 spans 0x57820-0x81a14) |
| 0x00081a14 | RKnanoFW header #3 (**fw2 = section_3, OUR target**): SP=0x0301e794, count=0x52, entry @ 0x03000010 |
| 0x0009baa0e | `ROCK` — resources start (one big resource block to 0x1ffffff) |
| 0x02000000 | trailer magic 0x1EA1C309 (constant, NOT a CRC of content) |

Boot strings confirmed: `fw1 Sign error!`, `fw1 compare error!`,
` fw2 compare error! 0x%x`, `No find fw2!`, `fw1 && fw2 error!`,
`fw2 error!`, `fw1valid = %d fw2valid = %d`.

## sec2 bootloader check function (Ghidra: sec2_bootloader.bin @ 0x030000ac)

sec2_bootloader.bin = IMG[0x57820..0x81a14] imported at 0x03000000
(162 functions). Runtime mapping: **RAM = Ghidra_addr + 0x0301e2b0**
(header load base 0x0301e2c0 ↔ Ghidra 0x10).

```c
undefined4 check_fw(void) {
  puVar2 = 0x0306fda8;              // validator table (literal @ Ghidra 0x30000e8)
  *0x0301e2c4 = 0;                  // zero first byte of "fw1 Sign error!" (overlay var)
  *(0x030059d0+0xc/0x10/0x14) = 0;  // zero 3 status dwords
  for (i=0; i<2; i++) {
    if ((*(code *)*puVar2)() != 0) err = -1;   // call *(0x0306fda8), then *(0x0306fdd0)
    puVar2 += 10;                   // +0x28 bytes per entry
  }
  return err;
}
```

- The 2 validators are read as POINTERS from RAM 0x0306fda8 / 0x0306fdd0.
- 0x0306fda8 is in a GAP of the memory map (not loaded from flash) → the
  table is **populated at runtime by the chip ROM (0x02FE0000-0x03000000,
  invisible — no ROM code available)**. The validators are ROM functions.
- The strings are only referenced by code at IMG 0x38000-0x43000
  (fw1/AP region) and in sec2 — i.e., the validation/print logic runs from
  the AP/loader side, the validators live in the ROM.

## Memory-map table (header #1 @ 0x1f8, count=0x5b, entries 0x208-0x7B8)

Format (partially decoded): two interleaved entry types:

- **Type A (small RAM):** `(RAM_start, size, RAM_end, flash_size)` with
  `RAM_end == RAM_start+size`. Examples:
  - 0x0218: RAM 0x03004000-0x03005afc, fsize 0x18c50 (audio buffers; 0x03005AFC = audio buffer)
  - 0x02f8/0x0318: BSS — RAM 0x0301e778 (fsize 0x10000 = FAT cache), 0x0301e794 (0x4000 = main stack)
  - **0x0478: RAM 0x030247a8-0x03024868, fsize 0xfb20 → 0x03024868 = UI framebuffer
    (0xfb20 = 64,288 bytes, matches bitmap sizes). The framebuffer is loaded FROM FLASH.**
- **Type B (big copy):** `(RAM_start, flash_base, flash_offset, RAM_end)`
  — e.g. 0x0228 (0x030a61f4, 0x03079cc8, 0x1604, 0x030a77f8),
  0x02c8 (0x030cf574, 0x03079cc8, 0x1210, 0x030d0784). flash_base values are
  0x03000000+section_3-file-offset (0x03079cc8 → IMG 0xF9EDC).

The sequential flash-cursor interpretation FAILED (sum overflowed), so the
exact per-region flash sources are NOT yet derived. Needed: the sec2/ROM
loader loop. 0x0306fda8 is in a map GAP (0x03057698-0x030795cc) — free RAM.

## Open questions / next steps

1. **Does the bootloader accept our section_3?** The `fw2 compare error!
   0x%x` string proves a checksum/compare validation exists (algorithm in
   ROM, invisible). Our 50KB section_3 (stock 3.1MB) may fail it → BB never
   loads → AP waits on mailbox → menu freeze (matches ALL V0.1-V0.6).
2. **DECISIVE TEST = UART.** Boot prints `fw1valid = %d fw2valid = %d`.
   A 3.3V USB-UART adapter on PB5 (UART TX, Echo Mini board test pad)
   answers everything in one capture. Secondarily, our BB can `bb_printf1`
   on the same UART to prove it runs.
3. If validation is a checksum: find the algorithm by testing (flash a
   single-byte-flipped stock section_3, see if boot changes) or by
   capturing UART error output (`fw2 compare error! 0x%x` prints the value).
4. Ghidra: sec2_bootloader.bin (162 funcs) is in project
   `FIIO-3.7.0-Decomp`; section_3 program covers 0x03000000+; ROM_API block
   at 0x02FE0000 is an EMPTY placeholder (no ROM bytes available).
