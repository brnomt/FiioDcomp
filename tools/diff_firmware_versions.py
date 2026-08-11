#!/usr/bin/env python3
"""
diff_firmware_versions.py — Compare any two Echo Mini firmware versions.

Usage:
    python tools/diff_firmware_versions.py 3.6.0 3.7.0

Diffs the main firmware code section between two IMGs, reports changed
regions, and cross-references known symbols so changelog items can be
mapped to functions.
"""
from __future__ import annotations

import glob
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
STOCK = ROOT / "stock"

# Known IMG layout (from decomp docs — verify per version)
SECTIONS = [
    ("outer_header_reloc", 0x00000000, 0x00057820),
    ("bootloader", 0x00057820, 0x00081A14),
    ("main_fw_code", 0x00081A14, 0x009BAA0E),
    ("resources_part5", 0x009BAA0E, 0x01FC41F8),
    ("padding", 0x01FC41F8, 0x2000000),
    ("trailer", 0x2000000, 0x2000004),
]

# Base load address of section_3 → file offset mapping
IMG_SECTION3_OFF = 0x00081A14
LOAD_BASE = 0x03000000


def find_img(version: str) -> Path:
    """Locate the .IMG file for a version."""
    candidates = glob.glob(str(STOCK / version / "**" / "*.IMG"), recursive=True)
    if not candidates:
        candidates = glob.glob(str(STOCK / version / "**" / "*.img"), recursive=True)
    if not candidates:
        sys.exit(f"ERROR: No IMG found for version {version} in {STOCK / version}")
    return Path(candidates[0])


def img_off(load_addr: int) -> int:
    return load_addr - LOAD_BASE + IMG_SECTION3_OFF


def count_diff(a: bytes, b: bytes, s: int, e: int) -> int:
    e = min(e, len(a))
    s = min(s, len(a))
    return sum(1 for i in range(s, e) if a[i] != b[i])


def diff_regions(a: bytes, b: bytes, s: int, e: int, min_len: int = 4) -> list:
    """Return list of (start, end) changed regions in [s, e)."""
    regions = []
    i = s
    while i < e:
        if a[i] != b[i]:
            j = i
            while j < e and a[j] != b[j]:
                j += 1
            if j - i >= min_len:
                regions.append((i, j))
            i = j
        else:
            i += 1
    return regions


# Symbol table: name -> load address (from docs/symbol-index.md)
SYMBOLS = [
    # Audio services
    ("firmware_entry", 0x03000010),
    ("MusicInit", 0x0302B9D8),
    ("MusicService_Init", 0x0302A3E0),
    ("AudioPlayback_Start", 0x0302A398),
    ("AudioPause", 0x0302A69E),
    ("audiocodec_open", 0x03029D0E),
    ("USB_DAC_OpenStream", 0x0302B80A),
    ("FormatList_Init", 0x03013C10),
    # DSP
    ("DSP_GOODEF_Init", 0x0300F7DC),
    ("DSP_GOODEF_Process", 0x0300FB0E),
    ("DSP_GOODEF_Reload", 0x0301022C),
    # Codecs
    ("mp3_dec_internal", 0x0306E5DE),
    ("mp3_id3v2_handler", 0x0306FEC4),
    ("wma_audio_parse", 0x0308CDDC),
    ("aac_aac_dec", 0x030AD690),
    ("aac_movfile_parser", 0x030AEB90),
    ("hifi_flac_dec", 0x030DF64C),
    ("wav_lib_decode", 0x030A42EE),
    ("VorbisOGG_Parser", 0x03023BE8),
    ("APE_Codec_Open", 0x030EEF60),
    ("DSD_DecodeBlock", 0x030FFA3C),
    ("ID3_Picture_Parser", 0x03023526),
    ("DICTDECODER_InitStream", 0x0304FB44),
    # Media / tags
    ("OGG_Picture_Metadata", 0x030059D6),
    # UI
    ("MainUI_KeyHandler", 0x0301020C),
    ("BroMemSelKeyMenu_Handler", 0x03013280),
    ("FLAC_ThemeColor_Select", 0x030054BA),
    # BT / record
    ("BT_Music_Handler", 0x0300DDEA),
    ("RecordWinSvc_Start", 0x0300AABC),
    # FS
    ("HifiFileSeek", 0x0306B8E6),
    ("HifiFileRead", 0x0306B94C),
    ("MediaLib_GetTotalFiles", 0x03000F94),
    # OS
    ("event_set", 0x03073840),
    ("hifi_busy_delay", 0x0306C2E8),
    ("hifi_debug_printf", 0x0306C07E),
    ("ipc_post_cmd", 0x03073C7C),
    # SDK-matched
    ("rk_printf", 0x03000E08),
    ("SDC_Init", 0x03004612),
    ("SNAND_Write", 0x03019246),
    ("OGGInfo_Parse", 0x0301930E),
    ("dhcpd_add_option", 0x0301A30E),
    ("DisplayDev_ClrRect", 0x0301C978),
    ("SNOR_Erase", 0x030264DC),
    ("ScuClockGateCtr", 0x03029822),
    ("TransCodeFromUTF8ToUnicode", 0x0302CAB0),
    ("FatDev_FileSeek", 0x0304ED3E),
    ("FATDelClusChain", 0x030644C4),
    ("SDC_UpdateFreq", 0x03082BFA),
    ("GUI_Setfocus", 0x0308CB4C),
    ("SNOR_Init", 0x0308EAF2),
    ("FSRealname", 0x030B1328),
    ("FW_Ansi2Unicode", 0x030C4DEC),
    ("APEV1_Parse", 0x030CB34A),
    ("SDC_WriteData", 0x030F0384),
]


