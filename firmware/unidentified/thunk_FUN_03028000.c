/**
 * thunk_FUN_03028000 @ 0x03027ff8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

bool thunk_FUN_03028000(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_r4;
  int iVar12;
  int iVar13;
  int unaff_r6;
  int iVar14;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  uint uVar15;
  uint unaff_r10;
  int unaff_r11;
  bool bVar16;
  undefined8 uVar17;
  int in_stack_00000000;
  int in_stack_00000004;
  uint in_stack_00000008;
  uint uStack0000000c;
  uint in_stack_00000010;
  int in_stack_00000014;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
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
  
  do {
    uStack0000000c = (unaff_r7 - param_1) + -1;
    for (iVar12 = 0; iVar12 < (int)uStack0000000c; iVar12 = iVar12 + 1) {
      if ((uint)(DAT_030282b8[3] + iVar12) <= *(int *)(DAT_030282b0 + 0x10) - 1U) {
        FUN_03027e02(in_stack_00000058);
      }
    }
    uStack0000000c = unaff_r7 - unaff_r6;
    for (iVar12 = 0; iVar12 < unaff_r6; iVar12 = iVar12 + 1) {
      iVar11 = (int)*(short *)(DAT_030282b0 + 6);
      FUN_02ff89c2(DAT_030282b4 + iVar12 * iVar11 * 4,
                   DAT_030282b4 + iVar11 * ((iVar12 - unaff_r6) + 4) * 4,iVar11 << 2);
      DAT_030282b8[iVar12] = uStack0000000c + iVar12;
    }
    for (iVar12 = 0; iVar11 = DAT_030282b0, iVar12 < (unaff_r9 - unaff_r7) + 1; iVar12 = iVar12 + 1)
    {
      uStack0000000c = unaff_r7 + iVar12;
      if (*(int *)(DAT_030282b0 + 0x10) - 1U < uStack0000000c) {
        if ((unaff_r6 < 1) && (iVar12 < 1)) goto LAB_0302830e;
        iVar11 = (int)*(short *)(DAT_030282b0 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar11 * (unaff_r6 + iVar12) * 4,
                     DAT_030282b4 + iVar11 * (unaff_r6 + iVar12 + -1) * 4,iVar11 << 2);
      }
      else {
        FUN_03027e02(in_stack_00000058);
        iVar10 = (int)*(short *)(iVar11 + 6);
        FUN_02ff89c2(DAT_030282b4 + iVar10 * (unaff_r6 + iVar12) * 4,
                     *(undefined4 *)(*(int *)(iVar11 + 0x20) + 8),iVar10 << 2);
      }
      DAT_030282b8[unaff_r6 + iVar12] = uStack0000000c;
    }
    do {
      iVar12 = *DAT_030282b8 * in_stack_00000000 * -4 + DAT_030282b4;
      iVar11 = iVar12 + in_stack_00000018;
      bVar3 = *(byte *)(iVar11 + 3);
      in_stack_00000014 = iVar12 + in_stack_00000014;
      bVar16 = unaff_r10 != 0;
      uVar15 = (uint)*(byte *)(in_stack_00000014 + 3);
      if (bVar16) {
        uVar15 = (uint)bVar3;
      }
      iVar10 = in_stack_00000010 + iVar12;
      bVar4 = *(byte *)(iVar10 + 3);
      iVar12 = iVar12 + in_stack_00000008;
      uStack0000003c = (uint)*(byte *)(iVar12 + 3);
      if (bVar16) {
        uStack0000003c = (uint)bVar4;
      }
      bVar5 = *(byte *)(iVar11 + 2);
      uStack00000028 = (uint)*(byte *)(in_stack_00000014 + 2);
      if (bVar16) {
        uStack00000028 = (uint)bVar5;
      }
      bVar1 = *(byte *)(iVar10 + 2);
      in_stack_00000018 = (uint)*(byte *)(iVar12 + 2);
      if (bVar16) {
        in_stack_00000018 = (uint)bVar1;
      }
      bVar2 = *(byte *)(iVar11 + 1);
      in_stack_00000010 = (uint)*(byte *)(in_stack_00000014 + 1);
      if (bVar16) {
        in_stack_00000010 = (uint)bVar2;
      }
      uStack0000000c = (uint)*(byte *)(iVar10 + 1);
      in_stack_00000008 = (uint)*(byte *)(iVar12 + 1);
      if (bVar16) {
        in_stack_00000008 = uStack0000000c;
      }
      FUN_02ff8be8(in_stack_00000044,0x10);
      iVar12 = FUN_02ff8ee0();
      iVar14 = (unaff_r8 * 0x10000 - iVar12) + 0x10000;
      FUN_02ff8be8(in_stack_00000020,0x10);
      iVar10 = FUN_02ff8ee0();
      iVar13 = (unaff_r4 * 0x10000 - iVar10) + 0x10000;
      uVar6 = FUN_03011cac(iVar13,iVar14);
      iVar11 = FUN_03011cac((uint)bVar3 << 0x10,uVar6);
      iVar10 = iVar10 + unaff_r4 * -0x10000;
      uVar6 = FUN_03011cac(iVar10,iVar14);
      iVar7 = FUN_03011cac(uVar15 << 0x10,uVar6);
      iVar12 = iVar12 + unaff_r8 * -0x10000;
      uVar6 = FUN_03011cac(iVar13,iVar12);
      iVar8 = FUN_03011cac((uint)bVar4 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar10,iVar12);
      iVar9 = FUN_03011cac(uStack0000003c << 0x10,uVar6);
      uVar17 = FUN_02ff8e94(iVar9 + iVar11 + iVar7 + iVar8);
      FUN_02ff8e32((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xfffffff0);
      FUN_02ff8f6c();
      bVar3 = FUN_02ff8ee0();
      uVar6 = FUN_03011cac(iVar13,iVar14);
      iVar11 = FUN_03011cac((uint)bVar5 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar10,iVar14);
      iVar7 = FUN_03011cac(uStack00000028 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar13,iVar12);
      iVar8 = FUN_03011cac((uint)bVar1 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar10,iVar12);
      iVar9 = FUN_03011cac(in_stack_00000018 << 0x10,uVar6);
      uVar17 = FUN_02ff8e94(iVar9 + iVar11 + iVar7 + iVar8);
      FUN_02ff8e32((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xfffffff0);
      FUN_02ff8f6c();
      bVar4 = FUN_02ff8ee0();
      uVar6 = FUN_03011cac(iVar13,iVar14);
      iVar11 = FUN_03011cac((uint)bVar2 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar10,iVar14);
      iVar7 = FUN_03011cac(in_stack_00000010 << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar13,iVar12);
      iVar8 = FUN_03011cac(uStack0000000c << 0x10,uVar6);
      uVar6 = FUN_03011cac(iVar10,iVar12);
      iVar12 = FUN_03011cac(in_stack_00000008 << 0x10,uVar6);
      uVar17 = FUN_02ff8e94(iVar12 + iVar11 + iVar7 + iVar8);
      FUN_02ff8e32((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0xfffffff0);
      FUN_02ff8f6c();
      bVar5 = FUN_02ff8ee0();
      if ((((-1 < unaff_r8) && (unaff_r8 <= in_stack_00000050 * 2)) && (-1 < unaff_r4)) &&
         (unaff_r4 <= in_stack_00000000 * 2)) {
        *(ushort *)(in_stack_00000048 + unaff_r11 * 2) =
             (bVar5 & 0xf8) << 8 | (bVar4 & 0xfc) << 3 | (ushort)(bVar3 >> 3);
      }
      unaff_r11 = unaff_r11 + 1;
      if (in_stack_0000004c <= unaff_r11) {
LAB_0302830e:
        iVar12 = *(int *)(in_stack_00000058 + 0x24) + 1;
        *(int *)(in_stack_00000058 + 0x24) = iVar12;
        bVar16 = iVar12 != *(int *)(in_stack_00000058 + 0x10);
        if (!bVar16) {
          *(undefined4 *)(DAT_030283e0 + 0x1c) = 0;
        }
        return bVar16;
      }
      uVar6 = FUN_02ff8e60();
      in_stack_00000020 = FUN_02ff8b68(uVar6,in_stack_00000040);
      unaff_r4 = FUN_02ff8eae();
      iVar12 = unaff_r4 * 4;
      in_stack_00000018 = in_stack_00000038 + iVar12;
      in_stack_00000014 = in_stack_00000038 + iVar12 + 4;
      in_stack_00000008 = iVar12 + 4 + in_stack_00000030;
      in_stack_00000010 = iVar12 + in_stack_00000030;
      unaff_r10 = (uint)(in_stack_00000004 + -1 < unaff_r4 + 1);
      param_1 = DAT_030282b8[3];
    } while (in_stack_00000024 <= param_1);
    unaff_r6 = 0;
    unaff_r9 = in_stack_00000024;
    if (in_stack_00000024 - param_1 < 4) {
      unaff_r7 = param_1 + 1;
      unaff_r6 = 4 - (in_stack_00000024 - param_1);
    }
    else {
      unaff_r7 = in_stack_00000024 + -3;
    }
  } while( true );
}
