/**
 * FUN_03087f6e @ 0x03087f6e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03087f6e(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined2 *param_5,
                 undefined2 *param_6)

{
  if (param_4 <= param_3) {
    *param_5 = 0;
    *param_6 = (short)param_4;
    return;
  }
  *param_5 = (short)((uint)(((param_4 - param_3) - (param_4 - param_3 >> 0x1f)) * 0x8000) >> 0x10);
  *param_6 = (short)((uint)(((param_4 + param_3) - (param_4 + param_3 >> 0x1f)) * 0x8000) >> 0x10);
  return;
}


