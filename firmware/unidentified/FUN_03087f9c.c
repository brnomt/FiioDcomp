/**
 * FUN_03087f9c @ 0x03087f9c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03087f9c(undefined4 param_1,undefined4 param_2,int param_3,int param_4,short param_5,
                 short *param_6,short *param_7)

{
  if (param_4 < param_3) {
    *param_6 = param_5 + (short)((param_3 - param_4) / 2);
    param_5 = param_5 + (short)((param_3 + param_4) / 2);
  }
  else {
    *param_6 = param_5;
    param_5 = param_5 << 1;
  }
  *param_7 = param_5;
  return;
}


