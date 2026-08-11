#!/usr/bin/env python3
"""List all includes from SDK source files."""
from pathlib import Path
import re

all_includes = set()
for f in Path("firmware/rockchip").rglob("*.c"):
    try:
        for line in f.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = re.match(r'\s*#include\s+["<]([^">]+)[">]', line)
            if m:
                all_includes.add(m.group(1))
    except:
        pass

for inc in sorted(all_includes):
    print(inc)
