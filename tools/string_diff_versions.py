#!/usr/bin/env python3
"""
string_diff_versions.py — Paso 1: String diff between adjacent versions.

For each adjacent pair of versions, compute:
  added   = strings_vN   - strings_vN-1   # new features/fixes
  removed = strings_vN-1 - strings_vN      # removed/renamed

Added strings are direct hints of changelog features (menu text, error
messages, EQ preset names, format names).

Usage:
    python tools/string_diff_versions.py                 # all adjacent pairs
    python tools/string_diff_versions.py 3.6.0 3.7.0      # specific pair
"""
from __future__ import annotations

import argparse
import glob
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
BUILD = ROOT / "build"

IMG_SECTION3_OFF = 0x00081A14
MAIN_END = 0x009BAA0E
LOAD_BASE = 0x03000000

# Junk strings to filter (noise)
JUNK_RE = re.compile(r"^[A-Za-z0-9 _\-.,:;!?/\\()\[\]{}<>+=*&%$#@'\"~`^|]*$")
JUNK_SHORT_WORDS = {"the", "and", "this", "that", "with", "from", "have", "were", "will",
                    "your", "about", "their", "what", "when", "there", "would", "could"}

# Interesting keywords for changelog correlation
INTEREST_KEYWORDS = [
    "album", "favorite", "genre", "artist", "track", "EQ", "preset", "gain",
    "filter", "balance", "volume", "battery", "shuffle", "repeat", "lyric",
    "cover", "ID3", "M4A", "OGG", "APE", "WMA", "FLAC", "DSD", "DFF", "RIFF",
    "USB", "DAC", "bluetooth", "BT", "TF", "SD", "format", "sleep", "clock",
    "theme", "brightness", "backlight", "charging", "warning", "unknown",
    "playlist", "library", "sort", "memory", "factory", "update", "upgrade",
]


def find_imgs() -> dict[str, Path]:
    """Map version -> first IMG path."""
    out = {}
    for img in sorted(STOCK.rglob("*.IMG")) + sorted(STOCK.rglob("*.img")):
        version = img.relative_to(STOCK).parts[0]
        if version not in out:
            out[version] = img
    return out


def get_sec3(version: str, imgs: dict) -> bytes:
    img = imgs.get(version)
    if not img:
        sys.exit(f"No IMG for {version}")
    data = img.read_bytes()
    return data[IMG_SECTION3_OFF:MAIN_END]


def extract_ascii(data: bytes, min_len: int = 5) -> dict[str, int]:
    """string -> first file offset."""
    out = {}
    cur = []
    start = 0
    for i, b in enumerate(data):
        if 0x20 <= b < 0x7F:
            if not cur:
                start = i
            cur.append(b)
        else:
            if len(cur) >= min_len:
                s = bytes(cur).decode("ascii", errors="replace")
                if s not in out:
                    out[s] = start
            cur = []
    return out


def extract_utf16(data: bytes, min_len: int = 5) -> dict[str, int]:
    out = {}
    cur = []
    start = 0
    i = 0
    while i + 1 < len(data):
        b0, b1 = data[i], data[i + 1]
        if b1 == 0 and 0x20 <= b0 < 0x7F:
            if not cur:
                start = i
            cur.append(chr(b0))
        else:
            if len(cur) >= min_len:
                s = "".join(cur)
                if s not in out:
                    out[s] = start
            cur = []
        i += 2
    return out


def is_interesting(s: str) -> bool:
    """Filter junk: too generic, too short, hex dumps, etc."""
    s = s.strip()
    if len(s) < 5:
        return False
    # Pure numbers / hex
    if re.fullmatch(r"[0-9a-fA-FxX _\-]+", s):
        return False
    # Pure punctuation
    if re.fullmatch(r"[^a-zA-Z0-9]+", s):
        return False
    # Super long lines are usually data dumps
    if len(s) > 120:
        return False
    # Common debug junk
    if s.startswith("sjlsjdlfjlsdf") or "------" in s:
        return False
    return True


def score_interest(s: str) -> int:
    """Higher = more changelog-relevant."""
    up = s.upper()
    score = 0
    for kw in INTEREST_KEYWORDS:
        if kw.upper() in up:
            score += 1
    # Penalize pure code-ish strings
    if s.startswith(("0x", "&", "err", "ERR")):
        score -= 1
    return score


def diff_pair(old_v: str, new_v: str, imgs: dict, limit: int = 40) -> dict:
    old_sec3 = get_sec3(old_v, imgs)
    new_sec3 = get_sec3(new_v, imgs)

    old_all = {**extract_ascii(old_sec3), **extract_utf16(old_sec3)}
    new_all = {**extract_ascii(new_sec3), **extract_utf16(new_sec3)}

    old_set = set(old_all)
    new_set = set(new_all)

    added_raw = new_set - old_set
    removed_raw = old_set - new_set

    added = [s for s in added_raw if is_interesting(s)]
    removed = [s for s in removed_raw if is_interesting(s)]

    # Score and sort
    added.sort(key=lambda s: -score_interest(s))
    removed.sort(key=lambda s: -score_interest(s))

    # Keep addresses of the most interesting added strings
    result = {
        "old_version": old_v,
        "new_version": new_v,
        "total_strings_old": len(old_set),
        "total_strings_new": len(new_set),
        "added_count": len(added_raw),
        "removed_count": len(removed_raw),
        "added": [
            {"string": s, "addr": f"0x{new_all[s] + LOAD_BASE:08X}", "interest": score_interest(s)}
            for s in added[:limit]
        ],
        "removed": [
            {"string": s, "addr": f"0x{old_all[s] + LOAD_BASE:08X}", "interest": score_interest(s)}
            for s in removed[:limit]
        ],
    }
    return result


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("versions", nargs="*", help="Version pair or list (e.g. '3.6.0 3.7.0' or '--all')")
    parser.add_argument("--all", action="store_true", help="Diff all adjacent version pairs")
    parser.add_argument("--limit", type=int, default=40)
    args = parser.parse_args()

    imgs = find_imgs()
    versions = sorted(imgs.keys())

    if args.versions:
        if len(args.versions) == 2:
            pairs = [tuple(args.versions)]
        else:
            pairs = [(args.versions[i], args.versions[i + 1]) for i in range(len(args.versions) - 1)]
    else:
        pairs = [(versions[i], versions[i + 1]) for i in range(len(versions) - 1)]

    all_results = {}
    for old_v, new_v in pairs:
        print(f"\n{'='*80}")
        print(f"=== {old_v} -> {new_v} ===")
        print(f"{'='*80}")
        result = diff_pair(old_v, new_v, imgs, args.limit)
        all_results[f"{old_v}->{new_v}"] = result

        print(f"  Added: {result['added_count']}, Removed: {result['removed_count']}")
        print(f"\n  ADDED strings (top {len(result['added'])} by interest):")
        for item in result["added"]:
            marker = " *" if item["interest"] >= 2 else ""
            print(f"    {item['addr']} [{item['interest']}]{marker} {item['string'][:90]}")
        print(f"\n  REMOVED strings (top {len(result['removed'])} by interest):")
        for item in result["removed"]:
            print(f"    {item['addr']} [{item['interest']}] {item['string'][:90]}")

    BUILD.mkdir(exist_ok=True)
    out_file = BUILD / "string_diffs_all_versions.json"
    out_file.write_text(json.dumps(all_results, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\n\nAll results saved to: {out_file}")


if __name__ == "__main__":
    main()
