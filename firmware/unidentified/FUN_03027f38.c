/**
 * FUN_03027f38 @ 0x03027f38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03027f38(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
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
  int unaff_r4;
  undefined4 uVar21;
  int unaff_r5;
  int iVar22;
  int iVar23;
  int unaff_r6;
  int iVar24;
  int iVar25;
  int unaff_r7;
  int iVar26;
  undefined4 unaff_r8;
  uint uVar27;
  bool bVar28;
  undefined8 uVar29;
  int in_stack_00000000;
  int in_stack_00000004;
  uint uStack00000008;
  uint uStack00000010;
  uint uStack00000018;
  uint uStack00000028;
  uint uStack0000003c;
  undefined4 in_stack_00000040;
  int in_stack_00000050;
  int in_stack_00000058;
  
  while( true ) {
    *(int *)(unaff_r7 + unaff_r4 * 4) = unaff_r4;
    unaff_r4 = unaff_r4 + 1;
    if (3 < unaff_r4) break;
    FUN_03027e02(in_stack_00000058);
    FUN_02ff89c2(unaff_r6 + unaff_r4 * *(short *)(unaff_r5 + 6) * 4,
                 *(undefined4 *)(*(int *)(unaff_r5 + 0x20) + 8),(int)*(short *)(unaff_r5 + 6) << 2);
  }
  *(undefined4 *)(unaff_r5 + 0x1c) = unaff_r8;
  iVar19 = *(int *)(*(int *)(DAT_030282b0 + 0x20) + 0xc);
  iVar7 = *(int *)(*(int *)(DAT_030282b0 + 0x20) + 0x14);
  iVar8 = *(int *)(in_stack_00000058 + 0x28);
  uVar21 = *(undefined4 *)(in_stack_00000058 + 0x24);
  uVar9 = FUN_02ff8e60(in_stack_00000000);
  FUN_02ff8afc(uVar9,in_stack_00000040);
  iVar10 = FUN_02ff8eae();
  FUN_02ff8e60(uVar21);
  uVar9 = FUN_02ff8b68();
  iVar11 = FUN_02ff8eae();
  iVar12 = iVar11 + 1;
  iVar13 = iVar11 * in_stack_00000004 * 4;
  iVar14 = in_stack_00000004 * (iVar11 + 1) * 4;
  for (iVar15 = 0; iVar15 < iVar10; iVar15 = iVar15 + 1) {
    uVar21 = FUN_02ff8e60();
    uVar21 = FUN_02ff8b68(uVar21,in_stack_00000040);
    iVar16 = FUN_02ff8eae();
    iVar20 = iVar16 * 4;
    iVar17 = DAT_030282b8[3];
    if (iVar17 < iVar12) {
      iVar24 = 0;
      if (iVar12 - iVar17 < 4) {
        iVar26 = iVar17 + 1;
        iVar24 = 4 - (iVar12 - iVar17);
      }
      else {
        iVar26 = iVar11 + -2;
      }
      for (iVar22 = 0; iVar22 < (iVar26 - iVar17) + -1; iVar22 = iVar22 + 1) {
        if ((uint)(DAT_030282b8[3] + iVar22) <= *(int *)(DAT_030282b0 + 0x10) - 1U) {
          FUN_03027e02(in_stack_00000058);
        }
      }
      for (iVar17 = 0; iVar17 < iVar24; iVar17 = iVar17 + 1) {
        iVar22 = (int)*(short *)(DAT_030282b0 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar17 * iVar22 * 4,
                     DAT_030282b4 + iVar22 * ((iVar17 - iVar24) + 4) * 4,iVar22 << 2);
        DAT_030282b8[iVar17] = (iVar26 - iVar24) + iVar17;
      }
      for (iVar17 = 0; iVar22 = DAT_030282b0, iVar17 < (iVar12 - iVar26) + 1; iVar17 = iVar17 + 1) {
        if (*(int *)(DAT_030282b0 + 0x10) - 1U < (uint)(iVar26 + iVar17)) {
          if ((iVar24 < 1) && (iVar17 < 1)) goto LAB_0302830e;
          iVar22 = (int)*(short *)(DAT_030282b0 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar22 * (iVar24 + iVar17) * 4,
                       DAT_030282b4 + iVar22 * (iVar24 + iVar17 + -1) * 4,iVar22 << 2);
        }
        else {
          FUN_03027e02(in_stack_00000058);
          iVar18 = (int)*(short *)(iVar22 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar18 * (iVar24 + iVar17) * 4,
                       *(undefined4 *)(*(int *)(iVar22 + 0x20) + 8),iVar18 << 2);
        }
        DAT_030282b8[iVar24 + iVar17] = iVar26 + iVar17;
      }
    }
    iVar17 = *DAT_030282b8 * in_stack_00000000 * -4 + DAT_030282b4;
    iVar26 = iVar17 + iVar13 + iVar20;
    bVar4 = *(byte *)(iVar26 + 3);
    iVar24 = iVar17 + iVar13 + iVar20 + 4;
    bVar28 = in_stack_00000004 + -1 < iVar16 + 1;
    uVar27 = (uint)*(byte *)(iVar24 + 3);
    if (bVar28) {
      uVar27 = (uint)bVar4;
    }
    iVar22 = iVar20 + iVar14 + iVar17;
    bVar5 = *(byte *)(iVar22 + 3);
    iVar17 = iVar17 + iVar20 + 4 + iVar14;
    uStack0000003c = (uint)*(byte *)(iVar17 + 3);
    if (bVar28) {
      uStack0000003c = (uint)bVar5;
    }
    bVar6 = *(byte *)(iVar26 + 2);
    uStack00000028 = (uint)*(byte *)(iVar24 + 2);
    if (bVar28) {
      uStack00000028 = (uint)bVar6;
    }
    bVar1 = *(byte *)(iVar22 + 2);
    uStack00000018 = (uint)*(byte *)(iVar17 + 2);
    if (bVar28) {
      uStack00000018 = (uint)bVar1;
    }
    bVar2 = *(byte *)(iVar26 + 1);
    uStack00000010 = (uint)*(byte *)(iVar24 + 1);
    if (bVar28) {
      uStack00000010 = (uint)bVar2;
    }
    bVar3 = *(byte *)(iVar22 + 1);
    uStack00000008 = (uint)*(byte *)(iVar17 + 1);
    if (bVar28) {
      uStack00000008 = (uint)bVar3;
    }
    FUN_02ff8be8(uVar9,0x10);
    iVar17 = FUN_02ff8ee0();
    iVar25 = (iVar11 * 0x10000 - iVar17) + 0x10000;
    FUN_02ff8be8(uVar21,0x10);
    iVar24 = FUN_02ff8ee0();
    iVar23 = (iVar16 * 0x10000 - iVar24) + 0x10000;
    uVar21 = FUN_03011cac(iVar23,iVar25);
    iVar20 = FUN_03011cac((uint)bVar4 << 0x10,uVar21);
    iVar24 = iVar24 + iVar16 * -0x10000;
    uVar21 = FUN_03011cac(iVar24,iVar25);
    iVar26 = FUN_03011cac(uVar27 << 0x10,uVar21);
    iVar17 = iVar17 + iVar11 * -0x10000;
    uVar21 = FUN_03011cac(iVar23,iVar17);
    iVar22 = FUN_03011cac((uint)bVar5 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar24,iVar17);
    iVar18 = FUN_03011cac(uStack0000003c << 0x10,uVar21);
    uVar29 = FUN_02ff8e94(iVar18 + iVar20 + iVar26 + iVar22);
    FUN_02ff8e32((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar4 = FUN_02ff8ee0();
    uVar21 = FUN_03011cac(iVar23,iVar25);
    iVar20 = FUN_03011cac((uint)bVar6 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar24,iVar25);
    iVar26 = FUN_03011cac(uStack00000028 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar23,iVar17);
    iVar22 = FUN_03011cac((uint)bVar1 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar24,iVar17);
    iVar18 = FUN_03011cac(uStack00000018 << 0x10,uVar21);
    uVar29 = FUN_02ff8e94(iVar18 + iVar20 + iVar26 + iVar22);
    FUN_02ff8e32((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar5 = FUN_02ff8ee0();
    uVar21 = FUN_03011cac(iVar23,iVar25);
    iVar20 = FUN_03011cac((uint)bVar2 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar24,iVar25);
    iVar26 = FUN_03011cac(uStack00000010 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar23,iVar17);
    iVar22 = FUN_03011cac((uint)bVar3 << 0x10,uVar21);
    uVar21 = FUN_03011cac(iVar24,iVar17);
    iVar17 = FUN_03011cac(uStack00000008 << 0x10,uVar21);
    uVar29 = FUN_02ff8e94(iVar17 + iVar20 + iVar26 + iVar22);
    FUN_02ff8e32((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar6 = FUN_02ff8ee0();
    if ((((-1 < iVar11) && (iVar11 <= in_stack_00000050 * 2)) && (-1 < iVar16)) &&
       (iVar16 <= in_stack_00000000 * 2)) {
      *(ushort *)(iVar8 + (iVar19 - iVar7 & 0xfffffffeU) + iVar15 * 2) =
           (bVar6 & 0xf8) << 8 | (bVar5 & 0xfc) << 3 | (ushort)(bVar4 >> 3);
    }
  }
LAB_0302830e:
  iVar7 = *(int *)(in_stack_00000058 + 0x24) + 1;
  *(int *)(in_stack_00000058 + 0x24) = iVar7;
  bVar28 = iVar7 != *(int *)(in_stack_00000058 + 0x10);
  if (!bVar28) {
    *(undefined4 *)(DAT_030283e0 + 0x1c) = 0;
  }
  return bVar28;
}


