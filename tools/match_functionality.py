#!/usr/bin/env python3
"""
match_functionality.py — Match binary functions to SDK functions by
behavioral fingerprint (constants + control flow + call structure).

This bypasses the naming gap: functions are matched by WHAT THEY DO,
not what they're called.
"""
import re, json, time, urllib.request, urllib.parse
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


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


def extract_binary_features(code):
    """Extract behavioral features from decompiled C code."""
    features = {}

    # Control flow
    features['ifs'] = len(re.findall(r'\bif\s*\(', code))
    features['elses'] = len(re.findall(r'\belse\b', code))
    features['whiles'] = len(re.findall(r'\bwhile\s*\(', code))
    features['fors'] = len(re.findall(r'\bfor\s*\(', code))
    features['switches'] = len(re.findall(r'\bswitch\s*\(', code))
    features['cases'] = len(re.findall(r'\bcase\b', code))
    features['returns'] = len(re.findall(r'\breturn\b', code))

    # Function calls (FUN_, func_, rom_, known names)
    features['calls_fun'] = len(re.findall(r'\bFUN_\w+\s*\(', code))
    features['calls_func'] = len(re.findall(r'\bfunc_0x\w+\s*\(', code))
    features['calls_rom'] = len(re.findall(r'\brom_\w+\s*\(', code))
    features['calls_named'] = len(re.findall(r'\b[a-zA-Z]\w+\s*\(', code)) - features['calls_fun'] - features['calls_func'] - features['calls_rom']

    # Constants — hex literals
    constants = set()
    for m in re.finditer(r'\b0x([0-9a-fA-F]+)\b', code):
        val = int(m.group(1), 16)
        if 2 <= val <= 0xFFFFFF:
            constants.add(val)
    # Decimal literals (not in addresses)
    for m in re.finditer(r'\b(\d{2,})\b', code):
        val = int(m.group(1))
        if 2 <= val <= 0xFFFF:
            constants.add(val)

    features['constants'] = sorted(constants)
    features['num_constants'] = len(constants)

    # Data references (DAT_*)
    features['data_refs'] = len(set(re.findall(r'\bDAT_[0-9a-f]+\b', code)))

    # Parameter count (from function signature)
    sig_match = re.match(r'\w+\s+FUN_\w+\s*\(([^)]*)\)', code)
    if sig_match:
        params = sig_match.group(1).strip()
        if params and params != 'void':
            features['param_count'] = len([p for p in params.split(',') if p.strip() and p.strip() != 'void'])
        else:
            features['param_count'] = 0
    else:
        features['param_count'] = 0

    return features


def compute_similarity(bin_feats, sdk_feats):
    """Compute similarity score between binary and SDK function features."""
    score = 0

    # Constant set overlap (most important signal)
    bin_consts = set(bin_feats.get('constants', []))
    sdk_consts = set(sdk_feats.get('constants', []))

    if bin_consts and sdk_consts:
        overlap = bin_consts & sdk_consts
        # Jaccard similarity
        union = bin_consts | sdk_consts
        if union:
            const_score = len(overlap) / len(union)
            # Weight by number of overlapping constants
            score += const_score * 10 + len(overlap) * 2

    # Control flow similarity
    for key in ['ifs', 'whiles', 'fors', 'switches', 'cases', 'returns']:
        bin_val = bin_feats.get(key, 0)
        sdk_val = sdk_feats.get(key, 0)
        if bin_val > 0 or sdk_val > 0:
            diff = abs(bin_val - sdk_val)
            max_val = max(bin_val, sdk_val)
            if max_val > 0:
                score += (1 - diff / max_val) * 3

    # Call count similarity
    bin_calls = bin_feats.get('calls_fun', 0) + bin_feats.get('calls_func', 0) + bin_feats.get('calls_rom', 0) + bin_feats.get('calls_named', 0)
    sdk_calls = sdk_feats.get('calls', 0)
    if bin_calls > 0 and sdk_calls > 0:
        diff = abs(bin_calls - sdk_calls)
        max_val = max(bin_calls, sdk_calls)
        score += (1 - diff / max_val) * 2

    # Parameter count similarity
    bin_params = bin_feats.get('param_count', 0)
    sdk_params = sdk_feats.get('param_count', 0)
    if bin_params == sdk_params:
        score += 3
    elif abs(bin_params - sdk_params) <= 1:
        score += 1

    return score


def main():
    # Load SDK features
    sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))
    print(f"SDK functions with features: {len(sdk_features)}")

    # Load decompiled binary functions
    decomp = json.loads((ROOT / "build" / "all_decompilations.json").read_text(encoding="utf-8"))
    print(f"Decompiled binary functions: {len(decomp)}")

    # Get current named functions (to skip already-named)
    result = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(result.read().decode())
    all_funcs = data.get("functions", data)
    named_addrs = set(f["address"] for f in all_funcs
                      if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))

    # Extract features for each binary function and match
    print("\nMatching by functionality...")
    matches = []
    skipped = 0

    for func_name, info in decomp.items():
        addr = info.get("address", "")
        if addr in named_addrs:
            skipped += 1
            continue

        code = info.get("code", "")
        if not code or len(code) < 50:
            continue

        bin_feats = extract_binary_features(code)

        # Skip functions with no constants and few features (too ambiguous)
        if bin_feats['num_constants'] < 2 and bin_feats['ifs'] < 1:
            continue

        # Find best SDK match
        best_match = None
        best_score = 0
        for sdk_name, sdk_feats in sdk_features.items():
            score = compute_similarity(bin_feats, sdk_feats)
            if score > best_score:
                best_score = score
                best_match = sdk_name

        if best_match and best_score >= 15:  # Threshold for confident match
            matches.append({
                "binary_func": func_name,
                "binary_addr": addr,
                "sdk_func": best_match,
                "score": best_score,
                "bin_consts": bin_feats.get('constants', [])[:10],
                "bin_ifs": bin_feats.get('ifs', 0),
                "bin_calls": bin_feats.get('calls_fun', 0) + bin_feats.get('calls_func', 0) + bin_feats.get('calls_rom', 0) + bin_feats.get('calls_named', 0),
                "bin_params": bin_feats.get('param_count', 0),
                "sdk_params": sdk_features[best_match].get('param_count', 0),
                "sdk_source": sdk_features[best_match].get('source_file', ''),
            })

    print(f"Skipped (already named): {skipped}")
    print(f"Confident matches: {len(matches)}")

    # Sort by score
    matches.sort(key=lambda m: -m["score"])

    # Show top matches
    print("\nTop 30 matches:")
    for m in matches[:30]:
        print(f"  {m['binary_func']:25s} -> {m['sdk_func']:30s} score={m['score']:.1f} "
              f"consts={m['bin_consts'][:5]} ifs={m['bin_ifs']} calls={m['bin_calls']} "
              f"params={m['bin_params']}/{m['sdk_params']} src={m['sdk_source']}")

    # Rename in Ghidra
    print(f"\nRenaming {len(matches)} functions in Ghidra...")
    renamed = 0
    for m in matches:
        result = rename_function(m["binary_addr"], m["sdk_func"])
        if "error" not in result.lower():
            renamed += 1
        time.sleep(0.05)

    print(f"\n=== SUMMARY ===")
    print(f"Functions renamed by functionality matching: {renamed}")

    # Final count
    result = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(result.read().decode())
    all_funcs = data.get("functions", data)
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    # Save results
    out = ROOT / "build" / "functionality_matches.json"
    out.write_text(json.dumps(matches, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
