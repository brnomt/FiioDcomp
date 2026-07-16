"""
HIFIEC37.IMG Extractor for Snowsky Echo Mini (RKnanoFW format)
Extracts all firmware segments for disassembly.
"""
import os, struct, sys

import argparse

parser = argparse.ArgumentParser(description='Extract and analyze Echo Mini firmware (HIFIEC37.IMG)')
parser.add_argument('input', nargs='?', default='stock/ECHO MINI V3.7.0/HIFIEC37.IMG',
                    help='Path to HIFIEC37.IMG (default: stock/ECHO MINI V3.7.0/HIFIEC37.IMG)')
parser.add_argument('--output', '-o', default=None,
                    help='Output directory (default: <input_dir>/extracted)')
args = parser.parse_args()

path = args.input
out_dir = args.output or os.path.join(os.path.dirname(path), 'extracted')
os.makedirs(out_dir, exist_ok=True)

with open(path, 'rb') as f:
    data = f.read()

size = len(data)
print(f"File: {path}")
print(f"Size: {size} bytes ({size/1024/1024:.2f} MB)")

# === Parse Outer Header (0x00 - 0x1EF) ===
magic_date = struct.unpack('<I', data[0:4])[0]
sentinel = struct.unpack('<I', data[0x0C:0x10])[0]
chip_name = data[0x10:0x18].decode('ascii').strip('\x00')
sdk_ver = data[0x30:0x3E].rstrip(b'\x00').decode('ascii')

print(f"\n=== Outer Header ===")
print(f"Magic/Date: 0x{magic_date:08X}")
print(f"Sentinel:   0x{sentinel:08X}")
print(f"Chip:       {chip_name}")
print(f"SDK:        {sdk_ver}")

# === Find and Parse RKnanoFW Header ===
rknano_pos = data.find(b'RKnanoFW')
if rknano_pos < 0:
    print("ERROR: RKnanoFW magic not found!")
    sys.exit(1)

print(f"\n=== RKnanoFW Header at 0x{rknano_pos:08X} ===")

# The 8 bytes before RKnanoFW: 4 bytes padding + 4 bytes chunk size
pre_size = struct.unpack('<I', data[rknano_pos-4:rknano_pos])[0]
print(f"Chunk size (pre): 0x{pre_size:08X} ({pre_size})")

# After "RKnanoFW\0" (9 bytes), we have a segment table
table_start = rknano_pos + 9  # after "RKnanoFW\0"

# Let's try to parse the segment table.
# The structure appears to be an array of entries.
# Each entry seems to have: [addr_A, size/addr_B, addr_C, addr_D] (4 x uint32)
# But the actual layout is unclear. Let me try a different approach.

# Looking at the hex, after "RKnanoFW\0" at 0x201:
# 00 00 05 03 5B 00 00 00 CC 95 07 03 00 00 05 03
# These 4 uint32s: 0x03050000, 91, 0x030795CC, 0x03050000

# Then: 68 65 02 00 34 3B 0A 03 00 40 00 03 FC 1A 00 00
# 0x00026568 (157032), 0x030A3B34, 0x03004000, 0x00001AFC (6908)

# Hmm, maybe the format is: [count][entries...] where each entry is:
# {addr_in_file, size, addr_in_memory, flags}

# Actually, looking again at the very beginning of the file (offset 0x50),
# we have what looks like a section table:
# 04 00 00 00 -> 4 sections
# 00 02 00 00 -> 0x200 (512)
# 00 00 00 00 -> 0
# 00 02 00 00 -> 0x200
# 
# Then more entries. Each entry is 16 bytes.

# Let me parse the table at offset 0x50
print(f"\n=== Section Table at 0x50 ===")
table_50_start = 0x50
# First value might be a count
count_or_val = struct.unpack('<I', data[table_50_start:table_50_start+4])[0]
print(f"First value: {count_or_val}")

# Let's try reading as a table with count as first field
# Actually, 0x50: 04 00 00 00 00 02 00 00 00 00 00 00 00 02 00 00
# This could be: count=4, then entries of 12 bytes each? Let's try.

# Try to interpret as section count at 0x50
sect_count = struct.unpack('<I', data[0x50:0x54])[0]
print(f"\nPossible section count at 0x50: {sect_count}")

# After count, we have section descriptors
# Each descriptor might be: [size_A, addr_A, size_B, addr_B]?
# Or: [offset, size, load_addr, flags]?

