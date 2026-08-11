#!/usr/bin/env python3
"""Poll analysis status until v3.5.0 finishes, then save it."""
import json
import sys
import time
import urllib.request

BASE = "http://127.0.0.1:8089"


def get_json(url, timeout=30):
    resp = urllib.request.urlopen(url, timeout=timeout)
    return json.loads(resp.read().decode("utf-8", errors="replace"))


def main():
    target = sys.argv[1] if len(sys.argv) > 1 else "3_5_0"
    max_iter = int(sys.argv[2]) if len(sys.argv) > 2 else 40
    for i in range(max_iter):
        try:
            data = get_json(f"{BASE}/analysis_status")
            done = True
            for p in data.get("programs", []):
                if target in p.get("name", ""):
                    print(f"iter {i}: {p.get('name')} analyzing={p.get('analyzing')} funcs={p.get('function_count')}")
                if p.get("analyzing"):
                    done = False
            if done:
                print("ALL ANALYSIS DONE")
                break
        except Exception as e:
            print(f"iter {i}: ERR {e}")
        time.sleep(15)


if __name__ == "__main__":
    main()
