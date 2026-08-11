#!/usr/bin/env python3
"""Check what strings are in section_3 and compare to SDK strings."""
import json, re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
string_map = json.loads((ROOT / "build" / "sdk_string_map.json").read_text(encoding="utf-8"))

# Extract all printable strings >= 6 chars from section_3
print("=== Binary strings sample ===")
binary_strings = set()
current = bytearray()
for i, b in enumerate(section3):
    if 32 <= b < 127:
        current.append(b)
    else:
        if len(current) >= 6:
            s = current.decode('ascii', errors='ignore')
            binary_strings.add(s)
        current = bytearray()
if len(current) >= 6:
    binary_strings.add(current.decode('ascii', errors='ignore'))

print(f"Binary strings (>= 6 chars): {len(binary_strings)}")

# Show some samples
samples = [s for s in sorted(binary_strings) if len(s) >= 8 and len(s) <= 40][:30]
print("Sample binary strings:")
for s in samples:
    print(f"  {s!r}")

# Check if SDK strings are substrings of binary strings
print("\n=== SDK string substring matches ===")
sdk_strings = list(string_map.keys())
substring_matches = 0
for sdk_str in sdk_strings:
    if len(sdk_str) < 6:
        continue
    for bin_str in binary_strings:
        if sdk_str in bin_str or bin_str in sdk_str:
            if abs(len(sdk_str) - len(bin_str)) < 10:  # close length
                substring_matches += 1
                if substring_matches <= 10:
                    print(f"  SDK: {sdk_str!r} ~= BIN: {bin_str!r} -> {string_map[sdk_str]}")
                break

print(f"Substring matches: {substring_matches}")

# Check for common patterns: file extensions, format strings
print("\n=== File format strings in binary ===")
for pattern in ['.mp3', '.flac', '.wav', '.ogg', '.ape', '.aac', '.wma', '.dsf', '.dff']:
    count = section3.count(pattern.encode())
    if count:
        print(f"  {pattern}: {count} occurrences")

# Check for known firmware strings
print("\n=== Known firmware strings ===")
for known in ['RKnanoFW', 'ROCK26', 'HIFIEC', 'ECHO', 'MINI', 'MusicInit', 'ID3', 'DICTDECODER', 'GOODEF', 'VorbisOGG']:
    pos = section3.find(known.encode())
    if pos >= 0:
        print(f"  {known} at section3 offset 0x{pos:08X} (load 0x{0x03000000 + pos:08X})")
