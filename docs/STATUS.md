# ReChord — Build Status (Aug 2026)

> **Goal:** a **complete custom firmware written from source** for the FiiO
> Echo Mini (RKnanoC) — a **"Rockbox for the FiiO"**. Not a patch, not a
> byte-mod: **all the firmware source available and modifiable**, covering
> **both** halves of the device.
>
> **ReChord** = re-harmonize: compile the Rockchip SDK from source (the audio
> side) + write our **own UI layer** from scratch (the front end).
>
> **Architecture (key):** the device runs **two firmwares** over a mailbox,
> **both with SDK source available**:
> - **fw1 (AP) @ IMG `0x7B8–0x57820`** → **UI** — built on the **RKnanoC SDK**
>   (`rk3399-table-RKNanoC`: UI MainMenu/MusicWin, drivers I2C/AD_KEY/DAC,
>   FileSys FAT, NANO_OS — 103 `.c`). We rebuild our own UI on top.
> - **section_3 (BB) @ IMG `0x81A14–0x9BAA0E`** → **audio/DSP** — the
>   **RKnanoD SDK** covers this (already integrated).
>
> **Current:** SDK (BB) compiles and our own BB code boots in QEMU. The open
> problems are: (1) **BB display** — get our framebuffer to the LCD (the DMA
> transfer `Lcd_BuferTranfer` lives in the ROM/FiiO layer, not the SDK), and
> (2) **AP/UI** — map fw1 and rebuild the menus/navigation from scratch.
> See `docs/dispatch-map.md` (M0) and `docs/community.md` (community findings).

---

## What compiles today

### fw1 (AP/UI) = build App/UI del SDK RKnanoD — identificado 2026-08-12
> **Corrección tras el match de strings**: fw1 (AP) **NO** es el SDK
> `rk3399-table-RKNanoC` (solo 32 strings). Es el **SDK RKnanoD** (el mismo
> que el BB): 223 strings de RKnanoD_MP3_V1.3, 205 de RKnanoD_Wireless_V1.5.
> La UI del AP está en `RKnanoD_MP3_V1.3/SDK_160_128/UI/` (45 `.c`: MainMenu,
> MusicWin, SetMenu, Browser…) + `main.c`. El BB es `Main2.c` + codecs.
> → **Ambos firmwares son dos builds del mismo SDK RKnanoD.**

### RKnanoD SDK (BB/audio) — integrado (ver abajo)

## What compiles today (RKnanoD = BB)

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

## Build status (link works)

| Item | Status |
|------|--------|
| **Linker script** | ✅ `firmware/firmware.ld` — captures all SDK sections (AudioCode/Bss, SysCode, FindFileCode, FlacDecCode, driver_code, bb_vect) + buffers at segment-table addresses |
| **Link** (section_3 binary) | ✅ `make all` → `build/rechord_full.elf` (998 KB: 67 KB text, 183 KB data, 747 KB bss) + `build/section3_custom.bin` (50 KB) |
| **Codec .lib integration** | ⬜ 22 binaries ready; the linker must place them at their segment addresses |
| **App layer (FiiO UI)** | ⬜ The Ghidra-decompiled layer (archived in `docs/re/decomp/`) — the SDK covers kernel/audio/codecs, the UI is FiiO-specific |
| **Flash test** | Resource mods flashed OK (boot animation). Code replacement not yet flashed — stubs make the current build a bootable kernel without working drivers |

### What the current build is

The linked firmware boots the SDK kernel (Main2 = the BB/audio side) on real
hardware, but the FiiO UI layer is not ours — the stock AP side draws the
cassette UI. Pressing a menu item makes the AP send a mailbox command to our
BB, which (being stubs) never answers → freeze + power-off.

**The next milestone is the mailbox handshake** (§7 in HANDOVER.md): if we
reply to the AP's commands, menus stop freezing and we get a working
navigation → then real drivers + DSP.

### Makefile targets

```
make build-sdk      # compile firmware/rockchip/**/*.c -> build/objs/
make link-firmware  # link -> build/rechord_full.elf + section3_custom.bin
make all            # both
make pack-img       # splice section_3 into HIFIEC37.IMG (identity test)
```

Excluded from `build-sdk` (need project-layer defines): `systick2.c`,
`pCODECS2.c`, `RecordControl.c`, `PowerManager.c`, `AsicToUnicode.c`,
`cue.c`, `ID3.c`, `AsicToUnicodeTable.c`. Linked via prebuilt .o or stubs.

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

- `docs/dispatch-map.md` — **M0: mapa de despacho del ROM** (entry points fijos + ROM API)
- `docs/community.md` — **hallazgos de la comunidad** (RSE blog, FlameOcean, SDKs leakeados)
- `docs/HARDWARE.md` — SoC addresses, segment table, ROM API, fuentes
- `docs/FLASHING.md` — safe flashing + recovery
- `docs/c-cleanup-status.md` — decompiled .c tree cleanup (327/394 compile)
