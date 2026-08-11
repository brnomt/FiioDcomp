/**
 * FUN_030acb16 @ 0x030acb16
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030acb16(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar1 < 0x3ff) {
    param_1 = 0;
  }
  else {
    if (uVar1 < 0x434) {
      param_1 = FUN_030acb9e(param_1,param_2 & 0xfffff | 0x100000,-(uVar1 - 0x433));
    }
    else {
      param_1 = param_1 << (uVar1 - 0x433 & 0xff);
    }
    if ((param_2 & 0x80000000) != 0) {
      return -param_1;
    }
  }
  return param_1;
}


