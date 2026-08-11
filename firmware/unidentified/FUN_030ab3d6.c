/**
 * FUN_030ab3d6 @ 0x030ab3d6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ab3d6(undefined1 *param_1,undefined1 param_2,uint param_3)

{
  undefined1 *puVar1;
  
  if (param_3 == 0) {
    return;
  }
  puVar1 = param_1 + -1;
  if ((param_3 & 1) != 0) {
    *param_1 = param_2;
    puVar1 = param_1;
  }
  param_3 = param_3 >> 1;
  if (param_3 == 0) {
    return;
  }
  do {
    puVar1[1] = param_2;
    puVar1 = puVar1 + 2;
    *puVar1 = param_2;
    param_3 = param_3 - 1;
  } while (param_3 != 0);
  return;
}


