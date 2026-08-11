#!/usr/bin/env python3
"""ReChord V0.7 — first binary patch on STOCK firmware.

PROVEN: the bootloader accepts modified section_3 content (single-byte-flip
test passed — menu worked 100%). So we can patch the stock IMG directly.

Strategy change (see docs/bootloader-analysis.md): section_3 = the WHOLE
app (UI + audio + DSP). Rebuilding it from SDK needs the full FiiO layer
(not available). Instead: PATCH the stock firmware — keep the working UI,
modify data/hooks.

V0.7 changes (all DATA, reversible, device-safe):
  1. "MainMenu" -> "ReChord"   @ IMG 0x42560  (UI task-name string, top of screen)
  2. USB SD descriptors "ECHO    MINI" -> "ReChord     "  @ 0x7EB7A / 0x7EB9E
     (visible on PC when connected as USB drive)
  3. PresetGain row 4 (bass-shaped preset) @ 0xC12EA: 17->22, 15->20
     (audible bass boost on one EQ preset)

Usage:  python tools/make_v07_patch.py
Output: build/ReChord_V0.7_firstpatch.IMG
Flash:  copy to internal storage root, reboot (official FiiO method).
Restore stock: copy stock/.../HIFIEC37.IMG back.
"""
import struct
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STOCK = os.path.join(ROOT, 'stock', '3.7.0', 'ECHO MINI V3.7.0', 'HIFIEC37.IMG')
OUT = os.path.join(ROOT, 'build', 'ReChord_V0.7_firstpatch.IMG')

def main():
    stock = bytearray(open(STOCK, 'rb').read())
    changes = []

    # 1) UI task-name string
    assert bytes(stock[0x42560:0x42568]) == b'MainMenu', 'MainMenu not found'
    stock[0x42560:0x42568] = b'ReChord\x00'
    changes.append(('MainMenu -> ReChord', 0x42560))

    # 2) USB SD descriptors
    for off in (0x7EB7A, 0x7EB9E):
        assert bytes(stock[off:off+12]) == b'ECHO    MINI', hex(off)
        stock[off:off+12] = b'ReChord     '
        changes.append(('USB descriptor -> ReChord', off))

    # 3) PresetGain row 4 bass boost
    row4 = 0xC11F2 + 4 * 62
    vals = struct.unpack_from('<31H', stock, row4)
    assert vals[5] == 17 and vals[8] == 15, vals[:10]
    struct.pack_into('<H', stock, row4 + 5*2, 22)
    struct.pack_into('<H', stock, row4 + 8*2, 20)
    changes.append(('PresetGain row4 bass 17/15 -> 22/20', row4))

    open(OUT, 'wb').write(stock)
    orig = open(STOCK, 'rb').read()
    diffs = [i for i in range(len(orig)) if orig[i] != stock[i]]
    print(f'V0.7 written: {len(stock)} bytes, {len(diffs)} bytes changed')
    for c in changes:
        print(f'  {c[0]} @ 0x{c[1]:07x}')

if __name__ == '__main__':
    main()
