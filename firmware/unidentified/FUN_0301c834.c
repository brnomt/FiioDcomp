/**
 * FUN_0301c834 @ 0x0301c834
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301c834(uint *param_1,uint param_2)

{
  *param_1 = param_2 & 0xfffffffc;
  param_1[1] = (param_2 & 3) << 3;
  return;
}


