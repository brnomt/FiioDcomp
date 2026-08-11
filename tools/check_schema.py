#!/usr/bin/env python3
"""Check API schema for rename/create function tools."""
import urllib.request, json

resp = urllib.request.urlopen("http://127.0.0.1:8089/mcp/schema", timeout=15)
data = json.loads(resp.read().decode())
tools = data if isinstance(data, list) else data.get("tools", [])
print(f"Tools: {len(tools)}")
for t in tools:
    name = t.get("name", "")
    if "rename" in name.lower() or "create" in name.lower() or "function" in name.lower():
        desc = t.get("description", "")[:80]
        print(f"  {name}: {desc}")
        schema = t.get("inputSchema", t.get("schema", {}))
        if schema:
            props = schema.get("properties", {})
            for k, v in props.items():
                ptype = v.get("type", "?")
                pdesc = v.get("description", "")[:60]
                print(f"    param: {k} ({ptype}) - {pdesc}")
