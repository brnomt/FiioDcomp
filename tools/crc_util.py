#!/usr/bin/env python3
"""
crc_util.py — Echo Mini / RKnano IMG trailer helpers.

The HIFIEC*.IMG container stores a 4-byte little-endian trailer at EOF.
Stock V3.7.0 ends with 0x1EA1C309. Community tools (Flame Ocean /
Echo-Mini-Customizer) report the device does not actively verify this
value during SD-card updates; it is still preserved/restored on save.
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path


def read_trailer(data: bytes | bytearray) -> int:
    if len(data) < 4:
        raise ValueError("image too small for trailer")
    return struct.unpack_from("<I", data, len(data) - 4)[0]


def write_trailer(data: bytearray, value: int) -> None:
    if len(data) < 4:
        raise ValueError("image too small for trailer")
    struct.pack_into("<I", data, len(data) - 4, value & 0xFFFFFFFF)


def preserve_trailer(original: bytes, modified: bytearray) -> int:
    """Copy the original EOF trailer onto a modified image; return its value."""
    trailer = read_trailer(original)
    if len(modified) < 4:
        raise ValueError("modified image too small")
    # If the file grew, keep trailer at the new EOF.
    write_trailer(modified, trailer)
    return trailer


def main() -> int:
    ap = argparse.ArgumentParser(description="Echo Mini IMG CRC/trailer utility")
    ap.add_argument("image", type=Path, help="HIFIEC*.IMG path")
    ap.add_argument(
        "--set",
        type=lambda s: int(s, 0),
        default=None,
        help="write trailer value (e.g. 0x1EA1C309); implies --in-place",
    )
    ap.add_argument(
        "--in-place",
        action="store_true",
        help="write changes back to the image file",
    )
    args = ap.parse_args()

    data = bytearray(args.image.read_bytes())
    cur = read_trailer(data)
    print(f"file:    {args.image}")
    print(f"size:    {len(data)} (0x{len(data):X})")
    print(f"trailer: 0x{cur:08X}")

    if args.set is not None:
        write_trailer(data, args.set)
        if not args.in_place:
            print("--set requires --in-place", file=sys.stderr)
            return 2
        args.image.write_bytes(data)
        print(f"wrote trailer 0x{args.set:08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
