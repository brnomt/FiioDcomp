/**
 * FUN_03007f4c @ 0x03007f4c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03007f4c(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_r5;
  short sStack00000001;
  
  sStack00000001 = *(short *)(unaff_r5 + 2);
  iVar1 = *(int *)(param_2 + 0x1c);
  if ((iVar1 == 2 || iVar1 == 0) || (iVar1 == 3 || iVar1 == 1)) {
    sStack00000001 = FUN_02fe6040(sStack00000001,*(undefined4 *)(unaff_r5 + 0x34),DAT_0300821c,3);
  }
  if (sStack00000001 == 0) {
    sStack00000001 = *(short *)(unaff_r5 + 2);
  }
  FUN_02ff300e(9);
  return 1;
}


