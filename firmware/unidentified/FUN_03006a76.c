/**
 * FUN_03006a76 @ 0x03006a76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03006a76(void)

{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  ushort *puVar6;
  undefined2 uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined2 *unaff_r4;
  int unaff_r5;
  undefined2 unaff_r6;
  int unaff_r7;
  undefined2 *unaff_r8;
  uint unaff_r9;
  short unaff_r10;
  short unaff_r11;
  bool bVar12;
  short in_stack_00000008;
  short sStack0000000a;
  short in_stack_0000000c;
  short sStack0000000e;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  
  FUN_02ff2e00(0x4f);
  *DAT_03006c3c = *DAT_03006c40;
  *DAT_03006c44 = *DAT_03006c48;
  func_0x02fde8f6(DAT_03006c4c,DAT_03006c38,0x100);
  func_0x02fde8f6(DAT_03006c38,DAT_03006c30,0x100);
  if (*(char *)(DAT_03006c34 + 0x34f) == '\x01') {
    uVar7 = 0x94b2;
  }
  else {
    uVar7 = 0x528a;
  }
  *unaff_r4 = uVar7;
  if (unaff_r9 < 4) {
    sStack0000000a = (short)unaff_r9 * 0xc + 0x52;
  }
  else {
    sStack0000000a = 0x76;
  }
  sStack0000000e = sStack0000000a + 0x16;
  uVar8 = FUN_02fed6a6(DAT_03006c4c);
  in_stack_00000008 = unaff_r11;
  in_stack_0000000c = unaff_r10;
  if ((uVar8 < 0x134) && (0x9a < uVar8)) {
    uVar9 = (uVar8 >> 1) + 0xc;
    if (0x9a < uVar9) {
      uVar9 = 0x9a;
    }
    in_stack_00000008 = unaff_r11 + (short)((int)(0x9b - uVar9) / 2);
    in_stack_0000000c = (short)uVar9 + in_stack_00000008;
  }
  if (unaff_r9 < 4) {
    FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03006c4c,2);
  }
  FUN_02fee544(2);
  iVar10 = FUN_02ff2e44(1);
  if (iVar10 != 0) {
    FUN_02ff2de4(0x33);
  }
  iVar10 = FUN_02ff2e00(0x3b);
  piVar4 = DAT_03006c58;
  piVar3 = DAT_03006c54;
  piVar2 = DAT_03006c50;
  if (iVar10 == 0) {
LAB_03006bc8:
    piVar5 = DAT_03006c5c;
    iVar10 = *piVar2;
    bVar12 = iVar10 != 1;
    if (!bVar12) {
      iVar10 = *piVar3;
    }
    if (bVar12 || iVar10 != 0) goto LAB_03006cd2;
    if (*piVar4 == 0) {
      if (*DAT_03006c5c == 0) {
        iVar10 = 0xff;
      }
      else {
        iVar10 = FUN_0300b832();
        FUN_02ff2de4(0x11c);
      }
      iVar11 = *piVar5 + 1;
      *piVar5 = iVar11;
      if (iVar11 == 1) {
        FUN_02fef2b2(0x15c,0x11,0x16);
      }
      FUN_02fefb54();
      if (iVar10 != 0) goto LAB_03006cd2;
    }
  }
  else {
    *DAT_03006c5c = unaff_r5;
    *piVar2 = unaff_r5;
    *piVar3 = unaff_r5;
    *piVar4 = unaff_r5;
    FUN_02ff2e26(0x11c);
    if (*(int *)(unaff_r7 + 0x44) != 0) {
      *piVar2 = unaff_r5;
LAB_03006bc2:
      FUN_02ff2de4(0x43);
      goto LAB_03006bc8;
    }
    FUN_03005968();
    if (*piVar2 != 1) goto LAB_03006bc2;
    if (*piVar3 == 1) goto LAB_03006cd2;
    if (*piVar3 != 0) goto LAB_03006bc2;
    if (*piVar4 == 0) {
      FUN_02ff2c88(0x1a);
      goto LAB_03006bc8;
    }
  }
  FUN_02ff2cd4(0x1a);
  pcVar1 = DAT_03007074;
  FUN_02fe3c0c((int)*DAT_03007074);
  pcVar1[0] = -1;
  puVar6 = DAT_03007078;
  pcVar1[1] = -1;
  pcVar1[2] = -1;
  pcVar1[3] = -1;
  func_0x02fde8f6(DAT_0300707c + (uint)*DAT_03007078 * 0x15e00,DAT_0300707c,0x15e00);
  func_0x02fde8f6(DAT_03007080 + (uint)*puVar6 * 0x4b00,DAT_03007080,0x4b00);
  *piVar3 = 1;
  *piVar4 = 1;
  FUN_02ff2e26(0x11c);
  *DAT_03007084 = unaff_r5;
LAB_03006cd2:
  iVar10 = FUN_02ff2e44(0x4a);
  if (iVar10 == 1) {
    in_stack_00000014 = FUN_02fee544(2);
    *unaff_r4 = *unaff_r8;
    FUN_02fee180(DAT_03007088);
    *unaff_r4 = unaff_r6;
  }
  iVar10 = FUN_02ff2e44(0xae);
  if (iVar10 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *unaff_r8;
    FUN_02fedc4e(DAT_0300708c,0);
    *unaff_r4 = unaff_r6;
  }
  iVar10 = FUN_02ff2e44(0xaf);
  if (iVar10 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *unaff_r8;
    FUN_02fedd96(DAT_03007090,0);
    *unaff_r4 = unaff_r6;
  }
  iVar10 = FUN_02ff2e44(0xb0);
  if (iVar10 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *unaff_r8;
    FUN_02fedede(DAT_03007094,0);
    *unaff_r4 = unaff_r6;
  }
  FUN_02fee568(in_stack_00000020);
  unaff_r4[1] = (short)in_stack_00000024;
  *unaff_r4 = (short)in_stack_00000028;
  FUN_02fee544(in_stack_00000014);
  return;
}


