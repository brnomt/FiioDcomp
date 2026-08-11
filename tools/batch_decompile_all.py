#!/usr/bin/env python3
"""
batch_decompile_all.py — Batch decompile all unnamed functions and save to a file.
Then we can do offline matching against SDK source.
"""
import urllib.request, urllib.parse, json, re, time
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


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=300)
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

    # Batch decompile in groups of 50
    all_decomp = {}
    batch_size = 50
    for i in range(0, len(unnamed), batch_size):
        batch = unnamed[i:i+batch_size]
        addrs = ",".join(a for _, a in batch)
        print(f"  Batch {i//batch_size + 1}/{(len(unnamed)+batch_size-1)//batch_size}: {len(batch)} functions...")

        result = _post("/batch_decompile", {"functions": addrs})
        if result.startswith("ERROR"):
            print(f"    Error: {result[:200]}")
            # Fall back to individual decompilation
            for name, addr in batch:
                r = _get("/decompile_function", {"address": addr})
                if not r.startswith("ERROR"):
                    all_decomp[name] = {"address": addr, "code": r}
                time.sleep(0.1)
            continue

        # Parse batch result
        try:
            data = json.loads(result)
            if isinstance(data, dict):
                for key, val in data.items():
                    if isinstance(val, dict) and "decompilation" in val:
                        all_decomp[key] = {"address": val.get("address", ""), "code": val["decompilation"]}
                    elif isinstance(val, str):
                        all_decomp[key] = {"address": "", "code": val}
            elif isinstance(data, list):
                for item in data:
                    if isinstance(item, dict):
                        name = item.get("name", item.get("function", ""))
                        code = item.get("decompilation", item.get("code", ""))
                        addr = item.get("address", "")
                        if name and code:
                            all_decomp[name] = {"address": addr, "code": code}
        except:
            # Maybe it's plain text with function separators
            pass

        time.sleep(0.5)

    print(f"\nDecompiled {len(all_decomp)} functions")

    # Save to file
    out = ROOT / "build" / "all_decompilations.json"
    out.write_text(json.dumps(all_decomp, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    # Quick stats
    has_strings = 0
    has_calls = 0
    for name, info in all_decomp.items():
        code = info.get("code", "")
        if "s_" in code or "DAT_" in code:
            has_strings += 1
        if "FUN_" in code or "func_0x" in code:
            has_calls += 1

    print(f"Functions with string refs: {has_strings}")
    print(f"Functions with function calls: {has_calls}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
