# ReChord firmware — Source Index

## Live build tree (`firmware/`)

```
firmware/
├── rockchip/          # Rockchip RKnanoD SDK (compiled from source)
│   ├── audio/         #   audio control, codecs, RkEQ (Effect.c = DSP hook)
│   ├── bbsystem/      #   Main2, BSP, cru, dma, interrupt2, Delay2, Debug2
│   ├── system/        #   os (Task/Thread/Msg/Win), fileseek, module_overlay,
│   │                  #   sysservice (battery, backlight, Service, Hook)
│   └── include/       #   armcc_compat.h + integration headers
├── startup/
│   └── startup.c      # RKnanoFW header + firmware_entry @ 0x03000010 -> Main2
├── stubs.c            # link stubs: globals (zero), weak funcs, newlib syscalls
├── firmware.ld        # linker script (SDK sections + segment-table buffers)
└── resource/          # resource_api.h
```

## Build

```
make build-sdk      # compile firmware/rockchip/**/*.c -> build/objs/
make link-firmware  # link -> build/rechord_full.elf + section3_custom.bin
make all            # both
make pack-img       # splice section_3 into HIFIEC37.IMG (identity test)
```

## Archived decompilation (spec only, not compiled)

The Ghidra decompilation output that served as the spec for the
decompilation phase is archived under `docs/re/decomp/` (apps, codecs,
drivers, network, usb, stubs, firmware core + headers). It is **not**
part of the live build — the SDK is compiled from `firmware/rockchip/`.
