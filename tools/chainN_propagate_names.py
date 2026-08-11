#!/usr/bin/env python3
"""
chainN_propagate_names.py — Generic N-hop chain name propagation from v3.7.0
(651 named) down through any number of older versions.

Takes an ordered list of fuzzy match files, oldest-pair first:

    chainN --match build/fuzzy_match_v33_v34.json \
           --match build/fuzzy_match_v34_v35.json \
           --match build/fuzzy_match_v35_v36.json \
           --match build/fuzzy_match_v36_v8m_full.json \
           --program sec3_3_3_0.bin --threshold 0.7 --require-offset

Hop i maps (older_i -> newer_i). Names are harvested from the LAST match
file's targets (v3.7 names, non-FUN_*). The combo score = min of ALL hop
scores (names originate from v3.7, so the weakest link bounds confidence).
Each hop's src->tgt delta is AUTO-COMPUTED as the dominant (tgt - src) among
score>=0.9 matches of that hop. `--require-offset` verifies every hop sits at
the same physical location: older_i + delta_i == newer_i for all i.

NOTE: when a hop has a relink shift (segment table MOVEs), deltas vary per
function and offset-ok will reject most chain candidates. In that case lower
--threshold and drop --require-offset, or rely on direct matches only.

Usage:
    python tools/chainN_propagate_names.py \
        --match build/fuzzy_match_v33_v34.json \
        --match build/fuzzy_match_v34_v35.json \
        --match build/fuzzy_match_v35_v36.json \
        --match build/fuzzy_match_v36_v8m_full.json \
        --program sec3_3_3_0.bin \
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
    parser.add_argument("--match", action="append", required=True,
                        help="Fuzzy match JSON, oldest-pair first (repeat for each hop)")
    parser.add_argument("--program", default="sec3_3_3_0.bin", help="program to rename")
    parser.add_argument("--threshold", type=float, default=0.7,
                        help="Min combo score = min of all hop scores")
    parser.add_argument("--require-offset", action="store_true",
                        help="Only apply names where ALL hop offset checks hold")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    if len(args.match) < 2:
        print("FATAL: need at least 2 --match files")
        return

    hops = [load_matches(Path(p)) for p in args.match]
    n_hops = len(hops)

    # Per-hop dominant deltas
    deltas = []
    for i, m in enumerate(hops):
        d, n = dominant_delta(m)
        if d is None:
            print(f"FATAL: no dominant delta for hop {i}")
            return
        deltas.append(d)
        print(f"Hop {i} ({Path(args.match[i]).name}): delta={hex(d)} ({n} hi-conf matches)")

    # Names: harvest from LAST hop's SOURCE addresses (newest version, e.g.
    # v3.6 addrs in the v3.6->v3.7 match) keyed by those source addresses.
    last = hops[-1]
    newest_to_name = {}
    for m in last:
        tgt = m.get("target_name", "")
        if tgt.startswith("FUN_"):
            continue
        s = m.get("source_address", "")
        score = float(m.get("score", 0))
        if s and score > newest_to_name.get(s, (None, -1))[1]:
            newest_to_name[s] = (tgt, score)
    print(f"Newest-version source addrs with named targets: {len(newest_to_name)}")

    # Build intermediate hop maps: hop i: older_i addr (src) -> (newer_i addr, score)
    hop_maps = []  # hop_maps[i]: src_addr -> (tgt_addr, score) for hop i
    for m in hops:
        d = {}
        for x in m:
            s = x.get("source_address", "")
            t = x.get("target_address", "")
            score = float(x.get("score", 0))
            if s and t and score > d.get(s, (None, -1))[1]:
                d[s] = (t, score)
        hop_maps.append(d)

    candidates = []
    # Start from every src in hop 0. Track addrs = [src0, tgt0, tgt1, ...].
    # The LAST hop's source addr is addrs[n_hops-1]; its name lookup happens there.
    for src0, (tgt0, s0) in hop_maps[0].items():
        addrs = [src0, tgt0]
        scores = [s0]
        cur = tgt0
        for i in range(1, n_hops):
            if cur not in hop_maps[i]:
                cur = None
                break
            t, sc = hop_maps[i][cur]
            addrs.append(t)
            scores.append(sc)
            cur = t
        if cur is None:
            continue
        # cur == target of the last hop (newest addr). The name lives on the
        # last hop's SOURCE addr = addrs[n_hops-1] (e.g. v3.6 addr).
        last_src = addrs[n_hops - 1]
        if last_src not in newest_to_name:
            continue
        name, s_last = newest_to_name[last_src]
        scores.append(s_last)
        combo = min(scores)
        # Offset checks: for each hop i, addrs[i] + deltas[i] == addrs[i+1]
        offset_ok = True
        for i in range(n_hops):
            if addr_int(addrs[i]) < 0 or addr_int(addrs[i + 1]) < 0:
                offset_ok = False
                break
            if addr_int(addrs[i]) + deltas[i] != addr_int(addrs[i + 1]):
                offset_ok = False
                break
        candidates.append((src0, name, combo, scores, offset_ok))

    best = {}
    for src, name, combo, scores, ok in candidates:
        if src not in best or combo > best[src][0]:
            best[src] = (combo, name, scores, ok)

    named = [k for k, v in best.items() if not v[1].startswith("FUN_")]
    print(f"Oldest-version functions chained to named newest targets: {len(named)}")
    print(f"  with offset-ok (all {n_hops} hops same physical location): "
          f"{sum(1 for v in best.values() if not v[1].startswith('FUN_') and v[3])}")
    print(f"  combo >= {args.threshold}: "
          f"{sum(1 for v in best.values() if not v[1].startswith('FUN_') and v[0] >= args.threshold)}")

    sw = switch(args.program)
    print(f"Switch to {args.program}: {sw[:100]}")
    if "switched_to" not in sw and "already open" not in sw:
        print("WARNING: switch may have failed; renames could hit the wrong program!")

    applied = 0
    for src, (combo, name, scores, ok) in sorted(best.items(), key=lambda kv: -kv[1][0]):
        if name.startswith("FUN_") or combo < args.threshold:
            continue
        if args.require_offset and not ok:
            continue
        tag = "offset-ok" if ok else "OFFSET-MISMATCH"
        sc_str = ",".join(f"{s:.2f}" for s in scores)
        if args.dry_run:
            print(f"  [DRY] {src} -> {name}  (scores={sc_str}, combo={combo:.2f}, {tag})")
            applied += 1
            continue
        result = rename(src, name)
        ok_status = '"status":"success"' in result or '"success":true' in result
        status = "OK" if ok_status else "FAIL"
        print(f"  [{status}] {src} -> {name}  (scores={sc_str}, combo={combo:.2f}, {tag})")
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
    chained = {k: {"name": v[1], "combo_score": v[0], "hop_scores": v[2],
                    "offset_match": v[3]}
               for k, v in best.items() if not v[1].startswith("FUN_") and v[0] >= args.threshold}
    history[f"{args.program}.chainN"] = chained
    log.write_text(json.dumps(history, indent=2), encoding="utf-8")
    print(f"Log saved to: {log}")


if __name__ == "__main__":
    main()
