#!/usr/bin/env python3
"""Extract section_3 (main firmware code) from an IMG for Ghidra import.

Usage:
    python tools/extract_sec3_for_ghidra.py 3.6.0
    → build/sec3_3.6.0.bin
"""
from __future__ import annotations

import glob
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
BUILD = ROOT / "build"

IMG_SECTION3_OFF = 0x00081A14
MAIN_END = 0x009BAA0E
LOAD_BASE = 0x03000000


def find_img(version: str) -> Path:
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version}")
    return Path(candidates[0])


def main() -> None:
    if len(sys.argv) < 2:
        sys.exit("Usage: python tools/extract_sec3_for_ghidra.py <version> [<version> ...]")

    BUILD.mkdir(exist_ok=True)
    for version in sys.argv[1:]:
        img = find_img(version)
        data = img.read_bytes()
        sec3 = data[IMG_SECTION3_OFF:MAIN_END]
        out = BUILD / f"sec3_{version.replace('.', '_')}.bin"
        out.write_bytes(sec3)
        print(f"{version}: {img.name} -> {out} ({len(sec3):,} bytes)")
        print(f"  (load base for Ghidra import: 0x{LOAD_BASE:08X})")


if __name__ == "__main__":
    main()