def main() -> None:
    if len(sys.argv) < 3:
        sys.exit(f"Usage: {sys.argv[0]} <old_version> <new_version> [--regions]")

    old_v, new_v = sys.argv[1], sys.argv[2]
    show_regions = "--regions" in sys.argv

    old_img = find_img(old_v)
    new_img = find_img(new_v)
    print(f"Comparing: {old_v} ({old_img.name})  vs  {new_v} ({new_img.name})\n")

    old = old_img.read_bytes()
    new = new_img.read_bytes()

    if len(old) != len(new):
        print(f"WARNING: Sizes differ! {old_v}={len(old):,}  {new_v}={len(new):,}")
        size = min(len(old), len(new))
    else:
        size = len(old)
        print(f"Size: {len(old):,} bytes (identical)")

    if len(old) >= 4 and len(new) >= 4:
        t_old = struct.unpack("<I", old[-4:])[0]
        t_new = struct.unpack("<I", new[-4:])[0]
        print(f"EOF trailer: {old_v} = 0x{t_old:08X}   {new_v} = 0x{t_new:08X}\n")

    print("| Section | IMG range | Changed | % |")
    print("|---------|-----------|---------|---|")
    for name, s, e in SECTIONS:
        n = min(e, size) - s
        if n <= 0:
            continue
        c = count_diff(old, new, s, min(e, size))
        print(f"| {name} | `0x{s:08X}`-`0x{min(e,size):08X}` | {c:,} | {100 * c / n:.2f}% |")

    total = count_diff(old, new, 0, size)
    print(f"\n**Total changed:** {total:,} / {size:,} ({100 * total / size:.2f}%)")

    # Per-symbol change windows
    main_start, main_end = 0x00081A14, min(0x009BAA0E, size)
    print("\n## Known symbols — change window (4 KiB around each)\n")
    print("| Symbol | Load addr | Bytes changed in 4KiB window |")
    print("|--------|-----------|------------------------------|")
    for name, load in SYMBOLS:
        off = img_off(load)
        if off < main_start or off >= main_end:
            continue
        c = count_diff(old, new, off, off + 4096)
        if c > 0:
            print(f"| {name} | `0x{load:08X}` | {c:,} |")

    if show_regions:
        print(f"\n## Changed regions in main_fw_code (min 64 bytes)\n")
        regions = diff_regions(old, new, main_start, main_end, min_len=64)
        print(f"Total regions: {len(regions)}")
        for r_start, r_end in regions[:100]:
            load = r_start - IMG_SECTION3_OFF + LOAD_BASE
            print(f"- `0x{r_start:08X}`-`0x{r_end:08X}`  (load `0x{load:08X}`, {r_end - r_start} bytes)")


if __name__ == "__main__":
    main()
