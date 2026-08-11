#!/usr/bin/env python3
"""Debug: find correct endpoints and string addresses."""
import urllib.request
import urllib.parse
import json
import struct
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
LOAD_BASE = 0x03000000


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=60)
        ct = resp.headers.get("Content-Type", "")
        data = resp.read().decode("utf-8")
        if "json" in ct or data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except urllib.error.HTTPError as e:
        return f"HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:200]}"
    except Exception as e:
        return str(e)


# Load section3
section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()

# Find "Play All Album" without null terminator
test_string = b"Play All Album"
test_offset = section3.find(test_string)
print(f"String 'Play All Album' at section3 offset 0x{test_offset:x}, load addr 0x{LOAD_BASE + test_offset:08x}")

# Search for this load address as a 32-bit immediate
test_load_addr = LOAD_BASE + test_offset
needle = struct.pack("<I", test_load_addr)
refs = []
idx = 0
while True:
    pos = section3.find(needle, idx)
    if pos < 0:
        break
    refs.append(pos)
    idx = pos + 1
print(f"32-bit refs to 0x{test_load_addr:08x}: {len(refs)}")
for r in refs[:5]:
    print(f"  ref at section3 offset 0x{r:x} (load 0x{LOAD_BASE + r:08x})")

# Now try get_xrefs_to with the correct address
print("\n--- get_xrefs_to ---")
addr_str = f"0x{test_load_addr:08x}"
result = _get("/get_xrefs_to", {"address": addr_str})
print(f"  Result: {str(result)[:500]}")

# Try get_xrefs_from for a known code address
print("\n--- get_xrefs_from ---")
result = _get("/get_xrefs_from", {"address": "0x0306b9bc"})
print(f"  Result: {str(result)[:500]}")

# Find the correct endpoint for "function containing"
print("\n--- Searching for function endpoints ---")
schema = _get("/mcp/schema")
if isinstance(schema, dict):
    tools = schema.get("tools", [])
    for t in tools:
        name = t.get("name", "")
        path = t.get("path", "")
        if "function" in name.lower() and ("contain" in name.lower() or "at" in name.lower() or "get" in name.lower()):
            print(f"  {name:45s} {t.get('method','GET')} {path}")
        if "xref" in name.lower():
            print(f"  {name:45s} {t.get('method','GET')} {path}")
