/**
 * FUN_030e57da @ 0x030e57da
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030e57da(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[2];
  uVar1 = *(uint *)(*param_1 + ((int)uVar2 >> 3));
  param_1[2] = param_2 + uVar2;
  return ((uVar1 >> 0x18 | (uVar1 >> 0x10 & 0xff) << 8 |
          ((uVar1 & 0xffff) >> 8 | uVar1 << 8) << 0x10) << (uVar2 & 7)) >> (0x20U - param_2 & 0xff);
}


