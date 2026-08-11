#!/usr/bin/env python3
"""
chain3_propagate_names.py — Chain-propagate function names from v3.7.0 (651
named) down THREE levels to v3.4.0 using three fuzzy match files:

    v3.4 -> v3.5  fuzzy_match_v34_v35.json       (targets = v3.5 addrs)
    v3.5 -> v3.6  fuzzy_match_v35_v36.json       (targets = v3.6 addrs)
    v3.6 -> v3.7  fuzzy_match_v36_v8m_full.json  (targets = v3.7 NAMES)

The src->tgt address delta for each pair is AUTO-COMPUTED as the dominant
(tgt - src) among score>=0.9 matches. Offset checks verify each link sits at
the same physical location. The combo score = min of the three link scores
(names originate from v3.7, so the weakest link bounds confidence).

Usage:
    python tools/chain3_propagate_names.py \
        --m45 build/fuzzy_match_v34_v35.json \
        --m56 build/fuzzy_match_v35_v36.json \
        --m67 build/fuzzy_match_v36_v8m_full.json \
        --program sec3_3_4_0.bin \
        --threshold 0.7 --require-offset
"""
from __future__ import annotations

import argparse
import json
import urllib.request
from collections import Counter
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def load_matches(path: Path):
    raw = json.loads(path.read_text(encoding="utf-8"))
    return raw.get("matches", raw) if isinstance(raw, dict) else raw


def addr_int(s: str) -> int:
    try:
        return int(s, 16)
    except Exception:
        return -1


def switch(program: str) -> str:
    try:
        resp = urllib.request.urlopen(f"{BASE}/switch_program?program={program}", timeout=60)
        return resp.read().decode("utf-8", errors="replace")
    except Exception as e:
        return f"ERR: {e}"


def rename(address: str, new_name: str) -> str:
    body = json.dumps({"function_address": address, "new_name": new_name}).encode("utf-8")
    req = urllib.request.Request(f"{BASE}/rename_function_by_address", data=body,
                                 headers={"Content-Type": "application/json"}, method="POST")
    resp = urllib.request.urlopen(req, timeout=60)
    return resp.read().decode("utf-8", errors="replace")


