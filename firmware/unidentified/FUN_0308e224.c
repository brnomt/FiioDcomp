/**
 * FUN_0308e224 @ 0x0308e224
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308e224(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_03083faa(param_1 + 0xac,param_4);
  FUN_03083f5c(param_1 + 0xac,0x18,&local_28);
  FUN_0308fd1e(param_2,&local_18);
  *(undefined4 *)(param_2 + 0x80) = local_28;
  *(undefined4 *)(param_2 + 0x84) = local_24;
  *(undefined4 *)(param_2 + 0x88) = local_20;
  *(undefined4 *)(param_2 + 0x8c) = local_1c;
  return;
}


