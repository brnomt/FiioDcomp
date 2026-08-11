#!/usr/bin/env python3
"""
download_stock_firmware.py — Fetch every Fiio Echo Mini firmware release from the
official firmware page and lay it out exactly like the repo's stock/ directory:

    stock/<version>/<zip contents>/...

The version folder is normalized to x.y.z (e.g. "ECHO MINI V3.7 512M.zip" becomes
3.7.0, so the 512M and regular zips share the same version folder, just like the
existing stock/3.7.0/ and stock/3.8.0/ folders).

Non-ASCII characters (Chinese / GBK-mojibake) in zip member names are discarded,
so extracted folders come out clean (e.g. "ECHO MINI V3.8.0-8G", not
"ECHO MINI V3.8.0-8G版本" or garbled text).

Pipeline:
  1. Fetch the firmware page and collect all firmware .zip links.
  2. Download every zip into a temporary folder.
  3. Unzip each into stock/<version>/ (skips versions already extracted unless --force).

Usage:
    python tools/download_stock_firmware.py [--dry-run] [--dest DIR]
                                            [--force] [--keep-temp] [--url URL]
"""

import argparse
import os
import re
import shutil
import sys
import tempfile
import time
import urllib.parse
import urllib.request
import zipfile

PAGE_URL = "https://forum.fiio.com/note/showNoteContent.do?id=202501210934383987154"
USER_AGENT = ("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
              "(KHTML, like Gecko) Chrome/120.0 Safari/537.36")
REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_DEST = os.path.join(REPO_ROOT, "stock")

VERSION_RE = re.compile(r"[Vv](\d+(?:\.\d+){0,2})")
ZIP_HREF_RE = re.compile(r'href="([^"]+\.zip)"', re.IGNORECASE)


def normalize_version(raw: str) -> str:
    """Turn '3.7' into '3.7.0', keep '3.8.0' as-is."""
    parts = raw.split(".")
    while len(parts) < 3:
        parts.append("0")
    return ".".join(parts[:3])


def version_key(ver: str):
    return tuple(int(p) for p in ver.split("."))


def fetch_zip_links(url: str):
    """Fetch the firmware page and return the list of firmware .zip URLs."""
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=60) as resp:
        html = resp.read().decode("utf-8", errors="replace")

    links = []
    for m in ZIP_HREF_RE.finditer(html):
        link = m.group(1).replace("&amp;", "&")
        if "MINI" in link.upper():
            links.append(link)
    # Dedupe, preserving first-seen order.
    seen = set()
    return [l for l in links if not (l in seen or seen.add(l))]


def download(url: str, dest_path: str, retries: int = 3) -> bool:
    """Download a zip with retries; verify it is actually a zip file."""
    for attempt in range(1, retries + 1):
        try:
            req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
            with urllib.request.urlopen(req, timeout=180) as resp, \
                    open(dest_path, "wb") as out:
                shutil.copyfileobj(resp, out)
            with open(dest_path, "rb") as f:
                if f.read(2) != b"PK":
                    raise ValueError("download is not a zip file")
            return True
        except Exception as exc:  # noqa: BLE001 - report and retry any error
            if attempt == retries:
                print(f"      FAILED after {retries} attempts: {exc}")
                return False
            print(f"      attempt {attempt}/{retries} failed ({exc}); retrying...")
            time.sleep(2 * attempt)
    return False


def sanitize_name(name: str):
    """Keep ASCII members only: drop non-ASCII (Chinese/mojibake) characters.

    Returns None for unsafe names (absolute paths or '..' traversal).
    """
    cleaned = "".join(c for c in name if 32 <= ord(c) < 127)
    cleaned = cleaned.replace("\\", "/")
    parts = [p for p in cleaned.split("/") if p not in ("", ".")]
    if not parts or any(p == ".." for p in parts):
        return None
    return "/".join(parts)


