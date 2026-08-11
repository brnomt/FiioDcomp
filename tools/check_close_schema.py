#!/usr/bin/env python3
import json
import urllib.request

BASE = "http://127.0.0.1:8089"

resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=30)
data = json.loads(resp.read().decode())
tools = data if isinstance(data, list) else data.get("tools", [])

for t in tools:
    if t.get("path") in ("/close_program", "/open_program", "/switch_program", "/save_program", "/save_all_programs"):
        print(f"=== {t['path']} ({t['method']}) ===")
        for p in t.get("params", []):
            print(f"  {p.get('name')} ({p.get('type')}) [{p.get('source')}] req={p.get('required')}: {p.get('description','')[:80]}")
        print()

# analysis status
resp = urllib.request.urlopen(f"{BASE}/analysis_status", timeout=60)
print("ANALYSIS:", resp.read().decode("utf-8", errors="replace")[:600])
