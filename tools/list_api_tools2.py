#!/usr/bin/env python3
"""List all Ghidra MCP API tools with their endpoints."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=30)
data = json.loads(resp.read().decode())
tools = data if isinstance(data, list) else data.get("tools", data.get("functions", []))
print(f"Total tools: {len(tools)}\n")

# Show keys of first tool to understand structure
if tools:
    print(f"First tool keys: {list(tools[0].keys())}")
    print(json.dumps(tools[0], indent=2)[:1500])
    print()

# Extract endpoint paths - try multiple key names
for t in tools:
    endpoint = (t.get("endpoint") or t.get("path") or t.get("url") or
                t.get("method") or t.get("route") or t.get("name"))
    name = t.get("name") or t.get("title") or t.get("function") or "?"
    desc = (t.get("description") or t.get("summary") or "")[:80]
    # Find keys that look like endpoints
    for k, v in t.items():
        if isinstance(v, str) and v.startswith("/"):
            endpoint = v
            break
    print(f"  {endpoint}: {desc}")
