/**
 * FUN_030c3c7e @ 0x030c3c7e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c3c7e(uint *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  param_4 = param_4 / (int)*param_1;
  piVar1 = (int *)FUN_030ca4a0(*param_1 << 2);
  iVar5 = 0;
  if (0 < param_4) {
    do {
      iVar2 = FUN_030c3a52(param_1,param_3,piVar1,param_5);
      if (iVar2 != 0) {
        FUN_030ca488();
        return 0xffffffff;
      }
      if (0 < (int)*param_1) {
        iVar2 = param_2 + (iVar5 - param_4) * 4;
        piVar3 = piVar1 + -1;
        if ((*param_1 & 1) != 0) {
          *(int *)(iVar2 + param_4 * 4) = *(int *)(iVar2 + param_4 * 4) + *piVar1;
          iVar2 = iVar2 + param_4 * 4;
          piVar3 = piVar1;
        }
        for (iVar4 = (int)*param_1 >> 1; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(int *)(iVar2 + param_4 * 4) = *(int *)(iVar2 + param_4 * 4) + piVar3[1];
          piVar3 = piVar3 + 2;
          *(int *)(iVar2 + param_4 * 8) = *(int *)(iVar2 + param_4 * 8) + *piVar3;
          iVar2 = iVar2 + param_4 * 8;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_4);
  }
  FUN_030ca488();
  return 0;
}