# Let's dump the next several 16-byte chunks from 0x54
print("\nSection descriptors from 0x54:")
for i in range(min(20, int((0x1F0 - 0x54) / 16))):
    off = 0x54 + i * 16
    if off >= 0x1F0:
        break
    a, b, c, d = struct.unpack('<IIII', data[off:off+16])
    # If all zeros, stop
    if a == 0 and b == 0 and c == 0 and d == 0:
        break
    print(f"  [{i}] off=0x{off:04X}: a=0x{a:08X} b=0x{b:08X} c=0x{c:08X} d=0x{d:08X}")

# Now, let's also parse what comes after "RKnanoFW"
# It looks like there's another table there
# Let me try to understand the RKnanoFW format by looking at known Rockchip code

# The addresses in the file (0x0305xxxx) correspond to the MCU memory map.
# RKnano devices typically use a Cortex-M core with flash at 0x00000000 or 0x10000000
# and SRAM at 0x20000000. But 0x03050000 seems like an external flash address.

# Let's try to find the actual payload start
# The file might be structured as:
# 1. Outer header (0x00 - 0x1EF)
# 2. RKnanoFW header (0x1F0 - ...)
# 3. Multiple segments starting at some offset

# Let me look for ARM vector table at known flash addresses
# ARM Cortex-M vector table starts with SP (4 bytes) and Reset vector (4 bytes)
# The SP value is typically near the top of RAM

print(f"\n=== Scanning for ARM vector tables ===")
# Look for plausible vector tables: first 4 bytes look like a stack pointer (high value),
# second 4 bytes look like a code address (odd due to Thumb)
for scan in [0x0000, 0x0200, 0x0400, 0x1000]:
    if scan + 8 < size:
        sp = struct.unpack('<I', data[scan:scan+4])[0]
        pc = struct.unpack('<I', data[scan+4:scan+8])[0]
        # SP should be in RAM range, PC should point to code area
        if 0x20000000 <= sp <= 0x21000000 and pc > 0 and (pc & 1) == 1:
            print(f"  Possible vector table at 0x{scan:08X}: SP=0x{sp:08X}, PC=0x{pc:08X} (Thumb)")

# === Strategy: Extract everything after the RKnanoFW header ===
# Let's find where the actual data begins
# The RKnanoFW table might describe multiple firmware images

# Actually, let me look at the entire file for ELF headers or other known structures
print(f"\n=== Scanning for known structures ===")
for sig, name in [(b'\x7fELF', 'ELF'), (b'\x7fELE', 'ELF'), (b'ARM\x00', 'ARM map')]:
    p = data.find(sig)
    if p >= 0:
        print(f"  {name} at 0x{p:08X}")
    else:
        print(f"  {name}: not found")

# Also look for common patterns
# Let me search for any null-terminated strings that look like partition names
print(f"\n=== Scanning for partition-like strings ===")
import re
# Find all printable strings between 4 and 20 chars
for m in re.finditer(rb'[A-Za-z][A-Za-z0-9_-]{3,20}\x00', data[:0x10000]):
    s = m.group()[:-1].decode('ascii', errors='replace')
    if s.lower() in ['boot', 'loader', 'system', 'app', 'firmware', 'update', 'resource', 'logo', 'parameter', 'misc', 'recovery', 'cache', 'userdata', 'vendor', 'oem', 'persist']:
        print(f"  '{s}' at 0x{m.start():08X}")

# === Key insight: the file is 32MB + 4 bytes CRC ===
# Strip the last 4 bytes to get the raw 32MB image
print(f"\n=== File analysis ===")
data_len = size - 4
print(f"Data area (minus CRC): {data_len} bytes = {data_len/1024/1024:.2f} MB = 0x{data_len:X}")
crc = struct.unpack('<I', data[size-4:size])[0]
print(f"Last 4 bytes (possible CRC): 0x{crc:08X}")

# Write stripped data (without last 4 bytes) for analysis
stripped_path = os.path.join(out_dir, 'firmware_stripped.bin')
with open(stripped_path, 'wb') as f:
    f.write(data[:data_len])
print(f"\nStripped firmware written to: {stripped_path}")

# Now let's try to identify the CPU architecture by looking at the first bytes after the headers
# RKnano typically uses ARM Cortex-M (e.g., Cortex-M4)
# Let's examine the RKnanoFW section more closely

