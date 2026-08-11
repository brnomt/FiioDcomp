#!/usr/bin/env python3
"""
changelog_to_functions.py — Map changelog items to functions in Ghidra.

Pipeline:
1. /search_strings — find strings matching changelog keywords (regex)
2. /find_undocumented_by_string — find FUN_* functions referencing those strings
3. /get_function_by_address — identify named functions too

Usage:
    python tools/changelog_to_functions.py --keywords "ID3,M4A,OGG"
    python tools/changelog_to_functions.py --all
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import urllib.request
import urllib.parse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
BASE = "http://127.0.0.1:8089"

# Changelog keyword -> regex to search strings, plus notes
KEYWORD_RE = {
    "ID3": (r"ID3", "ID3 tag display (v1.3/v3.3/v2.6)"),
    "M4A": (r"M4A", "M4A album sorting (v3.6/v2.6)"),
    "OGG": (r"OGG", "OGG support (v1.7/v3.8)"),
    "APE": (r"APE", "APE ID3 (v3.8)"),
    "DSD": (r"DSD", "DSD ID3 display (v3.3)"),
    "WMA": (r"WMA", "WMA ID3 (v3.8)"),
    "FLAC": (r"FLAC", "FLAC"),
    "album": (r"[Aa]lbum", "Album sorting (v3.6/v3.5)"),
    "favorites": (r"[Ff]avorite", "Favorites freeze fix (v3.6)"),
    "lyrics": (r"[Ll]yric", "Lyrics display (v2.8)"),
    "genre": (r"[Gg]enre", "Genre classification (v3.1)"),
    "RIFF": (r"RIFF", "RIFF ID3 support (v2.6)"),
    "shuffle": (r"[Ss]huffle", "Shuffle logic (v2.5)"),
    "balance": (r"[Bb]alance", "Channel balance (v2.8)"),
    "volume": (r"[Vv]olume", "Volume levels (v1.4)"),
    "battery": (r"[Bb]atter", "Battery display (v3.4)"),
    "gain": (r"[Gg]ain", "Gain settings (v1.2.5)"),
    "filter": (r"[Ff]ilter", "Filter settings (v1.2.5)"),
    "clock": (r"[Cc]lock", "Clock display (v1.3/v1.2.7)"),
    "cover": (r"[Cc]over", "Album cover (v2.7)"),
    "EQ": (r"EQ", "Custom EQ (v1.7)"),
    "theme": (r"[Tt]heme", "UI themes (v1.8)"),
    "bluetooth": (r"BT|Bluetooth", "BT reconnect (v1.2.7)"),
    "usb_dac": (r"USB.*DAC|DAC.*USB", "USB DAC (v2.4)"),
    "playlist": (r"[Pp]laylist", "Playlist/media library (v3.0)"),
    "format": (r"[Ff]ormat", "TF card format (v3.6)"),
    "unknown": (r"[Uu]nknown", "ID3 unknown display (v1.8)"),
    "charging": (r"[Cc]harg", "Charging display (v1.2.7)"),
}


def api_get(endpoint: str, params: dict | None = None, timeout: int = 60) -> str:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def search_strings(pattern: str, limit: int = 30) -> list[dict]:
    """Search defined strings by regex."""
    try:
        raw = api_get("/search_strings", {"search_term": pattern, "limit": str(limit)})
        try:
            data = json.loads(raw)
            if isinstance(data, list):
                return data
            if isinstance(data, dict):
                for key in ("strings", "results", "matches"):
                    if key in data:
                        return data[key]
                return [data]
        except json.JSONDecodeError:
            return [{"raw": raw}]
    except Exception as e:
        return [{"error": str(e)}]


def find_undocumented(address: str) -> list[dict]:
    """Find FUN_* functions referencing a string address."""
    try:
        raw = api_get("/find_undocumented_by_string", {"address": address})
        try:
            data = json.loads(raw)
            if isinstance(data, list):
                return data
            if isinstance(data, dict):
                for key in ("functions", "results", "matches"):
                    if key in data:
                        return data[key]
                return [data]
        except json.JSONDecodeError:
            if raw.strip() and "No functions" not in raw:
                return [{"raw": raw.strip()}]
    except Exception as e:
        return [{"error": str(e)}]
    return []


def get_function(address: str) -> str:
    """Get function name at address."""
    try:
        raw = api_get("/get_function_by_address", {"address": address})
        for line in raw.split("\n"):
            if line.startswith("Function:"):
                return line.strip()
        return raw.strip()[:80]
    except Exception:
        return ""


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--keywords", help="Comma-separated keywords (from table)")
    parser.add_argument("--all", action="store_true", help="Run all keywords")
    parser.add_argument("--limit", type=int, default=30, help="Max strings per keyword")
    args = parser.parse_args()

    if args.all:
        keywords = list(KEYWORD_RE.keys())
    elif args.keywords:
        keywords = [k.strip() for k in args.keywords.split(",") if k.strip()]
    else:
        keywords = list(KEYWORD_RE.keys())

    print(f"Keywords: {keywords}\n")
    all_results = {}

    for kw in keywords:
        if kw not in KEYWORD_RE:
            print(f"[{kw}] unknown keyword, skipping")
            continue
        pattern, note = KEYWORD_RE[kw]
        print(f"\n{'='*70}")
        print(f"[{kw}] {note} (regex: {pattern})")
        print(f"{'='*70}")

        strings = search_strings(pattern, args.limit)
        found_any = False
        kw_results = []

        for s in strings:
            if not isinstance(s, dict):
                continue
            addr = s.get("address", s.get("addr", ""))
            value = s.get("value", s.get("string", s.get("str", "")))
            if not addr:
                continue
            addr_clean = addr.replace("0x", "") if addr.startswith("0x") else addr
            # Only look at code-region strings (0x0300xxxx - 0x0310xxxx)
            try:
                addr_int = int(addr_clean, 16)
            except ValueError:
                continue
            if not (0x03000000 <= addr_int <= 0x03110000):
                continue

            funcs = find_undocumented(addr_clean)
            named_funcs = []
            for f in funcs:
                fname = f.get("name", f.get("function", ""))
                faddr = f.get("address", f.get("addr", ""))
                if not fname and faddr:
                    fname = get_function(str(faddr).replace("0x", ""))
                named_funcs.append(f"{fname}@{faddr}" if fname else str(f))

            if funcs:
                found_any = True
                print(f"  '{str(value)[:60]}' @ {addr}")
                print(f"    -> functions: {named_funcs[:5]}")
                kw_results.append({
                    "string": str(value)[:100],
                    "address": addr,
                    "functions": named_funcs,
                })

        if not found_any:
            print("  (no FUN_* references found in code region)")
        all_results[kw] = {"note": note, "results": kw_results}

    BUILD.mkdir(exist_ok=True)
    out_file = BUILD / "changelog_function_map.json"
    out_file.write_text(json.dumps(all_results, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\n\nSaved to: {out_file}")


if __name__ == "__main__":
    main()
