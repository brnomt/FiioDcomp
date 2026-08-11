#!/usr/bin/env python3
"""Check /rename_function_by_address schema and test address formats."""
import json
import urllib.request

BASE = "http://127.0.0.1:8089"

# Get schema
resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=30)
data = json.loads(resp.read().decode())
tools = data if isinstance(data, list) else data.get("tools", [])

for t in tools:
    if t.get("path") in ("/rename_function_by_address", "/rename_function", "/switch_program"):
        print(f"=== {t['path']} ({t['method']}) ===")
        for p in t.get("params", []):
            print(f"  param: {p.get('name')} ({p.get('type')}) [{p.get('source')}] req={p.get('required')}")
        print()

# Test switch program first
print("=== Switching to sec3_3_6_0.bin ===")
try:
    resp = urllib.request.urlopen(f"{BASE}/switch_program?program=sec3_3_6_0.bin", timeout=60)
    print(resp.read().decode("utf-8", errors="replace")[:300])
except Exception as e:
    print(f"ERROR: {e}")

# Test rename with different address formats
for addr_fmt in ["03009ef4", "0x03009ef4", "0309ef4"]:
    body = json.dumps({"address": addr_fmt, "new_name": "TestRename"}).encode()
    req = urllib.request.Request(
        f"{BASE}/rename_function_by_address", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        print(f"\naddr={addr_fmt}: {resp.read().decode('utf-8', errors='replace')[:300]}")
    except urllib.error.HTTPError as e:
        print(f"\naddr={addr_fmt}: HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:300]}")
    except Exception as e:
        print(f"\naddr={addr_fmt}: {e}")
