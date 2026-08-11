#!/usr/bin/env python3
"""Close a Ghidra program via POST /close_program."""
import json
import sys
import urllib.request

BASE = "http://127.0.0.1:8089"

def main():
    if len(sys.argv) < 2:
        print("Usage: python tools/close_program.py <name-or-path>")
        return
    body = json.dumps({"name": sys.argv[1]}).encode()
    req = urllib.request.Request(f"{BASE}/close_program", data=body,
                                 headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        print(resp.read().decode("utf-8", errors="replace")[:400])
    except Exception as e:
        print(f"ERROR: {e}")

if __name__ == "__main__":
    main()
