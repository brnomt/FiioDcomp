#!/usr/bin/env python3
"""
match_combined.py — Combine constant-based and structure-based matching
for more robust function identification.

A function that matches by BOTH constants AND structure is very likely correct.
"""
import re, json, time, urllib.request
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
MIN_DISTINCTIVE_CONST = 0x100


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


def extract_distinctive_constants(code):
    constants = set()
    for m in re.finditer(r"\b0x([0-9a-fA-F]+)\b", code):
        val = int(m.group(1), 16)
        if MIN_DISTINCTIVE_CONST <= val <= 0xFFFFFF:
            constants.add(val)
    clean = re.sub(r"/\*.*?\*/", "", code, flags=re.DOTALL)
    clean = re.sub(r"//.*?$", "", clean, flags=re.MULTILINE)
    clean = re.sub(r'"[^"]*"', '""', clean)
    for m in re.finditer(r"\b(\d{3,})\b", clean):
        val = int(m.group(1))
        if MIN_DISTINCTIVE_CONST <= val <= 0xFFFF:
            constants.add(val)
    return constants


def extract_binary_structure(code):
    s = {}
    sig = re.match(r'\w+\s+FUN_\w+\s*\(([^)]*)\)', code)
    if sig:
        params = sig.group(1).strip()
        s['params'] = len([p for p in params.split(',') if p.strip() and p.strip() != 'void']) if params and params != 'void' else 0
    else:
        s['params'] = 0
    s['returns_void'] = 1 if re.match(r'\bvoid\b\s+FUN_', code) else 0
    s['ifs'] = len(re.findall(r'\bif\s*\(', code))
    s['whiles'] = len(re.findall(r'\bwhile\s*\(', code))
    s['fors'] = len(re.findall(r'\bfor\s*\(', code))
    s['switches'] = len(re.findall(r'\bswitch\s*\(', code))
    s['cases'] = len(re.findall(r'\bcase\b', code))
    s['returns'] = len(re.findall(r'\breturn\b', code))
    all_calls = len(re.findall(r'\b[a-zA-Z_]\w*\s*\(', code))
    s['calls_fun'] = len(re.findall(r'\bFUN_\w+\s*\(', code))
    s['calls_rom'] = len(re.findall(r'\brom_\w+\s*\(', code))
    s['total_calls'] = max(0, all_calls - s['ifs'] - s['whiles'] - s['fors'] - s['switches'])
    s['code_size'] = len(code)
    return s


