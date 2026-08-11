#!/usr/bin/env python3
"""
match_via_api.py — Use Ghidra HTTP API endpoints directly to match SDK strings
to binary functions.

Process:
  1. For each SDK string, use search_strings to find it in the binary
  2. If found, get the string's address
  3. Use get_xrefs_to to find functions referencing that string
  4. Rename FUN_* functions to the SDK function name

Also:
  5. Use get_function_callees for named functions that exist in SDK
  6. Match callees by call pattern and rename
"""
import urllib.request
import urllib.parse
import json
import re
import time
import sys
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=TIMEOUT)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return {"error": str(e)}


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    try:
        resp = urllib.request.urlopen(req, timeout=TIMEOUT)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return {"error": str(e)}


def search_strings(pattern):
    """Search for strings matching a pattern. Returns list of {address, value}."""
    result = _get("/search_strings", {"search_term": pattern})
    if isinstance(result, dict):
        strings = result.get("strings", result.get("items", result.get("results", [])))
        if isinstance(strings, list):
            return strings
    elif isinstance(result, list):
        return result
    elif isinstance(result, str):
        # Parse text format: "address: value"
        strings = []
        for line in result.strip().split("\n"):
            m = re.match(r'^([0-9a-f]+):\s*(.*)$', line)
            if m:
                strings.append({"address": m.group(1), "value": m.group(2)})
        return strings
    return []


def get_xrefs_to(address):
    """Get cross-references to an address. Returns list of {from_address, function}."""
    result = _get("/get_xrefs_to", {"address": address})
    if isinstance(result, str):
        # Parse text format: "From ADDR in FUNC [TYPE]"
        refs = []
        for line in result.strip().split("\n"):
            m = re.match(r'From\s+([0-9a-f]+)\s+in\s+(\S+)', line)
            if m:
                refs.append({"from_address": m.group(1), "function": m.group(2)})
        return refs
    elif isinstance(result, dict):
        refs = result.get("references", result.get("xrefs", []))
        if isinstance(refs, list):
            return refs
    elif isinstance(result, list):
        return result
    return []


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def get_function_by_address(address):
    """Get function info by address."""
    result = _get("/get_function_by_address", {"address": address})
    if isinstance(result, dict):
        return result
    if isinstance(result, str):
        m = re.match(r'(\w+)\s+at\s+([0-9a-f]+)', result)
        if m:
            return {"name": m.group(1), "address": m.group(2)}
    return None


def get_function_callees(address):
    """Get functions called by a function."""
    result = _get("/get_function_callees", {"address": address})
    callees = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            m = re.match(r'(\w+)\s+at\s+([0-9a-f]+)', line)
            if m:
                callees.append({"name": m.group(1), "address": m.group(2)})
    elif isinstance(result, dict):
        items = result.get("callees", result.get("functions", []))
        if isinstance(items, list):
            callees = items
    elif isinstance(result, list):
        callees = result
    return callees


