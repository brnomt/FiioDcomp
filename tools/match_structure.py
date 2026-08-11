#!/usr/bin/env python3
"""
match_structure.py — Match binary functions to SDK functions by structural
fingerprint (code shape), not constants.

Features:
  - Parameter count
  - Local variable count
  - If/else/while/for/switch/case/return counts
  - Function call count
  - Assignment count
  - Return type (void vs non-void)
  - Function size (instruction count / code length)

Matching: find SDK functions with the closest structural fingerprint.
Apply uniqueness constraint to avoid false positives.
"""
import re, json, time, urllib.request
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _post(endpoint, data):
    body = json.dumps(data).encode("utf-8")
    req = urllib.request.Request(f"{BASE}{endpoint}", data=body,
        headers={"Content-Type": "application/json"}, method="POST")
    try:
        return urllib.request.urlopen(req, timeout=30).read().decode()
    except Exception as e:
        return f"ERROR: {e}"

def rename_function(address, new_name):
    return _post("/rename_function_by_address", {"function_address": address, "new_name": new_name})


def extract_binary_structure(code):
    """Extract structural fingerprint from decompiled code."""
    s = {}

    # Parameter count
    sig = re.match(r'\w+\s+FUN_\w+\s*\(([^)]*)\)', code)
    if sig:
        params = sig.group(1).strip()
        s['params'] = len([p for p in params.split(',') if p.strip() and p.strip() != 'void']) if params and params != 'void' else 0
    else:
        s['params'] = 0

    # Return type (void vs non-void)
    s['returns_void'] = 1 if re.match(r'\bvoid\b\s+FUN_', code) else 0

    # Control flow
    s['ifs'] = len(re.findall(r'\bif\s*\(', code))
    s['whiles'] = len(re.findall(r'\bwhile\s*\(', code))
    s['fors'] = len(re.findall(r'\bfor\s*\(', code))
    s['switches'] = len(re.findall(r'\bswitch\s*\(', code))
    s['cases'] = len(re.findall(r'\bcase\b', code))
    s['returns'] = len(re.findall(r'\breturn\b', code))

    # Function calls
    s['calls_fun'] = len(re.findall(r'\bFUN_\w+\s*\(', code))
    s['calls_func'] = len(re.findall(r'\bfunc_0x\w+\s*\(', code))
    s['calls_rom'] = len(re.findall(r'\brom_\w+\s*\(', code))
    all_calls = len(re.findall(r'\b[a-zA-Z_]\w*\s*\(', code))
    s['calls_named'] = max(0, all_calls - s['calls_fun'] - s['calls_func'] - s['calls_rom'] - s['ifs'] - s['whiles'] - s['fors'] - s['switches'])
    s['total_calls'] = s['calls_fun'] + s['calls_func'] + s['calls_rom'] + s['calls_named']

    # Local variables (count declarations in function body)
    # Look for patterns like "int var", "uint var", "ushort var", etc.
    body_match = re.search(r'\{', code)
    if body_match:
        body = code[body_match.start():]
        # Count variable declarations
        decls = len(re.findall(r'\b(?:int|uint|ushort|short|char|uchar|byte|undefined\d?|long|ulong|void\s*\*|float|double)\s+\w+', body))
        s['locals'] = decls
    else:
        s['locals'] = 0

    # Code size
    s['code_size'] = len(code)

    # Data references
    s['data_refs'] = len(set(re.findall(r'\bDAT_[0-9a-f]+\b', code)))

    return s


