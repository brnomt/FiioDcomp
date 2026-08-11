#!/usr/bin/env python3
"""Direct Ghidra HTTP API client — bypasses the MCP bridge."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

def api_get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        from urllib.parse import urlencode
        url += "?" + urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=60)
        return json.loads(resp.read().decode("utf-8"))
    except Exception as e:
        return {"error": str(e)}

# Fetch raw schema
schema = api_get("/mcp/schema")
if "error" in schema:
    print(f"Schema error: {schema['error']}")
else:
    # Print the raw structure of the first few entries
    if isinstance(schema, list):
        print(f"Schema is a list of {len(schema)} items")
        print("\nFirst item:")
        print(json.dumps(schema[0], indent=2)[:500])
    elif isinstance(schema, dict):
        print(f"Schema is a dict with keys: {list(schema.keys())}")
        for k, v in schema.items():
            if isinstance(v, list):
                print(f"\n{k}: list of {len(v)} items")
                if v:
                    print(json.dumps(v[0], indent=2)[:500])
            else:
                print(f"\n{k}: {str(v)[:200]}")
