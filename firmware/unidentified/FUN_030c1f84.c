/**
 * FUN_030c1f84 @ 0x030c1f84
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c1f84(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


