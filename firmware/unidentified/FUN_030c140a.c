/**
 * FUN_030c140a @ 0x030c140a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


ulonglong FUN_030c140a(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}


