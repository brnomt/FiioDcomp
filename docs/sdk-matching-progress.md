# SDK Matching Progress

## Objective

Use leaked Rockchip SDK source code (`RKNanoD_MP3_V1.3` + `RKNanoD_Wireless_Audio_SDK_V1.5`)
to automatically name functions in the Fiio Echo Mini firmware binary via Ghidra.

## Current Status

| Metric | Value |
|--------|-------|
| Total functions in binary | 2,776 |
| **Named functions** | **624** (22.5%) |
| Unnamed (`FUN_*`) | 2,152 |
| SDK functions indexed | 5,333 |
| SDK functions with callees indexed | 6,327 |
| SDK functions with distinctive constants | 588 |
| SDK functions with structural fingerprints | 5,028 |
| Decompiled binary functions | 2,601 |
| Anchor functions (named in both binary + SDK) | 431 |
| Functions named by functionality matching | +356 (188→544) |
| Functions named by call graph propagation | +80 (544→624) |

## Approaches Tried

### 1. String Matching (exhausted)

**Result:** 26 SDK strings found in binary, 0 new renames.

All 26 matched strings are referenced by **already-named** functions
(`FLAC_FileSeekFast`, `AudioStart`, `VorbisOGG_Parser`, etc.).
Unnamed functions don't contain SDK-matching strings.

Tools: `tools/match_strings_ghidra.py`, `tools/reverse_string_match.py`,
`tools/match_decompiled_strings.py`, `tools/run_string_extract.py`

### 2. Callee-Set Matching (failed)

**Result:** 0 renames.

Only 5 direct name matches between binary and SDK. The naming conventions
differ completely (e.g., binary `ipc_post_cmd` vs SDK `MailBoxWriteB2ACmd`),
so translated callee sets never overlap enough to match.

Tools: `tools/match_callees.py`, `tools/debug_callgraph.py`

### 3. Call Graph Propagation (failed)

**Result:** 0 renames.

With only 5 direct matches, positional callee matching is too fragile.
Compiler differences (inlining, reordering) make callee counts differ.

Tools: `tools/propagate_names.py`, `tools/propagate_names2.py`

### 4. Compilation + Binary Pattern Matching (limited)

**Result:** 1/64 SDK files compile, 0 binary pattern matches.

Most SDK files fail due to missing header chains:
`SysInclude.h` → `SysConfig.h` → `typedef.h` → `DriverInclude.h` → `FsInclude.h`.

Tools: `tools/compile_and_match.py`, `tools/check_compilation.py`

### 5. Ghidra Auto-Analysis (partial success)

**Result:** +21 functions (159→180).

Running Ghidra's `AutoAnalysisManager` defined more strings and triggered
reference analysis, which named 21 additional functions.

Tools: `tools/run_auto_analysis2.py`

### 6. ROM API Naming (success)

**Result:** +7 functions.

Named ROM API functions from `firmware/rom_api.h` at their known addresses
in the 0x02FE0000–0x02FFFFFF ROM region.

Tools: `tools/name_rom_api.py`

### 7. Similarity Matching (partial success)

**Result:** +8 functions (180→188).

Used Ghidra's `find_similar_functions` endpoint to find structurally
similar functions. Named 8 unnamed functions that were >95% similar to
named bitstream/bitreader utility functions.

Tools: `tools/propagate_similar.py`

### 8. Name Mapping from String Xrefs (failed)

**Result:** 5 name mappings, 0 renames from propagation.

Only 5 mappings is insufficient for callee-set translation.

Tools: `tools/build_name_mapping.py`

### 9. Functionality Matching — Distinctive Constants (SUCCESS)

**Result:** +85 functions (188→273).

Matched binary functions to SDK functions by **distinctive constant overlap**.
Only constants >= 0x100 (256) are used — smaller constants (2-255) are too
generic (loop counters, array indices, bit shifts).

Key insight: functions that use the same magic numbers, register addresses,
buffer sizes, sample rates, and encoding ranges are very likely the same
function, even if their names differ.

