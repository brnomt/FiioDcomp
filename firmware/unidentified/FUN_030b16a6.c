/**
 * FUN_030b16a6 @ 0x030b16a6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b16a6(int param_1,uint param_2)

{
  uint uVar1;
  
  if ((int)param_2 < 1) {
    return;
  }
  do {
    if ((int)param_2 < 0x20) {
      param_2 = param_2 & 0x1f;
      if (*(int *)(param_1 + 8) < (int)param_2) {
        param_2 = param_2 - *(int *)(param_1 + 8);
        FUN_030b1532(param_1);
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) << (param_2 & 0xff);
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) - param_2;
      return;
    }
    uVar1 = 0x1f;
    if (*(int *)(param_1 + 8) < 0x1f) {
      uVar1 = 0x1f - *(int *)(param_1 + 8);
      FUN_030b1532(param_1);
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) << (uVar1 & 0xff);
    param_2 = param_2 - 0x1f;
    *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) - uVar1;
  } while (0 < (int)param_2);
  return;
}


