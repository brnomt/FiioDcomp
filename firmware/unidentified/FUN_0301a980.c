/**
 * FUN_0301a980 @ 0x0301a980
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a980(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(short *)(DAT_0301ace0 + 4) != 4) {
    *(undefined2 *)(DAT_0301ace0 + 4) = 4;
    FUN_0301abb2(0x11c,0);
    FUN_0301b094();
    FUN_02ff7b3c(0x23);
    FUN_02ff7be6(0x23);
    FUN_030081b0(0x23);
    iVar2 = FUN_02ff4090();
    iVar1 = DAT_0301ace4;
    if ((iVar2 == 0) && (*(char *)(DAT_0301ace4 + 0xe) == '\x04')) {
      FUN_03008eb4(0x12f);
      *(undefined1 *)(iVar1 + 0xe) = 2;
      FUN_02ff8772();
      FUN_03007416();
    }
    else {
      FUN_03008d58(0x23);
      FUN_03009500(2,7);
      FUN_03008da4(0x23);
      if (param_1 != 0) {
        return 1;
      }
      FUN_0301abb2(0x122,1);
    }
  }
  return 0;
}


