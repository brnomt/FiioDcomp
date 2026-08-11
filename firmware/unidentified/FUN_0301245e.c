/**
 * FUN_0301245e @ 0x0301245e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301245e(undefined4 param_1,short *param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*DAT_03012614 == '\x03') {
    sVar1 = FUN_02ff3baa(param_2 + 6,param_1);
    param_2[1] = sVar1;
    sVar1 = FUN_02ff2676(param_2 + 6,param_3);
  }
  else {
    sVar1 = FUN_02ff3a22(*(undefined4 *)(param_2 + 4));
    param_2[1] = sVar1;
    sVar1 = FUN_02ff258c(*(undefined4 *)(param_2 + 4),param_3);
  }
  param_2[2] = sVar1;
  *param_2 = param_2[1] + param_2[2];
  return 0;
}


