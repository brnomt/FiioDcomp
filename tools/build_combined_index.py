#!/usr/bin/env python3
"""Build combined SDK string map and function index from both MP3 V1.3 and Wireless V1.5."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

mp3_index = json.loads((ROOT / "build" / "sdk_function_index_mp3.json").read_text(encoding="utf-8"))
wireless_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

# Combine (MP3 takes priority since it matches the binary better)
combined = {}
for func_name, info in wireless_index.items():
    combined[func_name] = info
for func_name, info in mp3_index.items():
    combined[func_name] = info  # MP3 overwrites wireless for same name

# Write combined function index
out_idx = ROOT / "build" / "sdk_function_index_combined.json"
out_idx.write_text(json.dumps(combined, indent=2, ensure_ascii=False), encoding="utf-8")
print(f"Combined function index: {len(combined)} functions -> {out_idx}")

# Build combined string map (unique strings only)
string_map = {}
ambiguous = set()
for func_name, info in combined.items():
    for s in info.get("strings", []):
        if len(s) >= 6:
            if s in string_map and string_map[s] != func_name:
                ambiguous.add(s)
            else:
                string_map[s] = func_name
for s in ambiguous:
    del string_map[s]

out_map = ROOT / "build" / "sdk_string_map_combined.json"
out_map.write_text(json.dumps(string_map, indent=2, ensure_ascii=False), encoding="utf-8")
print(f"Combined string map: {len(string_map)} strings -> {out_map}")
