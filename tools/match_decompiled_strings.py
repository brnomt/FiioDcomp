#!/usr/bin/env python3
"""
match_decompiled_strings.py — Extract string references from decompiled code,
resolve them, and match against SDK strings to rename functions.
"""
import json, re, time, urllib.request, urllib.parse
from pathlib import Path
from collections import defaultdict

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


def resolve_string_at_addr(addr_str):
    """Read memory at address and try to parse as ASCII or UTF-16LE string."""
    result = _get("/inspect_memory_content", {"address": addr_str, "size": "256"})
    if result.startswith("ERROR"):
        return None
    try:
        data = json.loads(result)
        if isinstance(data, dict):
            if data.get("is_likely_string"):
                val = data.get("ascii_repr", "").strip()
                if val and val != '""':
                    return val
            # Try to parse from hex dump
            hex_dump = data.get("hex_dump", "")
            if hex_dump:
                # Parse hex bytes
                bytes_list = []
                for part in hex_dump.split():
                    try:
                        bytes_list.append(int(part, 16))
                    except:
                        pass
                if bytes_list:
                    # Try ASCII
                    ascii_str = ""
                    for b in bytes_list:
                        if b == 0:
                            break
                        if 32 <= b < 127:
                            ascii_str += chr(b)
                        else:
                            break
                    if len(ascii_str) >= 4:
                        return ascii_str
                    # Try UTF-16LE
                    utf16_str = ""
                    for i in range(0, len(bytes_list) - 1, 2):
                        lo, hi = bytes_list[i], bytes_list[i+1]
                        if lo == 0 and hi == 0:
                            break
                        if hi == 0 and 32 <= lo < 127:
                            utf16_str += chr(lo)
                        else:
                            break
                    if len(utf16_str) >= 4:
                        return utf16_str
    except:
        pass
    return None


def main():
    # Load decompiled code
    decomp = json.loads((ROOT / "build" / "all_decompilations.json").read_text(encoding="utf-8"))
    print(f"Loaded {len(decomp)} decompiled functions")

    # Load SDK string map
    sdk_string_map = json.loads((ROOT / "build" / "sdk_string_map_combined.json").read_text(encoding="utf-8"))
    print(f"Loaded {len(sdk_string_map)} SDK strings")

    # Extract string references from decompiled code
    # Pattern: s_<text>_<hex_addr> or just references to string addresses
    string_ref_pattern = re.compile(r's_[A-Za-z0-9_]+_(0x[0-9a-fA-F]+)')
    # Also look for direct address references that might be strings
    addr_ref_pattern = re.compile(r'\b(0x030[0-9a-fA-F]{5})\b')

    # Collect all unique string addresses referenced in decompiled code
    all_string_addrs = set()
    func_string_refs = defaultdict(set)  # func_name -> set of string addresses

    for func_name, info in decomp.items():
        code = info.get("code", "")
        # Find s_..._0xADDR patterns
        for m in string_ref_pattern.finditer(code):
            addr = m.group(1)
            all_string_addrs.add(addr)
            func_string_refs[func_name].add(addr)
        # Also find direct address references in the 0x030xxxxx range
        for m in addr_ref_pattern.finditer(code):
            addr = m.group(1)
            # Only consider if it's not a function address (not in our function list)
            all_string_addrs.add(addr)
            func_string_refs[func_name].add(addr)

    print(f"Unique string/data addresses referenced: {len(all_string_addrs)}")
    print(f"Functions with string refs: {len(func_string_refs)}")

    # Resolve string values for each address
    print("\nResolving string values...")
    addr_to_string = {}
    cache_file = ROOT / "build" / "string_resolution_cache.json"
    if cache_file.exists():
        addr_to_string = json.loads(cache_file.read_text(encoding="utf-8"))
        print(f"  Loaded {len(addr_to_string)} from cache")

    resolved = 0
    for i, addr in enumerate(sorted(all_string_addrs)):
        if addr in addr_to_string:
            continue
        if i % 100 == 0:
            print(f"  Resolving {i}/{len(all_string_addrs)}...")
        val = resolve_string_at_addr(addr)
        if val:
            addr_to_string[addr] = val
            resolved += 1
        time.sleep(0.05)

    # Save cache
    cache_file.write_text(json.dumps(addr_to_string, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"  Resolved {resolved} new strings, total: {len(addr_to_string)}")

    # Match strings to SDK
    print("\nMatching strings to SDK...")
    renamed = 0
    for func_name, addrs in func_string_refs.items():
        func_addr = decomp[func_name].get("address", "")
        if not func_addr:
            continue

        # Get all strings for this function
        func_strings = []
        for addr in addrs:
            s = addr_to_string.get(addr)
            if s:
                func_strings.append(s)

        if not func_strings:
            continue

        # Match against SDK
        best_match = None
        best_score = 0
        for s in func_strings:
            if s in sdk_string_map:
                sdk_func = sdk_string_map[s]
                # Score by string length (longer strings are more unique)
                score = len(s)
                if score > best_score:
                    best_score = score
                    best_match = sdk_func

        if best_match and best_score >= 6:
            result = rename_function(func_addr, best_match)
            if "error" not in result.lower():
                renamed += 1
                if renamed <= 50:
                    matched_strings = [s for s in func_strings if s in sdk_string_map]
                    print(f"  {func_name} -> {best_match} @ {func_addr}")
                    print(f"    Matched strings: {matched_strings[:3]}")

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by decompiled string matching: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
