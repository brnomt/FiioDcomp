/**
 * FUN_0301a87c @ 0x0301a87c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0301a87c(void)

{
  int iVar1;
  
  iVar1 = FUN_02ff7f24(*DAT_0301a8b8,DAT_0301a8b4);
  if (iVar1 == 1) {
    return;
  }
  FUN_02ff7ee0(DAT_0301a8b8);
  FUN_030094e4(0xe,7);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


