import os
from difflib import SequenceMatcher

def sim(a, b):
    return SequenceMatcher(None, a, b).ratio()

ours_root = 'firmware/rockchip'
candidates = {
    'MP3_V1.3': 'community/sdks/RKNanoD_MP3_V1.3_20161102',
    'Wireless_V1.5': 'community/sdks/RKNanoD_Wireless_Audio_SDK_V1.5',
}

# archivos clave de nuestro SDK (basename) -> rutas relativas en cada SDK
key_files = [
    'bbsystem/Main2.c',
    'bbsystem/BSP2.c',
    'bbsystem/interrupt2.c',
    'bbsystem/SysTickHandler2.c',
    'system/os/Win.c',
    'system/os/Task.c',
    'system/os/Thread.c',
    'system/os/Msg.c',
    'system/os/OsHook.c',
    'system/sysservice/Service.c',
    'system/module_overlay/ModuleOverlay.c',
]

# construir mapa basename -> path para cada SDK
def build_map(root):
    m = {}
    for dirpath, dirs, files in os.walk(root):
        if '.git' in dirpath:
            continue
        for fn in files:
            m.setdefault(fn, []).append(os.path.join(dirpath, fn))
    return m

ours_map = build_map(ours_root)
cand_maps = {k: build_map(v) for k, v in candidates.items()}

print(f'{"archivo":38} {"MP3_V1.3":>10} {"Wireless_V1.5":>14}')
print('-' * 66)
for rel in key_files:
    base = os.path.basename(rel)
    our_path = os.path.join(ours_root, rel)
    if not os.path.exists(our_path):
        print(f'{rel:38} (no existe en nuestro SDK)')
        continue
    our_txt = open(our_path, encoding='utf-8', errors='replace').read()
    row = f'{rel:38}'
    for cname, cmap in cand_maps.items():
        cand_paths = cmap.get(base, [])
        best = 0.0
        for cp in cand_paths:
            try:
                ct = open(cp, encoding='utf-8', errors='replace').read()
                best = max(best, sim(our_txt, ct))
            except Exception:
                pass
        row += f' {best*100:9.1f}%'
    print(row)
