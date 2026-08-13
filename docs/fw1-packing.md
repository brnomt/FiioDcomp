# fw1 (AP) packing — RKnanoFW container format & status

> Consolidated reverse-engineering of the **fw1/AP** image container so the
> "pack both halves" step can be completed correctly. The BB (section_3)
> container is a *flat* 16-byte header + code (already handled by
> tools/pack_img.py); **fw1 is different** — it is scatter-loaded by the
> Mask ROM through a memory-map table.

## 1. IMG layout (stock HIFIEC37.IMG, v3.7.0)

| IMG offset | Content |
|---|---|
| 0x000000 | outer header / part table |
| 0x0001F8 | **RKnanoFW header #1 (fw1/AP)** — magic + 0x03050000 + count 0x5B |
| 0x000208 | **memory-map table** — 91 entries x 16 B (0x208..0x7B8) |
| 0x0007B8 | fw1/AP payload: starts with a pointer table, then code/data |
| 0x057820 | **RKnanoFW header #2 (sec2 bootloader)** + strings (fw1 Sign error!) |
| 0x081A14 | **RKnanoFW header #3 (section_3/BB)** — magic + 0x0301E794 + count 0x52 |
| 0x081A24 | section_3 code (flat, firmware_entry @ 0x03000010) |
| 0x09BAA0E | ROCK resources |
| 0x02000000 | 4-byte trailer 0x1EA1C309 |

The three RKnanoFW sections are independent stages: the **Mask ROM loads fw1
via the memory-map table**, fw1/second-stage validates and then loads
**section_3 flat to 0x03000000** and jumps to firmware_entry @ 0x03000010.
That is why pack_img.py (flat section_3 splice) works, while fw1 needs the
scatter table.

## 2. RKnanoFW container format (confirmed against SDK)

Byte-exact, seen in both the Echo Mini IMG and the prebuilt
rk3399-table-RKNanoC SDK Firmware.img (offset 0xC2D7 there):

    [0:8]   "RKnanoFW"          magic (ASCII)
    [8:12]  uint32 LE           load base / initial SP
    [12:16] uint32 LE           entry count N
    [16..]  N x 16-byte entries (memory-map table)

- Echo Mini header #1: base **0x03050000**, count **0x5B** (91).
- Echo Mini header #3: base **0x0301E794**, count **0x52** (82, but NO table —
  section_3 is flat; the ROM treats count as flags there).
- SDK RKnanoC header: base **0x01000000** (its IRAM), count **0x3D** (61).

## 3. Memory-map entry format (two interleaved types)

Each entry is 4 x uint32 LE. The table alternates two shapes:

**Type B — load/copy** (even indices mostly), {dest, src, size, dest_end}:

| field | meaning | example (entry 2) |
|---|---|---|
| w0 | RAM destination | 0x030A61F4 |
| w1 | XIP source (flash) | 0x03079CC8 |
| w2 | byte size | 0x1604 |
| w3 | RAM end (== w0 + w2) | 0x030A77F8 |

**Type A — data/BSS region** (odd indices), {ram_start, size, ram_end, flash_size}:

| field | meaning | example (entry 1) |
|---|---|---|
| w0 | RAM start | 0x03004000 |
| w1 | region size | 0x1AFC |
| w2 | RAM end (== w0 + w1) | 0x03005AFC |
| w3 | total object size (may exceed the span) | 0x18C50 |

XIP mapping: **flash is XIP-mapped with IMG offset N <-> address 0x03000000+N**
(verified: entry 88's src 0x0308A5A4 -> IMG 0x8A5A4, which is section_3 code;
several src values land on erased/zero flash used to zero-fill data). The
scatter destinations (0x030A61F4 .. 0x0311EE04) are the *copy-to-RAM* window,
above the XIP image.

## 4. Why fw1 cannot simply be spliced like section_3

1. **Scatter table.** The Mask ROM loads fw1 through the 91-entry table; a
   flat binary has no way to express it. The table must be regenerated from
   the build's real section layout (what Rockchip's RKnanoTool.exe /
   My_tool.exe / RKImageMaker.exe do from the Keil AXF).
