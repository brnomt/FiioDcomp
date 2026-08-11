/**
 * FUN_03002980 @ 0x03002980
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03002980(void)

{
  int iVar1;
  
  FUN_03002330();
  iVar1 = FUN_02ff00a8(0x12a);
  if (iVar1 != 0) {
    FUN_02ff008c(0x172);
    FUN_03002330();
  }
  iVar1 = FUN_02ff00ec(1);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = FUN_02ff00a8(0x3e);
  if (iVar1 != 1) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


