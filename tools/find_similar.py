#!/usr/bin/env python3
"""
find_similar.py — Use Ghidra's find_similar_functions and get_bulk_function_hashes
to find structurally similar functions and propagate names.
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
        resp = urllib.request.urlopen(url, timeout=300)
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


def main():
    # Get all functions
    print("Getting all functions...")
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data

    named = [(f["name"], f["address"]) for f in all_funcs
             if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_")]
    unnamed = [(f["name"], f["address"]) for f in all_funcs
               if f.get("name", "").startswith("FUN_") and int(f.get("address", "0"), 16) >= 0x03000000]
    print(f"Named: {len(named)}, Unnamed: {len(unnamed)}")

    # Get bulk function hashes
    print("\nGetting bulk function hashes...")
    result = _get("/get_bulk_function_hashes")
    if result.startswith("ERROR"):
        print(f"Error: {result[:200]}")
        return 1

    # Parse hashes
    hashes = {}  # address -> hash
    try:
        data = json.loads(result)
        funcs_list = data.get("functions", []) if isinstance(data, dict) else data
        for item in funcs_list:
            if isinstance(item, dict):
                addr = item.get("address", "")
                hash_val = item.get("hash", "")
                inst_count = item.get("instruction_count", 0)
                if addr and hash_val and inst_count > 0:
                    hashes[addr] = hash_val
    except Exception as e:
        print(f"Parse error: {e}")

    print(f"Function hashes: {len(hashes)}")

    if not hashes:
        print("No hashes available, trying individual hash computation...")
        # Try getting hashes for a sample
        for name, addr in unnamed[:10]:
            result = _get("/get_function_hash", {"address": addr})
            print(f"  {name} @ {addr}: {result[:100]}")
            time.sleep(0.2)
        return 0

    # Group functions by hash
    hash_groups = defaultdict(list)
    for addr, hash_val in hashes.items():
        hash_groups[hash_val].append(addr)

    # Find groups with both named and unnamed functions
    print("\nFinding similar functions by hash...")
    renamed = 0
    for hash_val, addrs in hash_groups.items():
        if len(addrs) < 2:
            continue

        # Check if any address is in a named function
        named_in_group = []
        unnamed_in_group = []
        for addr in addrs:
            addr_int = int(addr, 16) if not addr.startswith("0x") else int(addr, 16)
            addr_str = f"0x{addr_int:08x}" if not addr.startswith("0x") else addr

            for n, a in named:
                if a.lower().lstrip("0x") == addr.lower().lstrip("0x"):
                    named_in_group.append((n, addr_str))
            for n, a in unnamed:
                if a.lower().lstrip("0x") == addr.lower().lstrip("0x"):
                    unnamed_in_group.append((n, addr_str))

        if named_in_group and unnamed_in_group:
            # We can propagate the name!
            for bin_name, bin_addr in named_in_group:
                for un_name, un_addr in unnamed_in_group:
                    result = rename_function(un_addr, bin_name)
                    if "error" not in result.lower():
                        renamed += 1
                        print(f"  RENAMED: {un_name} -> {bin_name} @ {un_addr} (hash match)")

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by hash matching: {renamed}")

    # Final count
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named_count = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named_count} ({100*named_count/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