def dominant_delta(matches, floor=0.9):
    deltas = Counter()
    for m in matches:
        try:
            if float(m.get("score", 0)) >= floor:
                s = addr_int(m["source_address"])
                t = addr_int(m["target_address"])
                if s >= 0 and t >= 0:
                    deltas[t - s] += 1
        except Exception:
            pass
    if not deltas:
        return None
    return deltas.most_common(1)[0]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--m45", required=True, help="v3.4->v3.5 match JSON")
    parser.add_argument("--m56", required=True, help="v3.5->v3.6 match JSON")
    parser.add_argument("--m67", required=True, help="v3.6->v3.7 match JSON")
    parser.add_argument("--program", default="sec3_3_4_0.bin", help="program to rename")
    parser.add_argument("--threshold", type=float, default=0.7,
                        help="Min combo score = min of the three link scores")
    parser.add_argument("--require-offset", action="store_true",
                        help="Only apply names where all three offset checks hold")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    m45 = load_matches(Path(args.m45))
    m56 = load_matches(Path(args.m56))
    m67 = load_matches(Path(args.m67))

    d45, n45 = dominant_delta(m45)
    d56, n56 = dominant_delta(m56)
    d67, n67 = dominant_delta(m67)
    if d45 is None or d56 is None or d67 is None:
        print("FATAL: could not compute a dominant delta for every pair")
        return
    print(f"Delta 45 (v3.4->v3.5): {hex(d45)} ({n45} hi-conf matches)")
    print(f"Delta 56 (v3.5->v3.6): {hex(d56)} ({n56} hi-conf matches)")
    print(f"Delta 67 (v3.6->v3.7): {hex(d67)} ({n67} hi-conf matches)")

    # v3.7 names: keyed by v3.6 source addr (from m67)
    v36_to_name = {}
    for m in m67:
        tgt = m.get("target_name", "")
        if tgt.startswith("FUN_"):
            continue
        s = m.get("source_address", "")
        score = float(m.get("score", 0))
        if s and score > v36_to_name.get(s, (None, -1))[1]:
            v36_to_name[s] = (tgt, score)
    print(f"v3.6 addresses with named v3.7 targets: {len(v36_to_name)}")

    # v3.5 -> v3.6 map: keyed by v3.5 source addr (from m56), keep best score
    v35_to_v36 = {}
    for m in m56:
        s = m.get("source_address", "")
        t = m.get("target_address", "")
        score = float(m.get("score", 0))
        if s and t and score > v35_to_v36.get(s, (None, -1))[1]:
            v35_to_v36[s] = (t, score)
    print(f"v3.5 addresses with v3.6 link: {len(v35_to_v36)}")

    candidates = []
    for m in m45:
        src45 = m.get("source_address", "")
        tgt45 = m.get("target_address", "")
        s45 = float(m.get("score", 0))
        if tgt45 not in v35_to_v36:
            continue
        tgt56, s56 = v35_to_v36[tgt45]
        if tgt56 not in v36_to_name:
            continue
        name, s67 = v36_to_name[tgt56]
        s = addr_int(src45)
        t = addr_int(tgt45)
        u = addr_int(tgt56)
        ok = (s >= 0 and t >= 0 and u >= 0
              and s + d45 == t and t + d56 == u)
        combo = min(s45, s56, s67)
        candidates.append((src45, name, combo, s45, s56, s67, ok))

    best = {}
    for src, name, combo, s1, s2, s3, ok in candidates:
        if src not in best or combo > best[src][0]:
            best[src] = (combo, name, s1, s2, s3, ok)

    named = [k for k, v in best.items() if not v[1].startswith("FUN_")]
    print(f"v3.4 functions chained to named v3.7 targets: {len(named)}")
    print(f"  with offset-ok (all 3 links same physical location): "
          f"{sum(1 for v in best.values() if not v[1].startswith('FUN_') and v[5])}")
    print(f"  combo >= {args.threshold}: "
          f"{sum(1 for v in best.values() if not v[1].startswith('FUN_') and v[0] >= args.threshold)}")

    sw = switch(args.program)
    print(f"Switch to {args.program}: {sw[:100]}")
    if "switched_to" not in sw and "already open" not in sw:
        print("WARNING: switch may have failed; renames could hit the wrong program!")

    applied = 0
    for src, (combo, name, s1, s2, s3, ok) in sorted(best.items(), key=lambda kv: -kv[1][0]):
        if name.startswith("FUN_") or combo < args.threshold:
            continue
        if args.require_offset and not ok:
            continue
        tag = "offset-ok" if ok else "OFFSET-MISMATCH"
        if args.dry_run:
            print(f"  [DRY] {src} -> {name}  (45={s1}, 56={s2}, 67={s3}, combo={combo}, {tag})")
            applied += 1
            continue
        result = rename(src, name)
        ok_status = '"status":"success"' in result or '"success":true' in result
        status = "OK" if ok_status else "FAIL"
        print(f"  [{status}] {src} -> {name}  (45={s1}, 56={s2}, 67={s3}, combo={combo}, {tag})")
        if ok_status:
            applied += 1

    print(f"\nDone: {applied} applied to {args.program}")

    if args.dry_run:
        print("Dry run - log NOT written.")
        return
    history = {}
    log = BUILD / "cross_version_renames_log.json"
    if log.exists():
        try:
            history = json.loads(log.read_text(encoding="utf-8"))
            if isinstance(history, list):
                history = {"legacy": history}
        except Exception:
            history = {}
    chained = {k: {"name": v[1], "combo_score": v[0], "s45": v[2], "s56": v[3],
                    "s67": v[4], "offset_match": v[5]}
               for k, v in best.items() if not v[1].startswith("FUN_") and v[0] >= args.threshold}
    history[f"{args.program}.chain3"] = chained
    log.write_text(json.dumps(history, indent=2), encoding="utf-8")
    print(f"Log saved to: {log}")


if __name__ == "__main__":
    main()
