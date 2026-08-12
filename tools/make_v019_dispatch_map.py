#!/usr/bin/env python3
"""make_v019_dispatch_map.py — build DISPATCH-MAPPING test IMGs.

Take the STOCK Echo Mini IMG and patch section_3 code at specific RAM
offsets to 'b .' (infinite loop, Thumb 0xE7FE little-endian = FE E7).
This empirically maps which menu feature dispatches to which section_3
offset: a feature that calls a hung offset crashes/freezes.

Layout: section_3 starts at IMG 0x81A14; RAM 0x03000000 == IMG 0x81A14,
so RAM offset X == IMG 0x81A14 + (X - 0x03000000).

Established on device (V0.18): firmware_entry (RAM 0x03000010) is called
for MEDIA operations (media library, music playback), NOT at boot —
patching it to 'b .' made media crash while menu/file browser/settings
kept working. 0x03000162 is `bx lr` in stock (no-op) — skip it.

Usage:
  python tools/make_v019_dispatch_map.py --build-all
  python tools/make_v019_dispatch_map.py -n map_USB \
      --offsets 0x0300016c,0x0300024e,0x03000aba -o build/X.IMG
"""
import argparse
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
STOCK = ROOT / "stock" / "3.7.0" / "ECHO MINI V3.7.0" / "HIFIEC37.IMG"
S3 = 0x81A14                      # section_3 start in the IMG
RAM_BASE = 0x03000000
HANG = b"\xfe\xe7"                # Thumb 'b .' (infinite loop)

# Known dispatch offsets (RAM). 0x03000162 is bx lr in stock -> skip.
KNOWN_OFFSETS = {
    "firmware_entry":    0x03000010,  # media ops (verified on device)
    "sec3_162_stub":     0x03000162,  # stock bx lr, skip
    "WriteData_To_Flash":0x0300016c,
    "MscTestUnitReady":  0x0300024e,
    "sec3_296":          0x03000296,
    "sec3_4f4":          0x030004f4,
    "sec3_546":          0x03000546,
    "sec3_a72":          0x03000a72,
    "sec3_a74":          0x03000a74,
    "main2_entry":       0x03000aba,  # USB MSC mode
    "application_start": 0x0300710a,  # UI event callback
}

# The three test groups the CFW dispatch-mapping campaign needs.
DEFAULT_GROUPS = {
    "map_USB":      [0x0300016c, 0x0300024e, 0x03000aba],
    "map_misc":     [0x03000296, 0x030004f4, 0x03000546,
                     0x03000a72, 0x03000a74],
    "map_appstart": [0x0300710a],
}


def img_addr(ram_offset: int) -> int:
    return S3 + (ram_offset - RAM_BASE)


def verify_code(stock: bytes, ram_offset: int) -> None:
    """Reject offsets that do not hold plausible Thumb code."""
    if ram_offset not in KNOWN_OFFSETS.values():
        # unknown offsets still must look like code, not zeros/0xFF
        pass
    a = img_addr(ram_offset)
    b0 = stock[a]
    if b0 in (0x00, 0xFF):
        raise ValueError(
            f"RAM {ram_offset:#x}: byte {b0:#04x} at IMG {a:#x} looks like "
            f"data/padding, not code — refusing to patch")
    print(f"  ok  RAM {ram_offset:#010x} -> IMG {a:#06x} "
          f"bytes {stock[a:a+4].hex()}")


def build_img(stock: bytes, offsets, out_path: Path) -> None:
    out = bytearray(stock)
    patched = []
    for off in sorted(offsets):
        a = img_addr(off)
        verify_code(stock, off)
        out[a:a + 2] = HANG
        patched.append(a)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(out)

    # verify: differs from stock ONLY at the patched 2-byte windows
    diffs = [i for i in range(len(out)) if out[i] != stock[i]]
    expected = set()
    for a in patched:
        expected.update((a, a + 1))
    if set(diffs) != expected:
        extra = sorted(set(diffs) - expected)[:8]
        missing = sorted(expected - set(diffs))[:8]
        raise RuntimeError(
            f"unexpected diff set: extra={[hex(x) for x in extra]} "
            f"missing={[hex(x) for x in missing]}")
    print(f"  wrote {out_path} ({len(out):,} bytes)")
    print(f"  diffs vs stock: {len(diffs)} bytes at "
          f"{[hex(x) for x in sorted(diffs)]}")


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Build dispatch-mapping IMGs (stock + 'b .' hangs).")
    mode = ap.add_mutually_exclusive_group(required=True)
    mode.add_argument("--build-all", action="store_true",
                      help="build all DEFAULT_GROUPS IMGs")
    mode.add_argument("-n", "--name", help="group name for -o")
    ap.add_argument("--offsets",
                    help="comma/space separated RAM offsets, e.g. "
                         "0x0300016c,0x0300024e")
    ap.add_argument("-o", "--out", type=Path, default=None)
    ap.add_argument("--stock", type=Path, default=STOCK,
                    help="stock IMG path (default: stock/3.7.0/.../HIFIEC37.IMG)")
    args = ap.parse_args()

    if not args.stock.is_file():
        print(f"ERROR: stock IMG not found: {args.stock}", file=sys.stderr)
        return 1
    stock = args.stock.read_bytes()

    if args.build_all:
        for name, offsets in DEFAULT_GROUPS.items():
            out = ROOT / "build" / f"ReChord_V0.19_{name}.IMG"
            print(f"== {name} ==")
            build_img(stock, offsets, out)
        return 0

    if not args.offsets or not args.out or not args.name:
        ap.error("--name, --offsets and -o are required without --build-all")
    offsets = [int(x, 0) for x in
               args.offsets.replace(",", " ").split()]
    build_img(stock, offsets, args.out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
