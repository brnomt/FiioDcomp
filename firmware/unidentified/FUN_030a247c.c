/**
 * FUN_030a247c @ 0x030a247c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a247c(short *param_1,short *param_2,int param_3,uint param_4)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = 0;
  if (0 < (int)(param_4 - 1)) {
    psVar2 = param_1 + -1;
    if ((param_4 & 1) == 0) {
      iVar7 = (int)*param_1;
      if (0 < iVar7) {
        iVar8 = iVar7;
      }
      psVar2 = param_1;
      if (-iVar8 != iVar7 && iVar8 <= -iVar7) {
        iVar8 = (int)(short)-iVar7;
      }
    }
    sVar1 = psVar2[1];
    for (iVar7 = (int)(param_4 - 1) >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      iVar5 = (int)sVar1;
      iVar6 = (int)psVar2[2];
      if (iVar8 < iVar5) {
        iVar8 = iVar5;
      }
      if (iVar8 < -iVar5) {
        iVar8 = (int)(short)-iVar5;
      }
      sVar1 = psVar2[3];
      if (iVar8 < iVar6) {
        iVar8 = iVar6;
      }
      if (iVar8 < -iVar6) {
        iVar8 = (int)(short)-iVar6;
      }
      psVar2 = psVar2 + 2;
    }
  }
  if (-1 < (int)(param_4 - 1)) {
    iVar7 = (int)param_1[param_4 - 1];
    if (iVar8 < iVar7) {
      iVar8 = iVar7;
    }
    if (-iVar8 != iVar7 && iVar8 <= -iVar7) {
      iVar8 = (int)(short)-iVar7;
    }
  }
  uVar3 = 0;
  for (; (iVar8 <= param_3 >> 1 && (iVar8 != 0)); iVar8 = (int)(short)(iVar8 << 1)) {
    uVar3 = uVar3 + 1;
  }
  if (0 < (int)param_4) {
    psVar4 = param_2 + -1;
    psVar2 = param_1 + -1;
    if ((param_4 & 1) != 0) {
      *param_2 = *param_1 << (uVar3 & 0xff);
      psVar4 = param_2;
      psVar2 = param_1;
    }
    iVar8 = (int)param_4 >> 1;
    if (iVar8 != 0) {
      do {
        psVar4[1] = psVar2[1] << (uVar3 & 0xff);
        psVar2 = psVar2 + 2;
        psVar4 = psVar4 + 2;
        *psVar4 = *psVar2 << (uVar3 & 0xff);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      return;
    }
    return;
  }
  return;
}


