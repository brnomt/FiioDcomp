/**
 * FUN_030259d4 @ 0x030259d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030259d4(char param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [4];
  byte local_1c;
  byte local_1b;
  
  iVar1 = FUN_02ffcece(10,0);
  if (iVar1 == 0) {
    iVar1 = FUN_02ffce8c((int)param_1);
    if (*DAT_03025da0 < iVar1) {
      return 0xffffffff;
    }
    uVar2 = FUN_02ffc9d6(auStack_20,6,(int)param_1);
    if ((5 < uVar2) &&
       (FUN_02ff8972(auStack_28,auStack_20,3), (uint)local_1b + (uint)local_1c * 0x100 != 0)) {
      uVar3 = FUN_02ff89ce(auStack_28,&DAT_03025da4,3);
      return uVar3;
    }
  }
  return 0xffffffff;
}


