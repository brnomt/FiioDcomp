#!/usr/bin/env python3
"""
changelog_report.py — Correlate string diffs with changelog entries.

Reads build/string_diffs_all_versions.json and generates a per-version
changelog -> interesting added strings report.
"""
from __future__ import annotations

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# Changelog per version (from Read me.txt files) — abbreviated
CHANGELOG = {
    "1.2.7": "Song sort, clock reset fix, charging display, BT reconnect",
    "1.3.0": "ID3 title display, 24h clock, audio drop fix, favorites, charging-media-lib fix",
    "1.4.0": "Cover display, full-screen lyrics, FF/rewind, 120-level volume, favorites save, pop fix",
    "1.4.6": "Gear rotation, screensaver clock, backlight noise, lyrics lib, playlist sort, album track sort",
    "1.5.0": "Retro EQ, shutdown logo font, album artist, low-brightness flicker, shuffle prev-track, ID3 display",
    "1.6.2": "Track artist priority, playback clipping, shuffle rules, album art",
    "1.7.0": "Custom EQ, no auto media-lib on boot, OGG support, special chars, cover lyrics",
    "1.8.0": "3 UI themes, low-brightness flicker, ID3 unknown fix, upgrade crash, character drops, translations",
    "2.4.0": "USB DAC, folder skip, DAC DRE params",
    "2.5.0": "Noise fix, shuffle logic, memory display",
    "2.6.0": "M4A album sort, RIFF ID3 support",
    "2.7.0": "Volume button swap, cover display on track switch",
    "2.8.0": "Lyrics switch, channel balance, drive-letter favorites fix, media-lib crash, nav speed",
    "3.0.0": "Long-press menu favorites, screen-off FF/rewind, Playlist->Media Library rename",
    "3.1.0": "Genre play-all, sleep timer key reset",
    "3.2.0": "Song-skip fix, volume levels 4-5 smoothness",
    "3.3.0": "DSD ID3 display, favorites clear on media-lib update fix",
    "3.4.0": "Button modes A/B (short/long/double press), battery accuracy",
    "3.5.0": "Favorites resume playback, album sort (CD>track>filename)",
    "3.6.0": "M4A album sort, favorites freeze fix, TF card media-lib fix",
    "3.7.0": "Button C mode, FLAC ID3 fix, prev-track logic, media-lib speed",
    "3.8.0": "OGG prev-track fix, APE ID3, WMA ID3, MP3 cover art",
}


def main() -> None:
    data_file = BUILD / "string_diffs_all_versions.json"
    if not data_file.exists():
        print("Run string_diff_versions.py --all first")
        return

    data = json.loads(data_file.read_text(encoding="utf-8"))

    report = []
    report.append("# Echo Mini Firmware — Changelog × String Diff Correlation\n")
    report.append("Auto-generated from section_3 string diffs between adjacent versions.\n")
    report.append("Added strings are hints of new/changed features; xref in Ghidra to find the function.\n")

    for pair, result in data.items():
        old_v, new_v = pair.split("->")
        changelog = CHANGELOG.get(new_v, "")
        report.append(f"\n## {old_v} → {new_v}")
        report.append(f"**Changelog {new_v}:** {changelog}")
        report.append(f"Added: {result['added_count']}, Removed: {result['removed_count']}")

        # Interesting added strings (interest >= 1)
        interesting = [a for a in result["added"] if a["interest"] >= 1]
        if interesting:
            report.append("\n**Interesting ADDED strings:**")
            for item in interesting:
                report.append(f"- `{item['string'][:80]}` @ {item['addr']}")

        # Very interesting = keyword matches changelog
        kw_hits = []
        for item in result["added"]:
            for kw in re.findall(r"[A-Za-z]{4,}", changelog):
                if kw.lower() in item["string"].lower() and item["interest"] > 0:
                    kw_hits.append((kw, item))
                    break
        if kw_hits:
            report.append("\n**Changelog keyword hits:**")
            for kw, item in kw_hits[:5]:
                report.append(f"- '{kw}': `{item['string'][:60]}` @ {item['addr']}")

        report.append("")

    out_file = ROOT / "docs" / "changelog-string-diff.md"
    out_file.write_text("\n".join(report), encoding="utf-8")
    print(f"Report written to: {out_file}")
    print(f"Pairs covered: {len(data)}")


if __name__ == "__main__":
    main()
