/**
 * FUN_030a3900 @ 0x030a3900
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a3900(uint param_1)

{
  *(uint *)(DAT_030a397c + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030a397c + (param_1 >> 5) * 4);
  return;
}


