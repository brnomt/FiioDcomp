#!/usr/bin/env python3
"""
decompile_match.py — Decompile unnamed functions from Ghidra, extract
referenced strings, and match them to SDK functions.

This is the most accurate approach because:
  1. The decompiler resolves all address computations (MOVW/MOVT, literal pools)
  2. We get ALL strings referenced by each function
  3. We match against the SDK source directly

Process:
  1. Get all unnamed functions from Ghidra
  2. Decompile each one
  3. Extract string references from the decompilation
  4. Search the SDK source for those strings
  5. Name the function based on the best match
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
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try:
                return json.loads(data)
            except:
                pass
        return data
    except Exception as e:
        return {"error": str(e)}


def get_all_functions():
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def decompile_function(address):
    """Decompile function at address. Returns the decompiled C code."""
    result = _get("/decompile_function", {"address": address})
    if isinstance(result, dict):
        return result.get("decompilation", result.get("code", result.get("result", "")))
    return str(result)


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def extract_strings_from_decompilation(code: str) -> list[str]:
    """Extract string literals from decompiled C code."""
    if not code:
        return []
    # Match "..." string literals (handle escaped quotes)
    strings = re.findall(r'"((?:[^"\\]|\\.)*)"', code)
    # Filter: only keep strings >= 4 chars, skip format-only strings
    result = []
    for s in strings:
        s_unescaped = s.replace('\\"', '"').replace('\\n', '\n').replace('\\t', '\t').replace('\\\\', '\\')
        if len(s_unescaped) >= 4 and not s_unescaped.startswith('%') and s_unescaped not in ('true', 'false', 'null'):
            result.append(s_unescaped)
    return result


def main():
    # Load SDK source files
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

    # Load SDK function index
    sdk_index = json.loads((ROOT / "build" / "sdk_function_index.json").read_text(encoding="utf-8"))

    # Build string -> SDK function map
    string_to_sdk_funcs = {}
    for func_name, info in sdk_index.items():
        for s in info.get("strings", []):
            if len(s) >= 4:
                string_to_sdk_funcs.setdefault(s, []).append(func_name)
    print(f"SDK string->function map: {len(string_to_sdk_funcs)} strings")

    # Get all unnamed functions
    print("Fetching functions from Ghidra...")
    all_funcs = get_all_functions()
    unnamed = [f for f in all_funcs if f.get("name", "").startswith("FUN_")]
    print(f"Unnamed functions: {len(unnamed)}")

    # Process in batches
    renamed = {}
    batch_size = 50
    total_batches = (len(unnamed) + batch_size - 1) // batch_size

    for batch_idx in range(total_batches):
        start = batch_idx * batch_size
        end = min(start + batch_size, len(unnamed))
        batch = unnamed[start:end]

        if batch_idx % 10 == 0:
            print(f"\nBatch {batch_idx + 1}/{total_batches} (functions {start}-{end})...")

        for func in batch:
            func_addr = func.get("address", "")
            func_name = func.get("name", "")

            if not func_addr or func_addr in renamed:
                continue

            # Decompile the function
            code = decompile_function(func_addr)
            if not code or len(code) < 20:
                continue

            # Extract strings from decompilation
            strings = extract_strings_from_decompilation(code)
            if not strings:
                continue

            # Match strings to SDK functions
            sdk_matches = {}
            for s in strings:
                # Check SDK string map
                if s in string_to_sdk_funcs:
                    for sf in string_to_sdk_funcs[s]:
                        sdk_matches[sf] = sdk_matches.get(sf, 0) + 1

                # Also search SDK source files
                for file_path, text in sdk_file_contents.items():
                    if s in text:
                        # Find which function in this file uses this string
                        for fn, info in sdk_index.items():
                            if info.get("file") == file_path and s in info.get("strings", []):
                                sdk_matches[fn] = sdk_matches.get(fn, 0) + 1
                                break

            if not sdk_matches:
                continue

            # Pick the best match (most string matches)
            best_match = max(sdk_matches.items(), key=lambda x: x[1])
            best_name = best_match[0]
            best_score = best_match[1]

            # Only rename if score >= 2 (at least 2 string matches)
            if best_score >= 2:
                result = rename_function(func_addr, best_name)
                if isinstance(result, dict) and "error" not in result:
                    renamed[func_addr] = best_name
                    if len(renamed) <= 30:
                        print(f"  {func_name} -> {best_name} @ {func_addr} (score: {best_score}, strings: {strings[:3]})")

        # Rate limit between batches
        time.sleep(0.5)

    print(f"\n=== Summary ===")
    print(f"Functions processed: {len(unnamed)}")
    print(f"Functions renamed: {len(renamed)}")

    # Save results
    output = ROOT / "build" / "ghidra_decompile_renames.json"
    output.write_text(json.dumps({
        "processed": len(unnamed),
        "renamed": [{"address": k, "name": v} for k, v in renamed.items()],
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
