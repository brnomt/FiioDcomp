#!/usr/bin/env python3
"""
define_and_match.py — Define SDK strings in Ghidra, then find xrefs and rename functions.

Process:
  1. Search the raw binary for SDK strings (both ASCII and UTF-16LE)
  2. Define each found string as a string data type in Ghidra using apply_data_type
  3. Run reanalyze to find references to the newly defined strings
  4. Use get_xrefs_to to find which functions reference each string
  5. Rename FUN_* functions to the SDK function name
"""
import urllib.request, urllib.parse, json, re, time, sys
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]
LOAD_BASE = 0x03000000


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=TIMEOUT)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"

def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body, headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=TIMEOUT)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"

def get_xrefs_to(load_addr):
    result = _get("/get_xrefs_to", {"address": f"0x{load_addr:08x}"})
    refs = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            m = re.match(r'From\s+([0-9a-f]+)\s+in\s+(\S+)', line)
            if m:
                refs.append({"from_address": m.group(1), "function": m.group(2)})
    return refs

def rename_function(address, new_name):
    result = _post("/rename_function_by_address", {"address": address, "new_name": new_name})
    if isinstance(result, str) and result.startswith("{"):
        try: return json.loads(result)
        except: pass
    return result

def define_string(addr_hex, type_name="string"):
    return _post("/apply_data_type", {"address": addr_hex, "type_name": type_name})

def reanalyze():
    return _post("/reanalyze", {})


def main():
    # Load both SDK indexes
    mp3_index = json.loads((ROOT / "build" / "sdk_function_index_mp3.json").read_text(encoding="utf-8"))
    wireless_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Build combined string -> SDK function map (unique strings only)
    string_to_sdk = {}
    ambiguous = set()
    for idx in [mp3_index, wireless_index]:
        for func_name, info in idx.items():
            for s in info.get("strings", []):
                if len(s) >= 6:
                    if s in string_to_sdk and string_to_sdk[s] != func_name:
                        ambiguous.add(s)
                    else:
                        string_to_sdk[s] = func_name
    for s in ambiguous:
        del string_to_sdk[s]
    print(f"Combined unique strings: {len(string_to_sdk)}")

    # Load binary
    section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
    print(f"Section_3: {len(section3):,} bytes")

    # Search for each SDK string in the binary
    matches = []
    for sdk_str, sdk_func in string_to_sdk.items():
        if len(sdk_str) < 6:
            continue
        # ASCII search
        try:
            pos = section3.find(sdk_str.encode("ascii"))
            if pos >= 0:
                # Verify it's a proper string boundary (null terminator follows)
                end = pos + len(sdk_str)
                if end < len(section3) and section3[end] == 0:
                    matches.append({
                        "string": sdk_str, "offset": pos, "load_addr": LOAD_BASE + pos,
                        "encoding": "ascii", "sdk_func": sdk_func, "length": len(sdk_str)
                    })
                    continue
                # Also accept if preceded by non-printable (string start)
                if pos == 0 or section3[pos - 1] == 0 or section3[pos - 1] < 32 or section3[pos - 1] >= 127:
                    matches.append({
                        "string": sdk_str, "offset": pos, "load_addr": LOAD_BASE + pos,
                        "encoding": "ascii", "sdk_func": sdk_func, "length": len(sdk_str)
                    })
                    continue
        except:
            pass
        # UTF-16LE search
        try:
            utf16 = sdk_str.encode("utf-16-le")
            pos = section3.find(utf16)
            if pos >= 0:
                # Check null terminator (2 zero bytes)
                end = pos + len(utf16)
                if end + 1 < len(section3) and section3[end] == 0 and section3[end + 1] == 0:
                    matches.append({
                        "string": sdk_str, "offset": pos, "load_addr": LOAD_BASE + pos,
                        "encoding": "utf16le", "sdk_func": sdk_func, "length": len(sdk_str)
                    })
        except:
            pass

    print(f"String matches in binary: {len(matches)}")

    # Phase 1: Define strings in Ghidra
    print("\nPhase 1: Defining strings in Ghidra...")
    defined = 0
    for i, m in enumerate(matches):
        if i % 10 == 0:
            print(f"  Defining {i}/{len(matches)}...")

        addr_hex = f"0x{m['load_addr']:08x}"
        type_name = "string" if m["encoding"] == "ascii" else "ushort"

        if m["encoding"] == "ascii":
            result = define_string(addr_hex, "string")
            if isinstance(result, str) and "Successfully" in result:
                defined += 1
            elif isinstance(result, str) and "ERROR" not in result and "error" not in result.lower():
                defined += 1
        time.sleep(0.05)

    print(f"  Defined: {defined}")

    # Phase 2: Get xrefs and rename functions
    print("\nPhase 2: Getting xrefs and renaming functions...")
    renamed = {}
    for i, m in enumerate(matches):
        if i % 10 == 0:
            print(f"  Processing {i}/{len(matches)}...")

        load_addr = m["load_addr"]
        sdk_func = m["sdk_func"]

        xrefs = get_xrefs_to(load_addr)
        if not xrefs:
            continue

        for xref in xrefs:
            func_name = xref.get("function", "")
            from_addr = xref.get("from_address", "")

            if func_name.startswith("FUN_"):
                if from_addr and from_addr not in renamed:
                    result = rename_function(from_addr, sdk_func)
                    if isinstance(result, dict) and "error" not in result:
                        renamed[from_addr] = sdk_func
                        print(f"  RENAMED: {func_name} -> {sdk_func} @ {from_addr} (string: {m['string'][:40]})")
                    elif isinstance(result, str) and "error" not in result.lower():
                        renamed[from_addr] = sdk_func
                        print(f"  RENAMED: {func_name} -> {sdk_func} @ {from_addr} (string: {m['string'][:40]})")

        time.sleep(0.1)

    print(f"\n=== SUMMARY ===")
    print(f"String matches: {len(matches)}")
    print(f"Strings defined: {defined}")
    print(f"Functions renamed: {len(renamed)}")

    # Final count
    result = _get("/list_functions_enhanced")
    if isinstance(result, str) and result.startswith("{"):
        try:
            data = json.loads(result)
            all_funcs = data.get("functions", [])
            final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
            print(f"Total functions: {len(all_funcs)}")
            print(f"Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")
        except:
            pass

    output = ROOT / "build" / "ghidra_define_renames.json"
    output.write_text(json.dumps({
        "matches": len(matches), "defined": defined,
        "renamed": [{"address": k, "name": v} for k, v in renamed.items()]
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
