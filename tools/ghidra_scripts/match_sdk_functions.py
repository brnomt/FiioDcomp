# Ghidra headless script: match_sdk_functions.py
# Run via analyzeHeadless or the Ghidra MCP script runner.
#
# This script:
# 1. Reads build/sdk_function_index.json (SDK function → string literals)
# 2. For each string, finds it in the binary
# 3. Finds functions that reference that string
# 4. Names those functions with the SDK name
# 5. Prints a summary of renamed functions
#
# @category Fiio
# @author Cursor

import json
import os
from ghidra.program.model.listing import CodeUnit
from ghidra.program.model.symbol import SourceType

# Paths (relative to project)
INDEX_PATH = os.path.join(os.path.expanduser("~"), "Desktop", "FiioDcomp", "build", "sdk_function_index.json")
OUTPUT_PATH = os.path.join(os.path.expanduser("~"), "Desktop", "FiioDcomp", "build", "ghidra_rename_log.json")

def main():
    fm = currentProgram.getFunctionManager()
    listing = currentProgram.getListing()
    mem = currentProgram.getMemory()
    sym_table = currentProgram.getSymbolTable()

    # Load SDK index
    with open(INDEX_PATH, "r") as f:
        sdk_index = json.load(f)

    # Build string → function_name map (only strings >= 6 chars)
    string_to_func = {}
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 6:
                string_to_func[s] = func_name

    print("SDK strings to search: %d" % len(string_to_func))

    # Find strings in the binary and their addresses
    # Use the memory scanner to find string bytes
    renamed = []
    already_named = set()

    # Get all defined strings from the listing
    from ghidra.program.model.data import StringDataType
    data_iter = listing.getDefinedData(True)
    string_addrs = {}  # addr -> string value

    while data_iter.hasNext():
        d = data_iter.next()
        if d.getDataType() instanceof StringDataType or "string" in str(d.getDataType()).lower():
            val = d.getValue()
            if val and len(str(val)) >= 6:
                string_addrs[d.getAddress().getOffset()] = str(val)

    print("Defined strings in binary: %d" % len(string_addrs))

    # Also scan raw memory for SDK strings
    addr = mem.getMinAddress()
    end = mem.getMaxAddress()
    found_strings = {}

    for sdk_str, func_name in string_to_func.items():
        try:
            found = mem.findBytes(addr, sdk_str.encode("utf-8"), None, True, None)
            if found is not None:
                found_strings[found.getOffset()] = (sdk_str, func_name)
        except Exception:
            pass

    print("SDK strings found in binary: %d" % len(found_strings))

    # For each found string, find xrefs (functions that reference it)
    from ghidra.program.model.symbol import RefType
    ref_mgr = currentProgram.getReferenceManager()

    for str_offset, (sdk_str, sdk_func) in found_strings.items():
        str_addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(str_offset)

        # Get references to this string
        refs = ref_mgr.getReferencesTo(str_addr)
        for ref in refs:
            ref_addr = ref.getFromAddress()
            func = fm.getFunctionContaining(ref_addr)

            if func is None:
                # Try to create function at this address
                func = fm.getFunctionAt(ref_addr)

            if func is not None:
                old_name = func.getName()
                if old_name.startswith("FUN_") and old_name not in already_named:
                    # Rename it
                    func.setName(sdk_func, SourceType.USER_DEFINED)
                    already_named.add(old_name)
                    renamed.append({
                        "old_name": old_name,
                        "new_name": sdk_func,
                        "address": "0x%08x" % func.getEntryPoint().getOffset(),
                        "string": sdk_str,
                    })
                    print("Renamed %s -> %s @ 0x%08x (string: %s)" % (
                        old_name, sdk_func, func.getEntryPoint().getOffset(), sdk_str[:40]))

    print("\n=== Summary ===")
    print("Total renamed: %d" % len(renamed))

    with open(OUTPUT_PATH, "w") as f:
        json.dump(renamed, f, indent=2)
    print("Log written to: %s" % OUTPUT_PATH)

main()
