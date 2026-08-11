/**
 * FUN_030ee4c8 @ 0x030ee4c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ee4c8(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x10000;
  }
  else {
    iVar1 = 0x10001;
  }
  *(int *)(DAT_030ee4f0 + (param_1 >> 4) * 4 + 0xc0) = iVar1 << (param_1 & 0xf);
  hifi_busy_delay_ovl_0ed6(5);
  return;
}


