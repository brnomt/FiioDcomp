#!/usr/bin/env python3
"""
check_decompilation_status.py — Current v3.7.0 decompilation status.

Queries the Ghidra MCP server live (authoritative), falling back to the frozen
build/all_decompilations.json cache when the server is unreachable.

Usage:
    python tools/check_decompilation_status.py [--program section_3_0x00081A14.bin]
"""
from __future__ import annotations

import argparse
import json
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
BASE = "http://127.0.0.1:8089"


def api_get(url: str, timeout: int = 60) -> str:
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def live_status(program: str) -> dict | None:
    try:
        # Switch to the target program
        api_get(f"{BASE}/switch_program?program={program}", timeout=60)
        # Total function count
        raw = api_get(f"{BASE}/get_function_count", timeout=60)
        total = json.loads(raw).get("function_count", 0)
        # Enhanced list for named vs unnamed
        raw = api_get(f"{BASE}/list_functions_enhanced", timeout=180)
        data = json.loads(raw)
        funcs = data.get("functions", data) if isinstance(data, dict) else data
        named = [f for f in funcs if isinstance(f, dict) and not f.get("name", "").startswith("FUN_")]
        thunks = [f for f in named if "thunk" in f.get("name", "").lower()]
        return {
            "source": "LIVE (Ghidra MCP)",
            "total": total,
            "named": len(named),
            "thunks": len(thunks),
            "unnamed": total - len(named),
        }
    except Exception as e:
        print(f"(Ghidra MCP unreachable: {e} — using frozen cache)\n")
        return None


def cache_status() -> dict:
    decomp_file = BUILD / "all_decompilations.json"
    if not decomp_file.exists():
        return {"source": "NO DATA — run decompile_missing.py", "total": 0, "named": 0, "thunks": 0, "unnamed": 0}
    data = json.loads(decomp_file.read_text(encoding="utf-8"))
    named = {k: v for k, v in data.items() if not k.startswith("FUN_")}
    unnamed = {k: v for k, v in data.items() if k.startswith("FUN_")}
    return {
        "source": "CACHE (build/all_decompilations.json — may be stale)",
        "total": len(data),
        "named": len(named),
        "thunks": 0,
        "unnamed": len(unnamed),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--program", default="section_3_0x00081A14.bin",
                        help="v3.7.0 Ghidra program name")
    args = parser.parse_args()

    status = live_status(args.program) or cache_status()

    total = status["total"]
    named = status["named"]
    unnamed = status["unnamed"]
    pct = (named / total * 100) if total else 0.0

    print(f"=== v3.7.0 Decompilation Status ({status['source']}) ===")
    print(f"  Total functions : {total}")
    print(f"  Named in Ghidra : {named} ({pct:.1f}%)")
    if status["thunks"]:
        print(f"    (of which thunks: {status['thunks']})")
    print(f"  Unnamed (FUN_*) : {unnamed}")

    # Show a few unnamed examples from cache if available
    decomp_file = BUILD / "all_decompilations.json"
    if decomp_file.exists():
        data = json.loads(decomp_file.read_text(encoding="utf-8"))
        unnamed_items = [k for k in data if k.startswith("FUN_")]
        print(f"\n  Decompiled in cache: {len(data)} ({len(unnamed_items)} of them FUN_*)")

    # SDK matching results (if any)
    matches_file = BUILD / "combined_matches.json"
    if matches_file.exists():
        matches = json.loads(matches_file.read_text(encoding="utf-8"))
        print(f"\n  Combined SDK matches: {len(matches)}")


if __name__ == "__main__":
    main()
