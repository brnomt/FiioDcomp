/**
 * FUN_030e5e80 @ 0x030e5e80
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e5e80(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  uVar1 = param_2 & 0xfffff | 0x100000;
  if (uVar2 < 0x3ff) {
    return;
  }
  if (uVar2 < 0x434) {
    FUN_030e5ef6(param_1,uVar1,-(uVar2 - 0x433));
    return;
  }
  FUN_030e5ed8(param_1,uVar1);
  return;
}


