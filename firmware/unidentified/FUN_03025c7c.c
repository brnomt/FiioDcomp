/**
 * FUN_03025c7c @ 0x03025c7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03025c7c(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_r6;
  int *unaff_r7;
  byte bStack0000000c;
  byte bStack0000000d;
  
  *(short *)(param_2 + 10) = (short)param_2;
  iVar3 = FUN_02ff89ce();
  if ((((((((((iVar3 != 0) && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
            (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
           ((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)))) &&
          (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
         (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
          ((iVar3 = FUN_02ff89ce(), iVar3 != 0 &&
           (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
            (iVar3 = FUN_02ff89ce(), iVar3 != 0)))))))) &&
        ((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)))) &&
       ((iVar3 = FUN_02ff89ce(), iVar3 != 0 &&
        (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
         ((iVar3 = FUN_02ff89ce(), iVar3 != 0 &&
          (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
           (iVar3 = FUN_02ff89ce(), iVar3 != 0)))))))))) &&
      (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
       (iVar3 = FUN_02ff89ce(), iVar3 != 0)))) &&
     (((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)) &&
      ((iVar3 = FUN_02ff89ce(), iVar3 != 0 && (iVar3 = FUN_02ff89ce(), iVar3 != 0)))))) {
    thunk_FUN_03011c1c(s______Check_PIC_Error______03026270);
    return 0xffffffff;
  }
  iVar3 = FUN_02ffcece();
  if (iVar3 == 0) {
    iVar3 = FUN_02ffce8c();
    if (*unaff_r7 < iVar3) {
      return unaff_r6;
    }
    uVar1 = FUN_02ffc9d6(&stack0x00000008,6);
    if ((5 < uVar1) && (FUN_02ff8972(), (uint)bStack0000000d + (uint)bStack0000000c * 0x100 != 0)) {
      uVar2 = FUN_02ff89ce();
      return uVar2;
    }
  }
  return 0xffffffff;
}


