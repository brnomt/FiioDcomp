/**
 * FUN_030a2a1c @ 0x030a2a1c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a2a1c(undefined4 *param_1,short *param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar4 = *(int *)*param_1;
  *(short *)param_1[1] = *param_2 + param_2[iVar4 * 2 + -1];
  *(short *)(param_1[1] + 2) = *param_2 - param_2[iVar4 * 2 + -1];
  for (iVar3 = 1; iVar3 < iVar4 / 2 + 1; iVar3 = iVar3 + 1) {
    iVar11 = iVar4 - iVar3;
    sVar6 = param_2[iVar3 * 2 + -1] + param_2[iVar11 * 2 + -1];
    sVar5 = param_2[iVar3 * 2] - param_2[iVar11 * 2];
    iVar12 = iVar3 * 4 + 2;
    iVar10 = (int)*(short *)(param_1[2] + iVar3 * 4);
    iVar7 = (int)(short)(param_2[iVar3 * 2 + -1] - param_2[iVar11 * 2 + -1]);
    iVar9 = (int)*(short *)(param_1[2] + iVar12);
    iVar8 = (int)(short)(param_2[iVar3 * 2] + param_2[iVar11 * 2]);
    sVar1 = (short)((uint)(((iVar10 * iVar7 - iVar8 * iVar9) + 0x4000) * 2) >> 0x10);
    *(short *)(param_1[1] + iVar3 * 4) = sVar6 + sVar1;
    sVar2 = (short)((uint)((iVar8 * iVar10 + iVar9 * iVar7 + 0x4000) * 2) >> 0x10);
    *(short *)(param_1[1] + iVar12) = sVar5 + sVar2;
    sVar5 = sVar5 - sVar2;
    *(short *)(param_1[1] + iVar11 * 4) = sVar6 - sVar1;
    iVar7 = iVar11 * 4 + 2;
    *(short *)(param_1[1] + iVar7) = sVar5;
    *(short *)(param_1[1] + iVar7) = -sVar5;
  }
  FUN_030a386a(*param_1,param_1[1],param_3);
  return;
}


