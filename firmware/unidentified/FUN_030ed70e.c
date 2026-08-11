/**
 * FUN_030ed70e @ 0x030ed70e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ed70e(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_030eda0c;
  DAT_030eda0c[10] = 1 << (param_1 & 0xff);
  piVar1[0xb] = 0;
  *piVar1 = 0x101 << (param_1 & 0xff);
  piVar1[1] = 0;
  return 0;
}


