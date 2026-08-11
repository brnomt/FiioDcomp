# SDK Matching Progress

## Objective

Use leaked Rockchip SDK source code (`RKNanoD_MP3_V1.3` + `RKNanoD_Wireless_Audio_SDK_V1.5`)
to automatically name functions in the Fiio Echo Mini firmware binary via Ghidra.

## Current Status

| Metric | Value |
|--------|-------|
| Total functions in binary | 2,776 |
| Named functions | **188** (6.8%) |
| Unnamed (`FUN_*`) | 2,588 |
| SDK functions indexed | 2,269 |
| SDK strings indexed | 2,320 |
| Direct name matches (binary ↔ SDK) | 5 |
| SDK strings found in binary | 26 |
| String xrefs to unnamed functions | 0 |

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

The one file that compiled (`hifi_get_bits.c`, 23 functions) produced
no binary pattern matches — likely a different compiler version/flags.

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

Built a binary→SDK name mapping from the 26 string matches:
- `AudioPlayback_Start` → `AudioStart`
- `FLAC_FileGetSeekInfo` → `FLAC_FileGetSeekInfo` (direct)
- `FLAC_FileSeekFast` → `FLAC_FileSeekFast` (direct)
- `MusicService_Init` → `AudioStart`
- `VorbisOGG_Parser` → `APEInfo_Parse`

Only 5 mappings is insufficient for callee-set translation.

Tools: `tools/build_name_mapping.py`

## Fundamental Blocker

The SDK and binary use **different function names** for the same operations.
There is no automated bridge between them:

| Binary name | SDK name |
|-------------|----------|
| `ipc_post_cmd` | `MailBoxWriteB2ACmd` |
| `hifi_debug_printf` | `rk_printf` |
| `HifiFileRead` | `HifiFileRead` (match!) |

Only 5 functions share the same name in both. String matching, callee-set
matching, and call graph propagation all fail because of this naming gap.

## Next Approaches (not yet attempted)

### A. Stub Header Creation (high effort, high reward)

Create minimal stub headers for the missing SDK includes:
`SysInclude.h`, `SysConfig.h`, `typedef.h`, `DriverInclude.h`, `FsInclude.h`,
`Macro.h`, `global.h`, `debug.h`, `backlight.h`, `LcdInclude.h`, etc.

This would allow compiling all 64 SDK files and matching binary patterns.
Estimated effort: 2-4 hours of stub creation.

### B. Decompilation-Based Structural Matching (complex)

For each unnamed function, extract structural features from decompiled code:
- Parameter count, local variable count
- Branch count (if/while/for/switch)
- Call count, call targets
- Return type, body size

Match these features against SDK source functions.
This bypasses the naming gap by matching code *structure* rather than names.

### C. Code Functionality Matching (user suggestion)

Match based on what the code *does* rather than its name:
- Identify functions by their side effects (registers written, memory modified)
- Match by constant patterns (magic numbers, enum values, bit masks)
- Use data flow analysis to identify input/output patterns

This is the most promising untried approach but requires significant
custom analysis tooling.

### D. Manual Analysis (accurate but slow)

Manually decompile key functions and trace their behavior to SDK source.
The 188 named functions serve as anchors for understanding surrounding code.

## Tools Created

All matching tools are in `tools/`:
- `build_sdk_index.py` / `build_sdk_index_mp3.py` — Build SDK function/string index
- `build_combined_index.py` — Combine MP3 + Wireless SDK indices
- `name_rom_api.py` — Name ROM API functions from `rom_api.h`
- `propagate_similar.py` — Similarity-based name propagation
- `run_auto_analysis2.py` — Run Ghidra auto-analysis + string matching
- `batch_decompile_all2.py` — Batch decompile all functions
- `compile_and_match.py` — Compile SDK and match binary patterns
- `build_name_mapping.py` — Build binary→SDK name mapping from string xrefs

## Build Artifacts

- `build/sdk_function_index_combined.json` — 2,269 SDK functions with callees
- `build/sdk_string_map_combined.json` — 2,320 SDK strings → functions
- `build/all_decompilations.json` — 1,413 decompiled functions
- `build/binary_to_sdk_mapping.json` — 5 binary→SDK name mappings
- `build/current_named_functions.json` — 188 currently named functions
