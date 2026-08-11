/**
 * FUN_0308392c @ 0x0308392c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308392c(uint param_1)

{
  *(uint *)(DAT_030839a8 + (param_1 >> 5) * 4) =
       1 << (param_1 & 0x1f) | *(uint *)(DAT_030839a8 + (param_1 >> 5) * 4);
  return;
}


