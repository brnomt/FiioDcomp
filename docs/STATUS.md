# ReChord — Build Status (Aug 2026)

> **Goal:** a free, compile-from-source firmware for the FiiO Echo Mini (RKnanoC),
> so DSP effects / features can be modified in C and flashed via pack_img.py.
>
> **ReChord** = re-harmonize: rebuild the Echo Mini firmware from the Rockchip
> SDK source + our own app layer, starting with DSP effects.
>
> **Current:** **ALL 53 Rockchip SDK source files compile** (kernel + audio +
> codecs) with `arm-none-eabi-gcc`. The DSP-effects mod target (`Effect.c`)
> is ready to modify. The linker step is the remaining blocker.

---

## What compiles today (53/53 SDK .c files)

| Layer | Files | Status |
|-------|------:|--------|
| **Kernel** (bbsystem + system/os + fileseek + module_overlay + sysservice) | 29 | ✅ all compile |
| **Audio** (AudioControl, HoldonPlay, Pcm, audio_file_access, audio_track_control, pCODECS, **Effect**, RecordControl) | 8 | ✅ all compile |
| **Codec wrappers** (AAC, DSDIFF, DSF, ALAC, APE, FLAC, MP3, OGG p*.c) | 16 | ✅ all compile |
| **Codec .lib binaries** (FLAC/AAC/DSD/APE/ALAC + EQ/FADE) | 22 | 📦 ready to link |

Compile check (any SDK .c):
```bash
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

## The integration headers (all in firmware/rockchip/include/)

Created to make the armcc-written SDK build with GCC:

| Header | Purpose |
|--------|---------|
| `armcc_compat.h` | Keil keywords → GCC (`__packed`, `__irq`, `_ATTR_*` sections, `__asm`) |
| `SysConfig.h` | Module selection (MUSIC/RADIO/RECORD/PICTURE/BT/USB_HOST), MODULE_ID_*, SYSTEM_DEFAULT_PARA_T, FIRMWARE_INFO_T/CODE_INFO_T, MEMDEV_INFO |
| `driverlib_def.h` | SoC registers: CRU @0x20000000, DMA @0x40010000, INTC @0x400B0000, GRF @0x400C0000, SAR-ADC @0x400D0000, I2S/PMU, SysTick/NVIC (RKnano layout), PLL_ARG_t, chip_freq_t |
| `freq_enums.h` | eFREQ_APP enum (shared; PowerManager.h redefines EXT) |
| `mailbox.h` | CPU↔DSP GOODE mailbox protocol (IDs/channels/MSGBOX_CMD_*) |
| `service_globals.h` | Audio service globals (AudioPtr, AudioPlayState, DmaTransting...) |
| `FileInfo.h` / `File.h` / `fsinclude.h` | File info struct, file I/O API, FAT/find types |
| `battery.h` / `backlight.h` / `lowpower.h` / `pmu.h` | Power/battery/backlight |
| `I2S.h` / `Spectrum.h` / `Dma.h` / `pcm.h` | Audio/USB interfaces |
| `RecordWin.h` / `MusicWin.h` / etc. | UI window externs (30+ stubs) |

## What's still missing for a flashable custom firmware

| Item | Status |
|------|--------|
| **Linker script** | `firmware/firmware.ld` draft exists but not validated; needs codec `.lib` placement + segment table from `docs/memory-map.md` |
| **Link** (produce section_3 binary) | Not done — the 53 .c compile standalone, but nothing links them together yet |
| **Codec .lib integration** | 22 binaries ready; the linker must place them at their segment addresses |
| **App layer (FiiO UI)** | The Ghidra-decompiled layer (852 named funcs, 327 compile as C) — the SDK covers kernel/audio/codecs, the UI is FiiO-specific |
| **Flash test** | Resource mods flashed OK (boot animation). Code replacement not yet flashed |

## The DSP-effects mod target (your goal)

`firmware/rockchip/audio/RkEQ/Effect/Effect.c` compiles clean:

```c
long EffectInit(void);                          // init
long EffectProcess(EQ_TYPE *pBuffer, long PcmLen); // ← per-frame hook
long EffectAdjust(void);                        // adjust
long RKEQAdjust(RKEffect *pEft);                // apply coefficients
```

`effect.h` defines `RKEffect` (5-band `dbGain[5]`) + 8 presets
(`EQ_HEAVY/POP/JAZZ/CLASS/BASS/ROCK/USER/NOR`).

**To add DSP effects:** modify `EffectProcess()` (e.g. multiply samples for
bass boost, add delay taps for reverb) and rebuild.

## Next steps (recommended order)

1. **Linker script** — place kernel/audio/codecs at segment addresses
   (`docs/memory-map.md` + section_1 table). The 22 `.lib` codecs go at their
   `RkNanoD_*` addresses; `pack_img.py` splices the result into section_3.
2. **Link test** — produce a flat binary, verify it loads at 0x03000000 and
   `firmware_entry` @ 0x03000010 runs (QEMU cortex-m3 smoke test).
3. **App layer** — the Ghidra-decompiled UI (852 named, 327 compile) fills
   the FiiO-specific windows/menus on top of the SDK.
4. **Flash** — pack_img.py + the safe flashing method (stock backup always).

## Related docs

- `docs/MULTI-VERSION-PLAN.md` — RE progress, changelog-anchored naming
- `docs/memory-map.md` — SoC addresses, segment table
- `docs/flashing-guide.md` — safe flashing + recovery
- `docs/c-cleanup-status.md` — decompiled .c tree cleanup (327/394 compile)
