#!/usr/bin/env python3
"""Decompile first 20 unnamed firmware functions to see patterns."""
import urllib.request, urllib.parse, json, time

BASE = "http://127.0.0.1:8089"

def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=120)
    data = resp.read().decode("utf-8")
    try:
        if data.startswith("{") or data.startswith("["): return json.loads(data)
    except: pass
    return data

resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
data = json.loads(resp.read().decode())
funcs = data.get("functions", data)

fw_unnamed = [f for f in funcs if f.get("name","").startswith("FUN_") and int(f.get("address","0"),16) >= 0x03000000]
print(f"FW unnamed: {len(fw_unnamed)}")

for i, func in enumerate(fw_unnamed[:20]):
    addr = func["address"]
    name = func["name"]
    sep = "=" * 70
    print(f"\n{sep}")
    print(f"[{i+1}/20] {name} @ {addr}")
    print(sep)

    # Get callees
    try:
        result = _get("/get_function_callees", {"address": addr})
        callees = []
        if isinstance(result, str):
            for line in result.strip().split("\n"):
                parts = line.split()
                if len(parts) >= 2:
                    callees.append(parts[0])
        elif isinstance(result, dict):
            items = result.get("callees", [])
            callees = [c.get("name","") for c in items if isinstance(c, dict)]
        if callees:
            print(f"Callees: {callees}")
    except: pass

    # Decompile
    try:
        result = _get("/decompile_function", {"address": addr})
        if isinstance(result, dict):
            code = result.get("decompilation", result.get("code", ""))
        else:
            code = str(result)
        lines = code.split("\n")
        for line in lines[:60]:
            print(line)
        if len(lines) > 60:
            print(f"  ... ({len(lines)-60} more lines)")
    except Exception as e:
        print(f"  Error: {e}")

    time.sleep(0.3)
