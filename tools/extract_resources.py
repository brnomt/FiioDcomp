#!/usr/bin/env python3
"""
extract_resources.py — Parse ROCK26IMAGERES + metadata, export RGB565 BMPs.

Firmware layout (HIFIEC*.IMG):
  Header @ 0x14C: part5_offset, part5_size  (resource partition)
  Part5 starts with magic \"ROCK26IMAGERES\"
    +16: entry_count
    +32: array of 16-byte ROCK26 entries:
         u16 width | (u16 height << 16), flags, byte_size, offset_in_part5
  Metadata table (108 bytes/entry), V3.7 layout:
         +0x00 name (ASCII, may have trailing spaces)
         +0x60 offset, width, height  (u32 LE each)

Pixels are RGB565, big-endian (byte-swapped) row-major.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
import zlib
from pathlib import Path

ROCK26_MAGIC = b"ROCK26IMAGERES"
METADATA_ENTRY = 108
PART5_INFO_OFF = 0x14C


def _u32(data: bytes, off: int) -> int:
    return struct.unpack_from("<I", data, off)[0]


def parse_part5_bounds(img: bytes) -> tuple[int, int]:
    off, size = struct.unpack_from("<II", img, PART5_INFO_OFF)
    if off == 0 or size == 0 or off + size > len(img):
        raise ValueError(f"invalid part5 bounds off=0x{off:X} size=0x{size:X}")
    return off, size


def parse_rock26(part5: bytes) -> tuple[int, list[dict]]:
    magic_off = part5.find(ROCK26_MAGIC)
    if magic_off < 0:
        raise ValueError("ROCK26IMAGERES magic not found in part5")
    count = _u32(part5, magic_off + 16)
    start = magic_off + 32
    entries: list[dict] = []
    for i in range(count):
        base = start + i * 16
        w_h, flags, size, offset = struct.unpack_from("<IIII", part5, base)
        w, h = w_h & 0xFFFF, w_h >> 16
        entries.append(
            {
                "index": i,
                "width": w,
                "height": h,
                "flags": flags,
                "size": size,
                "offset": offset,
            }
        )
    return magic_off, entries


def _meta_name(entry: bytes) -> str:
    raw = entry[:64].split(b"\x00", 1)[0]
    return raw.decode("ascii", "ignore").strip()


def find_metadata_table(part5: bytes, rock26: list[dict]) -> tuple[int, list[dict]]:
    """Locate the 108-byte metadata catalog (names + dims)."""
    if not rock26:
        raise ValueError("empty ROCK26 table")
    anchor = rock26[0]["offset"]
    aw, ah = rock26[0]["width"], rock26[0]["height"]

    def is_v37_entry(pos: int) -> bool:
        off, w, h = struct.unpack_from("<III", part5, pos + 0x60)
        if off != anchor or w != aw or h != ah:
            return False
        return _meta_name(part5[pos : pos + METADATA_ENTRY]).upper().endswith(".BMP")

    def is_legacy_entry(pos: int) -> bool:
        off = _u32(part5, pos + 20)
        if off != anchor:
            return False
        name = part5[pos + 32 : pos + 96].split(b"\x00", 1)[0].decode("ascii", "ignore")
        return name.upper().endswith(".BMP")

    first_match: int | None = None
    layout_v37 = True
    # Fast path: name string search (V3.7 stores name at entry +0)
    for needle in (b"POWERON0_(0,0).BMP", b"POWERON0"):
        rel = 0
        while True:
            hit = part5.find(needle, rel)
            if hit < 0:
                break
            if hit + METADATA_ENTRY <= len(part5) and is_v37_entry(hit):
                first_match = hit
                break
            rel = hit + 1
        if first_match is not None:
            break

    if first_match is None:
        for pos in range(0, len(part5) - METADATA_ENTRY, 4):
            if is_v37_entry(pos):
                first_match = pos
                break
            if is_legacy_entry(pos):
                first_match = pos
                layout_v37 = False
                break

    if first_match is None:
        raise ValueError("metadata table not found (anchor mismatch)")

    table_start = first_match
    while table_start >= METADATA_ENTRY:
        prev = table_start - METADATA_ENTRY
        if layout_v37:
            name = _meta_name(part5[prev : prev + METADATA_ENTRY])
        else:
            name = part5[prev + 32 : prev + 96].split(b"\x00", 1)[0].decode("ascii", "ignore").strip()
        if name.upper().endswith(".BMP"):
            table_start = prev
        else:
            break

    metas: list[dict] = []
    pos = table_start
    while pos + METADATA_ENTRY <= len(part5) and len(metas) < len(rock26):
        entry = part5[pos : pos + METADATA_ENTRY]
        if layout_v37:
            name = _meta_name(entry)
            off, w, h = struct.unpack_from("<III", entry, 0x60)
        else:
            name = entry[32:96].split(b"\x00", 1)[0].decode("ascii", "ignore").strip()
            off, w, h = struct.unpack_from("<III", entry, 20)
        if not name.upper().endswith(".BMP"):
            break
        metas.append(
            {
                "name": name,
                "offset": off,
                "width": w,
                "height": h,
                "table_pos": pos,
            }
        )
        pos += METADATA_ENTRY
    return table_start, metas


def merge_resources(rock26: list[dict], metas: list[dict]) -> list[dict]:
    """Pair ROCK26 geometry with metadata names (ROCK26 is authoritative)."""
    meta_by_off = {m["offset"]: m for m in metas}
    out: list[dict] = []
    for e in rock26:
        meta = meta_by_off.get(e["offset"])
        name = meta["name"] if meta else f"res_{e['index']:04d}.BMP"
        w, h = e["width"], e["height"]
        out.append(
            {
                "index": e["index"],
                "name": name,
                "offset": e["offset"],
                "width": w,
                "height": h,
                "size": e["size"],
                "meta_pos": meta["table_pos"] if meta else None,
            }
        )
    return out


def rgb565_be_to_rgba(raw: bytes, w: int, h: int) -> bytes:
    need = w * h * 2
    if len(raw) < need:
        raw = raw + b"\x00" * (need - len(raw))
    out = bytearray(w * h * 4)
    for i in range(w * h):
        pix = (raw[i * 2] << 8) | raw[i * 2 + 1]
        r = ((pix >> 11) & 0x1F) * 255 // 31
        g = ((pix >> 5) & 0x3F) * 255 // 63
        b = (pix & 0x1F) * 255 // 31
        j = i * 4
        out[j] = r
        out[j + 1] = g
        out[j + 2] = b
        out[j + 3] = 255
    return bytes(out)


def write_png(path: Path, w: int, h: int, rgba: bytes) -> None:
    """Minimal PNG writer (no external deps)."""

    def chunk(tag: bytes, data: bytes) -> bytes:
        return (
            struct.pack(">I", len(data))
            + tag
            + data
            + struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF)
        )

    raw = bytearray()
    stride = w * 4
    for y in range(h):
        raw.append(0)  # filter None
        raw.extend(rgba[y * stride : (y + 1) * stride])
    ihdr = struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0)
    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", ihdr) + chunk(b"IDAT", zlib.compress(bytes(raw), 9)) + chunk(b"IEND", b"")
    path.write_bytes(png)


def extract_all(img_path: Path, out_dir: Path, limit: int | None = None) -> dict:
    img = img_path.read_bytes()
    part5_off, part5_size = parse_part5_bounds(img)
    part5 = img[part5_off : part5_off + part5_size]
    rock26_off, rock26 = parse_rock26(part5)
    meta_off, metas = find_metadata_table(part5, rock26)
    resources = merge_resources(rock26, metas)

    out_dir.mkdir(parents=True, exist_ok=True)
    bmp_dir = out_dir / "bmp"
    bmp_dir.mkdir(exist_ok=True)

    exported = 0
    skipped = 0
    manifest = []
    for res in resources:
        if limit is not None and exported >= limit:
            break
        off, w, h = res["offset"], res["width"], res["height"]
        size = w * h * 2
        ok = off > 0 and w > 0 and h > 0 and off + size <= len(part5)
        entry = {**res, "ok": ok}
        manifest.append(entry)
        if not ok:
            skipped += 1
            continue
        raw = part5[off : off + size]
        rgba = rgb565_be_to_rgba(raw, w, h)
        safe = res["name"].replace("/", "_").replace("\\", "_")
        if not safe.lower().endswith(".bmp"):
            safe += ".BMP"
        png_name = Path(safe).with_suffix(".png").name
        write_png(bmp_dir / png_name, w, h, rgba)
        # Also keep raw RGB565 for round-trip repack
        (bmp_dir / (Path(safe).stem + ".rgb565")).write_bytes(raw)
        exported += 1

    summary = {
        "image": str(img_path),
        "part5_offset": part5_off,
        "part5_size": part5_size,
        "rock26_offset_in_part5": rock26_off,
        "metadata_offset_in_part5": meta_off,
        "rock26_count": len(rock26),
        "metadata_count": len(metas),
        "exported": exported,
        "skipped": skipped,
        "resources": manifest,
    }
    (out_dir / "manifest.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    return summary


def main() -> int:
    ap = argparse.ArgumentParser(description="Extract Echo Mini ROCK26 resources")
    ap.add_argument(
        "image",
        nargs="?",
        type=Path,
        default=Path("stock/ECHO MINI V3.7.0/HIFIEC37.IMG"),
        help="path to HIFIEC*.IMG",
    )
    ap.add_argument(
        "-o",
        "--output",
        type=Path,
        default=Path("build/resources"),
        help="output directory",
    )
    ap.add_argument("--limit", type=int, default=None, help="export only first N images")
    args = ap.parse_args()

    if not args.image.is_file():
        print(f"image not found: {args.image}", file=sys.stderr)
        return 1

    summary = extract_all(args.image, args.output, args.limit)
    print(f"part5 @ 0x{summary['part5_offset']:X} size 0x{summary['part5_size']:X}")
    print(f"ROCK26 entries: {summary['rock26_count']}")
    print(f"metadata names: {summary['metadata_count']}")
    print(f"exported: {summary['exported']}  skipped: {summary['skipped']}")
    print(f"manifest: {args.output / 'manifest.json'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
