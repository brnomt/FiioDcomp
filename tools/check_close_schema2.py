#!/usr/bin/env python3
"""Check close_program schema and close the v8-m duplicate v3.6 program."""
import json
import sys
import urllib.request

BASE = "http://127.0.0.1:8089"


def get_json(url):
    resp = urllib.request.urlopen(url, timeout=60)
    return json.loads(resp.read().decode("utf-8", errors="replace"))


def main():
    data = get_json(f"{BASE}/mcp/schema")
    tools = data if isinstance(data, list) else data.get("tools", [])
    for t in tools:
        if t.get("path") in ("/close_program", "/switch_program", "/save_program"):
            print(f"=== {t['path']} ({t.get('method')}) ===")
            for p in t.get("params", []):
                print(f"  {p.get('name')} ({p.get('type')}) [{p.get('source')}] req={p.get('required')}")

    # Try closing by path
    if len(sys.argv) > 1:
        body = json.dumps({"path": sys.argv[1]}).encode()
        req = urllib.request.Request(f"{BASE}/close_program", data=body,
                                     headers={"Content-Type": "application/json"}, method="POST")
        try:
            resp = urllib.request.urlopen(req, timeout=120)
            print("CLOSE by path:", resp.read().decode("utf-8", errors="replace")[:300])
        except Exception as e:
            print("CLOSE by path ERR:", e)


if __name__ == "__main__":
    main()