def main():
    # Load SDK index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Build string -> SDK function map (only unique strings)
    string_to_sdk = {}
    ambiguous_strings = set()
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 6:
                if s in string_to_sdk:
                    ambiguous_strings.add(s)
                else:
                    string_to_sdk[s] = func_name

    # Remove ambiguous strings (used by multiple SDK functions)
    for s in ambiguous_strings:
        del string_to_sdk[s]

    print(f"SDK unique strings: {len(string_to_sdk)}")

    # Phase 1: Search for SDK strings in the binary
    renamed = {}
    found_strings = 0

    sdk_strings = sorted(string_to_sdk.keys(), key=len, reverse=True)
    print(f"\nPhase 1: Searching for {len(sdk_strings)} SDK strings in binary...")

    for i, sdk_str in enumerate(sdk_strings):
        if i % 200 == 0:
            print(f"  Searching {i}/{len(sdk_strings)}...")

        # Search for this string in the binary
        results = search_strings(sdk_str)
        if not results:
            continue

        for r in results:
            if isinstance(r, dict):
                addr = r.get("address", "")
                val = r.get("value", r.get("string", ""))
            else:
                continue

            if not addr:
                continue

            found_strings += 1
            sdk_func = string_to_sdk[sdk_str]

            # Get xrefs to this string address
            xrefs = get_xrefs_to(f"0x{addr}" if not addr.startswith("0x") else addr)
            if not xrefs:
                continue

            for xref in xrefs:
                func_name = xref.get("function", "")
                from_addr = xref.get("from_address", "")

                if func_name.startswith("FUN_"):
                    # Get the function address
                    func_info = get_function_by_address(from_addr)
                    if func_info:
                        func_addr = func_info.get("address", from_addr)
                    else:
                        func_addr = from_addr

                    if func_addr not in renamed:
                        result = rename_function(func_addr, sdk_func)
                        if isinstance(result, dict) and "error" not in result:
                            renamed[func_addr] = sdk_func
                            if len(renamed) <= 50:
                                print(f"  {func_name} -> {sdk_func} @ {func_addr} (string: {sdk_str[:40]})")

        if (i + 1) % 50 == 0:
            time.sleep(0.5)

    print(f"\nPhase 1 results: {found_strings} strings found, {len(renamed)} functions renamed")

    # Phase 2: Call-graph propagation
    print("\nPhase 2: Call-graph propagation...")

    # Get all functions
    all_funcs_result = _get("/list_functions_enhanced")
    all_funcs = all_funcs_result.get("functions", []) if isinstance(all_funcs_result, dict) else []
    named = [f for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
    print(f"  Named functions: {len(named)}")

    cg_renamed = {}
    for i, func in enumerate(named):
        func_name = func.get("name", "")
        func_addr = func.get("address", "")

        if func_name not in sdk_index:
            continue

        sdk_callees = sdk_index[func_name].get("callees", [])
        if not sdk_callees:
            continue

        if i % 50 == 0:
            print(f"  Processing {i}/{len(named)} ({func_name})...")

        # Get binary callees
        bin_callees = get_function_callees(func_addr)
        if not bin_callees:
            continue

        # Match by position if counts are close
        unnamed_callees = [c for c in bin_callees if isinstance(c, dict) and c.get("name", "").startswith("FUN_")]

        if len(bin_callees) == len(sdk_callees):
            for j, (bin_c, sdk_c) in enumerate(zip(bin_callees, sdk_callees)):
                if not isinstance(bin_c, dict):
                    continue
                bin_name = bin_c.get("name", "")
                bin_addr = bin_c.get("address", "")

                if bin_name.startswith("FUN_") and bin_addr and bin_addr not in renamed and bin_addr not in cg_renamed:
                    if sdk_c in sdk_index or (sdk_c[0].islower() and len(sdk_c) > 3):
                        result = rename_function(bin_addr, sdk_c)
                        if isinstance(result, dict) and "error" not in result:
                            cg_renamed[bin_addr] = sdk_c
                            if len(cg_renamed) <= 20:
                                print(f"    {func_name}: {bin_name} -> {sdk_c} @ {bin_addr}")

        time.sleep(0.1)

    print(f"\nPhase 2 results: {len(cg_renamed)} functions renamed via call-graph")

    # Final summary
    all_funcs_result = _get("/list_functions_enhanced")
    all_funcs = all_funcs_result.get("functions", []) if isinstance(all_funcs_result, dict) else []
    final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    final_unnamed = sum(1 for f in all_funcs if f.get("name", "").startswith("FUN_"))

    print(f"\n=== FINAL SUMMARY ===")
    print(f"Total functions: {len(all_funcs)}")
    print(f"Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")
    print(f"Unnamed: {final_unnamed}")
    print(f"String-match renames: {len(renamed)}")
    print(f"Call-graph renames: {len(cg_renamed)}")

    output = ROOT / "build" / "ghidra_auto_renames.json"
    output.write_text(json.dumps({
        "string_renames": [{"address": k, "name": v} for k, v in renamed.items()],
        "callgraph_renames": [{"address": k, "name": v} for k, v in cg_renamed.items()],
        "final_named": final_named,
        "final_unnamed": final_unnamed,
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
