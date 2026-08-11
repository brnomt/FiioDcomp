#!/usr/bin/env python3
"""Find rename/create function endpoints in the schema."""
import urllib.request, json

resp = urllib.request.urlopen("http://127.0.0.1:8089/mcp/schema", timeout=15)
data = json.loads(resp.read().decode())
tools = data.get("tools", [])
for t in tools:
    path = t.get("path", "")
    if "rename" in path or "create_function" in path or "create_func" in path:
        method = t.get("method", "")
        desc = t.get("description", "")[:100]
        print(f"Path: {path}")
        print(f"  Method: {method}")
        print(f"  Desc: {desc}")
        for p in t.get("params", []):
            req = "REQUIRED" if p.get("required") else "optional"
            pname = p["name"]
            ptype = p.get("type", "?")
            pdesc = p.get("description", "")[:60]
            print(f"  Param: {pname} ({ptype}) [{req}] - {pdesc}")
        print()
