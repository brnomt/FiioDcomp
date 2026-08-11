#!/usr/bin/env python3
"""
ghidra_client.py — Direct HTTP client for the Ghidra MCP plugin.
Bypasses the MCP bridge to call the Ghidra plugin's HTTP API directly.
"""
import urllib.request
import urllib.parse
import json
import time
from typing import Any

BASE = "http://127.0.0.1:8089"
TIMEOUT = 120


def _get(endpoint: str, params: dict | None = None) -> Any:
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=TIMEOUT)
        return json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        return {"error": f"HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:200]}"}
    except Exception as e:
        return {"error": str(e)}


def _post(endpoint: str, data: dict) -> Any:
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(
        f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST"
    )
    try:
        resp = urllib.request.urlopen(req, timeout=TIMEOUT)
        return json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        return {"error": f"HTTP {e.code}: {e.read().decode('utf-8', errors='replace')[:200]}"}
    except Exception as e:
        return {"error": str(e)}


# === High-level API ===

def list_functions():
    """List all functions in the program."""
    return _get("/list_functions")

def list_functions_enhanced():
    """List functions with thunk/external flags."""
    return _get("/list_functions_enhanced")

def decompile_function(address: str):
    """Decompile function at address."""
    return _get("/decompile_function", {"address": address})

def batch_decompile(addresses: str):
    """Decompile multiple functions (comma-separated addresses)."""
    return _get("/batch_decompile", {"functions": addresses})

def rename_function_by_address(address: str, new_name: str, dry_run: bool = False):
    """Rename function at address."""
    params = {"address": address, "new_name": new_name}
    if dry_run:
        params["dry_run"] = "true"
    return _post("/rename_function_by_address", params)

def get_function_callees(address: str):
    """Get functions called by a function."""
    return _get("/get_function_callees", {"address": address})

def get_function_callers(address: str):
    """Get functions calling a function."""
    return _get("/get_function_callers", {"address": address})

def get_xrefs_to(address: str):
    """Get cross-references to an address."""
    return _get("/get_xrefs_to", {"address": address})

def search_strings(pattern: str):
    """Search strings by regex pattern."""
    return _get("/search_strings", {"pattern": pattern})

def list_strings(limit: int = 100, filter_type: str = "defined"):
    """List defined strings."""
    return _get("/list_strings", {"limit": str(limit), "filter": filter_type})

def get_function_count():
    """Get total function count."""
    return _get("/get_function_count")

def get_function_call_graph(address: str, depth: int = 1):
    """Traverse call graph from a function."""
    return _get("/get_function_call_graph", {"address": address, "depth": str(depth)})


if __name__ == "__main__":
    import sys

    # Quick test: get function count
    print("=== Function count ===")
    result = get_function_count()
    print(json.dumps(result, indent=2)[:500])

    # List first 20 functions
    print("\n=== First 20 functions ===")
    funcs = list_functions()
    if isinstance(funcs, list):
        print(f"Total: {len(funcs)}")
        for f in funcs[:20]:
            print(f"  {f}")
    elif isinstance(funcs, dict):
        print(json.dumps(funcs, indent=2)[:1000])
