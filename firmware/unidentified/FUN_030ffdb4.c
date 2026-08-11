/**
 * FUN_030ffdb4 @ 0x030ffdb4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ffdb4(uint param_1)

{
  *(uint *)(DAT_030ffe30 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030ffe30 + (param_1 >> 5) * 4);
  return;
}


