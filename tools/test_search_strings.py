#!/usr/bin/env python3
"""Test /search_strings response format."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

for pattern in ["ID3", "M4A", "favorite", "album", "DSD"]:
    try:
        resp = urllib.request.urlopen(
            f"{BASE}/search_strings?search_term={pattern}&limit=5", timeout=60)
        raw = resp.read().decode("utf-8", errors="replace")
        print(f"\n=== {pattern} ===")
        print(raw[:800])
    except Exception as e:
        print(f"\n=== {pattern} === ERROR {e}")
