#!/usr/bin/env python3
"""Find function-related endpoints."""
import urllib.request, json

resp = urllib.request.urlopen("http://127.0.0.1:8089/mcp/schema", timeout=15)
data = json.loads(resp.read().decode())
tools = data.get("tools", [])
for t in tools:
    path = t.get("path", "")
    if "function" in path.lower():
        desc = t.get("description", "")[:60]
        print(f"{path}: {desc}")
