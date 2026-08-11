# ReChord

> **Re-Chord** — re-harmonize the FiiO Echo Mini. A free, compile-from-source
> firmware for the Echo Mini digital audio player (Rockchip RKnanoC, ARM
> Cortex-M3), built to be modified — starting with the DSP / EQ.

## What is ReChord?

ReChord is a **custom firmware project** for the FiiO Echo Mini. It builds a
free, modifiable firmware from source, so you can add DSP effects (bass
boost, reverb, custom EQ), change the UI, and flash it to your device.

The firmware is ~90% **Rockchip RKnanoD SDK** (the chip vendor's own code,
legitimately available) + ~10% FiiO-specific app layer (UI, menus, services).
ReChord compiles the SDK from source and rebuilds the FiiO layer as clean,
modifiable C — a "Rockbox for the Echo Mini".

> **This is NOT a decompilation project anymore.** The decompilation phase
> (2026) produced the knowledge and SDK integration that power ReChord. See
> `docs/RE-HISTORY.md` for the reverse-engineering notes that remain useful.

## Project history

ReChord started as a **reverse-engineering project**: decompiling the stock
FiiO Echo Mini firmware (all 23 versions, v1.2.5 → v3.8.0) with Ghidra,
correlating each version's changes with its official changelog, and naming
852 functions (30.7%) to understand how the device works.

That phase revealed the key insight that **changed the project's identity**:
the Echo Mini firmware is ~90% Rockchip RKnanoD SDK — the chip vendor's own
source code — plus a thin ~10% FiiO app layer (UI, menus, services).
Reconstructing the firmware from Ghidra's decompiled output would have been
impractical (unreadable `param_1`/`undefined4` C). Instead, ReChord:

1. **Compiles the real Rockchip SDK from source** (53 files: kernel, audio,
   codecs) — the foundation.
2. **Rebuilds the FiiO app layer** as clean, modifiable C, using the
   decompilation as the specification.
3. **Focuses on DSP**: the goal is to add custom effects (bass boost,
   reverb, EQ presets) to `Effect.c` and flash a modified firmware.

The reverse-engineering work is archived in `docs/RE-HISTORY.md` and
`docs/re/` — it remains the reference for the hardware map and the FiiO
layer.

## Status (Aug 2026)

**ALL 53 Rockchip SDK source files compile** with `arm-none-eabi-gcc`:

| Layer | Files | Status |
|-------|------:|--------|
| Kernel (OS, drivers, power) | 29 | ✅ compiles |
| Audio (incl. DSP `Effect.c`) | 8 | ✅ compiles |
| Codec wrappers (AAC, FLAC, MP3, OGG, DSD...) | 16 | ✅ compiles |
| Codec `.lib` binaries | 22 | 📦 ready to link |

**The DSP-effects mod target is ready:** `Effect.c`'s `EffectProcess()` is
the per-frame audio hook. Modify it → recompile → flash.

**Remaining to a flashable custom firmware:**
1. Linker script (place codecs + kernel at segment addresses)
2. Link → flat binary
3. FiiO app/UI layer (from RE knowledge)
4. Flash via `tools/pack_img.py`

Full details: [`docs/STATUS.md`](docs/STATUS.md)

## Quick build check

```bash
# any SDK .c compiles (see docs/STATUS.md for full include list)
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -fsyntax-only \
  -include firmware/rockchip/include/armcc_compat.h \
  -Ifirmware/rockchip/include -Ifirmware/rockchip \
  -Ifirmware/rockchip/audio/Include -Ifirmware/rockchip/audio/AudioControl \
  -Ifirmware/rockchip/audio/Common -Ifirmware/rockchip/audio/RkEQ/Effect \
  -Ifirmware/rockchip/audio/RecordControl -Ifirmware/rockchip/audio/ID3 \
  -Ifirmware/rockchip/audio/Wav/WAV_LIB -Ifirmware/rockchip/audio/SSRC/resampler \
  -Ifirmware/rockchip/system/os -Ifirmware/rockchip/system/fileseek \
  -Ifirmware/rockchip/system/module_overlay -Ifirmware/rockchip/system/sysservice \
  -Ifirmware/rockchip/bbsystem \
  firmware/rockchip/bbsystem/Main2.c
```

## Repository layout

```
firmware/rockchip/          # Rockchip RKnanoD SDK (source + codec .lib)
  ├── bbsystem/             # kernel base (Main2, CRU, DMA, interrupt, ...)
  ├── system/               # OS, fileseek, module_overlay, sysservice
  ├── audio/                # AudioControl, Effect (EQ/DSP), codecs
  └── include/              # ReChord integration headers (armcc compat, etc.)
firmware/                   # (SDK + FiiO layer + decompiled reference)
tools/                      # build, analyze, pack scripts
docs/                       # STATUS, RE-HISTORY, memory map, flashing
stock/                      # official firmware backups (not distributed)
```

## Roadmap

- [x] SDK kernel compiles (29 files)
- [x] SDK audio compiles (8 files, incl. DSP Effect.c)
- [x] SDK codecs compile (16 wrappers + 22 .lib ready)
- [ ] Linker script + link → section_3 binary
- [ ] QEMU smoke test (Cortex-M3)
- [ ] FiiO app/UI layer (from RE knowledge)
- [ ] First custom DSP effect
- [ ] Flash + verify on hardware

## Safety / flashing

- Flashing uses the **official upgrade method** (copy IMG + reboot) — the
  stock firmware is always restorable by copying it back.
- `tools/pack_img.py` preserves the bootloader and resources; only
  section_3 (code) is replaced.
- See [`docs/FLASHING.md`](docs/FLASHING.md) for the safe procedure.

## Disclaimer

ReChord is an independent project. It is not affiliated with FiiO, SNOWSKY,
or Rockchip. It uses the publicly-available Rockchip RKnanoD SDK and
independent reverse-engineering notes. Firmware images are not distributed;
obtain official firmware from FiiO. Flashing modified firmware carries risk —
use at your own risk.
