#!/usr/bin/env python3
"""Test script execution in Ghidra."""
import urllib.request, json

BASE = "http://127.0.0.1:8089"
code = 'println("Hello from Ghidra!"); println("Functions: " + currentProgram.getFunctionManager().getFunctionCount());'
body = json.dumps({"code": code}).encode("utf-8")
req = urllib.request.Request(
    f"{BASE}/run_script_inline", data=body,
    headers={"Content-Type": "application/json"}, method="POST"
)
try:
    resp = urllib.request.urlopen(req, timeout=60)
    print(resp.read().decode("utf-8")[:500])
except urllib.error.HTTPError as e:
    print(f"HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:300]}")
except Exception as e:
    print(f"ERROR: {e}")
