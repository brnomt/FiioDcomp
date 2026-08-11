#!/usr/bin/env python3
"""
propagate_similar_v2.py — Use Ghidra's find_similar_functions to find
structurally similar functions and propagate names from named to unnamed.
Run multiple times with different thresholds.
"""
import json, time, urllib.request
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=120)
    return resp.read().decode("utf-8", errors="ignore")

def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        return urllib.request.urlopen(req, timeout=30).read().decode()
    except Exception as e:
        return f"ERROR: {e}"

def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def main():
    # Get all functions
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)

    named = [(f["address"], f["name"]) for f in all_funcs
             if not f["name"].startswith("FUN_") and not f["name"].startswith("LAB_")]
    unnamed = [(f["address"], f["name"]) for f in all_funcs
               if f["name"].startswith("FUN_")]
    print(f"Named: {len(named)}, Unnamed: {len(unnamed)}")

    total_renamed = 0

    # Try multiple thresholds
    for threshold in [0.95, 0.90, 0.85, 0.80]:
        print(f"\n--- Threshold: {threshold} ---")
        renamed_this_round = 0

        for addr, name in named[:200]:  # Use first 200 named as seeds
            try:
                result = _get("/find_similar_functions", {"address": addr, "threshold": str(threshold)})
                # Parse response
                try:
                    matches = json.loads(result)
                    if isinstance(matches, dict):
                        matches = matches.get("similar_functions", matches.get("functions", []))
                except:
                    # Try plain text
                    matches = []
                    for line in result.strip().split("\n"):
                        line = line.strip()
                        if line and "FUN_" in line:
                            parts = line.split()
                            for p in parts:
                                if p.startswith("0") and len(p) >= 8:
                                    matches.append({"address": p, "name": "FUN_" + p})

                for m in matches:
                    m_addr = m.get("address", "")
                    m_name = m.get("name", "")
                    if m_addr and m_name.startswith("FUN_"):
                        # Rename to the seed function's name + "_similar"
                        new_name = f"{name}_sim"
                        result = rename_function(m_addr, new_name)
                        if "error" not in result.lower():
                            renamed_this_round += 1
                            total_renamed += 1
                            print(f"  {m_addr} -> {new_name}")
                        time.sleep(0.03)
            except Exception as e:
                pass

        print(f"  Renamed this round: {renamed_this_round}")

    print(f"\n=== SIMILARITY MATCHING SUMMARY ===")
    print(f"Total functions renamed: {total_renamed}")

    # Final count
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named_count = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named_count} ({100*named_count/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