def extract_zip(zip_path: str, dest_dir: str):
    """Extract a zip into dest_dir with sanitized (ASCII-only) member names."""
    with zipfile.ZipFile(zip_path) as zf:
        for info in zf.infolist():
            name = sanitize_name(info.filename)
            if name is None:
                print(f"      skipped unsafe member: {info.filename!r}")
                continue
            target = os.path.join(dest_dir, name)
            if info.is_dir():
                os.makedirs(target, exist_ok=True)
                continue
            os.makedirs(os.path.dirname(target), exist_ok=True)
            with zf.open(info) as src, open(target, "wb") as dst:
                shutil.copyfileobj(src, dst)


def first_top_dir(zip_path: str):
    """Return the sanitized name of the zip's first top-level member, if any."""
    with zipfile.ZipFile(zip_path) as zf:
        for info in zf.infolist():
            name = sanitize_name(info.filename)
            if name:
                return name.split("/", 1)[0]
    return None


def main():
    ap = argparse.ArgumentParser(
        description="Download every Fiio Echo Mini firmware release into stock/<version>/.")
    ap.add_argument("--dry-run", action="store_true",
                    help="only list the firmware files that would be downloaded")
    ap.add_argument("--dest", default=DEFAULT_DEST,
                    help=f"target directory (default: {DEFAULT_DEST})")
    ap.add_argument("--force", action="store_true",
                    help="re-download and re-extract even if the folder already exists")
    ap.add_argument("--keep-temp", action="store_true",
                    help="keep the downloaded zips in the temp folder")
    ap.add_argument("--url", default=PAGE_URL,
                    help=f"firmware page URL (default: {PAGE_URL})")
    ap.add_argument("--retries", type=int, default=3,
                    help="download attempts per file (default: 3)")
    args = ap.parse_args()

    print(f"[*] Fetching firmware page: {args.url}")
    links = fetch_zip_links(args.url)
    if not links:
        print("[!] No firmware .zip links found on the page.")
        sys.exit(1)

    entries = []
    for link in links:
        filename = urllib.parse.unquote(os.path.basename(link))
        m = VERSION_RE.search(filename)
        ver = normalize_version(m.group(1)) if m else None
        entries.append((ver, filename, link))
    entries.sort(key=lambda e: version_key(e[0]) if e[0] else (0, 0, 0),
                 reverse=True)

    print(f"[*] Found {len(entries)} firmware files:")
    for ver, filename, _ in entries:
        print(f"      V{ver or '????'}  <-  {filename}")
    if args.dry_run:
        return

    os.makedirs(args.dest, exist_ok=True)
    tmp = tempfile.mkdtemp(prefix="fiio_fw_")
    try:
        # Phase 1: download everything into the temp folder.
        print(f"[*] Downloading into temp folder: {tmp}")
        downloaded = []
        for ver, filename, link in entries:
            print(f"  [*] {filename} ...", flush=True)
            zip_path = os.path.join(tmp, filename)
            if download(link, zip_path, retries=args.retries):
                downloaded.append((ver, filename, zip_path))
            else:
                print(f"      SKIPPED (download failed): {filename}")

        # Phase 2: unzip each into stock/<version>.
        print(f"[*] Extracting into {args.dest}")
        for ver, filename, zip_path in downloaded:
            if ver is None:
                print(f"  [!] SKIPPED (could not parse version): {filename}")
                continue
            ver_dir = os.path.join(args.dest, ver)
            os.makedirs(ver_dir, exist_ok=True)
            top = first_top_dir(zip_path)
            if top and not args.force and os.path.isdir(os.path.join(ver_dir, top)):
                print(f"  [=] V{ver}: {top} already extracted -- skipping (use --force to redo)")
                continue
            print(f"  [*] V{ver}: extracting {filename}", flush=True)
            extract_zip(zip_path, ver_dir)
            print(f"      OK -> {ver_dir}")
    finally:
        if not args.keep_temp:
            shutil.rmtree(tmp, ignore_errors=True)
            print("[*] Temp folder cleaned up.")
        else:
            print(f"[*] Temp zips kept at: {tmp}")


if __name__ == "__main__":
    main()
