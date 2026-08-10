# Reverse Engineering Backlog

Prioritized `FUN_*` and gap work after SDK port into `firmware/rockchip/`.

**Ghidra:** `FIIO-3.7.0-Decomp` / `section_3_0x00081A14.bin`  
**Status:** 2,258 functions, **151 named**, **2,106 `FUN_*` remaining**

Workflow for each item:
1. Check if `firmware/rockchip/` SDK source already documents it
2. If yes → verify at Fiio address in `fiio_map.h`, port delta to `firmware/fiio/`
3. If no → decompile in Ghidra, land C in `firmware/fiio/` or `firmware/codecs/`

---

## P0 — Unblocks build / flash understanding

| Target | SDK reference | Fiio status | Notes |
|--------|---------------|-------------|-------|
| ~~`HifiFileWrite` / `Close`~~ | `bbsystem/audio_file_access2.c` | **Done** @ `0x0306b9bc` / `0x0306ba1e` | ipc `0x6d` / `0x73`; see `hifi_file.c` |
| `HifiFileOpen` handshake | SDK spin-wait only | Partial | Timeout string unused in Fiio binary |
| IMG section packer | `SDK Development/firmware_generate_*` | Missing | Need `tools/pack_img.py` |
| Linker scatter | `SDK Scatter/BuildAll.sct` | Missing | Port to `firmware/firmware.ld` |
| `firmware_entry` callers | `bbsystem/Main2.c` | Partial | Trace init chain from `0x03000010` |

---

## P1 — Fiio-only (no SDK source)

| Symbol | Address | File to extend |
|--------|---------|----------------|
| `DICTDECODER_InitStream` | `0x0304fb44` | `firmware/codecs/dict_decoder.c` |
| `dict_stream_read` | `0x0304eec4` | same |
| `dict_build_frame_index` | `0x0304f90a` | same |
| `DSP_GOODEF_Init/Process/Reload` | `0x0300f7dc`… | `firmware/firmware/dsp/dsp_goedef*.c` |
| `wma_audio_parse` + helpers | `0x0308cddc`… | `firmware/codecs/wma/wma_dec.c` |
| `FLAC_ThemeColor_Select` | `0x030054ba` | `firmware/apps/ui/` |
| `DSD_DecodeBlock` FIR loop | `0x030ffa3c` | `firmware/codecs/dsd/dsd_dec.c` (stub) |
| ROCK26 resource embed | part5 @ IMG | `tools/repack_firmware.py` (done) |

---

## P2 — Verify SDK port vs Fiio binary

| SDK file | Key symbols | Fiio address |
|----------|-------------|--------------|
| `audio/AudioControl/AudioControl.c` | `MusicInit`, `MusicService` | `0x0302b9d8`, `0x0302a3e0` |
| `bbsystem/audio_file_access2.c` | `HifiFileSeek/Read` | `0x0306b8e6`, `0x0306b94c` |
| `audio/Common/pCODECS.c` | `CodecOpen`, `CodecDecode` | xref from `audiocodec_open` |
| `system/module_overlay/ModuleOverlay.c` | `ModuleOverlay()` | overlay clones @ `0x0308175c`… |
| `system/sysservice/PowerManager.c` | battery/sleep | ROM-delegated; thin UI left |

**Action:** Diff SDK logic against Ghidra decomp at mapped address. Replace `firmware/firmware/*` decomp stubs with SDK port where they match.

---

## P3 — Ghidra boundary repair

Do **not** trust decompiler bodies until fixed:

| Symbol | Address | Issue |
|--------|---------|-------|
| `hifi_busy_delay_ovl_09e3` | `0x0309e334` | Body starts ~0xB00 before entry |
| `hifi_busy_delay_ovl_0e48` | `0x030e4808` | same |
| `hifi_busy_delay_ovl_0fd1` | `0x030fd100` | same |

Fix: `delete_function` + `create_function` at true entry in Ghidra.

---

## P4 — Grind `FUN_*` by subsystem (when forking)

Use Ghidra string xrefs and call-tree from named anchors:

| Anchor | Start xref scan for |
|--------|---------------------|
| `MusicInit` | audio state machine helpers |
| `DICTDECODER_InitStream` | container/stream parsers |
| `mp3_dec_internal` | libMad helpers |
| `MainUI_KeyHandler` | menu/keypad handlers |
| `FormatList_Init` | media library |
| `BT_Music_Handler` | bluetooth stack glue |

Tag named functions in Ghidra → update `docs/symbol-index.md`.

---

## Done / in progress (repo)

- [x] SDK framework copied to `firmware/rockchip/` (179 files)
- [x] `fiio_map.h` address cross-reference
- [x] Ghidra: all codec entry points named
- [x] Resource extract/repack tools
- [ ] Wire SDK into Makefile
- [ ] `tools/pack_img.py`
- [ ] Replace decomp stubs with verified SDK ports
