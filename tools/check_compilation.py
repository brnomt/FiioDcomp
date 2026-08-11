#!/usr/bin/env python3
"""Check which SDK files compile and which fail, with error details."""
import subprocess, re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
SDK_ROOT = ROOT / "firmware" / "rockchip"

CC = "arm-none-eabi-gcc"
CFLAGS = ["-mthumb", "-mcpu=cortex-m3", "-c", "-O2", "-ffreestanding",
           "-fno-builtin", "-fno-common", "-fdata-sections", "-ffunction-sections"]

# Collect include directories
include_dirs = set()
for f in SDK_ROOT.rglob("*.c"):
    include_dirs.add(str(f.parent))
    include_dirs.add(str(f.parent.parent))
    include_dirs.add(str(SDK_ROOT))
include_dirs = list(include_dirs)

sdk_files = sorted(SDK_ROOT.rglob("*.c"))
compiled = 0
failed = 0
errors = {}

for src in sdk_files:
    obj = BUILD / f"{src.stem}.o"
    cmd = [CC] + CFLAGS
    for inc in include_dirs:
        cmd.extend(["-I", str(inc)])
    cmd.extend([str(src), "-o", str(obj)])
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        if result.returncode == 0:
            compiled += 1
            # Count functions
            nm_result = subprocess.run(["arm-none-eabi-nm", "-S", str(obj)],
                                      capture_output=True, text=True, timeout=10)
            func_count = len(re.findall(r'\sT\s+\S+', nm_result.stdout))
            print(f"  OK: {src.relative_to(SDK_ROOT)} ({func_count} functions)")
        else:
            failed += 1
            # Get first error
            first_error = ""
            for line in result.stderr.split("\n"):
                if "error:" in line:
                    first_error = line.strip()
                    break
            errors[first_error] = errors.get(first_error, 0) + 1
            print(f"  FAIL: {src.relative_to(SDK_ROOT)} - {first_error[:80]}")
    except Exception as e:
        failed += 1
        print(f"  ERROR: {src.relative_to(SDK_ROOT)} - {e}")

print(f"\n=== SUMMARY ===")
print(f"Compiled: {compiled}/{len(sdk_files)}")
print(f"Failed: {failed}/{len(sdk_files)}")
print(f"\nCommon errors:")
for err, count in sorted(errors.items(), key=lambda x: -x[1]):
    print(f"  [{count}x] {err[:100]}")
