#!/usr/bin/env python3
"""
match_by_size.py — Match binary functions to compiled SDK functions by size.

This is the first step of the compilation-based matching approach:
  1. Get all binary function sizes from Ghidra
  2. Match against compiled SDK function sizes
  3. For unique size matches, rename the binary function

Size alone isn't unique, but combined with other features it narrows candidates.
"""
import urllib.request, urllib.parse, json, re, time
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=120)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try: return json.loads(data)
            except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body, headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=120)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try: return json.loads(data)
            except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def get_all_functions_with_sizes():
    """Get all functions with their sizes from Ghidra."""
    # list_functions_enhanced doesn't include sizes
    # Use list_functions (text format) which includes "name at address" but not size
    # We need to get sizes separately
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def get_function_size(address):
    """Get the size of a function by decompiling it or using get_function_by_address."""
    result = _get("/get_function_by_address", {"address": address})
    if isinstance(result, dict):
        return result.get("size", result.get("body_size", 0))
    if isinstance(result, str):
        m = re.search(r'size[:\s]+(\d+)', result)
        if m:
            return int(m.group(1))
    return 0


def disassemble_function(address):
    """Get assembly of function to count instructions and extract constants."""
    result = _get("/disassemble_function", {"address": address})
    if isinstance(result, dict):
        return result.get("assembly", result.get("listing", result.get("result", "")))
    return str(result) if result else ""


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def main():
    # Load compiled SDK functions
    sdk_compiled = json.loads((ROOT / "build" / "sdk_compiled_functions.json").read_text(encoding="utf-8"))
    print(f"Compiled SDK functions: {len(sdk_compiled)}")

    # Build size -> SDK function map
    size_to_sdk = defaultdict(list)
    for name, info in sdk_compiled.items():
        size = info["size"]
        if size > 10:  # Skip tiny functions
            size_to_sdk[size].append(name)

    # Sizes with unique matches
    unique_sizes = {s: funcs[0] for s, funcs in size_to_sdk.items() if len(funcs) == 1}
    print(f"Unique size matches: {len(unique_sizes)}")
    print(f"  Size range: {min(unique_sizes.keys())}-{max(unique_sizes.keys())}")

    # Get all binary functions
    print("\nFetching binary functions from Ghidra...")
    all_funcs = get_all_functions_with_sizes()
    unnamed = [f for f in all_funcs if f.get("name", "").startswith("FUN_")]
    print(f"Unnamed functions: {len(unnamed)}")

    # Get sizes for unnamed functions by decompiling
    # Actually, let's use disassemble_function to get instruction count
    # and use the function's address range to compute size

    # First, let's try to get function sizes from the enhanced listing
    # If that doesn't have sizes, we'll use disassembly

    renamed = {}
    matched = 0
    checked = 0

    for i, func in enumerate(unnamed):
        func_addr = func.get("address", "")
        func_name = func.get("name", "")

        if i % 200 == 0:
            print(f"  Checking {i}/{len(unnamed)}...")

        # Get function size via disassembly
        asm = disassemble_function(func_addr)
        if not asm or len(asm) < 10:
            continue

        # Count instructions (rough size estimate)
        # Each Thumb-2 instruction is 2 or 4 bytes
        # Count lines in assembly output
        inst_count = asm.count("\n")
        if inst_count < 3:
            continue

        # Estimate size: ~2.5 bytes per instruction average for Thumb-2
        estimated_size = int(inst_count * 2.5)

        # Check for unique size match
        # Try exact match and near match (±2 bytes)
        for delta in [0, -2, 2, -4, 4]:
            check_size = estimated_size + delta
            if check_size in unique_sizes:
                sdk_name = unique_sizes[check_size]
                if func_addr not in renamed:
                    result = rename_function(func_addr, sdk_name)
                    if isinstance(result, dict) and "error" not in result:
                        renamed[func_addr] = sdk_name
                        matched += 1
                        if matched <= 30:
                            print(f"  {func_name} -> {sdk_name} @ {func_addr} (est_size={estimated_size}, sdk_size={check_size})")
                break

        checked += 1
        if (i + 1) % 50 == 0:
            time.sleep(0.3)

    print(f"\n=== SUMMARY ===")
    print(f"Checked: {checked}")
    print(f"Matched: {matched}")

    # Final count
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        all_funcs = result.get("functions", [])
        final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
        print(f"Total: {len(all_funcs)}, Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")

    output = ROOT / "build" / "ghidra_size_renames.json"
    output.write_text(json.dumps({"checked": checked, "matched": matched, "renamed": [{"address": k, "name": v} for k, v in renamed.items()]}, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
