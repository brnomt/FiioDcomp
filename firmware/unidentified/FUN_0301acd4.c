/**
 * FUN_0301acd4 @ 0x0301acd4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301acd4(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_r4;
  undefined1 unaff_r5;
  
  *(undefined1 *)(param_2 + 2) = unaff_r5;
  iVar1 = FUN_0301abb2();
  if (iVar1 != 0) {
    *(undefined2 *)(unaff_r4 + 4) = 4;
    FUN_03008eb4(0x130);
    return 0;
  }
  return 1;
}


