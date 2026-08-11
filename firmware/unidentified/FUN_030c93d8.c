/**
 * FUN_030c93d8 @ 0x030c93d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c93d8(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  pbVar6 = DAT_030c9904;
  iVar9 = param_1[param_2 + -3];
  bVar1 = *DAT_030c9904;
  bVar2 = DAT_030c9904[1];
  param_1[param_2 + -3] = (param_1[param_2 + -1] >> 8) * (uint)bVar2 + (iVar9 >> 8) * (uint)bVar1;
  param_1[param_2 + -1] = (uint)bVar1 * (param_1[param_2 + -1] >> 8) - (iVar9 >> 8) * (uint)bVar2;
  pbVar6 = pbVar6 + param_3;
  piVar3 = param_1 + param_2 + -7;
  iVar9 = (int)param_1 + ((param_2 >> 1) * 4 - (int)piVar3) >> 2;
  iVar8 = (iVar9 + -4) / -4;
  piVar4 = piVar3;
  pbVar7 = pbVar6;
  if (0 < iVar8) {
    do {
      iVar5 = iVar8;
      bVar1 = *pbVar7;
      iVar8 = *piVar4;
      bVar2 = pbVar7[1];
      *piVar4 = (piVar4[2] >> 8) * (uint)bVar2 + (iVar8 >> 8) * (uint)bVar1;
      piVar4[2] = (piVar4[2] >> 8) * (uint)bVar1 - (iVar8 >> 8) * (uint)bVar2;
      iVar8 = iVar5 + -1;
      piVar4 = piVar4 + -4;
      pbVar7 = pbVar7 + param_3;
    } while (iVar8 != 0);
    iVar5 = iVar5 + -5;
    iVar5 = (iVar5 + iVar9) / iVar5;
    piVar3 = piVar3 + iVar5 * -4;
    pbVar7 = pbVar6 + (iVar5 + -1) * param_3 + param_3;
  }
  bVar1 = pbVar7[1];
  iVar9 = piVar3[2];
  bVar2 = *pbVar7;
  piVar3[2] = (iVar9 >> 8) * (uint)bVar1 - (*piVar3 >> 8) * (uint)bVar2;
  *piVar3 = (iVar9 >> 8) * (uint)bVar2 + (*piVar3 >> 8) * (uint)bVar1;
  piVar3 = piVar3 + -4;
  iVar9 = (((int)param_1 - (int)piVar3 >> 2) + -4) / -4;
  if (0 < iVar9) {
    pbVar7 = pbVar7 + (1 - param_3);
    do {
      bVar1 = *pbVar7;
      iVar8 = *piVar3;
      bVar2 = pbVar7[-1];
      *piVar3 = (piVar3[2] >> 8) * (uint)bVar2 + (iVar8 >> 8) * (uint)bVar1;
      piVar3[2] = (uint)bVar1 * (piVar3[2] >> 8) - (iVar8 >> 8) * (uint)bVar2;
      piVar3 = piVar3 + -4;
      pbVar7 = pbVar7 + -param_3;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar5 = param_1[2];
  iVar9 = *param_1;
  bVar1 = DAT_030c9904[1];
  bVar2 = *DAT_030c9904;
  iVar8 = param_1[param_2 + -4];
  iVar11 = param_1[param_2 + -2];
  param_1[param_2 + -4] = (iVar5 >> 8) * (uint)bVar1 - (iVar9 >> 8) * (uint)bVar2;
  param_1[param_2 + -2] = (iVar5 >> 8) * (uint)bVar2 + (iVar9 >> 8) * (uint)bVar1;
  iVar8 = iVar8 >> 8;
  bVar1 = *pbVar6;
  bVar2 = pbVar6[1];
  piVar4 = param_1 + param_2 + -8;
  iVar9 = (((int)param_1 + ((param_2 >> 1) * 4 - (int)piVar4) >> 2) + -4) / -4;
  *param_1 = (iVar11 >> 8) * (uint)bVar1 - iVar8 * (uint)bVar2;
  param_1[2] = (iVar11 >> 8) * (uint)bVar2 + (uint)bVar1 * iVar8;
  if (iVar9 < 1) {
    return;
  }
  pbVar7 = pbVar6 + 1;
  piVar3 = param_1 + 6;
  do {
    pbVar6 = pbVar6 + param_3;
    bVar1 = *pbVar7;
    iVar10 = *piVar3;
    iVar11 = piVar3[-2];
    bVar2 = pbVar7[-1];
    iVar5 = *piVar4;
    iVar8 = piVar4[2];
    *piVar4 = (iVar10 >> 8) * (uint)bVar1 - (iVar11 >> 8) * (uint)bVar2;
    piVar4[2] = (iVar10 >> 8) * (uint)bVar2 + (iVar11 >> 8) * (uint)bVar1;
    bVar1 = *pbVar6;
    bVar2 = pbVar6[1];
    piVar3[-2] = (iVar8 >> 8) * (uint)bVar1 - (iVar5 >> 8) * (uint)bVar2;
    *piVar3 = (iVar8 >> 8) * (uint)bVar2 + (iVar5 >> 8) * (uint)bVar1;
    piVar4 = piVar4 + -4;
    pbVar7 = pbVar7 + param_3;
    iVar9 = iVar9 + -1;
    piVar3 = piVar3 + 4;
  } while (iVar9 != 0);
  return;
}


