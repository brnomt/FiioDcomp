/**
 * FUN_030b1718 @ 0x030b1718
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b1718(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = uVar1 & 7;
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar2 - uVar1;
    FUN_030b1532();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) << (uVar2 & 0xff);
  *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) - uVar2;
  return;
}


