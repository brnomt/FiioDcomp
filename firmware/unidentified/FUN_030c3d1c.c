/**
 * FUN_030c3d1c @ 0x030c3d1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c3d1c(uint *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  piVar1 = (int *)FUN_030ca4a0(*param_1 << 2);
  iVar6 = 0;
  if (0 < param_4) {
    do {
      iVar2 = FUN_030c3a52(param_1,param_3,piVar1,param_5);
      if (iVar2 != 0) {
        FUN_030ca488();
        return 0xffffffff;
      }
      if (0 < (int)*param_1) {
        piVar3 = (int *)(param_2 + iVar6 * 4);
        piVar4 = piVar3 + -1;
        piVar5 = piVar1 + -1;
        if ((*param_1 & 1) != 0) {
          *piVar3 = *piVar3 + *piVar1;
          piVar4 = piVar3;
          piVar5 = piVar1;
        }
        for (iVar2 = (int)*param_1 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
          piVar4[1] = piVar4[1] + piVar5[1];
          piVar3 = piVar4 + 2;
          piVar5 = piVar5 + 2;
          piVar4 = piVar4 + 2;
          *piVar4 = *piVar3 + *piVar5;
        }
        iVar6 = iVar6 + *param_1;
      }
    } while (iVar6 < param_4);
  }
  FUN_030ca488();
  return 0;
}


