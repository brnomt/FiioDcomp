#!/usr/bin/env python3
"""
version_analysis_pipeline.py — Full changelog to function mapping pipeline.

Combines:
1. Binary diff between two versions (find changed code regions)
2. String anchoring (shared strings between versions)
3. Ghidra function lookup (identify functions in the loaded program)

Usage:
    python tools/version_analysis_pipeline.py 3.6.0 3.7.0
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

# Changelog keywords for this version pair (from Read me.txt)
# (keyword, regex, changelog note)  -- ASCII only
CHANGELOG = [
    ("m4a_sort", r"M4A", "v3.6: Fixed M4A album sorting"),
    ("favorites_freeze", r"[Ff]avorite", "v3.6: Freeze when accessing Favorites"),
    ("tf_medialib", r"TF|micro.SD|SD", "v3.6: Media Library update on some micro-SD cards"),
    ("album_sort", r"[Aa]lbum", "v3.5: Album sorting logic (CD>track>filename)"),
    ("cd_sort", r"CD", "v3.5: CD number sorting"),
    ("track_buttons", r"track", "v3.4: New button modes"),
    ("battery", r"[Bb]atter", "v3.4: Battery level accuracy"),
    ("dsd_id3", r"DSD", "v3.3: DSD ID3 display"),
    ("genre", r"[Gg]enre", "v3.1: Genre play-all"),
    ("sleep_timer", r"[Ss]leep", "v3.1: Sleep timer key reset"),
    ("favorites_longpress", r"menu", "v3.0: Long-press menu add/remove favorites"),
    ("playlist_rename", r"[Pp]laylist", "v3.0: Playlist renamed to Media Library"),
    ("lyrics", r"[Ll]yric", "v2.8: Lyrics switch"),
    ("balance", r"[Bb]alance", "v2.8: Channel balance"),
    ("volume_swap", r"[Vv]olume", "v2.7: Volume button swap"),
    ("cover", r"[Cc]over", "v2.7: Album cover on track switch"),
    ("riff_id3", r"RIFF", "v2.6: RIFF ID3 support"),
    ("noise", r"[Nn]oise", "v2.5: Noise fix"),
    ("shuffle", r"[Ss]huffle", "v2.5: Shuffle logic"),
    ("usb_dac", r"USB|DAC", "v2.4: USB DAC function"),
    ("folder_skip", r"[Ff]older", "v2.4: Folder skip"),
    ("eq", r"EQ", "v1.7: Custom EQ"),
    ("ogg_fix", r"OGG", "v1.7: OGG support fix"),
    ("id3_display", r"ID3", "v1.3: ID3 display"),
    ("gain", r"[Gg]ain", "v1.2.5: Gain settings"),
    ("filter_save", r"[Ff]ilter", "v1.2.5: Filter settings save"),
    ("bt_reconnect", r"BT|Bluetooth", "v1.2.7: BT reconnect"),
]


def find_img(version: str) -> Path:
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version}")
    return Path(candidates[0])


def api_get(endpoint: str, params: dict | None = None, timeout: int = 60) -> str:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def get_function_at(load_addr: str) -> str:
    """Get function containing a load address in Ghidra."""
    try:
        raw = api_get("/get_function_by_address", {"address": load_addr})
        for line in raw.split("\n"):
            line = line.strip()
            if line.startswith("Function:"):
                return line.replace("Function:", "").strip()
            if line.startswith("Signature:"):
                return line.replace("Signature:", "").strip().split("(")[0].strip()
        return raw.strip()[:80]
    except Exception:
        return "?"


def find_changed_regions(old: bytes, new: bytes, s: int, e: int, min_len: int = 8) -> list:
    """Find changed regions in [s, e)."""
    regions = []
    i = s
    while i < e:
        if old[i] != new[i]:
            j = i
            while j < e and old[j] != new[j]:
                j += 1
            if j - i >= min_len:
                regions.append((i, j))
            i = j
        else:
            i += 1
    return regions


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("old_version", help="e.g. 3.6.0")
    parser.add_argument("new_version", help="e.g. 3.7.0 (must be loaded in Ghidra)")
    parser.add_argument("--min-region", type=int, default=8)
    parser.add_argument("--max-regions", type=int, default=200)
    args = parser.parse_args()

    old_v, new_v = args.old_version, args.new_version
    old_img, new_img = find_img(old_v), find_img(new_v)
    print(f"=== {old_v} ({old_img.name}) -> {new_v} ({new_img.name}) ===")

    old = old_img.read_bytes()
    new = new_img.read_bytes()
    old_sec3 = old[IMG_SECTION3_OFF:MAIN_END]
    new_sec3 = new[IMG_SECTION3_OFF:MAIN_END]

    # Step 1: find changed regions (for reference)
    print("\nStep 1: Finding changed regions in main code...")
    regions = find_changed_regions(old, new, IMG_SECTION3_OFF, min(MAIN_END, len(old)), args.min_region)
    print(f"  {len(regions)} changed regions (raw byte diffs, includes relink address fixups)")

    # Merge nearby regions
    merged = []
    for r in regions:
        if merged and r[0] - merged[-1][1] < 16:
            merged[-1] = (merged[-1][0], r[1])
        else:
            merged.append(r)
    print(f"  {len(merged)} after merging (gap < 16 bytes)")
    total_changed = sum(e - s for s, e in merged)
    print(f"  Total changed bytes in main code: {total_changed:,}")

    # Step 2: map larger changed regions to functions in Ghidra (v3.7 addresses)
    print("\nStep 2: Mapping LARGER changed regions to functions...")
    big_regions = [r for r in merged if r[1] - r[0] >= 64]
    print(f"  {len(big_regions)} regions >= 64 bytes (likely real code changes)")
    region_functions = {}
    for r_start, r_end in big_regions[:args.max_regions]:
        load_start = r_start - IMG_SECTION3_OFF + LOAD_BASE
        load_end = r_end - IMG_SECTION3_OFF + LOAD_BASE
        samples = [load_start, load_start + (load_end - load_start) // 2, load_end]
        funcs = set()
        for s_addr in samples:
            f = get_function_at(f"{s_addr:08X}")
            if f and f != "?":
                funcs.add(f)
        if funcs:
            region_functions[(r_start, r_end)] = funcs

    print(f"  {len(region_functions)} regions mapped to functions")

    # Step 3: String anchors for changelog
    print("\nStep 3: Finding changelog string anchors...")
    changelog_hits = {}

    for kw, pattern, note in CHANGELOG:
        strings = []
        try:
            raw = api_get("/search_strings", {"search_term": pattern, "limit": "20"})
            try:
                data = json.loads(raw)
                if isinstance(data, list):
                    strings = data
                elif isinstance(data, dict):
                    strings = data.get("matches", data.get("strings", []))
                else:
                    strings = []
            except json.JSONDecodeError:
                strings = []
        except Exception:
            pass

        hits = []
        for s in strings:
            if not isinstance(s, dict):
                continue
            addr = s.get("address", "")
            value = s.get("value", s.get("string", ""))
            if not addr:
                continue
            try:
                addr_int = int(str(addr).replace("0x", ""), 16)
            except ValueError:
                continue
            if not (0x03000000 <= addr_int <= 0x03110000):
                continue
            # Find functions referencing this string (all, via get_xrefs_to)
            ref_funcs = []
            try:
                raw2 = api_get("/get_xrefs_to", {"address": format(addr_int, '08x')})
                # Format: "From ADDR in FUNCNAME [TYPE]" lines
                for line in raw2.split("\n"):
                    line = line.strip()
                    if " in " in line:
                        fn = line.split(" in ")[1].split(" ")[0]
                        fa = line.split(" in ")[0].replace("From", "").strip()
                        ref_funcs.append(f"{fn}@{fa}")
            except Exception:
                pass
            # Also try undocumented-only endpoint
            if not ref_funcs:
                try:
                    raw3 = api_get("/find_undocumented_by_string", {"address": format(addr_int, '08x')})
                    try:
                        data3 = json.loads(raw3)
                        refs = data3 if isinstance(data3, list) else data3.get("functions", [])
                        for rf in refs:
                            if isinstance(rf, dict):
                                fn = rf.get("name", rf.get("function", ""))
                                fa = rf.get("address", rf.get("addr", ""))
                                ref_funcs.append(f"{fn}@{fa}")
                    except json.JSONDecodeError:
                        pass
                except Exception:
                    pass
            hits.append({
                "string": str(value)[:80],
                "address": f"0x{addr_int:08X}",
                "functions": ref_funcs[:5],
            })
        changelog_hits[kw] = {"note": note, "strings": hits}

    # Step 4: correlate
    print("\nStep 4: Correlating...")
    report = {
        "old_version": old_v,
        "new_version": new_v,
        "total_changed_bytes": total_changed,
        "changed_regions": len(merged),
        "large_changed_regions": len(big_regions),
        "region_functions": {
            f"0x{s - IMG_SECTION3_OFF + LOAD_BASE:08X}-0x{e - IMG_SECTION3_OFF + LOAD_BASE:08X}": sorted(fs)
            for (s, e), fs in region_functions.items()
        },
        "changelog": changelog_hits,
    }

    # Print summary
    print("\n" + "=" * 80)
    print("CHANGELOG -> FUNCTION MAP")
    print("=" * 80)
    for kw, info in changelog_hits.items():
        print(f"\n[{kw}] {info['note']}")
        for s in info.get("strings", [])[:5]:
            funcs = ", ".join(s["functions"]) if s["functions"] else "(no FUN_* refs)"
            print(f"  '{s['string'][:50]}' @ {s['address']} -> {funcs}")

    print("\n" + "=" * 80)
    print(f"TOP CHANGED REGIONS (in v{new_v} load addresses)")
    print("=" * 80)
    for (s, e), fs in list(region_functions.items())[:30]:
        load_s = s - IMG_SECTION3_OFF + LOAD_BASE
        load_e = e - IMG_SECTION3_OFF + LOAD_BASE
        print(f"  0x{load_s:08X}-0x{load_e:08X} ({e-s:>6} B): {', '.join(sorted(fs))[:100]}")

    # Save
    BUILD.mkdir(exist_ok=True)
    out_file = BUILD / f"version_report_{old_v.replace('.', '_')}_{new_v.replace('.', '_')}.json"
    out_file.write_text(json.dumps(report, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\n\nFull report saved to: {out_file}")


if __name__ == "__main__":
    main()
