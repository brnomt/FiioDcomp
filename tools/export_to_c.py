#!/usr/bin/env python3
"""
export_to_c.py — Export all decompiled functions from Ghidra to individual C files.

Organizes files by subsystem based on:
1. Named functions → firmware/{subsystem}/{function_name}.c
2. Unnamed functions → firmware/unidentified/{address}.c
"""
import json
import os
import re
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
FIRMWARE = ROOT / "firmware"

# Load decompilations
decomp_file = BUILD / "all_decompilations.json"
decomps = json.loads(decomp_file.read_text(encoding="utf-8"))
print(f"Loaded {len(decomps)} decompilations")

# Load symbol index to get tags/names
symbol_file = ROOT / "docs" / "symbol-index.md"
symbol_text = symbol_file.read_text(encoding="utf-8")

# Parse symbol index for tagged functions
# Format: | `name` | `0xADDR` | tags |
symbol_tags = {}
for line in symbol_text.split("\n"):
    m = re.match(r'\|\s*`(\w+)`\s*\|\s*`(0x[0-9a-fA-F]+)`\s*\|\s*(.+?)\s*\|', line)
    if m:
        name, addr, tags = m.groups()
        symbol_tags[name] = {"address": addr, "tags": tags.strip()}

print(f"Loaded {len(symbol_tags)} tagged symbols from docs/symbol-index.md")

# Map addresses to names from symbol index
addr_to_name = {}
for name, info in symbol_tags.items():
    addr = info["address"].replace("0x", "").lower()
    addr_to_name[addr] = name

# Tag → subsystem directory mapping
TAG_TO_DIR = {
    "audio": "apps/audio",
    "codec": "codecs",
    "mp3": "codecs/mp3",
    "flac": "codecs/flac",
    "aac": "codecs/aac",
    "wma": "codecs/wma",
    "wav": "codecs/wav",
    "ogg": "codecs/ogg",
    "ape": "codecs/ape",
    "dsd": "codecs/dsd",
    "os": "firmware/os",
    "fs": "firmware/filesystem",
    "dsp": "firmware/dsp",
    "usb": "firmware/usb",
    "ui": "apps/ui",
    "bluetooth": "apps/bluetooth",
    "recording": "apps/recorder",
    "media": "firmware/media",
    "rom": "stubs",
    "tls": "crypto",
    "crypto": "crypto",
    "network": "network",
    "sd": "drivers/sd",
    "flash": "drivers/flash",
    "uart": "drivers/uart",
    "init": "firmware/os",
    "bitstream": "firmware/os",
}

def get_subsystem(tags_str):
    """Determine subsystem directory from tags."""
    tags = [t.strip() for t in tags_str.split(",")]
    for tag in tags:
        if tag in TAG_TO_DIR:
            return TAG_TO_DIR[tag]
    return "unidentified"

def sanitize_code(code):
    """Clean up decompiled code."""
    # Remove Ghidra-specific annotations
    code = re.sub(r'/\*\s*0x[0-9a-fA-F]+\s*\*/', '', code)
    return code

def generate_header(name, addr, tags):
    """Generate a C header comment."""
    return f"""/**
 * {name} @ 0x{addr}
 * Tags: {tags}
 * Auto-exported from Ghidra decompilation
 */
"""

# Track stats
stats = defaultdict(int)
created_files = []

for func_key, info in decomps.items():
    addr = info.get("address", "")
    code = info.get("code", "")
    
    if not code or len(code) < 20:
        stats["skipped_empty"] += 1
        continue
    
    # Get name
    clean_addr = addr.lower().replace("0x", "")
    if func_key.startswith("FUN_") and clean_addr in addr_to_name:
        name = addr_to_name[clean_addr]
    else:
        name = func_key
    
    # Get tags and subsystem
    if name in symbol_tags:
        tags = symbol_tags[name]["tags"]
    else:
        tags = "unidentified"
    
    subsystem = get_subsystem(tags)
    
    # Create directory
    subdir = FIRMWARE / subsystem
    subdir.mkdir(parents=True, exist_ok=True)
    
    # Create filename
    safe_name = re.sub(r'[^\w]', '_', name)
    filename = subdir / f"{safe_name}.c"
    
    # Generate file content
    header = generate_header(name, addr, tags)
    content = header + "\n" + code + "\n"
    
    # Write file
    filename.write_text(content, encoding="utf-8")
    created_files.append(str(filename.relative_to(ROOT)))
    stats[subsystem] += 1

# Write summary
print(f"\n{'='*60}")
print(f"EXPORT SUMMARY")
print(f"{'='*60}")
print(f"Total functions exported: {len(created_files)}")
print(f"\nBy subsystem:")
for subsystem, count in sorted(stats.items(), key=lambda x: -x[1]):
    print(f"  {subsystem}: {count}")

# Save file list
file_list = BUILD / "exported_c_files.json"
file_list.write_text(json.dumps(created_files, indent=2), encoding="utf-8")
print(f"\nFile list saved to: {file_list}")

# Create index file
index_path = FIRMWARE / "INDEX.md"
with open(index_path, "w", encoding="utf-8") as f:
    f.write("# Fiio Echo Mini Firmware — C Source Index\n\n")
    f.write(f"Exported {len(created_files)} functions from Ghidra decompilation.\n\n")
    f.write("## By Subsystem\n\n")
    
    by_subdir = defaultdict(list)
    for fp in created_files:
        parts = Path(fp).parts
        if len(parts) >= 2:
            subdir = parts[1]
        else:
            subdir = "other"
        by_subdir[subdir].append(fp)
    
    for subdir in sorted(by_subdir.keys()):
        files = by_subdir[subdir]
        f.write(f"### {subdir} ({len(files)} files)\n")
        for fp in sorted(files):
            f.write(f"- `{fp}`\n")
        f.write("\n")

print(f"Index written to: {index_path}")
