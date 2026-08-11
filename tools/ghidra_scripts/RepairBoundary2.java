//RepairBoundary2.java
//@category Analysis
// Repara funciones con boundary hinchado: delete + create en entry real.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.symbol.SourceType;

public class RepairBoundary2 extends GhidraScript {

    @Override
    public void run() throws Exception {
        String entryStr = getScriptArgs()[0].trim();
        Address addr = toAddr(entryStr);
        FunctionManager fm = currentProgram.getFunctionManager();
        Function f = fm.getFunctionAt(addr);
        if (f == null) {
            println("NOFUNC " + entryStr);
            return;
        }
        String oldName = f.getName();
        Address bodyMin = f.getBody().getMinAddress();
        long delta = addr.subtract(bodyMin);
        println("FUNC " + oldName + " entry=" + addr + " bodyMin=" + bodyMin + " delta=" + delta);
        if (delta <= 8) {
            println("OK_SKIP");
            return;
        }
        fm.removeFunction(addr);
        println("DELETED " + oldName + " at " + addr);
        Function nf = fm.createFunction(null, addr, new AddressSet(addr), SourceType.USER_DEFINED);
        if (nf != null) {
            nf.setName(oldName, SourceType.USER_DEFINED);
            println("RECREATED " + oldName + " at " + addr);
        } else {
            println("RECREATE_FAILED");
        }
    }
}
