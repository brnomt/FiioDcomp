/**
 * FUN_030f06ee @ 0x030f06ee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f06ee(undefined4 param_1,uint param_2,int param_3)

{
  if (param_3 != 1) {
    return;
  }
  if (param_2 != 0) {
    do {
      FUN_030f0588(param_1,8);
      param_2 = param_2 - 1 & 0xffff;
    } while (param_2 != 0);
    return;
  }
  return;
}


