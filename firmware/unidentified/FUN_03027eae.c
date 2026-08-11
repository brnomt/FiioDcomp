/**
 * FUN_03027eae @ 0x03027eae
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03027eae(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined4 uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  uint uVar31;
  char in_CY;
  bool bVar32;
  undefined8 uVar33;
  uint uStack_78;
  uint uStack_70;
  uint uStack_68;
  uint uStack_58;
  uint uStack_44;
  
  iVar12 = DAT_030282b0;
  iVar8 = (int)*(short *)(DAT_030282b0 + 6);
  uVar23 = *(undefined4 *)(param_1 + 0xc);
  uVar9 = FUN_02ff8e60();
  uVar23 = FUN_02ff8e60(uVar23);
  uVar23 = FUN_02ff8b68(uVar23,uVar9);
  uVar9 = FUN_02ff8e60((int)*(short *)(iVar12 + 8));
  uVar10 = FUN_02ff8e60(*(undefined4 *)(param_1 + 0x10));
  uVar9 = FUN_02ff8b68(uVar10,uVar9);
  FUN_02ff8fa4(uVar23,uVar9);
  iVar13 = DAT_030282b4;
  if (in_CY == '\0') {
    uVar9 = uVar23;
  }
  iVar11 = (int)*(short *)(iVar12 + 6);
  sVar4 = *(short *)(iVar12 + 8);
  if (*(int *)(iVar12 + 0x1c) == 0) {
    iVar24 = 0;
    iVar29 = DAT_030282b4 + 0x4000;
    do {
      FUN_03027e02(param_1);
      FUN_02ff89c2(iVar13 + iVar24 * *(short *)(iVar12 + 6) * 4,
                   *(undefined4 *)(*(int *)(iVar12 + 0x20) + 8),(int)*(short *)(iVar12 + 6) << 2);
      *(int *)(iVar29 + iVar24 * 4) = iVar24;
      iVar24 = iVar24 + 1;
    } while (iVar24 < 4);
    *(undefined4 *)(iVar12 + 0x1c) = 1;
  }
  iVar21 = *(int *)(*(int *)(DAT_030282b0 + 0x20) + 0xc);
  iVar12 = *(int *)(*(int *)(DAT_030282b0 + 0x20) + 0x14);
  iVar13 = *(int *)(param_1 + 0x28);
  uVar10 = *(undefined4 *)(param_1 + 0x24);
  uVar23 = FUN_02ff8e60(iVar11);
  FUN_02ff8afc(uVar23,uVar9);
  iVar24 = FUN_02ff8eae();
  uVar23 = FUN_02ff8e60(uVar10);
  uVar23 = FUN_02ff8b68(uVar23,uVar9);
  iVar29 = FUN_02ff8eae();
  iVar14 = iVar29 + 1;
  iVar15 = iVar29 * iVar8 * 4;
  iVar16 = iVar8 * (iVar29 + 1) * 4;
  for (iVar17 = 0; iVar17 < iVar24; iVar17 = iVar17 + 1) {
    uVar10 = FUN_02ff8e60();
    uVar10 = FUN_02ff8b68(uVar10,uVar9);
    iVar18 = FUN_02ff8eae();
    iVar22 = iVar18 * 4;
    iVar19 = DAT_030282b8[3];
    if (iVar19 < iVar14) {
      iVar27 = 0;
      if (iVar14 - iVar19 < 4) {
        iVar30 = iVar19 + 1;
        iVar27 = 4 - (iVar14 - iVar19);
      }
      else {
        iVar30 = iVar29 + -2;
      }
      for (iVar25 = 0; iVar25 < (iVar30 - iVar19) + -1; iVar25 = iVar25 + 1) {
        if ((uint)(DAT_030282b8[3] + iVar25) <= *(int *)(DAT_030282b0 + 0x10) - 1U) {
          FUN_03027e02(param_1);
        }
      }
      for (iVar19 = 0; iVar19 < iVar27; iVar19 = iVar19 + 1) {
        iVar25 = (int)*(short *)(DAT_030282b0 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar19 * iVar25 * 4,
                     DAT_030282b4 + iVar25 * ((iVar19 - iVar27) + 4) * 4,iVar25 << 2);
        DAT_030282b8[iVar19] = (iVar30 - iVar27) + iVar19;
      }
      for (iVar19 = 0; iVar25 = DAT_030282b0, iVar19 < (iVar14 - iVar30) + 1; iVar19 = iVar19 + 1) {
        if (*(int *)(DAT_030282b0 + 0x10) - 1U < (uint)(iVar30 + iVar19)) {
          if ((iVar27 < 1) && (iVar19 < 1)) goto LAB_0302830e;
          iVar25 = (int)*(short *)(DAT_030282b0 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar25 * (iVar27 + iVar19) * 4,
                       DAT_030282b4 + iVar25 * (iVar27 + iVar19 + -1) * 4,iVar25 << 2);
        }
        else {
          FUN_03027e02(param_1);
          iVar20 = (int)*(short *)(iVar25 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar20 * (iVar27 + iVar19) * 4,
                       *(undefined4 *)(*(int *)(iVar25 + 0x20) + 8),iVar20 << 2);
        }
        DAT_030282b8[iVar27 + iVar19] = iVar30 + iVar19;
      }
    }
    iVar19 = *DAT_030282b8 * iVar11 * -4 + DAT_030282b4;
    iVar30 = iVar19 + iVar15 + iVar22;
    bVar5 = *(byte *)(iVar30 + 3);
    iVar27 = iVar19 + iVar15 + iVar22 + 4;
    bVar32 = iVar8 + -1 < iVar18 + 1;
    uVar31 = (uint)*(byte *)(iVar27 + 3);
    if (bVar32) {
      uVar31 = (uint)bVar5;
    }
    iVar25 = iVar22 + iVar16 + iVar19;
    bVar6 = *(byte *)(iVar25 + 3);
    iVar19 = iVar19 + iVar22 + 4 + iVar16;
    uStack_44 = (uint)*(byte *)(iVar19 + 3);
    if (bVar32) {
      uStack_44 = (uint)bVar6;
    }
    bVar7 = *(byte *)(iVar30 + 2);
    uStack_58 = (uint)*(byte *)(iVar27 + 2);
    if (bVar32) {
      uStack_58 = (uint)bVar7;
    }
    bVar1 = *(byte *)(iVar25 + 2);
    uStack_68 = (uint)*(byte *)(iVar19 + 2);
    if (bVar32) {
      uStack_68 = (uint)bVar1;
    }
    bVar2 = *(byte *)(iVar30 + 1);
    uStack_70 = (uint)*(byte *)(iVar27 + 1);
    if (bVar32) {
      uStack_70 = (uint)bVar2;
    }
    bVar3 = *(byte *)(iVar25 + 1);
    uStack_78 = (uint)*(byte *)(iVar19 + 1);
    if (bVar32) {
      uStack_78 = (uint)bVar3;
    }
    FUN_02ff8be8(uVar23,0x10);
    iVar19 = FUN_02ff8ee0();
    iVar28 = (iVar29 * 0x10000 - iVar19) + 0x10000;
    FUN_02ff8be8(uVar10,0x10);
    iVar27 = FUN_02ff8ee0();
    iVar26 = (iVar18 * 0x10000 - iVar27) + 0x10000;
    uVar10 = FUN_03011cac(iVar26,iVar28);
    iVar22 = FUN_03011cac((uint)bVar5 << 0x10,uVar10);
    iVar27 = iVar27 + iVar18 * -0x10000;
    uVar10 = FUN_03011cac(iVar27,iVar28);
    iVar30 = FUN_03011cac(uVar31 << 0x10,uVar10);
    iVar19 = iVar19 + iVar29 * -0x10000;
    uVar10 = FUN_03011cac(iVar26,iVar19);
    iVar25 = FUN_03011cac((uint)bVar6 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar27,iVar19);
    iVar20 = FUN_03011cac(uStack_44 << 0x10,uVar10);
    uVar33 = FUN_02ff8e94(iVar20 + iVar22 + iVar30 + iVar25);
    FUN_02ff8e32((int)uVar33,(int)((ulonglong)uVar33 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar5 = FUN_02ff8ee0();
    uVar10 = FUN_03011cac(iVar26,iVar28);
    iVar22 = FUN_03011cac((uint)bVar7 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar27,iVar28);
    iVar30 = FUN_03011cac(uStack_58 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar26,iVar19);
    iVar25 = FUN_03011cac((uint)bVar1 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar27,iVar19);
    iVar20 = FUN_03011cac(uStack_68 << 0x10,uVar10);
    uVar33 = FUN_02ff8e94(iVar20 + iVar22 + iVar30 + iVar25);
    FUN_02ff8e32((int)uVar33,(int)((ulonglong)uVar33 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar6 = FUN_02ff8ee0();
    uVar10 = FUN_03011cac(iVar26,iVar28);
    iVar22 = FUN_03011cac((uint)bVar2 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar27,iVar28);
    iVar30 = FUN_03011cac(uStack_70 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar26,iVar19);
    iVar25 = FUN_03011cac((uint)bVar3 << 0x10,uVar10);
    uVar10 = FUN_03011cac(iVar27,iVar19);
    iVar19 = FUN_03011cac(uStack_78 << 0x10,uVar10);
    uVar33 = FUN_02ff8e94(iVar19 + iVar22 + iVar30 + iVar25);
    FUN_02ff8e32((int)uVar33,(int)((ulonglong)uVar33 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar7 = FUN_02ff8ee0();
    if ((((-1 < iVar29) && (iVar29 <= sVar4 * 2)) && (-1 < iVar18)) && (iVar18 <= iVar11 * 2)) {
      *(ushort *)(iVar13 + (iVar21 - iVar12 & 0xfffffffeU) + iVar17 * 2) =
           (bVar7 & 0xf8) << 8 | (bVar6 & 0xfc) << 3 | (ushort)(bVar5 >> 3);
    }
  }
LAB_0302830e:
  iVar12 = *(int *)(param_1 + 0x24) + 1;
  *(int *)(param_1 + 0x24) = iVar12;
  bVar32 = iVar12 != *(int *)(param_1 + 0x10);
  if (!bVar32) {
    *(undefined4 *)(DAT_030283e0 + 0x1c) = 0;
  }
  return bVar32;
}


