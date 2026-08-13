import os, re
from collections import Counter

fw1 = open('build/fw1_ap.bin', 'rb').read()

# extraer strings ASCII (>=5 chars) de fw1
fw1_strings = set()
for m in re.finditer(rb'[\x20-\x7e]{5,}', fw1):
    s = m.group()
    fw1_strings.add(s)

print(f'fw1: {len(fw1_strings)} strings ASCII unicas (>=5 chars)')
print()

# buscar en cada SDK leakeado cuántas strings de fw1 aparecen
sdks = {
    'RKnanoC (rk3399-table)': 'community/sdks/rk3399-table-RKNanoC',
    'RKnanoD_MP3_V1.3': 'community/sdks/RKNanoD_MP3_V1.3_20161102',
    'RKnanoD_Wireless_V1.5': 'community/sdks/RKNanoD_Wireless_Audio_SDK_V1.5',
}

results = {}
for name, root in sdks.items():
    # volcar todo el source del SDK a un solo blob para buscar rápido
    blob = bytearray()
    for dirpath, dirs, files in os.walk(root):
        if '.git' in dirpath:
            continue
        for fn in files:
            if fn.lower().endswith(('.c', '.h')):
                try:
                    blob += open(os.path.join(dirpath, fn), 'rb').read()
                except Exception:
                    pass
    blob = bytes(blob)
    hits = sum(1 for s in fw1_strings if s in blob)
    results[name] = hits
    print(f'  {name:30} {hits} strings de fw1')

print()
best = max(results, key=results.get)
print(f'MEJOR MATCH: {best} ({results[best]} strings)')
