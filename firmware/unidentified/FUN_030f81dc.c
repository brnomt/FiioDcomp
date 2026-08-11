/**
 * FUN_030f81dc @ 0x030f81dc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f81dc(uint param_1)

{
  *(uint *)(DAT_030f8258 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030f8258 + (param_1 >> 5) * 4);
  return;
}


