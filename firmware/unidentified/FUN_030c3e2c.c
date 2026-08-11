/**
 * FUN_030c3e2c @ 0x030c3e2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030c3e2c(uint *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  piVar1 = (int *)FUN_030ca4a0(*param_1 << 2);
  param_6 = param_6 + param_3;
  while( true ) {
    if (param_6 <= param_3) {
      FUN_030ca488();
      return 0;
    }
    iVar2 = FUN_030c3a52(param_1,param_5,piVar1,param_7);
    if (iVar2 != 0) break;
    if (0 < (int)*param_1) {
      piVar3 = piVar1 + -1;
      if ((*param_1 & 1) != 0) {
        iVar2 = *(int *)(param_2 + iVar5 * 4);
        iVar5 = iVar5 + 1;
        *(int *)(iVar2 + param_3 * 4) = *(int *)(iVar2 + param_3 * 4) + *piVar1;
        piVar3 = piVar1;
        if (iVar5 == param_4) {
          iVar5 = 0;
          param_3 = param_3 + 1;
        }
      }
      for (iVar2 = (int)*param_1 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
        iVar4 = *(int *)(param_2 + iVar5 * 4);
        *(int *)(iVar4 + param_3 * 4) = *(int *)(iVar4 + param_3 * 4) + piVar3[1];
        iVar5 = iVar5 + 1;
        if (iVar5 == param_4) {
          iVar5 = 0;
          param_3 = param_3 + 1;
        }
        iVar4 = *(int *)(param_2 + iVar5 * 4);
        piVar3 = piVar3 + 2;
        iVar5 = iVar5 + 1;
        *(int *)(iVar4 + param_3 * 4) = *(int *)(iVar4 + param_3 * 4) + *piVar3;
        if (iVar5 == param_4) {
          iVar5 = 0;
          param_3 = param_3 + 1;
        }
      }
    }
  }
  FUN_030ca488();
  return 0xffffffff;
}


