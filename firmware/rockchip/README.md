# Rockchip SDK Port (RKNanoD MP3 v1.3)

Reference C sources ported from `RKNanoD_MP3_V1.3_20161102` for Fiio Echo Mini v3.7.0 reverse engineering.

**Origin:** Rockchip leaked/reference SDK (Nov 2016). Not affiliated with FiiO.

## Layout

```
rockchip/
├── include/              SysInclude.h, typedef.h, global.h
├── bbsystem/             audio_file_access2.c, pCODECS2.c, Main2.c
├── audio/                AudioControl, pCODECS, codec wrappers, *.bin blobs
├── system/
│   ├── module_overlay/   ModuleOverlay.c — codec bank switching
│   ├── os/               Task, Msg, Thread, Win
│   ├── sysservice/       PowerManager, battery, backlight
│   ├── fileseek/         SysFindFile
│   └── debug/            Debug.c
├── fiio_map.h            Ghidra symbol → address map (Fiio v3.7.0)
└── README.md
```

## How to use

1. **Read SDK source** for how a subsystem works (`audio/bbsystem/audio_file_access2.c` = HifiFile*).
2. **Check `fiio_map.h`** for where that logic lives in the Fiio binary.
3. **Compare** with `firmware/fiio/` or `firmware/firmware/` Ghidra decomp files.
4. **RE remaining `FUN_*`** using Ghidra — see `docs/re-backlog.md`.

## Build status

These files are **not wired into `make` yet**. They depend on `SysConfig.h`, `DriverInclude.h`, and Keil scatter layout not present in this tree. Use as reference until the full build pipeline lands (`docs/flashing-guide.md`).

Codec decode logic is in `audio/*/*.bin` blobs — link at scatter addresses, do not expect `.c` decoders to compile standalone.

## Fiio-only code (not in this tree)

Keep in `firmware/codecs/dict_decoder.c`, `firmware/firmware/dsp/`, etc.:

- DICTDECODER / VaT container
- ROCK26IMAGERES embedding
- GOODEF DSP
- WMA decoder internals
- Theme color hooks
