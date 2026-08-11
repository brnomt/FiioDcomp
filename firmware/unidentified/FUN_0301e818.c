/**
 * FUN_0301e818 @ 0x0301e818
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301e818(int param_1)

{
  uint uVar1;
  
  uVar1 = 0x20U - *(int *)(param_1 + 0xc) & 7;
  if (uVar1 == 0) {
    uVar1 = 8;
  }
  return uVar1;
}


