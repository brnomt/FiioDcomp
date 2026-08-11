#!/usr/bin/env python3
"""Get all unnamed FUN_* functions from Ghidra MCP."""
import urllib.request
import json
import os

BASE = "http://127.0.0.1:8089"
OUTPUT_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), "build")

def get_functions():
    """Get all functions from Ghidra using enhanced endpoint."""
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=120)
    data = json.loads(resp.read().decode())
    # Handle different response formats
    if isinstance(data, dict) and "functions" in data:
        return data["functions"]
    return data

def main():
    print("Fetching functions from Ghidra...")
    functions = get_functions()
    print(f"Total functions: {len(functions)}")
    
    # Filter unnamed functions (FUN_* prefix)
    unnamed = [f for f in functions if f.get("name", "").startswith("FUN_")]
    print(f"Unnamed functions (FUN_*): {len(unnamed)}")
    
    # Named functions
    named = [f for f in functions if not f.get("name", "").startswith("FUN_")]
    print(f"Named functions: {len(named)}")
    
    # Save to build directory
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    output_file = os.path.join(OUTPUT_DIR, "ghidra_all_functions.json")
    with open(output_file, "w") as f:
        json.dump(functions, f, indent=2)
    print(f"\nSaved all functions to: {output_file}")
    
    # Save unnamed functions separately
    unnamed_file = os.path.join(OUTPUT_DIR, "ghidra_unnamed_functions.json")
    with open(unnamed_file, "w") as f:
        json.dump(unnamed, f, indent=2)
    print(f"Saved unnamed functions to: {unnamed_file}")
    
    # Show first 10 unnamed
    print("\nFirst 10 unnamed functions:")
    for func in unnamed[:10]:
        name = func.get("name", "")
        addr = func.get("address", "")
        print(f"  {name} @ {addr}")
    
    return unnamed

if __name__ == "__main__":
    main()
