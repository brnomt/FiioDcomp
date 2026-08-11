/**
 * FUN_0300981c @ 0x0300981c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_0300981c(void)

{
  int iVar1;
  
  iVar1 = FUN_02fe6440(*DAT_0300985c,DAT_03009858);
  if (iVar1 == 1) {
    return;
  }
  *DAT_03009860 = 0;
  *DAT_03009864 = 0;
  FUN_02ff7a00(0x3c,7);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


