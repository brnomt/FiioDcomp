#!/usr/bin/env python3
"""
cross_version_string_map.py — Match strings between two firmware versions and
map changelog items to functions using Ghidra MCP (v3.7.0 program loaded).

Usage:
    python tools/cross_version_string_map.py 3.6.0 --keywords "M4A,album,favorites"
    python tools/cross_version_string_map.py 3.6.0 --all

Strategy:
1. Extract section_3 from both IMGs
2. Find printable strings (ASCII + UTF-16LE) in both
3. Match identical strings between versions (address anchor pairs)
4. For changelog keywords, find matching strings
5. Query Ghidra MCP (v3.7.0) for xrefs → identify functions in current program
6. Report: keyword → string → v3.6 addr → v3.7 addr → function(s) in Ghidra
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

IMG_SECTION3_OFF = 0x00081A14
LOAD_BASE = 0x03000000
MAIN_END = 0x009BAA0E

# Changelog keywords and their meanings
KEYWORD_NOTES = {
    "M4A": "M4A album sorting fix (v3.6)",
    "favorites": "Favorites freeze fix (v3.6) / add-remove (v3.0)",
    "TF": "micro-SD media library fix (v3.6)",
    "SD": "media library / storage",
    "album": "album sorting (v3.6/v3.5)",
    "CD": "CD-number sorting (v3.5)",
    "DSD": "DSD ID3 display (v3.3)",
    "genre": "genre classification (v3.1)",
    "lyrics": "lyrics display (v2.8)",
    "balance": "channel balance (v2.8)",
    "RIFF": "RIFF ID3 (v2.6)",
    "noise": "noise fix (v2.5)",
    "shuffle": "shuffle logic (v2.5)",
    "USB": "USB DAC (v2.4)",
    "DAC": "USB DAC / DRE params (v2.4)",
    "folder": "folder skip (v2.4)",
    "EQ": "custom EQ (v1.7)",
    "OGG": "OGG support (v1.7)",
    "ID3": "ID3 tag display (v1.3)",
    "cover": "album cover (v2.7/v1.4)",
    "theme": "UI themes (v1.8)",
    "gain": "gain settings (v1.2.5)",
    "filter": "filter settings (v1.2.5)",
    "bluetooth": "BT reconnect (v1.2.7)",
    "battery": "battery display (v3.4)",
    "volume": "volume levels (v1.4/v3.4)",
    "clock": "clock display (v1.3)",
}


def find_img(version: str) -> Path:
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version}")
    return Path(candidates[0])


def extract_strings(data: bytes, min_len: int = 5) -> dict[str, int]:
    """Map string -> file offset (first occurrence) for ASCII strings."""
    out = {}
    cur_start = None
    cur = bytearray()
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7F:
            if cur_start is None:
                cur_start = i
            cur.append(b)
        else:
            if cur_start is not None and len(cur) >= min_len:
                s = cur.decode("ascii", errors="replace")
                if s not in out:
                    out[s] = cur_start
            cur_start = None
            cur = bytearray()
    if cur_start is not None and len(cur) >= min_len:
        s = cur.decode("ascii", errors="replace")
        if s not in out:
            out[s] = cur_start
    return out


def extract_utf16_strings(data: bytes, min_len: int = 5) -> dict[str, int]:
    """Map UTF-16LE string -> file offset (first occurrence)."""
    out = {}
    cur_start = None
    cur = []
    i = 0
    n = len(data)
    while i + 1 < n:
        b0, b1 = data[i], data[i + 1]
        if b1 == 0 and 0x20 <= b0 < 0x7F:
            if cur_start is None:
                cur_start = i
            cur.append(chr(b0))
        else:
            if cur_start is not None and len(cur) >= min_len:
                s = "".join(cur)
                if s not in out:
                    out[s] = cur_start
            cur_start = None
            cur = []
        i += 2
    if cur_start is not None and len(cur) >= min_len:
        s = "".join(cur)
        if s not in out:
            out[s] = cur_start
    return out


def api_get(endpoint: str, params: dict | None = None, timeout: int = 60) -> str:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def get_xref_functions(string_load_addr: str) -> list[str]:
    """Get functions referencing an address in the loaded Ghidra program."""
    try:
        raw = api_get("/get_xrefs_to", {"address": string_load_addr})
        try:
            data = json.loads(raw)
        except json.JSONDecodeError:
            return [raw.strip()]
        if isinstance(data, list):
            return [str(x) for x in data]
        for key in ("xrefs", "result", "functions", "callers"):
            if key in data:
                return [str(x) for x in data[key]]
        return [raw[:200]]
    except Exception as e:
        return [f"ERR:{e}"]


def main() -> None:
    parser = argparse.ArgumentParser(description="Cross-version string → function mapping")
    parser.add_argument("old_version", help="Older version (e.g. 3.6.0)")
    parser.add_argument("--new-version", default="3.7.0", help="Newer version loaded in Ghidra (default 3.7.0)")
    parser.add_argument("--keywords", help="Comma-separated keywords (default: all in table)")
    parser.add_argument("--all", action="store_true", help="Include all string matches, not just keywords")
    parser.add_argument("--limit", type=int, default=50, help="Max strings per keyword")
    args = parser.parse_args()

    old_v, new_v = args.old_version, args.new_version
    print(f"=== Cross-version string mapping: {old_v} -> {new_v} ===\n")

    old_img = find_img(old_v)
    new_img = find_img(new_v)
    print(f"Old ({old_v}): {old_img.name}")
    print(f"New ({new_v}): {new_img.name}")

    old_data = old_img.read_bytes()[IMG_SECTION3_OFF:MAIN_END]
    new_data = new_img.read_bytes()[IMG_SECTION3_OFF:MAIN_END]
    print(f"Section 3 sizes: old={len(old_data):,}  new={len(new_data):,}\n")

    # Extract strings
    print("Extracting strings...")
    old_ascii = extract_strings(old_data)
    old_utf16 = extract_utf16_strings(old_data)
    new_ascii = extract_strings(new_data)
    new_utf16 = extract_utf16_strings(new_data)
    print(f"  {old_v}: {len(old_ascii)} ascii + {len(old_utf16)} utf16")
    print(f"  {new_v}: {len(new_ascii)} ascii + {len(new_utf16)} utf16")

    # Match strings between versions
    old_all = {**old_ascii, **old_utf16}
    new_all = {**new_ascii, **new_utf16}
    shared = set(old_all.keys()) & set(new_all.keys())
    print(f"Shared strings: {len(shared)}")

    # Determine keywords
    if args.all:
        keywords = None
    elif args.keywords:
        keywords = [k.strip() for k in args.keywords.split(",") if k.strip()]
    else:
        keywords = list(KEYWORD_NOTES.keys())

    print(f"\nKeywords: {keywords if keywords else 'ALL'}\n")

    # Match and report
    results = []
    seen_strings = set()

    for s in sorted(shared):
        up = s.upper()
        matched_kw = None
        if keywords:
            for kw in keywords:
                if kw.upper() in up:
                    matched_kw = kw
                    break
            if not matched_kw:
                continue
        else:
            matched_kw = "all"

        # Skip overly generic strings
        if len(s) < 5 or s in seen_strings:
            continue
        if up in {"STOP", "PLAY", "NEXT", "PREV", "MENU", "SELECT", "CANCEL", "OK", "BACK"}:
            continue
        seen_strings.add(s)

        old_off = old_all[s]
        new_off = new_all[s]
        old_load = old_off + LOAD_BASE
        new_load = new_off + LOAD_BASE

        # Query Ghidra for functions referencing this string in new (v3.7) program
        funcs = get_xref_functions(f"0x{new_load:08X}")

        results.append({
            "keyword": matched_kw,
            "note": KEYWORD_NOTES.get(matched_kw, ""),
            "string": s,
            "old_addr": f"0x{old_load:08X}",
            "new_addr": f"0x{new_load:08X}",
            "ghidra_xrefs": funcs,
        })

    # Print results grouped by keyword
    by_kw = {}
    for r in results:
        by_kw.setdefault(r["keyword"], []).append(r)

    print("=" * 80)
    for kw in sorted(by_kw.keys()):
        items = by_kw[kw]
        note = KEYWORD_NOTES.get(kw, "")
        print(f"\n## [{kw}] {note} ({len(items)} strings)")
        for r in items[:args.limit]:
            xrefs = ", ".join(r["ghidra_xrefs"][:5]) if r["ghidra_xrefs"] else "none"
            print(f"  '{r['string'][:70]}'")
            print(f"    {r['old_addr']} ({old_v}) -> {r['new_addr']} ({new_v})")
            print(f"    Ghidra refs: {xrefs}")

    # Save full results
    BUILD.mkdir(exist_ok=True)
    out_file = BUILD / f"cross_version_map_{old_v.replace('.', '_')}_{new_v.replace('.', '_')}.json"
    out_file.write_text(json.dumps({
        "old_version": old_v,
        "new_version": new_v,
        "shared_strings": len(shared),
        "results": results,
    }, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\n\nFull results saved to: {out_file}")


if __name__ == "__main__":
    main()
