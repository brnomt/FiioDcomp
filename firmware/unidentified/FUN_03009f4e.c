/**
 * FUN_03009f4e @ 0x03009f4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03009f4e(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_02ff0ea6();
  iVar2 = iVar1 - DAT_0300a154;
  if (iVar1 != DAT_0300a154) {
    if (iVar1 < DAT_0300a154) {
      if (iVar2 != -6 && iVar2 != -4) {
        return 0;
      }
    }
    else {
      if (iVar2 != 0x38) {
        iVar1 = iVar2 + -0x800;
      }
      if (iVar2 != 0x38 && iVar1 != 0x7f8) {
        return 0;
      }
    }
  }
  return 1;
}


