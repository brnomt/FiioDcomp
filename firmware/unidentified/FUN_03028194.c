/**
 * FUN_03028194 @ 0x03028194
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03028194(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,uint param_7,uint param_8,uint param_9,uint param_10,
                 uint param_11,uint param_12,undefined4 param_13,int param_14,uint param_15,
                 uint param_16,int param_17,uint param_18,int param_19,uint param_20,
                 undefined4 param_21,undefined4 param_22,int param_23,int param_24,int param_25,
                 int param_26,int param_27)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_r4;
  int iVar10;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  int unaff_r11;
  bool bVar11;
  undefined8 uVar12;
  
  while( true ) {
    iVar5 = FUN_03011cac(unaff_r9 << 0x10,param_2);
    param_26 = param_26 + unaff_r8 * -0x10000;
    uVar6 = FUN_03011cac(unaff_r5,param_26);
    iVar7 = FUN_03011cac(param_18 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r10,param_26);
    iVar8 = FUN_03011cac(param_20 << 0x10,uVar6);
    uVar12 = FUN_02ff8e94(iVar8 + unaff_r7 + iVar5 + iVar7);
    FUN_02ff8e32((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar1 = FUN_02ff8ee0();
    uVar6 = FUN_03011cac(unaff_r5,unaff_r6);
    iVar5 = FUN_03011cac(param_16 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r10,unaff_r6);
    iVar7 = FUN_03011cac(param_15 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r5,param_26);
    iVar8 = FUN_03011cac(param_12 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r10,param_26);
    iVar9 = FUN_03011cac(param_11 << 0x10,uVar6);
    uVar12 = FUN_02ff8e94(iVar9 + iVar5 + iVar7 + iVar8);
    FUN_02ff8e32((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar2 = FUN_02ff8ee0();
    uVar6 = FUN_03011cac(unaff_r5,unaff_r6);
    iVar5 = FUN_03011cac(param_10 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r10,unaff_r6);
    iVar7 = FUN_03011cac(param_9 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r5,param_26);
    iVar8 = FUN_03011cac(param_8 << 0x10,uVar6);
    uVar6 = FUN_03011cac(unaff_r10,param_26);
    iVar9 = FUN_03011cac(param_7 << 0x10,uVar6);
    uVar12 = FUN_02ff8e94(iVar9 + iVar5 + iVar7 + iVar8);
    FUN_02ff8e32((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar3 = FUN_02ff8ee0();
    if ((((-1 < unaff_r8) && (unaff_r8 <= param_25 * 2)) && (-1 < unaff_r4)) &&
       (unaff_r4 <= param_5 * 2)) {
      *(ushort *)(param_23 + unaff_r11 * 2) =
           (bVar3 & 0xf8) << 8 | (bVar2 & 0xfc) << 3 | (ushort)(bVar1 >> 3);
    }
    unaff_r11 = unaff_r11 + 1;
    if (param_24 <= unaff_r11) break;
    uVar6 = FUN_02ff8e60();
    uVar6 = FUN_02ff8b68(uVar6,param_21);
    unaff_r4 = FUN_02ff8eae();
    iVar7 = unaff_r4 * 4;
    iVar5 = DAT_030282b8[3];
    if (iVar5 < param_14) {
      iVar8 = 0;
      if (param_14 - iVar5 < 4) {
        iVar9 = iVar5 + 1;
        iVar8 = 4 - (param_14 - iVar5);
      }
      else {
        iVar9 = param_14 + -3;
      }
      for (iVar10 = 0; iVar10 < (iVar9 - iVar5) + -1; iVar10 = iVar10 + 1) {
        if ((uint)(DAT_030282b8[3] + iVar10) <= *(int *)(DAT_030282b0 + 0x10) - 1U) {
          FUN_03027e02(param_27);
        }
      }
      for (iVar5 = 0; iVar5 < iVar8; iVar5 = iVar5 + 1) {
        iVar10 = (int)*(short *)(DAT_030282b0 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar5 * iVar10 * 4,
                     DAT_030282b4 + iVar10 * ((iVar5 - iVar8) + 4) * 4,iVar10 << 2);
        DAT_030282b8[iVar5] = (iVar9 - iVar8) + iVar5;
      }
      for (iVar5 = 0; iVar10 = DAT_030282b0, iVar5 < (param_14 - iVar9) + 1; iVar5 = iVar5 + 1) {
        if (*(int *)(DAT_030282b0 + 0x10) - 1U < (uint)(iVar9 + iVar5)) {
          if ((iVar8 < 1) && (iVar5 < 1)) goto LAB_0302830e;
          iVar10 = (int)*(short *)(DAT_030282b0 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar10 * (iVar8 + iVar5) * 4,
                       DAT_030282b4 + iVar10 * (iVar8 + iVar5 + -1) * 4,iVar10 << 2);
        }
        else {
          FUN_03027e02(param_27);
          iVar4 = (int)*(short *)(iVar10 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar4 * (iVar8 + iVar5) * 4,
                       *(undefined4 *)(*(int *)(iVar10 + 0x20) + 8),iVar4 << 2);
        }
        DAT_030282b8[iVar8 + iVar5] = iVar9 + iVar5;
      }
    }
    iVar5 = *DAT_030282b8 * param_5 * -4 + DAT_030282b4;
    iVar9 = iVar5 + param_19 + iVar7;
    bVar1 = *(byte *)(iVar9 + 3);
    iVar8 = iVar5 + param_19 + iVar7 + 4;
    bVar11 = param_6 + -1 < unaff_r4 + 1;
    unaff_r9 = (uint)*(byte *)(iVar8 + 3);
    if (bVar11) {
      unaff_r9 = (uint)bVar1;
    }
    iVar10 = iVar7 + param_17 + iVar5;
    param_18 = (uint)*(byte *)(iVar10 + 3);
    iVar5 = iVar5 + iVar7 + 4 + param_17;
    param_20 = (uint)*(byte *)(iVar5 + 3);
    if (bVar11) {
      param_20 = param_18;
    }
    param_16 = (uint)*(byte *)(iVar9 + 2);
    param_15 = (uint)*(byte *)(iVar8 + 2);
    if (bVar11) {
      param_15 = param_16;
    }
    param_12 = (uint)*(byte *)(iVar10 + 2);
    param_11 = (uint)*(byte *)(iVar5 + 2);
    if (bVar11) {
      param_11 = param_12;
    }
    param_10 = (uint)*(byte *)(iVar9 + 1);
    param_9 = (uint)*(byte *)(iVar8 + 1);
    if (bVar11) {
      param_9 = param_10;
    }
    param_8 = (uint)*(byte *)(iVar10 + 1);
    param_7 = (uint)*(byte *)(iVar5 + 1);
    if (bVar11) {
      param_7 = param_8;
    }
    FUN_02ff8be8(param_22,0x10);
    param_26 = FUN_02ff8ee0();
    unaff_r6 = (unaff_r8 * 0x10000 - param_26) + 0x10000;
    FUN_02ff8be8(uVar6,0x10);
    iVar5 = FUN_02ff8ee0();
    unaff_r5 = (unaff_r4 * 0x10000 - iVar5) + 0x10000;
    uVar6 = FUN_03011cac(unaff_r5,unaff_r6);
    unaff_r7 = FUN_03011cac((uint)bVar1 << 0x10,uVar6);
    unaff_r10 = iVar5 + unaff_r4 * -0x10000;
    param_2 = FUN_03011cac(unaff_r10,unaff_r6);
  }
LAB_0302830e:
  iVar5 = *(int *)(param_27 + 0x24) + 1;
  *(int *)(param_27 + 0x24) = iVar5;
  bVar11 = iVar5 != *(int *)(param_27 + 0x10);
  if (!bVar11) {
    *(undefined4 *)(DAT_030283e0 + 0x1c) = 0;
  }
  return bVar11;
}


