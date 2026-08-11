#!/usr/bin/env python3
"""Open all firmware programs in the Ghidra project."""
import urllib.request
import urllib.parse

BASE = "http://127.0.0.1:8089"

PROGRAMS = [
    "/section_3_0x00081A14.bin",   # v3.7.0 primary
    "/sec3_3_6_0.bin",             # v3.6.0 (Cortex, has renames)
    "/sec3_3_6_0.bin.0",           # v3.6.0 (v8-m)
    "/sec3_3_5_0.bin",             # v3.5.0
]

def api_get(endpoint, timeout=120):
    resp = urllib.request.urlopen(f"{BASE}{endpoint}", timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")

if __name__ == "__main__":
    for prog in PROGRAMS:
        try:
            q = urllib.parse.quote(prog)
            result = api_get(f"/open_program?path={q}")
            print(f"{prog}: {result[:120]}")
        except Exception as e:
            print(f"{prog}: ERROR {e}")

    print("\nOpen programs:")
    print(api_get("/list_open_programs")[:1200])
