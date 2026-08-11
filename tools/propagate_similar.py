#!/usr/bin/env python3
"""
propagate_similar.py — For each named function, find similar unnamed functions
and propagate the name. Only propagate for very high similarity (>0.95).
"""
import urllib.request, urllib.parse, json, re, time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=120)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def main():
    # Get all functions
    print("Getting all functions...")
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data

    named = [(f["name"], f["address"]) for f in all_funcs
             if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
    print(f"Named functions: {len(named)}")

    # For each named function, find similar unnamed functions
    print("\nFinding similar functions for each named function...")
    renamed = 0
    threshold = 0.90  # Lower threshold for more matches

    for i, (func_name, func_addr) in enumerate(named):
        if i % 20 == 0:
            print(f"  [{i}/{len(named)}] Processing {func_name}...")

        result = _get("/find_similar_functions", {"target_function": func_name, "threshold": threshold})
        if result.startswith("ERROR"):
            continue

        try:
            data = json.loads(result)
        except:
            continue

        similar = data.get("similar_functions", [])
        for sim_func in similar:
            sim_name = sim_func.get("name", "")
            sim_addr = sim_func.get("address", "")
            similarity = sim_func.get("similarity", 0)

            if sim_name.startswith("FUN_") and similarity >= threshold:
                # This unnamed function is very similar to a named function
                # Rename it (add suffix to avoid conflicts)
                new_name = f"{func_name}_copy"
                result = rename_function(sim_addr, new_name)
                if "error" not in result.lower():
                    renamed += 1
                    print(f"  RENAMED: {sim_name} -> {new_name} @ {sim_addr} (similarity: {similarity})")

        time.sleep(0.2)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by similarity: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named_count = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named_count} ({100*named_count/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
