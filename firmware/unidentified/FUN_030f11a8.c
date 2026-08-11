/**
 * FUN_030f11a8 @ 0x030f11a8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f11a8(uint param_1)

{
  *(uint *)(DAT_030f1224 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030f1224 + (param_1 >> 5) * 4);
  return;
}


