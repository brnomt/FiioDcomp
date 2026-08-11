#!/usr/bin/env python3
"""
Run a Ghidra script via the HTTP API to:
1. Auto-define strings in the binary
2. Search for SDK strings
3. Find xrefs to those strings
4. Name FUN_* functions that reference matching strings
5. Also do call-graph propagation from named functions
"""
import urllib.request
import urllib.parse
import json
import time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    try:
        resp = urllib.request.urlopen(req, timeout=300)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return f"ERROR: {e}"


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=300)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return f"ERROR: {e}"


# The Ghidra script to run inline
# This script will:
# 1. Scan the binary for ASCII strings and define them
# 2. Build a string→address map
# 3. Load the SDK string→function map
# 4. For each SDK string found in the binary, find xrefs
# 5. Rename FUN_* functions that reference matching strings
SCRIPT_CODE = r"""
import json
import os
from ghidra.program.model.data import StringDataType, TerminatedStringDataType
from ghidra.program.model.symbol import SourceType

# Paths
INDEX_PATH = os.path.join(os.path.expanduser("~"), "Desktop", "FiioDcomp", "build", "sdk_function_index.json")
OUTPUT_PATH = os.path.join(os.path.expanduser("~"), "Desktop", "FiioDcomp", "build", "ghidra_auto_renames.json")

def main():
    fm = currentProgram.getFunctionManager()
    mem = currentProgram.getMemory()
    ref_mgr = currentProgram.getReferenceManager()
    listing = currentProgram.getListing()
    addr_factory = currentProgram.getAddressFactory()

    # Load SDK index
    with open(INDEX_PATH, "r") as f:
        sdk_index = json.load(f)

    # Build string -> SDK function map
    string_to_sdk = {}
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 6:
                string_to_sdk[s] = func_name

    println("SDK strings: " + str(len(string_to_sdk)))

    # Step 1: Find SDK strings in the binary and define them as strings
    renamed = []
    already_renamed = set()

    # Get the address space
    space = addr_factory.getDefaultAddressSpace()
    min_addr = mem.getMinAddress()
    max_addr = mem.getMaxAddress()

    # For each SDK string, search for it in the binary
    found_count = 0
    for sdk_str, sdk_func in string_to_sdk.items():
        if len(sdk_str) < 6:
            continue
        try:
            # Search for the string in memory
            found = mem.findBytes(min_addr, sdk_str.getBytes("UTF-8"), None, True, None)
            if found is not None:
                found_count += 1
                # Get xrefs to this address
                refs = ref_mgr.getReferencesTo(found)
                for ref in refs:
                    ref_addr = ref.getFromAddress()
                    func = fm.getFunctionContaining(ref_addr)
                    if func is None:
                        func = fm.getFunctionAt(ref_addr)
                    if func is not None:
                        old_name = func.getName()
                        if old_name.startswith("FUN_") and old_name not in already_renamed:
                            func.setName(sdk_func, SourceType.USER_DEFINED)
                            already_renamed.add(old_name)
                            renamed.append({
                                "old_name": old_name,
                                "new_name": sdk_func,
                                "address": "0x%08x" % func.getEntryPoint().getOffset(),
                                "string": sdk_str[:60]
                            })
                            println("Renamed " + old_name + " -> " + sdk_func)
        except Exception as e:
            pass

    println("Strings found: " + str(found_count))
    println("Functions renamed: " + str(len(renamed)))

    # Step 2: Call-graph propagation
    # For each named function that exists in the SDK, get its callees
    # and match them to SDK callees by position
    sdk_callgraph = {}
    for func_name, info in sdk_index.items():
        sdk_callgraph[func_name] = info.get("callees", [])

    cg_renamed = []
    all_funcs = fm.getFunctions(True)
    named_funcs = []
    while all_funcs.hasNext():
        f = all_funcs.next()
        name = f.getName()
        if not name.startswith("FUN_"):
            named_funcs.append(f)

    println("Named functions for callgraph: " + str(len(named_funcs)))

    for func in named_funcs:
        func_name = func.getName()
        if func_name not in sdk_callgraph:
            continue
        sdk_callees = sdk_callgraph[func_name]
        if not sdk_callees:
            continue

        # Get binary callees
        bin_callees = []
        body = func.getBody()
        inst_iter = listing.getInstructions(body, True)
        while inst_iter.hasNext():
            inst = inst_iter.next()
            for ref in inst.getReferencesFrom():
                if ref.getReferenceType().isCall():
                    target = ref.getToAddress()
                    callee = fm.getFunctionAt(target)
                    if callee is None:
                        callee = fm.getFunctionContaining(target)
                    if callee is not None:
                        bin_callees.append(callee.getName())

        # Match by position if counts match
        if len(bin_callees) == len(sdk_callees):
            for i in range(min(len(bin_callees), len(sdk_callees))):
                bin_name = bin_callees[i]
                sdk_name = sdk_callees[i]
                if bin_name.startswith("FUN_") and sdk_name in sdk_index:
                    callee_func = None
                    # Find the callee function
                    body2 = func.getBody()
                    inst_iter2 = listing.getInstructions(body2, True)
                    idx = 0
                    while inst_iter2.hasNext():
                        inst2 = inst_iter2.next()
                        for ref in inst2.getReferencesFrom():
                            if ref.getReferenceType().isCall():
                                target = ref.getToAddress()
                                cf = fm.getFunctionAt(target)
                                if cf is None:
                                    cf = fm.getFunctionContaining(target)
                                if cf is not None and cf.getName() == bin_name:
                                    if idx == i and bin_name not in already_renamed:
                                        cf.setName(sdk_name, SourceType.USER_DEFINED)
                                        already_renamed.add(bin_name)
                                        cg_renamed.append({
                                            "old_name": bin_name,
                                            "new_name": sdk_name,
                                            "parent": func_name
                                        })
                                        println("CG: " + bin_name + " -> " + sdk_name + " (from " + func_name + ")")
                                idx += 1

    println("Callgraph renames: " + str(len(cg_renamed)))

    # Save results
    result = {
        "string_renames": renamed,
        "callgraph_renames": cg_renamed,
        "total_string": len(renamed),
        "total_callgraph": len(cg_renamed)
    }
    with open(OUTPUT_PATH, "w") as f:
        json.dump(result, f, indent=2)
    println("Results saved to: " + OUTPUT_PATH)

main()
"""

print("Running Ghidra script via HTTP API...")
print(f"Script length: {len(SCRIPT_CODE)} chars")

result = _post("/run_script_inline", {"code": SCRIPT_CODE})
print(f"\nResult type: {type(result)}")
if isinstance(result, dict):
    if "error" in result:
        print(f"Error: {result['error'][:500]}")
    else:
        print(f"Output: {str(result)[:2000]}")
elif isinstance(result, str):
    print(f"Output: {result[:2000]}")
else:
    print(f"Output: {str(result)[:2000]}")
