/**
 * FUN_0303fc58 @ 0x0303fc58
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0303fc58(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int unaff_r4;
  char *unaff_r6;
  uint unaff_r7;
  int *unaff_r8;
  undefined1 *unaff_r9;
  uint *unaff_r10;
  uint *unaff_r11;
  bool bVar6;
  uint in_stack_00000000;
  
  FUN_0300fe2e(0,0,(int)*unaff_r6);
  if (*unaff_r8 == 7) {
    *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
    uVar4 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                         *(int *)(unaff_r4 + 0x38) + -1);
    *unaff_r11 = uVar4;
    *unaff_r9 = *(undefined1 *)(unaff_r4 + 0x5c);
    uVar5 = FUN_0300f34e(unaff_r4 + 0x14,*(undefined4 *)(unaff_r4 + 0x34),
                         *(int *)(unaff_r4 + 0x38) + -1);
    *unaff_r10 = uVar5;
    uVar4 = *unaff_r11;
    if (*unaff_r11 < 9) {
      uVar4 = uVar5;
    }
    in_stack_00000000 = unaff_r7;
    if (8 < uVar4) {
      return 0xffffffff;
    }
  }
  uVar2 = DAT_0303fe64;
  bVar6 = *(int *)(unaff_r4 + 0x44) == 0;
  sVar1 = 0;
  if (!bVar6) {
    sVar1 = *(short *)(unaff_r4 + 0xf2);
  }
  if ((bVar6 || sVar1 == 10) || sVar1 == 99) {
    FUN_0301198c(*(undefined4 *)(unaff_r4 + 0x34),*(int *)(unaff_r4 + 0x38) + -1);
  }
  else {
    FUN_0301ece0(DAT_0303fe64,
                 ((uint)*(ushort *)(unaff_r4 + 2) +
                 (uint)*(ushort *)(unaff_r4 + (uint)*(ushort *)(unaff_r4 + 0xf4) * 2 + 0x110)) * 2 +
                 *(int *)(unaff_r4 + 0xfc) * 0x200 + -2,2);
    in_stack_00000000 = in_stack_00000000 & 0xffff;
    FUN_0301ece0(uVar2,*(int *)(unaff_r4 + 0xf8) * 0x200 + in_stack_00000000 * 0x800 + 0x400,0x80,
                 DAT_0303fe68);
    iVar3 = DAT_0303fe6c;
    FUN_0301ece0(uVar2,*(int *)(unaff_r4 + 0xf8) * 0x200 + in_stack_00000000 * 0x800 + 0x500,0x100,
                 DAT_0303fe6c + 0x15e);
    FUN_0301ece0(uVar2,*(int *)(unaff_r4 + 0xf8) * 0x200 + in_stack_00000000 * 0x800 + 0x600,0x100,
                 iVar3 + 0x25c);
  }
  return 0;
}


