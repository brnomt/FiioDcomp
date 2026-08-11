#!/usr/bin/env python3
"""Show params for specific Ghidra MCP endpoints."""
import urllib.request
import json

BASE = "http://127.0.0.1:8089"

resp = urllib.request.urlopen(f"{BASE}/mcp/schema", timeout=30)
data = json.loads(resp.read().decode())
tools = data if isinstance(data, list) else data.get("tools", data.get("functions", []))

INTERESTING = [
    "/find_undocumented_by_string",
    "/search_strings",
    "/list_strings",
    "/import_file",
    "/switch_program",
    "/list_open_programs",
    "/bulk_fuzzy_match",
    "/find_similar_functions_fuzzy",
    "/diff_functions",
    "/get_bulk_function_hashes",
    "/search_functions",
    "/batch_string_anchor_report",
    "/set_image_base",
    "/read_memory",
    "/inspect_memory_content",
]

for t in tools:
    path = t.get("path", "")
    if path in INTERESTING:
        print(f"\n=== {path} ({t.get('method')}) ===")
        print(f"  Desc: {t.get('description', '')[:150]}")
        for p in t.get("params", []):
            print(f"  param: {p.get('name')} ({p.get('type')}) [{p.get('source')}] req={p.get('required')}: {p.get('description', '')[:80]}")
