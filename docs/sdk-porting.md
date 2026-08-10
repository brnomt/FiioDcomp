# SDK Porting Guide — Can We Just Grab the Leaked Code?

Short answer: **yes for the framework, no for a turnkey Fiio firmware.**

The RKNanoD SDKs (`RKNanoD_MP3_V1.3`, `RKNanoD_Wireless_Audio_V1.5`) are leaked/reference Rockchip source. You can use them to **implement** large parts of the player — but you cannot copy-paste the whole SDK, hit Build, and get Echo Mini firmware. Fiio forked and customized it heavily.

---

## What "Grab Files From SDK" Actually Means

```
┌─────────────────────────────────────────────────────────┐
│  RKNanoD SDK (leaked)          Fiio Echo Mini v3.7.0    │
│  ─────────────────────         ─────────────────────    │
│  MusicInit.c          ≈ same →  MusicInit @ 0x0302b9d8  │
│  audio_file_access2.c ≈ same →  HifiFile* @ 0x0306b8e6  │
│  pCODECS.c            ≈ same →  codec dispatch          │
│  mp3_code.bin         ≈ close→  mp3_dec_internal        │
│                                                         │
│  (nothing)            Fiio-only→ DICTDECODER, ROCK26     │
│  (nothing)            Fiio-only→ GOODEF DSP, WMA decode  │
│  image.uis on SD       Fiio-only→ 1617 imgs baked in IMG │
└─────────────────────────────────────────────────────────┘
```

**Three buckets:**

| Bucket | Action | Examples |
|--------|--------|----------|
| **A — Copy from SDK** | Port `.c`/`.h` files, verify vs Fiio binary | `AudioControl.c`, `audio_file_access2.c`, `pCODECS.c`, `ModuleOverlay.c`, OS/tasks |
| **B — SDK blobs, Fiio addresses** | Use SDK `*_code.bin` as starting point; confirm in Ghidra | MP3, AAC, FLAC, APE, OGG, DSD |
| **C — Ghidra only** | No SDK equivalent — decomp from Fiio binary | `DICTDECODER_*`, `DSP_GOODEF_*`, WMA, `FLAC_ThemeColor_Select`, ROCK26 packer |

---

## Files You Can Port Directly (Bucket A)

From `RKNanoD_MP3_V1.3_20161102/Common/`:

```
Codec/Audio/AudioControl/AudioControl.c    → MusicInit, MusicService
Codec/Audio/AudioControl/AudioControl.h
Codec/Audio/Common/pCODECS.c               → codec dispatch table
BBSystem/audio_file_access2.c              → HifiFile*, AudioFile* buffers
BBSystem/pCODECS2.c                         → B-core codec IPC
System/Os/Task.c, Msg.c, Thread.c           → event loop
System/ModuleOverlay/ModuleOverlay.c       → overlay loader (explains Fiio ovl_* clones)
System/SysService/PowerManager.c, battery.c
```

From `SDK_160_128/UI/` — UI shell (Fiio reskinned, same patterns):
```
UI/MusicWin/, UI/SetMenu/, UI/medialib/
```

**How to port:**
1. Copy file into `firmware/rockchip/` (or appropriate subdir)
2. Add header: SDK version, Fiio verify address
3. Diff logic against Ghidra decomp at that address — fix deltas
4. Wire into Makefile when build exists

---

## Files You Use as Binaries, Not Source (Bucket B)

SDK ships decoders as precompiled blobs:

```
Common/Codec/Audio/Mp3/mp3_code.bin + mp3_data.bin
Common/Codec/Audio/HIFI/flac/hifi_flac_code.bin + hifi_flac_data.bin
Common/Codec/Audio/AAC/aac_code.bin + aac_data.bin
... (OGG, APE, ALAC, DSD, WAV)
```

**You link these at fixed addresses** (see SDK `BuildAll.sct`). Your `.c` codec files in this repo are **wrappers/documentation** — the real decode logic is in the blobs.

To verify a blob matches Fiio: Ghidra → compare bytes at `mp3_dec_internal` region vs SDK `mp3_code.bin`.

---

## Fiio-Only — Must Come From Ghidra (Bucket C)

