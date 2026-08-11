#!/usr/bin/env python3
"""Compare two HIFIEC*.IMG firmware files and report byte-level changes."""

from __future__ import annotations

import argparse
import hashlib
import struct
from pathlib import Path


def parse_section_table(data: bytes) -> list[dict]:
    """Parse outer section table @ 0x50 (4 x uint32 per entry after count)."""
    count = struct.unpack_from("<I", data, 0x50)[0]
    entries = []
    off = 0x54
    for _ in range(count):
        a, b, c, d = struct.unpack_from("<IIII", data, off)
        entries.append({"file_off": a, "size": b, "load": c, "flags": d})
        off += 16
    return entries


def diff_runs(old: bytes, new: bytes) -> list[tuple[int, int]]:
    diffs = [i for i, (a, b) in enumerate(zip(old, new)) if a != b]
    if not diffs:
        return []
    runs: list[tuple[int, int]] = []
    s = e = diffs[0]
    for d in diffs[1:]:
        if d == e + 1:
            e = d
        else:
            runs.append((s, e))
            s = e = d
    runs.append((s, e))
    return runs


def main() -> None:
    ap = argparse.ArgumentParser(description="Diff two Echo Mini IMG files")
    ap.add_argument("old_img", type=Path)
    ap.add_argument("new_img", type=Path)
    ap.add_argument("-o", "--output", type=Path, help="write report markdown")
    args = ap.parse_args()

    old = args.old_img.read_bytes()
    new = args.new_img.read_bytes()

    lines: list[str] = []
    def out(s: str = "") -> None:
        lines.append(s)
        print(s)

    out(f"# Firmware diff: {args.old_img.name} -> {args.new_img.name}")
    out()
    out(f"| | {args.old_img.name} | {args.new_img.name} |")
    out(f"|--|--|--|")
    out(f"| Size | {len(old):,} | {len(new):,} |")
    out(f"| SHA-256 | `{hashlib.sha256(old).hexdigest()}` | `{hashlib.sha256(new).hexdigest()}` |")
    if len(old) == len(new):
        trailer_old = struct.unpack("<I", old[-4:])[0]
        trailer_new = struct.unpack("<I", new[-4:])[0]
        out(f"| EOF trailer | `0x{trailer_old:08X}` | `0x{trailer_new:08X}` |")

    runs = diff_runs(old, new)
    total = sum(e - s + 1 for s, e in runs)
    out()
    out(f"**Differing bytes:** {total:,} / {len(old):,} ({100 * total / len(old):.4f}%)")
    out(f"**Diff regions:** {len(runs)}")
    out()

    # Section-level summary
    if len(old) == len(new):
        try:
            secs_old = parse_section_table(old)
            secs_new = parse_section_table(new)
            out("## By IMG section")
            out()
            out("| Section | File offset | Size | Changed bytes |")
            out("|---------|-------------|------|---------------|")
            for i, (so, sn) in enumerate(zip(secs_old, secs_new)):
                fo, sz = so["file_off"], so["size"]
                changed = sum(
                    1 for j in range(sz) if fo + j < len(old) and old[fo + j] != new[fo + j]
                )
                label = ["reloc", "bootloader", "main fw", "padding"][i] if i < 4 else f"sec{i}"
                out(f"| {i} ({label}) | `0x{fo:08X}` | `0x{sz:X}` | {changed:,} |")
            out()
        except Exception as exc:
            out(f"(section parse skipped: {exc})")

    out("## Diff regions (top 40 by size)")
    out()
    out("| IMG offset | Length | Load addr hint |")
    out("|------------|--------|----------------|")
    for s, e in sorted(runs, key=lambda x: x[1] - x[0], reverse=True)[:40]:
        length = e - s + 1
        # section 3 load base ~0x03000000, file off 0x81A14
        load_hint = ""
        if 0x81A14 <= s < 0x1FC41F8:
            load_hint = f"`0x{0x03000000 + (s - 0x81A14):08X}`"
        out(f"| `0x{s:08X}` | {length:,} | {load_hint} |")

    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"\nWrote {args.output}")


if __name__ == "__main__":
    main()
