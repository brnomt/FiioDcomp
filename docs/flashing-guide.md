# Flashing Guide — Echo Mini (HIFIEC37.IMG)

How to get a modified firmware onto your device, what works today, and what is still missing for a full custom build.

## How Fiio Upgrades Work (Official)

From the stock `Read me.txt`:

1. Copy `HIFIEC37.IMG` (or `HIFIECxx.IMG` for your version) to the **root** of the player's **internal storage** (USB mass-storage mode).
2. **Remove the TF/micro-SD card** if one is inserted.
3. **Reboot** the player — it upgrades automatically.

No PC flashing tool is required for normal user upgrades. The player reads the IMG from internal flash and applies it on boot.

> **Warning:** Some major upgrades (e.g. v2.4.0) **format internal storage**. Back up music and data before flashing anything custom.

---

## What You Can Flash Today (Safe)

### Option A — Resource mods (recommended first step)

Change UI bitmaps (themes, icons, boot animation frames) **without touching code**.

**Requirements:**
- Python 3
- Stock `HIFIEC37.IMG` in `stock/ECHO MINI V3.7.0/` (not distributed by this repo — obtain from official Fiio/Snowsky firmware)
- This repo's `tools/`

**Steps:**

```bash
# 1. Extract all ROCK26 UI resources (~1617 bitmaps)
python tools/extract_resources.py "stock/ECHO MINI V3.7.0/HIFIEC37.IMG" -o build/resources

# 2. Prepare replacements (match exact resource name + dimensions)
#    Put files in build/replacements/ as either:
#      POWERON0_(0,0).BMP.rgb565   (raw big-endian RGB565)
#      POWERON0_(0,0).BMP.png      (auto-converted; must match w×h)

# 3. Repack into a new IMG (preserves EOF trailer)
python tools/repack_firmware.py "stock/ECHO MINI V3.7.0/HIFIEC37.IMG" \
    -r build/replacements -o build/custom.IMG

# 4. Verify trailer byte
python tools/crc_util.py build/custom.IMG

# 5. Copy to device
#    - Connect Echo Mini via USB, enter storage mode
#    - Copy build/custom.IMG to root as HIFIEC37.IMG (or matching version name)
#    - Eject safely, remove TF card, reboot
```

**Risk:** Very low. Code sections are untouched. Worst case: wrong image dimensions → garbled UI, fixable by reflashing stock IMG.

---

### Option B — Hex patches on stock IMG (advanced, moderate risk)

Small code changes without compiling from source — e.g. theme color values, NOP slides (Flame Ocean–style patches).

**Requirements:**
- Ghidra with `FIIO-3.7.0-Decomp` project
- Hex editor or a patch script
- Understanding of ARM Thumb-2 patch size limits

**Workflow:**
1. Find target address in Ghidra (e.g. theme color @ `0x0301d750`)
2. Compute patched bytes (Thumb instructions are 2-byte aligned, often 2 or 4 bytes)
3. Map Ghidra address → file offset in `section_3` (use segment table / `extract_fw.py`)
4. Patch bytes in a **copy** of stock IMG
5. Flash same as Option A

**Risk:** Moderate. Wrong patch can brick boot or cause crashes. Always keep a stock IMG backup and test on a device you can recover.

> A `tools/patch_img.py` helper does not exist yet — this is manual today.

---

## Building from source (v3.7.0, in progress)

**Toolchain verified:** GNU Arm Embedded `arm-none-eabi-gcc` 10.3+

```bash
# Windows (use mingw32-make if `make` is not on PATH)
mingw32-make toolchain      # verify gcc
mingw32-make all            # core OS/filesystem objects → build/reference.o
mingw32-make compile-check  # compile all firmware/*.c, report pass/fail
```

**What compiles today (core layer):** `entry.c`, `bitreader.c`, `hifi_file.c`, filesystem I/O, ROM API stubs — 11 files linked into `build/reference.o`.

**Still blocking full link:** `firmware.ld` is drafted but not validated; codec/apps layers need `g_*` globals and header/API alignment; SDK tree needs `DriverInclude.h` / SysConfig; `pack_img.py` does not exist yet.

See `firmware/rom_api.h` for boot-ROM call stubs used during host compile.

