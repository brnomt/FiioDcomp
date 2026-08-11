/**
 * FUN_030ca490 @ 0x030ca490
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ca490(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_030ca4cc;
  *DAT_030ca4cc = iVar1 + param_1;
  return ((iVar1 + param_1) - param_1) + DAT_030ca4d0;
}


