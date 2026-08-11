/**
 * FUN_030b5418 @ 0x030b5418
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b5418(uint param_1)

{
  *(uint *)(DAT_030b5494 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030b5494 + (param_1 >> 5) * 4);
  return;
}


