#!/usr/bin/env python3
"""Look at bytes at Ghidra-reported xref locations to understand string ref encoding."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
IMG_SECTION3_OFF = 0x00081A14
LOAD_BASE = 0x03000000
MAIN_END = 0x009BAA0E

v37 = STOCK / "3.7.0" / "ECHO MINI V3.7.0"
# find IMG
import glob
imgs = glob.glob(str(v37 / "*.IMG"))
if not imgs:
    imgs = glob.glob(str(v37 / "**" / "*.IMG"), recursive=True)
data = Path(imgs[0]).read_bytes()
sec3 = data[IMG_SECTION3_OFF:MAIN_END]

def off(load_addr):
    return load_addr - LOAD_BASE

# Xref locations reported by Ghidra for ID3V2 start:%d @ 0x030FEC24
xref_locs = [0x030fece6, 0x030fed54]
string_addr = 0x030FEC24

for loc in xref_locs:
    o = off(loc)
    print(f"\n=== bytes around xref {hex(loc)} (sec3 off {hex(o)}) ===")
    print("  " + sec3[o-16:o+16].hex(" "))

# Look for the string address in the code region more broadly
# Maybe encoded as MOVW/MOVT or as literal pool
import struct
pat = struct.pack("<I", string_addr)
print(f"\n=== Searching for 0x{string_addr:08X} as LE32 in whole sec3 ===")
pos = 0
found = []
while True:
    idx = sec3.find(pat, pos)
    if idx < 0:
        break
    found.append(idx)
    pos = idx + 1
print(f"  Found {len(found)} occurrences: {[hex(f + LOAD_BASE) for f in found[:10]]}")

# Search for the Thumb-2 MOVW/MOVT encoding pattern:
# MOVW rX, #imm16: 0xF240 | 0xF2C0 pattern etc. Complex. Instead search for the string
# with the upper 16 bits in MOVT: 0xF6Cx 0xF2Cx patterns

# Alternative: search for PC-relative ADR (ADD rX, pc, #imm) - hard without disasm.
# Instead: check the literal pool region before the xref location.
print("\n=== Literal pool dump near FUN_030fed5e (0x030fed5e) ===")
start = off(0x030fed5e)
end = start + 0x200
# Find 32-bit values in range that look like addresses in 0x03000000-0x03100000
import struct
for i in range(start, end - 3, 2):
    v = struct.unpack("<I", sec3[i:i+4])[0]
    if 0x03000000 <= v <= 0x04000000:
        print(f"  {hex(i + LOAD_BASE)}: 0x{v:08X}")
