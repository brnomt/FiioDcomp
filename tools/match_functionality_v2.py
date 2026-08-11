#!/usr/bin/env python3
"""
match_functionality_v2.py — Match binary functions to SDK functions by
DISTINCTIVE behavioral fingerprint.

Key improvements over v1:
  - Only use distinctive constants (>= 0x100) — small constants are too generic
  - Require minimum constant overlap (>= 2 distinctive constants shared)
  - Uniqueness constraint: if an SDK function matches multiple binary functions,
    only keep the best-scoring one
  - Higher score threshold
"""
import re, json, time, urllib.request
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

# Constants that are distinctive (not generic loop counters / array indices)
# We want: magic numbers, register addresses, buffer sizes, sample rates, etc.
MIN_DISTINCTIVE_CONST = 0x100  # 256 — below this, constants are too common


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


def extract_distinctive_constants(code):
    """Extract only distinctive constants (>= 0x100) from code."""
    constants = set()
    # Hex literals
    for m in re.finditer(r'\b0x([0-9a-fA-F]+)\b', code):
        val = int(m.group(1), 16)
        if val >= MIN_DISTINCTIVE_CONST and val <= 0xFFFFFF:
            constants.add(val)
    # Decimal literals (>= 256, <= 0xFFFF)
    # Remove comments and strings first
    clean = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    clean = re.sub(r'//.*?$', '', clean, flags=re.MULTILINE)
    clean = re.sub(r'"[^"]*"', '""', clean)
    for m in re.finditer(r'\b(\d{3,})\b', clean):
        val = int(m.group(1))
        if MIN_DISTINCTIVE_CONST <= val <= 0xFFFF:
            constants.add(val)
    return constants


def extract_binary_features(code):
    """Extract behavioral features from decompiled C code."""
    features = {}

    # Control flow
    features['ifs'] = len(re.findall(r'\bif\s*\(', code))
    features['whiles'] = len(re.findall(r'\bwhile\s*\(', code))
    features['fors'] = len(re.findall(r'\bfor\s*\(', code))
    features['switches'] = len(re.findall(r'\bswitch\s*\(', code))
    features['cases'] = len(re.findall(r'\bcase\b', code))
    features['returns'] = len(re.findall(r'\breturn\b', code))

    # Function calls
    features['calls_fun'] = len(re.findall(r'\bFUN_\w+\s*\(', code))
    features['calls_func'] = len(re.findall(r'\bfunc_0x\w+\s*\(', code))
    features['calls_rom'] = len(re.findall(r'\brom_\w+\s*\(', code))
    features['calls_named'] = max(0, len(re.findall(r'\b[a-zA-Z]\w+\s*\(', code)) - features['calls_fun'] - features['calls_func'] - features['calls_rom'])

    # Distinctive constants only
    features['constants'] = extract_distinctive_constants(code)
    features['num_constants'] = len(features['constants'])

    # Data references
    features['data_refs'] = len(set(re.findall(r'\bDAT_[0-9a-f]+\b', code)))

    # Parameter count
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
    """Compute similarity score based on distinctive constants + structure."""
    bin_consts = bin_feats.get('constants', set())
    sdk_consts = set(sdk_feats.get('constants', []))

    # REQUIRE at least 1 distinctive constant to overlap
    overlap = bin_consts & sdk_consts
    if len(overlap) < 1:
        return 0

    score = 0

    # Constant overlap (primary signal)
    # With distinctive constants (>= 0x100), even 1 shared constant is strong evidence
    # Weight by overlap count and Jaccard similarity
    union = bin_consts | sdk_consts
    jaccard = len(overlap) / len(union) if union else 0
    score += len(overlap) * 8  # Each shared distinctive constant is strong evidence
    score += jaccard * 10       # High overlap ratio is even stronger

    # Control flow similarity (secondary signal)
    for key in ['ifs', 'whiles', 'fors', 'switches', 'cases', 'returns']:
        bin_val = bin_feats.get(key, 0)
        sdk_val = sdk_feats.get(key, 0)
        if bin_val > 0 or sdk_val > 0:
            diff = abs(bin_val - sdk_val)
            max_val = max(bin_val, sdk_val)
            if max_val > 0:
                score += (1 - diff / max_val) * 2

    # Call count similarity
    bin_calls = bin_feats.get('calls_fun', 0) + bin_feats.get('calls_func', 0) + bin_feats.get('calls_rom', 0) + bin_feats.get('calls_named', 0)
    sdk_calls = sdk_feats.get('calls', 0)
    if bin_calls > 0 and sdk_calls > 0:
        diff = abs(bin_calls - sdk_calls)
        max_val = max(bin_calls, sdk_calls)
        score += (1 - diff / max_val) * 2

    # Parameter count (strong signal — functions rarely change param count)
    bin_params = bin_feats.get('param_count', 0)
    sdk_params = sdk_feats.get('param_count', 0)
    if bin_params == sdk_params:
        score += 5
    elif abs(bin_params - sdk_params) <= 1:
        score += 2

    return score


