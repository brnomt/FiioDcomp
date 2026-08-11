/**
 * FUN_030ae50e @ 0x030ae50e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ae50e(int *param_1)

{
  int unaff_r4;
  
  if (param_1 != (int *)0x0) {
    unaff_r4 = *param_1;
  }
  if (param_1 != (int *)0x0 && unaff_r4 != 0) {
    FUN_030b1740(unaff_r4 + 0x3048,0x2000);
    FUN_030b1740(unaff_r4 + 0x5048,8);
    return 0;
  }
  return 0xfffffffe;
}


