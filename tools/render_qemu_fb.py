#!/usr/bin/env python3
"""render_qemu_fb.py — ReChord GUI dev loop.

Run a QEMU lm3s6965evb instance with a framebuffer-in-RAM harness,
read the framebuffer via the QEMU monitor, and render it to a PNG.

Usage:
    python tools/render_qemu_fb.py [--bin build/qemu_gui_menu.bin]
                                  [--out build/gui.png]
                                  [--port 4473]
                                  [--keep]   # don't quit QEMU

Requires: qemu-system-arm on PATH or set QEMU=... env.
"""
import argparse
import os
import re
import socket
import subprocess
import sys
import time
from pathlib import Path

FB_ADDR = 0x20000000
FB_W, FB_H = 128, 64

QEMU = os.environ.get("QEMU", r"C:\Program Files\qemu\qemu-system-arm.exe")


def read_fb(port: int) -> list[int]:
    """Connect to the QEMU monitor, dump 128x64x2 bytes, parse halfwords."""
    s = socket.create_connection(("127.0.0.1", port), timeout=5)
    time.sleep(0.4)
    # 8192 halfwords = full 128x64 framebuffer
    s.sendall(f"x/{8192}hx 0x{FB_ADDR:08x}\n".encode())
    time.sleep(1.5)
    data = b""
    s.settimeout(6)
    try:
        while True:
            chunk = s.recv(65536)
            if not chunk:
                break
            data += chunk
    except socket.timeout:
        pass
    if not args_keep_quitting(s):
        s.sendall(b"q\n")
    s.close()

    txt = data.decode(errors="replace")
    hws: list[int] = []
    for line in txt.split("\n"):
        line = line.strip()
        if ":" in line and line[:4].isdigit():
            body = line.split(":", 1)[1]
            for m in re.findall(r"0x([0-9a-fA-F]{4})", body):
                hws.append(int(m, 16))
    return hws


def args_keep_quitting(sock) -> bool:
    return False


def render(hws: list[int], out: Path):
    from PIL import Image
    im = Image.new("RGB", (FB_W, FB_H))
    for y in range(FB_H):
        for x in range(FB_W):
            i = y * FB_W + x
            v = hws[i] if i < len(hws) else 0
            r = (v >> 11) & 0x1F
            g = (v >> 5) & 0x3F
            b = v & 0x1F
            im.putpixel((x, y), (r << 3, g << 2, b << 3))
    im = im.resize((FB_W * 3, FB_H * 3), Image.NEAREST)
    im.save(out)
    print(f"rendered {out} ({FB_W}x{FB_H} -> {FB_W*3}x{FB_H*3})")


def main():
    global FB_ADDR, FB_W, FB_H
    ap = argparse.ArgumentParser()
    ap.add_argument("--bin", default="build/qemu_gui_menu.bin")
    ap.add_argument("--out", default="build/gui.png")
    ap.add_argument("--port", type=int, default=4473)
    ap.add_argument("--width", type=int, default=FB_W)
    ap.add_argument("--height", type=int, default=FB_H)
    ap.add_argument("--fb-addr", type=lambda x: int(x, 0), default=FB_ADDR)
    args = ap.parse_args()

    FB_W, FB_H = args.width, args.height
    FB_ADDR = args.fb_addr

    if not Path(args.bin).exists():
        print(f"missing {args.bin} — build it first (see docs/HANDOVER.md)", file=sys.stderr)
        sys.exit(1)

    # launch QEMU with a TCP monitor
    qemu = subprocess.Popen(
        [QEMU, "-machine", "lm3s6965evb", "-kernel", args.bin,
         "-display", "none", "-monitor", f"tcp:127.0.0.1:{args.port},server=on,wait=off"],
        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
    )
    try:
        time.sleep(4)  # let it boot and draw
        hws = read_fb(args.port)
        print(f"read {len(hws)} halfwords, non-zero: {sum(1 for h in hws if h)}")
        if not hws:
            print("WARNING: framebuffer empty — is the harness running?", file=sys.stderr)
            sys.exit(2)
        render(hws, Path(args.out))
    finally:
        qemu.terminate()
        try:
            qemu.wait(timeout=3)
        except subprocess.TimeoutExpired:
            qemu.kill()


if __name__ == "__main__":
    main()
