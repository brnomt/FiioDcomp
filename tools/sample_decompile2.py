#!/usr/bin/env python3
"""
sample_decompile2.py — Decompile unnamed firmware functions (address >= 0x03000000)
sorted by size, skipping ROM functions.
"""
import urllib.request, urllib.parse, json, re, time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
FW_BASE = 0x03000000


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=120)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try: return json.loads(data)
            except: pass
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
        return result.get("decompilation", result.get("code", str(result)))
    return str(result)


def get_callees(address):
    result = _get("/get_function_callees", {"address": address})
    callees = []
    if isinstance(result, str):
        for line in result.strip().split("\n"):
            parts = line.split()
            if len(parts) >= 2:
                callees.append({"name": parts[0], "address": parts[-1]})
    elif isinstance(result, dict):
        items = result.get("callees", result.get("functions", []))
        if isinstance(items, list):
            callees = items
    elif isinstance(result, list):
        callees = result
    return callees


def main():
    all_funcs = get_all_functions()

    # Filter: only firmware functions (address >= 0x03000000), unnamed, with size > 0
    unnamed = []
    for f in all_funcs:
        name = f.get("name", "")
        addr_str = f.get("address", "0")
        size = f.get("size", 0)
        if not name.startswith("FUN_"):
            continue
        try:
            addr = int(addr_str, 16)
        except:
            continue
        if addr < FW_BASE:
            continue
        if size == 0:
            continue
        unnamed.append(f)

    # Sort by size descending
    unnamed.sort(key=lambda f: f.get("size", 0), reverse=True)

    print(f"Unnamed firmware functions with size > 0: {len(unnamed)}")
    print(f"Top 20 by size:\n")
    for f in unnamed[:20]:
        print(f"  {f['name']} @ {f['address']} size={f.get('size', 0)}")
    print()

    # Decompile top 20
    results = []
    for i, func in enumerate(unnamed[:20]):
        addr = func["address"]
        name = func["name"]
        size = func.get("size", 0)
        print(f"\n{'='*70}")
        print(f"[{i+1}/20] {name} @ {addr} (size={size})")
        print(f"{'='*70}")

        # Get callees
        callees = get_callees(addr)
        callee_names = [c.get("name", "") for c in callees if isinstance(c, dict)]
        if callee_names:
            print(f"Callees: {callee_names}")

        # Decompile
        code = decompile_function(addr)
        if isinstance(code, str) and len(code) > 0:
            lines = code.split("\n")
            for line in lines[:80]:
                print(line)
            if len(lines) > 80:
                print(f"  ... ({len(lines)-80} more lines)")

            results.append({
                "address": addr, "name": name, "size": size,
                "callees": callee_names,
                "code": code[:8000]
            })
        else:
            print(f"  [No decompilation available]")

        time.sleep(0.3)

    out = ROOT / "build" / "sample_decompilation2.json"
    out.write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nSaved to: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
