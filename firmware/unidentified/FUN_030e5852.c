/**
 * FUN_030e5852 @ 0x030e5852
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030e5852(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = param_1[2];
  bVar1 = *(byte *)(*param_1 + (uVar2 >> 3));
  param_1[2] = uVar2 + 1;
  return ((uint)bVar1 << (uVar2 & 7) & 0xff) >> 7;
}


