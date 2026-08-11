#!/usr/bin/env python3
"""
cross_version_match.py — Paso 2: Cross-version function matching in Ghidra.

1. Waits for analysis of both programs to complete
2. Runs /bulk_fuzzy_match (source = older program, target = newer program)
3. Optionally runs /diff_functions on top matches
4. Saves results to build/

Usage:
    python tools/cross_version_match.py sec3_3_6_0.bin section_3_0x00081A14.bin
    python tools/cross_version_match.py sec3_3_6_0.bin section_3_0x00081A14.bin --filter FUN_ --threshold 0.7
"""
from __future__ import annotations

import argparse
import json
import time
import urllib.request
import urllib.parse
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def api_get(endpoint: str, params: dict | None = None, timeout: int = 300) -> str:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def wait_for_analysis(programs: list[str], timeout_s: int = 1800) -> None:
    """Poll /analysis_status until all programs finish analyzing."""
    print("Waiting for Ghidra analysis to complete...")
    deadline = time.time() + timeout_s
    while time.time() < deadline:
        try:
            raw = api_get("/analysis_status", timeout=30)
            data = json.loads(raw)
            progs = data.get("programs", [])
            busy = [p.get("name") for p in progs if p.get("analyzing")]
            done = [p.get("name") for p in progs if not p.get("analyzing")]
            if not busy:
                print("  All programs analyzed.")
                return
            print(f"  Still analyzing: {busy} (done: {len(done)})")
        except Exception as e:
            print(f"  poll error: {e}")
        time.sleep(10)
    print(f"WARNING: analysis still running after {timeout_s}s; continuing anyway")


def bulk_match(source: str, target: str, filter_str: str, threshold: float,
               offset: int = 0, limit: int = 500) -> list:
    params = {
        "source_program": source,
        "target_program": target,
        "filter": filter_str,
        "threshold": str(threshold),
        "offset": str(offset),
        "limit": str(limit),
    }
    raw = api_get("/bulk_fuzzy_match", params, timeout=600)
    try:
        data = json.loads(raw)
        if isinstance(data, list):
            return data
        for key in ("matches", "results", "functions"):
            if key in data:
                return data[key]
        return [data]
    except json.JSONDecodeError:
        print(f"Raw (non-JSON) response (first 500): {raw[:500]}")
        return []


def diff_functions(addr_a: str, addr_b: str, prog_a: str, prog_b: str) -> dict:
    params = {
        "address_a": addr_a,
        "address_b": addr_b,
        "program_a": prog_a,
        "program_b": prog_b,
    }
    raw = api_get("/diff_functions", params, timeout=300)
    try:
        return json.loads(raw)
    except json.JSONDecodeError:
        return {"raw": raw[:500]}


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("source_program", help="Older program name (e.g. sec3_3_6_0.bin)")
    parser.add_argument("target_program", help="Newer program name (e.g. section_3_0x00081A14.bin)")
    parser.add_argument("--filter", default="", help="Name filter (e.g. FUN_ for unnamed only)")
    parser.add_argument("--threshold", type=float, default=0.6)
    parser.add_argument("--limit", type=int, default=500)
    parser.add_argument("--no-wait", action="store_true")
    parser.add_argument("--diff-top", type=int, default=10, help="Run /diff_functions on top N matches")
    args = parser.parse_args()

    BUILD.mkdir(exist_ok=True)

    if not args.no_wait:
        wait_for_analysis([args.source_program, args.target_program])

    print(f"\n=== Bulk fuzzy match: {args.source_program} -> {args.target_program} ===")
    print(f"  filter={args.filter!r} threshold={args.threshold} limit={args.limit}")

    matches = bulk_match(args.source_program, args.target_program, args.filter,
                         args.threshold, 0, args.limit)
    print(f"  Matches: {len(matches)}")

    # Show summary
    total = len(matches)
    named_targets = 0
    high_conf = 0
    rows = []
    for m in matches[:200]:
        if not isinstance(m, dict):
            continue
        src = m.get("source_function", m.get("function", m.get("source", "")))
        dst = m.get("target_function", m.get("matched_function", m.get("target", "")))
        score = m.get("score", m.get("similarity", m.get("confidence", 0)))
        src_name = m.get("source_name", m.get("name", ""))
        dst_name = m.get("target_name", m.get("matched_name", ""))
        if "FUN_" not in str(dst_name):
            named_targets += 1
        try:
            if float(score) >= 0.9:
                high_conf += 1
        except (TypeError, ValueError):
            pass
        rows.append((src, dst, score, src_name, dst_name))

    print(f"  High-confidence (>=0.9): {high_conf}")
    print(f"  Matched to already-named targets: {named_targets}")
    print(f"\n  Top matches:")
    for src, dst, score, src_name, dst_name in rows[:30]:
        print(f"    {src} -> {dst}  score={score}  ({src_name} -> {dst_name})")

    # Save all matches
    out_file = BUILD / f"fuzzy_match_{args.source_program.replace('.', '_')}_{args.target_program.replace('.', '_')}.json"
    out_file.write_text(json.dumps(matches, indent=2), encoding="utf-8")
    print(f"\n  Saved all matches to: {out_file}")

    # Diff top matches
    if args.diff_top > 0 and rows:
        print(f"\n=== Function diffs for top {min(args.diff_top, len(rows))} matches ===")
        diffs = []
        for src, dst, score, _, _ in rows[:args.diff_top]:
            if not src or not dst:
                continue
            # Addresses may be strings like "03014af2" or "0x03014af2"
            addr_a = str(src).replace("0x", "")
            addr_b = str(dst).replace("0x", "")
            d = diff_functions(addr_a, addr_b, args.source_program, args.target_program)
            diffs.append({"source": src, "target": dst, "score": score, "diff": d})
            print(f"  {src} vs {dst}: {json.dumps(d)[:200]}")
        diff_file = BUILD / f"fuzzy_diffs_{args.source_program.replace('.', '_')}.json"
        diff_file.write_text(json.dumps(diffs, indent=2), encoding="utf-8")
        print(f"  Saved diffs to: {diff_file}")


if __name__ == "__main__":
    main()
