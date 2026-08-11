/**
 * FUN_03021ffe @ 0x03021ffe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03021ffe(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  int unaff_r11;
  bool bVar10;
  undefined *puStack00000000;
  
  puStack00000000 = &DAT_03022140;
  iVar3 = FUN_02ffc3ee(unaff_r11 + 0x14,*(undefined4 *)(unaff_r11 + 0x34),
                       *(int *)(unaff_r11 + 0x38) + -1,3);
  piVar1 = DAT_03022124;
  *DAT_03022124 = iVar3;
  pcVar6 = DAT_0302213c;
  if (iVar3 == -1) goto LAB_030220fc;
  uVar9 = 0xff;
  uVar7 = 0;
  bVar2 = FUN_02ff898a(DAT_0302213c);
  do {
    uVar7 = uVar7 + 3 & 0xff;
    if (((*(char *)(unaff_r11 + 0x1c) == *pcVar6) && (*(char *)(unaff_r11 + 0x1d) == pcVar6[1])) &&
       (*(char *)(unaff_r11 + 0x1e) == pcVar6[2])) break;
    pcVar6 = pcVar6 + 3;
  } while (uVar7 <= bVar2);
  if (uVar7 <= bVar2) {
    uVar9 = uVar7 / 3;
  }
  iVar3 = *piVar1;
  uVar8 = 0xff;
  FUN_02ffc9d6();
  uVar7 = (uint)puStack00000000 & 0xff;
  if (uVar7 == 0xff) {
    if (puStack00000000._1_1_ == 0xd8) {
      *(undefined1 *)(unaff_r11 + 0x1c) = 0x4a;
      *(undefined1 *)(unaff_r11 + 0x1d) = 0x50;
      *(undefined1 *)(unaff_r11 + 0x1e) = 0x47;
      uVar8 = 1;
    }
  }
  else {
    bVar10 = uVar7 == 0x42;
    if (bVar10) {
      uVar7 = (uint)puStack00000000._1_1_;
    }
    if (bVar10 && uVar7 == 0x4d) {
      *(undefined1 *)(unaff_r11 + 0x1c) = 0x42;
      *(undefined1 *)(unaff_r11 + 0x1d) = 0x4d;
      *(undefined1 *)(unaff_r11 + 0x1e) = 0x50;
      uVar8 = 3;
    }
  }
  FUN_02ffcece(0,0,(int)(char)iVar3);
  if (uVar9 == 0xff) {
    if (uVar8 == 0xff) goto LAB_030220fc;
LAB_030220d2:
    uVar9 = uVar8;
    if (uVar8 != 1 && uVar8 != 2) goto joined_r0x030220dc;
LAB_0302210a:
    *DAT_03022114 = unaff_r8;
    uVar4 = 0x13;
  }
  else {
    if (uVar8 != 0xff) goto LAB_030220d2;
    if (uVar9 == 0xff) goto LAB_0302214e;
    if (uVar9 == 1 || uVar9 == 2) goto LAB_0302210a;
joined_r0x030220dc:
    if (uVar9 != 3) {
LAB_030220fc:
      FUN_0300ba94(0x168);
      return;
    }
    *DAT_03022114 = unaff_r9;
    uVar4 = 0x14;
  }
  FUN_0300c0e0(uVar4,7);
LAB_0302214e:
  FUN_03021c54();
  iVar5 = FUN_03021c74(0,*piVar1);
  iVar3 = DAT_030221d8;
  if (iVar5 != 0) {
    FUN_03021cec(DAT_030221d8 + 0x18);
    FUN_03021cd8(iVar3 + 0x10);
    uVar9 = *(uint *)(iVar3 + 0x10);
    if (1000 < uVar9) {
      uVar9 = *(uint *)(iVar3 + 0x14);
    }
    if (uVar9 < 0x3e9) {
      func_0x0300875a();
    }
    else {
      func_0x0300875a();
      FUN_030087e4();
      FUN_03008804();
    }
    FUN_030087ec();
    FUN_03021cc4(iVar3 + 0xc);
    FUN_03007222(*(int *)(iVar3 + 0xc) != *(int *)(DAT_030221dc + 8));
    FUN_0300ba94(0x169);
    *DAT_030221e0 = (short)unaff_r8;
    return;
  }
  FUN_0300ba94(0x16a);
  return;
}


