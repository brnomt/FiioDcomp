/**
 * FUN_030e6652 @ 0x030e6652
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e6652(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10 = param_4;
  buffered_fseek_ovl_0e64(*param_2,(param_1 - param_2[2]) * 4 + -4,1);
  param_2[2] = param_1;
  buffered_fread_ovl_0e65(&local_10,1,4,*param_2);
  return local_10;
}


