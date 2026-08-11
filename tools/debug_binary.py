#!/usr/bin/env python3
"""Debug: check what's at specific offsets in section3."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()

# Check offset 0x1ad8 (where "Play All Album" should be)
print(f"Section3 size: {len(section3):,} bytes")
print(f"\nAt offset 0x1ad8:")
chunk = section3[0x1ad8:0x1ad8 + 64]
print(f"  Hex: {chunk[:32].hex()}")
print(f"  ASCII: {chunk.decode('ascii', errors='replace')}")

# Search for "Play All" (shorter)
for needle in [b"Play All", b"Play", b"Album", b"Music", b"mp3", b"flac", b"wav"]:
    pos = section3.find(needle)
    print(f"\n  '{needle.decode()}' found at offset 0x{pos:x}" if pos >= 0 else f"\n  '{needle.decode()}' NOT FOUND")

# Check if the file might be the wrong one
print(f"\nFirst 32 bytes: {section3[:32].hex()}")
print(f"  As string: {section3[:32].decode('ascii', errors='replace')}")

# Check if there's a different section3 file
import os
build_dir = ROOT / "build"
for f in sorted(build_dir.iterdir()):
    if f.is_file() and "section" in f.name.lower():
        print(f"\n  {f.name}: {f.stat().st_size:,} bytes")
