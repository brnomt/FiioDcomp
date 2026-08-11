/**
 * FUN_0301b20c @ 0x0301b20c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301b20c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_r4;
  
  iVar1 = FUN_0301b848();
  uVar2 = FUN_02ff5cbe((int)((longlong)iVar1 * 1000),
                       (int)((ulonglong)((longlong)iVar1 * 1000) >> 0x20));
  *unaff_r4 = uVar2;
  return 1;
}


