#!/usr/bin/env python3
"""
repack_firmware.py — Replace ROCK26 bitmaps in a HIFIEC*.IMG and save.

Replacements are matched by resource name (e.g. POWERON0_(0,0).BMP).
Accepted inputs per resource (first match wins):
  - <stem>.rgb565  (raw big-endian RGB565, exact size)
  - <stem>.png     (converted to RGB565 BE; must match width/height)

Preserves the original 4-byte EOF trailer (see crc_util.py).
"""

from __future__ import annotations

import argparse
import struct
import sys
import zlib
from pathlib import Path

from crc_util import preserve_trailer, read_trailer
from extract_resources import (
    METADATA_ENTRY,
    merge_resources,
    find_metadata_table,
    parse_part5_bounds,
    parse_rock26,
)


def rgba_to_rgb565_be(rgba: bytes, w: int, h: int) -> bytes:
    out = bytearray(w * h * 2)
    for i in range(w * h):
        r, g, b = rgba[i * 4], rgba[i * 4 + 1], rgba[i * 4 + 2]
        pix = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)
        out[i * 2] = (pix >> 8) & 0xFF
        out[i * 2 + 1] = pix & 0xFF
    return bytes(out)


def read_png_rgba(path: Path) -> tuple[int, int, bytes]:
    """Minimal PNG reader (8-bit RGBA/RGB, non-interlaced)."""
    data = path.read_bytes()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError(f"not a PNG: {path}")
    pos = 8
    width = height = None
    raw_idat = bytearray()
    color_type = None
    bit_depth = None
    while pos + 8 <= len(data):
        length = struct.unpack_from(">I", data, pos)[0]
        tag = data[pos + 4 : pos + 8]
        chunk = data[pos + 8 : pos + 8 + length]
        pos += 12 + length
        if tag == b"IHDR":
            width, height, bit_depth, color_type, *_ = struct.unpack(">IIBBBBB", chunk)
        elif tag == b"IDAT":
            raw_idat.extend(chunk)
        elif tag == b"IEND":
            break
    if width is None or height is None or color_type is None:
        raise ValueError(f"incomplete PNG: {path}")
    if bit_depth != 8 or color_type not in (2, 6):
        raise ValueError(f"unsupported PNG format (need 8-bit RGB/RGBA): {path}")

    decompressed = zlib.decompress(bytes(raw_idat))
    bpp = 3 if color_type == 2 else 4
    stride = width * bpp
    rows = []
    expect = (stride + 1) * height
    if len(decompressed) < expect:
        raise ValueError(f"truncated PNG pixels: {path}")
    cursor = 0
    prev = bytearray(stride)
    for _ in range(height):
        filt = decompressed[cursor]
        cursor += 1
        row = bytearray(decompressed[cursor : cursor + stride])
        cursor += stride
        if filt == 0:
            pass
        elif filt == 1:  # Sub
            for i in range(bpp, stride):
                row[i] = (row[i] + row[i - bpp]) & 0xFF
        elif filt == 2:  # Up
            for i in range(stride):
                row[i] = (row[i] + prev[i]) & 0xFF
        elif filt == 3:  # Average
            for i in range(stride):
                left = row[i - bpp] if i >= bpp else 0
                row[i] = (row[i] + ((left + prev[i]) // 2)) & 0xFF
        elif filt == 4:  # Paeth
            for i in range(stride):
                a = row[i - bpp] if i >= bpp else 0
                b = prev[i]
                c = prev[i - bpp] if i >= bpp else 0
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if pa <= pb and pa <= pc else (b if pb <= pc else c)
                row[i] = (row[i] + pr) & 0xFF
        else:
            raise ValueError(f"unsupported PNG filter {filt} in {path}")
        rows.append(bytes(row))
        prev = row

    rgba = bytearray(width * height * 4)
    for y, row in enumerate(rows):
        for x in range(width):
            j = (y * width + x) * 4
            if bpp == 3:
                rgba[j : j + 3] = row[x * 3 : x * 3 + 3]
                rgba[j + 3] = 255
            else:
                rgba[j : j + 4] = row[x * 4 : x * 4 + 4]
    return width, height, bytes(rgba)


def load_replacement(folder: Path, name: str, w: int, h: int) -> bytes | None:
    stem = Path(name).stem
    rgb_path = folder / f"{stem}.rgb565"
    png_path = folder / f"{stem}.png"
    need = w * h * 2
    if rgb_path.is_file():
        raw = rgb_path.read_bytes()
        if len(raw) != need:
            raise ValueError(f"{rgb_path} size {len(raw)} != {need}")
        return raw
    if png_path.is_file():
        pw, ph, rgba = read_png_rgba(png_path)
        if pw != w or ph != h:
            raise ValueError(f"{png_path} is {pw}x{ph}, resource is {w}x{h}")
        return rgba_to_rgb565_be(rgba, w, h)
    return None


def repack(img_path: Path, replacements_dir: Path, out_path: Path) -> int:
    original = img_path.read_bytes()
    data = bytearray(original)
    part5_off, part5_size = parse_part5_bounds(data)
    part5 = memoryview(data)[part5_off : part5_off + part5_size]

    part5_bytes = bytes(part5)
    rock26_off, rock26 = parse_rock26(part5_bytes)
    _, metas = find_metadata_table(part5_bytes, rock26)
    resources = merge_resources(rock26, metas)

    replaced = 0
    for res in resources:
        raw = load_replacement(replacements_dir, res["name"], res["width"], res["height"])
        if raw is None:
            continue
        off = res["offset"]
        size = res["width"] * res["height"] * 2
        abs_off = part5_off + off
        if off <= 0 or abs_off + size > part5_off + part5_size:
            raise ValueError(f"bad offset for {res['name']}: 0x{off:X}")
        data[abs_off : abs_off + size] = raw
        # Keep ROCK26 size field consistent
        r26_abs = part5_off + rock26_off + 32 + res["index"] * 16
        struct.pack_into("<I", data, r26_abs + 8, size)
        # Metadata dims/offset (V3.7 @ +0x60)
        if res.get("meta_pos") is not None:
            meta_abs = part5_off + res["meta_pos"]
            struct.pack_into("<III", data, meta_abs + 0x60, off, res["width"], res["height"])
        replaced += 1
        print(f"replaced {res['name']} ({res['width']}x{res['height']})")

    trailer = preserve_trailer(original, data)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(data)
    print(f"wrote {out_path} ({replaced} replacements, trailer 0x{trailer:08X})")
    return replaced


def main() -> int:
    ap = argparse.ArgumentParser(description="Repack Echo Mini IMG resources")
    ap.add_argument("image", type=Path, help="source HIFIEC*.IMG")
    ap.add_argument(
        "-r",
        "--replacements",
        type=Path,
        required=True,
        help="directory of .png / .rgb565 replacements",
    )
    ap.add_argument(
        "-o",
        "--output",
        type=Path,
        required=True,
        help="output IMG path",
    )
    args = ap.parse_args()
    if not args.image.is_file():
        print(f"missing image: {args.image}", file=sys.stderr)
        return 1
    if not args.replacements.is_dir():
        print(f"missing replacements dir: {args.replacements}", file=sys.stderr)
        return 1
    repack(args.image, args.replacements, args.output)
    print(f"source trailer was 0x{read_trailer(args.image.read_bytes()):08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
