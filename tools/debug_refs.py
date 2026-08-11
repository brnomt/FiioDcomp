#!/usr/bin/env python3
"""Debug: how does the binary reference string addresses?"""
import glob
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"

IMG_SECTION3_OFF = 0x00081A14
LOAD_BASE = 0x03000000
MAIN_END = 0x009BAA0E

def find_img(version):
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    return Path(candidates[0])

v37 = find_img("3.7.0").read_bytes()[IMG_SECTION3_OFF:MAIN_END]

# Known string: "ID3V2 start:%d" at load 0x030FEC24 (v3.7)
test_addrs = {
    "ID3V2 start:%d": 0x030FEC24,
    "VorbisOGG_Parser strings": 0x03023BE8,
}

for name, load in test_addrs.items():
    print(f"\n=== {name} @ 0x{load:08X} ===")
    pat = struct.pack("<I", load)
    refs = []
    start = 0
    while True:
        idx = v37.find(pat, start)
        if idx < 0:
            break
        refs.append(idx)
        start = idx + 1
    print(f"  Absolute LE refs ({len(refs)}): {[hex(r + LOAD_BASE) for r in refs[:10]]}")

    # Also try Thumb-2 MOVW/MOVT patterns and PC-relative
    # PC-relative LDR: 0x4800 | imm8 style (short literal pools)
    # Look for the 32-bit address in nearby literal pool (within 1KB of code)

# Now look for how MP1MP2MP3... string is referenced (0x03013414)
load = 0x03013414
pat = struct.pack("<I", load)
refs = []
start = 0
while True:
    idx = v37.find(pat, start)
    if idx < 0:
        break
    refs.append(idx)
    start = idx + 1
print(f"\n=== format list string @ 0x{load:08X} ===")
print(f"  Absolute LE refs ({len(refs)}): {[hex(r + LOAD_BASE) for r in refs[:10]]}")

# Check what's near the string itself (maybe a table of pointers)
print(f"\n  Bytes around string (offset in sec3 = 0x{0x03013414 - LOAD_BASE:08X}):")
off = 0x03013414 - LOAD_BASE
print("   ", v37[off-16:off+64].hex())
