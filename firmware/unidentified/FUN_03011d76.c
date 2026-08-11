/**
 * FUN_03011d76 @ 0x03011d76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03011d76(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_r11;
  char in_ZR;
  undefined2 in_stack_00000008;
  
  if (in_ZR == '\0') {
    FUN_030110cc();
    uVar1 = 0x33;
  }
  else {
    in_stack_00000008 = param_2;
    FUN_03000162(10,&stack0x00000008);
    unaff_r11 = 1;
    uVar1 = 0x32;
  }
  FUN_02ffff38(uVar1);
  return unaff_r11;
}


