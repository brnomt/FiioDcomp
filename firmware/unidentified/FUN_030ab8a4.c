/**
 * FUN_030ab8a4 @ 0x030ab8a4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ab8a4(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(DAT_030ab8fc + 0x24) / 3000) * param_1;
  if (0x7fffffff < uVar1) {
    do {
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
    return;
  }
  do {
    uVar1 = uVar1 - 1;
  } while (0 < (int)uVar1);
  return;
}


