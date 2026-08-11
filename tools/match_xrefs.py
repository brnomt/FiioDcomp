#!/usr/bin/env python3
"""
match_xrefs.py — Find SDK strings in the raw binary, then use Ghidra's
get_xrefs_to to find which functions reference them.

Key insight: get_xrefs_to works even for addresses that aren't defined as
strings in Ghidra — it finds code references to any address.
"""
import urllib.request
import urllib.parse
import json
import re
import struct
import time
import sys
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]
LOAD_BASE = 0x03000000


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


def get_xrefs_to(address):
    """Get cross-references to an address. Returns list of {from_address, function}."""
    addr_str = f"0x{address:08x}" if isinstance(address, int) else address
    result = _get("/get_xrefs_to", {"address": addr_str})
    refs = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            m = re.match(r'From\s+([0-9a-f]+)\s+in\s+(\S+)', line)
            if m:
                refs.append({"from_address": m.group(1), "function": m.group(2)})
    elif isinstance(result, dict):
        items = result.get("references", result.get("xrefs", []))
        if isinstance(items, list):
            refs = items
    elif isinstance(result, list):
        refs = result
    return refs


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def extract_ascii_strings(data, min_len=6):
    """Extract ASCII strings from binary."""
    strings = []
    current = bytearray()
    start = 0
    for i, b in enumerate(data):
        if 32 <= b < 127:
            if not current:
                start = i
            current.append(b)
        else:
            if len(current) >= min_len:
                strings.append((start, current.decode('ascii', errors='ignore')))
            current = bytearray()
    if len(current) >= min_len:
        strings.append((start, current.decode('ascii', errors='ignore')))
    return strings


def extract_utf16le_strings(data, min_len=6):
    """Extract UTF-16LE strings from binary."""
    strings = []
    i = 0
    while i < len(data) - 1:
        if data[i] >= 32 and data[i] < 127 and data[i + 1] == 0:
            start = i
            chars = []
            j = i
            while j < len(data) - 1:
                lo = data[j]
                hi = data[j + 1]
                if hi == 0 and lo >= 32 and lo < 127:
                    chars.append(chr(lo))
                    j += 2
                elif lo == 0 and hi == 0:
                    break
                else:
                    break
            if len(chars) >= min_len:
                strings.append((start, "".join(chars)))
            i = j + 2
        else:
            i += 1
    return strings


def main():
    # Load SDK index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Build string -> SDK function map (unique strings only)
    string_to_sdk = {}
    ambiguous = set()
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 6:
                if s in string_to_sdk:
                    ambiguous.add(s)
                else:
                    string_to_sdk[s] = func_name
    for s in ambiguous:
        del string_to_sdk[s]
    print(f"SDK unique strings: {len(string_to_sdk)}")

    # Also index SDK source files directly
    sdk_root = ROOT / "firmware" / "rockchip_wireless"
    sdk_files = {}
    for f in sorted(sdk_root.rglob("*.c")):
        try:
            sdk_files[str(f.relative_to(sdk_root))] = f.read_text(encoding="utf-8", errors="ignore")
        except:
            pass

    # Also check MP3 V1.3 SDK
    sdk_root2 = ROOT / "firmware" / "rockchip"
    for f in sorted(sdk_root2.rglob("*.c")):
        try:
            sdk_files[str(f.relative_to(sdk_root2))] = f.read_text(encoding="utf-8", errors="ignore")
        except:
            pass
    print(f"SDK source files: {len(sdk_files)}")

    # Load section3 binary
    section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
    print(f"Section_3: {len(section3):,} bytes")

    # Extract all strings from binary
    print("Extracting ASCII strings...")
    ascii_strings = extract_ascii_strings(section3, min_len=8)
    print(f"  ASCII: {len(ascii_strings)}")

    print("Extracting UTF-16LE strings...")
    utf16_strings = extract_utf16le_strings(section3, min_len=6)
    print(f"  UTF-16LE: {len(utf16_strings)}")

    all_strings = [(off, s, "ascii") for off, s in ascii_strings] + [(off, s, "utf16le") for off, s in utf16_strings]
    print(f"  Total: {len(all_strings)}")

    # Match binary strings to SDK
    matches = []
    for offset, string_val, encoding in all_strings:
        if len(string_val) < 8:
            continue
        alpha_count = sum(1 for c in string_val if c.isalpha())
        if alpha_count < len(string_val) * 0.4:
            continue

        # Check SDK string map
        if string_val in string_to_sdk:
            matches.append({
                "string": string_val,
                "offset": offset,
                "load_addr": LOAD_BASE + offset,
                "encoding": encoding,
                "sdk_func": string_to_sdk[string_val],
                "source": "sdk_map",
            })
            continue

        # Search SDK source files
        for file_path, text in sdk_files.items():
            if string_val in text:
                # Find which SDK function uses this string
                for fn, info in sdk_index.items():
                    if info.get("file", "").endswith(file_path) and string_val in info.get("strings", []):
                        matches.append({
                            "string": string_val,
                            "offset": offset,
                            "load_addr": LOAD_BASE + offset,
                            "encoding": encoding,
                            "sdk_func": fn,
                            "source": "sdk_source",
                        })
                        break
                break

    print(f"\nString matches: {len(matches)}")

    # For each match, use get_xrefs_to to find the referencing function
    renamed = {}
    for i, m in enumerate(matches):
        if i % 5 == 0:
            print(f"  Processing {i}/{len(matches)}...")

        load_addr = m["load_addr"]
        sdk_func = m["sdk_func"]

        # Use get_xrefs_to to find references to this string address
        xrefs = get_xrefs_to(load_addr)
        if not xrefs:
            continue

        for xref in xrefs:
            func_name = xref.get("function", xref.get("name", ""))
            from_addr = xref.get("from_address", xref.get("from", ""))

            if func_name.startswith("FUN_"):
                # Get the function address
                func_addr = from_addr
                if func_addr and func_addr not in renamed:
                    result = rename_function(func_addr, sdk_func)
                    if isinstance(result, dict) and "error" not in result:
                        renamed[func_addr] = sdk_func
                        print(f"  RENAMED: {func_name} -> {sdk_func} @ {func_addr} (string: {m['string'][:40]}, {m['encoding']})")

        time.sleep(0.2)

    print(f"\n=== SUMMARY ===")
    print(f"String matches: {len(matches)}")
    print(f"Functions renamed: {len(renamed)}")

    # Get final function count
    result = _get("/list_functions_enhanced")
    all_funcs = result.get("functions", []) if isinstance(result, dict) else []
    final_named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total functions: {len(all_funcs)}")
    print(f"Named: {final_named} ({100*final_named/len(all_funcs):.1f}%)")

    output = ROOT / "build" / "ghidra_xref_renames.json"
    output.write_text(json.dumps({
        "matches": len(matches),
        "renamed": [{"address": k, "name": v} for k, v in renamed.items()],
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
