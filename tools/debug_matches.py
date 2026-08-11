#!/usr/bin/env python3
"""Show the 13 string matches and their xref results."""
import urllib.request, urllib.parse, json, re, struct
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
LOAD_BASE = 0x03000000

def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=60)
        data = resp.read().decode("utf-8")
        return data
    except Exception as e:
        return f"ERROR: {e}"

# Load the matches
result = json.loads((ROOT / "build" / "ghidra_xref_renames.json").read_text(encoding="utf-8"))
print(f"Matches: {result.get('matches')}, Renamed: {len(result.get('renamed', []))}")

# Rebuild the matches
sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))
string_to_sdk = {}
for func_name, info in sdk_index.items():
    for s in info.get("strings", []):
        if len(s) >= 6:
            string_to_sdk[s] = func_name

section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()

# Find matches
for sdk_str, sdk_func in string_to_sdk.items():
    if len(sdk_str) < 8:
        continue
    try:
        pos = section3.find(sdk_str.encode("ascii"))
    except:
        pos = -1
    if pos < 0:
        try:
            pos = section3.find(sdk_str.encode("utf-16-le"))
            if pos >= 0:
                enc = "utf16le"
            else:
                continue
        except:
            continue
    else:
        enc = "ascii"

    load_addr = LOAD_BASE + pos
    print(f"\nString: {sdk_str[:50]!r} ({enc})")
    print(f"  SDK func: {sdk_func}")
    print(f"  Load addr: 0x{load_addr:08x}")

    # Get xrefs
    xref_result = _get("/get_xrefs_to", {"address": f"0x{load_addr:08x}"})
    print(f"  Xrefs: {xref_result[:200]}")
