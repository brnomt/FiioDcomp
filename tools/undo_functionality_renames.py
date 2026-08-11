#!/usr/bin/env python3
"""Undo the 511 incorrect functionality renames by restoring FUN_ names."""
import json, time, urllib.request

BASE = "http://127.0.0.1:8089"
matches = json.loads(open("build/functionality_matches.json", encoding="utf-8").read())

print(f"Undoing {len(matches)} renames...")
undone = 0
for m in matches:
    addr = m["binary_addr"]
    orig_name = m["binary_func"]  # e.g. FUN_03000162
    body = json.dumps({"function_address": addr, "new_name": orig_name}).encode()
    req = urllib.request.Request(f"{BASE}/rename_function_by_address", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=30)
        if b"error" not in resp.read().lower():
            undone += 1
    except:
        pass
    time.sleep(0.03)

print(f"Undone: {undone}")

# Verify
resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
data = json.loads(resp.read().decode())
funcs = data.get("functions", data)
named = sum(1 for f in funcs if not f.get("name","").startswith("FUN_") and not f.get("name","").startswith("LAB_"))
print(f"Total: {len(funcs)}, Named: {named} ({100*named/len(funcs):.1f}%)")
