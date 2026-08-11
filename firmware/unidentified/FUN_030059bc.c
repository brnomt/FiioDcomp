/**
 * FUN_030059bc @ 0x030059bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030059bc(int param_1)

{
  char *pcVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_r5;
  undefined4 unaff_r6;
  int unaff_r7;
  int unaff_r9;
  undefined4 *unaff_r10;
  
  pcVar1 = DAT_03005a5c;
  if (param_1 != 0) {
    FUN_02fe3c0c((int)*DAT_03005a5c);
    *pcVar1 = (char)unaff_r5;
    *unaff_r10 = unaff_r6;
  }
  piVar2 = DAT_03005a60;
  if (*DAT_03005a60 != -1) {
    FUN_02fe3c0c((int)(char)*DAT_03005a60);
    *piVar2 = unaff_r5;
  }
  FUN_02fe75e6(&DAT_03005a70,s_PICTURE_OGG_03005a64);
  iVar4 = FUN_02fe373e(unaff_r9 + 0x14,*(undefined4 *)(unaff_r9 + 0x34),
                       *(int *)(unaff_r9 + 0x38) + -1);
  puVar5 = DAT_03005a78;
  *piVar2 = iVar4;
  if (iVar4 != -1) {
    iVar4 = FUN_0300af38(iVar4,DAT_03005a7c);
    if ((iVar4 == 0) ||
       (iVar4 = FUN_0300b548(*piVar2,*(undefined4 *)(unaff_r7 + 0x20)), psVar3 = DAT_03005e80,
       iVar4 == 0)) {
      *puVar5 = unaff_r6;
      FUN_02fe3c0c((int)(char)*piVar2);
      *piVar2 = unaff_r5;
      return;
    }
    *puVar5 = 1;
    puVar5 = DAT_03005e84;
    if ((*psVar3 < 0x3e9) && (*DAT_03005e88 < 0x3e9)) {
      FUN_02fef2b2(0x15c,0x11,0x16);
      FUN_02ff2c88(0x1a);
      FUN_0300b63c(*(undefined4 *)(unaff_r7 + 0x20));
      FUN_02ff2cd4(0x1a);
      FUN_02fe3c0c((int)(char)*piVar2);
      *piVar2 = unaff_r5;
      *puVar5 = 1;
      return;
    }
  }
  *puVar5 = unaff_r6;
  return;
}


