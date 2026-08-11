#!/usr/bin/env python3
"""
revert_weak_chain_names.py — Revert chained renames whose v3.6->v3.7 chain
score was below the confidence floor (the fuzzy-matcher's low-score names are
unreliable, e.g. flac_bitstream_getbits_s placed in the vector area).

Reverts to FUN_<addr> in the CURRENT program. Run with --program to switch.
"""
from __future__ import annotations

import argparse
import json
import urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def load(p):
    d = json.loads(Path(p).read_text(encoding="utf-8"))
    return d.get("matches", d) if isinstance(d, dict) else d


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
    parser.add_argument("--program", default="sec3_3_5_0.bin")
    parser.add_argument("--min-chain", type=float, default=0.6,
                        help="Revert names whose v3.6->v3.7 chain score is below this")
    parser.add_argument("--old-match", required=True, help="v3.5->v3.6 match JSON")
    parser.add_argument("--new-match", required=True, help="v3.6->v3.7 match JSON")
    parser.add_argument("--delta", type=lambda x: int(x, 0), default=0x03000268)
    args = parser.parse_args()

    old = load(Path(args.old_match))
    new = load(Path(args.new_match))

    v36 = {}
    for m in new:
        t = m.get("target_name", "")
        if t.startswith("FUN_"):
            continue
        sa = m.get("source_address", "")
        sc = float(m.get("score", 0))
        if sa and sc > v36.get(sa, (None, -1))[1]:
            v36[sa] = (t, sc)

    def ai(s):
        try:
            return int(s, 16)
        except Exception:
            return -1

    # Reproduce the apply that happened (direct>=0.7 + require-offset)
    applied = []
    for m in old:
        src = m.get("source_address", "")
        tgt = m.get("target_address", "")
        score = float(m.get("score", 0))
        if tgt in v36 and score >= 0.7 and ai(src) >= 0 and ai(tgt) >= 0 \
                and ai(src) + args.delta == ai(tgt):
            name, chain = v36[tgt]
            if not name.startswith("FUN_"):
                applied.append((src, name, score, chain))

    weak = [a for a in applied if a[3] < args.min_chain]
    print(f"Applied (old filter): {len(applied)}, weak chain (<{args.min_chain}): {len(weak)}")

    if not weak:
        print("Nothing to revert.")
        return

    sw = switch(args.program)
    print(f"Switch to {args.program}: {sw[:80]}")
    if "switched_to" not in sw and "already open" not in sw:
        print("WARNING: switch may have failed!")

    for src, name, score, chain in sorted(weak, key=lambda x: x[3]):
        fun = f"FUN_{src}"
        result = rename(src, fun)
        ok = '"status":"success"' in result or '"success":true' in result
        print(f"  [{'OK' if ok else 'FAIL'}] {src} {name} -> {fun}  (chain={chain}): {result[:60]}")

    print("Done. Save the program now.")


if __name__ == "__main__":
    main()
