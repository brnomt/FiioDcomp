#!/usr/bin/env python3
"""
decompile_match_v2.py — Decompile unnamed functions, extract string LABEL
references (s_..._ADDR), resolve them to actual string values, and match
against SDK functions.

Key insight: Ghidra's decompiler shows string references as labels like
  s_totalFmfile____d_0300162c
not as inline "..." literals. We must resolve these labels.
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

# Cache for string label → value lookups
_string_cache = {}


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


def get_all_functions():
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        return result.get("functions", [])
    return []


def decompile_function(address):
    result = _get("/decompile_function", {"address": address})
    if isinstance(result, dict):
        return result.get("decompilation", result.get("code", result.get("result", "")))
    return str(result) if result else ""


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"address": address, "new_name": new_name})


def resolve_string_label(label: str) -> str | None:
    """Resolve a Ghidra string label like s_totalFmfile____d_0300162c to its value.

    Uses inspect_memory_content to read the actual bytes at the address.
    """
    if label in _string_cache:
        return _string_cache[label]

    # Extract address from label: s_..._0300162c → 0x0300162c
    m = re.search(r'_(0[0-9a-f]{6,8})$', label)
    if not m:
        return None

    addr_hex = f"0x{m.group(1)}"

    # Use inspect_memory_content to read the string
    result = _get("/inspect_memory_content", {"address": addr_hex, "size": "256"})
    if isinstance(result, dict) and "error" not in result:
        # Check if it's likely a string
        if result.get("is_likely_string"):
            # Extract the string from ascii_repr or hex_dump
            ascii_repr = result.get("ascii_repr", "")
            if ascii_repr:
                # Clean up the ascii representation
                # Remove non-printable chars at start/end
                val = ascii_repr.strip()
                if val:
                    _string_cache[label] = val
                    return val

        # Also try parsing hex dump for ASCII string
        hex_dump = result.get("hex_dump", "")
        if hex_dump:
            # Parse hex bytes
            hex_bytes = hex_dump.replace("\\n", " ").replace("\n", " ")
            try:
                raw = bytes.fromhex(hex_bytes.replace(" ", ""))
                # Find null terminator
                null_pos = raw.find(b'\x00')
                if null_pos > 3:
                    val = raw[:null_pos].decode('ascii', errors='replace')
                    if sum(1 for c in val if c.isprintable()) > len(val) * 0.5:
                        _string_cache[label] = val
                        return val
            except:
                pass

    _string_cache[label] = None
    return None


def extract_string_refs_from_decompilation(code: str) -> list[str]:
    """Extract string label references from decompiled code.

    Looks for patterns like:
      s_totalFmfile____d_0300162c
      s_Play_03001ad8
      DAT_0300162c (when used as string param)
    """
    # Match s_..._ADDR patterns (Ghidra string labels)
    refs = set()

    # Pattern: s_text_ADDR where ADDR is a hex address
    for m in re.finditer(r'\bs_([a-zA-Z0-9_]+?)_(0[0-9a-f]{6,8})\b', code):
        label = m.group(0)
        refs.add(label)

    # Also match inline string literals "..."
    for m in re.finditer(r'"((?:[^"\\]|\\.)*)"', code):
        s = m.group(1)
        if len(s) >= 4:
            refs.add(f'INLINE:"{s}"')

    return list(refs)


def main():
    # Load SDK index
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
    batch_size = 100
    total_batches = (len(unnamed) + batch_size - 1) // batch_size

    for batch_idx in range(total_batches):
        start = batch_idx * batch_size
        end = min(start + batch_size, len(unnamed))
        batch = unnamed[start:end]

        if batch_idx % 5 == 0:
            print(f"\nBatch {batch_idx + 1}/{total_batches} (functions {start}-{end})...")

        for func in batch:
            func_addr = func.get("address", "")
            func_name = func.get("name", "")

            if not func_addr or func_addr in renamed:
                continue

            # Decompile
            code = decompile_function(func_addr)
            if not code or len(code) < 20:
                continue

            # Extract string references
            string_refs = extract_string_refs_from_decompilation(code)
            if not string_refs:
                continue

            # Resolve string labels to values
            resolved_strings = []
            for ref in string_refs:
                if ref.startswith('INLINE:'):
                    resolved_strings.append(ref[8:].strip('"'))
                else:
                    val = resolve_string_label(ref)
                    if val and len(val) >= 4:
                        resolved_strings.append(val)

            if not resolved_strings:
                continue

            # Match resolved strings to SDK functions
            sdk_matches = {}
            for s in resolved_strings:
                if s in string_to_sdk_funcs:
                    for sf in string_to_sdk_funcs[s]:
                        sdk_matches[sf] = sdk_matches.get(sf, 0) + 1

            if not sdk_matches:
                continue

            # Pick the best match
            best_match = max(sdk_matches.items(), key=lambda x: x[1])
            best_name = best_match[0]
            best_score = best_match[1]

            if best_score >= 1:
                result = rename_function(func_addr, best_name)
                if isinstance(result, dict) and "error" not in result:
                    renamed[func_addr] = best_name
                    if len(renamed) <= 50:
                        print(f"  {func_name} -> {best_name} @ {func_addr} (score: {best_score}, strings: {resolved_strings[:3]})")

        time.sleep(0.3)

    print(f"\n=== Summary ===")
    print(f"Functions processed: {len(unnamed)}")
    print(f"Functions renamed: {len(renamed)}")

    output = ROOT / "build" / "ghidra_decompile_renames_v2.json"
    output.write_text(json.dumps({
        "processed": len(unnamed),
        "renamed": [{"address": k, "name": v} for k, v in renamed.items()],
    }, indent=2), encoding="utf-8")
    print(f"Saved to: {output}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
