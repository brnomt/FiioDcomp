#!/usr/bin/env python3
"""V0.18 — DECISIVE test: does the ROM/loader CALL section_3's firmware_entry?

Theory test: take the STOCK section_3 (everything stock) and replace the
first instruction of firmware_entry @ 0x03000010 with `b .` (0xE7FE,
infinite loop). The stock first instructions are:
    IMG 0x81A24: b5 10   push {r4,lr}
    IMG 0x81A26: 04 46   mov r4,r0
  -> replace with: fe e7   b .   (hang forever)

Outcomes:
  A) Device FREEZES at boot (cassette static, no menu response):
     firmware_entry IS called -> the flash pipeline works -> our custom
     section_3 code SHOULD run too -> the problem is our code.
  B) Device boots normally (menus/navigation work):
     firmware_entry is NOT called -> the ROM runs the app without calling
     0x03000010 -> we have been patching the wrong entry all along.

Usage:  python tools/make_v018_hangtest.py
Output: build/ReChord_V0.18_hangtest.IMG
"""
import struct
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STOCK = os.path.join(ROOT, 'stock', '3.7.0', 'ECHO MINI V3.7.0', 'HIFIEC37.IMG')
OUT = os.path.join(ROOT, 'build', 'ReChord_V0.18_hangtest.IMG')

S3 = 0x81A14            # section_3 start in the IMG
FW_ENTRY = S3 + 0x10    # firmware_entry @ 0x03000010 -> IMG 0x81A24

def main():
    stock = bytearray(open(STOCK, 'rb').read())

    # sanity: stock firmware_entry prologue
    cur = bytes(stock[FW_ENTRY:FW_ENTRY + 8])
    print(f'stock @0x{FW_ENTRY:06x}: {cur.hex()}')
    if not (cur[0] == 0x10 and cur[1] == 0xb5):  # push {r4,lr}
        print('ERROR: expected push {r4,lr} (b5 10) at firmware_entry')
        return 1

    # patch: b . (0xE7FE) -> infinite loop
    stock[FW_ENTRY:FW_ENTRY + 2] = b'\xfe\xe7'
    print(f'patched @0x{FW_ENTRY:06x}: fe e7  (b .  = infinite loop)')

    open(OUT, 'wb').write(bytes(stock))
    print(f'wrote {OUT} ({len(stock):,} bytes)')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
