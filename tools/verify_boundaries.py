#!/usr/bin/env python3
"""Verify exact IMG section boundaries for pack_img.py."""
import struct
from pathlib import Path

img = Path('stock/3.7.0/ECHO MINI V3.7.0/HIFIEC37.IMG').read_bytes()
print(f'Size: {len(img)} (0x{len(img):X})')
trailer = struct.unpack_from('<I', img, len(img) - 4)[0]
print(f'Trailer: 0x{trailer:08X}')

# Part5 bounds from header @ 0x14C
p5_off, p5_size = struct.unpack_from('<II', img, 0x14C)
print(f'Part5 (from header 0x14C): off=0x{p5_off:08X} size=0x{p5_size:X} ({p5_size:,})')

# Known boundaries from docs
for name, s, e in [
    ('header_reloc', 0x00000000, 0x00057820),
    ('bootloader',   0x00057820, 0x00081A14),
    ('main_code',    0x00081A14, 0x009BAA0E),
    ('resources',    0x009BAA0E, 0x01FC41F8),
    ('padding',      0x01FC41F8, 0x02000000),
    ('trailer',      0x02000000, 0x02000004),
]:
    print(f'{name:14s} 0x{s:08X}-0x{e:08X}  size=0x{e-s:X} ({e-s:,})')

# Find magics
for magic in [b'ROCK26IMAGERES', b'RKnanoFW', b'ROCK26']:
    r = img.find(magic)
    print(f'{magic.decode():20s} at 0x{r:08X}' if r >= 0 else f'{magic.decode()} not found')

# Bytes at key offsets
print(f'main_code start (0x081A14): {img[0x081A14:0x081A14+16].hex()}')
print(f'resources start (0x9BAA0E): {img[0x9BAA0E:0x9BAA0E+16].hex()}')
print(f'padding start (0x1FC41F8): {img[0x1FC41F8:0x1FC41F8+16].hex()}')

# Verify part5_off matches known resources start
print(f'\nPart5 header off 0x{p5_off:08X} vs known 0x009BAA0E: {"MATCH" if p5_off == 0x009BAA0E else "MISMATCH"}')
print(f'Part5 end 0x{p5_off+p5_size:08X} vs known 0x01FC41F8: {"MATCH" if p5_off+p5_size == 0x01FC41F8 else "MISMATCH"}')
