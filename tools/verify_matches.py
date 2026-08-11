#!/usr/bin/env python3
"""Verify functionality matches by decompiling binary functions and showing SDK source."""
import json, urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

matches = json.loads((ROOT / "build" / "functionality_matches_v2.json").read_text(encoding="utf-8"))
sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))

# Show top 10 matches with verification
for m in matches[:10]:
    print(f"\n{'='*80}")
    print(f"BINARY: {m['binary_func']} @ {m['binary_addr']}")
    print(f"SDK:    {m['sdk_func']} (score={m['score']:.1f}, overlap={m['overlap_consts']})")
    print(f"Source: {m['sdk_source']}")

    # Show SDK source
    sdk_src_path = ROOT / m['sdk_source']
    if sdk_src_path.exists():
        code = sdk_src_path.read_text(encoding="utf-8", errors="ignore")
        # Find the function in the source
        import re
        pattern = rf'\b{re.escape(m["sdk_func"])}\s*\('
        match = re.search(pattern, code)
        if match:
            # Show ~40 lines around the match
            lines = code.split('\n')
            line_num = code[:match.start()].count('\n')
            start = max(0, line_num - 2)
            end = min(len(lines), line_num + 40)
            print(f"\nSDK source (lines {start+1}-{end}):")
            for i in range(start, end):
                print(f"  {i+1:4d}: {lines[i]}")

    # Decompile binary function
    try:
        resp = urllib.request.urlopen(
            f"{BASE}/decompile_function?address={m['binary_addr']}", timeout=30)
        decomp = resp.read().decode("utf-8", errors="ignore")
        print(f"\nDECOMPILED BINARY:")
        # Show first 40 lines
        for line in decomp.split('\n')[:40]:
            print(f"  {line}")
    except Exception as e:
        print(f"  Decompile error: {e}")
