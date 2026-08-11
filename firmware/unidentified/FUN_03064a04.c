/**
 * FUN_03064a04 @ 0x03064a04
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03064a04(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 2000;
  if (*(int *)(DAT_03064cb0 + 0x20) == 0) {
    *(undefined4 *)(DAT_03064cb0 + 0x20) = 1;
    iVar1 = thunk_FUN_03028000(5);
    while (iVar1 == 1) {
      FUN_030376b8(1);
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      iVar1 = thunk_FUN_03028000(5);
    }
    iVar2 = 2000;
    iVar1 = thunk_FUN_03028000(4);
    while (iVar1 == 1) {
      FUN_030376b8(1);
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      iVar1 = thunk_FUN_03028000(4);
    }
    FUN_03022354(0,6);
    func_0x030245e8(3,1);
    FUN_0303328c(0);
    FUN_0303328c(2);
  }
  return 1;
}


