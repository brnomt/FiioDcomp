#!/usr/bin/env python3
"""Run /bulk_fuzzy_match between two programs, parse dict response, save results."""
import argparse
import json
import urllib.request
import urllib.parse
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("source_program")
    parser.add_argument("target_program")
    parser.add_argument("--filter", default="")
    parser.add_argument("--threshold", type=float, default=0.5)
    parser.add_argument("--limit", type=int, default=1000)
    parser.add_argument("--out", default=None)
    args = parser.parse_args()

    params = urllib.parse.urlencode({
        "source_program": args.source_program,
        "target_program": args.target_program,
        "filter": args.filter,
        "threshold": str(args.threshold),
        "limit": str(args.limit),
    })
    print(f"Matching {args.source_program} -> {args.target_program} "
          f"(filter={args.filter!r}, threshold={args.threshold})")
    resp = urllib.request.urlopen(f"{BASE}/bulk_fuzzy_match?{params}", timeout=1200)
    raw = resp.read().decode("utf-8", errors="replace")
    data = json.loads(raw)
    matches = data.get("matches", data) if isinstance(data, dict) else data

    src = data.get("source_program", args.source_program)
    tgt = data.get("target_program", args.target_program)
    total_src = data.get("total_source_functions", "?")
    print(f"source={src} target={tgt} total_source_functions={total_src}")
    print(f"total matches: {len(matches)}")

    hi = [m for m in matches if float(m.get("score", 0)) >= 0.9]
    named_tgt = [m for m in matches if not m.get("target_name", "").startswith("FUN_")]
    print(f"high conf >=0.9: {len(hi)}")
    print(f"matched to named targets: {len(named_tgt)}")
    print("\nMatches to named targets:")
    for m in named_tgt:
        print(f"  {m.get('source_name')} -> {m.get('target_name')} score={m.get('score')}")

    out = args.out or f"fuzzy_match_{Path(src).stem}_{Path(tgt).stem}.json"
    (BUILD / out).write_text(json.dumps(data, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nSaved: {BUILD / out}")


if __name__ == "__main__":
    main()
