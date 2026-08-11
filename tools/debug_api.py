#!/usr/bin/env python3
"""List all Ghidra tool names."""
import urllib.request, json
BASE = "http://127.0.0.1:8089"
resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=60)
schema = json.loads(resp.read())
for t in schema.get("tools", []):
    name = t.get("name", "")
    path = t.get("path", "")
    method = t.get("method", "")
    print(f"  {name:50s} {method:5s} {path}")
