#!/usr/bin/env python3
"""
segment_table_diff.py — Paso 4: Diff segment/relocation tables between versions.

Section 1 (~200 segments with load addresses) reveals which modules were
edited between versions (moved/grew/shrunk overlays) BEFORE opening Ghidra.

Usage:
    python tools/segment_table_diff.py 3.6.0 3.7.0
"""
from __future__ import annotations

import argparse
import glob
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
BUILD = ROOT / "build"

# Segment table location (from docs/memory-map.md): entries at IMG offset 0x200
SEG_TABLE_OFF = 0x200
SEG_ENTRY_SIZE = 16
SEG_COUNT = 64  # scan a generous range

# Known segment content labels (from memory-map.md, in order — 32-byte spaced entries)
SEG_LABELS = [
    "unknown_0", "audio_buffer", "zero_init", "dsp_input", "dsp_output",
    "unknown_5", "codec_work", "id3_parse", "fat_cache", "main_stack",
    "flac_work", "ogg_decode", "mp3_frame", "wma_work", "ape_work",
    "dsd_buffer", "aac_decoder", "wav_decode", "dict_decoder", "media_index",
    "ui_framebuffer", "bt_stream", "usb_dma", "record_buf", "jpeg_decode",
]


def find_img(version: str) -> Path:
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version}")
    return Path(candidates[0])


def parse_segments(data: bytes) -> list[dict]:
    """Parse segment descriptors from section 1.

    Format: 16-byte entries at 0x200 + i*16.
    Every entry: [load_addr?, size?, ...]. Entries where the first field is a
    plausible RAM load address (0x03000000-0x03110000) are real segments;
    others are interleaved table metadata.
    """
    segs = []
    for i in range(SEG_COUNT):
        off = SEG_TABLE_OFF + i * SEG_ENTRY_SIZE
        if off + SEG_ENTRY_SIZE > len(data):
            break
        a, b, c, d = struct.unpack("<IIII", data[off:off + SEG_ENTRY_SIZE])
        # Segment entries: a = load addr, b = size
        if 0x03000000 <= a <= 0x03110000:
            label = SEG_LABELS[len(segs)] if len(segs) < len(SEG_LABELS) else f"seg_{len(segs)}"
            segs.append({
                "idx": len(segs),
                "label": label,
                "load_addr": a,
                "size": b,
                "val2": c,
                "val3": d,
            })
    return segs


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("old_version")
    parser.add_argument("new_version")
    args = parser.parse_args()

    old_img = find_img(args.old_version)
    new_img = find_img(args.new_version)
    old_data = old_img.read_bytes()
    new_data = new_img.read_bytes()

    old_segs = parse_segments(old_data)
    new_segs = parse_segments(new_data)

    print(f"=== Segment table diff: {args.old_version} ({old_img.name}) vs {args.new_version} ({new_img.name}) ===\n")
    print(f"{'#':<3} {'Label':<16} {'v-old load addr':>14} {'v-old size':>10} | {'v-new load addr':>14} {'v-new size':>10}  Delta")
    print("-" * 95)

    changed = 0
    for o, n in zip(old_segs, new_segs):
        moved = o["load_addr"] != n["load_addr"]
        resized = o["size"] != n["size"]
        if moved or resized:
            changed += 1
            delta_size = n["size"] - o["size"]
            delta_load = n["load_addr"] - o["load_addr"]
            marker = "MOVE" if moved and resized else ("MOVE" if moved else "RESIZE")
            print(f"{o['idx']:<3} {o['label']:<16} 0x{o['load_addr']:08X} {o['size']:>10,} | "
                  f"0x{n['load_addr']:08X} {n['size']:>10,}  {marker} (load {delta_load:+d}, size {delta_size:+d})")
        else:
            print(f"{o['idx']:<3} {o['label']:<16} 0x{o['load_addr']:08X} {o['size']:>10,} | "
                  f"0x{n['load_addr']:08X} {n['size']:>10,}  same")

    print(f"\n{changed}/{len(old_segs)} segments changed")

    BUILD.mkdir(exist_ok=True)
    out = {
        "old_version": args.old_version,
        "new_version": args.new_version,
        "changed_segments": changed,
        "old_segments": old_segs,
        "new_segments": new_segs,
    }
    out_file = BUILD / f"segment_diff_{args.old_version.replace('.', '_')}_{args.new_version.replace('.', '_')}.json"
    out_file.write_text(json.dumps(out, indent=2), encoding="utf-8")
    print(f"Saved to: {out_file}")


if __name__ == "__main__":
    main()
