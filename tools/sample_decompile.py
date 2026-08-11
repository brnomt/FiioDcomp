#!/usr/bin/env python3
"""
sample_decompile.py — Decompile a sample of unnamed functions and look for
recognizable patterns (constants, register usage, call sequences) that can
be matched to SDK functions.
"""
import urllib.request, urllib.parse, json, re, time
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


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


def main():
    all_funcs = get_all_functions()
    unnamed = [f for f in all_funcs if f.get("name", "").startswith("FUN_")]

    # Sort by size (largest first — larger functions have more recognizable patterns)
    unnamed.sort(key=lambda f: f.get("size", 0), reverse=True)

    # Decompile top 30 unnamed functions
    print(f"Decompiling top 30 unnamed functions by size...")
    results = []
    for i, func in enumerate(unnamed[:30]):
        addr = func["address"]
        name = func["name"]
        size = func.get("size", 0)
        print(f"\n{'='*60}")
        print(f"[{i+1}/30] {name} @ {addr} (size={size})")
        print(f"{'='*60}")

        code = decompile_function(addr)
        if isinstance(code, str) and len(code) > 0:
            # Print first 60 lines
            lines = code.split("\n")
            for line in lines[:60]:
                print(line)
            if len(lines) > 60:
                print(f"  ... ({len(lines)-60} more lines)")

            results.append({
                "address": addr,
                "name": name,
                "size": size,
                "code": code[:5000]
            })
        else:
            print(f"  [No decompilation available]")

        time.sleep(0.2)

    # Save results
    out = ROOT / "build" / "sample_decompilation.json"
    out.write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nSaved to: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
