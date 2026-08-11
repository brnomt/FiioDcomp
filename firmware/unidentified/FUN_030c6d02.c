/**
 * FUN_030c6d02 @ 0x030c6d02
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c6d02(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)param_1[1];
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)FUN_030c6432(*param_1);
    param_1[2] = piVar2;
    param_1[1] = piVar2;
    iVar1 = 0;
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
    }
    return iVar1;
  }
  iVar1 = *piVar2;
  iVar4 = piVar2[2];
  iVar3 = *(int *)(iVar1 + 0x400);
  if (param_2 <= (iVar3 - iVar4) - piVar2[1]) {
    return iVar1 + iVar4 + piVar2[1];
  }
  if (iVar4 == 0) {
    if (param_2 < iVar3) {
      param_2 = iVar3;
    }
    *(int *)(iVar1 + 0x400) = param_2;
    return ((int *)param_1[1])[1] + *(int *)param_1[1];
  }
  piVar2 = (int *)FUN_030c6432(*param_1);
  if (piVar2 != (int *)0x0) {
    *(int **)(param_1[1] + 0xc) = piVar2;
    param_1[1] = piVar2;
    return *piVar2;
  }
  return 0;
}


