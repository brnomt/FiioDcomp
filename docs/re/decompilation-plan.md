# Echo Mini Firmware — Decompilation Plan

## Objective

Modular C decompilation of the Fiio Echo Mini firmware (v3.7.0), structured like Rockbox, enabling arbitrary modifications.

## Chip: Rockchip RKnanoC

- **CPU**: ARM Cortex-M3, Thumb-2, little-endian
- **Clock**: 24 MHz crystal + PLL
- **Audio DAC**: Integrated (90dB SNR, 95.5dB volume range)
- **Peripherals**: USB 2.0 OTG, SPI flash, SDMMC, I2S, I2C, UART, SAR-ADC (3ch), PWM
- **Package**: LQFP64
- **SDK**: RKnano SDK 1.0 (all hardware I/O via boot ROM at 0x02FE0000-0x02FFFFFF)

## Phases

### Phase 1 — Ghidra Setup & Subsystem Mapping ✅

**Status: Complete** (audited against Ghidra project `FIIO-3.7.0-Decomp`)

- [x] Load section_3 in Ghidra (ARM:LE:32:v8-m, ~32MB, **2,232 functions**)
- [x] Run auto-analysis
- [x] Parse 25 segment descriptors into docs (`memory-map.md`); Ghidra keeps one `ram` block for section_3
- [x] Identify key init symbols: `firmware_entry`, `MusicInit`, `MusicService_Init` / `AudioPlayback_Start` (related audio paths; **not** a direct call chain)
- [x] Label **34** firmware functions with names + tags (plus ROM stub symbols)
- [x] Create **23** tag categories (codec, audio, os, ui, bluetooth, etc.)
- [x] Map ROM API stub block `ROM_API` @ `0x02FE0000`–`0x02FFFFFF` + named stub functions (`rom_alloc`, `rom_dac_mute`, …)
- [x] Create Rockbox-style directory scaffold
- [x] Write 12 API headers covering all subsystems
- [x] Document memory map with RKnanoC datasheet pin mappings
- [x] Create Makefile for arm-none-eabi-gcc

**Deliverables:**
```
docs/symbol-index.md     — 34 labeled functions with addresses
docs/memory-map.md       — full address space, segments, pinout
firmware/firmware.h      — address space, ROM, segment defines
firmware/*/              — 12 subsystem headers
Ghidra: FIIO-3.7.0-Decomp / section_3_0x00081A14.bin
```

**Ghidra notes (audit):**
- Entry is `firmware_entry` @ `0x03000010`; MusicInit/MusicService are called from `FUN_0304d022` / `FUN_0304e968`, not from entry.
- `AudioPlayback_Start` @ `0x0302a398` and `MusicService_Init` @ `0x0302a3e0` are contiguous (likely one routine / mid-entry — revisit later).
- Former `DICTDECODER_OpenFile` @ `0x0301020c` renamed to `MainUI_KeyHandler` (physical keypad + on-screen soft-keyboard GUI areas / EQ path — not capacitive touch). Real DICTDECODER strings: `DICTDECODER_InitStream` @ `0x0304fb44`.
- `rom_gui_check_area` @ `0x02ff7e0a` tests whether key/focus maps into an LCD rectangle (list rows, letter cells). Input is LADC button matrix.

---

### Phase 2 — Function Decompilation ✅

**Status: Complete** (Phase-2 subsystem scope — not all 2,253 functions)

#### Coverage (Ghidra, after this pass)

| Metric | Count |
|--------|------:|
| Total functions in binary | **2,256** |
| Custom-named (firmware + ROM stubs) | **115** |
| Still `FUN_*` / unlabeled | **2,125** |
| Phase-2 key symbols with `.c` reconstructions | **all planned subsystems + FS/bitstream/events** |

> Full-IMG goal owns the remaining **2,125** unlabeled functions.
> Latest pass: codec-overlay delay/runtime clones, WMA bitreader/memcmp/log2,
> APE ROM I/O thunks, BE bitreader, and signed saturation.

#### Substantial reconstructions

