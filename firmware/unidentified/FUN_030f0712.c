/**
 * FUN_030f0712 @ 0x030f0712
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f0712(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  
  if (param_3 == 0) {
    return;
  }
  do {
    param_3 = param_3 - 1 & 0xff;
    uVar1 = FUN_030f0588(param_1,8);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return;
}


