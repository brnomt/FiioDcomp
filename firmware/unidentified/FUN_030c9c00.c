/**
 * FUN_030c9c00 @ 0x030c9c00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c9c00(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
  pbVar3 = DAT_030c9e40;
  if (3 < param_3) {
    pbVar3 = (byte *)(DAT_030c9e34 + (param_3 >> 1));
  }
  pbVar8 = pbVar3 + 0x400;
  piVar1 = param_1 + (param_2 >> 1);
  do {
    piVar2 = piVar1 + -2;
    iVar5 = *param_1 + *piVar2 >> 9;
    iVar4 = piVar1[-1] - param_1[1] >> 9;
    iVar6 = iVar4 * (uint)*pbVar3 + iVar5 * (uint)pbVar3[1];
    iVar7 = iVar4 * (uint)pbVar3[1] - iVar5 * (uint)*pbVar3;
    iVar4 = param_1[1] + piVar1[-1] >> 1;
    iVar5 = *param_1 - *piVar2 >> 1;
    *param_1 = iVar4 + iVar6;
    param_1[1] = iVar5 + iVar7;
    *piVar2 = iVar4 - iVar6;
    piVar1[-1] = iVar7 - iVar5;
    pbVar3 = pbVar3 + param_3;
    param_1 = param_1 + 2;
    piVar1 = piVar2;
  } while (pbVar3 < pbVar8);
  do {
    piVar1 = piVar2 + -2;
    pbVar3 = pbVar3 + -param_3;
    iVar4 = piVar2[-1] - param_1[1] >> 9;
    iVar5 = *param_1 + *piVar1 >> 9;
    iVar7 = iVar4 * (uint)pbVar3[1] + iVar5 * (uint)*pbVar3;
    iVar4 = iVar4 * (uint)*pbVar3 - iVar5 * (uint)pbVar3[1];
    iVar5 = param_1[1] + piVar2[-1] >> 1;
    iVar6 = *param_1 - *piVar1 >> 1;
    *param_1 = iVar5 + iVar7;
    param_1[1] = iVar6 + iVar4;
    *piVar1 = iVar5 - iVar7;
    param_1 = param_1 + 2;
    piVar2[-1] = iVar4 - iVar6;
    piVar2 = piVar1;
  } while (param_1 < piVar1);
  return;
}