| File | Functions |
|------|-----------|
| `firmware/os/entry.c` | `firmware_entry`, `boot_param_layout` (corrected) |
| `firmware/apps/audio/music_*.c`, `volume_control.c` | MusicInit / MusicService / volume |
| `firmware/dsp/dsp_goedef*.c` | Init / Process / Reload |
| `firmware/media/format_list.c`, `id3_picture.c` | playlist + cover art |
| `firmware/apps/ui/main_ui_handler.c`, `bromem_sel_key_menu.c` | keypad UI |
| `firmware/apps/{bluetooth,recorder}/*` | BT + record |
| `firmware/codecs/{mp3,flac,aac,wma,wav,ogg,ape,dsd}/*` | all format parsers |
| `firmware/codecs/dict_decoder.c` | DICTDECODER_InitStream |
| `firmware/usb/usb_dac.c` | `USB_DAC_OpenStream` |
| `firmware/filesystem/hifi_file.c` | `HifiFileSeek` / `HifiFileRead` (+ overlay) |
| `firmware/filesystem/audio_file_buf.c` | AudioFile* double-buffer + FLAC seek IPC |
| `firmware/filesystem/buffered_io.c` | `buffered_fread` / `buffered_fseek` |
| `firmware/os/bitreader.c` | bitreader_* / bitstream_getbits |
| `firmware/os/hifi_runtime.c` | memmove, delay, IPC, debug printf |

#### Remaining (deferred / in progress for full-IMG C)

| Module | Notes |
|--------|-------|
| ~2,150+ `FUN_*` helpers | full-IMG goal; grind by xref + string anchors |
| HifiFile Open | SDK spin-wait; Open timeout string has no xrefs in Fiio binary |
| HifiFile Write/Close | Recovered @ `0x0306b9bc` / `0x0306ba1e` (ipc `0x6d` / `0x73`) |
| Power/Battery UI layer | ROM-delegated; only thin UI left |
| `DSD_DecodeBlock` FIR body | named in Ghidra; C has stub for the large FIR loop |
| `AudioPlayback_Start` / `MusicService_Init` split | revisit mid-function boundary |
| `MediaLib_GetTotalFiles` clones | `FUN_03000fb0` / `fd6` / `ff4` still unlabeled |

---

### Phase 3 — Safe Modding Toolkit 🟡

**Status: In progress** (resource extract / repack / trailer tools landed)

Goal: Tools that allow resource and code modification without bricking.

#### 3.1 Resource Tools (safe — zero brick risk) ✅ scaffolding

- [x] `tools/extract_resources.py` — Parse `ROCK26IMAGERES` + 108-byte metadata, export PNG + raw RGB565
- [x] `tools/repack_firmware.py` — Replace bitmaps by name, preserve EOF trailer
- [x] `tools/crc_util.py` — Read/write IMG EOF trailer (`0x1EA1C309` on V3.7.0; device may not verify)

**V3.7.0 facts (from stock `HIFIEC37.IMG`):**
| Item | Value |
|------|-------|
| Part5 (resource partition) | header `@0x14C` → off `0x9BAA0E`, size `0x16069E8` |
| ROCK26 entries | **1617** |
| Metadata entry | 108 B; name `@+0x00`, offset/w/h `@+0x60` (not 4-byte aligned) |
| Pixels | RGB565 **big-endian** (byte-swapped), offsets relative to part5 |
| IMG trailer | last 4 bytes LE (`0x1EA1C309`), **not** at `0x200000` |

```
python tools/extract_resources.py stock/ECHO\ MINI\ V3.7.0/HIFIEC37.IMG -o build/resources
python tools/repack_firmware.py stock/.../HIFIEC37.IMG -r build/replacements -o build/out.IMG
python tools/crc_util.py stock/.../HIFIEC37.IMG
```

#### 3.2 Code Patching (moderate risk — proven by community)

- Theme color patching via NOP slide + BL injection (Flame Ocean pattern)
- DSP firmware replacement (WOOOOONXBIN/GOODEFGHMP3)
- Font replacement (SMALL/LARGE glyph sets)
- Document all NOP slide regions found in the binary

#### 3.3 Full Rebuild (long-term goal — high effort)

- Complete decompilation of all 2,256 functions to C
- Set up RKnano SDK toolchain
- Verify binary-identical compilation
- Enable arbitrary code modifications

---

## Key Discovered Addresses

### Entry & Init
| Function | Address |
|----------|---------|
| `firmware_entry` | 0x03000010 |
| `MusicInit` | 0x0302b9d8 |
| `MusicService_Init` | 0x0302a3e0 |
| `AudioPlayback_Start` | 0x0302a398 |
| `FormatList_Init` | 0x03013c10 |

