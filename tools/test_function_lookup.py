#!/usr/bin/env python3
"""Test which Ghidra MCP endpoint returns the function containing an address."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"
ADDRS = ["0306fec4", "030fed5e", "0306e5de", "03023526", "03023be8"]

endpoints = [
    "/get_function_by_address",
    "/function_by_address",
    "/get_function_at",
    "/list_functions",
]

for addr in ADDRS:
    print(f"\n=== Address {addr} ===")
    for ep in endpoints:
        try:
            resp = urllib.request.urlopen(f"{BASE}{ep}?address={addr}", timeout=30)
            raw = resp.read().decode("utf-8", errors="replace")
            print(f"  {ep}: {raw[:150]}")
        except Exception as e:
            print(f"  {ep}: HTTP ERROR {e}")

# Try decompile to see function at address (decompile_function accepts address in body of func)
print("\n=== decompile_function results (function header only) ===")
for addr in ADDRS:
    try:
        resp = urllib.request.urlopen(f"{BASE}/decompile_function?address={addr}", timeout=60)
        raw = resp.read().decode("utf-8", errors="replace")
        # First line contains function signature
        first_line = raw.strip().split("\n")[0] if raw.strip() else "(empty)"
        print(f"  {addr}: {first_line}")
    except Exception as e:
        print(f"  {addr}: ERROR {e}")
