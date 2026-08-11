/**
 * FUN_030ed6f0 @ 0x030ed6f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ed6f0(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_030eda0c;
  DAT_030eda0c[10] = 1 << (param_1 & 0xff);
  piVar1[0xb] = 0;
  *piVar1 = 0x100 << (param_1 & 0xff);
  piVar1[1] = 0;
  return 0;
}


