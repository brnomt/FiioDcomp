#!/usr/bin/env python3
"""
run_auto_analysis.py — Run a Ghidra script that:
  1. Runs full auto-analysis (which defines strings and finds references)
  2. After analysis, iterates all defined strings
  3. Matches against SDK strings
  4. Renames functions based on string xrefs
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
import java.io.*;
import java.util.*;

public class AutoAnalyzeMatch extends GhidraScript {
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

        // Step 1: Run auto-analysis to find strings and references
        println("Running auto-analysis...");
        try {
            ghidra.app.plugin.core.analysis.AutoAnalysisManager mgr =
                ghidra.app.plugin.core.analysis.AutoAnalysisManager.getAnalysisManager(currentProgram);
            mgr.reAnalyzeAll(null);
            mgr.startAnalysis(monitor);
            println("Auto-analysis complete.");
        } catch (Exception e) {
            println("Auto-analysis error: " + e.getMessage());
        }

        // Step 2: Iterate all defined strings and match against SDK
        println("Searching defined strings...");
        int totalStrings = 0;
        int matchedStrings = 0;
        int renamed = 0;
        Set<String> renamedAddrs = new HashSet<String>();

        DataIterator dataIter = listing.getDefinedData(true);
        while (dataIter.hasNext() && !monitor.isCancelled()) {
            Data data = dataIter.next();
            if (data == null) continue;

            // Check if it's a string type
            DataType dt = data.getDataType();
            if (dt == null) continue;
            String typeName = dt.getName();
            if (!typeName.contains("string") && !typeName.contains("String") &&
                !typeName.contains("unicode") && !typeName.contains("Unicode") &&
                !typeName.equals("char") && !typeName.equals("wchar_t")) {
                continue;
            }

            totalStrings++;

            // Get the string value
            String value = null;
            try {
                value = (String) data.getValue();
            } catch (Exception e) {
                try {
                    Object val = data.getValue();
                    if (val != null) value = val.toString();
                } catch (Exception e2) {}
            }

            if (value == null || value.length() < 6) continue;

            // Check if this string matches an SDK string
            String sdkFunc = stringToSdk.get(value);
            if (sdkFunc == null) {
                // Try with different encodings
                continue;
            }

            matchedStrings++;

            // Get xrefs to this string
            Address strAddr = data.getAddress();
            ReferenceIterator refs = refMgr.getReferencesTo(strAddr);
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
                            println("RENAMED: " + oldName + " -> " + sdkFunc + " @ " + funcAddr + " (string: " + value.substring(0, Math.min(40, value.length())) + ")");
                        } catch (Exception e) {}
                    }
                }
            }
        }

        println("Total defined strings: " + totalStrings);
        println("Matched SDK strings: " + matchedStrings);
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
        File outFile = new File(outDir, "ghidra_auto_analyze_results.json");
        PrintWriter log = new PrintWriter(new FileWriter(outFile));
        log.println("{\"total_strings\":" + totalStrings + ",\"matched_strings\":" + matchedStrings + ",\"renamed\":" + renamed + ",\"total\":" + total + ",\"named\":" + named + ",\"percent\":" + (100.0 * named / total) + "}");
        log.close();
        println("Results saved to: " + outFile.getAbsolutePath());
    }
}
"""

print(f"Script length: {len(SCRIPT_CODE)} chars")
print("Running auto-analysis match script...")

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
