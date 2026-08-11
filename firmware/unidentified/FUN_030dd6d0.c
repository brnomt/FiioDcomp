/**
 * FUN_030dd6d0 @ 0x030dd6d0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030dd6d0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  return uVar1 >> 0x18 | (uVar1 >> 0x10 & 0xff) << 8 | ((uVar1 & 0xffff) >> 8 | uVar1 << 8) << 0x10;
}


