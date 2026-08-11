/**
 * FUN_0303fc78 @ 0x0303fc78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0303fc78(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_r4;
  uint uVar3;
  char in_ZR;
  ushort in_stack_00000000;
  
  uVar1 = DAT_0303fe64;
  if (in_ZR == '\0') {
    in_ZR = param_1 == 99;
  }
  if (in_ZR == '\0') {
    FUN_0301ece0(DAT_0303fe64,
                 ((uint)*(ushort *)(unaff_r4 + 2) +
                 (uint)*(ushort *)(unaff_r4 + (uint)*(ushort *)(unaff_r4 + 0xf4) * 2 + 0x110)) * 2 +
                 *(int *)(unaff_r4 + 0xfc) * 0x200 + -2,2);
    uVar3 = (uint)in_stack_00000000;
    FUN_0301ece0(uVar1,*(int *)(unaff_r4 + 0xf8) * 0x200 + uVar3 * 0x800 + 0x400,0x80,DAT_0303fe68);
    iVar2 = DAT_0303fe6c;
    FUN_0301ece0(uVar1,*(int *)(unaff_r4 + 0xf8) * 0x200 + uVar3 * 0x800 + 0x500,0x100,
                 DAT_0303fe6c + 0x15e);
    FUN_0301ece0(uVar1,*(int *)(unaff_r4 + 0xf8) * 0x200 + uVar3 * 0x800 + 0x600,0x100,iVar2 + 0x25c
                );
  }
  else {
    FUN_0301198c(*(undefined4 *)(unaff_r4 + 0x34),*(int *)(unaff_r4 + 0x38) + -1);
  }
  return 0;
}


