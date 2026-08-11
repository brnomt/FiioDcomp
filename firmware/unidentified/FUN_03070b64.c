/**
 * FUN_03070b64 @ 0x03070b64
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03070b64(uint *param_1,uint param_2)

{
  *param_1 = param_2 & 0xfffffffc;
  param_1[1] = (param_2 & 3) << 3;
  return;
}


