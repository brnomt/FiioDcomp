#!/usr/bin/env python3
"""Inspect raw segment table bytes."""
import glob
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"

img = Path(glob.glob(str(STOCK / "3.7.0" / "**" / "*.IMG"), recursive=True)[0])
data = img.read_bytes()

print("=== Bytes at 0x1E0 - 0x260 ===")
for off in range(0x1E0, 0x260, 16):
    chunk = data[off:off+16]
    hexs = chunk.hex(" ")
    print(f"  0x{off:04X}: {hexs}")

# Try parsing as 16-byte entries from 0x200
print("\n=== 16-byte entries from 0x200 ===")
for i in range(8):
    off = 0x200 + i * 16
    a, b, c, d = struct.unpack("<IIII", data[off:off+16])
    print(f"  [{i}] 0x{off:04X}: a=0x{a:08X} b=0x{b:08X} ({b:>10,}) c=0x{c:08X} d=0x{d:08X}")

# Also try the outer header at 0x50 (from extract_fw.py analysis)
print("\n=== 16-byte entries from 0x54 ===")
for i in range(8):
    off = 0x54 + i * 16
    a, b, c, d = struct.unpack("<IIII", data[off:off+16])
    print(f"  [{i}] 0x{off:04X}: a=0x{a:08X} b=0x{b:08X} ({b:>10,}) c=0x{c:08X} d=0x{d:08X}")
