#!/usr/bin/env python3
"""
check_xrefs_again.py — Check xrefs for the 26 known string matches again.
The previous FullMatch script may have defined strings and triggered analysis.
"""
import urllib.request, urllib.parse, json, re, time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=60)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def main():
    # Recompute matches
    string_map = json.loads((ROOT / "build" / "sdk_string_map_combined.json").read_text(encoding="utf-8"))
    section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
    LOAD_BASE = 0x03000000

    matches = []
    for sdk_str, sdk_func in string_map.items():
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

    print(f"String matches: {len(matches)}")

    # Check xrefs for each
    renamed = 0
    for m in matches:
        addr = m["load_addr"]
        addr_str = f"0x{addr:08x}"
        sdk_func = m["sdk_func"]
        sdk_str = m["string"]

        # Get xrefs
        result = _get("/get_xrefs_to", {"address": addr_str})
        if "ERROR" in str(result) or "No references" in str(result):
            continue

        # Parse xrefs
        xref_addrs = []
        if isinstance(result, str):
            for line in result.strip().split("\n"):
                # Extract address from line
                m2 = re.search(r'([0-9a-f]{8})', line)
                if m2:
                    xref_addrs.append(m2.group(1))
        elif isinstance(result, dict):
            xrefs = result.get("xrefs", result.get("references", []))
            for x in xrefs:
                if isinstance(x, dict):
                    xref_addrs.append(x.get("from_address", x.get("address", "")))
                elif isinstance(x, str):
                    xref_addrs.append(x)

        if not xref_addrs:
            continue

        print(f"\nString: {sdk_str[:50]!r}")
        print(f"  Addr: {addr_str}, Encoding: {m['encoding']}")
        print(f"  SDK func: {sdk_func}")
        print(f"  Xrefs: {xref_addrs}")

        # For each xref, find the containing function and rename it
        for xref_addr in xref_addrs:
            # Get function at this address
            func_result = _get("/get_function_info", {"address": xref_addr})
            if isinstance(func_result, str) and "ERROR" not in func_result:
                # Parse function info
                func_name_match = re.search(r'Name:\s*(\S+)', func_result)
                if func_name_match:
                    func_name = func_name_match.group(1)
                    if func_name.startswith("FUN_"):
                        # Rename it
                        # Need to find the function's entry point
                        entry_match = re.search(r'Entry:\s*([0-9a-f]+)', func_result)
                        if entry_match:
                            entry_addr = entry_match.group(1)
                            full_entry = f"0x{entry_addr}"
                            result = rename_function(full_entry, sdk_func)
                            if "error" not in result.lower():
                                renamed += 1
                                print(f"  RENAMED: {func_name} -> {sdk_func} @ {full_entry}")
                            time.sleep(0.1)

        time.sleep(0.2)

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
