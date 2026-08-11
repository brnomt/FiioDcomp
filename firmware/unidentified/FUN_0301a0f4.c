/**
 * FUN_0301a0f4 @ 0x0301a0f4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301a0f4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined2 *unaff_r4;
  int unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  undefined2 *unaff_r8;
  bool bVar14;
  char cVar15;
  undefined1 *puVar16;
  longlong lVar17;
  
  func_0x03008eda(0x134);
  cVar15 = '\x01';
  FUN_03004626();
  FUN_0300614c();
  FUN_03006134();
  uVar13 = (uint)*DAT_0301a478;
  if (uVar13 == 0) {
    uVar13 = FUN_0300710a();
  }
  puVar1 = (undefined1 *)0x390;
  puVar2 = (undefined1 *)0x398;
  lVar17 = 8;
  puVar16 = (undefined1 *)register0x00000054;
  while( true ) {
    *puVar1 = *puVar16;
    puVar16 = puVar16 + 1;
    *puVar2 = *puVar16;
    puVar16 = puVar16 + 1;
    lVar17 = lVar17 + -1;
    if (lVar17 == 0) break;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  if (cVar15 == '\0') {
    FUN_02ff2de4(0x33);
  }
  iVar10 = FUN_02ff2e00(0x3b);
  piVar7 = DAT_03006c58;
  piVar6 = DAT_03006c54;
  piVar5 = DAT_03006c50;
  if (iVar10 == 0) {
LAB_03006bc8:
    piVar8 = DAT_03006c5c;
    iVar10 = *piVar5;
    bVar14 = iVar10 != 1;
    if (!bVar14) {
      iVar10 = *piVar6;
    }
    if (bVar14 || iVar10 != 0) goto LAB_03006cd2;
    if (*piVar7 == 0) {
      if (*DAT_03006c5c == 0) {
        iVar10 = 0xff;
      }
      else {
        iVar10 = FUN_0300b832();
        FUN_02ff2de4(0x11c);
      }
      iVar11 = *piVar8 + 1;
      *piVar8 = iVar11;
      if (iVar11 == 1) {
        FUN_02fef2b2(0x15c,0x11,0x16);
      }
      FUN_02fefb54();
      if (iVar10 != 0) goto LAB_03006cd2;
    }
  }
  else {
    *DAT_03006c5c = unaff_r5;
    *piVar5 = unaff_r5;
    *piVar6 = unaff_r5;
    *piVar7 = unaff_r5;
    FUN_02ff2e26(0x11c);
    if (*(int *)(unaff_r7 + 0x44) != 0) {
      *piVar5 = unaff_r5;
LAB_03006bc2:
      FUN_02ff2de4(0x43);
      goto LAB_03006bc8;
    }
    FUN_03005968();
    if (*piVar5 != 1) goto LAB_03006bc2;
    if (*piVar6 == 1) goto LAB_03006cd2;
    if (*piVar6 != 0) goto LAB_03006bc2;
    if (*piVar7 == 0) {
      FUN_02ff2c88(0x1a);
      goto LAB_03006bc8;
    }
  }
  FUN_02ff2cd4(0x1a);
  pcVar4 = DAT_03007074;
  FUN_02fe3c0c((int)*DAT_03007074);
  pcVar4[0] = -1;
  puVar9 = DAT_03007078;
  pcVar4[1] = -1;
  pcVar4[2] = -1;
  pcVar4[3] = -1;
  func_0x02fde8f6(DAT_0300707c + (uint)*DAT_03007078 * 0x15e00,DAT_0300707c,0x15e00);
  func_0x02fde8f6(DAT_03007080 + (uint)*puVar9 * 0x4b00,DAT_03007080,0x4b00);
  *piVar6 = 1;
  *piVar7 = 1;
  FUN_02ff2e26(0x11c);
  *DAT_03007084 = unaff_r5;
LAB_03006cd2:
  iVar10 = FUN_02ff2e44(0x4a);
  uVar3 = (undefined2)unaff_r6;
  if (iVar10 == 1) {
    uVar12 = FUN_02fee544(2);
    *(undefined4 *)((int)register0x00000054 + uVar13 + 0x14) = uVar12;
    *unaff_r4 = *unaff_r8;
    FUN_02fee180(DAT_03007088);
    *unaff_r4 = uVar3;
  }
  iVar10 = FUN_02ff2e44(0xae);
  if (iVar10 == 1) {
    uVar12 = FUN_02fee544();
    *(undefined4 *)((int)register0x00000054 + uVar13 + 0x14) = uVar12;
    *unaff_r4 = *unaff_r8;
    FUN_02fedc4e(DAT_0300708c,0);
    *unaff_r4 = uVar3;
  }
  iVar10 = FUN_02ff2e44(0xaf);
  if (iVar10 == 1) {
    uVar12 = FUN_02fee544();
    *(undefined4 *)((int)register0x00000054 + uVar13 + 0x14) = uVar12;
    *unaff_r4 = *unaff_r8;
    FUN_02fedd96(DAT_03007090,0);
    *unaff_r4 = uVar3;
  }
  iVar10 = FUN_02ff2e44(0xb0);
  if (iVar10 == 1) {
    uVar12 = FUN_02fee544();
    *(undefined4 *)((int)register0x00000054 + uVar13 + 0x14) = uVar12;
    *unaff_r4 = *unaff_r8;
    FUN_02fedede(DAT_03007094,0);
    *unaff_r4 = uVar3;
  }
  FUN_02fee568(*(undefined4 *)((int)register0x00000054 + uVar13 + 0x20));
  unaff_r4[1] = (short)*(undefined4 *)((int)register0x00000054 + uVar13 + 0x24);
  *unaff_r4 = (short)*(undefined4 *)((int)register0x00000054 + uVar13 + 0x28);
  FUN_02fee544(*(undefined4 *)((int)register0x00000054 + uVar13 + 0x14));
  return;
}


