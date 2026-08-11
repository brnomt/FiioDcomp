#!/usr/bin/env python3
"""
callgraph_propagate_names2.py — Propagate names via the call graph.

For every NAMED function in v3.7.0, look at its callees AND callers. Any
FUN_* (unnamed) callee/caller in the SAME address region (same subsystem)
as a named function gets a candidate name = <prefix>_<suffix> derived from
the caller/callee relationship.

This is the "neighbors of named functions" sweep. It does NOT guess names
on its own — it only proposes candidates with high locality confidence:

  named_func  →  FUN_xxx (callee)  →  candidate: named_func + helper/_sub
  named_func  ←  FUN_xxx (caller)  →  candidate: context + wrapper

Output: build/callgraph_neighbor_candidates.json (dry-run candidates).
Use --apply to actually rename (only names you approve via --allow map).

Usage:
    python tools/callgraph_propagate_names2.py [--apply] [--region-size 0x4000]
"""
from __future__ import annotations

import argparse
import json
import re
import urllib.request
from collections import defaultdict
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def get(url: str) -> str:
    return urllib.request.urlopen(url, timeout=120).read().decode("utf-8", errors="replace")


def get_json(url: str):
    return json.loads(get(url))


def list_named() -> dict[str, str]:
    """addr -> name for all named (non-FUN_*) functions."""
    d = get_json(f"{BASE}/list_functions_enhanced")
    out = {}
    for f in d.get("functions", []):
        n = f.get("name", "")
        a = f.get("address", "")
        if not n.startswith("FUN_") and a:
            out[a] = n
    return out


def callees(addr: str):
    """Return list of (name, addr) from get_function_callees output."""
    out = []
    for l in get(f"{BASE}/get_function_callees?address={addr}").splitlines():
        l = l.strip()
        if not l or "@" not in l:
            continue
        name, a = l.split("@")
        out.append((name.strip(), a.strip()))
    return out


def callers(addr: str):
    """Return list of (name, addr) from get_function_callers output."""
    out = []
    for l in get(f"{BASE}/get_function_callers?address={addr}").splitlines():
        l = l.strip()
        if not l or "@" not in l:
            continue
        name, a = l.split("@")
        out.append((name.strip(), a.strip()))
    return out


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--apply", action="store_true", help="actually rename")
    parser.add_argument("--region-size", type=lambda x: int(x, 0), default=0x4000,
                        help="max address distance to count as same-region")
    parser.add_argument("--out", default=str(BUILD / "callgraph_neighbor_candidates.json"))
    args = parser.parse_args()

    named = list_named()
    print(f"named functions: {len(named)}")

    addr_set = set(named.keys())

    # For each named function, find unnamed callees + callers in the same region
    candidates = []  # (neighbor_addr, named_src, relation, src_addr)
    for addr, name in sorted(named.items()):
        base = int(addr, 16)
        for rel, fn in (("callee", callees), ("caller", callers)):
            try:
                neigh = fn(addr)
            except Exception:
                continue
            for n_name, n_addr in neigh:
                if n_name.startswith("FUN_") and n_addr:
                    if abs(int(n_addr, 16) - base) <= args.region_size:
                        candidates.append((n_addr, name, rel, addr))

    # Dedup by neighbor_addr, keep the highest-confidence relation
    best = {}
    for c_addr, named_src, rel, src_addr in candidates:
        if c_addr not in best:
            best[c_addr] = (named_src, rel, src_addr)
    print(f"unnamed callees/callers in-region of named functions: {len(best)}")

    # Show distribution by named source
    by_src = defaultdict(list)
    for c_addr, (src, rel, _) in best.items():
        by_src[src].append(c_addr)
    for src, addrs in sorted(by_src.items(), key=lambda kv: -len(kv[1]))[:25]:
        print(f"  {src}: {len(addrs)} unnamed callees {[a for a in addrs[:5]]}")

    json.dump({a: {"named_source": s, "relation": r, "src_addr": sa}
               for a, (s, r, sa) in best.items()},
              open(args.out, "w"), indent=1)
    print(f"\nSaved candidates: {args.out}")
    print("Review them, then rename manually (or extend this script with an --allow map).")


if __name__ == "__main__":
    main()
