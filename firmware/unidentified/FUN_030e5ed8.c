/**
 * FUN_030e5ed8 @ 0x030e5ed8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


longlong FUN_030e5ed8(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}


