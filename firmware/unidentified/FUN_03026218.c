/**
 * FUN_03026218 @ 0x03026218
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026218(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_r5;
  int unaff_r6;
  undefined4 unaff_r7;
  int in_stack_00000010;
  
  if (param_1 == 0) {
    iVar3 = FUN_02ffcece();
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    unaff_r7 = 0;
  }
  else {
    FUN_02ffcece(in_stack_00000010 + -0x18,1);
    if (unaff_r5 + 1 < unaff_r6) {
      FUN_02ffce8c();
      uVar1 = FUN_02ffc9d6();
      if (uVar1 < 0x18) {
        return 0xffffffff;
      }
      uVar2 = FUN_02ff89ce();
      return uVar2;
    }
  }
  return unaff_r7;
}


