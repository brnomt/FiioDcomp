#!/usr/bin/env python3
"""Test decompile_match_v2 on first 20 unnamed functions."""
import urllib.request, urllib.parse, json, re, time
BASE = "http://127.0.0.1:8089"
ROOT = None  # not needed for test

_string_cache = {}

def _get(endpoint, params=None):
    url = f"{BASE}{endpoint}"
    if params: url += "?" + urllib.parse.urlencode(params)
    try:
        resp = urllib.request.urlopen(url, timeout=120)
        data = resp.read().decode("utf-8")
        if data.startswith("{") or data.startswith("["):
            try: return json.loads(data)
            except: pass
        return data
    except Exception as e:
        return {"error": str(e)}

def resolve_string_label(label):
    if label in _string_cache:
        return _string_cache[label]
    m = re.search(r'_(0[0-9a-f]{6,8})$', label)
    if not m:
        return None
    addr_hex = f"0x{m.group(1)}"
    result = _get("/inspect_memory_content", {"address": addr_hex, "size": "256"})
    if isinstance(result, dict) and "error" not in result:
        if result.get("is_likely_string"):
            ascii_repr = result.get("ascii_repr", "")
            if ascii_repr:
                val = ascii_repr.strip()
                if val:
                    _string_cache[label] = val
                    return val
        hex_dump = result.get("hex_dump", "")
        if hex_dump:
            hex_bytes = hex_dump.replace("\\n", " ").replace("\n", " ")
            try:
                raw = bytes.fromhex(hex_bytes.replace(" ", ""))
                null_pos = raw.find(b'\x00')
                if null_pos > 3:
                    val = raw[:null_pos].decode('ascii', errors='replace')
                    if sum(1 for c in val if c.isprintable()) > len(val) * 0.5:
                        _string_cache[label] = val
                        return val
            except:
                pass
    _string_cache[label] = None
    return None

# Get functions
result = _get("/list_functions_enhanced")
funcs = result.get("functions", []) if isinstance(result, dict) else []
unnamed = [f for f in funcs if f.get("name","").startswith("FUN_")]
print(f"Unnamed: {len(unnamed)}")

# Process first 20
for func in unnamed[:20]:
    addr = func["address"]
    name = func["name"]
    code = _get("/decompile_function", {"address": addr})
    if isinstance(code, dict):
        code = code.get("decompilation", code.get("code", code.get("result", "")))
    if not code or len(code) < 20:
        print(f"\n{name} @ {addr}: no code")
        continue

    # Extract string refs
    refs = set()
    for m in re.finditer(r'\bs_([a-zA-Z0-9_]+?)_(0[0-9a-f]{6,8})\b', code):
        refs.add(m.group(0))
    for m in re.finditer(r'"((?:[^"\\]|\\.)*)"', code):
        s = m.group(1)
        if len(s) >= 4:
            refs.add(f'INLINE:"{s}"')

    if not refs:
        print(f"\n{name} @ {addr}: no string refs ({len(code)} chars)")
        continue

    # Resolve
    resolved = []
    for ref in list(refs)[:10]:
        if ref.startswith('INLINE:'):
            resolved.append(ref[8:].strip('"'))
        else:
            val = resolve_string_label(ref)
            if val:
                resolved.append(val)

    print(f"\n{name} @ {addr}: {len(refs)} refs, resolved: {resolved[:5]}")
