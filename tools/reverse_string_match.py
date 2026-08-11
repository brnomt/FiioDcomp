#!/usr/bin/env python3
"""
reverse_string_match.py — Reverse string matching with UTF-16LE support.

The Fiio Echo Mini firmware stores UI strings as UTF-16LE (wide strings),
while codec/system strings are ASCII. This script searches for both.

Strategy:
  1. Extract ALL strings from the binary (both ASCII and UTF-16LE)
  2. For each binary string, search the SDK source for it
  3. If found, identify which SDK function uses that string
  4. Find the binary function that references that string address
  5. Name it
"""
import urllib.request
import urllib.parse
import json
import re
import struct
import sys
import time
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
        ct = resp.headers.get("Content-Type", "")
        data = resp.read().decode("utf-8")
        if "json" in ct or data.startswith("{") or data.startswith("["):
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
        ct = resp.headers.get("Content-Type", "")
        data = resp.read().decode("utf-8")
        if "json" in ct or data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return {"error": str(e)}


def extract_ascii_strings(data: bytes, min_len: int = 6) -> list[tuple[int, str, str]]:
    """Extract ASCII strings. Returns [(offset, string, encoding)]."""
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
                strings.append((start, current.decode('ascii', errors='ignore'), "ascii"))
            current = bytearray()
    if len(current) >= min_len:
        strings.append((start, current.decode('ascii', errors='ignore'), "ascii"))
    return strings


def extract_utf16le_strings(data: bytes, min_len: int = 6) -> list[tuple[int, str, str]]:
    """Extract UTF-16LE strings. Returns [(offset, string, encoding)].

    UTF-16LE strings have the pattern: char\x00char\x00...
    Terminated by \x00\x00.
    """
    strings = []
    i = 0
    while i < len(data) - 1:
        # Check if this looks like a UTF-16LE string start
        # (ASCII char followed by \x00)
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
                    # Null terminator
                    break
                else:
                    # Non-ASCII or non-null high byte — end of string
                    break
            if len(chars) >= min_len:
                strings.append((start, "".join(chars), "utf16le"))
            i = j + 2
        else:
            i += 1
    return strings


def find_code_refs_to_address(section3: bytes, target_addr: int) -> list[int]:
    """Find offsets in the binary that contain a 32-bit reference to target_addr."""
    needle = struct.pack("<I", target_addr)
    refs = []
    idx = 0
    while True:
        pos = section3.find(needle, idx)
        if pos < 0:
            break
        refs.append(pos)
        idx = pos + 1
    return refs


def get_function_containing(address: str):
    """Get the function that contains the given address."""
    # Try different endpoint names
    for endpoint in ["/get_function_containing", "/function_containing", "/get_function_at"]:
        result = _get(endpoint, {"address": address})
        if isinstance(result, dict) and "error" not in result:
            return result
        if isinstance(result, str) and "404" not in result and "Not Found" not in result:
            # Parse text format
            m = re.search(r'(\w+)\s+at\s+([0-9a-f]+)', result)
            if m:
                return {"name": m.group(1), "address": m.group(2)}
    return None


