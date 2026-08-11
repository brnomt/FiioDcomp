#!/usr/bin/env python3
"""
propagate_callgraph.py — Propagate function names through the call graph.

Algorithm:
  1. For each named binary function that has an SDK equivalent (same name):
     a. Get its binary callees (from Ghidra)
     b. Get its SDK callees (from sdk_callees.json)
     c. Match unnamed binary callees to unmatched SDK callees
  2. The simplest case: 1 unnamed binary callee + 1 unmatched SDK callee = direct match
  3. For multiple matches, use elimination (if N-1 are already named, the last one is determined)
"""
import json, time, urllib.request, urllib.parse
from pathlib import Path
from collections import defaultdict

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]


def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    resp = urllib.request.urlopen(url, timeout=60)
    return resp.read().decode("utf-8", errors="ignore")


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


def get_callees(address):
    """Get callees of a function. Returns list of (name, address) tuples."""
    try:
        result = _get("/get_function_callees", {"address": "0x" + address})
        callees = []
        for line in result.strip().split("\n"):
            line = line.strip()
            if not line or line.startswith("{") or "error" in line.lower():
                continue
            if " @ " in line:
                parts = line.split(" @ ")
                name = parts[0].strip()
                addr = parts[1].strip().lstrip("0x").lower()
                callees.append((name, addr))
        return callees
    except:
        return []


def main():
    # Load SDK callees index
    sdk_callees = json.loads((ROOT / "build" / "sdk_callees.json").read_text(encoding="utf-8"))
    print(f"SDK functions with callees: {len(sdk_callees)}")

    # Get all functions from Ghidra
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)

    # Build maps
    addr_to_name = {}
    name_to_addr = {}
    for f in all_funcs:
        addr = f["address"]
        name = f.get("name", "")
        addr_to_name[addr] = name
        if not name.startswith("FUN_") and not name.startswith("LAB_"):
            name_to_addr[name] = addr

    named_funcs = [(addr, name) for addr, name in addr_to_name.items()
                   if not name.startswith("FUN_") and not name.startswith("LAB_")]
    print(f"Named binary functions: {len(named_funcs)}")

    # Find named binary functions that have SDK equivalents
    anchors = []
    for addr, name in named_funcs:
        if name in sdk_callees:
            anchors.append((addr, name))
    print(f"Anchor functions (named in both binary and SDK): {len(anchors)}")

    # For each anchor, try to propagate names to unnamed callees
    print("\nPropagating through call graph...")
    rename_candidates = {}  # binary_addr -> sdk_callee_name (with vote count)
    candidate_votes = defaultdict(lambda: defaultdict(int))  # addr -> {name: votes}

    processed = 0
    for addr, name in anchors:
        processed += 1
        if processed % 50 == 0:
            print(f"  Processed {processed}/{len(anchors)} anchors...")

        # Get binary callees
        bin_callees = get_callees(addr)
        if not bin_callees:
            continue

        # Split into named and unnamed
        unnamed_bin = [(n, a) for n, a in bin_callees if n.startswith("FUN_")]
        named_bin = [(n, a) for n, a in bin_callees if not n.startswith("FUN_") and not n.startswith("LAB_")]

        if not unnamed_bin:
            continue

        # Get SDK callees
        sdk_calls = sdk_callees.get(name, [])
        # Remove self-reference (function calling itself)
        sdk_calls = [c for c in sdk_calls if c != name]
        if not sdk_calls:
            continue

        # Filter SDK callees: remove those already named in binary
        unmatched_sdk = [c for c in sdk_calls if c not in name_to_addr and c in sdk_callees]
        # Also include SDK callees that aren't in our index at all (they might be library functions)
        unmatched_sdk_all = [c for c in sdk_calls if c not in name_to_addr]

        if not unmatched_sdk_all:
            continue

        # Case 1: Exactly 1 unnamed binary callee and 1 unmatched SDK callee
        if len(unnamed_bin) == 1 and len(unmatched_sdk_all) == 1:
            bin_addr = unnamed_bin[0][1]
            sdk_name = unmatched_sdk_all[0]
            candidate_votes[bin_addr][sdk_name] += 3  # High confidence
            continue

        # Case 2: Same count of unnamed binary callees and unmatched SDK callees
        if len(unnamed_bin) == len(unmatched_sdk_all) and len(unnamed_bin) <= 3:
            # Positional matching (less confident)
            for i, (bin_name, bin_addr) in enumerate(unnamed_bin):
                if i < len(unmatched_sdk_all):
                    sdk_name = unmatched_sdk_all[i]
                    candidate_votes[bin_addr][sdk_name] += 1
            continue

        # Case 3: More unnamed binary callees than unmatched SDK callees
        # Try elimination: if we can identify some, the rest are determined
        if len(unnamed_bin) > len(unmatched_sdk_all) and len(unmatched_sdk_all) <= 2:
            # Can't easily determine which is which — skip
            continue

        # Case 4: Fewer unnamed binary callees than unmatched SDK callees
        # Some SDK callees might be inlined or optimized away
        if len(unnamed_bin) < len(unmatched_sdk_all) and len(unnamed_bin) == 1:
            # Only 1 unnamed binary callee but multiple SDK candidates — skip (ambiguous)
            continue

    # Resolve candidates: only keep unambiguous votes
    final_renames = {}
    for addr, votes in candidate_votes.items():
        if len(votes) == 1:
            # Unambiguous — only one SDK name suggested
            name, vote_count = list(votes.items())[0]
            final_renames[addr] = (name, vote_count)
        else:
            # Multiple suggestions — keep the one with most votes
            best_name = max(votes, key=votes.get)
            best_votes = votes[best_name]
            second_votes = sorted(votes.values(), reverse=True)[1] if len(votes) > 1 else 0
            if best_votes > second_votes * 2:  # Need 2x more votes than second
                final_renames[addr] = (best_name, best_votes)

    print(f"\nRename candidates: {len(final_renames)}")

    # Show candidates
    sorted_renames = sorted(final_renames.items(), key=lambda x: -x[1][1])
    print("\nTop 40 rename candidates:")
    for addr, (name, votes) in sorted_renames[:40]:
        current = addr_to_name.get(addr, "???")
        print(f"  {current:25s} @ {addr} -> {name:30s} (votes={votes})")

    # Rename in Ghidra
    print(f"\nRenaming {len(final_renames)} functions...")
    renamed = 0
    for addr, (name, votes) in final_renames.items():
        # Apply all candidates with votes >= 1 (1-vote matches are still useful
        # for common library functions like memcpy, memset, strlen, etc.)
        if votes >= 1:
            result = rename_function(addr, name)
            if "error" not in result.lower():
                renamed += 1
            time.sleep(0.05)

    print(f"\n=== CALL GRAPH PROPAGATION SUMMARY ===")
    print(f"Functions renamed: {renamed}")

    # Final count
    resp = urllib.request.urlopen(f"{BASE}/list_functions_enhanced", timeout=30)
    data = json.loads(resp.read().decode())
    all_funcs = data.get("functions", data)
    named = sum(1 for f in all_funcs if not f.get("name", "").startswith("FUN_") and not f.get("name", "").startswith("LAB_"))
    print(f"Total: {len(all_funcs)}, Named: {named} ({100*named/len(all_funcs):.1f}%)")

    # Save
    out = ROOT / "build" / "callgraph_propagation_matches.json"
    out.write_text(json.dumps([{ "addr": a, "name": n, "votes": v}
                               for a, (n, v) in final_renames.items()],
                              indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Saved to: {out}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
