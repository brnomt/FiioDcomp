# Fork Strategy — Fiio Echo Mini Firmware

## Goal

Produce a **forkable, readable C codebase** that behaves like Fiio Echo Mini v3.7.0 firmware.
This is **not** a byte-identical recovery of every function in the binary.

Success looks like: someone clones the repo, reads the code, understands how playback/UI/codecs
work, and can modify features without opening Ghidra.

## Two-Source Model

| Source | Use for | Do not use for |
|--------|---------|----------------|
| **RKNanoD SDK** (MP3 v1.3 + Wireless v1.5) | Framework: `MusicInit`, `MusicService`, `HifiFile*`, `pCODECS`, OS/tasks, overlays, UI shell | Fiio-specific code; codec internals (SDK ships blobs only) |
| **Ghidra** (`FIIO-3.7.0-Decomp`) | Everything Fiio changed or added | Generic Rockchip plumbing the SDK already documents |

### SDK handles (~60–70% of framework)

- Audio engine (`Common/Codec/Audio/AudioControl/`)
- File I/O (`Common/BBSystem/audio_file_access2.c`)
- Codec dispatch (`pCODECS.c`)
- OS / events / tasks (`Common/System/`)
- Module overlays (`Common/System/ModuleOverlay/`)
- UI scaffolding (`SDK_160_128/UI/`)

Port these with a file header noting SDK origin + Fiio address if verified.

### Ghidra handles (Fiio deltas + codecs)

- `DICTDECODER` / `VaT`/`VAT` container layer
- `ROCK26IMAGERES` resource format (1617 RGB565 assets in IMG)
- `GOODEF` external DSP (`WOOOOONXBIN`, `GOODEFGHMP3`)
- WMA decoder (not in SDK source)
- Theme hooks (`FLAC_ThemeColor_Select`, etc.)
- Codec bitstream helpers where SDK blobs differ from Fiio binary
- Any function with no SDK equivalent

## Directory Convention

```
firmware/
├── rockchip/     # Ported from RKNanoD SDK (document SDK version + Fiio verify addr)
├── fiio/         # Ghidra decomp — Fiio-only modules
├── codecs/       # Per-format wrappers; decomp where no source exists
└── stubs/        # ROM API @ 0x02FE0000, hardware abstractions
```

### File header template

```c
/*
 * Source:   RKNanoD_MP3 v1.3 AudioControl.c  OR  Ghidra FIIO-3.7.0-Decomp
 * Fiio:     @ 0x0302b9d8 (if applicable)
 * Status:   PORTED | DECOMPILED | STUB | WRAPPER
 * Notes:    ...
 */
```

## What We Ship vs. What We Stub

| Ship as C | Stub / document only |
|-----------|----------------------|
| Playback engine, FS wrappers, event loop | ROM calls (`rom_dac_mute`, etc.) |
| Fiio-specific parsers (DICTDECODER, ROCK26) | Precompiled codec cores unless decomped |
| UI logic (keypad handler, themes) | Hardware drivers that only exist in boot ROM |
| Resource extract/repack tools (Phase 3) | Binary-identical rebuild |

Stubs are fine. Label them clearly so forks know what needs hardware or more RE work.

## Ghidra Role

Ghidra is **required** for Fiio-specific work. It is **optional** for SDK-covered framework code.

Keep Ghidra project `FIIO-3.7.0-Decomp` / `section_3_0x00081A14.bin` as the ground truth for:

- Naming `FUN_*` functions when a subsystem is actively being worked on
- Verifying SDK ports against the actual Fiio binary
- Decompiling codecs and custom modules
- Resolving function boundary issues (see `needs-body-repair` tag)

Do **not** aim to name all ~2,100 remaining `FUN_*` unless someone is actively forking that subsystem.

## Phases

### Phase A — Forkable base (target now)

- [x] Rockbox-style `firmware/` layout
- [x] Ghidra project with key symbols named (~150 functions)
- [x] C reconstructions for major subsystems
- [x] Resource tools (extract / repack / CRC)
- [ ] Port SDK framework files into `firmware/rockchip/`
- [ ] Move Fiio-only code into `firmware/fiio/`
- [ ] README: build instructions, what's stubbed, what's safe to mod

### Phase B — Fiio-faithful (ongoing)

- Ghidra decomp for Fiio-only modules
- Codec expansion (WMA, DSD FIR, etc.)
- SDK cross-check: diff Fiio binary vs SDK for each ported file

### Phase C — Full IMG (not a goal)

- All 2,258 functions to C
- Binary-identical rebuild
- Only pursue if a specific fork needs it

## For Contributors

1. Before decompiling a `FUN_*`, check if the RKNanoD SDK already has readable source.
2. If SDK matches (strings, call pattern, logic), **port** — don't re-decompile from assembly.
3. If Fiio-only or SDK differs, **Ghidra decomp** into `firmware/fiio/` or `firmware/codecs/`.
4. Update `docs/symbol-index.md` when naming a function in Ghidra.
5. Mark stubs honestly. A documented stub is more useful than fake C.
