/**
 * FUN_030dc7d4 @ 0x030dc7d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dc7d4(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_030dcaf0;
  DAT_030dcaf0[10] = 1 << (param_1 & 0xff);
  piVar1[0xb] = 0;
  *piVar1 = 0x100 << (param_1 & 0xff);
  piVar1[1] = 0;
  return 0;
}