def extract_sdk_structure(code):
    """Extract structural fingerprint from SDK source code."""
    s = {}

    # Parameter count
    sig = re.match(r'\w[\w\s\*]*?\s+(\w+)\s*\(([^)]*)\)', code)
    if sig:
        params = sig.group(2).strip()
        s['params'] = len([p for p in params.split(',') if p.strip() and p.strip() != 'void']) if params and params != 'void' else 0
    else:
        s['params'] = 0

    # Return type
    s['returns_void'] = 1 if re.match(r'\bvoid\b\s+\w+\s*\(', code) else 0

    # Control flow
    s['ifs'] = len(re.findall(r'\bif\s*\(', code))
    s['whiles'] = len(re.findall(r'\bwhile\s*\(', code))
    s['fors'] = len(re.findall(r'\bfor\s*\(', code))
    s['switches'] = len(re.findall(r'\bswitch\s*\(', code))
    s['cases'] = len(re.findall(r'\bcase\b', code))
    s['returns'] = len(re.findall(r'\breturn\b', code))

    # Function calls
    all_calls = len(re.findall(r'\b[a-zA-Z_]\w*\s*\(', code))
    keywords = s['ifs'] + s['whiles'] + s['fors'] + s['switches'] + len(re.findall(r'\bsizeof\s*\(', code))
    s['total_calls'] = max(0, all_calls - keywords)

    # Local variables
    decls = len(re.findall(r'\b(?:int|UINT|uint|UINT16|UINT32|UINT8|uint16|uint32|uint8|SHORT|short|CHAR|char|BOOL|BOOLEAN|float|double|long|LONG)\s+\w+', code))
    s['locals'] = decls

    s['code_size'] = len(code)

    return s


def structural_distance(bin_s, sdk_s):
    """Compute structural distance between binary and SDK function.
    Lower is better. Returns a score where higher is better.
    """
    # Weighted sum of squared differences
    score = 0

    # Parameter count (strong signal)
    if bin_s['params'] == sdk_s['params']:
        score += 10
    elif abs(bin_s['params'] - sdk_s['params']) <= 1:
        score += 5

    # Return type (strong signal)
    if bin_s['returns_void'] == sdk_s['returns_void']:
        score += 5

    # Control flow (medium signal)
    for key in ['ifs', 'whiles', 'fors', 'switches', 'cases', 'returns']:
        bv = bin_s.get(key, 0)
        sv = sdk_s.get(key, 0)
        if bv == sv and bv > 0:
            score += 3
        elif bv > 0 or sv > 0:
            max_v = max(bv, sv)
            diff = abs(bv - sv)
            score += max(0, (1 - diff / max_v) * 3)

    # Call count (medium signal)
    bc = bin_s.get('total_calls', 0)
    sc = sdk_s.get('total_calls', 0)
    if bc > 0 and sc > 0:
        max_c = max(bc, sc)
        diff = abs(bc - sc)
        score += (1 - diff / max_c) * 5
    elif bc == 0 and sc == 0:
        score += 2

    # Local variable count (weak signal)
    bl = bin_s.get('locals', 0)
    sl = sdk_s.get('locals', 0)
    if bl > 0 and sl > 0:
        max_l = max(bl, sl)
        diff = abs(bl - sl)
        score += (1 - diff / max_l) * 2

    # Code size ratio (weak signal)
    bs = bin_s.get('code_size', 0)
    ss = sdk_s.get('code_size', 0)
    if bs > 0 and ss > 0:
        ratio = min(bs, ss) / max(bs, ss)
        score += ratio * 3

    return score


