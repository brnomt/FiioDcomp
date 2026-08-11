/**
 * FUN_03005a00 @ 0x03005a00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03005a00(undefined4 param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  int *unaff_r8;
  int unaff_r9;
  
  iVar2 = FUN_02fe373e(param_1,*(undefined4 *)(unaff_r9 + 0x34));
  puVar3 = DAT_03005a78;
  *unaff_r8 = iVar2;
  if (iVar2 != -1) {
    iVar2 = FUN_0300af38(iVar2,DAT_03005a7c);
    if ((iVar2 == 0) ||
       (iVar2 = FUN_0300b548(*unaff_r8,*(undefined4 *)(unaff_r7 + 0x20)), psVar1 = DAT_03005e80,
       iVar2 == 0)) {
      *puVar3 = unaff_r6;
      FUN_02fe3c0c((int)(char)*unaff_r8);
      *unaff_r8 = unaff_r5;
      return;
    }
    *puVar3 = 1;
    puVar3 = DAT_03005e84;
    if ((*psVar1 < 0x3e9) && (*DAT_03005e88 < 0x3e9)) {
      FUN_02fef2b2(0x15c,0x11,0x16);
      FUN_02ff2c88(0x1a);
      FUN_0300b63c(*(undefined4 *)(unaff_r7 + 0x20));
      FUN_02ff2cd4(0x1a);
      FUN_02fe3c0c((int)(char)*unaff_r8);
      *unaff_r8 = unaff_r5;
      *puVar3 = 1;
      return;
    }
  }
  *puVar3 = unaff_r6;
  return;
}


