#!/usr/bin/env python3
"""
compile_and_match.py — Compile SDK source files, extract function bytes,
and search for matching patterns in the firmware binary.

Strategy:
  1. Compile each SDK .c file to an object file
  2. Extract function names and their compiled bytes from the object file
  3. Search for those byte patterns in the firmware binary (section3_stock.bin)
  4. If a match is found, rename the function in Ghidra
"""
import subprocess, re, json, time, urllib.request, urllib.parse
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"
SDK_ROOT = ROOT / "firmware" / "rockchip"
SECTION3 = BUILD / "section3_stock.bin"
BASE = "http://127.0.0.1:8089"

# Compiler flags matching the original firmware (Cortex-M3, Thumb-2, -O2)
CC = "arm-none-eabi-gcc"
CFLAGS = ["-mthumb", "-mcpu=cortex-m3", "-c", "-O2", "-ffreestanding",
           "-fno-builtin", "-fno-common", "-fdata-sections", "-ffunction-sections"]


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        resp = urllib.request.urlopen(req, timeout=60)
        return resp.read().decode("utf-8")
    except Exception as e:
        return f"ERROR: {e}"


def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def compile_file(src_path, include_dirs):
    """Compile a .c file to an object file. Returns path to .o file or None."""
    obj_path = BUILD / f"{src_path.stem}.o"
    cmd = [CC] + CFLAGS
    for inc in include_dirs:
        cmd.extend(["-I", str(inc)])
    cmd.extend([str(src_path), "-o", str(obj_path)])
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        if result.returncode == 0:
            return obj_path
        else:
            return None
    except:
        return None


def extract_functions_from_obj(obj_path):
    """Extract function names and their compiled bytes from an object file."""
    # Get function symbols with addresses
    result = subprocess.run(
        ["arm-none-eabi-nm", "-S", str(obj_path)],
        capture_output=True, text=True, timeout=10
    )
    functions = []
    for line in result.stdout.split("\n"):
        m = re.match(r'([0-9a-fA-F]+)\s+([0-9a-fA-F]+)\s+T\s+(\S+)', line)
        if m:
            addr = int(m.group(1), 16)
            size = int(m.group(2), 16)
            name = m.group(3)
            if size > 0:
                functions.append({"name": name, "offset": addr, "size": size})
    return functions


def extract_function_bytes(obj_path, func):
    """Extract the raw bytes of a function from an object file."""
    # Use objcopy to extract the .text section
    result = subprocess.run(
        ["arm-none-eabi-objcopy", "-O", "binary", str(obj_path), str(obj_path) + ".bin"],
        capture_output=True, text=True, timeout=10
    )
    if result.returncode != 0:
        return None
    bin_data = (obj_path.with_suffix(".bin")).read_bytes() if (obj_path.with_suffix(".bin")).exists() else None
    # Actually, let's read the raw object file and extract bytes at the function offset
    # The object file has sections, so we need to use objdump to get the actual bytes
    result = subprocess.run(
        ["arm-none-eabi-objdump", "-d", str(obj_path)],
        capture_output=True, text=True, timeout=10
    )

    # Parse the disassembly to extract bytes for each function
    func_bytes = {}
    current_func = None
    current_bytes = []

    for line in result.stdout.split("\n"):
        # Function header: "00000000 <swap16>:"
        m = re.match(r'([0-9a-fA-F]+)\s+<(\S+)>:', line)
        if m:
            if current_func and current_bytes:
                func_bytes[current_func] = bytes(current_bytes)
            current_func = m.group(2)
            current_bytes = []
            continue

        # Instruction line: "   0:	b510      	push	{r4, lr}"
        # Thumb-2 32-bit instructions: "   0:	f000 b8f0 	bl	0x..."
        m = re.match(r'\s+([0-9a-fA-F]+):\s+([0-9a-fA-F ]+?)\t', line)
        if m and current_func:
            hex_part = m.group(2).strip()
            for byte_str in hex_part.split():
                try:
                    val = int(byte_str, 16)
                    if 0 <= val <= 255:
                        current_bytes.append(val)
                except:
                    pass

    if current_func and current_bytes:
        func_bytes[current_func] = bytes(current_bytes)

    return func_bytes


def search_in_binary(pattern, binary_data, load_base=0x03000000):
    """Search for a byte pattern in the binary. Returns list of load addresses."""
    matches = []
    start = 0
    while True:
        pos = binary_data.find(pattern, start)
        if pos < 0:
            break
        matches.append(load_base + pos)
        start = pos + 1
    return matches


def main():
    # Load firmware binary
    fw_binary = SECTION3.read_bytes()
    print(f"Firmware binary: {len(fw_binary)} bytes")

    # Find all SDK source files
    sdk_files = list(SDK_ROOT.rglob("*.c"))
    print(f"SDK source files: {len(sdk_files)}")

    # Collect include directories
    include_dirs = set()
    for f in sdk_files:
        include_dirs.add(str(f.parent))
        include_dirs.add(str(f.parent.parent))
        include_dirs.add(str(SDK_ROOT))
    include_dirs = list(include_dirs)

    total_compiled = 0
    total_functions = 0
    total_matches = 0
    renamed = 0
    all_matches = []

    for i, src_file in enumerate(sdk_files):
        if i % 10 == 0:
            print(f"\n[{i}/{len(sdk_files)}] Compiling {src_file.name}...")

        # Compile
        obj_path = compile_file(src_file, include_dirs)
        if obj_path is None:
            continue
        total_compiled += 1

        # Extract functions
        functions = extract_functions_from_obj(obj_path)
        if not functions:
            continue

        # Extract function bytes
        func_bytes = extract_function_bytes(obj_path, None)
        if not func_bytes:
            continue

        total_functions += len(func_bytes)

        # Search for each function in the firmware binary
        for func_name, byte_pattern in func_bytes.items():
            if len(byte_pattern) < 8:  # Skip very short functions
                continue

            matches = search_in_binary(byte_pattern, fw_binary)
            if len(matches) == 1:
                # Unique match - high confidence
                addr = matches[0]
                addr_str = f"0x{addr:08x}"
                total_matches += 1
                all_matches.append({
                    "name": func_name,
                    "address": addr_str,
                    "size": len(byte_pattern),
                    "source": src_file.name,
                    "confidence": "unique"
                })
                print(f"  UNIQUE MATCH: {func_name} @ {addr_str} ({len(byte_pattern)} bytes) from {src_file.name}")

                # Rename in Ghidra
                result = rename_function(addr_str, func_name)
                if "error" not in result.lower():
                    renamed += 1
                time.sleep(0.05)
            elif 2 <= len(matches) <= 3:
                # Few matches - medium confidence
                for addr in matches:
                    addr_str = f"0x{addr:08x}"
                    all_matches.append({
                        "name": func_name,
                        "address": addr_str,
                        "size": len(byte_pattern),
                        "source": src_file.name,
                        "confidence": "multi"
                    })
                    total_matches += 1

    print(f"\n=== SUMMARY ===")
    print(f"Files compiled: {total_compiled}/{len(sdk_files)}")
    print(f"Functions extracted: {total_functions}")
    print(f"Pattern matches: {total_matches}")
    print(f"Functions renamed: {renamed}")

    # Save results
    out = BUILD / "compile_match_results.json"
    out.write_text(json.dumps(all_matches, indent=2), encoding="utf-8")
    print(f"Results saved to: {out}")

    # Final count
    result = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(result.read().decode())
    all_funcs = data.get("functions", data) if isinstance(data, dict) else data
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
