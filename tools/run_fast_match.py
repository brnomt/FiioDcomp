#!/usr/bin/env python3
"""
run_fast_match.py — Fast matching: only define the ~22 pre-computed matching strings
in Ghidra, then get xrefs and rename. Much faster than scanning all 2,320 SDK strings.
"""
import urllib.request, json
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

# Load pre-computed matches (from match_mp3_sdk.py / match_xrefs.py)
# These are SDK strings found in the binary with their load addresses
matches = []
for match_file in ["ghidra_mp3_renames.json", "ghidra_xref_renames.json", "ghidra_define_renames.json"]:
    p = ROOT / "build" / match_file
    if p.exists():
        data = json.loads(p.read_text(encoding="utf-8"))
        # These files have "matches" count and "renamed" list, but we need the actual string matches
        # Let me recompute them
        break

# Recompute matches from the combined string map
string_map = json.loads((ROOT / "build" / "sdk_string_map_combined.json").read_text(encoding="utf-8"))
section3 = (ROOT / "build" / "section3_stock.bin").read_bytes()
LOAD_BASE = 0x03000000

for sdk_str, sdk_func in string_map.items():
    if len(sdk_str) < 6:
        continue
    # ASCII
    try:
        pos = section3.find(sdk_str.encode("ascii"))
        if pos >= 0:
            matches.append({"string": sdk_str, "load_addr": LOAD_BASE + pos, "encoding": "ascii", "sdk_func": sdk_func})
            continue
    except:
        pass
    # UTF-16LE
    try:
        pos = section3.find(sdk_str.encode("utf-16-le"))
        if pos >= 0:
            matches.append({"string": sdk_str, "load_addr": LOAD_BASE + pos, "encoding": "utf16le", "sdk_func": sdk_func})
    except:
        pass

print(f"Pre-computed matches: {len(matches)}")

# Build the Ghidra script with hardcoded match addresses
# This avoids the slow mem.findBytes() calls
match_lines = []
for m in matches:
    addr = f"0x{m['load_addr']:08x}"
    enc = m["encoding"]
    s = m["string"].replace("\\", "\\\\").replace("\"", "\\\"")
    func = m["sdk_func"].replace("\"", "\\\"")
    match_lines.append(f'    defineAndCheck("{addr}", "{s}", "{func}", "{enc}");')

matches_java = "\n".join(match_lines)

SCRIPT_CODE = f"""
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class FastMatch extends GhidraScript {{
    int defined = 0, renamed = 0;
    Set<String> renamedAddrs = new HashSet<String>();
    FunctionManager fm;
    ReferenceManager refMgr;
    Listing listing;
    DataType stringType;
    DataType unicodeType;

    public void run() throws Exception {{
        fm = currentProgram.getFunctionManager();
        refMgr = currentProgram.getReferenceManager();
        listing = currentProgram.getListing();
        stringType = new StringDataType();
        unicodeType = new UnicodeDataType();

        println("Phase 1: Defining " + {len(matches)} + " pre-computed strings...");

{matches_java}

        println("Strings defined: " + defined);
        println("Functions renamed: " + renamed);

        // Final count
        int total = 0, named = 0;
        FunctionIterator funcIter = fm.getFunctions(true);
        while (funcIter.hasNext()) {{
            Function f = funcIter.next();
            total++;
            if (!f.getName().startsWith("FUN_")) named++;
        }}
        println("FINAL: " + named + "/" + total + " (" + (100.0 * named / total) + "%)");

        // Save results
        String home = System.getProperty("user.home");
        File outDir = new File(new File(new File(home, "Desktop"), "FiioDcomp"), "build");
        File outFile = new File(outDir, "ghidra_fast_match_results.json");
        PrintWriter log = new PrintWriter(new FileWriter(outFile));
        log.println("{{\"defined\":" + defined + ",\"renamed\":" + renamed + ",\"total\":" + total + ",\"named\":" + named + ",\"percent\":" + (100.0 * named / total) + "}}");
        log.close();
        println("Saved: " + outFile.getAbsolutePath());
    }}

    void defineAndCheck(String addrStr, String sdkStr, String sdkFunc, String encoding) {{
        try {{
            Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(java.lang.Long.parseLong(addrStr.substring(2), 16));
            int len = sdkStr.getBytes("UTF-8").length;
            if (encoding.equals("utf16le")) {{
                len = sdkStr.getBytes("UTF-16LE").length;
                try {{
                    listing.createData(addr, unicodeType, len + 2);
                    defined++;
                }} catch (Exception e) {{}}
            }} else {{
                try {{
                    listing.createData(addr, stringType, len + 1);
                    defined++;
                }} catch (Exception e) {{}}
            }}

            // Get xrefs
            ReferenceIterator refs = refMgr.getReferencesTo(addr);
            while (refs.hasNext()) {{
                Reference ref = refs.next();
                Address refAddr = ref.getFromAddress();
                Function func = fm.getFunctionContaining(refAddr);
                if (func == null) func = fm.getFunctionAt(refAddr);
                if (func != null) {{
                    String oldName = func.getName();
                    String funcAddr = func.getEntryPoint().toString();
                    if (oldName.startsWith("FUN_") && !renamedAddrs.contains(funcAddr)) {{
                        try {{
                            func.setName(sdkFunc, SourceType.USER_DEFINED);
                            renamedAddrs.add(funcAddr);
                            renamed++;
                            println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr);
                        }} catch (Exception e) {{}}
                    }}
                }}
            }}
        }} catch (Exception e) {{
            println("Error for " + addrStr + ": " + e.getMessage());
        }}
    }}
}}
"""

print(f"Script length: {len(SCRIPT_CODE)} chars")
print(f"Matches to define: {len(matches)}")
print("Running fast match script...")

body = json.dumps({"code": SCRIPT_CODE}).encode("utf-8")
req = urllib.request.Request(
    f"{BASE}/run_script_inline", data=body,
    headers={"Content-Type": "application/json"}, method="POST"
)
try:
    resp = urllib.request.urlopen(req, timeout=300)
    result = resp.read().decode("utf-8")
    print(f"\nResult:\n{result[:5000]}")
except Exception as e:
    print(f"ERROR: {e}")
