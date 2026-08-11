#!/usr/bin/env python3
"""
match_sdk_names.py — Search for SDK function names directly embedded in the
firmware binary (debug strings, format strings, symbol tables).

Many embedded firmware images contain function names as strings
(debug print, assert macros, error messages). If we find "MusicInit"
or "APEInfo_Parse" as a string in the binary, we can use Ghidra xrefs
to name the function that references it.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SECTION3 = ROOT / "build" / "section3_stock.bin"
FUNC_INDEX = ROOT / "build" / "sdk_function_index.json"
OUTPUT = ROOT / "build" / "sdk_name_matches.json"

LOAD_BASE = 0x03000000


def main() -> int:
    if not SECTION3.is_file():
        print("ERROR: section3 not found. Run: py tools/pack_img.py --extract", file=sys.stderr)
        return 1

    section3 = SECTION3.read_bytes()
    func_index: dict = json.loads(FUNC_INDEX.read_text(encoding="utf-8"))

    # All SDK function names
    sdk_names = sorted(func_index.keys(), key=len, reverse=True)
    print(f"SDK functions: {len(sdk_names)}")
    print(f"Section_3: {len(section3):,} bytes")

    # Search for each function name as a null-terminated string in the binary
    # Filter: only names >= 4 chars, not common C keywords
    skip = {'main', 'init', 'read', 'write', 'open', 'close', 'seek', 'free',
            'malloc', 'calloc', 'realloc', 'printf', 'sprintf', 'memcpy',
            'memset', 'memcmp', 'strlen', 'strcpy', 'strcat', 'strcmp',
            'strncmp', 'strstr', 'abort', 'exit', 'start', 'stop', 'run',
            'loop', 'wait', 'send', 'recv', 'flush', 'clear', 'set', 'get',
            'put', 'post', 'pull', 'push', 'tick', 'idle', 'poll', 'exec',
            'fork', 'join', 'yield', 'sleep', 'wake', 'lock', 'unlock',
            'size', 'count', 'index', 'value', 'data', 'buf', 'ptr',
            'test', 'check', 'scan', 'find', 'sort', 'load', 'save'}

    matches = []
    for name in sdk_names:
        if len(name) < 4 or name.lower() in skip:
            continue
        needle = name.encode('ascii') + b'\x00'
        pos = section3.find(needle)
        if pos >= 0:
            # Verify it's a real string boundary (preceded by non-printable or start)
            if pos > 0 and 32 <= section3[pos - 1] < 127:
                continue  # part of a longer string
            load_addr = LOAD_BASE + pos
            matches.append({
                "name": name,
                "offset": pos,
                "load_addr": load_addr,
                "file": func_index[name].get("file", ""),
            })

    print(f"\nSDK function names found as strings in binary: {len(matches)}")
    print("\nMatches:")
    for m in matches:
        print(f"  {m['name']:40s} @ 0x{m['load_addr']:08X}  ({m['file']})")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(matches, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nWritten: {OUTPUT}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
