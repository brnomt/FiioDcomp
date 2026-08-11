/**
 * FUN_030c68e6 @ 0x030c68e6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c68e6(undefined4 *param_1,int *param_2)

{
  memset_byte(param_1,0,0x14);
  if (param_2 != (int *)0x0) {
    *param_1 = param_2;
    param_1[1] = param_2;
    param_1[3] = 0;
    param_1[4] = param_2[2];
    param_1[2] = *param_2 + param_2[1];
    return 0;
  }
  return 0xffffffff;
}


