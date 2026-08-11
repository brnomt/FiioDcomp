#!/usr/bin/env python3
"""
export_named_flac.py — Export the newly named v3.6.0-introduced FLAC decoder
functions (v3.7.0 primary program) to firmware/codecs/flac/.

These functions were named via changelog-anchored lineage analysis
(function introduced in v3.6.0 = FLAC decoder rewrite per changelog +
string diff). Decompiles live from Ghidra and writes .c files.
"""
import json
import re
import urllib.request
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "firmware" / "codecs" / "flac"

# name -> v3.7.0 address
FUNCS = {
    "flac_bs_bswap32": "030dd6d0",
    "flac_clz32": "030dd956",
    "flac_bs_getbits_u": "030dd842",
    "flac_bs_init": "030dd888",
    "flac_bs_getbits_s": "030df3ae",
    "flac_bs_getbits_u_wide": "030df46c",
    "flac_frame_header_parse": "030df30e",
    "flac_decode_subframe": "030ded62",
    "flac_decode_frame": "030df9fa",
    "flac_decode_residual": "030def58",
    "flac_lpc_compute": "030ddd0a",
    "flac_hifi_cfg_write": "030de824",
    "flac_hifi_ctrl_clear": "030e0920",
    "flac_hifi_ctrl_set": "030e0936",
}

TAGS = {
    "flac_bs_bswap32": "codec, flac, bitstream",
    "flac_clz32": "codec, flac, util",
    "flac_bs_getbits_u": "codec, flac, bitstream",
    "flac_bs_init": "codec, flac, bitstream",
    "flac_bs_getbits_s": "codec, flac, bitstream",
    "flac_bs_getbits_u_wide": "codec, flac, bitstream",
    "flac_frame_header_parse": "codec, flac, parser",
    "flac_decode_subframe": "codec, flac, decoder",
    "flac_decode_frame": "codec, flac, decoder",
    "flac_decode_residual": "codec, flac, decoder",
    "flac_lpc_compute": "codec, flac, lpc",
    "flac_hifi_cfg_write": "codec, flac, hifi",
    "flac_hifi_ctrl_clear": "codec, flac, hifi",
    "flac_hifi_ctrl_set": "codec, flac, hifi",
}


def decompile(addr: str) -> str:
    url = f"{BASE}/decompile_function?address={addr}"
    return urllib.request.urlopen(url, timeout=90).read().decode("utf-8", errors="replace").strip()


def main():
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for name, addr in FUNCS.items():
        code = decompile(addr)
        header = f"""/**\n * {name} @ 0x{addr}\n * Tags: {TAGS[name]}\n *\n * Introduced in v3.6.0 (FLAC decoder rewrite per changelog + string diff)\n * Named via cross-version lineage analysis; decompiled from Ghidra v3.7.0.\n */\n"""
        out = OUT_DIR / f"{name}.c"
        out.write_text(header + "\n" + code + "\n", encoding="utf-8")
        print(f"  wrote {out.relative_to(ROOT)} ({len(code)} chars)")
    print(f"\nDone: {len(FUNCS)} files in firmware/codecs/flac/")


if __name__ == "__main__":
    main()