2. **Module overlay.** Stock fw1 is the RKnanoD *A_CORE* build
   (Scatter/BuildAll.sct): resident SYS_CODE @ 0x03060000 (256 KB) +
   SYS_DATA @ 0x03000000 (384 KB), with USB/Video/UI-windows/audio/BT/FM/
   record/codecs as **overlay modules** swapped into the same RAM on demand.
   Our flat AP build does not reproduce this; it links everything at once.
3. **Size mismatch.** Current AP ELF: .text 0x42814 (272 KB) @ 0x03200000,
   .data 0x3329C + .bss 0x93C18 (~814 KB) @ 0x03000000. The code base
   is 0x03200000 (not the stock 0x03060000) precisely because data+bss
   (~814 KB) overflows the stock 384 KB data window.

## 5. Path forward

1. **Resident A_CORE only** — restrict the AP manifest to the resident
   SysCode+SysData object set (kernel + UI core), link it at
   SYS_CODE 0x03060000 / SYS_DATA 0x03000000, and build each overlay
   module separately (mirroring the uvproj's A_CORE + per-codec targets).
2. **Generate the scatter table** from that build's section map (implement in
   tools/pack_fw1.py), or run Rockchip RKnanoTool.exe on the AXF and
   transplant its RKnanoFW section into the FiiO IMG.
3. **Validate on hardware UART** (fw1valid = %d fw2valid = %d) — the only
   authoritative check, since the ROM loader format is not fully documented.

See also docs/dispatch-map.md, docs/bootloader-analysis.md, docs/HARDWARE.md.

## 6. Size analysis (flat AP build, after .bss NOLOAD fix)

`firmware_ap.ld` now marks `.bss (NOLOAD)`; the ARMCC `zero_init` attribute is
ignored by GCC, so every `_ATTR_*_BSS_` section (e.g. `RecordControlBss`,
271 KB) lands in the output `.bss` (NOBITS) and is correctly zero-fill — this
cut the scatter payload from 1.30 MB to **694 KB**.

Remaining payload = RW FileSiz 0x3BA00 (244 KB `.data`+stack) + RX FileSiz
0x6DEE3 (450 KB `.text`+`.rodata`+ARM unwind tables). The fw1 region is
0x57068 (356 KB), so the flat build is still ~338 KB over.

Largest object contributors (`arm-none-eabi-size`, text+data+bss):

| group | total | note |
|---|---:|---|
| audio/RecordControl | 335 KB | 271 KB BSS (now zero-fill) + 57 KB data |
| audio/ID3 | 167 KB | ID3/Unicode tables — all code+rodata |
| audio/AudioControl | 127 KB | mostly `.data` |
| display/LcdInterface | 111 KB | LCD framebuffer/config `.data` |
| filesys/nFAT | 67 KB | FAT structures |
| bt/lwbt + radio/FMControl | 60 KB | BT + FM |

To fit 356 KB the AP must be split into the resident A_CORE (kernel +
drivers + filesystem + LCD) and on-demand overlay modules (ID3, RecordControl,
BT, FM, image codecs, UI windows) — the exact structure the Keil A_CORE +
per-codec targets already model. A flat GCC build of all 187 sources cannot
share their data the way the overlay scatter does.

## 7. Result — AP slims to 273 KB and packs (DONE)

The codec `.lib` (AP_CODEC_LIBS) and 40 overlay sources (audio codec
wrappers, ID3/AsicToUnicode, RecordControl, image, BT, FM, usbcontrol) were
removed from `ap.mk`; 72 weak stubs were added to `firmware/stubs.c` for their
entry points (they belong in the BB / overlay modules, not the resident UI).
The AP now links with 0 undefined symbols and its scatter payload is
**273,084 bytes** (< 356 KB), producing `build/ap/fw1_custom.img`.

`pack_img.py --pack-full` then emits `build/ReChord_APBB.IMG`: fw1 header
(SP 0x03050000, 3 entries) + payload @ 0x7B8, sec2 preserved, section_3
(SP 0x0301E794, count 82) @ 0x81A14, trailer 0x1EA1C309 — 33,554,436 bytes.

Remaining before claiming a *verified* boot: the AP UI now has stubbed
audio/BT/FM/image/record — it is the resident A_CORE, not the full player.
Hardware-UART validation (`fw1valid = %d fw2valid = %d`) is the authoritative
check that the scatter table + payload are accepted by the Mask ROM.
