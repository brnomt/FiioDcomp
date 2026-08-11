#!/usr/bin/env python3
"""
propagate_from_functionality.py — After functionality matching names functions,
propagate names through the call graph using SDK call structure.

If binary function A is named (e.g., FmFreqToChan) and calls FUN_X,
and SDK function FmFreqToChan calls function Y in the SDK source,
then FUN_X might be Y.
"""
import json, time, urllib.request, re
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=60)
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


def get_callees(address):
    """Get callees of a function from Ghidra."""
    try:
        result = _get("/get_function_callees", {"address": address})
        # Parse the response — might be JSON or plain text
        try:
            data = json.loads(result)
            if isinstance(data, list):
                return data
            elif isinstance(data, dict):
                return data.get("callees", data.get("functions", []))
        except:
            pass
        # Try plain text parsing
        callees = []
        for line in result.strip().split("\n"):
            line = line.strip()
            if line and not line.startswith("ERROR"):
                parts = line.split()
                if len(parts) >= 2:
                    callees.append({"address": parts[0], "name": parts[1] if len(parts) > 1 else ""})
        return callees
    except:
        return []


def get_callers(address):
    """Get callers of a function from Ghidra."""
    try:
        result = _get("/get_function_callers", {"address": address})
        try:
            data = json.loads(result)
            if isinstance(data, list):
                return data
            elif isinstance(data, dict):
                return data.get("callers", data.get("functions", []))
        except:
            pass
        callers = []
        for line in result.strip().split("\n"):
            line = line.strip()
            if line and not line.startswith("ERROR"):
                parts = line.split()
                if len(parts) >= 2:
                    callers.append({"address": parts[0], "name": parts[1] if len(parts) > 1 else ""})
        return callers
    except:
        return []


def main():
    # Load SDK features (which include callees)
    sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))

    # Load functionality matches
    func_matches = json.loads((ROOT / "build" / "functionality_matches_v2.json").read_text(encoding="utf-8"))
    print(f"Functionality matches: {len(func_matches)}")

    # Get all functions from Ghidra
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)

    # Build address -> name map
    addr_to_name = {f["address"]: f["name"] for f in all_funcs}
    name_to_addr = {f["name"]: f["address"] for f in all_funcs if not f["name"].startswith("FUN_")}

    # For each named function that was matched by functionality,
    # get its callees from the binary and from the SDK
    print("\nPropagating names through call graph...")

    # First, collect all named functions (not just functionality matches — all named ones)
    named_funcs = [(f["address"], f["name"]) for f in all_funcs
                   if not f["name"].startswith("FUN_") and not f["name"].startswith("LAB_")]
    print(f"Named functions to propagate from: {len(named_funcs)}")

    # For each named function, get its callees
    # If a callee is unnamed, check if the SDK source of the named function
    # calls a specific function that we can identify
    rename_candidates = {}  # addr -> (suggested_name, score)

    for addr, name in named_funcs:
        if name not in sdk_features:
            continue

        # Get binary callees
        bin_callees = get_callees(addr)
        unnamed_callees = [c for c in bin_callees if c.get("name", "").startswith("FUN_")]

        if not unnamed_callees:
            continue

        # Get SDK callees from source
        sdk_src_path = ROOT / sdk_features[name].get("source_file", "")
        if not sdk_src_path.exists():
            continue

        sdk_code = sdk_src_path.read_text(encoding="utf-8", errors="ignore")

        # Find function calls in the SDK source for this specific function
        # Extract the function body
        pattern = rf'\b{re.escape(name)}\s*\([^)]*\)\s*\{{'
        match = re.search(pattern, sdk_code)
        if not match:
            continue

        # Find the function body (from { to matching })
        brace_count = 0
        body_start = match.end() - 1  # position of {
        for i in range(match.end() - 1, min(match.end() + 5000, len(sdk_code))):
            if sdk_code[i] == '{':
                brace_count += 1
            elif sdk_code[i] == '}':
                brace_count -= 1
            if brace_count == 0:
                body = sdk_code[body_start:i+1]
                break
        else:
            continue

        # Extract function calls from the body
        sdk_calls = re.findall(r'\b(\w+)\s*\(', body)
        # Filter out C keywords and the function itself
        keywords = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'case', 'do', name}
        sdk_calls = [c for c in sdk_calls if c not in keywords and not c.startswith('_')]

        # If the SDK function calls N functions and the binary function calls N unnamed functions,
        # try positional matching (but only if counts are close)
        if len(unnamed_callees) == 1 and len(sdk_calls) >= 1:
            # Only one unnamed callee — try to identify it
            # Check if any SDK call is a known function in our SDK index
            for sdk_call in sdk_calls:
                if sdk_call in sdk_features and sdk_call not in name_to_addr:
                    # This SDK function is not yet named in the binary
                    callee_addr = unnamed_callees[0]["address"]
                    if callee_addr not in rename_candidates:
                        rename_candidates[callee_addr] = (sdk_call, 1)
                    else:
                        # Multiple suggestions — keep the one with more votes
                        old_name, old_score = rename_candidates[callee_addr]
                        if sdk_call != old_name:
                            # Conflict — don't rename
                            rename_candidates[callee_addr] = (None, 0)
                        else:
                            rename_candidates[callee_addr] = (sdk_call, old_score + 1)

    # Filter out conflicts
    final_renames = {addr: name for addr, (name, score) in rename_candidates.items() if name and score > 0}
    print(f"Rename candidates from propagation: {len(final_renames)}")

    # Rename in Ghidra
    renamed = 0
    for addr, name in final_renames.items():
        result = rename_function(addr, name)
        if "error" not in result.lower():
            renamed += 1
            print(f"  {addr} -> {name}")
        time.sleep(0.05)

    print(f"\n=== PROPAGATION SUMMARY ===")
    print(f"Functions renamed by call graph propagation: {renamed}")

    # Final count
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
