/**
 * FUN_030ca4a0 @ 0x030ca4a0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ca4a0(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 3) != 0) {
    param_1 = (param_1 - (param_1 & 3)) + 4;
  }
  iVar1 = *(int *)(DAT_030ca4cc + 4) + param_1;
  if (iVar1 < 0x3000) {
    *(int *)(DAT_030ca4cc + 4) = iVar1;
    return (iVar1 - param_1) + DAT_030ca4d4;
  }
  *(uint *)(DAT_030ca4cc + 4) = param_1;
  return DAT_030ca4d4;
}


