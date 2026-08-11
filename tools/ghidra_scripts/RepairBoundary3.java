//RepairBoundary3.java
//@category Analysis
// Completa la reparación: recrea función con body en entry real (o repara body null).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.symbol.SourceType;

public class RepairBoundary3 extends GhidraScript {

    @Override
    public void run() throws Exception {
        String entryStr = getScriptArgs()[0].trim();
        Address addr = toAddr(entryStr);
        FunctionManager fm = currentProgram.getFunctionManager();

        // Si existe función (quizá con body null), intentar borrarla robustamente
        Function f = fm.getFunctionAt(addr);
        String oldName = (f != null) ? f.getName() : null;
        if (f != null) {
            try {
                fm.removeFunction(addr);
                println("REMOVED_EXISTING");
            } catch (Exception e) {
                println("REMOVE_ERR " + e.getMessage());
                // alternativa: crear de todos modos puede fallar; intentar set body
                try {
                    f.setBody(new AddressSet(addr));
                    println("SET_BODY_FALLBACK");
                    return;
                } catch (Exception e2) {
                    println("SETBODY_ERR " + e2.getMessage());
                }
            }
        }

        // Recrear
        Function nf = fm.createFunction(null, addr, new AddressSet(addr), SourceType.USER_DEFINED);
        if (nf != null) {
            if (oldName != null) {
                nf.setName(oldName, SourceType.USER_DEFINED);
            }
            println("RECREATED at " + addr + " name=" + nf.getName());
        } else {
            println("RECREATE_FAILED");
        }
    }
}
