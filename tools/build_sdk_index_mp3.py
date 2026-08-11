#!/usr/bin/env python3
"""
build_sdk_index_mp3.py — Build function→string index from the MP3 V1.3 SDK
(firmware/rockchip/), which is the SDK the Fiio firmware was actually built from.
"""
import json, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SDK_ROOT = ROOT / "firmware" / "rockchip"
OUTPUT = ROOT / "build" / "sdk_function_index_mp3.json"

FUNC_DEF_RE = re.compile(
    r'^[ \t]*(?:static[ \t]+)?'
    r'(?:unsigned[ \t]+|signed[ \t]+|const[ \t]+|volatile[ \t]+)*'
    r'(?:void|int|char|short|long|float|double|uint8_t|uint16_t|uint32_t|'
    r'int8_t|int16_t|int32_t|bool|size_t|HANDLE|LPVOID|DWORD|UINT|BOOL|'
    r'rk_err_t|pFun|FTYPE|MEDIA_ERR|UINT32|INT32|INT16|UINT16|UINT8|CHAR|'
    r'[A-Z_][A-Za-z0-9_]*\s*\*+|struct\s+\w+|enum\s+\w+)'
    r'(?:\s+\*+|\s+)'
    r'(\w+)\s*\([^)]*\)\s*$',
    re.MULTILINE,
)
STRING_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')
CALL_RE = re.compile(r'\b([a-z_][a-z0-9_]*)\s*\(', re.IGNORECASE)

def extract_functions(filepath):
    try:
        text = filepath.read_text(encoding="utf-8", errors="ignore")
    except:
        return {}
    result = {}
    lines = text.split("\n")
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        if line.startswith("#") or line.startswith("//") or not line:
            i += 1
            continue
        m = FUNC_DEF_RE.match(line)
        if m:
            func_name = m.group(1)
            brace_line = i
            while brace_line < len(lines) and "{" not in lines[brace_line]:
                brace_line += 1
            if brace_line >= len(lines):
                i += 1
                continue
            depth = 0
            body_lines = []
            j = brace_line
            while j < len(lines):
                body_lines.append(lines[j])
                depth += lines[j].count("{") - lines[j].count("}")
                if depth <= 0 and j > brace_line:
                    break
                j += 1
            body = "\n".join(body_lines)
            strings = STRING_RE.findall(body)
            interesting = []
            for s in strings:
                s_unescaped = s.replace('\\"', '"').replace('\\n', '\n').replace('\\t', '\t').replace('\\\\', '\\')
                if len(s_unescaped) >= 4 and not s_unescaped.startswith('%') and s_unescaped not in ('true', 'false', 'null'):
                    interesting.append(s_unescaped)
            callees = set(CALL_RE.findall(body))
            callees.discard(func_name)
            if func_name not in result:
                result[func_name] = {"file": str(filepath.relative_to(SDK_ROOT)), "strings": interesting, "callees": sorted(callees)}
            else:
                result[func_name]["strings"].extend(interesting)
                result[func_name]["callees"] = sorted(set(result[func_name]["callees"]) | callees)
            i = j + 1
        else:
            i += 1
    return result

def main():
    if not SDK_ROOT.is_dir():
        print(f"ERROR: SDK root not found: {SDK_ROOT}", file=sys.stderr)
        return 1
    c_files = sorted(SDK_ROOT.rglob("*.c"))
    print(f"Scanning {len(c_files)} .c files in {SDK_ROOT}")
    index = {}
    for f in c_files:
        funcs = extract_functions(f)
        for name, info in funcs.items():
            if name in index:
                index[name]["strings"].extend(info["strings"])
                index[name]["callees"] = sorted(set(index[name]["callees"]) | set(info["callees"]))
            else:
                index[name] = info
    for name in index:
        seen = set()
        unique = []
        for s in index[name]["strings"]:
            if s not in seen:
                seen.add(s)
                unique.append(s)
        index[name]["strings"] = unique
    matchable = {k: v for k, v in index.items() if len(v["strings"]) > 0}
    print(f"Total functions: {len(index)}")
    print(f"Functions with strings: {len(matchable)}")
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(index, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"Written: {OUTPUT}")
    # String map
    string_map = {}
    for func_name, info in matchable.items():
        for s in info["strings"]:
            if s not in string_map:
                string_map[s] = func_name
    string_map_path = ROOT / "build" / "sdk_string_map_mp3.json"
    string_map_path.write_text(json.dumps(string_map, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"String map: {string_map_path} ({len(string_map)} unique strings)")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
