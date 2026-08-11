/**
 * FUN_030e0430 @ 0x030e0430
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e0430(uint param_1)

{
  *(uint *)(DAT_030e04ac + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030e04ac + (param_1 >> 5) * 4);
  return;
}


