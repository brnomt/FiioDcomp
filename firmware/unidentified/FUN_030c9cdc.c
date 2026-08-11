/**
 * FUN_030c9cdc @ 0x030c9cdc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c9cdc(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  param_2 = param_2 >> 1;
  iVar12 = param_3 >> 2;
  bVar1 = *DAT_030c9e34;
  bVar2 = DAT_030c9e34[1];
  uVar10 = (uint)DAT_030c9e34[0x402];
  uVar11 = (uint)DAT_030c9e34[0x403];
  iVar9 = *param_1 >> 8;
  iVar5 = -param_1[1] >> 8;
  if (iVar12 == 0) {
    iVar12 = (int)(uVar10 - bVar1) >> 2;
    iVar16 = (uint)bVar1 + iVar12;
    iVar14 = (int)(uVar11 - bVar2) >> 2;
    iVar13 = (uint)bVar2 + iVar14;
    *param_1 = iVar5 * iVar13 + iVar9 * iVar16;
    param_1[1] = iVar5 * iVar16 - iVar9 * iVar13;
    pbVar4 = DAT_030ca284;
    iVar12 = uVar10 - iVar12;
    iVar9 = param_1[2];
    iVar14 = uVar11 - iVar14;
    param_1[2] = (-param_1[3] >> 8) * iVar14 + (iVar9 >> 8) * iVar12;
    pbVar6 = pbVar4 + 0x402;
    param_1[3] = (-param_1[3] >> 8) * iVar12 - (iVar9 >> 8) * iVar14;
    uVar15 = (uint)*pbVar4;
    uVar8 = (uint)pbVar4[1];
    iVar12 = (int)(uVar8 - uVar11) >> 2;
    iVar9 = (int)(uVar15 - uVar10) >> 2;
    param_1[4] = (-param_1[5] >> 8) * (uVar11 + iVar12) + (param_1[4] >> 8) * (uVar10 + iVar9);
    iVar9 = uVar15 - iVar9;
    iVar12 = uVar8 - iVar12;
    param_1[5] = (-param_1[7] >> 8) * iVar12 + (param_1[6] >> 8) * iVar9;
    param_1[6] = (-param_1[7] >> 8) * iVar9 - (param_1[6] >> 8) * iVar12;
    piVar3 = param_1 + 8;
    iVar12 = (int)param_1 + (param_2 * 4 - (int)piVar3) + 0x1c;
    for (iVar9 = 1; iVar9 < ((int)((iVar12 >> 2) + ((uint)(iVar12 >> 0x1f) >> 0x1d)) >> 3) + 1;
        iVar9 = iVar9 + 1) {
      pbVar7 = pbVar6 + 1;
      uVar10 = (uint)*pbVar6;
      pbVar6 = pbVar6 + 2;
      uVar11 = (uint)*pbVar7;
      iVar5 = (int)(uVar10 - uVar15) >> 2;
      iVar13 = uVar15 + iVar5;
      iVar14 = (int)(uVar11 - uVar8) >> 2;
      iVar17 = *piVar3;
      iVar16 = uVar8 + iVar14;
      *piVar3 = (-piVar3[1] >> 8) * iVar16 + (iVar17 >> 8) * iVar13;
      piVar3[1] = (-piVar3[1] >> 8) * iVar13 - (iVar17 >> 8) * iVar16;
      iVar16 = piVar3[2];
      iVar14 = uVar11 - iVar14;
      iVar5 = uVar10 - iVar5;
      piVar3[2] = (-piVar3[3] >> 8) * iVar14 + (iVar16 >> 8) * iVar5;
      piVar3[3] = (-piVar3[3] >> 8) * iVar5 - (iVar16 >> 8) * iVar14;
      uVar15 = (uint)pbVar4[2];
      uVar8 = (uint)pbVar4[3];
      iVar5 = (int)(uVar15 - uVar10) >> 2;
      iVar14 = (int)(uVar8 - uVar11) >> 2;
      piVar3[4] = (-piVar3[5] >> 8) * (uVar11 + iVar14) + (piVar3[4] >> 8) * (uVar10 + iVar5);
      iVar14 = uVar8 - iVar14;
      iVar5 = uVar15 - iVar5;
      piVar3[5] = (-piVar3[7] >> 8) * iVar14 + (piVar3[6] >> 8) * iVar5;
      piVar3[6] = (-piVar3[7] >> 8) * iVar5 - (piVar3[6] >> 8) * iVar14;
      piVar3 = piVar3 + 8;
      pbVar4 = pbVar4 + 2;
    }
    return;
  }
  if (iVar12 != 1) {
    pbVar4 = DAT_030c9e40;
    if (3 < iVar12) {
      pbVar4 = DAT_030c9e34 + (param_3 >> 3);
    }
    bVar1 = *pbVar4;
    bVar2 = pbVar4[1];
    *param_1 = iVar5 * (uint)bVar2 + iVar9 * (uint)bVar1;
    param_1[1] = iVar5 * (uint)bVar1 - iVar9 * (uint)bVar2;
    iVar5 = (int)param_1 + (param_2 * 4 - (int)(param_1 + 2)) + 4;
    iVar9 = iVar5 >> 2;
    if (iVar9 < 2) {
      return;
    }
    iVar9 = iVar9 - (iVar5 >> 0x1f) >> 1;
    piVar3 = param_1 + 2;
    do {
      pbVar4 = pbVar4 + iVar12;
      iVar5 = *piVar3;
      bVar1 = *pbVar4;
      bVar2 = pbVar4[1];
      *piVar3 = (-piVar3[1] >> 8) * (uint)bVar2 + (iVar5 >> 8) * (uint)bVar1;
      piVar3[1] = (uint)bVar1 * (-piVar3[1] >> 8) - (iVar5 >> 8) * (uint)bVar2;
      iVar9 = iVar9 + -1;
      piVar3 = piVar3 + 2;
    } while (iVar9 != 0);
    return;
  }
  uVar15 = (uint)(DAT_030c9e34[0x402] >> 1);
  iVar14 = uVar15 + (bVar1 >> 1);
  uVar11 = (uint)(DAT_030c9e34[0x403] >> 1);
  iVar12 = (bVar2 >> 1) + uVar11;
  *param_1 = iVar5 * iVar12 + iVar9 * iVar14;
  param_1[1] = iVar5 * iVar14 - iVar9 * iVar12;
  pbVar4 = DAT_030c9e44;
  iVar5 = param_1[2];
  pbVar6 = DAT_030c9e44 + 0x402;
  uVar10 = (uint)(*DAT_030c9e44 >> 1);
  iVar12 = uVar15 + uVar10;
  uVar15 = (uint)(DAT_030c9e44[1] >> 1);
  iVar9 = uVar11 + uVar15;
  param_1[2] = (-param_1[3] >> 8) * iVar9 + (iVar5 >> 8) * iVar12;
  param_1[3] = (-param_1[3] >> 8) * iVar12 - (iVar5 >> 8) * iVar9;
  piVar3 = param_1 + 4;
  iVar12 = (int)param_1 + (param_2 * 4 - (int)piVar3) + 0xc;
  for (iVar9 = 1; iVar9 < ((int)((iVar12 >> 2) + ((uint)(iVar12 >> 0x1f) >> 0x1e)) >> 2) + 1;
      iVar9 = iVar9 + 1) {
    iVar5 = piVar3[1];
    pbVar7 = pbVar6 + 1;
    bVar1 = *pbVar6;
    iVar14 = uVar10 + (bVar1 >> 1);
    pbVar6 = pbVar6 + 2;
    bVar2 = *pbVar7;
    iVar16 = uVar15 + (bVar2 >> 1);
    piVar3[1] = (-iVar5 >> 8) * iVar14 - (*piVar3 >> 8) * iVar16;
    *piVar3 = (-iVar5 >> 8) * iVar16 + (*piVar3 >> 8) * iVar14;
    iVar16 = piVar3[2];
    uVar10 = (uint)(pbVar4[2] >> 1);
    iVar5 = (bVar1 >> 1) + uVar10;
    uVar15 = (uint)(pbVar4[3] >> 1);
    iVar14 = (bVar2 >> 1) + uVar15;
    piVar3[2] = (-piVar3[3] >> 8) * iVar14 + (iVar16 >> 8) * iVar5;
    piVar3[3] = (-piVar3[3] >> 8) * iVar5 - (iVar16 >> 8) * iVar14;
    piVar3 = piVar3 + 4;
    pbVar4 = pbVar4 + 2;
  }
  return;
}


