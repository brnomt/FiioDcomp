#!/usr/bin/env python3
"""
pack_img.py — Splice a custom section_3 (main firmware code) into a stock HIFIEC*.IMG.

IMG layout (HIFIEC37.IMG, 33,554,436 bytes = 32 MiB + 4-byte trailer):

    0x00000000  header + reloc table
    0x00057820  bootloader (stock — preserved)
    0x00081A14  section_3: main firmware code (RKnanoFW image)  ← REPLACEABLE
    0x009BAA0E  ROCK26 resources (UI bitmaps — preserved)
    0x01FC13F6  end of part5 (per header @ 0x14C)
    0x01FC41F8  RKnanoFW end marker + padding
    0x02000000  4-byte EOF trailer (0x1EA1C309 for v3.7.0)

Usage:
    # Extract stock section_3 for analysis or identity test
    python tools/pack_img.py --extract -o build/section3_stock.bin

    # Identity test: extract, repack unchanged, verify byte-identical
    python tools/pack_img.py --identity-test

    # Pack custom section_3 into stock IMG
    python tools/pack_img.py --pack build/section3_custom.bin -o build/custom.IMG

    # Pack with explicit stock source
    python tools/pack_img.py --pack build/section3_custom.bin \
        --stock "stock/3.7.0/ECHO MINI V3.7.0/HIFIEC37.IMG" -o build/custom.IMG

The section_3 region is 0x081A14–0x009BAA0E (9,670,650 bytes = 0x938FFA).
A custom section_3 must be <= this size; if shorter, the remainder is zero-padded.
The EOF trailer is always preserved from stock.

Milestone M2: --identity-test should produce a byte-identical IMG.
"""

from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from pathlib import Path

# --- Layout constants (from docs/memory-map.md + verify_boundaries.py) ---
SECTION3_OFFSET = 0x00081A14
SECTION3_END    = 0x009BAA0E
SECTION3_SIZE   = SECTION3_END - SECTION3_OFFSET  # 0x938FFA = 9,670,650

TRAILER_OFFSET  = 0x02000000
IMG_SIZE        = 0x02000004  # 33,554,436

DEFAULT_STOCK  = "stock/3.7.0/ECHO MINI V3.7.0/HIFIEC37.IMG"


def read_trailer(data: bytes) -> int:
    return struct.unpack_from("<I", data, len(data) - 4)[0]


def extract_section3(img: bytes, out_path: Path) -> int:
    """Extract the section_3 region from an IMG to a .bin file."""
    section = img[SECTION3_OFFSET:SECTION3_END]
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(section)
    print(f"extracted section_3: {len(section):,} bytes (0x{len(section):X})")
    print(f"  SHA-256: {hashlib.sha256(section).hexdigest()[:16]}...")
    print(f"  -> {out_path}")
    return len(section)


def pack_section3(stock_img: bytes, custom_section3: bytes, out_path: Path) -> Path:
    """Splice a custom section_3 into a stock IMG, preserving everything else."""
    if len(stock_img) != IMG_SIZE:
        raise ValueError(
            f"stock IMG size {len(stock_img)} != expected {IMG_SIZE}"
        )
    if len(custom_section3) > SECTION3_SIZE:
        raise ValueError(
            f"custom section_3 too large: {len(custom_section3):,} > {SECTION3_SIZE:,}"
        )

    # Start from a mutable copy of stock
    out = bytearray(stock_img)

    # Write custom section_3, zero-pad the remainder
    out[SECTION3_OFFSET : SECTION3_OFFSET + len(custom_section3)] = custom_section3
    if len(custom_section3) < SECTION3_SIZE:
        pad_start = SECTION3_OFFSET + len(custom_section3)
        out[pad_start:SECTION3_END] = b"\x00" * (SECTION3_SIZE - len(custom_section3))

    # Preserve the original trailer
    trailer = read_trailer(stock_img)
    struct.pack_into("<I", out, TRAILER_OFFSET, trailer)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(out)

    print(f"packed {len(custom_section3):,} bytes of section_3 into {out_path}")
    print(f"  section_3 fill: {len(custom_section3):,}/{SECTION3_SIZE:,} "
          f"({100 * len(custom_section3) / SECTION3_SIZE:.1f}%)")
    print(f"  trailer preserved: 0x{trailer:08X}")
    print(f"  output size: {len(out):,} bytes")
    return out_path


