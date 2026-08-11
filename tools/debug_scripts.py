#!/usr/bin/env python3
"""Read generated ghidra scripts to debug compilation errors."""
from pathlib import Path

d = Path("C:/Users/brnomt/ghidra_scripts")
for f in sorted(d.iterdir()):
    if f.suffix == ".java":
        print(f"=== {f.name} ({f.stat().st_size} bytes) ===")
        content = f.read_text()
        for i, line in enumerate(content.splitlines(), 1):
            print(f"  {i}: {line}")
        print()
