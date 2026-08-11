/**
 * FUN_030e7948 @ 0x030e7948
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7948(int param_1)

{
  int iVar1;
  
  FUN_030e422e(DAT_030e7a90,0,0x804);
  iVar1 = DAT_030e7a94;
  if (param_1 != -1) {
    *(undefined2 *)(DAT_030e7a94 + 0x4dc) = 0;
    *(undefined2 *)(iVar1 + 0x4de) = 0;
    *(int *)(iVar1 + 0x4e0) = param_1;
    buffered_fseek_ovl_0e64(iVar1 + 0x2dc,0,0);
    iVar1 = FUN_030e65cc(*DAT_030e7a9c,DAT_030e7a98);
    if ((-1 < iVar1) && (iVar1 = FUN_030e65cc(*DAT_030e7aa4,DAT_030e7aa0), -1 < iVar1)) {
      return 0;
    }
  }
  return 0xffffffff;
}


