/**
 * FUN_030a2920 @ 0x030a2920
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a2920(undefined4 *param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar7 = *(int *)*param_1;
  FUN_030a386a((int *)*param_1,param_2,param_1[1]);
  sVar1 = (short)((uint)((*(short *)param_1[1] * 0x3fff + 0x4000) * 2) >> 0x10);
  sVar2 = (short)((uint)((((short *)param_1[1])[1] * 0x3fff + 0x4000) * 2) >> 0x10);
  *param_3 = sVar1 + sVar2;
  param_3[iVar7 * 2 + -1] = sVar1 - sVar2;
  for (iVar4 = 1; iVar4 <= iVar7 / 2; iVar4 = iVar4 + 1) {
    iVar3 = param_1[1];
    iVar5 = iVar7 - iVar4;
    iVar12 = (int)*(short *)(iVar3 + iVar4 * 4);
    iVar11 = (int)*(short *)(iVar3 + iVar5 * 4);
    iVar10 = iVar4 * 4 + 2;
    iVar8 = (int)*(short *)(iVar3 + iVar10);
    iVar3 = (int)*(short *)(iVar3 + iVar5 * 4 + 2);
    iVar13 = iVar8 - iVar3;
    iVar9 = (int)*(short *)(param_1[2] + iVar4 * 4);
    iVar6 = iVar12 - iVar11 >> 1;
    iVar10 = (int)*(short *)(param_1[2] + iVar10);
    iVar8 = (iVar8 + iVar3 + 1) * 0x8000 >> 0x10;
    iVar11 = (iVar11 + iVar12) * 0x2000;
    iVar3 = iVar9 * iVar6 - iVar8 * iVar10 >> 1;
    param_3[iVar4 * 2 + -1] = (short)((uint)((iVar11 + iVar3 + 0x4000) * 2) >> 0x10);
    iVar8 = iVar6 * iVar10 + iVar9 * iVar8 >> 1;
    param_3[iVar4 * 2] = (short)((uint)((iVar13 * 0x2000 + iVar8 + 0x4000) * 2) >> 0x10);
    param_3[iVar5 * 2 + -1] = (short)((uint)(((iVar11 - iVar3) + 0x4000) * 2) >> 0x10);
    param_3[iVar5 * 2] = (short)((uint)((iVar8 + iVar13 * -0x2000 + 0x4000) * 2) >> 0x10);
  }
  return;
}


