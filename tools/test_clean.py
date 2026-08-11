#!/usr/bin/env python3
"""Test script execution after cleanup."""
import urllib.request, json

code = """println("Script execution works!");
println("Functions: " + currentProgram.getFunctionManager().getFunctionCount());
"""

body = json.dumps({"code": code}).encode("utf-8")
req = urllib.request.Request(
    "http://127.0.0.1:8089/run_script_inline", data=body,
    headers={"Content-Type": "application/json"}, method="POST"
)
resp = urllib.request.urlopen(req, timeout=60)
print(resp.read().decode())
