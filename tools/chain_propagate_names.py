#!/usr/bin/env python3
"""
chain_propagate_names.py — Chain-propagate function names from the newest
analyzed version (v3.7, 651 named) down through older versions using fuzzy
match files.

Chain: v3.5 -> v3.6 (fuzzy_match_v35_v36.json) and v3.6 -> v3.7
       (fuzzy_match_v36_v8m_full.json).

The src->tgt address delta is AUTO-COMPUTED as the dominant (tgt - src) among
high-confidence matches (for v3.5->v3.6 it is 0x03000268, because v3.5's
section_3 was imported at base 0 while v3.6/v3.7 are rebased). Override with
--delta. The offset check (src + delta == tgt) verifies the match sits at the
same physical location even when fuzzy scores are low.

Usage:
    python tools/chain_propagate_names.py \
        --old match  build/fuzzy_match_v35_v36.json \
        --new match  build/fuzzy_match_v36_v8m_full.json \
        --program    sec3_3_5_0.bin \
        --threshold  0.6
"""
from __future__ import annotations

import argparse
import json
import urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
# Default delta (v3.5 file-offset addr + 0x03000268 == v3.6 Ghidra addr),
# auto-computed from the match file unless overridden with --delta.
DEFAULT_DELTA = 0x03000268


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


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--old-match", required=True, help="v3.5->v3.6 match JSON")
    parser.add_argument("--new-match", required=True, help="v3.6->v3.7 match JSON")
    parser.add_argument("--program", default="sec3_3_5_0.bin", help="program to rename")
    parser.add_argument("--threshold", type=float, default=0.6,
                        help="Min combo score = min(direct, chain) score")
    parser.add_argument("--delta", type=lambda x: int(x, 0), default=None,
                        help="Override the src->tgt address delta (auto-computed if omitted)")
    parser.add_argument("--require-offset", action="store_true",
                        help="Only apply names where src+delta==tgt (same physical location)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    old_matches = load_matches(Path(args.old_match))
    new_matches = load_matches(Path(args.new_match))

    # Auto-compute delta: dominant (tgt - src) among score>=0.9 matches
    # (ignore -1 sentinel from unparseable addresses)
    from collections import Counter
    deltas = Counter()
    for m in old_matches:
        try:
            if float(m.get("score", 0)) >= 0.9:
                s = addr_int(m["source_address"])
                t = addr_int(m["target_address"])
                if s >= 0 and t >= 0:
                    deltas[t - s] += 1
        except Exception:
            pass
    if args.delta is not None:
        delta = args.delta
    elif deltas:
        delta = deltas.most_common(1)[0][0]
    else:
        delta = DEFAULT_DELTA
    print(f"Auto delta (dominant tgt-src @score>=0.9): {hex(delta)} "
          f"({deltas.get(delta, 0)} matches) [--delta to override]")

    # Build lookup: v3.6 address (hex string) -> (name, score) from v3.6->v3.7
    v36_to_name = {}
    for m in new_matches:
        tgt = m.get("target_name", "")
        if tgt.startswith("FUN_"):
            continue
        src_addr = m.get("source_address", "")
        score = float(m.get("score", 0))
        if src_addr and score > v36_to_name.get(src_addr, (None, -1))[1]:
            v36_to_name[src_addr] = (tgt, score)

    print(f"v3.6 addresses with named v3.7 targets: {len(v36_to_name)}")

    # Chain: for each v3.5->v3.6 match, target addr (v3.6) -> name
    candidates = []
    for m in old_matches:
        src_addr = m.get("source_address", "")
        tgt_addr = m.get("target_address", "")
        score = float(m.get("score", 0))
        if tgt_addr in v36_to_name:
            name, chain_score = v36_to_name[tgt_addr]
            # Verify layout identity: v3.5 + delta == v3.6
            s = addr_int(src_addr)
            t = addr_int(tgt_addr)
            offset_ok = (s >= 0 and t >= 0 and s + delta == t)
            candidates.append((src_addr, name, score, chain_score, offset_ok))

    # Deduplicate by source addr: keep best by min(direct, chain) score
    # (names originate from v3.7, so the weaker link bounds confidence)
    best = {}
    for src, name, score, chain, ok in candidates:
        combo = min(score, chain)
        if src not in best or combo > best[src][0]:
            best[src] = (combo, name, score, chain, ok)

    named_cands = [k for k, (combo, nm, sc, ch, ok) in best.items() if not nm.startswith("FUN_")]
    print(f"v3.5 functions chained to named v3.7 targets: {len(named_cands)}")

    sw = switch(args.program)  # renames apply to the CURRENT program
    print(f"Switch to {args.program}: {sw[:100]}")
    if "switched_to" not in sw and "already open" not in sw:
        print("WARNING: switch may have failed; renames could hit the wrong program!")
    applied = 0
    for src, (combo, name, score, chain, ok) in sorted(best.items(), key=lambda kv: -kv[1][0]):
        if name.startswith("FUN_") or combo < args.threshold:
            continue
        if args.require_offset and not ok:
            continue
        tag = "offset-match" if ok else "OFFSET-MISMATCH"
        if args.dry_run:
            print(f"  [DRY] {src} -> {name}  (v3.5->3.6={score}, 3.6->3.7={chain}, combo={combo}, {tag})")
            applied += 1
            continue
        result = rename(src, name)
        ok_status = '"status":"success"' in result or '"success":true' in result
        status = "OK" if ok_status else "FAIL"
        print(f"  [{status}] {src} -> {name}  (v3.5->3.6={score}, 3.6->3.7={chain}, {tag}): {result[:60]}")
        if ok_status:
            applied += 1

    print(f"\nDone: {applied} applied to {args.program}")

    # Save log ONLY on a real run (dry-run must not clobber the history)
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
    # Log applied-only entries with named fields (v is (combo,name,score,chain,ok))
    chained = {k: {"name": v[1], "combo_score": v[0], "direct_score": v[2],
                    "chain_score": v[3], "offset_match": v[4]}
               for k, v in best.items() if not v[1].startswith("FUN_") and v[0] >= args.threshold}
    history[f"{args.program}.chained"] = chained
    log.write_text(json.dumps(history, indent=2), encoding="utf-8")
    print(f"Log saved to: {log}")


if __name__ == "__main__":
    main()
