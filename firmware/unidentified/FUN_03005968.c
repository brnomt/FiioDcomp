/**
 * FUN_03005968 @ 0x03005968
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03005968(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  short *psVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  iVar5 = DAT_03005a40;
  iVar1 = DAT_03005a3c;
  *(undefined4 *)(DAT_03005a3c + 0x20) = 0xffffffff;
  if (*(short *)(iVar5 + 0xf2) == 10) {
    uVar6 = 1;
  }
  else if (*(short *)(iVar5 + 0xf2) == 8) {
    uVar6 = 2;
  }
  else {
    uVar6 = 3;
  }
  *DAT_03005a44 = 0x7e;
  *DAT_03005a48 = 0x7e;
  *DAT_03005a4c = 0x11;
  *DAT_03005a50 = 0x16;
  FUN_0300b78c(0);
  FUN_0300b786(1);
  piVar2 = DAT_03005a58;
  *DAT_03005a54 = 0;
  pcVar3 = DAT_03005a5c;
  if (*piVar2 != 0) {
    FUN_02fe3c0c((int)*DAT_03005a5c);
    *pcVar3 = -1;
    *piVar2 = 0;
  }
  piVar2 = DAT_03005a60;
  if (*DAT_03005a60 != -1) {
    FUN_02fe3c0c((int)(char)*DAT_03005a60);
    *piVar2 = -1;
  }
  FUN_02fe75e6(&DAT_03005a70,s_PICTURE_OGG_03005a64);
  iVar5 = FUN_02fe373e(iVar5 + 0x14,*(undefined4 *)(iVar5 + 0x34),*(int *)(iVar5 + 0x38) + -1,uVar6,
                       DAT_03005a74);
  puVar7 = DAT_03005a78;
  *piVar2 = iVar5;
  if (iVar5 != -1) {
    iVar5 = FUN_0300af38(iVar5,DAT_03005a7c);
    if ((iVar5 == 0) ||
       (iVar5 = FUN_0300b548(*piVar2,*(undefined4 *)(iVar1 + 0x20)), psVar4 = DAT_03005e80,
       iVar5 == 0)) {
      *puVar7 = 0;
      FUN_02fe3c0c((int)(char)*piVar2);
      *piVar2 = -1;
      return;
    }
    *puVar7 = 1;
    puVar7 = DAT_03005e84;
    if ((*psVar4 < 0x3e9) && (*DAT_03005e88 < 0x3e9)) {
      FUN_02fef2b2(0x15c,0x11,0x16);
      FUN_02ff2c88(0x1a);
      FUN_0300b63c(*(undefined4 *)(iVar1 + 0x20));
      FUN_02ff2cd4(0x1a);
      FUN_02fe3c0c((int)(char)*piVar2);
      *piVar2 = -1;
      *puVar7 = 1;
      return;
    }
  }
  *puVar7 = 0;
  return;
}


