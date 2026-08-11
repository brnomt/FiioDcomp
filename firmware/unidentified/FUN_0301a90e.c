/**
 * FUN_0301a90e @ 0x0301a90e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a90e(void)

{
  int iVar1;
  
  iVar1 = DAT_0301ace0;
  if (*(short *)(DAT_0301ace0 + 4) == 4) {
    return 1;
  }
  if (*(short *)(DAT_0301ace0 + 4) != 2) {
    FUN_03001e04(0);
    *(undefined2 *)(iVar1 + 4) = 2;
  }
  iVar1 = thunk_FUN_0301da82(0x4b,0xffffffff);
  if (iVar1 == 0) {
    FUN_0301ddf2(0);
    FUN_0301dd4e();
    return 1;
  }
  return 0;
}