### Audio Hardware (via ROM) — stub names in Ghidra `ROM_API` block
| Function | ROM Address | Ghidra stub name |
|----------|------------|------------------|
| Alloc | 0x02feeedc | `rom_alloc` |
| HW init (shared) | 0x02feeebe / 0x02feee7c | `rom_hw_init` / `rom_hw_init2` |
| Early init | 0x02fe860e | `rom_early_init` |
| DAC mute | 0x02ff44ce | `rom_dac_mute` |
| DAC unmute | 0x02ff4580 | `rom_dac_unmute` |
| Sample rate set | 0x02ffa410 | `rom_sample_rate_set` |
| I2S master config | 0x02ff5752 | `rom_i2s_master_config` |
| DMA config | 0x02ff6814 | `rom_dma_config` |
| I2S/DMA start | 0x02ff68f0 | `rom_i2s_dma_start` |
| Audio path route/disable | 0x02ffa6f0 / 0x02ffa72a | `rom_audio_path_route` / `rom_audio_path_disable` |
| Audio clock | 0x02ff5c30 | `rom_audio_clock_setup` |
| memcpy | 0x02ff952e | `rom_memcpy` |
| USB connect | 0x02ffb2e0 | `rom_usb_connect` |

### DSP
| Function | Address |
|----------|---------|
| `DSP_GOODEF_Init` | 0x0300f7dc |
| `DSP_GOODEF_Process` | 0x0300fb0e |
| DSP firmware blob | "WOOOOONXBIN" (SPI flash file) |
| DSP config blob | "GOODEFGHMP3" (SPI flash file) |

### Theme/UI
| Function | Address |
|----------|---------|
| `FLAC_ThemeColor_Select` | 0x030054ba |
| `BroMemSelKeyMenu_Handler` | 0x03013280 |
| `MainUI_KeyHandler` | 0x0301020c |
| Theme E color register | 0x0301d750 (value: 0xE162) |
| Default theme color | 0x0301d750 (value: 0x44DE) |

### Codec Dispatch / DICTDECODER
| Function | Address | Notes |
|----------|---------|-------|
| `DICTDECODER_InitStream` | 0x0304fb44 | 'VaT '/'VAT ' container header parser (see `firmware/codecs/dict_decoder.c`) |
| `dict_stream_read` | 0x0304eec4 | buffered stream reader (4 storage modes) |
| `dict_build_frame_index` | 0x0304f90a | seek/frame-offset table builder |
| `DSP_GOODEF_Reload` | 0x0301022c | ex-`DICTDECODER_DispatchFile` — actually GOODEF DSP reload (not codec dispatch) |

### Codec Implementations
| Function | Address | Format |
|----------|---------|--------|
| `mp3_dec_internal` | 0x0306e5de | MP3 (libMad) |
| `mp3_id3v2_handler` | 0x0306fec4 | MP3 tags |
| `wma_audio_parse` | 0x0308cddc | WMA |
| `aac_aac_dec` | 0x030ad690 | AAC |
| `aac_movfile_parser` | 0x030aeb90 | M4A/MOV |
| `hifi_flac_dec` | 0x030df64c | FLAC |
| `hifi_flac_helper` | 0x030df52a | FLAC helper |
| `wav_lib_decode` | 0x030a42ee | WAV |
| `wav_lib_parse_header` | 0x030a46c8 | WAV header |
| `VorbisOGG_Parser` | 0x03023be8 | OGG Vorbis |
| `APE_Codec_Open` | 0x030eef60 | APE |

### Media/Tags
| Function | Address |
|----------|---------|
| `ID3_Picture_Parser` | 0x03023526 |
| Cover art MIME types | "image/jpeg", "image/bmp" |

### Bluetooth
| Function | Address |
|----------|---------|
| `BT_Music_Handler` | 0x0300ddea |
| BT display string | "BT Music " @ 0x0300e2d0 |

### Recording
| Function | Address |
|----------|---------|
| `RecordWinSvc_Start` | 0x0300aabc |
| Record path | "U:\\RECORD" @ 0x030005e4 |

