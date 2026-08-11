#!/usr/bin/env python3
"""
propagate_names2.py — Get full call graph, find name matches, propagate.
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
        resp = urllib.request.urlopen(url, timeout=300)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=120)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def main():
    # Step 1: Get all named functions
    print("Getting all functions...")
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data

    named_funcs = {}  # name -> address
    unnamed_funcs = {}  # name -> address
    for f in all_funcs:
        name = f.get("name", "")
        addr = f.get("address", "")
        if name.startswith("FUN_") or name.startswith("LAB_"):
            unnamed_funcs[name] = addr
        else:
            named_funcs[name] = addr

    print(f"Named: {len(named_funcs)}, Unnamed: {len(unnamed_funcs)}")

    # Step 2: Load SDK function index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index_combined.json").read_text(encoding="utf-8"))
    sdk_names = set(sdk_index.keys())
    print(f"SDK functions: {len(sdk_names)}")

    # Step 3: Find direct name matches
    direct_matches = set(named_funcs.keys()) & sdk_names
    print(f"\nDirect name matches: {len(direct_matches)}")
    for m in sorted(direct_matches):
        print(f"  {m} @ {named_funcs[m]}")

    # Step 4: Get full call graph
    print("\nGetting full call graph...")
    cg_text = _get("/get_full_call_graph", {"format": "text", "limit": 100000})
    if cg_text.startswith("ERROR"):
        print(f"Error: {cg_text}")
        return 1

    # Parse: "caller_name@caller_addr -> callee_name@callee_addr"
    binary_graph = defaultdict(list)  # caller_name -> [(callee_name, callee_addr)]
    all_callee_names = set()
    for line in cg_text.strip().split("\n"):
        m = re.match(r'(\S+)@(\S+)\s*->\s*(\S+)@(\S+)', line)
        if m:
            caller_name = m.group(1)
            caller_addr = m.group(2)
            callee_name = m.group(3)
            callee_addr = m.group(4)
            binary_graph[caller_name].append((callee_name, callee_addr))
            all_callee_names.add(callee_name)

    print(f"Call graph: {len(binary_graph)} callers, {len(all_callee_names)} unique callees")

    # Step 5: Build name mapping from callee overlap
    # For each direct match, map binary callees to SDK callees
    name_mapping = {}  # binary_name -> sdk_name
    for match in direct_matches:
        name_mapping[match] = match

    # SDK callee sets for matched functions
    sdk_callee_sets = {}
    for match in direct_matches:
        sdk_callees = sdk_index.get(match, {}).get("callees", [])
        if sdk_callees:
            sdk_callee_sets[match] = sdk_callees

    # For each direct match, try to map callees by name
    for match in direct_matches:
        bin_callees = binary_graph.get(match, [])
        sdk_callees = sdk_callee_sets.get(match, [])

        # Direct name matches in callees
        bin_callee_names = [c[0] for c in bin_callees]
        for bc_name, bc_addr in bin_callees:
            if bc_name in sdk_callees:
                name_mapping[bc_name] = bc_name

    print(f"Name mapping after callee name matches: {len(name_mapping)}")

    # Step 6: Positional matching for unmatched callees
    new_mappings = {}
    for match in direct_matches:
        bin_callees = [(c[0], c[1]) for c in binary_graph.get(match, []) if c[0] not in name_mapping]
        sdk_callees = [c for c in sdk_callee_sets.get(match, []) if c not in name_mapping.values()]

        if len(bin_callees) == len(sdk_callees) and 1 <= len(bin_callees) <= 3:
            for (bc_name, bc_addr), sc_name in zip(bin_callees, sdk_callees):
                if bc_name.startswith("FUN_") and bc_name not in new_mappings:
                    new_mappings[bc_name] = (sc_name, bc_addr)

    print(f"New mappings from positional matching: {len(new_mappings)}")

    # Step 7: Rename functions
    print("\nRenaming functions...")
    renamed = 0
    for bin_name, mapping in new_mappings.items():
        if isinstance(mapping, tuple):
            sdk_name, addr = mapping
        else:
            sdk_name = mapping
            addr = unnamed_funcs.get(bin_name, "")

        if addr:
            result = rename_function(addr, sdk_name)
            if "error" not in result.lower():
                renamed += 1
                if renamed <= 30:
                    print(f"  {bin_name} -> {sdk_name} @ {addr}")
            time.sleep(0.05)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
