#!/usr/bin/env python3
"""
run_string_extract.py — Run a Ghidra script that:
  1. Uses Ghidra's built-in string extractor to find ALL strings in the binary
  2. Matches them against the SDK string map
  3. Defines matching strings and finds xrefs
  4. Renames functions based on xrefs
"""
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
import ghidra.app.plugin.core.strings.*;
import java.io.*;
import java.util.*;

public class StringExtractMatch extends GhidraScript {
    public void run() throws Exception {
        String home = System.getProperty("user.home");
        File outDir = new File(new File(new File(home, "Desktop"), "FiioDcomp"), "build");

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

        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        Listing listing = currentProgram.getListing();
        Memory mem = currentProgram.getMemory();

        // Use Ghidra's string extractor to find all strings
        println("Extracting all strings from binary...");
        ghidra.program.model.listing.StringDiff strings = new ghidra.program.model.listing.StringDiff();
        // Use DataIterator to find existing strings
        int totalStrings = 0;
        int matchedStrings = 0;
        int renamed = 0;
        Set<String> renamedAddrs = new HashSet<String>();

        // Iterate through all defined data
        DataType stringType = new StringDataType();
        DataType unicodeType = new UnicodeDataType();

        // Search for SDK strings in memory directly
        println("Searching for SDK strings in binary...");
        Address minAddr = mem.getMinAddress();

        // For each SDK string, search in binary
        int searched = 0;
        for (Map.Entry<String, String> entry : stringToSdk.entrySet()) {
            String sdkStr = entry.getKey();
            String sdkFunc = entry.getValue();
            if (sdkStr.length() < 6) continue;
            searched++;

            if (searched % 500 == 0) {
                println("  Searched " + searched + "/" + stringToSdk.size() + " strings...");
            }

            // Search for ASCII
            byte[] asciiBytes = sdkStr.getBytes("UTF-8");
            Address found = mem.findBytes(minAddr, asciiBytes, null, true, monitor);
            if (found != null) {
                matchedStrings++;
                // Define the string
                try {
                    listing.createData(found, stringType, asciiBytes.length + 1);
                } catch (Exception e) { /* already defined */ }

                // Get xrefs
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
                                println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr + " (string: " + sdkStr.substring(0, Math.min(40, sdkStr.length())) + ")");
                            } catch (Exception e) {}
                        }
                    }
                }
            }

            // Search for UTF-16LE
            byte[] utf16Bytes = sdkStr.getBytes("UTF-16LE");
            Address found16 = mem.findBytes(minAddr, utf16Bytes, null, true, monitor);
            if (found16 != null) {
                matchedStrings++;
                try {
                    listing.createData(found16, unicodeType, utf16Bytes.length + 2);
                } catch (Exception e) { /* already defined */ }

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
                                println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr + " (utf16: " + sdkStr.substring(0, Math.min(40, sdkStr.length())) + ")");
                            } catch (Exception e) {}
                        }
                    }
                }
            }
        }

        println("Strings searched: " + searched);
        println("Strings matched in binary: " + matchedStrings);
        println("Functions renamed: " + renamed);

        // Final count
        int total = 0, named = 0;
        FunctionIterator funcIter = fm.getFunctions(true);
        while (funcIter.hasNext()) {
            Function f = funcIter.next();
            total++;
            if (!f.getName().startsWith("FUN_")) named++;
        }
        println("FINAL: " + named + "/" + total + " (" + (100.0 * named / total) + "%)");

        // Save results
        File outFile = new File(outDir, "ghidra_string_extract_results.json");
        PrintWriter log = new PrintWriter(new FileWriter(outFile));
        log.println("{\"searched\":" + searched + ",\"matched\":" + matchedStrings + ",\"renamed\":" + renamed + ",\"total\":" + total + ",\"named\":" + named + ",\"percent\":" + (100.0 * named / total) + "}");
        log.close();
        println("Results saved to: " + outFile.getAbsolutePath());
    }
}
"""

print(f"Script length: {len(SCRIPT_CODE)} chars")
print("Running string extract match script...")

body = json.dumps({"code": SCRIPT_CODE}).encode("utf-8")
req = urllib.request.Request(
    f"{BASE}/run_script_inline", data=body,
    headers={"Content-Type": "application/json"}, method="POST"
)
try:
    resp = urllib.request.urlopen(req, timeout=900)
    result = resp.read().decode("utf-8")
    print(f"\nResult:\n{result[:5000]}")
except Exception as e:
    print(f"ERROR: {e}")
