#!/usr/bin/env python3
"""Import a binary into Ghidra via /import_file MCP endpoint.

Usage:
    python tools/import_into_ghidra.py <path-to-bin> [--language ARM:LE:32:Cortex] [--no-analyze]
"""
from __future__ import annotations

import argparse
import json
import sys
import urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def api_post(endpoint: str, data: dict, timeout: int = 600) -> str:
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    resp = urllib.request.urlopen(req, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def api_get(endpoint: str, timeout: int = 60) -> str:
    resp = urllib.request.urlopen(f"{BASE}{endpoint}", timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("bin_path", help="Absolute path to the binary")
    parser.add_argument("--language", default="ARM:LE:32:Cortex", help="Ghidra language ID")
    parser.add_argument("--no-analyze", action="store_true", help="Skip auto-analysis")
    parser.add_argument("--base", help="Set image base after import (e.g. 0x03000000)")
    args = parser.parse_args()

    path = str(Path(args.bin_path).resolve())
    if not Path(path).exists():
        sys.exit(f"File not found: {path}")

    print(f"Importing: {path}")
    print(f"Language:  {args.language}")

    payload = {
        "file_path": path,
        "language": args.language,
        "compiler_spec": "default",
        "auto_analyze": not args.no_analyze,
    }
    result = api_post("/import_file", payload)
    print(f"\nImport result:\n{result[:1000]}")

    if args.base:
        print(f"\nSetting image base to {args.base}...")
        result2 = api_post("/set_image_base", {"address": args.base})
        print(f"Base result:\n{result2[:500]}")

    print("\nOpen programs:")
    print(api_get("/list_open_programs")[:500])


if __name__ == "__main__":
    main()