def main():
    # Load SDK features
    sdk_features = json.loads((ROOT / "build" / "sdk_features.json").read_text(encoding="utf-8"))
    # Pre-compute SDK distinctive constants as sets
    for name, feats in sdk_features.items():
        feats['constants_set'] = set(feats.get('constants', []))
    print(f"SDK functions with features: {len(sdk_features)}")

    # SDK functions with at least 1 distinctive constant
    sdk_with_consts = {n: f for n, f in sdk_features.items() if len(f.get('constants_set', set())) >= 1}
    print(f"  With >= 1 distinctive constant: {len(sdk_with_consts)}")

    # Load decompiled binary functions
    decomp = json.loads((ROOT / "build" / "all_decompilations.json").read_text(encoding="utf-8"))
    print(f"Decompiled binary functions: {len(decomp)}")

    # Get current named functions (to skip already-named)
    result = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(result.read().decode())
    all_funcs = data.get("functions", data)
    named_addrs = set(f["address"] for f in all_funcs
                      if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Already named: {len(named_addrs)}")

    # Extract features for each binary function and find best SDK match
    print("\nMatching by distinctive constants + structure...")
    # First pass: find all candidate matches
    candidates = []  # list of (bin_addr, bin_func, sdk_name, score, overlap_consts)

    for func_name, info in decomp.items():
        addr = info.get("address", "")
        if addr in named_addrs:
            continue

        code = info.get("code", "")
        if not code or len(code) < 50:
            continue

        bin_feats = extract_binary_features(code)

        # Skip functions with no distinctive constants
        if bin_feats['num_constants'] < 1:
            continue

        # Find best SDK match
        best_match = None
        best_score = 0
        best_overlap = set()
        for sdk_name, sdk_feats in sdk_with_consts.items():
            score = compute_similarity(bin_feats, sdk_feats)
            if score > best_score:
                best_score = score
                best_match = sdk_name
                best_overlap = bin_feats['constants'] & sdk_feats['constants_set']

        if best_match and best_score >= 8:  # Lower threshold for more matches
            candidates.append({
                "binary_func": func_name,
                "binary_addr": addr,
                "sdk_func": best_match,
                "score": best_score,
                "overlap_consts": sorted(best_overlap),
                "bin_consts": sorted(bin_feats['constants']),
                "bin_ifs": bin_feats.get('ifs', 0),
                "bin_calls": bin_feats.get('calls_fun', 0) + bin_feats.get('calls_func', 0) + bin_feats.get('calls_rom', 0) + bin_feats.get('calls_named', 0),
                "bin_params": bin_feats.get('param_count', 0),
                "sdk_params": sdk_features[best_match].get('param_count', 0),
                "sdk_source": sdk_features[best_match].get('source_file', ''),
            })

    print(f"Candidate matches (score >= 8): {len(candidates)}")

    # Uniqueness constraint: for each SDK function, keep only the best binary match
    sdk_to_best = {}
    for c in candidates:
        sdk = c["sdk_func"]
        if sdk not in sdk_to_best or c["score"] > sdk_to_best[sdk]["score"]:
            sdk_to_best[sdk] = c

    # Also filter: if multiple binary functions match the same SDK function with
    # very similar scores, it's ambiguous — skip them
    sdk_to_all = defaultdict(list)
    for c in candidates:
        sdk_to_all[c["sdk_func"]].append(c)

    final_matches = []
    for sdk, all_bin_matches in sdk_to_all.items():
        if len(all_bin_matches) == 1:
            # Unique match — high confidence
            final_matches.append(all_bin_matches[0])
        else:
            # Multiple binary functions matched this SDK function
            # Keep the best only if its score is significantly higher than the second
            all_bin_matches.sort(key=lambda x: -x["score"])
            best = all_bin_matches[0]
            if len(all_bin_matches) == 2:
                second = all_bin_matches[1]
                if best["score"] > second["score"] * 1.3:  # 30% better
                    final_matches.append(best)
            else:
                # 3+ matches — only keep if best is way ahead
                second = all_bin_matches[1]
                if best["score"] > second["score"] * 1.5:
                    final_matches.append(best)

    final_matches.sort(key=lambda x: -x["score"])
    print(f"Final unique matches: {len(final_matches)}")

    # Show top matches
    print("\nTop 40 matches:")
    for m in final_matches[:40]:
        print(f"  {m['binary_func']:25s} -> {m['sdk_func']:30s} score={m['score']:.1f} "
              f"overlap={m['overlap_consts'][:6]} ifs={m['bin_ifs']} "
              f"calls={m['bin_calls']} params={m['bin_params']}/{m['sdk_params']} "
              f"src={m['sdk_source']}")

    # Rename in Ghidra
    print(f"\nRenaming {len(final_matches)} functions in Ghidra...")
    renamed = 0
    for m in final_matches:
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
    out = ROOT / "build" / "functionality_matches_v2.json"
    out.write_text(json.dumps(final_matches, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
