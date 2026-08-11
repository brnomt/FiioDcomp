/**
 * FUN_030eeb28 @ 0x030eeb28
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030eeb28(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (int)param_2 >> 0x1f;
  FUN_030eec4a((param_1 ^ uVar1) + -uVar1,(param_2 ^ uVar1) + (uint)CARRY4(param_1 ^ uVar1,-uVar1),0
               ,0,0,uVar1 * -0x80000000,0x433);
  return;
}


