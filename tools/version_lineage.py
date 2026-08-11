#!/usr/bin/env python3
"""
version_lineage.py — Build the ancestor lineage for every v3.7.0 function.

For each function in v3.7.0 (the primary program), follow the fuzzy-match
chain backwards through all 21 adjacent version pairs to determine:
  - first_seen: the OLDEST version where this function exists (functions
    introduced in version X = changelog features of X)
  - changes: for each newer version, whether the function CHANGED there
    (score < 0.9 = shape changed / was edited)
  - ancestor chain: addr per version, with per-hop scores

This is the core of "changelog-anchored naming": a function whose first
appearance is v3.4.0 corresponds to a v3.4.0 changelog feature.

Usage:
    python tools/version_lineage.py [--out build/function_lineage.json]
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"

# Pairs oldest->newest: (match_file, older_version, newer_version)
# Each match file maps source(old) -> target(new).
PAIRS = [
    ("fuzzy_match_v125_v127.json", "1.2.5", "1.2.7"),
    ("fuzzy_match_v127_v13.json", "1.2.7", "1.3.0"),
    ("fuzzy_match_v13_v14.json", "1.3.0", "1.4.0"),
    ("fuzzy_match_v14_v146.json", "1.4.0", "1.4.6"),
    ("fuzzy_match_v146_v15.json", "1.4.6", "1.5.0"),
    ("fuzzy_match_v15_v162.json", "1.5.0", "1.6.2"),
    ("fuzzy_match_v162_v17.json", "1.6.2", "1.7.0"),
    ("fuzzy_match_v17_v18.json", "1.7.0", "1.8.0"),
    ("fuzzy_match_v18_v24.json", "1.8.0", "2.4.0"),
    ("fuzzy_match_v24_v25.json", "2.4.0", "2.5.0"),
    ("fuzzy_match_v25_v26.json", "2.5.0", "2.6.0"),
    ("fuzzy_match_v26_v27.json", "2.6.0", "2.7.0"),
    ("fuzzy_match_v27_v28.json", "2.7.0", "2.8.0"),
    ("fuzzy_match_v28_v30.json", "2.8.0", "3.0.0"),
    ("fuzzy_match_v30_v31.json", "3.0.0", "3.1.0"),
    ("fuzzy_match_v31_v32.json", "3.1.0", "3.2.0"),
    ("fuzzy_match_v32_v33.json", "3.2.0", "3.3.0"),
    ("fuzzy_match_v33_v34.json", "3.3.0", "3.4.0"),
    ("fuzzy_match_v34_v35.json", "3.4.0", "3.5.0"),
    ("fuzzy_match_v35_v36.json", "3.5.0", "3.6.0"),
    ("fuzzy_match_v36_v8m_full.json", "3.6.0", "3.7.0"),
]

VERSIONS = [p[1] for p in PAIRS] + ["3.7.0"]  # oldest -> newest


def load_matches(path: Path):
    raw = json.loads(path.read_text(encoding="utf-8"))
    return raw.get("matches", raw) if isinstance(raw, dict) else raw


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", default=str(BUILD / "function_lineage.json"))
    parser.add_argument("--min-score", type=float, default=0.0,
                        help="Min match score to consider a hop valid (default: any)")
    args = parser.parse_args()

    # Build hop maps: for each pair, target(new addr) -> (source(old addr), score)
    # We walk BACKWARDS: from newer addr to older addr.
    hops_back = []  # index i corresponds to PAIRS[i]: maps newer->older
    for fname, _, _ in PAIRS:
        m = load_matches(BUILD / fname)
        d = {}
        for x in m:
            t = x.get("target_address", "")
            s = x.get("source_address", "")
            sc = float(x.get("score", 0))
            if t and s and sc > d.get(t, (None, -1))[1]:
                d[t] = (s, sc)
        hops_back.append(d)
        print(f"{fname}: {len(d)} hops")

    # Source of v3.7 functions: the LAST pair's targets
    last = hops_back[-1]
    v37_addrs = sorted(last.keys())
    print(f"\nv3.7.0 functions with a v3.6 match: {len(v37_addrs)}")

    lineage = {}
    n_introduced = {}
    for addr in v37_addrs:
        entry = {"versions": {}, "first_seen": None, "changes": []}
        cur = addr
        # Walk from newest pair (3.6->3.7) down to oldest
        for i in range(len(hops_back) - 1, -1, -1):
            newer_ver = PAIRS[i][2]
            older_ver = PAIRS[i][1]
            hop = hops_back[i]
            if cur in hop:
                old_addr, score = hop[cur]
                entry["versions"][older_ver] = old_addr
                if score < args.min_score:
                    entry["changes"].append(newer_ver)
                cur = old_addr
            else:
                # No match in older version -> function introduced here
                entry["changes"].append(newer_ver)
                break
        # first_seen = oldest version where we have an addr
        if entry["versions"]:
            oldest_ver = VERSIONS[0]
            for v in VERSIONS:
                if v in entry["versions"]:
                    oldest_ver = v
                    break
            entry["first_seen"] = oldest_ver
            n_introduced[oldest_ver] = n_introduced.get(oldest_ver, 0) + 1
        else:
            entry["first_seen"] = "3.7.0"
            n_introduced["3.7.0"] = n_introduced.get("3.7.0", 0) + 1
        lineage[addr] = entry

    out = {"versions": VERSIONS, "functions": lineage}
    Path(args.out).write_text(json.dumps(out, indent=1), encoding="utf-8")
    print(f"\nSaved: {args.out}")

    print("\nFunctions first seen per version (introduced):")
    for v in VERSIONS:
        print(f"  {v}: {n_introduced.get(v, 0)}")


if __name__ == "__main__":
    main()
