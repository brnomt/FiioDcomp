#!/usr/bin/env python3
"""Section-aware diff for HIFIEC37 vs HIFIEC38."""

from __future__ import annotations

import glob
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
V37 = ROOT / "stock/3.7.0/ECHO MINI V3.7.0/HIFIEC37.IMG"
V38 = Path(glob.glob(str(ROOT / "stock/3.8.0/**/HIFIEC38.IMG"), recursive=True)[0])

SECTIONS = [
    ("outer_header_reloc", 0x00000000, 0x00057820),
    ("bootloader", 0x00057820, 0x00081A14),
    ("main_fw_code", 0x00081A14, 0x009BAA0E),
    ("resources_part5", 0x009BAA0E, 0x01FC41F8),
    ("padding", 0x01FC41F8, 0x2000000),
    ("trailer", 0x2000000, 0x2000004),
]

# Ghidra-known symbol regions in section_3 (load addr -> file offset via +0x81A14-0x03000000)
SYMBOLS = [
    ("VorbisOGG_Parser", 0x03023BE8),
    ("ID3_Picture_Parser", 0x03023526),
    ("mp3_id3v2_handler", 0x0306FEC4),
    ("wma_audio_parse", 0x0308CDDC),
    ("APE_Codec_Open", 0x030EEF60),
    ("MusicInit", 0x0302B9D8),
    ("firmware_entry", 0x03000010),
]


def img_off(load_addr: int) -> int:
    return load_addr - 0x03000000 + 0x00081A14


def count_diff(a: bytes, b: bytes, s: int, e: int) -> int:
    return sum(1 for i in range(s, e) if a[i] != b[i])


def main() -> None:
    old = V37.read_bytes()
    new = V38.read_bytes()
    assert len(old) == len(new)

    print("=== Echo Mini 8G: HIFIEC37.IMG vs HIFIEC38.IMG ===\n")
    print(f"Size: {len(old):,} bytes (identical)")
    t_old = struct.unpack("<I", old[-4:])[0]
    t_new = struct.unpack("<I", new[-4:])[0]
    print(f"EOF trailer: v3.7.0 = 0x{t_old:08X}   v3.8.0 = 0x{t_new:08X}\n")

    print("| Section | IMG range | Changed | % |")
    print("|---------|-----------|---------|---|")
    for name, s, e in SECTIONS:
        n = e - s
        c = count_diff(old, new, s, e)
        print(f"| {name} | `0x{s:08X}`-`0x{e:08X}` | {c:,} | {100 * c / n:.2f}% |")

    total = count_diff(old, new, 0, len(old))
    print(f"\n**Total changed:** {total:,} / {len(old):,} ({100 * total / len(old):.2f}%)\n")

    print("## Changelog v3.8.0 (forum) -> likely code areas\n")
    print("| Fix | Symbol / area | 4KB window changed |")
    print("|-----|---------------|-------------------|")
    changelog_map = [
        ("OGG prev-track unsupported", "VorbisOGG_Parser"),
        ("APE ID3 not shown", "APE_Codec_Open"),
        ("WMA ID3 not shown", "wma_audio_parse"),
        ("MP3 cover art", "ID3_Picture_Parser / mp3_id3v2_handler"),
    ]
    for note, sym in changelog_map:
        for sname, load in SYMBOLS:
            if sname in sym:
                off = img_off(load)
                c = count_diff(old, new, off, min(off + 4096, len(old)))
                print(f"| {note} | `{sname}` @ `0x{load:08X}` | {c:,} bytes |")
                break

    print("\n## Outer header field changes (first 0x80 bytes)\n")
    for off in range(0x80):
        if old[off] != new[off]:
            print(f"- `0x{off:04X}`: `0x{old[off]:02X}` -> `0x{new[off]:02X}`")


if __name__ == "__main__":
    main()
