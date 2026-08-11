/**
 * FUN_030cd468 @ 0x030cd468
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030cd468(uint param_1)

{
  *(uint *)(DAT_030cd4e4 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030cd4e4 + (param_1 >> 5) * 4);
  return;
}


