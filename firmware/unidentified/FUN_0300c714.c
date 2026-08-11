/**
 * FUN_0300c714 @ 0x0300c714
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300c714(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_r4;
  int unaff_r5;
  undefined1 unaff_r6;
  
  FUN_02fed62c(*(undefined4 *)(unaff_r5 + 0x34),param_2,3);
  *(undefined4 *)(unaff_r4 + 0x76) = *(undefined4 *)(unaff_r5 + 0x14);
  *(undefined4 *)(unaff_r4 + 0x7a) = *(undefined4 *)(unaff_r5 + 0x18);
  *(undefined2 *)(unaff_r4 + 0x7e) = *(undefined2 *)(unaff_r5 + 0x1c);
  *(undefined1 *)(unaff_r4 + 0x80) = *(undefined1 *)(unaff_r5 + 0x1e);
  *(undefined1 *)(unaff_r4 + 0x81) = unaff_r6;
  iVar2 = FUN_0300ca34();
  if (iVar2 == 0) {
    uVar1 = FUN_02feafee(unaff_r5 + 0x14,*(undefined4 *)(unaff_r5 + 0x34),
                         *(int *)(unaff_r5 + 0x38) + -1,3);
    *DAT_0300c82c = uVar1;
    FUN_0300cd58();
  }
  FUN_02ffa694(0x135);
  FUN_02ffa694(0x13f);
  return;
}


