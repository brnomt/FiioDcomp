#!/usr/bin/env python3
"""
match_structure_v2.py — Improved structural matcher against the Rockchip SDK.

Weaknesses of the v1 matcher (match_structure.py):
  - counts if/while/for in the C text, which differ wildly between Ghidra
    decompiler output style and the SDK source style
  - no use of callee information, which is the strongest signal

v2 signals (weighted):
  1. Signature: param_count exact + return_type match   (strong)
  2. Callee overlap: binary's named callees vs SDK's callee names
     (the 712 already-named functions are the anchor vocabulary)  (strongest)
  3. Distinctive constants (>=0x100) shared                       (strong)
  4. Code-size ratio                                             (medium)
  5. Control-flow counts (only as tiebreak)                      (weak)

Matching is per-binary-function, with a uniqueness constraint: an SDK
function is only assigned if its best binary match is unambiguous.

Usage:
    python tools/match_structure_v2.py [--threshold 40] [--top 8] [--apply]
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import time
import urllib.request
from collections import defaultdict
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# ---- SDK data ----
sdk_features = json.loads((BUILD / "sdk_features.json").read_text(encoding="utf-8"))
sdk_callees = json.loads((BUILD / "sdk_callees.json").read_text(encoding="utf-8"))

# Normalize SDK callees: HifiFileOpen -> ['DelayUs2', 'bb_printf1']
SDK_CALLEES = {}
for name, cals in sdk_callees.items():
    if isinstance(cals, list):
        SDK_CALLEES[name] = [c for c in cals if isinstance(c, str)]
    elif isinstance(cals, dict):
        SDK_CALLEES[name] = list(cals.keys())


def get_json(url: str):
    return json.loads(urllib.request.urlopen(url, timeout=120).read().decode("utf-8", errors="replace"))


def get_text(url: str) -> str:
    return urllib.request.urlopen(url, timeout=120).read().decode("utf-8", errors="replace")


def named_funcs() -> dict[str, str]:
    """addr -> name for all named functions."""
    d = get_json(f"{BASE}/list_functions_enhanced")
    return {f["address"]: f["name"] for f in d.get("functions", [])
            if not f.get("name", "").startswith("FUN_")}


def decompile(addr: str) -> str:
    return get_text(f"{BASE}/decompile_function?address={addr}")


def callees_of(addr: str):
    out = []
    for l in get_text(f"{BASE}/get_function_callees?address={addr}").splitlines():
        l = l.strip()
        if l and "@" in l:
            out.append(l.split("@")[0].strip())
    return out


def extract_sig(code: str):
    m = re.match(r'[\w\s*]+\s+FUN_\w+\s*\(([^)]*)\)', code)
    params = 0
    if m:
        ps = [p for p in m.group(1).split(",") if p.strip() and p.strip() != "void"]
        params = len(ps)
    ret_void = 1 if re.match(r'\bvoid\b\s+FUN_', code) else 0
    return params, ret_void


def extract_constants(code: str) -> set:
    consts = set()
    for m in re.finditer(r'\b(0x[0-9a-fA-F]{2,8})\b', code):
        v = int(m.group(1), 16)
        if v >= 0x100 and v not in (0xffffffff, 0x7fffffff, 0x80000000):
            consts.add(v)
    return consts


def score_binary(bin_params, bin_void, bin_consts, bin_size, bin_callees,
                 sdk_name):
    feat = sdk_features.get(sdk_name)
    if not feat:
        return 0.0
    s = 0.0

    # 1. Signature (max 20)
    sdk_params = feat.get("param_count", 0)
    if bin_params == sdk_params:
        s += 15
    elif abs(bin_params - sdk_params) <= 1:
        s += 8
    sdk_void = 1 if str(feat.get("return_type", "")).lower() == "void" else 0
    if bin_void == sdk_void:
        s += 5

    # 2. Callee overlap (max 40) — strongest
    sdk_cals = SDK_CALLEES.get(sdk_name, [])
    if bin_callees and sdk_cals:
        sdk_set = set(sdk_cals)
        bin_set = set(bin_callees)
        inter = bin_set & sdk_set
        if inter:
            s += 25 + 15 * (len(inter) / max(len(sdk_set), 1))
        else:
            # binary has SDK-vocab callees but none match this SDK func
            s -= 10
    elif not bin_callees:
        # no callee info on either side — neutral
        pass

    # 3. Constants (max 25)
    sdk_consts = set(feat.get("constants", []) or [])
    if bin_consts and sdk_consts:
        inter = bin_consts & sdk_consts
        if inter:
            s += 15 + 10 * (len(inter) / max(len(sdk_consts), 1))

    # 4. Code size ratio (max 15)
    sdk_size = feat.get("code_size", 0) or 0
    if bin_size > 0 and sdk_size > 0:
        ratio = min(bin_size, sdk_size) / max(bin_size, sdk_size)
        s += 15 * ratio

    # 5. Call count proximity (max 10)
    bc = feat.get("calls", 0)
    if bc > 0:
        s += min(10, bc * 1.5)

    return s


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--threshold", type=float, default=35.0)
    parser.add_argument("--top", type=int, default=6, help="candidates per binary func")
    parser.add_argument("--apply", action="store_true")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--limit", type=int, default=0, help="max binary funcs (0=all)")
    args = parser.parse_args()

    named = named_funcs()
    name_to_addr = {v: k for k, v in named.items()}
    print(f"named anchors: {len(named)}")

    # Module map: sdk_func name -> (sdk module source file, prefix)
    # e.g. mbedtls_mpi_div_mpi -> mbedtls_mpi ; wwd_bus_init -> wwd
    def module_of(name: str) -> str:
        feat = sdk_features.get(name, {})
        src = str(feat.get("source_file", ""))
        # last path component, strip extension
        base = src.replace("\\", "/").split("/")[-1]
        base = re.sub(r"\.(c|h)$", "", base)
        return base

    # Enumerate all functions
    d = get_json(f"{BASE}/list_functions_enhanced")
    allf = d.get("functions", [])
    funs = [f for f in allf if f.get("name", "").startswith("FUN_")]
    print(f"unnamed FUN_* to match: {len(funs)}")
    if args.limit:
        funs = funs[:args.limit]

    # SDK vocabulary of callee names (for overlap check)
    sdk_vocab = set(SDK_CALLEES.keys())
    # module of each already-named binary function (prefix before _ or first word)
    named_modules = {}
    for nm in named.values():
        m = re.match(r'^([a-zA-Z]+)', nm)
        if m:
            named_modules.setdefault(m.group(1).lower(), 0)
            named_modules[m.group(1).lower()] += 1

    results = []
    t0 = time.time()
    for i, f in enumerate(funs):
        addr = f["address"]
        try:
            code = decompile(addr)
        except Exception:
            continue
        if len(code) < 50:
            continue
        params, ret_void = extract_sig(code)
        consts = extract_constants(code)
        try:
            bcal = callees_of(addr)
        except Exception:
            bcal = []
        bcal_sdk = [c for c in bcal if c in sdk_vocab]
        bin_size = len(code)

        # MODULE SIGNAL: binary calls to already-named funcs -> module prefixes
        bin_call_names = []
        for m in re.finditer(r'\b([a-zA-Z_]\w*)\(', code):
            cname = m.group(1)
            if cname in named.values() and not cname.startswith(("FUN_", "LAB_", "DAT_")):
                bin_call_names.append(cname)
        bin_module_prefixes = set()
        for c in bin_call_names:
            pm = re.match(r'^([a-zA-Z]+)', c)
            if pm:
                bin_module_prefixes.add(pm.group(1).lower())

        # score against all SDK functions
        scored = []
        for sdk_name in sdk_features:
            s = score_binary(params, ret_void, consts, bin_size, bcal_sdk, sdk_name)
            # module bonus: SDK candidate's module prefix in binary's call prefixes
            sm = re.match(r'^([a-zA-Z]+)', sdk_name)
            if sm and sm.group(1).lower() in bin_module_prefixes:
                s += 12
            elif sm and sm.group(1).lower() in named_modules and not bin_module_prefixes:
                pass  # no info
            if s >= args.threshold:
                scored.append((s, sdk_name))
        if not scored:
            continue
        scored.sort(reverse=True)
        top = scored[:args.top]
        results.append({
            "binary_addr": addr,
            "binary_func": f["name"],
            "params": params,
            "callees": bcal_sdk[:8],
            "calls_named": bin_call_names[:8],
            "candidates": [{"sdk": n, "score": round(sc, 1)} for sc, n in top],
            "best_score": top[0][0],
        })
        if (i + 1) % 200 == 0:
            print(f"  {i+1}/{len(funs)} ({time.time()-t0:.0f}s)", flush=True)

    print(f"\nscored binary functions: {len(results)}")

    # Uniqueness: for each SDK function keep only its best binary match
    # and only if the top-2 binary candidates for that SDK are well separated
    sdk_to_bins = defaultdict(list)
    for r in results:
        best = r["candidates"][0]
        sdk_to_bins[best["sdk"]].append((best["score"], r["binary_addr"]))

    final = []
    for sdk, bins in sdk_to_bins.items():
        bins.sort(reverse=True)
        if len(bins) == 1:
            final.append((bins[0][1], sdk, bins[0][0], 1.0))
        else:
            best_sc, second_sc = bins[0][0], bins[1][0]
            if best_sc > second_sc * 1.25:  # clearly the best
                final.append((bins[0][1], sdk, best_sc, second_sc / best_sc if best_sc else 0))

    final.sort(key=lambda x: -x[2])
    print(f"unique SDK assignments: {len(final)}")

    out = BUILD / "structural_matches_v2.json"
    out.write_text(json.dumps({
        "threshold": args.threshold,
        "matches": [{"binary_addr": a, "sdk_func": n, "score": round(s, 1), "margin": round(m, 2)}
                    for a, n, s, m in final],
        "all_scored": results,
    }, indent=1), encoding="utf-8")
    print(f"Saved: {out}")

    print("\nTop 40 (unique, by score):")
    for a, n, s, m in final[:40]:
        print(f"  {a} -> {n} (score={s:.1f}, margin={m:.2f})")

    if args.apply:
        print("\nApplying renames...")
        renamed = 0
        for a, n, s, m in final:
            try:
                body = json.dumps({"function_address": a, "new_name": n}).encode()
                req = urllib.request.Request(f"{BASE}/rename_function_by_address", data=body,
                                             headers={"Content-Type": "application/json"}, method="POST")
                resp = urllib.request.urlopen(req, timeout=60).read().decode()
                if "success" in resp:
                    renamed += 1
            except Exception:
                pass
        print(f"renamed: {renamed}")


if __name__ == "__main__":
    main()
