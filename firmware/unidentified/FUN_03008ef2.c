/**
 * FUN_03008ef2 @ 0x03008ef2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03008ef2(void)

{
  int iVar1;
  
  iVar1 = FUN_02ff73d0(0xa7);
  if (iVar1 == 1) {
    *DAT_03009030 = 3;
    FUN_03008d76();
  }
  iVar1 = FUN_02ff73d0(0xa8);
  if (iVar1 == 1) {
    FUN_03008d76(*(undefined1 *)(DAT_03009068 + 0x217));
  }
  iVar1 = FUN_02ff73d0(0xa9);
  if ((iVar1 == 1) && (*(short *)(*DAT_03009048 + 10) == 3 || *(short *)(*DAT_03009048 + 10) == 0))
  {
    FUN_03008d76();
  }
  return 0;
}


