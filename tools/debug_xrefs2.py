#!/usr/bin/env python3
"""Debug get_xrefs_to for specific string addresses."""
import urllib.request

BASE = "http://127.0.0.1:8089"

addrs = [
    ("MP1MP2MP3 format list", "03013FF4"),
    ("MP3/OGG/M4A/WMA", "03014F4C"),
    ("Play All Album", "03001AD8"),
    ("PICTURE OGG", "03023AD8"),
    ("BT Music", "0300E2D0"),
    ("ID3V2 start (known works)", "030FF6F8"),
    ("Cover Art (front)", "03023F84"),
]

for name, addr in addrs:
    try:
        resp = urllib.request.urlopen(f"{BASE}/get_xrefs_to?address={addr}", timeout=60)
        raw = resp.read().decode("utf-8", errors="replace")
        print(f"\n=== {name} @ {addr} ===")
        print(raw[:500])
    except Exception as e:
        print(f"\n=== {name} @ {addr} === ERROR {e}")