### OS Primitives
| Function | Address |
|----------|---------|
| `event_set` | 0x0300c6b4 |
| `event_clear` | 0x0300c6f6 |
| `os_delay_ms` | ~~0x030098e4~~ → **`dac_gain_curve_apply`** |
| `event_set` / `event_clear` | ~~0x0300c6b4 / 0x0300c6f6~~ → **`0x03073840` / `0x03073882`** |
| `debug_printf` | ~~0x03012838~~ → **`MediaLib_thunk_GetFiles`** (real print: `hifi_debug_printf`) |
| Real busy-wait | `hifi_busy_delay` @ 0x0306c2e8 |
| `debug_printf` | 0x03012838 |

### Resource Table
| Item | Address |
|------|---------|
| ROCK26IMAGERES header | part5 `@ IMG+0x9BAA0E` (magic); **1617** entries |
| Metadata table | 108 B/entry; name@0, off/w/h@+0x60 (V3.7) |
| Total BMP resources | **1617** (was listed ~1,200) |
| Font sets | SMALL (+ LARGE TBD — Flame Ocean) |
| IMG trailer (CRC field) | **EOF** last 4 B = `0x1EA1C309` (not file offset `0x200000`) |

---

## Codec Library Versions (from embedded strings)

| Codec | Version | Date |
|-------|---------|------|
| MP2 decoder | 0.0.1 | 2012-03-31 |
| MP3 decoder | 0.0.1 | 2012-03-23 |
| WMA decoder | 0.0.1 | 2012-03-26 |
| AAC decoder | 0.0.1 | 2012-03-28 |

---

## Modding Opportunities

### Already Possible (Flame Ocean)
- Replace any of ~1,200 UI bitmaps (RGB565 format)
- Replace SMALL/LARGE fonts with custom glyphs
- Apply custom theme colors (5 themes, FLAC string, menu text)

### Phase 2 Will Enable
- Custom EQ presets (5-band parametric)
- Volume curve modification (120 levels, 0.375dB steps)
- DAC filter selection (fast/slow roll-off)
- Audio routing control (mono/stereo, channel swap)
- Sample rate mapping (44.1kHz vs 48kHz)
- BT track name display customization

### Phase 3 Will Enable
- Replace DSP firmware (WOOOOONXBIN) with custom processing
- Add new codec support (via `DICTDECODER_InitStream` dispatch)
- Custom boot animation (Z_POWERON0-16 sequence)
- Modify playlist/format list behavior
- Recording format/path customization
- USB DAC mode customization

## File Structure

```
firmware/
├── firmware.h                    # Global defines, address space
├── firmware/
│   ├── os/
│   │   ├── os_api.h              # Event system, ROM calls
│   │   └── entry.c               # Boot sequence, event loop
│   ├── filesystem/
│   │   └── fs_layer.h            # HifiFile I/O, FAT, media lib
│   ├── dsp/
│   │   ├── dsp_api.h             # GOODE DSP, EQ, volume
│   │   └── dsp_goedef.c          # DSP init + process
│   ├── media/
│   │   ├── media_api.h           # ID3, APEv2, cover art
│   │   └── format_list.c         # Format table, playlist
│   ├── usb/
│   │   └── usb_api.h             # USB DAC, mass storage
│   └── power/
│       └── power_api.h           # Battery, charging, sleep
├── codecs/
│   ├── codec_api.h               # Unified codec interface
│   └── {mp3,wma,aac,flac,ape,wav,ogg,dsd}/
├── apps/
│   ├── audio/
│   │   ├── audio_service.h
│   │   ├── music_init.c          # DAC/I2S/DMA setup
│   │   ├── music_service.c       # Playback engine
│   │   └── volume_control.c      # Volume, DAC filter
│   ├── ui/
│   │   └── ui_theme.h
│   ├── recorder/
│   │   ├── recorder.h
│   │   └── recorder.c            # RecordWinSvc
│   └── bluetooth/
│       ├── bt_handler.h
│       └── bt_handler.c          # BT Music handler
├── drivers/
│   └── drivers.h                 # LCD, keypad, DAC, SPI
└── resource/
    └── resource_api.h            # ROCK26IMAGERES, BMPs, fonts

docs/
├── decompilation-plan.md         # This file
├── symbol-index.md               # All labeled functions
└── memory-map.md                 # Address space, segments, pinout

tools/                            # Phase 3 — to be created
├── extract_resources.py
├── repack_firmware.py
└── crc_util.py
```
