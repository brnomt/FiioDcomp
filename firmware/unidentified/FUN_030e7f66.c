/**
 * FUN_030e7f66 @ 0x030e7f66
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030e7f66(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_030e59c8();
  if (uVar1 < 9) {
    if (param_2 != 1) {
      iVar2 = FUN_030e581a(param_1,param_2);
      uVar1 = (uVar1 << (param_2 & 0xff)) - uVar1;
      if (iVar2 < 2) {
        FUN_030e584a(param_1,param_2 - 1);
      }
      else {
        uVar1 = (iVar2 + uVar1) - 1;
        FUN_030e584a(param_1,param_2);
      }
    }
  }
  else {
    uVar1 = FUN_030e58a0(param_1,param_3);
  }
  return uVar1;
}


