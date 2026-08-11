/**
 * FUN_03007416 @ 0x03007416
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03007416(void)

{
  int iVar1;
  undefined2 *unaff_r4;
  undefined2 unaff_r6;
  undefined2 *unaff_r7;
  undefined4 in_stack_00000008;
  undefined4 in_stack_00000020;
  undefined2 in_stack_00000024;
  undefined2 in_stack_00000028;
  
  *unaff_r4 = *unaff_r7;
  FUN_02fee180(DAT_0300751c);
  *unaff_r4 = unaff_r6;
  iVar1 = FUN_02ff2e44(0xae);
  if (iVar1 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *unaff_r7;
    FUN_02fedc4e(DAT_03007520,1);
    *unaff_r4 = unaff_r6;
  }
  iVar1 = FUN_02ff2e44(0xaf);
  if (iVar1 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *unaff_r7;
    FUN_02fedd96(DAT_03007524,1);
    *unaff_r4 = unaff_r6;
  }
  iVar1 = FUN_02ff2e44(0xb0);
  if (iVar1 == 1) {
    in_stack_00000008 = FUN_02fee544();
    *unaff_r4 = *unaff_r7;
    FUN_02fedede(DAT_03007528,1);
    *unaff_r4 = unaff_r6;
  }
  FUN_02fee568(in_stack_00000020);
  unaff_r4[1] = in_stack_00000024;
  *unaff_r4 = in_stack_00000028;
  FUN_02fee544(in_stack_00000008);
  return;
}


