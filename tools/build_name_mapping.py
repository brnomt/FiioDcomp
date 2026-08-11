#!/usr/bin/env python3
"""
build_name_mapping.py — Use the 82 matched strings to build a mapping between
binary function names and SDK function names, then use this mapping to
translate callee sets and match unnamed functions.

Strategy:
  1. For each SDK string found in the binary, find which binary function references it
  2. The SDK function that references the same string is the mapping target
  3. Build binary_name → sdk_name mapping
  4. Translate callee sets of unnamed functions using this mapping
  5. Match translated callee sets against SDK callee sets
  6. Rename matching functions
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


def get_xrefs_to(addr_str):
    result = _get("/get_xrefs_to", {"address": addr_str})
    if "ERROR" in str(result) or "No references" in str(result):
        return []
    xrefs = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            m = re.search(r'([0-9a-f]{8})', line)
            if m:
                xrefs.append(m.group(1))
    return xrefs


def get_function_at(addr_str):
    result = _get("/get_function_by_address", {"address": addr_str})
    if isinstance(result, str) and "ERROR" not in result and "Function:" in result:
        # Parse plain text: "Function: NAME at ADDR"
        m = re.search(r'Function:\s+(\S+)\s+at', result)
        if m:
            return m.group(1)
    elif isinstance(result, dict):
        return result.get("name", result.get("function_name", ""))
    return None


def main():
    # Load SDK string map (string → SDK function name)
    sdk_string_map = json.loads((ROOT / "build" / "sdk_string_map_combined.json").read_text(encoding="utf-8"))
    print(f"SDK string map: {len(sdk_string_map)} strings")

    # Load SDK function index (function name → callees)
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index_combined.json").read_text(encoding="utf-8"))
    sdk_callees = {}
    for name, info in sdk_index.items():
        callees = info.get("callees", [])
        if callees:
            sdk_callees[name] = set(callees)
    print(f"SDK functions with callees: {len(sdk_callees)}")

    # Load firmware binary
    section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
    LOAD_BASE = 0x03000000

    # Find all SDK strings in the binary
    matches = []
    for sdk_str, sdk_func in sdk_string_map.items():
        if len(sdk_str) < 6:
            continue
        try:
            pos = section3.find(sdk_str.encode("ascii"))
            if pos >= 0:
                matches.append({"string": sdk_str, "load_addr": LOAD_BASE + pos, "encoding": "ascii", "sdk_func": sdk_func})
                continue
        except:
            pass
        try:
            pos = section3.find(sdk_str.encode("utf-16-le"))
            if pos >= 0:
                matches.append({"string": sdk_str, "load_addr": LOAD_BASE + pos, "encoding": "utf16le", "sdk_func": sdk_func})
        except:
            pass

    print(f"String matches in binary: {len(matches)}")

    # For each match, find which binary function references the string
    print("\nBuilding binary->SDK name mapping...")
    name_mapping = {}  # binary_name → sdk_name

    for m in matches:
        addr_str = f"0x{m['load_addr']:08x}"
        sdk_func = m["sdk_func"]

        # Get xrefs to this string address
        xrefs = get_xrefs_to(addr_str)
        for xref_addr in xrefs:
            # Get the function containing this xref
            bin_func_name = get_function_at(f"0x{xref_addr}")
            if bin_func_name and not bin_func_name.startswith("FUN_"):
                # This binary function references a string that matches an SDK function
                if bin_func_name not in name_mapping:
                    name_mapping[bin_func_name] = sdk_func
                elif name_mapping[bin_func_name] != sdk_func:
                    # Conflict — skip
                    pass

        time.sleep(0.1)

    print(f"Name mapping: {len(name_mapping)} entries")
    for bin_name, sdk_name in sorted(name_mapping.items()):
        match_type = "DIRECT" if bin_name == sdk_name else "MAPPED"
        print(f"  {bin_name:40s} -> {sdk_name:40s} [{match_type}]")

    # Now use this mapping to translate binary callee names to SDK names
    # Get full call graph
    print("\nGetting full call graph...")
    cg_text = _get("/get_full_call_graph", {"format": "text", "limit": 100000})
    if cg_text.startswith("ERROR"):
        print(f"Error: {cg_text}")
        return 1

    # Parse call graph
    binary_graph = defaultdict(list)  # caller_name -> [(callee_name, callee_addr)]
    for line in cg_text.strip().split("\n"):
        m = re.match(r'(\S+)@(\S+)\s*->\s*(\S+)@(\S+)', line)
        if m:
            caller_name = m.group(1)
            callee_name = m.group(3)
            callee_addr = m.group(4)
            binary_graph[caller_name].append((callee_name, callee_addr))

    print(f"Binary call graph: {len(binary_graph)} callers")

    # Get all functions
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named_funcs = {f["name"]: f["address"] for f in all_funcs
                    if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")}
    unnamed_funcs = [(f["name"], f["address"]) for f in all_funcs
                     if f.get("name", "").startswith("FUN_") and int(f.get("address", "0"), 16) >= 0x03000000]
    print(f"Named: {len(named_funcs)}, Unnamed: {len(unnamed_funcs)}")

    # For each unnamed function, get its callees, translate to SDK names, and match
    print("\nMatching unnamed functions by translated callee sets...")
    renamed = 0

    for i, (func_name, func_addr) in enumerate(unnamed_funcs):
        if i % 200 == 0:
            print(f"  {i}/{len(unnamed_funcs)}...")

        # Get callees
        callees = binary_graph.get(func_name, [])
        if not callees:
            continue

        # Translate callee names to SDK names
        translated_callees = set()
        for callee_name, callee_addr in callees:
            if callee_name in name_mapping:
                translated_callees.add(name_mapping[callee_name])
            elif callee_name in sdk_callees:
                translated_callees.add(callee_name)

        if not translated_callees:
            continue

        # Match against SDK functions
        best_match = None
        best_score = 0
        for sdk_name, sdk_callee_set in sdk_callees.items():
            overlap = translated_callees & sdk_callee_set
            score = len(overlap)
            if score > best_score and score >= 2:
                best_score = score
                best_match = sdk_name

        if best_match and best_score >= 2:
            result = rename_function(func_addr, best_match)
            if "error" not in result.lower():
                renamed += 1
                if renamed <= 50:
                    print(f"  {func_name} -> {best_match} @ {func_addr} (score: {best_score}, callees: {translated_callees})")

        time.sleep(0.05)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by translated callee matching: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    # Save mapping
    out = ROOT / "build" / "binary_to_sdk_mapping.json"
    out.write_text(json.dumps(name_mapping, indent=2), encoding="utf-8")
    print(f"Mapping saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
