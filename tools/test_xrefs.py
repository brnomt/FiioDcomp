#!/usr/bin/env python3
"""Test get_xrefs_to on various string addresses."""
import urllib.request

BASE = "http://127.0.0.1:8089"

# Test addresses: known code strings and UI strings
test_addrs = [
    ("ID3V2 start:%d (code)", "030FEC24"),
    ("MP3/OGG/M4A/WMA (code)", "0301435C"),
    ("Play All Album (code)", "03001170"),
    ("Favorites (UI)", "0371B13E"),
    ("Equalizer (UI)", "0371AF3A"),
    ("Lyrics File Not Found (UI)", "0371C668"),
]

for name, addr in test_addrs:
    try:
        resp = urllib.request.urlopen(f"{BASE}/get_xrefs_to?address={addr}", timeout=30)
        raw = resp.read().decode("utf-8", errors="replace")
        print(f"\n=== {name} @ {addr} ===")
        print(raw[:600])
    except Exception as e:
        print(f"\n=== {name} @ {addr} === ERROR {e}")
