/**
 * FUN_030ee4a0 @ 0x030ee4a0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030ed628) */
/* WARNING: Removing unreachable block (ram,0x030ed62c) */

void FUN_030ee4a0(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x10001;
  }
  else {
    iVar1 = 0x10000;
  }
  *(int *)(DAT_030ee4f0 + (param_1 >> 4) * 4 + 0x80) = iVar1 << (param_1 & 0xf);
  iVar1 = 10;
  do {
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


