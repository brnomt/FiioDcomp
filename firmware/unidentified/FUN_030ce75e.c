/**
 * FUN_030ce75e @ 0x030ce75e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ce75e(uint *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *param_1;
  uVar5 = param_2 + uVar3 & 7;
  *param_1 = uVar5;
  iVar2 = (int)(param_2 + uVar3) >> 3;
  uVar3 = param_1[2] - iVar2;
  param_1[2] = uVar3;
  param_1[1] = param_1[1] + iVar2;
  if (0 < (int)uVar3) {
    return;
  }
  do {
    uVar4 = param_1[2];
    *param_1 = uVar5;
    param_1[2] = uVar4;
    uVar3 = param_1[3];
    if (*(int *)(uVar3 + 0xc) == 0) {
      if ((int)(uVar4 * 8) < (int)uVar5) {
        param_1[2] = 0xffffffff;
      }
      return;
    }
    param_1[5] = param_1[5] + *(int *)(uVar3 + 8);
    piVar1 = *(int **)(uVar3 + 0xc);
    param_1[3] = (uint)piVar1;
    if (0 < (int)(piVar1[2] + uVar4)) {
      param_1[1] = (*piVar1 + piVar1[1]) - uVar4;
    }
    iVar2 = piVar1[2];
    param_1[2] = iVar2 + uVar4;
  } while ((int)(iVar2 + uVar4) < 1);
  return;
}


