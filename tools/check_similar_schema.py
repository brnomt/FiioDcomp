#!/usr/bin/env python3
"""Check find_similar_functions schema."""
import urllib.request, json

resp = urllib.request.urlopen("http://127.0.0.1:8089/mcp/schema", timeout=15)
data = json.loads(resp.read().decode())
tools = data.get("tools", [])
for t in tools:
    path = t.get("path", "")
    if "find_similar" in path or "similar" in path:
        desc = t.get("description", "")[:100]
        print(f"{path}: {desc}")
        for p in t.get("params", []):
            req = "REQ" if p.get("required") else "opt"
            pname = p["name"]
            ptype = p.get("type", "?")
            pdesc = p.get("description", "")[:80]
            print(f"  {pname} ({ptype}) [{req}] - {pdesc}")
        print()
