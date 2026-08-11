#!/usr/bin/env python3
"""
callgraph_propagate.py — Propagate function names via call graph matching.

Strategy:
  1. Get all named functions from Ghidra (154 currently)
  2. For each named function, get its callees from Ghidra
  3. Look up the same function in the SDK source
  4. Get the SDK function's callees
  5. Match binary callees to SDK callees by position
  6. Name the matched callees

This is the most powerful approach because:
  - The SDK and binary share the same framework code
  - Call patterns are preserved across versions
  - Even if strings differ, the call structure is the same
"""
import urllib.request
import urllib.parse
import json
import re
import sys
import time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=TIMEOUT)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct or data.startswith("{") or data.startswith("["):
        try:
            return json.loads(data)
        except:
            pass
    return data


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    resp = urllib.request.urlopen(req, timeout=TIMEOUT)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct or data.startswith("{") or data.startswith("["):
        try:
            return json.loads(data)
        except:
            pass
    return data


def get_all_functions():
    """Get all functions. Returns list of {address, name, isThunk, isExternal}."""
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def get_callees(address):
    """Get functions called by a function. Returns list of {address, name}."""
    result = _get("/get_function_callees", {"address": address})
    if isinstance(result, dict):
        callees = result.get("callees", result.get("functions", result.get("items", [])))
        if isinstance(callees, list):
            return callees
    elif isinstance(result, list):
        return result
    return []


def rename_function(address, new_name):
    """Rename function at address."""
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def main():
    # Load SDK function index
    sdk_index_path = ROOT / "build" / "sdk_function_index.json"
    if not sdk_index_path.is_file():
        print("ERROR: sdk_function_index.json not found. Run build_sdk_index.py first.")
        return 1

    sdk_index = json.loads(sdk_index_path.read_text(encoding="utf-8"))
    print(f"SDK functions: {len(sdk_index)}")

    # Get all functions from Ghidra
    print("Fetching functions from Ghidra...")
    all_funcs = get_all_functions()
    print(f"Total functions: {len(all_funcs)}")

    # Separate named and unnamed
    named = [f for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
    unnamed = [f for f in all_funcs if f.get("name", "").startswith("FUN_")]
    print(f"Named: {len(named)}, Unnamed: {len(unnamed)}")

    # For each named function that exists in the SDK, get its callees
    # and match them to SDK callees
    renamed = {}
    rounds = 0
    max_rounds = 3

    while rounds < max_rounds:
        rounds += 1
        print(f"\n=== Round {rounds} ===")

        # Re-fetch functions to get current state
        all_funcs = get_all_functions()
        named = [f for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
        print(f"Named: {len(named)}")

        new_renames = 0
        for i, func in enumerate(named):
            func_name = func.get("name", "")
            func_addr = func.get("address", "")

            if i % 50 == 0:
                print(f"  Processing {i}/{len(named)} ({func_name})...")

            # Look up this function in the SDK
            if func_name not in sdk_index:
                continue

            sdk_callees = sdk_index[func_name].get("callees", [])
            if not sdk_callees:
                continue

            # Get binary callees
            bin_callees = get_callees(func_addr)
            if not bin_callees:
                continue

            # Match by position: if binary has N unnamed callees and SDK has N callees
            # with the same number of named ones at the same positions, match them
            unnamed_callees = [c for c in bin_callees if isinstance(c, dict) and c.get("name", "").startswith("FUN_")]
            named_callees = [c for c in bin_callees if isinstance(c, dict) and not c.get("name", "").startswith("FUN_")]

            # Simple matching: if the number of unnamed callees matches the number of
            # SDK callees that aren't already named in the binary, match by position
            # This is a heuristic — not perfect but good for many cases

            # Better approach: match SDK callees to binary callees 1:1 by position
            # Only rename if there's a clear positional match
            if len(bin_callees) == len(sdk_callees):
                for j, (bin_c, sdk_c) in enumerate(zip(bin_callees, sdk_callees)):
                    if not isinstance(bin_c, dict):
                        continue
                    bin_c_name = bin_c.get("name", "")
                    bin_c_addr = bin_c.get("address", "")

                    if bin_c_name.startswith("FUN_") and bin_c_addr not in renamed:
                        # Check if this SDK callee is also in the SDK (not a C library function)
                        if sdk_c in sdk_index or not sdk_c[0].isupper():
                            # Rename
                            result = rename_function(bin_c_addr, sdk_c)
                            if isinstance(result, dict) and "error" not in result:
                                renamed[bin_c_addr] = sdk_c
                                new_renames += 1
                                if new_renames <= 20:
                                    print(f"    {func_name}: {bin_c_name} -> {sdk_c} @ {bin_c_addr}")

            # Rate limit
            if (i + 1) % 20 == 0:
                time.sleep(0.5)

        print(f"Round {rounds}: {new_renames} new renames (total: {len(renamed)})")

        if new_renames == 0:
            break

    # Final count
    all_funcs = get_all_functions()
    final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    final_unnamed = sum(1 for f in all_funcs if f.get("name", "").startswith("FUN_"))
    print(f"\n=== Final ===")
    print(f"Total: {len(all_funcs)}")
    print(f"Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")
    print(f"Unnamed: {final_unnamed}")

    # Save results
    output = ROOT / "build" / "ghidra_callgraph_renames.json"
    output.write_text(json.dumps(renamed, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