def identity_test(stock_path: Path) -> bool:
    """Extract section_3, repack unchanged, verify byte-identical output."""
    print(f"=== Identity Test (M2 milestone) ===")
    print(f"stock: {stock_path}")
    print()

    stock_img = stock_path.read_bytes()
    if len(stock_img) != IMG_SIZE:
        print(f"ERROR: stock size {len(stock_img)} != {IMG_SIZE}", file=sys.stderr)
        return False

    # Extract
    print("[1/3] Extracting section_3 from stock...")
    section3 = stock_img[SECTION3_OFFSET:SECTION3_END]
    print(f"      {len(section3):,} bytes, SHA-256 {hashlib.sha256(section3).hexdigest()[:16]}...")
    print()

    # Repack
    print("[2/3] Repacking section_3 into a new IMG...")
    out = bytearray(stock_img)
    out[SECTION3_OFFSET:SECTION3_END] = section3  # identity
    trailer = read_trailer(stock_img)
    struct.pack_into("<I", out, TRAILER_OFFSET, trailer)
    print(f"      output: {len(out):,} bytes, trailer 0x{trailer:08X}")
    print()

    # Verify
    print("[3/3] Verifying byte-identical...")
    if bytes(out) == stock_img:
        print("      PASS — output is byte-identical to stock")
        print()
        print("M2 PASSED: pack_img.py can reproduce stock IMG from its own section_3.")
        print("Next: flash the repacked IMG to confirm the device boots identically.")
        return True
    else:
        # Find first diff
        diffs = [i for i in range(min(len(out), len(stock_img))) if out[i] != stock_img[i]]
        if diffs:
            first = diffs[0]
            print(f"      FAIL — first diff at 0x{first:08X}")
            print(f"        stock: {stock_img[first:first+16].hex()}")
            print(f"        out:   {bytes(out[first:first+16]).hex()}")
            print(f"        total diff bytes: {len(diffs)}")
        else:
            print("      FAIL — size or content mismatch")
        return False


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Pack/extract section_3 in Echo Mini HIFIEC*.IMG"
    )
    ap.add_argument(
        "--stock",
        type=Path,
        default=Path(DEFAULT_STOCK),
        help=f"stock IMG path (default: {DEFAULT_STOCK})",
    )
    mode = ap.add_mutually_exclusive_group(required=True)
    mode.add_argument(
        "--extract",
        action="store_true",
        help="extract section_3 from stock IMG to -o",
    )
    mode.add_argument(
        "--pack",
        type=Path,
        metavar="BIN",
        help="pack a custom section_3 .bin into stock IMG",
    )
    mode.add_argument(
        "--identity-test",
        action="store_true",
        help="extract + repack unchanged + verify byte-identical (M2 milestone)",
    )
    ap.add_argument(
        "-o", "--output",
        type=Path,
        default=Path("build/section3_stock.bin"),
        help="output path for --extract or --pack",
    )
    args = ap.parse_args()

    if not args.stock.is_file():
        print(f"ERROR: stock IMG not found: {args.stock}", file=sys.stderr)
        print(f"  Expected: {DEFAULT_STOCK}", file=sys.stderr)
        print("  Update --stock or place HIFIEC37.IMG there.", file=sys.stderr)
        return 1

    if args.identity_test:
        ok = identity_test(args.stock)
        return 0 if ok else 1

    stock_img = args.stock.read_bytes()

    if args.extract:
        extract_section3(stock_img, args.output)
        return 0

    if args.pack:
        if not args.pack.is_file():
            print(f"ERROR: section_3 bin not found: {args.pack}", file=sys.stderr)
            return 1
        custom = args.pack.read_bytes()
        pack_section3(stock_img, custom, args.output)
        return 0

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
