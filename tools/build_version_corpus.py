#!/usr/bin/env python3
"""
build_version_corpus.py — Paso 0: Normalize the firmware corpus.

Extracts section_3 (main firmware code) from every IMG in stock/,
hashes it, and deduplicates. Variants that share identical code get
collapsed so we only diff unique code versions.

Usage:
    python tools/build_version_corpus.py
"""
from __future__ import annotations

import glob
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"
BUILD = ROOT / "build"

# Layout constants (from decomp docs, verified on v3.7/v3.8)
IMG_SECTION3_OFF = 0x00081A14
MAIN_END = 0x009BAA0E
LOAD_BASE = 0x03000000

# Length check: RKnanoFW section 3 magic at 0x81A14
RKNANO_MAGIC = b"RKnanoFW"


def find_all_imgs() -> list[tuple[str, Path]]:
    """Find all IMG files, keyed by version folder."""
    imgs = []
    for img in sorted(STOCK.rglob("*.IMG")) + sorted(STOCK.rglob("*.img")):
        rel = img.relative_to(STOCK)
        version = rel.parts[0]
        imgs.append((version, img))
    return imgs


def extract_section3(data: bytes, path: Path) -> bytes | None:
    """Extract main firmware code. Returns None if layout doesn't match."""
    size = len(data)
    if size < IMG_SECTION3_OFF + 8:
        return None
    # Verify RKnanoFW magic near section 3 start
    magic_pos = data.find(RKNANO_MAGIC)
    if magic_pos < 0:
        return None
    # Section 3 is the main code blob. We expect magic at/near 0x81A14 for
    # recent versions; older versions may differ. Fall back to the offset
    # between the 2nd and 3rd RKnanoFW occurrences if available.
    positions = []
    pos = 0
    while True:
        pos = data.find(RKNANO_MAGIC, pos)
        if pos < 0:
            break
        positions.append(pos)
        pos += len(RKNANO_MAGIC)

    if len(positions) >= 3:
        # Section 3 typically starts right after section 2's data.
        # Use the fixed offset if magic validates, else the 3rd occurrence.
        if magic_pos == IMG_SECTION3_OFF - 8 or magic_pos == IMG_SECTION3_OFF:
            start = IMG_SECTION3_OFF
        else:
            start = positions[2]
        end = min(MAIN_END, size)
        # Make sure we don't grab the resource partition
        return data[start:end]
    return None


def main() -> None:
    imgs = find_all_imgs()
    if not imgs:
        sys.exit("No IMG files found in stock/")

    print(f"Found {len(imgs)} IMG files\n")
    print(f"{'Version':<12} {'Size':>10} {'SHA256 (sec3)':<16} {'Unique?'}  IMG")
    print("-" * 100)

    BUILD.mkdir(exist_ok=True)
    corpus = {}

    for version, img in imgs:
        try:
            data = img.read_bytes()
        except Exception as e:
            print(f"{version:<12} ERROR: {e}")
            continue

        sec3 = extract_section3(data, img)
        if sec3 is None:
            print(f"{version:<12} {'N/A':>10} layout mismatch          {img.name}")
            continue

        digest = hashlib.sha256(sec3).hexdigest()
        short = digest[:14]

        # Detect the load base by checking the RKnanoFW header near start
        # (for the corpus we assume 0x03000000; per-version table follows)
        entry = {
            "version": version,
            "img": str(img.relative_to(ROOT)),
            "img_size": len(data),
            "sec3_offset": IMG_SECTION3_OFF,
            "sec3_size": len(sec3),
            "sec3_sha256": digest,
            "load_base": LOAD_BASE,
        }
        corpus[version] = entry

    # Dedup by sec3 hash
    hash_groups = {}
    for version, entry in corpus.items():
        h = entry["sec3_sha256"]
        hash_groups.setdefault(h, []).append(version)

    print("\n=== CODE DEDUPLICATION (by section_3 hash) ===")
    uniq = 0
    for h, versions in sorted(hash_groups.items(), key=lambda kv: kv[1][0]):
        unique = "UNIQUE" if len(versions) == 1 else "DUPLICATE"
        if len(versions) == 1:
            uniq += 1
        print(f"  {h[:12]}  {len(versions)}x  {unique}: {', '.join(versions)}")

    print(f"\nTotal versions: {len(corpus)}, unique code versions: {uniq}")

    # Write corpus JSON
    out = {
        "layout": {
            "img_section3_off": IMG_SECTION3_OFF,
            "main_end": MAIN_END,
            "load_base": LOAD_BASE,
        },
        "versions": corpus,
        "dedup_groups": {h: v for h, v in hash_groups.items()},
        "unique_code_versions": uniq,
    }
    out_file = BUILD / "version_corpus.json"
    out_file.write_text(json.dumps(out, indent=2), encoding="utf-8")
    print(f"\nSaved to: {out_file}")


if __name__ == "__main__":
    main()
