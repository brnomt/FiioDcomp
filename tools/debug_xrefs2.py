#!/usr/bin/env python3
"""Debug: use Ghidra's xref system to find references to string addresses."""
import urllib.request
import urllib.parse
import json
import struct
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
LOAD_BASE = 0x03000000
section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=60)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except urllib.error.HTTPError as e:
        return f"HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:200]}"
    except Exception as e:
        return str(e)


# Test with "APETAGEX" at 0x03023f78
test_addr = "0x03023f78"
print(f"=== Testing get_xrefs_to for {test_addr} (APETAGEX) ===")
result = _get("/get_xrefs_to", {"address": test_addr})
print(f"  Type: {type(result)}")
print(f"  Result: {str(result)[:500]}")

# Try with "###AUDIO_DECODE_OPEN error!###" at 0x0306ceac
test_addr2 = "0x0306ceac"
print(f"\n=== Testing get_xrefs_to for {test_addr2} (AUDIO_DECODE_OPEN error) ===")
result = _get("/get_xrefs_to", {"address": test_addr2})
print(f"  Result: {str(result)[:500]}")

# Try "vorbis" at 0x030243d0
test_addr3 = "0x030243d0"
print(f"\n=== Testing get_xrefs_to for {test_addr3} (vorbis) ===")
result = _get("/get_xrefs_to", {"address": test_addr3})
print(f"  Result: {str(result)[:500]}")

# Let's also check what the search_strings endpoint returns for these
print(f"\n=== search_strings for 'APETAGEX' ===")
result = _get("/search_strings", {"pattern": "APETAGEX"})
print(f"  Result: {str(result)[:500]}")

print(f"\n=== search_strings for 'AUDIO_DECODE' ===")
result = _get("/search_strings", {"pattern": "AUDIO_DECODE"})
print(f"  Result: {str(result)[:500]}")

# Check if the addresses are in the defined data
print(f"\n=== Checking what Ghidra has at 0x03023f78 ===")
# Try to read the memory at this address
result = _get("/get_data_at", {"address": "0x03023f78"})
print(f"  get_data_at: {str(result)[:500]}")

# Try disassemble at a known function address to verify the API works
print(f"\n=== Checking xrefs to a known function (HifiFileOpen @ 0x0306b9bc) ===")
result = _get("/get_xrefs_to", {"address": "0x0306b9bc"})
print(f"  Result: {str(result)[:500]}")

# Try get_function_xrefs
print(f"\n=== get_function_xrefs for HifiFileOpen ===")
result = _get("/get_function_xrefs", {"name": "HifiFileOpen"})
print(f"  Result: {str(result)[:500]}")
