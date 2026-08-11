#!/usr/bin/env python3
"""
batch_decompile_all2.py — Batch decompile all unnamed functions using GET query params.
"""
import urllib.request, urllib.parse, json, time
from pathlib import Path

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


def main():
    # Get all functions
    print("Getting all functions...")
    result = _get("/list_functions_enhanced")
    data = json.loads(result)
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data

    unnamed = [(f["name"], f["address"]) for f in all_funcs
               if f.get("name", "").startswith("FUN_") and int(f.get("address", "0"), 16) >= 0x03000000]
    print(f"Unnamed firmware functions: {len(unnamed)}")

    all_decomp = {}
    batch_size = 30  # smaller batches to avoid URL length limits
    total_batches = (len(unnamed) + batch_size - 1) // batch_size

    for i in range(0, len(unnamed), batch_size):
        batch = unnamed[i:i+batch_size]
        names = ",".join(n for n, _ in batch)
        batch_num = i // batch_size + 1
        print(f"  Batch {batch_num}/{total_batches}: {len(batch)} functions...", end="", flush=True)

        result = _get("/batch_decompile", {"functions": names})
        if result.startswith("ERROR"):
            print(f" Error: {result[:100]}")
            # Fall back to individual
            for name, addr in batch:
                r = _get("/decompile_function", {"address": addr})
                if not r.startswith("ERROR"):
                    all_decomp[name] = {"address": addr, "code": r}
                time.sleep(0.1)
            continue

        try:
            data = json.loads(result)
            if isinstance(data, dict):
                for name, code in data.items():
                    # Find the address for this name
                    addr = ""
                    for n, a in batch:
                        if n == name:
                            addr = a
                            break
                    all_decomp[name] = {"address": addr, "code": code}
                print(f" OK ({len(data)} decompiled)")
            else:
                print(f" Unexpected format")
        except Exception as e:
            print(f" Parse error: {e}")

        time.sleep(0.3)

    print(f"\nDecompiled {len(all_decomp)} functions total")

    # Save to file
    out = ROOT / "build" / "all_decompilations.json"
    out.write_text(json.dumps(all_decomp, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    # Quick stats
    has_strings = 0
    has_calls = 0
    has_both = 0
    for name, info in all_decomp.items():
        code = info.get("code", "")
        has_s = "s_" in code or "DAT_" in code
        has_c = "FUN_" in code or "func_0x" in code
        if has_s: has_strings += 1
        if has_c: has_calls += 1
        if has_s and has_c: has_both += 1

    print(f"Functions with data/string refs: {has_strings}")
    print(f"Functions with function calls: {has_calls}")
    print(f"Functions with both: {has_both}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
