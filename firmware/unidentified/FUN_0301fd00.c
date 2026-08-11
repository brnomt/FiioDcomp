/**
 * FUN_0301fd00 @ 0x0301fd00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301fd00(short *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                 int param_7,int param_8,undefined2 *param_9,int param_10)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  short sVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_40;
  
  iVar12 = param_3 * param_4 + param_2;
  puVar1 = (undefined1 *)((int)param_1 + param_5 + 0xb4);
  iVar10 = 0;
  local_40 = param_7;
  iVar8 = 0;
  if (((param_2 != 0) && (param_10 + 1 <= iVar12)) &&
     (*(int *)(DAT_0301ffd4 + 0xc) == 3 || *(int *)(DAT_0301ffd4 + 0xc) == 4)) {
    local_40 = *(int *)(DAT_0301ffd4 + 0x10);
    iVar8 = DAT_0301ffd8;
  }
  iVar7 = DAT_0301ffdc + param_2 * 0xc4;
  iVar2 = 0;
  iVar11 = param_7;
  if ((param_10 + param_4 <= iVar12) && (*(int *)(iVar7 + 0xbc) == 3 || *(int *)(iVar7 + 0xbc) == 4)
     ) {
    iVar11 = *(int *)(iVar7 + 0xc0);
    iVar2 = iVar7;
  }
  if (((param_2 != 0) && (param_10 + param_4 + 1 <= iVar12)) &&
     (*(int *)(iVar7 + -8) == 3 || *(int *)(iVar7 + -8) == 4)) {
    iVar10 = iVar7 + -0xc4;
  }
  psVar4 = DAT_0301ffd0;
  psVar6 = DAT_0301ffd0;
  psVar9 = DAT_0301ffd0;
  switch(param_5) {
  case 0:
    if (iVar8 != 0) {
      psVar6 = (short *)(iVar8 + 0x1e);
    }
    if (iVar2 != 0) {
      psVar4 = (short *)(iVar2 + 0x3c);
    }
    if (iVar10 != 0) {
      psVar9 = (short *)(iVar10 + 0x5a);
    }
    break;
  case 1:
    local_40 = param_7;
    psVar6 = param_1;
    if (iVar2 != 0) {
      psVar4 = (short *)(iVar2 + 0x5a);
      psVar9 = (short *)(iVar2 + 0x3c);
    }
    break;
  case 2:
    psVar4 = param_1;
    iVar11 = param_7;
    if (iVar8 != 0) {
      psVar6 = (short *)(iVar8 + 0x5a);
      psVar4 = param_1;
      psVar9 = (short *)(iVar8 + 0x1e);
    }
    break;
  case 3:
    local_40 = param_7;
    psVar4 = param_1 + 0xf;
    psVar6 = param_1 + 0x1e;
    psVar9 = param_1;
    iVar11 = param_7;
    break;
  case 4:
    if (iVar8 != 0) {
      psVar6 = (short *)(iVar8 + 0x78);
    }
    if (iVar2 != 0) {
      psVar4 = (short *)(iVar2 + 0x78);
    }
    if (iVar10 != 0) {
      psVar9 = (short *)(iVar10 + 0x78);
    }
    break;
  case 5:
    if (iVar8 != 0) {
      psVar6 = (short *)(iVar8 + 0x96);
    }
    if (iVar2 != 0) {
      psVar4 = (short *)(iVar2 + 0x96);
    }
    if (iVar10 != 0) {
      psVar9 = (short *)(iVar10 + 0x96);
    }
  }
  iVar8 = (int)*psVar6 - (int)*psVar9;
  iVar10 = (int)*psVar9 - (int)*psVar4;
  if (iVar8 < 0) {
    iVar8 = -iVar8;
  }
  if (iVar10 < 0) {
    iVar10 = -iVar10;
  }
  iVar12 = param_8 >> 1;
  iVar2 = param_7 >> 1;
  if (iVar8 < iVar10) {
    *puVar1 = 1;
    if (*psVar4 < 1) {
      iVar12 = -iVar12;
    }
    *param_9 = (short)((*psVar4 + iVar12) / param_8);
    uVar3 = 1;
    do {
      sVar5 = psVar4[uVar3];
      if (sVar5 != 0) {
        iVar10 = sVar5 * iVar11;
        iVar8 = iVar2;
        if (iVar10 < 1) {
          iVar8 = -iVar2;
        }
        sVar5 = (short)((iVar10 + iVar8) / param_7);
      }
      param_9[uVar3] = sVar5;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 8);
    return;
  }
  *puVar1 = 2;
  if (*psVar6 < 1) {
    iVar12 = -iVar12;
  }
  *param_9 = (short)((*psVar6 + iVar12) / param_8);
  uVar3 = 1;
  do {
    sVar5 = psVar6[uVar3 + 7];
    if (sVar5 != 0) {
      iVar10 = local_40 * sVar5;
      iVar8 = iVar2;
      if (iVar10 < 1) {
        iVar8 = -iVar2;
      }
      sVar5 = (short)((iVar10 + iVar8) / param_7);
    }
    param_9[uVar3] = sVar5;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return;
}


