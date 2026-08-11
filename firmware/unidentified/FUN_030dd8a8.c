/**
 * FUN_030dd8a8 @ 0x030dd8a8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030dd8a8(int param_1)

{
  uint uVar1;
  
  uVar1 = -*(int *)(param_1 + 8) & 7;
  if (uVar1 != 0) {
    *(uint *)(param_1 + 8) = uVar1 + *(int *)(param_1 + 8);
  }
  return;
}


