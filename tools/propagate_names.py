#!/usr/bin/env python3
"""
propagate_names.py — Get the full call graph from Ghidra, build a name mapping
between SDK and binary functions, and propagate names through the call graph.

Strategy:
  1. Get full call graph from Ghidra (all functions and their callees)
  2. Load SDK function index (function names and their callees)
  3. Find direct name matches between binary and SDK
  4. For each direct match, map the binary callees to SDK callees
  5. Propagate: if binary function A matches SDK function B, and A calls C,
     then C matches whatever B calls (by position or by name)
  6. Rename matched functions
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
        data = resp.read().decode("utf-8")
        try:
            if data.startswith("{") or data.startswith("["): return json.loads(data)
        except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=120)
        data = resp.read().decode("utf-8")
        try:
            if data.startswith("{") or data.startswith("["): return json.loads(data)
        except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def main():
    # Step 1: Get full call graph from Ghidra
    print("Getting full call graph from Ghidra...")
    result = _get("/get_full_call_graph", {"format": "json", "limit": 50000})
    if isinstance(result, dict) and "error" in result:
        print(f"Error: {result['error']}")
        return 1

    # Parse the call graph
    binary_graph = {}  # function_name -> {address, callees: [(name, addr)]}
    if isinstance(result, dict):
        nodes = result.get("nodes", result.get("functions", []))
        edges = result.get("edges", result.get("calls", []))
        print(f"  Nodes: {len(nodes)}, Edges: {len(edges)}")

        # Build adjacency list
        callee_map = defaultdict(list)
        for edge in edges:
            if isinstance(edge, dict):
                src = edge.get("source", edge.get("from", edge.get("caller", "")))
                dst = edge.get("target", edge.get("to", edge.get("callee", "")))
                if src and dst:
                    callee_map[src].append(dst)
            elif isinstance(edge, list) and len(edge) >= 2:
                callee_map[edge[0]].append(edge[1])

        for node in nodes:
            if isinstance(node, dict):
                name = node.get("name", node.get("label", ""))
                addr = node.get("address", node.get("id", ""))
                if name:
                    binary_graph[name] = {
                        "address": addr,
                        "callees": callee_map.get(name, []),
                    }
    elif isinstance(result, str):
        # Parse text format
        for line in result.strip().split("\n"):
            parts = line.split()
            if len(parts) >= 2:
                caller = parts[0]
                callee = parts[1]
                if caller not in binary_graph:
                    binary_graph[caller] = {"address": "", "callees": []}
                binary_graph[caller]["callees"].append(callee)

    print(f"Binary functions in graph: {len(binary_graph)}")

    # Step 2: Load SDK function index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index_combined.json").read_text(encoding="utf-8"))
    sdk_graph = {}
    for func_name, info in sdk_index.items():
        callees = info.get("callees", [])
        if callees:
            sdk_graph[func_name] = set(callees)
    print(f"SDK functions with callees: {len(sdk_graph)}")

    # Step 3: Find direct name matches
    direct_matches = set(binary_graph.keys()) & set(sdk_graph.keys())
    print(f"Direct name matches: {len(direct_matches)}")
    for m in sorted(direct_matches):
        print(f"  {m}")

    # Step 4: Build name mapping from callee overlap
    # For each direct match, the binary callees should map to SDK callees
    name_mapping = {}  # binary_name -> sdk_name
    for match in direct_matches:
        name_mapping[match] = match

    # For each direct match, try to map callees by name
    for match in direct_matches:
        bin_callees = binary_graph[match]["callees"]
        sdk_callees = sdk_graph.get(match, set())

        # Direct name matches in callees
        for bc in bin_callees:
            if bc in sdk_callees:
                name_mapping[bc] = bc

    print(f"Name mapping after direct matches: {len(name_mapping)}")

    # Step 5: Propagate through call graph
    # For each direct match, if binary function calls X and SDK function calls Y,
    # and X and Y are both unnamed/unmatched, try to match by position
    new_mappings = {}
    for match in direct_matches:
        bin_callees = [c for c in binary_graph[match]["callees"] if c not in name_mapping]
        sdk_callees = [c for c in sdk_graph.get(match, []) if c not in name_mapping.values()]

        # Try positional matching (risky but sometimes works)
        if len(bin_callees) == len(sdk_callees) and len(bin_callees) <= 3:
            for bc, sc in zip(bin_callees, sdk_callees):
                if bc.startswith("FUN_") and bc not in new_mappings:
                    new_mappings[bc] = sc

    print(f"New mappings from positional matching: {len(new_mappings)}")
    name_mapping.update(new_mappings)

    # Step 6: Rename matched functions
    print("\nRenaming functions...")
    renamed = 0
    for bin_name, sdk_name in name_mapping.items():
        if bin_name.startswith("FUN_") and bin_name in binary_graph:
            addr = binary_graph[bin_name]["address"]
            if addr:
                result = rename_function(addr, sdk_name)
                if isinstance(result, dict) and "error" not in result:
                    renamed += 1
                    if renamed <= 30:
                        print(f"  {bin_name} -> {sdk_name} @ {addr}")
                time.sleep(0.05)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        all_funcs = result.get("functions", [])
        named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
        print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    # Save mapping
    out = ROOT / "build" / "name_mapping.json"
    out.write_text(json.dumps({k: v for k, v in name_mapping.items() if k.startswith("FUN_")}, indent=2), encoding="utf-8")
    print(f"Mapping saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
