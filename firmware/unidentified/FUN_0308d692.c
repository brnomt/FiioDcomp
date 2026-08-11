/**
 * FUN_0308d692 @ 0x0308d692
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308d692(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  uVar3 = param_1[1];
  uVar1 = uVar2 + param_2;
  wma_input_cache_read(param_1);
  *param_1 = uVar1 - 0x18;
  param_1[1] = uVar3 + CARRY4(uVar2,param_2) + -1 + (uint)(0x17 < uVar1);
  return 0;
}