def main():
    # Load SDK features
    sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))
    print(f"SDK functions: {len(sdk_features)}")

    # Pre-compute SDK structural fingerprints
    sdk_structures = {}
    for name, feats in sdk_features.items():
        src_path = ROOT / feats.get("source_file", "")
        if not src_path.exists():
            continue
        code = src_path.read_text(encoding="utf-8", errors="ignore")
        # Find the function body
        import re
        pattern = rf'\b{re.escape(name)}\s*\([^)]*\)\s*\{{'
        match = re.search(pattern, code)
        if not match:
            continue
        # Extract function body
        brace_count = 0
        start = match.start()
        for i in range(match.end() - 1, min(match.end() + 5000, len(code))):
            if code[i] == '{':
                brace_count += 1
            elif code[i] == '}':
                brace_count -= 1
            if brace_count == 0:
                func_code = code[start:i+1]
                break
        else:
            continue

        sdk_structures[name] = extract_sdk_structure(func_code)
        sdk_structures[name]['source_file'] = feats.get('source_file', '')

    print(f"SDK functions with structure: {len(sdk_structures)}")

    # Load decompiled binary functions
    decomp = json.loads((ROOT / "build" / "all_decompilations.json").read_text(encoding="utf-8"))
    print(f"Decompiled binary functions: {len(decomp)}")

    # Get current named functions
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named_addrs = set(f["address"] for f in all_funcs
                      if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Already named: {len(named_addrs)}")

    # Extract binary structures and match
    print("\nMatching by structure...")
    candidates = []

    for func_name, info in decomp.items():
        addr = info.get("address", "")
        if addr in named_addrs:
            continue

        code = info.get("code", "")
        if not code or len(code) < 50:
            continue

        bin_struct = extract_binary_structure(code)

        # Skip tiny functions (too ambiguous)
        if bin_struct['code_size'] < 100 and bin_struct['total_calls'] < 2:
            continue

        # Find best SDK match
        best_match = None
        best_score = 0
        for sdk_name, sdk_struct in sdk_structures.items():
            score = structural_distance(bin_struct, sdk_struct)
            if score > best_score:
                best_score = score
                best_match = sdk_name

        # Only keep high-scoring matches with enough structural complexity
        min_complexity = bin_struct['ifs'] + bin_struct['whiles'] + bin_struct['fors'] + bin_struct['switches'] + bin_struct['total_calls']
        if best_match and best_score >= 20 and min_complexity >= 5:
            candidates.append({
                "binary_func": func_name,
                "binary_addr": addr,
                "sdk_func": best_match,
                "score": best_score,
                "bin_params": bin_struct['params'],
                "sdk_params": sdk_structures[best_match]['params'],
                "bin_ifs": bin_struct['ifs'],
                "sdk_ifs": sdk_structures[best_match]['ifs'],
                "bin_calls": bin_struct['total_calls'],
                "sdk_calls": sdk_structures[best_match]['total_calls'],
                "bin_size": bin_struct['code_size'],
                "sdk_size": sdk_structures[best_match]['code_size'],
                "sdk_source": sdk_structures[best_match]['source_file'],
            })

    print(f"Candidates: {len(candidates)}")

    # Uniqueness constraint: for each SDK function, keep only the best match
    sdk_to_candidates = defaultdict(list)
    for c in candidates:
        sdk_to_candidates[c["sdk_func"]].append(c)

    final_matches = []
    for sdk, matches in sdk_to_candidates.items():
        matches.sort(key=lambda x: -x["score"])
        if len(matches) == 1:
            final_matches.append(matches[0])
        else:
            # Keep best only if significantly better than second
            best = matches[0]
            if len(matches) == 2:
                second = matches[1]
                if best["score"] > second["score"] * 1.2:
                    final_matches.append(best)
            else:
                second = matches[1]
                if best["score"] > second["score"] * 1.3:
                    final_matches.append(best)

    final_matches.sort(key=lambda x: -x["score"])
    print(f"Final unique matches: {len(final_matches)}")

    # Show top matches
    print("\nTop 40 matches:")
    for m in final_matches[:40]:
        print(f"  {m['binary_func']:25s} -> {m['sdk_func']:30s} score={m['score']:.1f} "
              f"params={m['bin_params']}/{m['sdk_params']} ifs={m['bin_ifs']}/{m['sdk_ifs']} "
              f"calls={m['bin_calls']}/{m['sdk_calls']} size={m['bin_size']}/{m['sdk_size']} "
              f"src={m['sdk_source']}")

    # Rename in Ghidra
    print(f"\nRenaming {len(final_matches)} functions...")
    renamed = 0
    for m in final_matches:
        result = rename_function(m["binary_addr"], m["sdk_func"])
        if "error" not in result.lower():
            renamed += 1
        time.sleep(0.05)

    print(f"\n=== STRUCTURAL MATCHING SUMMARY ===")
    print(f"Functions renamed: {renamed}")

    # Final count
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    # Save
    out = ROOT / "build" / "structural_matches.json"
    out.write_text(json.dumps(final_matches, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
