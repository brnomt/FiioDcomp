#!/usr/bin/env python3
"""Run the full match script with fixed Java syntax."""
import urllib.request, json
from pathlib import Path

BASE = "http://127.0.0.1:8089"
ROOT = Path(__file__).resolve().parents[1]

SCRIPT_CODE = r"""
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class FullMatch2 extends GhidraScript {
    public void run() throws Exception {
        String home = System.getProperty("user.home");
        File outDir = new File(new File(new File(home, "Desktop"), "FiioDcomp"), "build");
        File outFile = new File(outDir, "ghidra_full_match_results.json");
        PrintWriter log = new PrintWriter(new FileWriter(outFile));
        log.println("{\"stages\":[");

        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        Listing listing = currentProgram.getListing();
        Address minAddr = mem.getMinAddress();

        // Load SDK string map
        File stringMapFile = new File(outDir, "sdk_string_map_combined.json");
        Map<String, String> stringToSdk = new HashMap<String, String>();
        if (stringMapFile.exists()) {
            BufferedReader br = new BufferedReader(new FileReader(stringMapFile));
            StringBuilder sb = new StringBuilder();
            String line;
            while ((line = br.readLine()) != null) sb.append(line);
            br.close();
            String jsonStr = sb.toString();
            int idx = 0;
            while (idx < jsonStr.length()) {
                int keyStart = jsonStr.indexOf("\"", idx);
                if (keyStart < 0) break;
                int keyEnd = jsonStr.indexOf("\"", keyStart + 1);
                if (keyEnd < 0) break;
                int valStart = jsonStr.indexOf("\"", keyEnd + 1);
                if (valStart < 0) break;
                int valEnd = jsonStr.indexOf("\"", valStart + 1);
                if (valEnd < 0) break;
                String key = jsonStr.substring(keyStart + 1, keyEnd);
                String val = jsonStr.substring(valStart + 1, valEnd);
                if (key.length() >= 6) stringToSdk.put(key, val);
                idx = valEnd + 1;
            }
        }
        println("SDK strings loaded: " + stringToSdk.size());
        log.println("{\"stage\":\"load_sdk\",\"count\":" + stringToSdk.size() + "},");

        // Phase 1: Define strings and find xrefs
        println("Phase 1: Defining strings and finding xrefs...");
        DataType stringType = new StringDataType();
        DataType unicodeType = new UnicodeDataType();
        int defined = 0, renamed = 0;
        Set<String> renamedAddrs = new HashSet<String>();

        for (Map.Entry<String, String> entry : stringToSdk.entrySet()) {
            String sdkStr = entry.getKey();
            String sdkFunc = entry.getValue();
            if (sdkStr.length() < 6) continue;

            // ASCII search
            byte[] asciiBytes = sdkStr.getBytes("UTF-8");
            Address found = mem.findBytes(minAddr, asciiBytes, null, true, monitor);
            if (found != null) {
                try {
                    listing.createData(found, stringType, asciiBytes.length + 1);
                    defined++;
                } catch (Exception e) { /* already defined or conflict */ }

                ReferenceIterator refs = refMgr.getReferencesTo(found);
                while (refs.hasNext()) {
                    Reference ref = refs.next();
                    Address refAddr = ref.getFromAddress();
                    Function func = fm.getFunctionContaining(refAddr);
                    if (func == null) func = fm.getFunctionAt(refAddr);
                    if (func != null) {
                        String oldName = func.getName();
                        String funcAddr = func.getEntryPoint().toString();
                        if (oldName.startsWith("FUN_") && !renamedAddrs.contains(funcAddr)) {
                            try {
                                func.setName(sdkFunc, SourceType.USER_DEFINED);
                                renamedAddrs.add(funcAddr);
                                renamed++;
                                println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr);
                            } catch (Exception e) {}
                        }
                    }
                }
            }

            // UTF-16LE search
            byte[] utf16Bytes = sdkStr.getBytes("UTF-16LE");
            Address found16 = mem.findBytes(minAddr, utf16Bytes, null, true, monitor);
            if (found16 != null) {
                try {
                    listing.createData(found16, unicodeType, utf16Bytes.length + 2);
                    defined++;
                } catch (Exception e) { /* already defined or conflict */ }

                ReferenceIterator refs = refMgr.getReferencesTo(found16);
                while (refs.hasNext()) {
                    Reference ref = refs.next();
                    Address refAddr = ref.getFromAddress();
                    Function func = fm.getFunctionContaining(refAddr);
                    if (func == null) func = fm.getFunctionAt(refAddr);
                    if (func != null) {
                        String oldName = func.getName();
                        String funcAddr = func.getEntryPoint().toString();
                        if (oldName.startsWith("FUN_") && !renamedAddrs.contains(funcAddr)) {
                            try {
                                func.setName(sdkFunc, SourceType.USER_DEFINED);
                                renamedAddrs.add(funcAddr);
                                renamed++;
                                println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr);
                            } catch (Exception e) {}
                        }
                    }
                }
            }
        }
        println("Strings defined: " + defined);
        println("Functions renamed: " + renamed);
        log.println("{\"stage\":\"string_match\",\"defined\":" + defined + ",\"renamed\":" + renamed + "},");

        // Final count
        int total = 0, named = 0;
        FunctionIterator funcIter = fm.getFunctions(true);
        while (funcIter.hasNext()) {
            Function f = funcIter.next();
            total++;
            if (!f.getName().startsWith("FUN_")) named++;
        }
        println("FINAL: " + named + "/" + total + " (" + (100.0 * named / total) + "%)");
        log.println("{\"stage\":\"final\",\"total\":" + total + ",\"named\":" + named + ",\"percent\":" + (100.0 * named / total) + "}");
        log.println("]}");
        log.close();
        println("Results saved to: " + outFile.getAbsolutePath());
    }
}
"""

print(f"Script length: {len(SCRIPT_CODE)} chars")
print("Running full match script...")

body = json.dumps({"code": SCRIPT_CODE}).encode("utf-8")
req = urllib.request.Request(
    f"{BASE}/run_script_inline", data=body,
    headers={"Content-Type": "application/json"}, method="POST"
)
try:
    resp = urllib.request.urlopen(req, timeout=600)
    result = resp.read().decode("utf-8")
    print(f"\nResult:\n{result[:5000]}")
except Exception as e:
    print(f"ERROR: {e}")
