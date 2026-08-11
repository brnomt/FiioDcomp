//RepairBoundary4.java
//@category Analysis
// Repara boundary: borra función hinchada, limpia la región previa, recrea en entry.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import ghidra.program.model.symbol.SourceType;

public class RepairBoundary4 extends GhidraScript {

    @Override
    public void run() throws Exception {
        String entryStr = getScriptArgs()[0].trim();
        String bodyStartStr = getScriptArgs()[1].trim(); // bodyMin actual (para borrar previo)
        Address entry = toAddr(entryStr);
        Address bodyStart = toAddr(bodyStartStr);
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();

        Function f = fm.getFunctionAt(entry);
        String oldName = (f != null) ? f.getName() : null;
        if (f != null) {
            fm.removeFunction(entry);
            println("REMOVED " + oldName);
        }

        // Limpiar la región previa (bodyStart .. entry-1) para que no sea código de esta función
        if (bodyStart.compareTo(entry) < 0) {
            Address cur = bodyStart;
            while (cur.compareTo(entry) < 0) {
                Address end = cur.add(0x10);
                if (end.compareTo(entry) > 0) end = entry;
                try {
                    listing.clearCodeUnits(cur, end.subtract(1));
                } catch (Exception e) { /* continue */ }
                cur = end;
            }
            println("CLEARED " + bodyStart + ".." + entry);
        }

        // Recrear en entry
        Function nf = fm.createFunction(null, entry, new AddressSet(entry), SourceType.USER_DEFINED);
        if (nf != null) {
            if (oldName != null) nf.setName(oldName, SourceType.USER_DEFINED);
            println("RECREATED " + oldName + " at " + entry);
        } else {
            println("RECREATE_FAILED");
        }
    }
}
