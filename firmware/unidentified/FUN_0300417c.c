/**
 * FUN_0300417c @ 0x0300417c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0300417c(void)

{
  int iVar1;
  
  iVar1 = FUN_02fe1e70(*DAT_030041b0,DAT_030041ac);
  if (iVar1 == 1) {
    return;
  }
  func_0x02fe1e2c(DAT_030041b0);
  FUN_02ff3430(0x21,7);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


