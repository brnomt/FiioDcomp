#!/usr/bin/env python3
"""
match_baseline_v2.py — Match the v1.2.5 BASELINE functions (the most legacy
code) against the SDK, using ONLY the strongest validation.

The baseline (462 functions present since v1.2.5) is the oldest, most
legacy code in the firmware. It was compiled with old toolchains and may
differ from the SDK reference. Therefore we are EXTRA conservative:

  - Only accept a match when the SDK says the candidate calls functions
    X,Y,Z and the binary function calls the ALREADY-NAMED X,Y,Z
    (callee-overlap validation — the strongest signal).
  - Require a minimum overlap size (>=1 named callee that matches).
  - Never trust raw structural score alone.
  - Output candidates for manual review before applying.

Usage:
    python tools/match_baseline_v2.py [--min-overlap 1] [--review]
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import urllib.request
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[0]))
import match_structure_v2 as mv2  # reuse SDK data + helpers

BASE = mv2.BASE
ROOT = mv2.ROOT
BUILD = mv2.BUILD


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--min-overlap", type=int, default=1)
    parser.add_argument("--min-score", type=float, default=0.0)
    parser.add_argument("--out", default=str(BUILD / "baseline_matches_v2.json"))
    parser.add_argument("--review", action="store_true",
                        help="decompile each candidate for manual review")
    args = parser.parse_args()

    # Baseline addresses from the lineage (regenerate via version_lineage.py)
    lin_file = BUILD / "function_lineage.json"
    if not lin_file.exists():
        print("FATAL: run tools/version_lineage.py first")
        return
    lineage = json.loads(lin_file.read_text(encoding="utf-8"))
    baseline = [a for a, e in lineage["functions"].items()
                if e.get("first_seen") == "1.2.5"]

    named = mv2.named_funcs()
    names_exist = set(named.values())
    # baseline still unnamed (live check against CURRENT Ghidra state):
    # a function is a target if its address is NOT among the named ones
    target = [a for a in baseline if a not in named]
    print(f"baseline total: {len(baseline)} | already named: "
          f"{len(baseline) - len(target)} | to match: {len(target)}")

    sdk_callees = mv2.SDK_CALLEES
    results = []
    for i, addr in enumerate(target):
        try:
            code = mv2.decompile(addr)
        except Exception:
            continue
        if len(code) < 50:
            continue
        params, ret_void = mv2.extract_sig(code)
        consts = mv2.extract_constants(code)
        try:
            bcal = mv2.callees_of(addr)
        except Exception:
            bcal = []
        # binary calls that are already-named (the anchor vocabulary)
        bin_named_calls = set(c for c in bcal if c in names_exist)

        best = None
        for sdk_name in mv2.sdk_features:
            s = mv2.score_binary(params, ret_void, consts, len(code), bcal, sdk_name)
            if s < args.min_score:
                continue
            sdk_cals = set(sdk_callees.get(sdk_name, []) or [])
            overlap = bin_named_calls & sdk_cals
            if len(overlap) >= args.min_overlap:
                if best is None or s > best[0]:
                    best = (s, sdk_name, overlap)
        if best:
            s, sdk_name, overlap = best
            results.append({
                "binary_addr": addr,
                "sdk_func": sdk_name,
                "score": round(s, 1),
                "overlap": sorted(overlap),
            })
            if args.review:
                print(f"\n=== {addr} -> {sdk_name} (score={s:.1f}) overlap={sorted(overlap)}")
                print(code[:350])

    results.sort(key=lambda x: -x["score"])
    (BUILD / "baseline_matches_v2.json").write_text(
        json.dumps(results, indent=1), encoding="utf-8")
    print(f"\nbaseline matches (callee-overlap >= {args.min_overlap}): {len(results)}")
    for r in results:
        print(f"  {r['binary_addr']} -> {r['sdk_func']} (score={r['score']}) "
              f"overlap={r['overlap']}")


if __name__ == "__main__":
    main()
