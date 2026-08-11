/**
 * FUN_03021d20 @ 0x03021d20
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03021d20(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1 || param_1 == 2) {
    *DAT_03022114 = 0;
    uVar1 = 0x13;
  }
  else {
    if (param_1 != 3) {
      return 0;
    }
    *DAT_03022114 = 1;
    uVar1 = 0x14;
  }
  FUN_0300c0e0(uVar1,7);
  return 1;
}


