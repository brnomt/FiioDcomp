#!/usr/bin/env python3
"""
extract_sdk_features.py — Extract behavioral fingerprints from SDK source:
  - Numeric constants (hex/decimal literals)
  - Control flow features (if/while/for/switch/case counts)
  - Function call count
  - Parameter count
  - Local variable count
  - Return type

Output: build/sdk_features.json
"""
import re, json
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parents[1]
SDK_ROOTS = [
    ROOT / "firmware" / "rockchip",          # MP3 V1.3 SDK
    ROOT / "firmware" / "rockchip_wireless", # Wireless Audio SDK V1.5
]
OUTPUT = ROOT / "build" / "sdk_features.json"


def extract_constants(code):
    """Extract only DISTINCTIVE constants (>= 0x100) from C source code.

    Small constants (2-255) are too generic — they appear as array indices,
    loop counters, bit shifts, etc. in almost every function.
    Distinctive constants are magic numbers, register addresses, buffer sizes,
    sample rates, etc. that uniquely identify a function's purpose.
    """
    constants = set()
    MIN_DISTINCTIVE = 0x100  # 256

    # Hex literals: 0x1234, 0X1234
    for m in re.finditer(r'\b0[xX]([0-9a-fA-F]+)\b', code):
        val = int(m.group(1), 16)
        if val >= MIN_DISTINCTIVE and val <= 0xFFFFFF:
            constants.add(val)
    # Decimal literals (but not in comments or strings)
    clean = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)  # block comments
    clean = re.sub(r'//.*?$', '', clean, flags=re.MULTILINE)  # line comments
    clean = re.sub(r'"[^"]*"', '""', clean)  # string literals
    clean = re.sub(r"'[^']*'", "''", clean)  # char literals
    for m in re.finditer(r'\b(\d{3,})\b', clean):
        val = int(m.group(1))
        if MIN_DISTINCTIVE <= val <= 0xFFFF:
            constants.add(val)
    return constants


def extract_features(code):
    """Extract structural features from C source code."""
    # Remove comments and strings for cleaner parsing
    clean = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    clean = re.sub(r'//.*?$', '', clean, flags=re.MULTILINE)
    clean = re.sub(r'"[^"]*"', '""', clean)
    clean = re.sub(r"'[^']*'", "''", clean)

    features = {}
    # Control flow
    features['ifs'] = len(re.findall(r'\bif\s*\(', clean))
    features['elses'] = len(re.findall(r'\belse\b', clean))
    features['whiles'] = len(re.findall(r'\bwhile\s*\(', clean))
    features['fors'] = len(re.findall(r'\bfor\s*\(', clean))
    features['switches'] = len(re.findall(r'\bswitch\s*\(', clean))
    features['cases'] = len(re.findall(r'\bcase\b', clean))
    features['returns'] = len(re.findall(r'\breturn\b', clean))
    features['calls'] = len(re.findall(r'\w+\s*\(', clean))

    # Constants
    features['constants'] = list(extract_constants(code))

    return features


def parse_function_signature(line):
    """Parse a function signature to get return type, name, and param count."""
    # Match: "ret_type func_name(params) {"
    m = re.match(r'\s*(?:static\s+)?(\w[\w\s\*]+?)\s+(\w+)\s*\(([^)]*)\)', line)
    if m:
        ret_type = m.group(1).strip()
        name = m.group(2)
        params = m.group(3).strip()
        if params and params != 'void':
            param_count = len([p for p in params.split(',') if p.strip()])
        else:
            param_count = 0
        return ret_type, name, param_count
    return None, None, None


def extract_functions(code):
    """Extract individual functions from C source code."""
    functions = {}
    # Find function definitions: "ret_type func_name(params) {"
    # Simple approach: find lines that look like function signatures
    lines = code.split('\n')
    i = 0
    while i < len(lines):
        line = lines[i]
        # Skip preprocessor and comments
        if line.strip().startswith('#') or line.strip().startswith('/*') or line.strip().startswith('*'):
            i += 1
            continue

        ret_type, name, param_count = parse_function_signature(line)
        if name and not name in ('if', 'while', 'for', 'switch', 'return', 'sizeof'):
            # Find the function body (from { to matching })
            brace_count = 0
            body_start = i
            found_brace = False
            for j in range(i, min(i + 500, len(lines))):
                if '{' in lines[j]:
                    brace_count += lines[j].count('{')
                    found_brace = True
                if '}' in lines[j]:
                    brace_count -= lines[j].count('}')
                if found_brace and brace_count == 0:
                    body = '\n'.join(lines[body_start:j+1])
                    features = extract_features(body)
                    features['param_count'] = param_count
                    features['return_type'] = ret_type
                    features['source_line'] = body_start + 1
                    functions[name] = features
                    i = j + 1
                    break
            else:
                i += 1
                continue
        i += 1
    return functions


def main():
    all_features = {}
    sdk_files = []
    for root in SDK_ROOTS:
        if root.exists():
            files = list(root.rglob("*.c"))
            sdk_files.extend(files)
            print(f"  {root.name}: {len(files)} .c files")
    print(f"SDK source files total: {len(sdk_files)}")

    for f in sdk_files:
        try:
            code = f.read_text(encoding="utf-8", errors="ignore")
        except:
            continue

        funcs = extract_functions(code)
        for name, features in funcs.items():
            if name not in all_features:
                # Determine which SDK this came from
                sdk_name = "wireless" if "rockchip_wireless" in str(f) else "mp3"
                all_features[name] = {**features, "source_file": str(f.relative_to(ROOT)),
                                      "sdk": sdk_name}

    print(f"Functions with features: {len(all_features)}")

    # Stats
    has_constants = sum(1 for f in all_features.values() if f.get('constants'))
    has_calls = sum(1 for f in all_features.values() if f.get('calls', 0) > 0)
    print(f"  With constants: {has_constants}")
    print(f"  With calls: {has_calls}")

    OUTPUT.write_text(json.dumps(all_features, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {OUTPUT}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
