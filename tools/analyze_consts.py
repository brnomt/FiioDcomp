#!/usr/bin/env python3
"""Analyze constant distribution to tune the matching threshold."""
import re, json, urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
MIN_DISTINCTIVE_CONST = 0x100

sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))
for name, feats in sdk_features.items():
    feats["constants_set"] = set(feats.get("constants", []))

decomp = json.loads((ROOT / "build" / "all_decompilations.json").read_text(encoding="utf-8"))

result = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
data = json.loads(result.read().decode())
all_funcs = data.get("functions", data)
named_addrs = set(f["address"] for f in all_funcs
                  if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))

def extract_distinctive_constants(code):
    constants = set()
    for m in re.finditer(r"\b0x([0-9a-fA-F]+)\b", code):
        val = int(m.group(1), 16)
        if MIN_DISTINCTIVE_CONST <= val <= 0xFFFFFF:
            constants.add(val)
    clean = re.sub(r"/\*.*?\*/", "", code, flags=re.DOTALL)
    clean = re.sub(r"//.*?$", "", clean, flags=re.MULTILINE)
    clean = re.sub(r'"[^"]*"', '""', clean)
    for m in re.finditer(r"\b(\d{3,})\b", clean):
        val = int(m.group(1))
        if MIN_DISTINCTIVE_CONST <= val <= 0xFFFF:
            constants.add(val)
    return constants

bin_with_consts = 0
bin_const_counts = []
for func_name, info in decomp.items():
    addr = info.get("address", "")
    if addr in named_addrs:
        continue
    code = info.get("code", "")
    if not code or len(code) < 50:
        continue
    consts = extract_distinctive_constants(code)
    if len(consts) >= 1:
        bin_with_consts += 1
        bin_const_counts.append(len(consts))

print(f"Binary functions with >= 1 distinctive constant: {bin_with_consts}")
print(f"  With >= 2: {sum(1 for c in bin_const_counts if c >= 2)}")
print(f"  With >= 3: {sum(1 for c in bin_const_counts if c >= 3)}")
print(f"  With >= 5: {sum(1 for c in bin_const_counts if c >= 5)}")
if bin_const_counts:
    print(f"  Max: {max(bin_const_counts)}")
    print(f"  Avg: {sum(bin_const_counts)/len(bin_const_counts):.1f}")

sdk_const_counts = [len(f.get("constants_set", set())) for f in sdk_features.values()]
print(f"\nSDK functions with distinctive constants:")
print(f"  With >= 1: {sum(1 for c in sdk_const_counts if c >= 1)}")
print(f"  With >= 2: {sum(1 for c in sdk_const_counts if c >= 2)}")
print(f"  With >= 5: {sum(1 for c in sdk_const_counts if c >= 5)}")
print(f"  Max: {max(sdk_const_counts)}")

# Show some SDK functions with many constants
print("\nSDK functions with most distinctive constants:")
sorted_sdk = sorted(sdk_features.items(), key=lambda x: -len(x[1].get("constants_set", set())))
for name, feats in sorted_sdk[:15]:
    consts = sorted(feats.get("constants_set", set()))
    print(f"  {name:40s} {len(consts):3d} consts: {[hex(c) for c in consts[:10]]}")
