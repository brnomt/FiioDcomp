/**
 * FUN_03022060 @ 0x03022060
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03022060(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  char *unaff_r10;
  int unaff_r11;
  bool bVar6;
  char cStack00000000;
  char cStack00000001;
  
  cVar1 = *unaff_r10;
  iVar5 = 0xff;
  FUN_02ffc9d6();
  if (cStack00000000 == -1) {
    if (cStack00000001 == -0x28) {
      *(undefined1 *)(unaff_r11 + 0x1c) = 0x4a;
      *(undefined1 *)(unaff_r11 + 0x1d) = 0x50;
      *(undefined1 *)(unaff_r11 + 0x1e) = 0x47;
      iVar5 = 1;
    }
  }
  else {
    bVar6 = cStack00000000 == 'B';
    if (bVar6) {
      cStack00000000 = cStack00000001;
    }
    if (bVar6 && cStack00000000 == 'M') {
      *(undefined1 *)(unaff_r11 + 0x1c) = 0x42;
      *(undefined1 *)(unaff_r11 + 0x1d) = 0x4d;
      *(undefined1 *)(unaff_r11 + 0x1e) = 0x50;
      iVar5 = 3;
    }
  }
  FUN_02ffcece(0,0,(int)cVar1);
  if (unaff_r7 == 0xff) {
    if (iVar5 == 0xff) goto LAB_030220fc;
LAB_030220d2:
    unaff_r7 = iVar5;
    if (iVar5 != 1 && iVar5 != 2) goto joined_r0x030220dc;
LAB_0302210a:
    *DAT_03022114 = unaff_r8;
    uVar2 = 0x13;
  }
  else {
    if (iVar5 != 0xff) goto LAB_030220d2;
    if (unaff_r7 == 0xff) goto LAB_0302214e;
    if (unaff_r7 == 1 || unaff_r7 == 2) goto LAB_0302210a;
joined_r0x030220dc:
    if (unaff_r7 != 3) {
LAB_030220fc:
      FUN_0300ba94(0x168);
      return;
    }
    *DAT_03022114 = unaff_r9;
    uVar2 = 0x14;
  }
  FUN_0300c0e0(uVar2,7);
LAB_0302214e:
  FUN_03021c54();
  iVar3 = FUN_03021c74(0,*(undefined4 *)unaff_r10);
  iVar5 = DAT_030221d8;
  if (iVar3 != 0) {
    FUN_03021cec(DAT_030221d8 + 0x18);
    FUN_03021cd8(iVar5 + 0x10);
    uVar4 = *(uint *)(iVar5 + 0x10);
    if (1000 < uVar4) {
      uVar4 = *(uint *)(iVar5 + 0x14);
    }
    if (uVar4 < 0x3e9) {
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


