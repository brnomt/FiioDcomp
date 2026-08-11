/**
 * FUN_030ed674 @ 0x030ed674
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ed674(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(DAT_030ed6cc + 0x24) / 3000) * param_1;
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


