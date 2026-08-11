#!/usr/bin/env python3
"""Test Ghidra MCP JSON-RPC over HTTP."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

# Try MCP JSON-RPC style
for method in ["tools/list", "tools/call"]:
    payload = json.dumps({"jsonrpc": "2.0", "method": method, "id": 1, "params": {}}).encode()
    req = urllib.request.Request(f"{BASE}/mcp", data=payload, headers={"Content-Type": "application/json"})
    try:
        resp = urllib.request.urlopen(req)
        data = resp.read()
        print(f"{method}: {len(data)} bytes")
        print(data[:500].decode('utf-8', errors='replace'))
    except Exception as e:
        print(f"{method}: {e}")

# Try SSE-style
try:
    req = urllib.request.Request(f"{BASE}/sse")
    resp = urllib.request.urlopen(req)
    print(f"\nSSE: {resp.status}")
except Exception as e:
    print(f"\nSSE: {e}")

# Try direct endpoints
for path in ["/", "/health", "/status", "/mcp/sse"]:
    try:
        resp = urllib.request.urlopen(f"{BASE}{path}")
        print(f"\n{path}: {resp.status} - {resp.read()[:200]}")
    except Exception as e:
        print(f"\n{path}: {e}")