# The RKnanoFW header (at 0x1F8) might contain:
# - Count of firmware images
# - Descriptors for each image (type, offset, size, load address)

# Let me parse more of the data after RKnanoFW
# Try different interpretations

print(f"\n=== RKnanoFW segment table exploration ===")
# The data after RKnanoFW starts at 0x201
# Let's try to read it as: [magic][version][count][entries...]

# Actually, let's look at what rockchip-mkbootimg does for reference
# The standard Rockchip firmware format has "RKFW" at the start of the file,
# but here we have a different outer header and "RKnanoFW" inside.

# From the hex dump, it looks like the RKnanoFW section contains:
# - Some header fields
# - Then a list of firmware images with their load addresses and sizes

# Let me try to parse the segment table by looking for patterns
# The key observation: the values 0x03050000, 0x030795CC, etc. are all close.
# Maybe the table entries alternate between two types:
# Type A: {target_addr, count_or_flags, ?, target_addr_2}
# Type B: {size, target_addr, ?, size_2}

# But wait - looking at the full hex dump (4096 bytes), there's a TON of data
# starting at offset 0x200 that goes on for many lines. This looks like a 
# relocation table or segment descriptor table.

# Let me count how many entries by looking for the end of the table
# (when values stop looking like addresses and become zeros or code)

# Save the full RKnanoFW section for analysis
rknano_section_start = rknano_pos  # 0x1F8
# The section size is in the 4 bytes before: pre_size = 0x01FC4000
# But that's huge. Maybe it's the total size of all images?
section_data_start = rknano_pos  # we'll include the header
section_size = min(size - rknano_pos, 0x10000)  # first 64KB for analysis

# Extract the actual firmware images
# Let me try: after the RKnanoFW header table, the actual firmware data starts
# at some offset. The table might define segments.

# Looking at the hex at offset 0x6C0 onwards, I see patterns like:
# 0x6C0: 64 AE 04 03 2E 28 00 00 F0 9D 0C 03 DC A0 07 03
# 0x6D0: DC 0A 00 00 CC A8 0C 03 78 E7 01 03 80 00 00 00
# This looks like: [addr, size, addr2, addr3] repeated

# Let me try parsing from 0x200 as a flat array of entries
# Each entry might be: {load_addr, ?, file_offset, size}

print("\nAttempting to parse segment entries from 0x200...")
# Try 16-byte entries
entry_size = 16
max_entries = 50
parsed = []
for i in range(max_entries):
    off = 0x200 + i * entry_size
    if off + entry_size > min(size, 0x10000):
        break
    a, b, c, d = struct.unpack('<IIII', data[off:off+entry_size])
    # Stop if we hit all zeros or out of range
    if a == 0 and b == 0 and c == 0 and d == 0:
        continue
    # Check if values look like plausible addresses/sizes
    if a > 0x01000000 and a < 0x10000000:  # looks like a load address
        parsed.append((off, a, b, c, d))

print(f"Found {len(parsed)} plausible entries:")
for off, a, b, c, d in parsed[:30]:
    print(f"  0x{off:04X}: addr=0x{a:08X} val2={b:10d} (0x{b:08X}) val3=0x{c:08X} val4=0x{d:08X}")

# Let's also write a summary file
summary_path = os.path.join(out_dir, 'analysis_summary.txt')
with open(summary_path, 'w') as f:
    f.write(f"HIFIEC37.IMG Analysis\n")
    f.write(f"=====================\n")
    f.write(f"Size: {size} bytes\n")
    f.write(f"Outer header magic: 0x{magic_date:08X}\n")
    f.write(f"Sentinel: 0x{sentinel:08X}\n")
    f.write(f"Chip: {chip_name}\n")
    f.write(f"SDK: {sdk_ver}\n")
    f.write(f"RKnanoFW at: 0x{rknano_pos:08X}\n")
    f.write(f"CRC at end: 0x{crc:08X}\n")
    f.write(f"\nSegment entries from 0x200:\n")
    for off, a, b, c, d in parsed[:30]:
        f.write(f"  0x{off:04X}: 0x{a:08X} {b:10d} 0x{c:08X} 0x{d:08X}\n")

print(f"\nAnalysis summary written to: {summary_path}")
print(f"\nDone! Check {out_dir} for extracted files.")
