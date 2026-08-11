#!/usr/bin/env python3
"""
analyze_functions.py — Get all functions from Ghidra, analyze naming state,
and prepare for SDK-based matching.
"""
import urllib.request
import urllib.parse
import json
import re
import sys
from pathlib import Path

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=TIMEOUT)
    ct = resp.headers.get("Content-Type", "")
    data = resp.read().decode("utf-8")
    if "json" in ct:
        return json.loads(data)
    return data


def get_all_functions():
    """Get all functions with names and addresses."""
    # Use enhanced endpoint with high limit
    result = _get("/list_functions_enhanced", {"limit": "10000"})
    if isinstance(result, dict):
        return result.get("functions", [])
    return result


def main():
    print("Fetching all functions from Ghidra...")
    funcs = get_all_functions()
    print(f"Total functions: {len(funcs)}")

    # Categorize
    named = []
    unnamed = []
    rom_funcs = []
    fun_pattern = re.compile(r'^FUN_[0-9a-f]+$')

    for f in funcs:
        name = f.get("name", "")
        addr = f.get("address", "")
        if name.startswith("rom_"):
            rom_funcs.append(f)
        elif fun_pattern.match(name):
            unnamed.append(f)
        elif name.startswith("LAB_") or name.startswith("DAT_") or name.startswith("SUB_"):
            unnamed.append(f)
        else:
            named.append(f)

    print(f"  Named (user/system): {len(named)}")
    print(f"  ROM functions: {len(rom_funcs)}")
    print(f"  Unnamed (FUN_*): {len(unnamed)}")
    print(f"  Naming rate: {100 * (len(named) + len(rom_funcs)) / len(funcs):.1f}%")

    # Show some named functions
    print("\nSample named functions:")
    for f in named[:20]:
        print(f"  {f['name']:40s} @ {f['address']}")

    # Save function list for matching
    output = ROOT / "build" / "ghidra_functions.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps({
        "total": len(funcs),
        "named": named,
        "unnamed": unnamed,
        "rom": rom_funcs,
    }, indent=2), encoding="utf-8")
    print(f"\nSaved to: {output}")

    # Show unnamed sample
    print("\nSample unnamed functions:")
    for f in unnamed[:10]:
        print(f"  {f['name']:40s} @ {f['address']}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
