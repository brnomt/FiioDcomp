#!/usr/bin/env python3
"""Debug: compare binary callees to SDK callees for known functions."""
import urllib.request
import urllib.parse
import json
import re
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=120)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct or data.startswith("{") or data.startswith("["):
        try:
            return json.loads(data)
        except:
            pass
    return data


def get_callees(address):
    result = _get("/get_function_callees", {"address": address})
    if isinstance(result, dict):
        callees = result.get("callees", result.get("functions", result.get("items", [])))
        if isinstance(callees, list):
            return callees
    elif isinstance(result, list):
        return result
    # Parse text format
    if isinstance(result, str):
        callees = []
        for line in result.strip().split("\n"):
            m = re.match(r'(\S+)\s+at\s+([0-9a-f]+)', line)
            if m:
                callees.append({"name": m.group(1), "address": m.group(2)})
            else:
                parts = line.split()
                if len(parts) >= 2:
                    callees.append({"name": parts[0], "address": parts[-1]})
        return callees
    return []


def main():
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Get all functions
    result = _get("/list_functions_enhanced")
    all_funcs = result.get("functions", []) if isinstance(result, dict) else []
    named = [f for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]

    # Find named functions that exist in the SDK
    common = [f for f in named if f["name"] in sdk_index]
    print(f"Named functions also in SDK: {len(common)}")

    # Show details for first 10
    for func in common[:10]:
        func_name = func["name"]
        func_addr = func["address"]
        sdk_callees = sdk_index[func_name].get("callees", [])
        bin_callees = get_callees(func_addr)

        print(f"\n=== {func_name} @ {func_addr} ===")
        print(f"  SDK callees ({len(sdk_callees)}): {sdk_callees[:10]}")
        print(f"  Binary callees ({len(bin_callees)}):")
        for c in bin_callees[:15]:
            if isinstance(c, dict):
                print(f"    {c.get('name','?'):40s} @ {c.get('address','?')}")
            else:
                print(f"    {c}")

        # Check for matching patterns
        bin_callee_names = [c.get("name", "") for c in bin_callees if isinstance(c, dict)]
        sdk_in_bin = [s for s in sdk_callees if s in bin_callee_names]
        print(f"  SDK callees found in binary: {sdk_in_bin}")


if __name__ == "__main__":
    main()
