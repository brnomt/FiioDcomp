/**
 * FUN_0301e888 @ 0x0301e888
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301e888(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc) & 7;
  if (uVar1 != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) - uVar1;
  }
  return;
}


