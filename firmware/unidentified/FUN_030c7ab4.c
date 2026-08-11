/**
 * FUN_030c7ab4 @ 0x030c7ab4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c7ab4(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = 0;
    memset_byte(DAT_030c7b9c,0,0x120);
    memset_byte(DAT_030c7ba0,0,0x3a);
    memset_byte(DAT_030c7ba4,0,8);
  }
  memset_byte(param_1,0,0x10);
  return;
}


