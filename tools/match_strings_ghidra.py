#!/usr/bin/env python3
"""
match_strings_ghidra.py — Match SDK strings to binary strings via Ghidra,
then find xrefs to name functions.
"""
import urllib.request
import urllib.parse
import json
import re
import sys
import time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]


def _get_raw(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=TIMEOUT)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct or data.startswith("{") or data.startswith("["):
        try:
            return json.loads(data)
        except:
            pass
    return data


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    resp = urllib.request.urlopen(req, timeout=TIMEOUT)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct or data.startswith("{") or data.startswith("["):
        try:
            return json.loads(data)
        except:
            pass
    return data


def get_all_strings():
    """Get all defined strings from Ghidra. Returns list of (address, value)."""
    result = _get_raw("/list_strings", {"limit": "50000", "filter": "all"})
    if isinstance(result, list):
        return [(s.get("address", ""), s.get("value", s.get("string", ""))) for s in result if isinstance(s, dict)]
    elif isinstance(result, dict):
        strings = result.get("strings", result.get("items", []))
        return [(s.get("address", ""), s.get("value", s.get("string", ""))) for s in strings if isinstance(s, dict)]

    # Parse text format: "address: \"value\""
    strings = []
    for line in result.strip().split("\n"):
        m = re.match(r'^([0-9a-f]+):\s*"(.*)"\s*$', line)
        if m:
            strings.append((m.group(1), m.group(2)))
    return strings


def get_xrefs_to(address):
    """Get cross-references to an address."""
    result = _get_raw("/get_xrefs_to", {"address": address})
    if isinstance(result, dict):
        refs = result.get("references", result.get("xrefs", result.get("refs", [])))
        if isinstance(refs, list):
            return refs
    elif isinstance(result, list):
        return result
    return []


def get_function_containing(address):
    """Get the function that contains the given address."""
    result = _get_raw("/get_function_containing", {"address": address})
    if isinstance(result, dict):
        return result
    # Parse text format
    if isinstance(result, str):
        m = re.search(r'(\w+)\s+at\s+([0-9a-f]+)', result)
        if m:
            return {"name": m.group(1), "address": m.group(2)}
    return None


def rename_function(address, new_name, dry_run=False):
    """Rename function at address."""
    data = {"address": address, "new_name": new_name}
    if dry_run:
        data["dry_run"] = "true"
    return _post("/rename_function_by_address", data)


def main():
    # Load SDK string map
    string_map_path = ROOT / "build" / "sdk_string_map.json"
    if not string_map_path.is_file():
        print("ERROR: sdk_string_map.json not found. Run build_sdk_index.py first.")
        return 1

    string_map = json.loads(string_map_path.read_text(encoding="utf-8"))
    print(f"SDK strings: {len(string_map)}")

    # Get all strings from Ghidra
    print("Fetching strings from Ghidra...")
    binary_strings = get_all_strings()
    print(f"Binary strings: {len(binary_strings)}")

    # Build a lookup: string value → address
    binary_string_map = {}
    for addr, val in binary_strings:
        if val and len(val) >= 6:
            binary_string_map[val] = addr

    print(f"Binary string map entries: {len(binary_string_map)}")

    # Match SDK strings to binary strings
    matches = []
    for sdk_str, sdk_func in string_map.items():
        if len(sdk_str) < 6:
            continue
        if sdk_str in binary_string_map:
            matches.append({
                "string": sdk_str,
                "sdk_func": sdk_func,
                "string_addr": binary_string_map[sdk_str],
            })

    print(f"String matches: {len(matches)}")

    if not matches:
        print("No string matches found. Trying substring matching...")
        # Try substring matching for strings that didn't match exactly
        for sdk_str, sdk_func in string_map.items():
            if len(sdk_str) < 8:
                continue
            for bin_str, bin_addr in binary_string_map.items():
                if sdk_str in bin_str or bin_str in sdk_str:
                    if abs(len(sdk_str) - len(bin_str)) < 20:
                        matches.append({
                            "string": sdk_str,
                            "bin_string": bin_str,
                            "sdk_func": sdk_func,
                            "string_addr": bin_addr,
                        })
                        break
        print(f"Substring matches: {len(matches)}")

    # For each match, get xrefs and name functions
    renamed = []
    already_renamed = set()

    for i, m in enumerate(matches):
        if i % 20 == 0:
            print(f"  Processing {i}/{len(matches)}...")

        string_addr = m["string_addr"]
        sdk_func = m["sdk_func"]

        # Get xrefs to this string
        xrefs = get_xrefs_to(string_addr)
        if not xrefs:
            continue

        for xref in xrefs:
            if isinstance(xref, dict):
                ref_addr = xref.get("from_address", xref.get("from", xref.get("address", "")))
            elif isinstance(xref, str):
                ref_addr = xref
            else:
                continue

            if not ref_addr:
                continue

            # Get the function containing this reference
            func_info = get_function_containing(ref_addr)
            if not func_info:
                continue

            func_addr = func_info.get("address", func_info.get("entry", ref_addr))
            func_name = func_info.get("name", "")

            if func_name.startswith("FUN_") and func_addr not in already_renamed:
                # Rename it
                result = rename_function(func_addr, sdk_func)
                if isinstance(result, dict) and "error" not in result:
                    already_renamed.add(func_addr)
                    renamed.append({
                        "address": func_addr,
                        "old_name": func_name,
                        "new_name": sdk_func,
                        "string": m["string"][:60],
                    })
                    if len(renamed) <= 30:
                        print(f"  Renamed {func_name} -> {sdk_func} @ {func_addr}")
                else:
                    err = result.get("error", "unknown") if isinstance(result, dict) else str(result)
                    if len(renamed) <= 30 and "duplicate" not in str(err).lower():
                        print(f"  Failed: {func_name} -> {sdk_func}: {err[:100]}")

        # Rate limit
        if (i + 1) % 10 == 0:
            time.sleep(0.3)

    print(f"\n=== Summary ===")
    print(f"String matches: {len(matches)}")
    print(f"Functions renamed: {len(renamed)}")

    # Save results
    output = ROOT / "build" / "ghidra_string_renames.json"
    output.write_text(json.dumps({
        "matches": len(matches),
        "renamed": renamed,
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
