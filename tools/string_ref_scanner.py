#!/usr/bin/env python3
"""
string_ref_scanner.py — Find code that references changelog-relevant strings.

For each interesting string (found in both versions), scan both binaries for
the 4-byte LE address constant that references it. Then map those file offsets
to load addresses and identify the enclosing function in the loaded Ghidra
program (v3.7.0).

This handles references via absolute address constants (ARM LDR literal pools),
which is how most code references strings on this platform.

Usage:
    python tools/string_ref_scanner.py 3.6.0 --keywords "M4A,ID3,OGG"
"""
from __future__ import annotations

import argparse
import glob
import json
import struct
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

KEYWORD_NOTES = {
    "M4A": "M4A album sorting fix (v3.6)",
    "favorites": "Favorites freeze fix (v3.6)",
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


def find_addr_refs(data: bytes, target_addr: int) -> list[int]:
    """Find file offsets where the 4-byte LE target address appears."""
    pat = struct.pack("<I", target_addr)
    refs = []
    start = 0
    while True:
        idx = data.find(pat, start)
        if idx < 0:
            break
        refs.append(idx)
        start = idx + 1
    return refs


def file_off_to_load(file_off: int) -> int:
    return file_off + LOAD_BASE


def api_get(endpoint: str, params: dict | None = None, timeout: int = 60) -> str:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def get_function_at(load_addr: str) -> str:
    """Ask Ghidra which function contains a load address."""
    try:
        raw = api_get("/get_function_by_address", {"address": load_addr})
        # Response format: "Function: NAME at ADDR\nSignature: ..."
        for line in raw.split("\n"):
            line = line.strip()
            if line.startswith("Function:") or line.startswith("Name:"):
                return line
        return raw.strip()[:100]
    except Exception as e:
        return f"ERR:{e}"


def main() -> None:
    parser = argparse.ArgumentParser(description="Scan binaries for string address references")
    parser.add_argument("old_version", help="Older version (e.g. 3.6.0)")
    parser.add_argument("--new-version", default="3.7.0", help="Newer version (Ghidra program)")
    parser.add_argument("--keywords", help="Comma-separated keywords")
    parser.add_argument("--limit", type=int, default=10, help="Max refs per string")
    args = parser.parse_args()

    old_v, new_v = args.old_version, args.new_version
    print(f"=== String reference scanner: {old_v} -> {new_v} ===\n")

    old_img = find_img(old_v)
    new_img = find_img(new_v)
    old_data = old_img.read_bytes()[IMG_SECTION3_OFF:MAIN_END]
    new_data = new_img.read_bytes()[IMG_SECTION3_OFF:MAIN_END]

    # Extract strings
    old_all = {**extract_strings(old_data), **extract_utf16_strings(old_data)}
    new_all = {**extract_strings(new_data), **extract_utf16_strings(new_data)}
    shared = set(old_all.keys()) & set(new_all.keys())
    print(f"Shared strings: {len(shared)}")

    keywords = [k.strip() for k in args.keywords.split(",") if k.strip()] if args.keywords else list(KEYWORD_NOTES.keys())

    results = []
    for s in sorted(shared):
        up = s.upper()
        matched_kw = None
        for kw in keywords:
            if kw.upper() in up:
                matched_kw = kw
                break
        if not matched_kw:
            continue
        if len(s) < 5:
            continue
        # Skip junk strings (noise)
        if len(set(s)) <= 4 and len(s) > 12:
            continue

        old_off = old_all[s]
        new_off = new_all[s]
        old_load = old_off + LOAD_BASE
        new_load = new_off + LOAD_BASE

        # Find references in both binaries
        old_refs = find_addr_refs(old_data, old_load)
        new_refs = find_addr_refs(new_data, new_load)

        # Query Ghidra for function at each new-version ref
        new_funcs = set()
        for ref_off in new_refs[:args.limit]:
            ref_load = file_off_to_load(ref_off)
            fname = get_function_at(f"0x{ref_load:08X}")
            if fname and not fname.startswith("ERR"):
                new_funcs.add(fname)

        if not old_refs and not new_refs:
            continue

        results.append({
            "keyword": matched_kw,
            "note": KEYWORD_NOTES.get(matched_kw, ""),
            "string": s[:80],
            "old_load": f"0x{old_load:08X}",
            "new_load": f"0x{new_load:08X}",
            "old_refs": [f"0x{file_off_to_load(r):08X}" for r in old_refs[:args.limit]],
            "new_refs": [f"0x{file_off_to_load(r):08X}" for r in new_refs[:args.limit]],
            "new_functions": sorted(new_funcs),
        })

    # Print report
    print("\n" + "=" * 90)
    by_kw = {}
    for r in results:
        by_kw.setdefault(r["keyword"], []).append(r)

    for kw in sorted(by_kw.keys()):
        items = by_kw[kw]
        print(f"\n## [{kw}] {KEYWORD_NOTES.get(kw, '')} ({len(items)} strings with refs)")
        for r in items[:15]:
            funcs = ", ".join(r["new_functions"]) if r["new_functions"] else "(no named func)"
            print(f"  '{r['string']}'")
            print(f"    {r['old_load']} -> {r['new_load']}")
            print(f"    v3.7 refs ({len(r['new_refs'])}): {', '.join(r['new_refs'][:4])}")
            print(f"    Ghidra functions: {funcs}")

    # Save
    BUILD.mkdir(exist_ok=True)
    out_file = BUILD / f"string_refs_{old_v.replace('.', '_')}_{new_v.replace('.', '_')}.json"
    out_file.write_text(json.dumps({
        "old_version": old_v,
        "new_version": new_v,
        "shared_strings": len(shared),
        "results": results,
    }, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\n\nFull results saved to: {out_file}")


if __name__ == "__main__":
    main()
