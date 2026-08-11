#!/usr/bin/env python3
"""
build_sdk_callees.py — For each SDK function, extract the list of functions it calls.
This is used for call graph propagation.

Output: build/sdk_callees.json  {func_name: [callee1, callee2, ...]}
"""
import re, json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SDK_ROOTS = [
    ROOT / "firmware" / "rockchip",
    ROOT / "firmware" / "rockchip_wireless",
]
OUTPUT = ROOT / "build" / "sdk_callees.json"

# C keywords that look like function calls but aren't
KEYWORDS = {
    'if', 'while', 'for', 'switch', 'return', 'sizeof', 'case', 'do',
    'else', 'goto', 'break', 'continue', 'default',
    'void', 'int', 'char', 'short', 'long', 'unsigned', 'signed',
    'float', 'double', 'const', 'static', 'extern', 'register',
    'volatile', 'auto', 'struct', 'union', 'enum', 'typedef',
    'UINT8', 'UINT16', 'UINT32', 'UINT64', 'INT8', 'INT16', 'INT32', 'INT64',
    'BOOL', 'BOOLEAN', 'TRUE', 'FALSE', 'NULL', 'HDC', 'HFILE', 'HANDLE',
    'rk_err_t', 'rk_size_t', 'rk_size_t', 'uint8', 'uint16', 'uint32',
    'uint64', 'int8', 'int16', 'int32', 'int64', 'ushort', 'uchar',
    'pFunction', 'pFunType', 'CallbackHandler',
}


def extract_function_body(code, func_name):
    """Find and extract the body of a function by name."""
    # Match function definition: ret_type func_name(params) {
    pattern = rf'\b{re.escape(func_name)}\s*\([^)]*\)\s*\{{'
    match = re.search(pattern, code)
    if not match:
        return None

    # Find matching closing brace
    brace_count = 0
    start = match.end() - 1  # position of opening {
    for i in range(start, min(start + 10000, len(code))):
        if code[i] == '{':
            brace_count += 1
        elif code[i] == '}':
            brace_count -= 1
        if brace_count == 0:
            return code[match.start():i+1]
    return None


def extract_callees(body):
    """Extract function call names from a function body."""
    # Remove comments and strings
    clean = re.sub(r'/\*.*?\*/', '', body, flags=re.DOTALL)
    clean = re.sub(r'//.*?$', '', clean, flags=re.MULTILINE)
    clean = re.sub(r'"[^"]*"', '""', clean)
    clean = re.sub(r"'[^']*'", "''", clean)

    # Find all function calls: identifier followed by (
    # But skip: if(, while(, for(, switch(, sizeof(, etc.
    callees = []
    for m in re.finditer(r'\b([a-zA-Z_]\w*)\s*\(', clean):
        name = m.group(1)
        if name not in KEYWORDS and len(name) > 1:
            callees.append(name)

    # Deduplicate while preserving order
    seen = set()
    unique = []
    for c in callees:
        if c not in seen:
            seen.add(c)
            unique.append(c)

    return unique


def main():
    callees_index = {}

    for sdk_root in SDK_ROOTS:
        if not sdk_root.exists():
            continue
        sdk_files = list(sdk_root.rglob("*.c"))
        print(f"  {sdk_root.name}: {len(sdk_files)} files")

        for f in sdk_files:
            try:
                code = f.read_text(encoding="utf-8", errors="ignore")
            except:
                continue

            # Find all function definitions in this file
            # Pattern: ret_type func_name(params) {
            for m in re.finditer(r'\b([a-zA-Z_]\w*)\s*\(([^)]*)\)\s*\{', code):
                func_name = m.group(1)
                if func_name in KEYWORDS:
                    continue

                # Extract the function body
                body = extract_function_body(code, func_name)
                if not body:
                    continue

                # Extract callees
                callees = extract_callees(body)
                if func_name not in callees_index:
                    callees_index[func_name] = callees

    print(f"\nSDK functions with callees: {len(callees_index)}")

    # Stats
    total_callees = sum(len(v) for v in callees_index.values())
    avg = total_callees / len(callees_index) if callees_index else 0
    print(f"  Total callee references: {total_callees}")
    print(f"  Average callees per function: {avg:.1f}")

    # Show some examples
    print("\nExamples:")
    for name in ['AudioPause', 'FmFreqToChan', 'RecordStop', 'WavEncodeHeaderInit']:
        if name in callees_index:
            print(f"  {name}: {callees_index[name][:10]}")

    OUTPUT.write_text(json.dumps(callees_index, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"\nSaved to: {OUTPUT}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