| Module | Why SDK doesn't have it |
|--------|-------------------------|
| `DICTDECODER_InitStream` | Fiio container format (`VaT`/`VAT` magic) |
| `ROCK26IMAGERES` | Fiio packs 1617 RGB565 assets into IMG part5; SDK uses SD `image.uis` |
| `DSP_GOODEF_*` | External GOODE DSP chip — config blobs `WOOOOONXBIN`, `GOODEFGHMP3` |
| `wma_audio_parse` | WMA decode referenced but not shipped as source in SDK |
| `FLAC_ThemeColor_Select` | Fiio theme modding |
| Resource repack | `tools/repack_firmware.py` (this repo) |

Keep these in `firmware/fiio/` from Ghidra decomp.

---

## Chip Mismatch: RKnanoD SDK vs RKnanoC Fiio

| | SDK | Echo Mini |
|--|-----|-----------|
| Chip | RKnanoD (LQFP/BGA/QFN) | RKnanoC (LQFP64) |
| SDK label | RKNanoD MP3 v1.3 | "RKnano SDK 1.0" in IMG header |
| ROM API | `0x02FE0000` region | Same pattern — **addresses differ** |
| Scatter file | `BuildAll.sct` | Must derive Fiio version from segment table |

**Implication:** SDK source is right for *logic*; addresses, linker layout, and some drivers need Fiio-specific adjustment.

---

## Legal / Repo Policy Note

The SDKs are leaked third-party code (Rockchip). This repo's policy (see README):

- Do **not** commit full SDK trees or firmware binaries to git
- **Do** commit clean-room ports, decomp notes, and tooling
- Keep SDK path as a **local reference** (e.g. `~/Downloads/RKNanoD_MP3_V1.3_20161102`)

When porting, write fresh file headers documenting origin — don't blindly bulk-copy 400 files into the repo.

**Update:** Core SDK framework is now in `firmware/rockchip/` (179 files from RKNanoD_MP3 v1.3). See `firmware/rockchip/README.md` and `docs/re-backlog.md` for what to RE next.

---

## Recommended Workflow (Step by Step)

### If you're confused, do it in this order:

**1. Flash something today (no compiler)**
- Resource mod via `repack_firmware.py` → see [flashing-guide.md](flashing-guide.md)

**2. Understand one subsystem**
- Open SDK `AudioControl.c` → `MusicInit`
- Open Ghidra → `MusicInit` @ `0x0302b9d8`
- Open repo `firmware/apps/audio/music_init.c`
- They should tell the same story; repo file is decomp notes, SDK file is readable source

**3. Port one SDK file**
- Copy `audio_file_access2.c` → `firmware/rockchip/audio_file_access2.c`
- Trim to what Fiio actually uses (Seek/Read/Open/Close)
- Comment Fiio addresses next to each function

**4. Don't port codecs as C yet**
- Use SDK blobs in linker script when build exists
- Use Ghidra decomp `.c` files as documentation only

**5. Fill Fiio gaps from Ghidra**
- `dict_decoder.c`, `dsp_goedef.c`, WMA — already started in `firmware/`

---

## What a "Forkable" Repo Looks Like (End State)

```
firmware/
├── rockchip/          ← ported from SDK (Bucket A)
├── fiio/              ← Ghidra decomp (Bucket C)
├── codecs/
│   ├── mp3/           ← thin C wrapper + link mp3_code.bin
│   └── wma/           ← full Ghidra decomp (no SDK source)
└── stubs/rom_api.h    ← declarations for boot ROM @ 0x02FE0000

tools/
├── repack_firmware.py ← works today
└── pack_img.py        ← TODO: full IMG rebuild

docs/
├── flashing-guide.md
└── sdk-porting.md     ← this file
```

Someone cloning the repo gets:
- Readable C for the whole player architecture
- Working resource mod pipeline
- Clear labels: "from SDK", "from Ghidra", "blob", "stub"
- Build instructions when Phase 2–3 of flashing guide are done

---

## FAQ

**Q: Can I just copy the whole SDK into this repo and build?**  
No. Wrong chip scatter, missing Fiio modules, Keil project not portable, codecs are blobs, UI/resources differ.

**Q: Can I use SDK instead of Ghidra for MusicInit?**  
Yes. SDK `AudioControl.c` is the better source. Use Ghidra only to confirm it matches Fiio.

**Q: Do I still need Ghidra?**  
Yes for Bucket C (Fiio-only) and for verifying Bucket A ports. No for generic OS/audio plumbing once ported.

**Q: Is the decomp in `firmware/*.c` useless then?**  
No — it's the map of what Fiio actually shipped. Use it to validate SDK ports and to implement Fiio-only code.
