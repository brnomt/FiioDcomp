/**
 * FUN_03019998 @ 0x03019998
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03019998(void)

{
  int iVar1;
  
  iVar1 = FUN_02ff7890(*DAT_030199c8,DAT_030199c4);
  if (iVar1 == 1) {
    return;
  }
  FUN_03008e50(0x12,7);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


