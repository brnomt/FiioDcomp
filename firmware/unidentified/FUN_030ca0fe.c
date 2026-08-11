/**
 * FUN_030ca0fe @ 0x030ca0fe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030ca0fe(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,short *param_9,int param_10,int param_11,int param_12)

{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  int *piVar7;
  int *piVar8;
  byte *pbVar9;
  int unaff_r5;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int *local_64;
  byte *local_54;
  byte *local_50;
  
  if (param_4 == 0 || param_3 == 0) {
    unaff_r5 = param_1 >> 1;
  }
  if (param_4 != 0 && param_3 != 0) {
    unaff_r5 = param_2 >> 1;
  }
  iVar10 = param_1 >> 2;
  iVar3 = param_2 >> 2;
  iVar12 = iVar3;
  if (param_3 == 0) {
    iVar12 = iVar10;
  }
  piVar14 = (int *)(param_6 + iVar12 * 4);
  if (param_4 == 0 || param_3 == 0) {
    iVar12 = param_7 + (param_1 >> 1);
  }
  else {
    iVar12 = param_8 + (param_2 >> 1);
  }
  iVar13 = iVar3 - iVar10;
  local_54 = (byte *)param_7;
  if ((param_4 == 0) || (local_54 = (byte *)param_8, param_3 != 0)) {
    if (param_3 == 0) {
      iVar11 = 0;
      if (param_4 != 0) goto LAB_030ca178;
    }
    else {
      iVar11 = iVar13;
      if (param_4 != 0) {
        iVar10 = iVar3;
        iVar11 = 0;
      }
    }
    iVar13 = 0;
  }
  else {
    iVar11 = 0;
    local_54 = (byte *)param_7;
  }
LAB_030ca178:
  if (iVar11 != 0) {
    iVar3 = iVar11;
    if (param_12 < iVar11) {
      iVar3 = param_12;
    }
    if (param_11 < iVar11) {
      iVar11 = param_11;
    }
    piVar5 = piVar14 + -iVar3;
    piVar14 = piVar14 + -iVar11;
    param_11 = param_11 - iVar11;
    param_12 = param_12 - iVar3;
    iVar11 = (int)piVar14 - (int)piVar5 >> 2;
    psVar6 = param_9;
    iVar3 = iVar11;
    piVar8 = piVar14;
    if (0 < iVar11) {
      do {
        iVar4 = iVar3;
        iVar3 = piVar8[-1] >> 9;
        sVar2 = (short)iVar3;
        *psVar6 = (sVar2 - ((iVar3 < 0x8000) - 1 & sVar2 + 0x8001U)) -
                  ((-0x8001 < iVar3) - 1 & sVar2 + 0x8000U);
        iVar3 = iVar4 + -1;
        psVar6 = psVar6 + param_10;
        piVar8 = piVar8 + -1;
      } while (iVar3 != 0);
      piVar14 = (int *)((int)piVar14 - ((int)piVar14 - (int)piVar5 & 0xfffffffcU));
      param_9 = param_9 + param_10 + (iVar4 + -2 + iVar11) * param_10;
    }
  }
  iVar3 = param_12;
  if (iVar10 <= param_12) {
    iVar3 = iVar10;
  }
  iVar11 = param_11;
  if (iVar10 <= param_11) {
    iVar11 = iVar10;
  }
  piVar7 = piVar14 + -iVar11;
  local_64 = (int *)(param_5 + unaff_r5 * 4 + iVar11 * -8);
  param_11 = param_11 - iVar11;
  local_50 = (byte *)(iVar12 - iVar11);
  local_54 = (byte *)(iVar11 + (int)local_54);
  param_12 = param_12 - iVar3;
  iVar11 = (int)piVar7 - (int)(piVar14 + -iVar3) >> 2;
  psVar6 = param_9;
  pbVar9 = local_54;
  iVar12 = iVar11;
  piVar8 = local_64;
  pbVar1 = local_50;
  piVar5 = piVar7;
  if (0 < iVar11) {
    do {
      iVar4 = (int)((piVar8[-2] >> 8) * (uint)*pbVar9 + (piVar5[-1] >> 8) * (uint)pbVar1[-1]) >> 9;
      sVar2 = (short)iVar4;
      *psVar6 = (sVar2 - ((iVar4 < 0x8000) - 1 & sVar2 + 0x8001U)) -
                ((-0x8001 < iVar4) - 1 & sVar2 + 0x8000U);
      iVar12 = iVar12 + -1;
      psVar6 = psVar6 + param_10;
      pbVar9 = pbVar9 + 1;
      piVar8 = piVar8 + -2;
      pbVar1 = pbVar1 + -1;
      piVar5 = piVar5 + -1;
    } while (iVar12 != 0);
    local_64 = local_64 + iVar11 * -2;
    piVar7 = (int *)((int)piVar7 - ((int)piVar7 - (int)(piVar14 + -iVar3) & 0xfffffffcU));
    local_50 = local_50 + -iVar11;
    local_54 = local_54 + iVar11;
    param_9 = param_9 + param_10 + (iVar11 + -1) * param_10;
  }
  iVar3 = param_12;
  if (iVar10 <= param_12) {
    iVar3 = iVar10;
  }
  if (param_11 < iVar10) {
    iVar10 = param_11;
  }
  piVar8 = piVar7 + iVar10;
  local_64 = local_64 + iVar10 * 2;
  local_54 = local_54 + iVar10;
  iVar12 = (int)piVar7 + (iVar3 * 4 - (int)piVar8) >> 2;
  local_50 = local_50 + -iVar10;
  piVar14 = local_64;
  psVar6 = param_9;
  iVar11 = iVar12;
  if (0 < iVar12) {
    do {
      local_50 = local_50 + -1;
      iVar4 = (int)((*piVar8 >> 8) * (uint)*local_50 - (*piVar14 >> 8) * (uint)*local_54) >> 9;
      sVar2 = (short)iVar4;
      *psVar6 = (sVar2 - ((iVar4 < 0x8000) - 1 & sVar2 + 0x8001U)) -
                ((-0x8001 < iVar4) - 1 & sVar2 + 0x8000U);
      iVar11 = iVar11 + -1;
      piVar14 = piVar14 + 2;
      piVar8 = piVar8 + 1;
      local_54 = local_54 + 1;
      psVar6 = psVar6 + param_10;
    } while (iVar11 != 0);
    local_64 = local_64 + iVar12 * 2;
    param_9 = param_9 + param_10 + (iVar12 + -1) * param_10;
  }
  if (iVar13 != 0) {
    iVar12 = param_12 - iVar3;
    if (iVar13 <= param_12 - iVar3) {
      iVar12 = iVar13;
    }
    if (param_11 - iVar10 < iVar13) {
      iVar13 = param_11 - iVar10;
    }
    piVar14 = local_64 + iVar13 * 2;
    iVar10 = (int)local_64 + (iVar12 * 8 - (int)piVar14) + 4;
    iVar3 = iVar10 >> 2;
    if (1 < iVar3) {
      iVar3 = iVar3 - (iVar10 >> 0x1f) >> 1;
      do {
        iVar10 = -*piVar14 >> 9;
        sVar2 = (short)iVar10;
        *param_9 = (sVar2 - (sVar2 + 0x8001U & (iVar10 < 0x8000) - 1)) -
                   (sVar2 + 0x8000U & (-0x8001 < iVar10) - 1);
        piVar14 = piVar14 + 2;
        param_9 = param_9 + param_10;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return;
    }
    return;
  }
  return;
}


