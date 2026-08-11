#!/usr/bin/env python3
"""
decompile_all.py — Decompile ALL unnamed functions in Ghidra and save to JSON.
We currently have 1,413 decompiled; need ~1,300 more.
"""
import json, time, urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "build" / "all_decompilations.json"

# Load existing decompilations
existing = json.loads(OUTPUT.read_text(encoding="utf-8"))
print(f"Existing decompilations: {len(existing)}")

# Get all functions
resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
data = json.loads(resp.read().decode())
all_funcs = data.get("functions", data)
print(f"Total functions: {len(all_funcs)}")

# Find unnamed functions not yet decompiled
to_decompile = []
for f in all_funcs:
    name = f.get("name", "")
    addr = f.get("address", "")
    if name.startswith("FUN_") and f"FUN_{addr}" not in existing:
        to_decompile.append(f)

print(f"Functions to decompile: {len(to_decompile)}")

# Decompile in batches
batch_size = 50
total = len(to_decompile)
done = 0
errors = 0

for i in range(0, total, batch_size):
    batch = to_decompile[i:i+batch_size]
    for f in batch:
        addr = f["address"]
        name = f["name"]
        try:
            resp = urllib.request.urlopen(
                f"{BASE}/decompile_function?address={addr}", timeout=30)
            code = resp.read().decode("utf-8", errors="ignore")
            if code and len(code) > 20:
                existing[name] = {"address": addr, "code": code}
                done += 1
            else:
                errors += 1
        except Exception as e:
            errors += 1
        time.sleep(0.02)

    # Save progress every batch
    OUTPUT.write_text(json.dumps(existing, ensure_ascii=False), encoding="utf-8")
    print(f"  Progress: {done}/{total} decompiled ({errors} errors)", flush=True)

print(f"\nDone: {done} new decompilations, {errors} errors")
print(f"Total decompilations: {len(existing)}")
