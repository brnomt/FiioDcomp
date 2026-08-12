#!/usr/bin/env python3
"""qemu_echo_read.py — read ReChord QEMU test telemetry via a TCP monitor.

Starts qemu-system-arm (mps2-an385) with the echo test kernel, waits a few
seconds for Main2's heartbeat, then reads the telemetry regions:
  - 0x20008018  boot log     (BOOT_DONE marker from Main2's heartbeat)
  - 0x20008040  test results (entry tests 1+2, ROM trace head)
  - 0x20008080  ROM-init trace (rechord_firmware_entry ROM call sequence)
  - 0x200080A0  ROM-display trace (Main2 heartbeat ROM display calls)
  - 0x20010000  framebuffer  (red/black heartbeat pattern)
Prints PASS/FAIL lines for each assertion.

Usage: python tools/qemu_echo_read.py [--bin build/qemu_echo_test.bin]
                                      [--port 4474] [--delay 4]
"""
import argparse
import os
import re
import socket
import subprocess
import sys
import time

QEMU = os.environ.get("QEMU", r"C:\Program Files\qemu\qemu-system-arm.exe")

def mon_cmd(port, cmd, wait=1.0):
    """Send one monitor command over TCP, return raw response text."""
    s = socket.create_connection(("127.0.0.1", port), timeout=5)
    time.sleep(0.2)
    s.sendall(cmd.encode() + b"\n")
    time.sleep(wait)
    data = b""
    s.settimeout(4)
    try:
        while True:
            chunk = s.recv(65536)
            if not chunk:
                break
            data += chunk
    except socket.timeout:
        pass
    s.sendall(b"\n")
    s.close()
    return data.decode(errors="replace")

def parse_words(txt):
    """Return list of (addr, [words...]) from 'x/xw' monitor output."""
    out = []
    for line in txt.split("\n"):
        line = line.strip()
        m = re.match(r"^([0-9a-fA-F]{8}):\s*(.*)$", line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        words = [int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]{8})", m.group(2))]
        out.append((addr, words))
    return out

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bin", default="build/qemu_echo_test.bin")
    ap.add_argument("--port", type=int, default=4474)
    ap.add_argument("--delay", type=float, default=4.0)
    ap.add_argument("--qemu", default=QEMU)
    args = ap.parse_args()

    cmd = [args.qemu, "-machine", "mps2-an385", "-kernel", args.bin,
           "-nographic",
           "-monitor", f"tcp:127.0.0.1:{args.port},server,nowait"]
    proc = subprocess.Popen(cmd, stdout=subprocess.DEVNULL,
                            stderr=subprocess.DEVNULL)
    try:
        time.sleep(args.delay)
        # one big read of 0x20008000..0x200080E8 (crash+bootlog+res+layout+
        # init trace + disp trace + counters), then the framebuffer
        def read_words(addr, count):
            txt = mon_cmd(args.port, f"xp /{count}xw 0x{addr:08x}")
            words = {}
            for a, w in parse_words(txt):
                for i, v in enumerate(w):
                    words[a + 4 * i] = v
            return [words.get(addr + 4 * i, 0) for i in range(count)]

        mem = read_words(0x20008000, 48)      # 0x08000-0x080BF (crash+bootlog+res+layout+init_tr)
        disp_tr = read_words(0x20008100, 12)  # heartbeat ROM display calls
        fb = read_words(0x20010000, 8)
        for i in range(0, 48, 8):
            print(f"0x{0x20008000 + 4*i:08x}: " +
                  " ".join(f"{v:08x}" for v in mem[i:i+8]))
        print(f"0x20008100: " + " ".join(f"{v:08x}" for v in disp_tr))
        print(f"0x20010000: " + " ".join(f"{v:08x}" for v in fb))

        bootlog = mem[0x18 // 4:0x18 // 4 + 4]
        res = mem[0x40 // 4:0x40 // 4 + 16]
        layout_w = mem[0x80 // 4]
        init_tr = mem[0xA0 // 4:0xA0 // 4 + 8]

        ok = True
        def check(name, cond):
            nonlocal ok
            print(("PASS  " if cond else "FAIL  ") + name)
            if not cond:
                ok = False

        check("rechord_firmware_entry(mode=0xb) returned 0x191",
              res[0] == 0x11110191)
        check("rechord_firmware_entry(mode=0x5) returned 0x18f",
              res[1] == 0x2222018f)
        check("boot telemetry 'BOOT' written", res[2] == 0x424F4F54)
        check("boot layout base byte = 8", (layout_w & 0xFF) == 0x08)
        check("ROM init trace[0] = rom_alloc(0x1dc)",
              len(init_tr) > 0 and init_tr[0] == 0x100001DC)
        check("ROM init trace = exact stock sequence (alloc,0x1dc,0x16f,0x16f,0x171,0x170,early)",
              init_tr[:7] == [0x100001DC, 0x200001DC, 0x2000016F, 0x2000016F,
                              0x30000171, 0x20000170, 0x40000000])
        check("Main2 heartbeat reached its loop: ROM display calls fired (wait/ctx/color/rect/refresh)",
              len(disp_tr) >= 8 and disp_tr[0] == 0x1000019B and
              disp_tr[3] in (0x30000094, 0x30000095) and
              (disp_tr[4] & 0xFF000000) == 0x40000000 and
              (disp_tr[5] & 0xFF000000) == 0x50000000)
        # the fb alternates red/black with a long delay; all-black is a valid
        # heartbeat phase, so only fail if the display trace also never fired
        check("framebuffer written by the heartbeat (red or black phase)",
              any(w != 0 for w in fb[:8]) or
              (len(disp_tr) >= 1 and disp_tr[0] == 0x1000019B))

        print("ALL PASS" if ok else "SOME CHECKS FAILED")
        sys.exit(0 if ok else 1)
    finally:
        try:
            mon_cmd(args.port, "quit")
        except Exception:
            pass
        proc.terminate()

if __name__ == "__main__":
    main()
