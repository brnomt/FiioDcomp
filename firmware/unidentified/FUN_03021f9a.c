/**
 * FUN_03021f9a @ 0x03021f9a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03021f9a(int *param_1)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_r8;
  bool bVar12;
  char *pcStack00000000;
  
  *param_1 = unaff_r8;
  pcStack00000000 = DAT_0302213c;
  sVar3 = FUN_03000a74(DAT_03022130,*(undefined2 *)(DAT_0302211c + 0x221));
  iVar7 = DAT_03022130;
  iVar5 = DAT_03022120;
  iVar4 = unaff_r8;
  if (sVar3 != -1) {
    FUN_02ff8972(DAT_03022120 + 0x20,DAT_03022130 + 0x9a,0x66);
    *(undefined4 *)(iVar5 + 0x86) = *(undefined4 *)(iVar7 + 0x14);
    *(undefined4 *)(iVar5 + 0x8a) = *(undefined4 *)(iVar7 + 0x18);
    *(undefined2 *)(iVar5 + 0x8e) = *(undefined2 *)(iVar7 + 0x1c);
    *(undefined1 *)(iVar5 + 0x90) = *(undefined1 *)(iVar7 + 0x1e);
    *(char *)(iVar5 + 0x91) = (char)unaff_r8;
    iVar4 = 1;
  }
  if (iVar4 == 0) {
    FUN_0300ba94(0x167);
    return;
  }
  pcStack00000000 = &DAT_03022140;
  iVar5 = FUN_02ffc3ee(iVar7 + 0x14,*(undefined4 *)(iVar7 + 0x34),*(int *)(iVar7 + 0x38) + -1,3);
  piVar1 = DAT_03022124;
  *DAT_03022124 = iVar5;
  pcVar8 = DAT_0302213c;
  if (iVar5 == -1) goto LAB_030220fc;
  uVar11 = 0xff;
  uVar9 = 0;
  bVar2 = FUN_02ff898a(DAT_0302213c);
  do {
    uVar9 = uVar9 + 3 & 0xff;
    if (((*(char *)(iVar7 + 0x1c) == *pcVar8) && (*(char *)(iVar7 + 0x1d) == pcVar8[1])) &&
       (*(char *)(iVar7 + 0x1e) == pcVar8[2])) break;
    pcVar8 = pcVar8 + 3;
  } while (uVar9 <= bVar2);
  if (uVar9 <= bVar2) {
    uVar11 = uVar9 / 3;
  }
  iVar5 = *piVar1;
  uVar10 = 0xff;
  FUN_02ffc9d6();
  uVar9 = (uint)pcStack00000000 & 0xff;
  if (uVar9 == 0xff) {
    if (pcStack00000000._1_1_ == 0xd8) {
      *(undefined1 *)(iVar7 + 0x1c) = 0x4a;
      *(undefined1 *)(iVar7 + 0x1d) = 0x50;
      *(undefined1 *)(iVar7 + 0x1e) = 0x47;
      uVar10 = 1;
    }
  }
  else {
    bVar12 = uVar9 == 0x42;
    if (bVar12) {
      uVar9 = (uint)pcStack00000000._1_1_;
    }
    if (bVar12 && uVar9 == 0x4d) {
      *(undefined1 *)(iVar7 + 0x1c) = 0x42;
      *(undefined1 *)(iVar7 + 0x1d) = 0x4d;
      *(undefined1 *)(iVar7 + 0x1e) = 0x50;
      uVar10 = 3;
    }
  }
  FUN_02ffcece(0,0,(int)(char)iVar5);
  if (uVar11 == 0xff) {
    if (uVar10 == 0xff) goto LAB_030220fc;
LAB_030220d2:
    uVar11 = uVar10;
    if (uVar10 != 1 && uVar10 != 2) goto joined_r0x030220dc;
LAB_0302210a:
    *DAT_03022114 = unaff_r8;
    uVar6 = 0x13;
  }
  else {
    if (uVar10 != 0xff) goto LAB_030220d2;
    if (uVar11 == 0xff) goto LAB_0302214e;
    if (uVar11 == 1 || uVar11 == 2) goto LAB_0302210a;
joined_r0x030220dc:
    if (uVar11 != 3) {
LAB_030220fc:
      FUN_0300ba94(0x168);
      return;
    }
    *DAT_03022114 = 1;
    uVar6 = 0x14;
  }
  FUN_0300c0e0(uVar6,7);
LAB_0302214e:
  FUN_03021c54();
  iVar7 = FUN_03021c74(0,*piVar1);
  iVar5 = DAT_030221d8;
  if (iVar7 != 0) {
    FUN_03021cec(DAT_030221d8 + 0x18);
    FUN_03021cd8(iVar5 + 0x10);
    uVar11 = *(uint *)(iVar5 + 0x10);
    if (1000 < uVar11) {
      uVar11 = *(uint *)(iVar5 + 0x14);
    }
    if (uVar11 < 0x3e9) {
      func_0x0300875a();
    }
    else {
      func_0x0300875a();
      FUN_030087e4();
      FUN_03008804();
    }
    FUN_030087ec();
    FUN_03021cc4(iVar5 + 0xc);
    FUN_03007222(*(int *)(iVar5 + 0xc) != *(int *)(DAT_030221dc + 8));
    FUN_0300ba94(0x169);
    *DAT_030221e0 = (short)unaff_r8;
    return;
  }
  FUN_0300ba94(0x16a);
  return;
}


