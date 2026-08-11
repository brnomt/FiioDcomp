#!/usr/bin/env python3
"""
apply_cross_version_names.py — Rename high-confidence matches in the source
(older) program using names from the target (newer) program.

Usage:
    python tools/apply_cross_version_names.py sec3_3_6_0.bin \
        --matches build/fuzzy_match_sec3_3_6_0_bin_section_3_0x00081A14_bin.json \
        --threshold 0.9
"""
from __future__ import annotations

import argparse
import json
import urllib.request
import urllib.parse
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def api_post(endpoint: str, data: dict, timeout: int = 60) -> str:
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    resp = urllib.request.urlopen(req, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def switch(program: str) -> str:
    """Switch Ghidra to the target program; returns response text."""
    try:
        resp = urllib.request.urlopen(f"{BASE}/switch_program?program={program}", timeout=60)
        return resp.read().decode("utf-8", errors="replace")
    except Exception as e:
        return f"ERR: {e}"


def rename(address: str, new_name: str) -> str:
    """Rename in the CURRENT program. Caller must switch first."""
    try:
        return api_post("/rename_function_by_address", {
            "function_address": address,
            "new_name": new_name,
        }, timeout=60)
    except Exception as e:
        return f"ERR: {e}"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("program", help="Source program name (older, e.g. sec3_3_6_0.bin)")
    parser.add_argument("--matches", required=True, help="Path to fuzzy match JSON")
    parser.add_argument("--threshold", type=float, default=0.9)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    # Renames apply to the CURRENT program — always switch first.
    sw = switch(args.program)
    print(f"Switch to {args.program}: {sw[:120]}")
    if "switched_to" not in sw and "already open" not in sw:
        print("WARNING: switch may have failed; renames could hit the wrong program!")

    if not Path(args.matches).exists():
        print(f"Match file not found: {args.matches}")
        return
    raw = json.loads(Path(args.matches).read_text(encoding="utf-8"))
    matches = raw.get("matches", raw) if isinstance(raw, dict) else raw
    print(f"Matches loaded: {len(matches)}")

    # Filter: high confidence + target has a real (non-FUN_*) name
    renames = []
    for m in matches:
        score = float(m.get("score", 0))
        src_name = m.get("source_name", "")
        src_addr = m.get("source_address", "")
        tgt_name = m.get("target_name", "")
        if score < args.threshold:
            continue
        if tgt_name.startswith("FUN_"):
            continue  # no useful name to copy
        renames.append((src_addr, src_name, tgt_name, score))

    print(f"Renames to apply (score>={args.threshold}, named target): {len(renames)}\n")
    applied = 0
    skipped = 0
    for addr, old, new, score in sorted(renames, key=lambda r: -r[3]):
        if args.dry_run:
            print(f"  [DRY] {old}@{addr} -> {new}  (score={score})")
            applied += 1
            continue
        result = rename(addr, new)
        ok = '"status":"success"' in result or '"status": "success"' in result or '"success":true' in result
        status = "OK" if ok else "FAIL"
        print(f"  [{status}] {old}@{addr} -> {new}  (score={score}): {result[:80]}")
        if ok:
            applied += 1
        else:
            skipped += 1

    print(f"\nDone: {applied} applied, {skipped} failed")

    # Save log (append per-program, keep history) — skip on dry-run
    if args.dry_run:
        print("Dry run - log NOT written.")
        return
    out = BUILD / "cross_version_renames_log.json"
    if out.exists():
        try:
            history = json.loads(out.read_text(encoding="utf-8"))
        except Exception:
            history = {}
    else:
        history = {}
    history[args.program] = renames
    out.write_text(json.dumps(history, indent=2), encoding="utf-8")
    print(f"Log saved to: {out}")


if __name__ == "__main__":
    main()
