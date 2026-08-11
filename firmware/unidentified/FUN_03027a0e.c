/**
 * FUN_03027a0e @ 0x03027a0e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03027a0e(void)

{
  int iVar1;
  int iVar2;
  int unaff_r6;
  
  iVar2 = 0x600;
  while (iVar1 = FUN_0302754a(), iVar1 != 0xff) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) goto LAB_03027a3c;
  }
  if (iVar2 == 0) {
    return 0xffffff1c;
  }
  while ((0 < iVar2 && (unaff_r6 = FUN_0302754a(), unaff_r6 == 0xff))) {
    iVar2 = iVar2 + -1;
  }
LAB_03027a3c:
  iVar1 = DAT_03027e38;
  if ((iVar2 != 0) && (unaff_r6 == *(int *)(DAT_03027e38 + 0x68) + 0xd0)) {
    FUN_02ff8a10(DAT_03027e3c,*(int *)(DAT_03027e38 + 0x30) << 2);
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(iVar1 + 0x60);
    *(uint *)(iVar1 + 0x68) = *(byte *)(iVar1 + 0x68) + 1 & 7;
    *(undefined4 *)(iVar1 + 0x58) = 0x10;
    FUN_03027592();
    FUN_03027592(0x10);
    return 0;
  }
  return 0xffffff1c;
}