def get_all_functions():
    """Get all functions. Returns list of {address, name}."""
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def find_function_by_addr_range(funcs: list, addr: int) -> dict | None:
    """Find the function that contains the given address by binary search."""
    # Functions are sorted by address
    # Find the last function whose address <= addr
    lo, hi = 0, len(funcs) - 1
    result = None
    while lo <= hi:
        mid = (lo + hi) // 2
        func_addr = int(funcs[mid].get("address", "0"), 16)
        if func_addr <= addr:
            result = funcs[mid]
            lo = mid + 1
        else:
            hi = mid - 1
    return result


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def main():
    # Load SDK index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Build string -> SDK function map
    string_to_sdk_funcs = {}
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 6:
                if s not in string_to_sdk_funcs:
                    string_to_sdk_funcs[s] = []
                string_to_sdk_funcs[s].append(func_name)

    print(f"SDK string->function map: {len(string_to_sdk_funcs)} unique strings")

    # Also index SDK source files for direct string search
    sdk_root = ROOT / "firmware" / "rockchip_wireless"
    print("Indexing SDK source files...")
    sdk_file_contents = {}
    for f in sorted(sdk_root.rglob("*.c")):
        try:
            text = f.read_text(encoding="utf-8", errors="ignore")
            sdk_file_contents[str(f.relative_to(sdk_root))] = text
        except:
            pass
    print(f"Indexed {len(sdk_file_contents)} SDK source files")

    # Load section3 binary
    section3_path = ROOT / "build" / "section3_stock.bin"
    section3 = section3_path.read_bytes()
    print(f"Section_3: {len(section3):,} bytes")

    # Extract both ASCII and UTF-16LE strings
    print("Extracting ASCII strings...")
    ascii_strings = extract_ascii_strings(section3, min_len=8)
    print(f"  ASCII strings: {len(ascii_strings)}")

    print("Extracting UTF-16LE strings...")
    utf16_strings = extract_utf16le_strings(section3, min_len=6)
    print(f"  UTF-16LE strings: {len(utf16_strings)}")

    all_strings = ascii_strings + utf16_strings
    print(f"  Total: {len(all_strings)}")

    # Get all functions from Ghidra for address range lookup
    print("Fetching functions from Ghidra...")
    all_funcs = get_all_functions()
    # Sort by address
    all_funcs_sorted = sorted(all_funcs, key=lambda f: int(f.get("address", "0"), 16))
    print(f"  Functions: {len(all_funcs_sorted)}")

    # Match binary strings to SDK strings
    matches = []
    for offset, string_val, encoding in all_strings:
        if len(string_val) < 8:
            continue

        # Skip strings with too few alpha chars
        alpha_count = sum(1 for c in string_val if c.isalpha())
        if alpha_count < len(string_val) * 0.4:
            continue

        # Check SDK string map first
        sdk_funcs = string_to_sdk_funcs.get(string_val)
        if sdk_funcs:
            matches.append({
                "string": string_val,
                "offset": offset,
                "load_addr": LOAD_BASE + offset,
                "encoding": encoding,
                "sdk_funcs": sdk_funcs,
                "source": "sdk_string_map",
            })
            continue

        # Search SDK source files
        for file_path, text in sdk_file_contents.items():
            if string_val in text:
                # Find which SDK function uses this string
                for func_name, info in sdk_index.items():
                    if info.get("file") == file_path and string_val in info.get("strings", []):
                        matches.append({
                            "string": string_val,
                            "offset": offset,
                            "load_addr": LOAD_BASE + offset,
                            "encoding": encoding,
                            "sdk_funcs": [func_name],
                            "source": "sdk_source",
                        })
                        break
                break

    print(f"String matches: {len(matches)}")

    # For each match, find code references to the string address
    renamed = {}
    for i, m in enumerate(matches):
        if i % 10 == 0:
            print(f"  Processing {i}/{len(matches)}...")

        string_addr = m["load_addr"]
        sdk_funcs = m["sdk_funcs"]

        # Find code references to this string address
        refs = find_code_refs_to_address(section3, string_addr)
        if not refs:
            continue

        for ref_offset in refs:
            ref_addr = LOAD_BASE + ref_offset

            # Find the function containing this reference using binary search
            func = find_function_by_addr_range(all_funcs_sorted, ref_addr)
            if not func:
                continue

            func_name = func.get("name", "")
            func_addr = func.get("address", "")

            if func_name.startswith("FUN_") and func_addr and func_addr not in renamed:
                new_name = sdk_funcs[0] if len(sdk_funcs) == 1 else sdk_funcs[0]

                result = rename_function(func_addr, new_name)
                if isinstance(result, dict) and "error" not in result:
                    renamed[func_addr] = new_name
                    if len(renamed) <= 30:
                        print(f"  {func_name} -> {new_name} @ {func_addr} (string: {m['string'][:40]}, {m['encoding']})")

        if (i + 1) % 10 == 0:
            time.sleep(0.3)

    print(f"\n=== Summary ===")
    print(f"String matches: {len(matches)}")
    print(f"Functions renamed: {len(renamed)}")

    # Save results
    output = ROOT / "build" / "ghidra_reverse_renames.json"
    output.write_text(json.dumps({
        "matches": len(matches),
        "renamed": [{"address": k, "name": v} for k, v in renamed.items()],
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
