/**
 * FUN_03021f84 @ 0x03021f84
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03021f84(void)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined4 uStack_30;
  
  *DAT_03022118 = 0;
  *DAT_03022138 = 0;
  uStack_30 = DAT_0302213c;
  sVar3 = FUN_03000a74(DAT_03022130,*(undefined2 *)(DAT_0302211c + 0x221),3,0);
  iVar6 = DAT_03022130;
  iVar4 = DAT_03022120;
  if (sVar3 == -1) {
    FUN_0300ba94(0x167);
    return;
  }
  FUN_02ff8972(DAT_03022120 + 0x20,DAT_03022130 + 0x9a,0x66);
  *(undefined4 *)(iVar4 + 0x86) = *(undefined4 *)(iVar6 + 0x14);
  *(undefined4 *)(iVar4 + 0x8a) = *(undefined4 *)(iVar6 + 0x18);
  *(undefined2 *)(iVar4 + 0x8e) = *(undefined2 *)(iVar6 + 0x1c);
  *(undefined1 *)(iVar4 + 0x90) = *(undefined1 *)(iVar6 + 0x1e);
  *(undefined1 *)(iVar4 + 0x91) = 0;
  uStack_30 = &DAT_03022140;
  iVar4 = FUN_02ffc3ee(iVar6 + 0x14,*(undefined4 *)(iVar6 + 0x34),*(int *)(iVar6 + 0x38) + -1,3);
  piVar1 = DAT_03022124;
  *DAT_03022124 = iVar4;
  pcVar7 = DAT_0302213c;
  if (iVar4 == -1) goto LAB_030220fc;
  uVar10 = 0xff;
  uVar8 = 0;
  bVar2 = FUN_02ff898a(DAT_0302213c);
  do {
    uVar8 = uVar8 + 3 & 0xff;
    if (((*(char *)(iVar6 + 0x1c) == *pcVar7) && (*(char *)(iVar6 + 0x1d) == pcVar7[1])) &&
       (*(char *)(iVar6 + 0x1e) == pcVar7[2])) break;
    pcVar7 = pcVar7 + 3;
  } while (uVar8 <= bVar2);
  if (uVar8 <= bVar2) {
    uVar10 = uVar8 / 3;
  }
  iVar4 = *piVar1;
  uVar9 = 0xff;
  FUN_02ffc9d6(&uStack_30,10);
  uVar8 = (uint)uStack_30 & 0xff;
  if (uVar8 == 0xff) {
    if (uStack_30._1_1_ == 0xd8) {
      *(undefined1 *)(iVar6 + 0x1c) = 0x4a;
      *(undefined1 *)(iVar6 + 0x1d) = 0x50;
      *(undefined1 *)(iVar6 + 0x1e) = 0x47;
      uVar9 = 1;
    }
  }
  else {
    bVar11 = uVar8 == 0x42;
    if (bVar11) {
      uVar8 = (uint)uStack_30._1_1_;
    }
    if (bVar11 && uVar8 == 0x4d) {
      *(undefined1 *)(iVar6 + 0x1c) = 0x42;
      *(undefined1 *)(iVar6 + 0x1d) = 0x4d;
      *(undefined1 *)(iVar6 + 0x1e) = 0x50;
      uVar9 = 3;
    }
  }
  FUN_02ffcece(0,0,(int)(char)iVar4);
  if (uVar10 == 0xff) {
    if (uVar9 == 0xff) goto LAB_030220fc;
LAB_030220d2:
    uVar10 = uVar9;
    if (uVar9 != 1 && uVar9 != 2) goto joined_r0x030220dc;
LAB_0302210a:
    *DAT_03022114 = 0;
    uVar5 = 0x13;
  }
  else {
    if (uVar9 != 0xff) goto LAB_030220d2;
    if (uVar10 == 0xff) goto LAB_0302214e;
    if (uVar10 == 1 || uVar10 == 2) goto LAB_0302210a;
joined_r0x030220dc:
    if (uVar10 != 3) {
LAB_030220fc:
      FUN_0300ba94(0x168);
      return;
    }
    *DAT_03022114 = 1;
    uVar5 = 0x14;
  }
  FUN_0300c0e0(uVar5,7);
LAB_0302214e:
  FUN_03021c54();
  iVar6 = FUN_03021c74(0,*piVar1);
  iVar4 = DAT_030221d8;
  if (iVar6 == 0) {
    FUN_0300ba94(0x16a);
    return;
  }
  FUN_03021cec(DAT_030221d8 + 0x18);
  FUN_03021cd8(iVar4 + 0x10);
  uVar10 = *(uint *)(iVar4 + 0x10);
  if (1000 < uVar10) {
    uVar10 = *(uint *)(iVar4 + 0x14);
  }
  if (uVar10 < 0x3e9) {
    func_0x0300875a();
  }
  else {
    func_0x0300875a();
    FUN_030087e4();
    FUN_03008804();
  }
  FUN_030087ec();
  FUN_03021cc4(iVar4 + 0xc);
  FUN_03007222(*(int *)(iVar4 + 0xc) != *(int *)(DAT_030221dc + 8));
  FUN_0300ba94(0x169);
  *DAT_030221e0 = 0;
  return;
}


