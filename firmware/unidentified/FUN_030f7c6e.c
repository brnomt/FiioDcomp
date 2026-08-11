/**
 * FUN_030f7c6e @ 0x030f7c6e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f7c6e(int *param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  undefined8 uVar10;
  
  piVar3 = DAT_030f7f9c;
  piVar2 = DAT_030f7f98;
  if (DAT_030f7f98[1] != 0) {
    DAT_030f7f98[1] = 0;
    iVar6 = *piVar3;
    bVar8 = iVar6 == param_2;
    if (bVar8) {
      iVar6 = piVar3[1];
    }
    bVar9 = bVar8 && iVar6 == param_3;
    if (bVar8 && iVar6 == param_3) {
      bVar9 = piVar3[2] == param_4;
    }
    if (bVar9) {
      FUN_030f65cc(param_1,DAT_030f7f9c,0x9c);
      return;
    }
  }
  if (*piVar2 != param_4) {
    bVar1 = *DAT_030f7fa0;
    if ((bVar1 < 2) || (bVar1 == 2 || bVar1 == 3)) {
      uVar7 = 0x13b;
      uVar4 = DAT_030f7fa8;
    }
    else {
      uVar7 = 0x81;
      uVar4 = DAT_030f7fa4;
    }
    FUN_030f7e6a(uVar4,uVar7);
    *piVar2 = param_4;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_3 / param_4 >> 3;
  iVar6 = 0;
  if (0 < param_2) {
    do {
      iVar5 = iVar6 + 1;
      param_1[iVar6 * 0x11 + 5] = 0;
      param_1[iVar6 * 0x11 + 6] = 0;
      param_1[iVar6 * 0x11 + 7] = 0;
      param_1[iVar6 * 0x11 + 8] = 0;
      param_1[iVar6 * 0x11 + 9] = 0;
      param_1[iVar6 * 0x11 + 10] = 0;
      param_1[iVar6 * 0x11 + 0xb] = 0;
      param_1[iVar6 * 0x11 + 0xc] = 0;
      param_1[iVar6 * 0x11 + 0xd] = 0;
      param_1[iVar6 * 0x11 + 0xe] = 0;
      param_1[iVar6 * 0x11 + 0xf] = 0;
      param_1[iVar6 * 0x11 + 0x10] = 0;
      param_1[iVar6 * 0x11 + 0x11] = 0;
      param_1[iVar6 * 0x11 + 0x12] = 0;
      param_1[iVar6 * 0x11 + 0x13] = 0;
      param_1[iVar6 * 0x11 + 0x14] = 0;
      param_1[iVar6 * 0x11 + 0x15] = 0x3f;
      iVar6 = iVar5;
    } while (iVar5 < *param_1);
  }
  uVar10 = FUN_030f9a80(0,DAT_030f7fac);
  softfloat_dmul_a((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_030f7f90,DAT_030f7f94);
  iVar6 = FUN_030f6856();
  param_1[4] = iVar6;
  return;
}


