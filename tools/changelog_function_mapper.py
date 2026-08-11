#!/usr/bin/env python3
"""
changelog_function_mapper.py — Map changelog items to firmware functions.

Strategy:
1. Extract section_3 (main code) from a firmware version's IMG
2. Find printable strings in the binary
3. Match changelog-relevant keywords to strings
4. Query Ghidra MCP (currently loaded program) for functions referencing those strings
5. Report candidate functions

Usage:
    python tools/changelog_function_mapper.py <version> [--strings "kw1,kw2"]
"""
from __future__ import annotations

import argparse
import glob
import json
import re
import sys
import urllib.request
import urllib.parse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
BUILD = ROOT / "build"
BASE = "http://127.0.0.1:8089"

# Section_3 in IMG (main firmware code)
IMG_SECTION3_OFF = 0x00081A14
LOAD_BASE = 0x03000000
MAIN_END = 0x009BAA0E

# Changelog keyword -> description (from Read me.txt files)
CHANGELOG_KEYWORDS = {
    # v3.6.0
    "M4A": "M4A album sorting fix",
    "album": "album sorting",
    "favorites": "Favorites (My Favorites) handling",
    "media_library": "Media Library update",
    "TF": "micro-SD card support",
    "SD": "SD card / media library",
    # v3.5.0
    "CD": "CD number sorting",
    "track": "track number sorting",
    # v3.4.0
    "volume": "volume / button modes",
    "battery": "battery level display",
    # v3.3.0
    "DSD": "DSD ID3 tag display",
    "DFF": "DFF format",
    # v3.2.0
    "song": "song skip fix",
    # v3.1.0
    "genre": "genre classification",
    "sleep": "sleep timer",
    # v3.0.0
    "menu": "menu button / favorites",
    "playlist": "playlist / media library rename",
    # v2.8.0
    "lyrics": "lyrics display",
    "balance": "channel balance",
    # v2.7.0
    "swap": "volume button swap",
    "cover": "album cover display",
    # v2.6.0
    "RIFF": "RIFF ID3 support",
    # v2.5.0
    "noise": "noise fix",
    "shuffle": "shuffle logic",
    # v2.4.0
    "USB": "USB DAC function",
    "DAC": "USB DAC / DRE params",
    "folder": "folder skip",
    # v1.8.0
    "theme": "UI themes",
    "brightness": "low brightness flicker",
    # v1.7.0
    "EQ": "custom EQ",
    "OGG": "OGG format support",
    # v1.6.0
    "artist": "artist display",
    "clipping": "audio clipping",
    # v1.5.0
    "retro": "retro EQ",
    "shutdown": "shutdown logo",
    # v1.4.6
    "screensaver": "screensaver clock",
    "backlight": "backlight noise",
    # v1.4.0
    "lyric": "full-screen lyrics",
    "ff": "fast forward/rewind",
    "120": "120-level volume",
    "pop": "pop sound on shutdown",
    # v1.3.0
    "ID3": "ID3 tag display",
    "24": "24-hour clock",
    # v1.2.7
    "clock": "clock reset",
    "charging": "charging display",
    "bluetooth": "Bluetooth reconnect",
    # v1.2.5
    "gain": "gain settings",
    "filter": "filter settings",
    "warning": "warning symbol removal",
}


def find_img(version: str) -> Path:
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version}")
    return Path(candidates[0])


def extract_strings(data: bytes, min_len: int = 6) -> list[tuple[int, str]]:
    """Find printable ASCII strings (with offsets)."""
    strings = []
    cur_start = None
    cur = bytearray()
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7F:
            if cur_start is None:
                cur_start = i
            cur.append(b)
        else:
            if cur_start is not None and len(cur) >= min_len:
                strings.append((cur_start, cur.decode("ascii", errors="replace")))
            cur_start = None
            cur = bytearray()
    if cur_start is not None and len(cur) >= min_len:
        strings.append((cur_start, cur.decode("ascii", errors="replace")))
    return strings


