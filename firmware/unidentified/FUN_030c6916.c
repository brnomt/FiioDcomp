/**
 * FUN_030c6916 @ 0x030c6916
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c6916(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < param_1[3]) {
    piVar1 = (int *)*param_1;
    param_1[3] = 0;
    param_1[1] = (int)piVar1;
    param_1[4] = piVar1[2];
    param_1[2] = piVar1[1] + *piVar1;
  }
  iVar3 = 0;
  do {
    iVar2 = param_1[4];
    while (iVar2 <= param_3) {
      iVar2 = param_1[3] + *(int *)(param_1[1] + 8);
      param_1[3] = iVar2;
      piVar1 = *(int **)(param_1[1] + 0xc);
      param_1[1] = (int)piVar1;
      iVar2 = iVar2 + piVar1[2];
      param_1[4] = iVar2;
      param_1[2] = piVar1[1] + *piVar1;
    }
    iVar2 = param_3 - param_1[3];
    param_3 = param_3 + 1;
    *(char *)(param_1[2] + iVar2) = (char)param_2;
    param_2 = param_2 >> 8;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


