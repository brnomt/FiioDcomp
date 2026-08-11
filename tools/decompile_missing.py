#!/usr/bin/env python3
"""
Find functions missing from all_decompilations.json and decompile them.
Then run matching to name more functions.
"""
import json
import time
import urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
DECOMP_FILE = BUILD / "all_decompilations.json"

def api_get(endpoint, params=None, timeout=60):
    url = f"{BASE}{endpoint}"
    if params:
        from urllib.parse import urlencode
        url += "?" + urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    raw = resp.read().decode("utf-8", errors="replace")
    if not raw.strip():
        return {}
    return json.loads(raw)

def api_post(endpoint, data, timeout=60):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    resp = urllib.request.urlopen(req, timeout=timeout)
    raw = resp.read().decode("utf-8", errors="replace")
    if not raw.strip():
        return {}
    return json.loads(raw)

# ============================================================
# Step 1: Find missing functions
# ============================================================
print("=" * 60)
print("STEP 1: Identify missing functions")
print("=" * 60)

# Load existing decompilations
existing = {}
if DECOMP_FILE.exists():
    existing = json.loads(DECOMP_FILE.read_text(encoding="utf-8"))
print(f"Existing decompilations: {len(existing)}")

# Get all functions from Ghidra
print("Fetching functions from Ghidra...")
all_funcs_raw = api_get("/list_functions_enhanced", timeout=120)
all_funcs = all_funcs_raw.get("functions", all_funcs_raw) if isinstance(all_funcs_raw, dict) else all_funcs_raw
print(f"Total functions in Ghidra: {len(all_funcs)}")

# Find missing: functions in Ghidra but not in our decompilations
missing = []
for f in all_funcs:
    name = f.get("name", "")
    addr = f.get("address", "")
    # Check if this function is already decompiled
    # Key in existing is the name (e.g. "FUN_03000162")
    if name not in existing and f"FUN_{addr}" not in existing:
        missing.append(f)

print(f"Missing functions: {len(missing)}")

# ============================================================
# Step 2: Decompile missing functions
# ============================================================
print("\n" + "=" * 60)
print("STEP 2: Decompile missing functions")
print("=" * 60)

if missing:
    print(f"Decompiling {len(missing)} missing functions...")
    done = 0
    errors = 0
    
    for i, f in enumerate(missing):
        name = f.get("name", "")
        addr = f.get("address", "")
        
        try:
            url = f"{BASE}/decompile_function?address={addr}"
            resp = urllib.request.urlopen(url, timeout=60)
            code = resp.read().decode("utf-8", errors="replace").strip()
            
            # API returns raw C code as plain text
            if code and len(code) > 10 and "{" in code:
                existing[name] = {"address": addr, "code": code}
                done += 1
            else:
                errors += 1
        except Exception as e:
            errors += 1
        
        # Progress update every 10
        if (i + 1) % 10 == 0:
            print(f"  Progress: {i+1}/{len(missing)} (done={done}, errors={errors})")
        
        time.sleep(0.05)  # Rate limit
    
    print(f"\n  Final: {done} new decompilations, {errors} errors")
    
    # Save updated decompilations
    DECOMP_FILE.write_text(
        json.dumps(existing, ensure_ascii=False, indent=2),
        encoding="utf-8"
    )
    print(f"  Saved to {DECOMP_FILE}")
else:
    print("No missing functions found!")

print(f"\nTotal decompilations now: {len(existing)}")
