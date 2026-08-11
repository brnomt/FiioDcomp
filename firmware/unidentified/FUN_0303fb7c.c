/**
 * FUN_0303fb7c @ 0x0303fb7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0303fb7c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            uint param_5)

{
  short sVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int unaff_r4;
  char *unaff_r6;
  uint unaff_r7;
  int *unaff_r8;
  undefined1 *unaff_r9;
  bool in_ZR;
  bool in_CY;
  bool bVar8;
  
  *param_2 = param_1;
  if (in_CY && !in_ZR) {
    return 0xffffffff;
  }
  if (*unaff_r8 == 9) {
    FUN_0301ea36(0x115);
    FUN_0300b044();
    FUN_0300fe2e(0,0,(int)*unaff_r6);
    if (*unaff_r8 == 9) {
      uVar6 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                           *(int *)(unaff_r4 + 0x38) + -1);
      *DAT_0303fe58 = uVar6;
      param_5 = unaff_r7;
      if (8 < uVar6) {
        return 0xffffffff;
      }
    }
  }
  puVar3 = DAT_0303fe60;
  puVar2 = DAT_0303fe5c;
  if (*unaff_r8 == 2) {
    FUN_0301ea36(0x115);
    FUN_0300b044();
    FUN_0300fe2e(0,0,(int)*unaff_r6);
    if (*unaff_r8 == 2) {
      *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
      uVar6 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                           *(int *)(unaff_r4 + 0x38) + -1);
      *puVar2 = uVar6;
      *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
      uVar7 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                           *(int *)(unaff_r4 + 0x38) + -1);
      *puVar3 = uVar7;
      uVar6 = *puVar2;
      if (*puVar2 < 9) {
        uVar6 = uVar7;
      }
      param_5 = unaff_r7;
      if (8 < uVar6) {
        return 0xffffffff;
      }
    }
  }
  if (*unaff_r8 == 7) {
    FUN_0301ea36(0x115);
    FUN_0300b044();
    FUN_0300fe2e(0,0,(int)*unaff_r6);
    if (*unaff_r8 == 7) {
      *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
      uVar6 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                           *(int *)(unaff_r4 + 0x38) + -1);
      *puVar2 = uVar6;
      *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
      uVar7 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                           *(int *)(unaff_r4 + 0x38) + -1);
      *puVar3 = uVar7;
      uVar6 = *puVar2;
      if (*puVar2 < 9) {
        uVar6 = uVar7;
      }
      param_5 = unaff_r7;
      if (8 < uVar6) {
        return 0xffffffff;
      }
    }
  }
  uVar4 = DAT_0303fe64;
  bVar8 = *(int *)(unaff_r4 + 0x44) == 0;
  sVar1 = 0;
  if (!bVar8) {
    sVar1 = *(short *)(unaff_r4 + 0xf2);
  }
  if ((bVar8 || sVar1 == 10) || sVar1 == 99) {
    FUN_0301198c(*(undefined4 *)(unaff_r4 + 0x34),*(int *)(unaff_r4 + 0x38) + -1);
  }
  else {
    FUN_0301ece0(DAT_0303fe64,
                 ((uint)*(ushort *)(unaff_r4 + 2) +
                 (uint)*(ushort *)(unaff_r4 + (uint)*(ushort *)(unaff_r4 + 0xf4) * 2 + 0x110)) * 2 +
                 *(int *)(unaff_r4 + 0xfc) * 0x200 + -2,2);
    param_5 = param_5 & 0xffff;
    FUN_0301ece0(uVar4,*(int *)(unaff_r4 + 0xf8) * 0x200 + param_5 * 0x800 + 0x400,0x80,DAT_0303fe68
                );
    iVar5 = DAT_0303fe6c;
    FUN_0301ece0(uVar4,*(int *)(unaff_r4 + 0xf8) * 0x200 + param_5 * 0x800 + 0x500,0x100,
                 DAT_0303fe6c + 0x15e);
    FUN_0301ece0(uVar4,*(int *)(unaff_r4 + 0xf8) * 0x200 + param_5 * 0x800 + 0x600,0x100,
                 iVar5 + 0x25c);
  }
  return 0;
}


