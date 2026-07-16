"""
Extract all RKnanoFW sections from HIFIEC37.IMG
Each section represents a firmware component (bootloader, main app, resources, etc.)
"""
import os, struct

import argparse

parser = argparse.ArgumentParser(description='Extract all RKnanoFW sections from Echo Mini firmware')
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
data_len = size - 4  # strip CRC
crc = struct.unpack('<I', data[size-4:size])[0]

print("=" * 60)
print("HIFIEC37.IMG - RKnanoFW Multi-Image Extractor")
print("=" * 60)

# Find all RKnanoFW occurrences
magic = b'RKnanoFW'
positions = []
pos = 0
while True:
    pos = data.find(magic, pos)
    if pos < 0:
        break
    # Get context: 8 bytes before, magic (9 bytes with null), then some header
    positions.append(pos)
    pos += len(magic)

print(f"\nFound {len(positions)} 'RKnanoFW' occurrences:")
for p in positions:
    ctx = data[p:p+32].hex(' ').upper()
    print(f"  0x{p:08X}: {ctx}")

# Analyze each occurrence
for idx, rknano_pos in enumerate(positions):
    print(f"\n{'='*60}")
    print(f"Section {idx+1} at 0x{rknano_pos:08X}")
    print(f"{'='*60}")
    
    # The 8 bytes before RKnanoFW:
    pre_data = data[rknano_pos-8:rknano_pos]
    pre_a, pre_b = struct.unpack('<II', pre_data)
    print(f"  Pre-header: 0x{pre_a:08X} 0x{pre_b:08X} ({pre_b})")
    
    # After "RKnanoFW\0" (9 bytes), we have segment descriptors
    table_start = rknano_pos + 9
    
    # Try to find how many entries by looking for the end of the table
    # The table ends when we see a pattern that doesn't look like addresses
    
    # Let's parse as 16-byte entries
    entries = []
    for i in range(200):  # max 200 entries
        off = table_start + i * 16
        if off + 16 > data_len:
            break
        a, b, c, d = struct.unpack('<IIII', data[off:off+16])
        # Check if this looks like a valid entry
        # An entry might have: {load_addr, size/flags, addr2, addr3}
        # Or: {file_offset, size, load_addr, flags}
        
        # If all zeros, might be end of table
        if a == 0 and b == 0 and c == 0 and d == 0:
            continue
        
        # Heuristic: if a is an address-like value (0x01xxxxxx-0x20xxxxxx)
        # and b is small, it's plausible
        is_addr = (0x01000000 <= a <= 0x21000000 or 0x00000000 <= a <= 0x01000000)
        is_small_b = b < 0x01000000
        
        entries.append((off, a, b, c, d))
    
    print(f"  Parsed {len(entries)} entries")
    
    # Show first 20 entries
    for i, (off, a, b, c, d) in enumerate(entries[:20]):
        print(f"    [{i:2d}] 0x{off:06X}: a=0x{a:08X} b={b:10d} (0x{b:08X}) c=0x{c:08X} d=0x{d:08X}")
    
    # Try to extract firmware images
    # The actual data likely starts after the table
    # Let's find the end of the table by looking for a significant byte pattern change
    
    # Strategy: scan forward from the RKnanoFW position
    # Find where the data transitions from table-like to code-like
    
    # For now, let's extract the entire section from RKnanoFW to the next RKnanoFW or EOF
    next_pos = None
    for p in positions:
        if p > rknano_pos:
            next_pos = p
            break
    
    section_end = next_pos if next_pos else data_len
    
    # The actual firmware data might start after the header/table
    # Let's estimate the header size: outer header (0x1F0) + RKnanoFW header + table
    # From our analysis, the table seems to go from 0x200 to around 0xD00-0x1000
    
    # Save the whole section for analysis
    section_data = data[rknano_pos:section_end]
    section_file = os.path.join(out_dir, f'section_{idx+1}_0x{rknano_pos:08X}.bin')
    with open(section_file, 'wb') as f:
        f.write(section_data)
    print(f"  Saved section to: {section_file} ({len(section_data)} bytes)")
    
    # If there are entries that look like {load_addr, size, ?, ?}, 
    # try to interpret them as flash segments
    # The "size" values we saw earlier: 91, 101456, 157032, 6908, etc.
    # These might be segment sizes within the flash image
    
    # Let's try to find the actual data start by looking for ARM code
    # Sample a few bytes at various offsets after the table

# Now look for "ECHOMINIIMG" - might be another magic marker
echomagic_pos = data.find(b'ECHOMINIIMG')
if echomagic_pos >= 0:
    print(f"\n'ECHOMINIIMG' found at 0x{echomagic_pos:08X}")
    ctx = data[max(0,echomagic_pos-16):echomagic_pos+32]
    print(f"  Context: {ctx.hex(' ').upper()}")
    print(f"  ASCII: {ctx}")

# Now let's look at the structure around 0x57820 (second RKnanoFW)
# and 0x81A14 (third RKnanoFW) more carefully
if len(positions) >= 2:
    print(f"\n{'='*60}")
    print(f"Comparing RKnanoFW sections")
    print(f"{'='*60}")
    for i, p in enumerate(positions):
        # Read first 64 bytes of each section header
        hdr = data[p:p+64]
        print(f"\n  Section {i+1} (0x{p:08X}):")
        for j in range(0, 64, 16):
            chunk = hdr[j:j+16]
            hex_str = chunk.hex(' ').upper()
            ascii_str = ''.join(chr(b) if 32<=b<127 else '.' for b in chunk)
            print(f"    +{j:02X}: {hex_str:<48}  {ascii_str}")

# Also look for the string "ECHO" to find the device descriptor block
print(f"\n{'='*60}")
print("ECHO device descriptor strings")
print(f"{'='*60}")
for m in data.find(b'ECHO'):
    pass  # not needed

# Check for standard Rockchip update.img header at the very beginning
# RKFW magic is "RKFW" at offset 0
print(f"\nFirst 4 bytes: {data[0:4].hex(' ').upper()} = '{data[0:4].decode('ascii','replace')}'")

# Look for the size field at offset 0x1F4 (4 bytes before RKnanoFW)
# In the main header, this was 0x01FC4000
# Check if this value matches the distance to next RKnanoFW or total size
val_1f4 = struct.unpack('<I', data[0x1F4:0x1F8])[0]
print(f"\nSize field at 0x1F4: 0x{val_1f4:08X} ({val_1f4})")
print(f"  Actual data area: {data_len} = 0x{data_len:X}")
print(f"  Difference: {data_len - val_1f4} = 0x{data_len - val_1f4:X}")

# The value 0x01FC4000 = 33,308,672
# Data area = 33,554,432
# Difference = 245,760 = 0x3C000
# This could be the size of the header before the data area

print("\nDone! Time to look at the extracted sections in Ghidra.")
