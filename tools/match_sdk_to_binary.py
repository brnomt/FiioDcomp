#!/usr/bin/env python3
"""
match_sdk_to_binary.py — Find SDK strings in the v3.7.0 firmware binary,
then identify which functions reference those strings.

Strategy:
  1. Load the SDK string→function map
  2. Search for each string in the section_3 binary
  3. For each found string, record:
     - String offset in section_3 (→ load address = offset + 0x03000000)
     - SDK function name that uses that string
  4. Output a list of (string, file_offset, load_addr, sdk_func) tuples
     that can be used to name functions in Ghidra via xref analysis

Output: build/sdk_binary_matches.json
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SECTION3 = ROOT / "build" / "section3_stock.bin"
STRING_MAP = ROOT / "build" / "sdk_string_map.json"
OUTPUT = ROOT / "build" / "sdk_binary_matches.json"

LOAD_BASE = 0x03000000
SECTION3_FILE_OFFSET = 0x00081A14  # IMG offset where section_3 starts


def main() -> int:
    if not SECTION3.is_file():
        print(f"ERROR: {SECTION3} not found. Run: py tools/pack_img.py --extract", file=sys.stderr)
        return 1
    if not STRING_MAP.is_file():
        print(f"ERROR: {STRING_MAP} not found. Run: py tools/build_sdk_index.py", file=sys.stderr)
        return 1

    section3 = SECTION3.read_bytes()
    string_map: dict[str, str] = json.loads(STRING_MAP.read_text(encoding="utf-8"))

    print(f"Section_3: {len(section3):,} bytes")
    print(f"SDK strings to find: {len(string_map)}")

    # Search for each string in the binary
    # Only search for strings >= 6 chars to reduce false positives
    matches = []
    found_count = 0
    for string_val, sdk_func in sorted(string_map.items(), key=lambda x: (-len(x[0]), x[1])):
        if len(string_val) < 6:
            continue
        # Encode as bytes (the binary stores them as raw C strings)
        needle = string_val.encode("utf-8", errors="ignore") + b"\x00"
        if len(needle) < 7:
            continue

        # Find all occurrences
        idx = 0
        occurrences = []
        while True:
            pos = section3.find(needle, idx)
            if pos < 0:
                break
            occurrences.append(pos)
            idx = pos + 1
            if len(occurrences) > 5:  # too many hits, skip
                break

        if occurrences and len(occurrences) <= 5:
            for off in occurrences:
                load_addr = LOAD_BASE + off
                matches.append({
                    "string": string_val,
                    "section3_offset": off,
                    "load_addr": load_addr,
                    "sdk_func": sdk_func,
                })
            found_count += 1

    print(f"Strings found in binary: {found_count} / {len(string_map)}")
    print(f"Total occurrences: {len(matches)}")

    # Group by SDK function to see coverage
    func_coverage: dict[str, list] = {}
    for m in matches:
        func_coverage.setdefault(m["sdk_func"], []).append(m)

    print(f"SDK functions with binary string matches: {len(func_coverage)}")

    # Show top 20 by number of unique strings found
    print("\nTop 20 SDK functions by string matches:")
    for func, hits in sorted(func_coverage.items(), key=lambda x: -len(x[1]))[:20]:
        unique_strings = len(set(h["string"] for h in hits))
        print(f"  {func}: {unique_strings} strings, {len(hits)} occurrences")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps({
        "matches": matches,
        "func_coverage": {k: len(v) for k, v in func_coverage.items()},
    }, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nWritten: {OUTPUT}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
