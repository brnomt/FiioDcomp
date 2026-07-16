"""Scan firmware for ARM vector table, code regions, and architecture identification."""
import os, struct

path = r'C:\Users\brnomt\Downloads\ECHO MINI V3.7.0\ECHO MINI V3.7.0\HIFIEC37.IMG'
with open(path, 'rb') as f:
    data = f.read()

size = len(data)
data_len = size - 4  # strip CRC

print("=== Scanning for ARM Cortex-M vector table ===")
# Vector table: SP (4 bytes), PC (4 bytes, bit 0 = 1 for Thumb), then handlers
# SP is typically at the top of RAM (SRAM)
# Let's scan the first 64KB for plausible vector tables
found_vt = []
for off in range(0, min(0x100000, data_len - 256), 4):
    sp = struct.unpack('<I', data[off:off+4])[0]
    pc = struct.unpack('<I', data[off+4:off+8])[0]
    # Criteria: SP in plausible SRAM range (0x1FFF0000-0x21000000 or 0x03000000-0x04000000)
    # and PC points to code area with Thumb bit set
    if (0x1FFF0000 <= sp <= 0x21000000 or 0x03000000 <= sp <= 0x04000000):
        if pc > 0 and (pc & 1) == 1:  # Thumb bit
            # Check that the next few vectors look like handler addresses
            valid_vectors = 0
            for v in range(2, 16):
                vec = struct.unpack('<I', data[off+v*4:off+v*4+4])[0]
                if vec == 0 or (vec > 0x01000000 and vec < 0x20000000) or (vec & 1) == 1:
                    valid_vectors += 1
            if valid_vectors >= 10:  # most vectors look plausible
                found_vt.append((off, sp, pc))
                if len(found_vt) <= 10:
                    print(f"  0x{off:08X}: SP=0x{sp:08X} PC=0x{pc:08X} valid_vecs={valid_vectors}")

print(f"\nTotal plausible vector tables: {len(found_vt)}")
if found_vt:
    vt, sp, pc = found_vt[0]
    print(f"\nBest candidate: offset 0x{vt:08X}, SP=0x{sp:08X}, Reset=0x{pc:08X}")
    # Extract first 8 vectors
    print("First 8 vectors:")
    for v in range(8):
        vec = struct.unpack('<I', data[vt+v*4:vt+v*4+4])[0]
        print(f"  [{v}] 0x{vec:08X}")

print("\n=== Scanning for Thumb code prologues ===")
# Common Thumb function starts: PUSH {..., LR} = 0xB5xx where bit 8 is set (includes LR)
# or 0x2DE9 (PUSH.W)
code_sigs = {
    'PUSH {...,LR}': b'\xb5',  # 0xB5xx
    'PUSH.W': bytes.fromhex('2DE9'),
    'POP {...,PC}': b'\xbd',  # 0xBDxx  
}

# Count Thumb prologue density in 256-byte blocks
block_size = 256
density_map = []
for block_start in range(0, data_len - block_size, block_size):
    chunk = data[block_start:block_start+block_size]
    # Count 0xB5xx patterns
    count = 0
    for i in range(0, len(chunk) - 1, 2):
        if chunk[i] == 0xB5 and chunk[i+1] & 0xF0 != 0:
            count += 1
    if count > 0:
        density_map.append((block_start, count))

# Print top regions by code density
density_map.sort(key=lambda x: -x[1])
print(f"\nTop 20 regions by Thumb prologue density (per {block_size} bytes):")
for off, cnt in density_map[:20]:
    print(f"  0x{off:08X}: {cnt} prologues")

# Also look for strings that might indicate partition names or firmware info
print("\n=== Key strings in first 1MB ===")
import re
strings_found = []
for m in re.finditer(rb'[\x20-\x7E]{8,}', data[:0x100000]):
    s = m.group().decode('ascii', errors='replace')
    # Filter for interesting strings
    if any(c.isalpha() for c in s) and len(set(s)) > 3:
        strings_found.append((m.start(), s))

# Show strings that look like firmware metadata
for pos, s in strings_found:
    # Look for version strings, copyright, etc.
    if any(kw in s.lower() for kw in ['version', 'firmware', 'build', 'copyright', 'echo', 'mini', 'snow', 'sky', 'rknano', 'loader', 'boot', 'image']):
        print(f"  0x{pos:08X}: '{s}'")

# Let's also look at offset 0xCC 95 07 03 which appeared in the segment table
# 0x030795CC - this might be where code or data is loaded
# The file doesn't contain data at those addresses directly (they're target addresses)
# We need to find the file offset that corresponds to 0x03050000

# Looking at the first segment: addr=0x03050000, val2=91, val3=0x030795CC
# Maybe the segments are: {src_file_offset, size, dest_mem_addr, ?}
# But 0x03050000 doesn't look like a file offset (file is only 32MB = 0x2000000)

# Actually, wait. The chunk size before RKnanoFW is 0x01FC4000.
# This is 33,308,672 which is close to 32MB. Maybe the RKnanoFW section describes
# the firmware image that starts right after the header?

# Let me try: the segments might be described as {src_offset, size, dest_addr, flags}
# where src_offset is relative to the start of the data area

# If the data area starts at some offset after the table, let's find it.
# The table at 0x200 seems to have entries of 16 bytes each.
# Let me find where the table ends and actual data begins.

# Look for a large block of non-zero data after the table
print("\n=== Looking for data start ===")
# The table at 0x200 goes on for a while. Let's find where it transitions
# from table-like data (addresses) to actual code/data.
for off in range(0x200, 0x10000, 16):
    vals = struct.unpack('<IIII', data[off:off+16])
    # If all values are zero, we might be at padding
    if all(v == 0 for v in vals):
        # Check if next bytes are also zero
        if off + 32 < len(data) and all(b == 0 for b in data[off:off+64]):
            print(f"  Large zero padding at 0x{off:08X}")
            # Data might start after this
            break
    # Check if values stop looking like addresses and start looking like code
    if not any(0x01000000 <= v <= 0x20000000 for v in vals):
        # Sample the next bytes
        sample = data[off:off+32]
        if any(b != 0 for b in sample) and not any(0x01000000 <= struct.unpack('<I', sample[i:i+4])[0] <= 0x20000000 for i in range(0, 28, 4)):
            print(f"  Possible data start at 0x{off:08X}: {sample[:16].hex(' ').upper()}")

print("\nDone.")
