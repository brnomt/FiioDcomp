#!/usr/bin/env python3
"""
repair_boundaries.py — Repair oversized function bodies in Ghidra.

Known pattern: some functions (notably hifi_busy_delay_ovl_*) have a body
that starts ~0xB00 before the real entry — the auto-analyzer absorbed the
tail of the previous function. The fix is delete_function + create_function
at the true entry, then disassemble to extend the body.

Uses run_script_inline (Java) which works regardless of the OSGi bundle
cache problem that breaks run_ghidra_script after file edits.

Usage:
    python tools/repair_boundaries.py 0309e334 030bff80 030e4808 030fd100
    (pass --scan to auto-detect all functions with body_min < entry - 0x100)
"""
from __future__ import annotations

import argparse
import json
import re
import sys
import time
import urllib.request
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[0]))

BASE = "http://127.0.0.1:8089"
PROGRAM = "section_3_0x00081A14.bin"

INLINE_TEMPLATE = """
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.symbol.SourceType;
public class RepairBoundary extends GhidraScript {
    public void run() throws Exception {
        Address entry = toAddr("{entry}");
        FunctionManager fm = currentProgram.getFunctionManager();
        var f = fm.getFunctionAt(entry);
        String name = f != null ? f.getName() : null;
        if (f != null) {{ fm.removeFunction(entry); println("REMOVED " + name); }}
        var nf = fm.createFunction(null, entry, new AddressSet(entry), SourceType.USER_DEFINED);
        if (nf != null) {{ if (name != null) nf.setName(name, SourceType.USER_DEFINED); println("RECREATED " + name); }}
        else println("FAILED");
    }
}
"""


def get(url: str) -> str:
    return urllib.request.urlopen(url, timeout=60).read().decode("utf-8", errors="replace")


def post_json(path: str, data: dict):
    req = urllib.request.Request(f"{BASE}{path}", data=json.dumps(data).encode(),
                                 headers={"Content-Type": "application/json"}, method="POST")
    raw = urllib.request.urlopen(req, timeout=180).read().decode("utf-8", errors="replace")
    try:
        return json.loads(raw)
    except Exception:
        return {"console_output": raw}


def function_body(addr: str):
    r = get(f"{BASE}/get_function_by_address?address={addr}")
    for line in r.splitlines():
        if line.startswith("Body:"):
            m = re.search(r"Body:\s*(\w+)\s*-\s*(\w+)", line)
            if m:
                return m.group(1), m.group(2)
    return None, None


def repair(entry: str, dry_run: bool = False) -> str:
    body_min, _ = function_body(entry)
    if not body_min:
        return f"{entry}: no function found"
    delta = int(entry, 16) - int(body_min, 16)
    if delta <= 8:
        return f"{entry}: boundary OK (delta={delta})"
    print(f"{entry}: repairing (body started {body_min}, delta=0x{delta:x})")
    if dry_run:
        return f"{entry}: DRY-RUN would repair (delta=0x{delta:x})"
    res = post_json("/run_script_inline?program=" + PROGRAM,
                    {"code": INLINE_TEMPLATE.replace("{entry}", entry), "args": ""})
    out = res.get("console_output", "") or str(res)
    ok = "RECREATED" in out and "FAILED" not in out
    if ok:
        # disassemble to extend the body
        try:
            urllib.request.urlopen(f"{BASE}/disassemble_function?address={entry}", timeout=60)
        except Exception:
            pass
        bmin, bmax = function_body(entry)
        return f"{entry}: REPAIRED (body now {bmin}-{bmax})"
    return f"{entry}: FAILED ({out[-200:]})"


def scan() -> list[str]:
    """Find all functions whose body starts more than 0x100 before entry."""
    sys.path.insert(0, str(Path(__file__).resolve().parents[0]))
    import ghidra_client as gc
    gc._get("/switch_program", {"program": PROGRAM})
    d = gc._get("/list_functions_enhanced")
    suspicious = []
    for f in d.get("functions", []):
        addr = f.get("address", "")
        try:
            if not (0x03000000 <= int(addr, 16) <= 0x03110000):
                continue
        except Exception:
            continue
        bmin, _ = function_body(addr)
        if bmin:
            delta = int(addr, 16) - int(bmin, 16)
            if delta > 0x100:
                suspicious.append(addr)
    return suspicious


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("entries", nargs="*", help="function entry addresses to repair")
    parser.add_argument("--scan", action="store_true", help="auto-detect oversized bodies")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    entries = list(args.entries)
    if args.scan:
        found = scan()
        print(f"scanned: {len(found)} functions with oversized bodies")
        for a in found:
            print(f"  {a}")
        entries = found

    for e in entries:
        print(repair(e, args.dry_run))
        time.sleep(0.5)

    # save
    res = post_json("/save_program", {})
    print("save:", res.get("success"))


if __name__ == "__main__":
    main()
