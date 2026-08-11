#!/usr/bin/env python3
"""List all Ghidra MCP API tools from schema."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

try:
    resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=30)
    data = json.loads(resp.read().decode())
    tools = data if isinstance(data, list) else data.get("tools", data.get("functions", []))
    print(f"Total tools: {len(tools)}\n")
    for t in tools:
        name = t.get("name", t.get("title", "?"))
        desc = t.get("description", t.get("summary", ""))[:100]
        print(f"  {name}: {desc}")
except Exception as e:
    print(f"Schema error: {e}")
    # Try listing from common endpoints
    for ep in ["/tools", "/api", "/list_tools"]:
        try:
            resp = urllib.request.urlopen(f"{BASE}{ep}", timeout=10)
            print(f"{ep}: {resp.read().decode('utf-8', errors='replace')[:500]}")
        except Exception as e2:
            print(f"{ep}: {e2}")
