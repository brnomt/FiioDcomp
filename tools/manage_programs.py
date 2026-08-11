#!/usr/bin/env python3
"""Close duplicate Ghidra programs."""
import sys
import urllib.request
import urllib.parse

BASE = "http://127.0.0.1:8089"

def api_get(endpoint):
    resp = urllib.request.urlopen(f"{BASE}{endpoint}", timeout=60)
    return resp.read().decode("utf-8", errors="replace")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        for prog in sys.argv[1:]:
            try:
                print(f"Closing {prog}...")
                print(api_get(f"/close_program?program={urllib.parse.quote(prog)}")[:200])
            except Exception as e:
                print(f"  err: {e}")
    print("\nOpen programs:")
    print(api_get("/list_open_programs")[:800])
