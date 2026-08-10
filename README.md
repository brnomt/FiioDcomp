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
├── symbol-index.md             # Labeled function reference
├── memory-map.md               # Complete memory map + SoC pinout
├── fork-strategy.md            # SDK vs Ghidra source model
├── flashing-guide.md           # What you can flash today
├── sdk-porting.md              # SDK grab guide
└── re-backlog.md               # Prioritized FUN_* RE work

stock/                          # Reference firmware (not distributed)
├── ECHO MINI V3.7.0/           # Firmware version 3.7.0
└── ECHO MINI 512M/             # 512 MB variant

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
