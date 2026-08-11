# Fiio Echo Mini — Firmware Decompilation

Reverse engineering of the **Fiio Echo Mini** firmware, a digital audio player (DAP) based on a **Rockchip RKnanoC** SoC (ARM Cortex-M3, Thumb-2).

## Disclaimer

This project is an independent reverse engineering effort.

It is not affiliated with, endorsed by, or supported by FiiO, SNOWSKY, or any of their subsidiaries.

The software, documentation, and tools provided here are intended for research, educational, and interoperability purposes only.

Flashing modified firmware always carries a risk of data loss or rendering a device unusable ("bricking"). Use any tools or information in this repository at your own risk. The authors assume no responsibility for any damage, data loss, or other consequences resulting from their use.

Firmware images are not distributed by this repository. Users are expected to obtain firmware from official sources.

## Contribution Policy

Please do not submit copyrighted firmware binaries or proprietary code extracted from official firmware images.

Reverse engineering notes, documentation, tooling, patches, and clean-room implementations are welcome.

## Project Goals

- Document the Echo Mini firmware format.
- Analyze the boot process and memory layout.
- Develop open-source analysis and patching tools.
- Enable reproducible firmware research.
- Explore safe firmware modifications and custom features.

## RE Progress (Aug 2026)

Function naming status in Ghidra (v3.7.0, live): **651 / 2,776 functions named (23.4%)**
Decompiled to pseudocode: **2,764 / 2,776** (see `build/all_decompilations.json`)

Run `python tools/check_decompilation_status.py` for a live status from Ghidra.

| Approach | Functions named |
|----------|---------------|
| Manual analysis + Ghidra auto-analysis | 188 |
| Distinctive constant matching (>= 0x100) | +85 |
| Structural matching (code shape fingerprint) | +195 |
| Combined constant + structural matching | +67 |
| Call graph propagation (SDK callee index) | +80 |
| ROM API naming + similarity matching | +15 |
| Additional matching pass (Aug 2026) | +27 |

All matching uses leaked Rockchip SDK source (`RKNanoD_MP3_V1.3` + `RKNanoD_Wireless_Audio_SDK_V1.5`)
as reference. See `docs/sdk-matching-progress.md` for full details.

## Multi-Version Differential Analysis (NEW)

**All 23 firmware versions are in `stock/`** (v1.2.5 → v3.8.0), each with its
official changelog in `Read me.txt`. We use **changelog-anchored version diffing**
to name functions with certainty: each changelog entry maps to a cluster of
changed functions between adjacent versions.

Progress so far (backwards from v3.7.0, all saved in Ghidra):

| Version | Program in Ghidra | Named funcs | Done via |
|---------|-------------------|------------:|----------|
| **v3.7.0** | `section_3_0x00081A14.bin` | **651** | primary program (decompiled + exported) |
| **v3.6.0** | `sec3_3_6_0.bin` | ~25 | fuzzy match vs 3.7.0 (9 renames) |
| **v3.5.0** | `sec3_3_5_0.bin` | **75** | 1,141 fuzzy matches + 3.5→3.6→3.7 chain propagation |
| **v3.4.0** | `sec3_3_4_0.bin` | **104** | 1,132 fuzzy matches + 3.4→3.5→3.6→3.7 chain (73 direct + 39 chained) |
| **v3.3.0** | `sec3_3_3_0.bin` | **106** | 1,163 fuzzy matches + 4-hop chain to v3.7 (71 direct + 79 chained; relink shift) |
| **v3.2.0** | `sec3_3_2_0.bin` | **91** | 1,154 fuzzy matches + 5-hop chain to v3.7 (77 direct + 76 chained; relink shift) |
| **v3.1.0** | `sec3_3_1_0.bin` | **94** | 1,201 fuzzy matches + 6-hop chain to v3.7 (78 direct + 77 chained) |
| **v3.0.0** | `sec3_3_0_0.bin` | **94** | 1,203 fuzzy matches + 7-hop chain to v3.7 (77 direct + 77 chained) |
| **v2.8.0** | `sec3_2_8_0.bin` | **95** | 1,128 fuzzy matches + 8-hop chain to v3.7 (75 direct + 75 chained) |
| **v2.7.0** | `sec3_2_7_0.bin` | **92** | 1,149 fuzzy matches + 9-hop chain to v3.7 (75 direct + 75 chained) |
| **v2.6.0** | `sec3_2_6_0.bin` | **94** | 1,119 fuzzy matches + 10-hop chain to v3.7 (75 direct + 75 chained) |
| **v2.5.0** | `sec3_2_5_0.bin` | **89** | 1,168 fuzzy matches + 11-hop chain to v3.7 (73 direct + 73 chained) |
| **v2.4.0** | `sec3_2_4_0.bin` | **89** | 1,135 fuzzy matches + 12-hop chain to v3.7 (73 direct + 73 chained) |
| **v1.8.0** | `sec3_1_8_0.bin` | **89** | 1,086 fuzzy matches + 13-hop chain to v3.7 (74 direct + 74 chained) |
| **v1.7.0** | `sec3_1_7_0.bin` | **90** | 1,064 fuzzy matches + 14-hop chain to v3.7 (78 direct + 78 chained) |
| **v1.6.2** | `sec3_1_6_2.bin` | **92** | 1,073 fuzzy matches + 15-hop chain to v3.7 (78 direct + 78 chained) |
| **v1.5.0** | `sec3_1_5_0.bin` | **94** | 1,086 fuzzy matches + 16-hop chain to v3.7 (78 direct + 78 chained) |
| **v1.4.6** | `sec3_1_4_6.bin` | **94** | 1,109 fuzzy matches + 17-hop chain to v3.7 (78 direct + 78 chained) |