def main():
    # Load SDK features
    sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))
    for name, feats in sdk_features.items():
        feats['constants_set'] = set(feats.get('constants', []))
    print(f"SDK functions: {len(sdk_features)}")

    # Pre-compute SDK structural fingerprints
    sdk_structures = {}
    for name, feats in sdk_features.items():
        src_path = ROOT / feats.get("source_file", "")
        if not src_path.exists():
            continue
        code = src_path.read_text(encoding="utf-8", errors="ignore")
        pattern = rf'\b{re.escape(name)}\s*\([^)]*\)\s*\{{'
        match = re.search(pattern, code)
        if not match:
            continue
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

        s = {}
        sig = re.match(r'\w[\w\s\*]*?\s+(\w+)\s*\(([^)]*)\)', func_code)
        if sig:
            params = sig.group(2).strip()
            s['params'] = len([p for p in params.split(',') if p.strip() and p.strip() != 'void']) if params and params != 'void' else 0
        else:
            s['params'] = 0
        s['returns_void'] = 1 if re.match(r'\bvoid\b\s+\w+\s*\(', func_code) else 0
        s['ifs'] = len(re.findall(r'\bif\s*\(', func_code))
        s['whiles'] = len(re.findall(r'\bwhile\s*\(', func_code))
        s['fors'] = len(re.findall(r'\bfor\s*\(', func_code))
        s['switches'] = len(re.findall(r'\bswitch\s*\(', func_code))
        s['cases'] = len(re.findall(r'\bcase\b', func_code))
        s['returns'] = len(re.findall(r'\breturn\b', func_code))
        all_calls = len(re.findall(r'\b[a-zA-Z_]\w*\s*\(', func_code))
        keywords = s['ifs'] + s['whiles'] + s['fors'] + s['switches'] + len(re.findall(r'\bsizeof\s*\(', func_code))
        s['total_calls'] = max(0, all_calls - keywords)
        s['code_size'] = len(func_code)
        s['source_file'] = feats.get('source_file', '')
        sdk_structures[name] = s

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

    # Match
    print("\nCombined matching (constants + structure)...")
    candidates = []

    for func_name, info in decomp.items():
        addr = info.get("address", "")
        if addr in named_addrs:
            continue

        code = info.get("code", "")
        if not code or len(code) < 50:
            continue

        bin_consts = extract_distinctive_constants(code)
        bin_struct = extract_binary_structure(code)

        min_complexity = bin_struct['ifs'] + bin_struct['whiles'] + bin_struct['fors'] + bin_struct['switches'] + bin_struct['total_calls']
        if min_complexity < 3:
            continue

        best_match = None
        best_score = 0
        best_const_overlap = set()
        best_struct_score = 0
        best_const_score = 0

        for sdk_name, sdk_feats in sdk_features.items():
            if sdk_name not in sdk_structures:
                continue

            sdk_struct = sdk_structures[sdk_name]
            sdk_consts = sdk_feats.get('constants_set', set())

            # Constant score
            const_overlap = bin_consts & sdk_consts
            const_score = 0
            if const_overlap:
                union = bin_consts | sdk_consts
                jaccard = len(const_overlap) / len(union) if union else 0
                const_score = len(const_overlap) * 8 + jaccard * 10

            # Structure score
            struct_score = 0
            if bin_struct['params'] == sdk_struct['params']:
                struct_score += 10
            elif abs(bin_struct['params'] - sdk_struct['params']) <= 1:
                struct_score += 5

            if bin_struct['returns_void'] == sdk_struct['returns_void']:
                struct_score += 5

            for key in ['ifs', 'whiles', 'fors', 'switches', 'cases', 'returns']:
                bv = bin_struct.get(key, 0)
                sv = sdk_struct.get(key, 0)
                if bv == sv and bv > 0:
                    struct_score += 3
                elif bv > 0 or sv > 0:
                    max_v = max(bv, sv)
                    diff = abs(bv - sv)
                    struct_score += max(0, (1 - diff / max_v) * 3)

            bc = bin_struct.get('total_calls', 0)
            sc = sdk_struct.get('total_calls', 0)
            if bc > 0 and sc > 0:
                max_c = max(bc, sc)
                diff = abs(bc - sc)
                struct_score += (1 - diff / max_c) * 5

            bs = bin_struct.get('code_size', 0)
            ss = sdk_struct.get('code_size', 0)
            if bs > 0 and ss > 0:
                ratio = min(bs, ss) / max(bs, ss)
                struct_score += ratio * 3

            # Combined score: require BOTH signals for high confidence
            # If only one signal is present, lower the score
            combined = 0
            if const_score > 0 and struct_score > 15:
                # Both signals present — high confidence
                combined = const_score + struct_score * 1.5
            elif const_score > 0 and struct_score > 10:
                # Constants + decent structure
                combined = const_score + struct_score
            elif struct_score > 20 and min_complexity >= 8:
                # Strong structure only (no constants)
                combined = struct_score * 0.8

            if combined > best_score:
                best_score = combined
                best_match = sdk_name
                best_const_overlap = const_overlap
                best_struct_score = struct_score
                best_const_score = const_score

        if best_match and best_score >= 25:
            candidates.append({
                "binary_func": func_name,
                "binary_addr": addr,
                "sdk_func": best_match,
                "score": best_score,
                "const_score": best_const_score,
                "struct_score": best_struct_score,
                "overlap_consts": sorted(best_const_overlap),
                "bin_params": bin_struct['params'],
                "sdk_params": sdk_structures[best_match]['params'],
                "bin_ifs": bin_struct['ifs'],
                "sdk_ifs": sdk_structures[best_match]['ifs'],
                "bin_calls": bin_struct['total_calls'],
                "sdk_calls": sdk_structures[best_match]['total_calls'],
                "sdk_source": sdk_structures[best_match]['source_file'],
            })

    print(f"Candidates: {len(candidates)}")

    # Uniqueness constraint
    sdk_to_candidates = defaultdict(list)
    for c in candidates:
        sdk_to_candidates[c["sdk_func"]].append(c)

    final_matches = []
    for sdk, matches in sdk_to_candidates.items():
        matches.sort(key=lambda x: -x["score"])
        if len(matches) == 1:
            final_matches.append(matches[0])
        else:
            best = matches[0]
            second = matches[1]
            if best["score"] > second["score"] * 1.15:
                final_matches.append(best)

    final_matches.sort(key=lambda x: -x["score"])
    print(f"Final unique matches: {len(final_matches)}")

    # Show top matches
    print("\nTop 40 matches:")
    for m in final_matches[:40]:
        print(f"  {m['binary_func']:25s} -> {m['sdk_func']:30s} score={m['score']:.1f} "
              f"const={m['const_score']:.0f} struct={m['struct_score']:.0f} "
              f"overlap={m['overlap_consts'][:5]} "
              f"params={m['bin_params']}/{m['sdk_params']} "
              f"ifs={m['bin_ifs']}/{m['sdk_ifs']} "
              f"calls={m['bin_calls']}/{m['sdk_calls']} "
              f"src={m['sdk_source']}")

    # Rename
    print(f"\nRenaming {len(final_matches)} functions...")
    renamed = 0
    for m in final_matches:
        result = rename_function(m["binary_addr"], m["sdk_func"])
        if "error" not in result.lower():
            renamed += 1
        time.sleep(0.05)

    print(f"\n=== COMBINED MATCHING SUMMARY ===")
    print(f"Functions renamed: {renamed}")

    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    out = ROOT / "build" / "combined_matches.json"
    out.write_text(json.dumps(final_matches, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
