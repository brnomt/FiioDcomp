#!/usr/bin/env python3
"""
match_callees.py — Match unnamed functions by their callee sets.

Strategy:
  1. For each SDK function, get its set of callees (function names it calls)
  2. For each binary function, get its set of callees
  3. Match by overlap: if a binary FUN_* calls {HifiFileRead, ipc_post_cmd, ...}
     and an SDK function calls {HifiFileRead, MailBoxWriteB2ACmd, ...},
     and the known callees overlap, it's a match.
  4. Also use function size as a tiebreaker.

This works because many utility functions call the same set of known functions
even if they don't have strings.
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


def get_all_functions():
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def get_callees(address):
    result = _get("/get_function_callees", {"address": address})
    callees = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            m = re.match(r'(\S+)\s+at\s+([0-9a-f]+)', line)
            if m:
                callees.append({"name": m.group(1), "address": m.group(2)})
            else:
                parts = line.split()
                if len(parts) >= 2:
                    callees.append({"name": parts[0], "address": parts[-1]})
    elif isinstance(result, dict):
        items = result.get("callees", result.get("functions", []))
        if isinstance(items, list):
            callees = items
    elif isinstance(result, list):
        callees = result
    return callees


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def main():
    # Load combined SDK index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index_combined.json").read_text(encoding="utf-8"))
    print(f"SDK functions: {len(sdk_index)}")

    # Build SDK callee sets (only for functions with callees)
    sdk_callee_sets = {}
    for func_name, info in sdk_index.items():
        callees = info.get("callees", [])
        if callees:
            sdk_callee_sets[func_name] = set(callees)
    print(f"SDK functions with callees: {len(sdk_callee_sets)}")

    # Get all binary functions
    print("Fetching binary functions...")
    all_funcs = get_all_functions()
    named = [f for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
    unnamed = [f for f in all_funcs if f.get("name", "").startswith("FUN_")]
    print(f"Named: {len(named)}, Unnamed: {len(unnamed)}")

    # Get callee sets for all named binary functions (to build a name mapping)
    print("\nGetting callee sets for named binary functions...")
    binary_named_callees = {}
    for i, func in enumerate(named):
        if i % 50 == 0:
            print(f"  {i}/{len(named)}...")
        callees = get_callees(func["address"])
        callee_names = set(c.get("name", "") for c in callees if isinstance(c, dict))
        binary_named_callees[func["name"]] = callee_names
        time.sleep(0.05)

    # Build SDK→binary function name mapping based on callee overlap
    # If SDK function "Foo" calls {A, B, C} and binary function "Foo" calls {A, B, D},
    # and A, B are known in both, then the mapping is consistent
    name_mapping = {}  # sdk_name -> binary_name
    for bin_name, bin_callees in binary_named_callees.items():
        if bin_name in sdk_callee_sets:
            # Direct name match
            name_mapping[bin_name] = bin_name

    print(f"Direct name matches: {len(name_mapping)}")

    # Now match unnamed functions by callee set overlap
    print("\nMatching unnamed functions by callee sets...")
    renamed = {}

    for i, func in enumerate(unnamed):
        func_addr = func["address"]
        func_name = func["name"]

        if i % 200 == 0:
            print(f"  {i}/{len(unnamed)}...")

        # Get binary callees
        callees = get_callees(func_addr)
        if not callees:
            continue

        bin_callee_names = set(c.get("name", "") for c in callees if isinstance(c, dict))
        # Only keep known (named) callees for matching
        known_callees = {c for c in bin_callee_names if not c.startswith("FUN_") and not c.startswith("LAB_")}
        if not known_callees:
            continue

        # Match against SDK functions
        best_match = None
        best_score = 0
        for sdk_name, sdk_callees in sdk_callee_sets.items():
            # Count how many of the binary's known callees are in the SDK callee set
            overlap = known_callees & sdk_callees
            score = len(overlap)
            if score > best_score and score >= 2:
                best_score = score
                best_match = sdk_name

        if best_match and best_score >= 2:
            result = rename_function(func_addr, best_match)
            if isinstance(result, dict) and "error" not in result:
                renamed[func_addr] = best_match
                if len(renamed) <= 30:
                    print(f"  {func_name} -> {best_match} @ {func_addr} (score: {best_score}, callees: {known_callees})")

        time.sleep(0.05)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by callee-set matching: {len(renamed)}")

    # Final count
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        all_funcs = result.get("functions", [])
        final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
        print(f"Total: {len(all_funcs)}, Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")

    output = ROOT / "build" / "ghidra_callee_renames.json"
    output.write_text(json.dumps({"renamed": [{"address": k, "name": v} for k, v in renamed.items()]}, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