**⚠️ READ `docs/MULTI-VERSION-PLAN.md` FIRST** — it is the complete handoff
document for this workflow (corpus dedup, string diffs, Ghidra MCP API,
segment-table diffs, tool inventory, pitfalls, and next steps).

## Repository Structure

```
firmware/                       # Rockbox-style modular C project (decompiled)
├── firmware.h                  # Address space, ROM calls, segment defines
├── rockchip/                   # RKNanoD SDK v1.3 port (reference C + codec blobs)
├── firmware/
│   ├── os/                     # Event system, delays, OS primitives
│   ├── filesystem/             # HifiFile I/O, FAT wrapper, media library
│   ├── dsp/                    # GOODE DSP chip, EQ processing
│   ├── media/                  # ID3v2/APEv2/Vorbis tags, format list
│   ├── usb/                    # USB DAC mode, mass storage
│   └── power/                  # Battery, charging, sleep timer
├── codecs/                     # Audio codec interfaces (MP3/WMA/AAC/FLAC/APE/WAV/OGG/DSD)
├── apps/
│   ├── audio/                  # MusicInit, MusicService, playback engine
│   ├── ui/                     # Display, themes, menu system
│   ├── recorder/               # RecordWinSvc
│   └── bluetooth/              # BT audio handler
├── drivers/                    # LCD, keypad, DAC IC, flash, SD card
└── resource/                   # ROCK26IMAGERES table, bitmaps, fonts

docs/                           # Documentation
├── MULTI-VERSION-PLAN.md       # ⚠️ HANDOFF: full multi-version diff workflow
├── changelog-string-diff.md    # Changelog × string-diff correlation (auto-gen)
├── symbol-index.md             # Labeled function reference
├── memory-map.md               # Complete memory map + SoC pinout
├── fork-strategy.md            # SDK vs Ghidra source model
├── flashing-guide.md           # What you can flash today
├── sdk-porting.md              # SDK grab guide
└── re-backlog.md               # Prioritized FUN_* RE work

stock/                          # Reference firmware (not distributed)
├── 1.2.5 … 3.8.0/              # ALL 23 firmware versions, each with Read me.txt changelog

tools/                          # Analysis and patching scripts
Makefile                        # Build system (arm-none-eabi-gcc target)
```

## The Chip: RKnano

The Echo Mini runs on a **Rockchip RKnano** SoC with the following characteristics:

- **CPU**: ARM Cortex-M (Thumb-2 ISA, little-endian)
- **SDK**: RKnano SDK 1.0
- **Load address**: `0x0301E794` (main firmware RAM base)
- **Firmware container**: Multi-image format with `RKnanoFW` magic

## HIFIEC37.IMG Container Format

The firmware image is a multi-section container with CRC verification:

| Offset | Size | Content |
|--------|------|---------|
| `0x000000` | 504 B | Outer header: date, chip ID, magic `0x06222026`, sentinel `0x76543210` |
| `0x0001F8` | 358 KB | Section 1 — Relocation table (~200 segment entries) |
| `0x057820` | 173 KB | Section 2 — Bootloader: verifies firmware signatures ("fw1 Sign error!", "fw1 compare error!") |
| `0x081A14` | 31.25 MB | **Section 3 — Main firmware** (executable ARM Thumb-2 code) |
| `0x1FC41F8` | 245 KB | Section 4 — Padding (all zeros) |
| EOF `-4` | 4 B | Trailer / CRC field: `0x1EA1C309` (file size `0x2000004`) |

## Section 3 — Main Firmware

This is the code blob that runs on the device. It starts with the `RKnanoFW` header immediately followed by ARM Thumb instructions:

```
RKnanoFW              → container magic
0x0301E794            → load address
0x00000052            → count/flags
10 B5                 → PUSH {R4, LR}       ← code entry point
04 46                 → MOV R4, R0
00 F0 61 F8           → BL sub_xxx
```

The segment table in `section_1` describes how different modules are mapped into memory. It includes code regions, data, stacks, and likely on-demand overlays.

## Device Features (from changelogs)

The firmware implements the following features:

- **Audio**: MP3, FLAC, M4A, OGG, DSD (DFF/DSF), WAV/RIFF playback
- **DAC**: USB DAC mode (48 kHz, driverless)
- **Equalizer**: Custom EQ + presets (including "Retro EQ")
- **Bluetooth**: Playback and auto-reconnect
- **Display**: UI themes, album art, synced lyrics, screensaver
- **Controls**: 3 button modes (A/B/C) with different volume/track switching configurations
- **Storage**: Media library with ID3 tags, favorites, folder/artist/album/genre browsing
- **Extras**: Adjustable gain, channel balance, configurable DAC filters

## How to Use the Extracted Files

### Loading into Ghidra

The main file to analyze is `section_3_0x00081A14.bin`:

1. Open Ghidra, create a new project
2. Import the binary with:
   - **Language**: ARM → Cortex → little-endian → Thumb
   - **Base address**: `0x0301E794` (firmware load address)
3. Ghidra will auto-disassemble Thumb-2 instructions
4. Use the segment table from `section_1` to identify code vs. data regions

### String Search

The binary contains readable strings revealing:
- RKnano SDK module and function names
- Supported audio formats
- Error and debug messages
- UI text strings

## Notes

- The firmware is **not encrypted** — all strings and code are directly visible in the binary
- The image is a standard RKnano SDK container, not a Fiio proprietary format
- Two hardware variants exist: standard and 512 MB (`MINIV370.IMG`)
- The bootloader (section 2) implements signature verification, but it's not enforced during normal boot

## Useful Tools

- [Ghidra](https://ghidra-sre.org/) — Disassembler/decompiler (native ARM Thumb support)
- `arm-none-eabi-objdump` — Quick command-line disassembly
- `strings` — Extract all readable strings from the binary
