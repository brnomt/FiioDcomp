#!/usr/bin/env python3
"""Collect all new function names from matching and print them."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# Load all match results
all_names = {}
for fname in ["functionality_matches_v2.json", "structural_matches.json", 
              "combined_matches.json", "callgraph_propagation_matches.json"]:
    fpath = BUILD / fname
    if fpath.exists():
        data = json.loads(fpath.read_text(encoding="utf-8"))
        for match in data:
            addr = match.get("binary_addr", match.get("address", ""))
            name = match.get("sdk_func", match.get("sdk_name", match.get("new_name", "")))
            if addr and name:
                all_names[addr] = name

print(f"Total unique new names: {len(all_names)}")
print("\nNew function names:")
for addr, name in sorted(all_names.items()):
    print(f"  {addr} -> {name}")

# Save consolidated list
output = BUILD / "new_function_names.json"
output.write_text(json.dumps(all_names, indent=2), encoding="utf-8")
print(f"\nSaved to: {output}")