---

You **cannot** run `make all` and flash the result. The Makefile is a scaffold only.

| Missing | Status |
|---------|--------|
| `arm-none-eabi-gcc` toolchain | Installed — run `make toolchain` |
| Linker script (`firmware.ld`) | Draft (not validated) |
| Startup / vector table | Not in repo |
| Codec binary blobs linked in | Not integrated |
| IMG section packer (`tools/pack_img.py`) | Written — M2 identity test PASSES |
| Byte-identical rebuild of stock section_3 | M2 passed (pack_img identity test) |

See [Full Build Checklist](#full-build-checklist) below.

---

## IMG File Layout (Reference)

```
HIFIEC37.IMG (~32 MB)
├── Outer header          @ 0x000000
├── Section 1             @ 0x0001F8   Relocation / segment table
├── Section 2             @ 0x057820   Bootloader (~173 KB)
├── Section 3             @ 0x081A14   Main firmware (ARM Thumb-2)  ← Ghidra target
├── Section 4             @ 0x1FC41F8  Padding
└── EOF trailer           last 4 bytes  0x1EA1C309 (LE)
```

Part 5 (inside section 3 region): `ROCK26IMAGERES` — 1617 RGB565 UI bitmaps.

---

## Recovery If Something Goes Wrong

1. **Keep stock `HIFIEC37.IMG`** backed up on your PC.
2. Copy stock IMG to device root, remove TF card, reboot — same upgrade path restores factory firmware.
3. If the device won't boot into USB storage: check Fiio/Snowsky forums for maskrom / factory-tool recovery (Rockusb driver ships with RKNanoD SDK under `Development/firmware_upgrade/`).

---

## Full Build Checklist

Use this when aiming for **custom code** flashed from your own compile, not just resource mods.

### Phase 1 — Toolchain
- [x] Install `arm-none-eabi-gcc` (GNU Arm Embedded 10.3+ verified)
- [x] Install `make` or `mingw32-make` (Windows: winlibs mingw64)
- [x] Verify: `make toolchain` or `arm-none-eabi-gcc --version`

### Phase 2 — Linkable firmware
- [x] Create `firmware/firmware.ld` from Fiio segment table + SDK `BuildAll.sct` (draft — not validated)
- [ ] Add startup (`Reset_Handler`, stack, vectors) targeting `firmware_entry` @ `0x03000010`
- [ ] Port SDK framework sources OR verified Ghidra decomp into build
- [ ] Link codec blobs (`mp3_code.bin`, `hifi_flac_code.bin`, etc.) at correct addresses
- [ ] Stub ROM API calls @ `0x02FE0000` (boot ROM — not compiled in)
- [ ] Produce `build/RkNano.bin` (or equivalent flat binary for section 3)

### Phase 3 — IMG packaging
- [x] Write `tools/pack_img.py`: splice custom section_3 into stock IMG
  - Preserve sections 1, 2, 4 from stock (header, bootloader, resources, padding)
  - Replace section 3 with your binary
  - Preserve / recalculate EOF trailer
- [x] **Milestone M2:** packed IMG byte-matches stock section_3 before any code changes
  - `py tools/pack_img.py --identity-test` → PASS (SHA-256 identical)
- [ ] Flash milestone IMG — device must boot identically to stock

### Phase 4 — Custom changes
- [ ] Change one function (e.g. debug string, theme color)
- [ ] Rebuild, repack, flash, verify on hardware
- [ ] Document UART debug pin if available (PB5/PB6 per memory map)

### Phase 5 — Fork-friendly repo
- [ ] `docs/sdk-porting.md` — which files came from RKNanoD SDK vs Ghidra
- [ ] CI or script: `python tools/repack_firmware.py` + smoke test on extracted section_3 hash

---

## Related Docs

- [fork-strategy.md](fork-strategy.md) — SDK vs Ghidra source model
- [sdk-porting.md](sdk-porting.md) — what to copy from leaked SDK, what not to
- [re-backlog.md](re-backlog.md) — prioritized Ghidra RE work after SDK port
- [decompilation-plan.md](decompilation-plan.md) — Ghidra progress and addresses
- [memory-map.md](memory-map.md) — address space and segments