**Verified examples:**
- `FmFreqToChan`: binary uses 0x366 (870), 0x2f8 (760), 0x28a (650) — exact FM frequencies
- `FmDevSetInitArea`: binary uses 0x1db0 (7600), 9000, 0x222e (8750), 0x2a30 (10800) — FM area ranges
- `WavEncodeHeaderInit`: binary uses 0xff8-0xffd (4088-4093) — WAV header offsets
- `des_setkey`: binary uses 256, 512, 1024, 2048, 4096, 8192 — DES S-box sizes
- `RecordWriteFileTail`: binary uses 0x1ff (511), 0x200 (512) — matches SDK's `(uCounter + 511) / 512`

A **uniqueness constraint** is applied: if multiple binary functions match the
same SDK function, only the best-scoring match is kept (if significantly better
than the second-best). This prevents false positives where many binary functions
coincidentally share common constants.

Tools: `tools/extract_sdk_features.py`, `tools/match_functionality_v2.py`

### 10. Structural Matching — Code Shape (SUCCESS)

**Result:** +195 functions (275→470).

Matched binary functions to SDK functions by **structural fingerprint**:
- Parameter count
- Return type (void vs non-void)
- Control flow (if/else/while/for/switch/case/return counts)
- Function call count
- Local variable count
- Code size ratio

This catches functions that don't share distinctive constants but have
the same code structure. A uniqueness constraint is applied.

Tools: `tools/match_structure.py`

### 11. Combined Matching — Constants + Structure (SUCCESS)

**Result:** +67 functions (470→544, across multiple rounds).

Combines both signals: a function that matches by **both** constants AND
structure is very likely correct. Functions matching by only one signal
get a lower score.

Tools: `tools/match_combined.py`

### 12. Call Graph Propagation (SUCCESS)

**Result:** +80 functions (544→624, across multiple rounds).

Built an SDK callee index (6,327 functions with their call targets). For each
of the 431 "anchor" functions (named in both binary and SDK), matched unnamed
binary callees to unmatched SDK callees:

- **1:1 match** (1 unnamed binary callee + 1 unmatched SDK callee): high confidence (3 votes)
- **N:N positional match** (same count): lower confidence (1 vote)
- **Uniqueness**: only keep unambiguous suggestions (one SDK name per binary address)

This caught common library/system functions that are called by many anchors:
`memcpy`, `memset`, `strlen`, `printf`, `FileRead`, `FileWrite`, `DelayMs`,
`DelayUs`, `rkos_memory_malloc`, `rkos_queue_send`, `DisplayDev_SetOffset`,
`Lcd_Write`, `WatchDogReload`, `freertos_create_task`, `mbedtls_md4_process`, etc.

Tools: `tools/build_sdk_callees.py`, `tools/propagate_callgraph.py`

## Fundamental Insight

The SDK and binary use **different function names** for the same operations,
which defeats name-based matching. However, they share **behavioral
fingerprints** — the same constants, the same code structure, the same
call patterns. By matching on what the code *does* rather than what it's
*called*, we can bridge the naming gap.

## Tools Created

All matching tools are in `tools/`:
- `extract_sdk_features.py` — Extract distinctive constants + structure from SDK source
- `build_sdk_callees.py` — Extract callee index from SDK source (6,327 functions)
- `match_functionality_v2.py` — Match by distinctive constant overlap
- `match_structure.py` — Match by code structural fingerprint
- `match_combined.py` — Combined constant + structural matching
- `propagate_callgraph.py` — Propagate names through call graph
- `decompile_all.py` — Decompile all 2,601 functions in Ghidra
- `verify_matches.py` — Verify matches by comparing decompiled code to SDK source
- `analyze_consts.py` — Analyze constant distribution for threshold tuning
- `name_rom_api.py` — Name ROM API functions from `rom_api.h`
- `propagate_similar.py` — Similarity-based name propagation
- `run_auto_analysis2.py` — Run Ghidra auto-analysis + string matching

## Build Artifacts

- `build/sdk_features.json` — 5,333 SDK functions with constants + structure
- `build/all_decompilations.json` — 2,601 decompiled binary functions
- `build/functionality_matches_v2.json` — Constant-based match results
- `build/structural_matches.json` — Structure-based match results
- `build/combined_matches.json` — Combined match results
