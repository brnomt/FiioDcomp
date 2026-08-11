/**
 * FUN_030e9468 @ 0x030e9468
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e9468(uint param_1)

{
  *(uint *)(DAT_030e94e4 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030e94e4 + (param_1 >> 5) * 4);
  return;
}


