/**
 * FUN_030e48c6 @ 0x030e48c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e48c6(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_030e4bc4;
  DAT_030e4bc4[10] = 1 << (param_1 & 0xff);
  piVar1[0xb] = 0;
  *piVar1 = 0x101 << (param_1 & 0xff);
  piVar1[1] = 0;
  return 0;
}


