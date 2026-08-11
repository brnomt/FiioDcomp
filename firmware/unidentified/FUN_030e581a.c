/**
 * FUN_030e581a @ 0x030e581a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030e581a(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*param_1 + (param_1[2] >> 3));
  return ((uVar1 >> 0x18 | (uVar1 >> 0x10 & 0xff) << 8 |
          ((uVar1 & 0xffff) >> 8 | uVar1 << 8) << 0x10) << (param_1[2] & 7U)) >>
         (0x20U - param_2 & 0xff);
}


