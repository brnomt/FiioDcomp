//FixBoundary.java
//@category Analysis
// Repara el boundary de hifi_busy_delay_ovl_09e3 (body absorbe 0xBC8 bytes de la función anterior).
// delete_function + create_function en la entrada real 0309E334.
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;

public class FixBoundary extends GhidraScript {

    @Override
    public void run() throws Exception {
        String entryStr = getScriptArgs()[0].trim();
        Address addr = toAddr(entryStr);
        FunctionManager fm = currentProgram.getFunctionManager();
        Function f = fm.getFunctionAt(addr);
        if (f == null) {
            println("No function at " + entryStr + " - nothing to fix");
            return;
        }
        String oldName = f.getName();
        // Verificamos si el body empieza significativamente antes que el entry
        Address bodyMin = f.getBody().getMinAddress();
        long delta = addr.subtract(bodyMin);
        println("Function " + oldName + " at " + addr + " body starts at " + bodyMin
                + " (delta=" + delta + ")");
        if (delta <= 8) {
            println("Boundary OK, skipping");
            return;
        }
        // Borrar la función hinchada
        fm.removeFunction(f);
        println("Deleted oversized function " + oldName + " at " + addr);

        // Recrear función en la entrada real
        Function nf = fm.createFunction(null, addr,
                new AddressSet(addr), SourceType.USER_DEFINED);
        if (nf != null) {
            nf.setName(oldName, SourceType.USER_DEFINED);
            println("Recreated " + oldName + " at " + addr);
        } else {
            println("Failed to recreate function at " + addr);
        }
    }
}
