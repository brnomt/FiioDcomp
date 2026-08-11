/**
 * FUN_030842ba @ 0x030842ba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030842ba(uint *param_1)

{
  return *param_1 & 0xffffff | (uint)*(byte *)((int)param_1 + 3) << 0x18;
}


