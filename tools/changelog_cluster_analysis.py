#!/usr/bin/env python3
"""
changelog_cluster_analysis.py — Paso 3: correlate cross-version matches with
changelog clusters.

Loads fuzzy match results between two versions, groups matches by the
referenced v3.7 function's role, and maps them to the changelog of the OLDER
version (what changed going INTO the newer version).

Usage:
    python tools/changelog_cluster_analysis.py 3.6.0 3.7.0
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# Changelog clusters: role keywords -> which v3.7 symbols/areas matter
CLUSTERS = {
    "FLAC": {
        "note": "v3.7: FLAC ID3 not shown fix; v3.8 FLAC seek rewrite",
        "keywords": ["FLAC", "flac", "hifi_flac"],
    },
    "M4A/album sort": {
        "note": "v3.6: M4A album sorting fix; v3.5 CD-number sort",
        "keywords": ["movfile", "M4A", "m4a", "FormatList", "album", "Album"],
    },
    "Favorites": {
        "note": "v3.6: Favorites freeze; v3.0 long-press menu favorites",
        "keywords": ["favorite", "Favorit", "like"],
    },
    "Media library": {
        "note": "v3.6: TF-card media lib; v3.7 media-lib speed; v3.8 WMA sort metadata",
        "keywords": ["MediaLib", "medialib", "Media", "SortInfo", "SysFileInfo"],
    },
    "Button/input": {
        "note": "v3.7 Button C mode; v3.4 modes A/B; prev-track logic",
        "keywords": ["Key", "key", "Button", "button", "Mode", "Prev", "Previous", "track"],
    },
    "USB": {
        "note": "v2.4 USB DAC; v3.7 USB power/charging control",
        "keywords": ["USB", "usb", "DAC"],
    },
    "Bluetooth": {
        "note": "v1.2.7 BT reconnect; BT volume",
        "keywords": ["BT", "Bt", "blueTooth", "bluetooth", "bt_"],
    },
    "EQ/volume/gain": {
        "note": "v1.7 custom EQ; v1.5 retro EQ; v1.2.5 gain; v3.2 volume smoothness",
        "keywords": ["EQ", "eq", "Gain", "gain", "Volume", "volume", "dac_gain", "DRE"],
    },
    "Codec (MP3/WMA/APE/OGG/DSD/WAV)": {
        "note": "v3.8 APE/WMA ID3, MP3 cover, OGG prev-track",
        "keywords": ["mp3", "MP3", "wma", "WMA", "APE", "ape", "OGG", "ogg", "DSD", "dsd", "WAV", "wav", "Codec", "codec"],
    },
    "Display/UI/theme": {
        "note": "v1.8 themes; v1.4.6 display tweaks",
        "keywords": ["Display", "display", "GUI", "gui", "Lcd", "Theme", "theme", "Menu", "menu", "Ui", "UI"],
    },
    "Power/battery/sleep": {
        "note": "v1.2.5 power save; v3.4 battery accuracy; v3.1 sleep timer",
        "keywords": ["Power", "power", "Batter", "batter", "Sleep", "sleep", "Charg", "charg"],
    },
    "Filesystem/SD/TF": {
        "note": "v3.6 TF-card media lib; v2.5 memory display",
        "keywords": ["SD", "sd", "TF", "Sd", "File", "file", "Fat", "FAT", "Flash", "flash"],
    },
    "Network (wifi/udp/tcp)": {
        "note": "wireless SDK leftovers (not player features)",
        "keywords": ["wifi", "WiFi", "udp", "tcp", "http", "dhcp", "lwip"],
    },
}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("old_version", help="e.g. 3.6.0")
    parser.add_argument("new_version", help="e.g. 3.7.0")
    parser.add_argument("--matches", default=None, help="Custom match JSON file")
    args = parser.parse_args()

    if args.matches:
        match_file = Path(args.matches)
    else:
        match_file = BUILD / f"fuzzy_match_sec3_{args.old_version.replace('.', '_')}_bin_section_3_0x00081A14_bin.json"
    if not match_file.exists():
        print(f"Match file not found: {match_file}")
        return

    raw = json.loads(match_file.read_text(encoding="utf-8"))
    matches = raw.get("matches", raw) if isinstance(raw, dict) else raw
    print(f"=== Changelog cluster analysis: {args.old_version} -> {args.new_version} ===\n")
    print(f"Total matches: {len(matches)}")

    # Assign each match to a cluster by its target name
    cluster_assign = {c: [] for c in CLUSTERS}
    cluster_assign["Unassigned"] = []

    for m in matches:
        tgt_name = m.get("target_name", "")
        src_name = m.get("source_name", "")
        src_addr = m.get("source_address", "")
        tgt_addr = m.get("target_address", "")
        score = m.get("score", 0)
        assigned = False
        for cluster, info in CLUSTERS.items():
            if any(k in tgt_name for k in info["keywords"]):
                cluster_assign[cluster].append({
                    "source": src_name, "source_addr": src_addr,
                    "target": tgt_name, "target_addr": tgt_addr,
                    "score": score,
                })
                assigned = True
                break
        if not assigned:
            cluster_assign["Unassigned"].append({
                "source": src_name, "source_addr": src_addr,
                "target": tgt_name, "target_addr": tgt_addr,
                "score": score,
            })

    # Report
    total_assigned = 0
    for cluster, items in sorted(cluster_assign.items(), key=lambda kv: -len(kv[1])):
        if not items:
            continue
        note = CLUSTERS.get(cluster, {}).get("note", "")
        print(f"\n## {cluster} ({len(items)} matches) {('- ' + note) if note else ''}")
        for it in items[:12]:
            print(f"   {it['source']}@{it['source_addr']} -> {it['target']}@{it['target_addr']} score={it['score']}")
        if len(items) > 12:
            print(f"   ... +{len(items) - 12} more")
        if cluster != "Unassigned":
            total_assigned += len(items)

    print(f"\nAssigned to clusters: {total_assigned}/{len(matches)}")

    # Save
    out = BUILD / f"changelog_clusters_{args.old_version.replace('.', '_')}_{args.new_version.replace('.', '_')}.json"
    out.write_text(json.dumps({k: v for k, v in cluster_assign.items()}, indent=2), encoding="utf-8")
    print(f"Saved to: {out}")


if __name__ == "__main__":
    main()
