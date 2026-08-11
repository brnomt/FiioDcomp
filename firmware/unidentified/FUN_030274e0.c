/**
 * FUN_030274e0 @ 0x030274e0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030274e0(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (*(int *)(DAT_03027874 + 0x34) <= iVar1) {
      return 0;
    }
    if (DAT_03027878 + -0x20c +
        *(int *)(DAT_03027878 + -0xc + *(int *)(DAT_03027878 + iVar1 * 4) * 4) * 0x80 == 0) break;
    iVar1 = iVar1 + 1;
  }
  return 0xffffff22;
}


