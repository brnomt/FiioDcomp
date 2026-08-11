/**
 * FUN_03027fa8 @ 0x03027fa8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_03027fa8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int unaff_r8;
  uint uVar17;
  int unaff_r11;
  bool bVar18;
  undefined8 uVar19;
  uint uStack00000008;
  uint uStack00000010;
  uint uStack00000018;
  int in_stack_00000024;
  uint uStack00000028;
  int in_stack_00000030;
  int in_stack_00000038;
  uint uStack0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  int in_stack_00000058;
  
  while( true ) {
    uVar7 = FUN_02ff8b68(param_1,param_2);
    iVar8 = FUN_02ff8eae();
    iVar11 = iVar8 * 4;
    iVar9 = DAT_030282b8[3];
    if (iVar9 < in_stack_00000024) {
      iVar14 = 0;
      if (in_stack_00000024 - iVar9 < 4) {
        iVar16 = iVar9 + 1;
        iVar14 = 4 - (in_stack_00000024 - iVar9);
      }
      else {
        iVar16 = in_stack_00000024 + -3;
      }
      for (iVar12 = 0; iVar12 < (iVar16 - iVar9) + -1; iVar12 = iVar12 + 1) {
        if ((uint)(DAT_030282b8[3] + iVar12) <= *(int *)(DAT_030282b0 + 0x10) - 1U) {
          FUN_03027e02(in_stack_00000058);
        }
      }
      for (iVar9 = 0; iVar9 < iVar14; iVar9 = iVar9 + 1) {
        iVar12 = (int)*(short *)(DAT_030282b0 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar9 * iVar12 * 4,
                     DAT_030282b4 + iVar12 * ((iVar9 - iVar14) + 4) * 4,iVar12 << 2);
        DAT_030282b8[iVar9] = (iVar16 - iVar14) + iVar9;
      }
      for (iVar9 = 0; iVar12 = DAT_030282b0, iVar9 < (in_stack_00000024 - iVar16) + 1;
          iVar9 = iVar9 + 1) {
        if (*(int *)(DAT_030282b0 + 0x10) - 1U < (uint)(iVar16 + iVar9)) {
          if ((iVar14 < 1) && (iVar9 < 1)) goto LAB_0302830e;
          iVar12 = (int)*(short *)(DAT_030282b0 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar12 * (iVar14 + iVar9) * 4,
                       DAT_030282b4 + iVar12 * (iVar14 + iVar9 + -1) * 4,iVar12 << 2);
        }
        else {
          FUN_03027e02(in_stack_00000058);
          iVar10 = (int)*(short *)(iVar12 + 6);
          FUN_02ff89c2(DAT_030282b4 + iVar10 * (iVar14 + iVar9) * 4,
                       *(undefined4 *)(*(int *)(iVar12 + 0x20) + 8),iVar10 << 2);
        }
        DAT_030282b8[iVar14 + iVar9] = iVar16 + iVar9;
      }
    }
    iVar9 = *DAT_030282b8 * param_5 * -4 + DAT_030282b4;
    iVar16 = iVar9 + in_stack_00000038 + iVar11;
    bVar4 = *(byte *)(iVar16 + 3);
    iVar14 = iVar9 + in_stack_00000038 + iVar11 + 4;
    bVar18 = param_6 + -1 < iVar8 + 1;
    uVar17 = (uint)*(byte *)(iVar14 + 3);
    if (bVar18) {
      uVar17 = (uint)bVar4;
    }
    iVar12 = iVar11 + in_stack_00000030 + iVar9;
    bVar5 = *(byte *)(iVar12 + 3);
    iVar9 = iVar9 + iVar11 + 4 + in_stack_00000030;
    uStack0000003c = (uint)*(byte *)(iVar9 + 3);
    if (bVar18) {
      uStack0000003c = (uint)bVar5;
    }
    bVar6 = *(byte *)(iVar16 + 2);
    uStack00000028 = (uint)*(byte *)(iVar14 + 2);
    if (bVar18) {
      uStack00000028 = (uint)bVar6;
    }
    bVar1 = *(byte *)(iVar12 + 2);
    uStack00000018 = (uint)*(byte *)(iVar9 + 2);
    if (bVar18) {
      uStack00000018 = (uint)bVar1;
    }
    bVar2 = *(byte *)(iVar16 + 1);
    uStack00000010 = (uint)*(byte *)(iVar14 + 1);
    if (bVar18) {
      uStack00000010 = (uint)bVar2;
    }
    bVar3 = *(byte *)(iVar12 + 1);
    uStack00000008 = (uint)*(byte *)(iVar9 + 1);
    if (bVar18) {
      uStack00000008 = (uint)bVar3;
    }
    FUN_02ff8be8(in_stack_00000044,0x10);
    iVar9 = FUN_02ff8ee0();
    iVar15 = (unaff_r8 * 0x10000 - iVar9) + 0x10000;
    FUN_02ff8be8(uVar7,0x10);
    iVar14 = FUN_02ff8ee0();
    iVar13 = (iVar8 * 0x10000 - iVar14) + 0x10000;
    uVar7 = FUN_03011cac(iVar13,iVar15);
    iVar11 = FUN_03011cac((uint)bVar4 << 0x10,uVar7);
    iVar14 = iVar14 + iVar8 * -0x10000;
    uVar7 = FUN_03011cac(iVar14,iVar15);
    iVar16 = FUN_03011cac(uVar17 << 0x10,uVar7);
    iVar9 = iVar9 + unaff_r8 * -0x10000;
    uVar7 = FUN_03011cac(iVar13,iVar9);
    iVar12 = FUN_03011cac((uint)bVar5 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar14,iVar9);
    iVar10 = FUN_03011cac(uStack0000003c << 0x10,uVar7);
    uVar19 = FUN_02ff8e94(iVar10 + iVar11 + iVar16 + iVar12);
    FUN_02ff8e32((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar4 = FUN_02ff8ee0();
    uVar7 = FUN_03011cac(iVar13,iVar15);
    iVar11 = FUN_03011cac((uint)bVar6 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar14,iVar15);
    iVar16 = FUN_03011cac(uStack00000028 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar13,iVar9);
    iVar12 = FUN_03011cac((uint)bVar1 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar14,iVar9);
    iVar10 = FUN_03011cac(uStack00000018 << 0x10,uVar7);
    uVar19 = FUN_02ff8e94(iVar10 + iVar11 + iVar16 + iVar12);
    FUN_02ff8e32((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar5 = FUN_02ff8ee0();
    uVar7 = FUN_03011cac(iVar13,iVar15);
    iVar11 = FUN_03011cac((uint)bVar2 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar14,iVar15);
    iVar16 = FUN_03011cac(uStack00000010 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar13,iVar9);
    iVar12 = FUN_03011cac((uint)bVar3 << 0x10,uVar7);
    uVar7 = FUN_03011cac(iVar14,iVar9);
    iVar9 = FUN_03011cac(uStack00000008 << 0x10,uVar7);
    uVar19 = FUN_02ff8e94(iVar9 + iVar11 + iVar16 + iVar12);
    FUN_02ff8e32((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xfffffff0);
    FUN_02ff8f6c();
    bVar6 = FUN_02ff8ee0();
    if ((((-1 < unaff_r8) && (unaff_r8 <= in_stack_00000050 * 2)) && (-1 < iVar8)) &&
       (iVar8 <= param_5 * 2)) {
      *(ushort *)(in_stack_00000048 + unaff_r11 * 2) =
           (bVar6 & 0xf8) << 8 | (bVar5 & 0xfc) << 3 | (ushort)(bVar4 >> 3);
    }
    unaff_r11 = unaff_r11 + 1;
    if (in_stack_0000004c <= unaff_r11) break;
    param_1 = FUN_02ff8e60();
    param_2 = in_stack_00000040;
  }
LAB_0302830e:
  iVar8 = *(int *)(in_stack_00000058 + 0x24) + 1;
  *(int *)(in_stack_00000058 + 0x24) = iVar8;
  bVar18 = iVar8 != *(int *)(in_stack_00000058 + 0x10);
  if (!bVar18) {
    *(undefined4 *)(DAT_030283e0 + 0x1c) = 0;
  }
  return bVar18;
}


