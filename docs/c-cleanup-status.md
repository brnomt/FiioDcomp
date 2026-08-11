# C-Source Cleanup — Status & Deep-Cleanup Backlog

> **Last updated:** Aug 2026 · Phase 1–3 done: **327 / 394 named .c compile
> (83%)** with `arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -fsyntax-only`.

## What "compiles" means here

The decompiled `.c` files use Ghidra pseudo-types (`undefined1/2/4/8`, `uint`,
`ushort`, `longlong`), pseudo-globals (`DAT_xxxx`, `FUN_xxxx`, `s_xxxx`,
`uRamxxxxxx`, `stack0x...`, `g_*`), and pseudo-helpers (`CARRY4`, `SBORROW4`,
`halt_baddata`). Three auto-generated headers make them compile:

| Header | Contents |
|--------|----------|
| `firmware/decomp_support.h` | Ghidra types, CARRY/SBORROW macros, `code` typedef (`int(*)()`), `halt_baddata` stub |
| `firmware/decomp_globals.h` | **auto-generated**: weak externs for 962 `DAT_` (1-element arrays so `*DAT` and `DAT+n` compile), 536 `FUN_` (`int f()` old-style), 94 `s_`, 248 `uRam`/`g_`/`stack0x`/`ReservedN` |

Regenerate: `python tools/cleanup_c_files.py` (injects includes + writes
globals). Check: `python tools/cleanup_c_files.py --check` →
`build/compile_report.json` (per-file ok/err).

## The 4 "compile" hacks and their limits

1. **`DAT_xxx[1]` arrays** — make `*DAT_x` (deref) and `DAT_x + n` (pointer
   math) both compile. **Fails** when Ghidra mixes value and pointer use in
   one expression (e.g. `*(uint *)(DAT_a + 0x20) / DAT_b` → "invalid operands").
2. **`int FUN_xxx()` old-style** — any call compiles. **Fails** if the real
   definition (with a real name) is in another .c — excluded those from
   globals (they compile as implicit decls).
3. **`code` = `int(*)()`** — call-through-as-value (`uVar = (*(code*)p)(...)`)
   compiles. Void uses get warnings only.
4. **Weak externs** — linking is NOT solved; these are compile-check only.

## Deep-cleanup backlog (67 files)

Per-file errors: `build/compile_report.json`. Patterns by count:

| Pattern | Count | Files (examples) | Fix |
|---------|------:|------------------|-----|
| `invalid operands to binary / - *` (DAT value/pointer mix) | 17 | `hifi_busy_delay*.c`, `APEV1_Parse.c`, `OGGInfo_Parse.c`, `dac_gain_curve_apply.c` | Add explicit casts `(uintptr_t)DAT_x` / `*(uint*)((uintptr_t)DAT_x + n)`; the decompiler mixed address-as-value and address-as-pointer |
| `request for member '_2_2_'` (Ghidra mid-word access) | 4 | `audio_state_check.c`, `RecordWriteFile.c`, `VorbisOGG_Parser.c`, `wav_lib_decode.c` | Replace `local._2_2_` with explicit byte ops: `(local >> 16) & 0xffff` etc. |
| `conflicting types for 'g_*'` | 4 | `dac_gain_curve.c`, `music_service.c`, `volume_control.c`, `bt_handler.c` | Real `g_*` definitions exist elsewhere; align types (struct vs int) |
| `conflicting types for 'DSP_GOODEF_Init'` | 2 | `main_ui_handler.c`, `dsp_goedef_reload.c` | DSP_GOODEF_Init defined twice; merge |
| `label at end of compound statement` | 2 | `theme_color_helper.c`, `aac_dec_init.c` | Add a `;` after the trailing `LAB_...:` |
| `'stack0x...' undeclared` | 2 | `GetFreeMemory.c`, `rkos_semaphore_create.c` | Should be covered by globals now; re-check |
| `'Reserved2' undeclared` | 1 | `RecordWriteFile2.c` | Covered by globals now; re-check |
| `'u_BT_Music_0300e2d0' undeclared` | 1 | `BT_Music_Handler.c` | Covered by globals now; re-check |
| misc (member of non-struct, etc.) | ~34 | — | Per-file: reconstruct the real struct/type |

## Recommended order for the next session

1. **Re-run `cleanup_c_files.py --check`** — several "undeclared" entries
   may already be fixed by the newer globals (stack0x/ReservedN/u_*).
2. **Fix the 17 pointer/value mixes** first (biggest win): they are all in
   delay/EQ/parse code. Cast pattern: `(uintptr_t)DAT_x`.
3. **Fix the 4 `_2_2_`** bitfield accesses (mid-word ops).
4. **Reconcile the 6 `conflicting types`** (DSP_GOODEF_Init + g_*).
5. Aim for **100% syntax-clean**, then move to: real struct types for the
   FLAC/media clusters, then a real link test.

## Beyond syntax-clean

- The 394 named .c are the "known" tree. The other 2,597 files in
  `firmware/unidentified/` are mostly empty (`void f() { return; }`) or
  ROM thunks — low value; consider pruning or folding into a stubs file.
- The SDK reference trees (`firmware/rockchip*`) are SOURCE, not output —
  they compile separately via `tools/compile_check.py` (SDK objects).
- Real goal: byte-identical section_3 link → `docs/flashing-guide.md`.
