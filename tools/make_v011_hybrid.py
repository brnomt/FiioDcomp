#!/usr/bin/env python3
"""ReChord V0.11 — our compiled C code + preserved stock section_3 DATA.

THEORY (see docs/bootloader-analysis.md): the loader's memory map
(header @ IMG 0x1f8, 91 entries) loads DATA from the section_3 flash
region at offsets ~0x79000+ (fonts, tables, UI data) into RAM. All our
V0.1-V0.10 builds were 52-81KB of code + ZEROS there -> the loaded data
is zeros -> no text strings, app cannot init -> cassette + freeze.

V0.11 = our compiled section3_custom.bin + stock section_3 data from
our code end to the region end. Every file offset >= len(our code)
keeps its stock content, so the memory map loads the same data as stock.

Usage:  python tools/make_v011_hybrid.py
Output: build/section3_hybrid.bin  (== stock section_3 size)
Then:   python tools/pack_img.py --pack build/section3_hybrid.bin -o build/ReChord_V0.11_datakeep.IMG
"""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STOCK = os.path.join(ROOT, 'stock', '3.7.0', 'ECHO MINI V3.7.0', 'HIFIEC37.IMG')
OUR = os.path.join(ROOT, 'build', 'section3_custom.bin')
OUT = os.path.join(ROOT, 'build', 'section3_hybrid.bin')

S3 = 0x81A14
S3E = 0x9BAA0E

def main():
    stock = open(STOCK, 'rb').read()
    our = open(OUR, 'rb').read()
    s3 = stock[S3:S3E]
    assert len(our) < len(s3), 'our binary exceeds section_3!'
    hybrid = our + s3[len(our):]
    assert len(hybrid) == len(s3)
    open(OUT, 'wb').write(hybrid)
    diffs = [i for i in range(len(hybrid)) if hybrid[i] != s3[i]]
    print(f'hybrid: {hex(len(hybrid))} bytes == stock section_3')
    print(f'diffs vs stock: {len(diffs)} bytes, all inside our code range '
          f'(< {hex(len(our))}): {all(d < len(our) for d in diffs)}')

if __name__ == '__main__':
    main()
