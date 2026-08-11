#!/usr/bin/env python3
"""Use /find_undocumented_by_string to find FUN_* functions referencing strings."""
import urllib.request
import urllib.parse
import json
import sys

BASE = "http://127.0.0.1:8089"

def api_get(endpoint, params=None, timeout=60):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=timeout)
    return resp.read().decode("utf-8", errors="replace")

# Strings to search for (changelog-related)
SEARCH_STRINGS = [
    # v3.6.0 changelog
    "M4A",
    "album",
    "favorites",
    "media library",
    "MediaLib",
    # codec/tag related
    "ID3",
    "ID3V2",
    "OGG",
    "APE",
    "DSD",
    "cover",
    "art",
    "RIFF",
    "lyrics",
    # sorting
    "sort",
    "track",
    "genre",
    "artist",
    # settings
    "EQ",
    "gain",
    "balance",
    "volume",
    "battery",
    "shuffle",
]

for s in SEARCH_STRINGS:
    try:
        raw = api_get("/find_undocumented_by_string", {"search": s}, timeout=60)
        # Parse JSON
        try:
            data = json.loads(raw)
            if isinstance(data, list):
                if data:
                    print(f"\n[{s}] ({len(data)} results)")
                    for item in data[:8]:
                        if isinstance(item, dict):
                            print(f"  {item}")
                        else:
                            print(f"  {item}")
                # else: no results, skip
            else:
                if data:
                    print(f"\n[{s}] {str(data)[:200]}")
        except json.JSONDecodeError:
            if raw.strip() and "No" not in raw[:20]:
                print(f"\n[{s}] {raw[:200]}")
    except Exception as e:
        print(f"\n[{s}] ERROR: {e}")
