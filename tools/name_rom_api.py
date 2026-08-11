#!/usr/bin/env python3
"""
name_rom_api.py — Parse rom_api.h and rename ROM API functions in Ghidra.
Also creates functions at addresses that don't have functions yet.
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
        data = resp.read().decode("utf-8")
        try:
            if data.startswith("{") or data.startswith("["): return json.loads(data)
        except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        data = resp.read().decode("utf-8")
        try:
            if data.startswith("{") or data.startswith("["): return json.loads(data)
        except: pass
        return data
    except Exception as e:
        return {"error": str(e)}


def parse_rom_api_h():
    """Parse rom_api.h to extract function names and addresses."""
    content = (ROOT / "firmware" / "rom_api.h").read_text(encoding="utf-8")
    entries = []
    for line in content.split("\n"):
        # Look for lines like: void *rom_alloc(uint32_t size);  /* 0x02feeedc */
        m = re.match(r'\s*\w+\s+\*?(\w+)\s*\([^)]*\)\s*;\s*/\*\s*(0x[0-9a-fA-F]+)\s*\*/', line)
        if m:
            entries.append({"name": m.group(1), "address": m.group(2)})
    return entries


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def create_function(address):
    """Create a function at the given address if it doesn't exist."""
    return _post("/create_function", {"address": address})


def main():
    entries = parse_rom_api_h()
    print(f"ROM API functions from rom_api.h: {len(entries)}")
    for e in entries:
        print(f"  {e['name']:30s} @ {e['address']}")

    # Get current function list
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        all_funcs = result.get("functions", [])
    else:
        all_funcs = []
    existing = {f["address"].lower().lstrip("0x"): f["name"] for f in all_funcs if isinstance(f, dict)}
    print(f"\nExisting functions in Ghidra: {len(existing)}")

    renamed = 0
    created = 0
    for e in entries:
        addr = e["address"].lower().lstrip("0x")
        full_addr = e["address"]
        name = e["name"]

        if addr in existing:
            # Function exists, rename it
            current_name = existing[addr]
            if current_name != name:
                result = rename_function(full_addr, name)
                if isinstance(result, dict) and "error" not in result:
                    renamed += 1
                    print(f"  RENAMED: {current_name} -> {name} @ {full_addr}")
                elif isinstance(result, str) and "error" not in result.lower():
                    renamed += 1
                    print(f"  RENAMED: {current_name} -> {name} @ {full_addr}")
                else:
                    err = result if isinstance(result, str) else result.get("error", str(result))
                    print(f"  FAILED: {name} @ {full_addr}: {err}")
        else:
            # Try to create function at this address
            result = create_function(full_addr)
            if isinstance(result, dict) and "error" not in result:
                created += 1
                # Now rename it
                rename_result = rename_function(full_addr, name)
                if isinstance(rename_result, dict) and "error" not in rename_result:
                    print(f"  CREATED+RENAMED: {name} @ {full_addr}")
                else:
                    print(f"  CREATED but rename failed: {name} @ {full_addr}")
            else:
                err = result if isinstance(result, str) else result.get("error", str(result))
                if "error" not in str(err).lower():
                    created += 1
                    rename_result = rename_function(full_addr, name)
                    print(f"  CREATED+RENAMED: {name} @ {full_addr}")
                else:
                    print(f"  CREATE FAILED: {name} @ {full_addr}: {err}")

        time.sleep(0.1)

    print(f"\n=== SUMMARY ===")
    print(f"Renamed: {renamed}")
    print(f"Created: {created}")

    # Final count
    result = _get("/list_functions_enhanced")
    if isinstance(result, dict):
        all_funcs = result.get("functions", [])
        named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
        print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