def find_utf16_strings(data: bytes, min_len: int = 6) -> list[tuple[int, str]]:
    """Find printable UTF-16LE strings (used for UI text)."""
    strings = []
    cur_start = None
    cur = []
    i = 0
    while i + 1 < len(data):
        b0, b1 = data[i], data[i + 1]
        if b1 == 0 and 0x20 <= b0 < 0x7F:
            if cur_start is None:
                cur_start = i
            cur.append(chr(b0))
        else:
            if cur_start is not None and len(cur) >= min_len:
                strings.append((cur_start, "".join(cur)))
            cur_start = None
            cur = []
        i += 2
    if cur_start is not None and len(cur) >= min_len:
        strings.append((cur_start, "".join(cur)))
    return strings


def api_get(endpoint: str, params: dict | None = None, timeout: int = 60):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def query_string_xrefs(string_addr: str) -> list[str]:
    """Get functions that reference a string address via Ghidra MCP."""
    try:
        result = api_get("/get_xrefs_to", {"address": string_addr})
        # Parse result - could be JSON or text
        try:
            data = json.loads(result)
            if isinstance(data, list):
                return data
            return data.get("xrefs", data.get("result", []))
        except json.JSONDecodeError:
            return [result]
    except Exception as e:
        return [f"ERROR: {e}"]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("version", help="Firmware version to analyze (e.g. 3.6.0)")
    parser.add_argument("--strings", help="Comma-separated keywords to search (default: from changelog)")
    parser.add_argument("--limit", type=int, default=200, help="Max strings per keyword")
    args = parser.parse_args()

    version = args.version
    img = find_img(version)
    print(f"Analyzing {version}: {img}")
    data = img.read_bytes()

    # Extract section_3 (main firmware code)
    sec3 = data[IMG_SECTION3_OFF:MAIN_END]
    print(f"Section 3: {len(sec3):,} bytes")

    # Find strings in section 3
    ascii_strings = extract_strings(sec3)
    utf16_strings = find_utf16_strings(sec3)
    print(f"ASCII strings: {len(ascii_strings)}")
    print(f"UTF-16 strings: {len(utf16_strings)}")

    # Combine
    all_strings = [
        (off, s, "ascii") for off, s in ascii_strings
    ] + [
        (off, s, "utf16") for off, s in utf16_strings
    ]

    # Build keyword index
    keywords = args.strings.split(",") if args.strings else list(CHANGELOG_KEYWORDS.keys())
    keywords = [k.strip() for k in keywords if k.strip()]
    print(f"\nKeywords to search: {keywords}")

    # Find strings matching keywords
    print("\n=== Changelog-relevant strings found ===")
    found = {}
    for off, s, enc in all_strings:
        up = s.upper()
        for kw in keywords:
            kwu = kw.upper()
            if kwu in up and len(s) >= 4:
                load_addr = off + LOAD_BASE
                found.setdefault(kw, []).append((load_addr, s, enc))
                break

    for kw in keywords:
        matches = found.get(kw, [])
        print(f"\n[{kw}] ({len(matches)} strings, showing up to {args.limit})")
        for load_addr, s, enc in matches[:args.limit]:
            print(f"  @ 0x{load_addr:08X} ({enc}): {s[:100]}")

    # Save results
    build_output = {
        "version": version,
        "img": str(img),
        "section3_size": len(sec3),
        "strings_by_keyword": {
            kw: [{"address": f"0x{off + LOAD_BASE:08X}", "string": s, "encoding": enc}
                 for off, s, enc in matches]
            for kw, matches in found.items()
        }
    }
    out_file = BUILD / f"strings_{version.replace('.', '_')}.json"
    BUILD.mkdir(exist_ok=True)
    out_file.write_text(json.dumps(build_output, indent=2), encoding="utf-8")
    print(f"\nSaved to: {out_file}")


if __name__ == "__main__":
    main()
