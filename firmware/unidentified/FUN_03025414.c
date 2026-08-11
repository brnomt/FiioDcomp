/**
 * FUN_03025414 @ 0x03025414
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03025414(void)

{
  undefined4 uVar1;
  int unaff_r5;
  int unaff_r8;
  int unaff_r9;
  undefined4 *unaff_r11;
  char in_ZR;
  char in_stack_00000020;
  
  while (in_ZR == '\0') {
    FUN_02ffc9d6(&stack0x00000020,1);
    unaff_r5 = unaff_r5 + 1;
    in_ZR = in_stack_00000020 == '\0';
  }
  uVar1 = FUN_02ffce8c();
  *unaff_r11 = uVar1;
  unaff_r11[1] = unaff_r8 - unaff_r5;
  if (unaff_r9 < 0) {
    return -1;
  }
  return unaff_r9;
}


