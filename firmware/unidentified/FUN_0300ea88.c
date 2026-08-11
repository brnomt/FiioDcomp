/**
 * FUN_0300ea88 @ 0x0300ea88
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300ea88(void)

{
  int iVar1;
  
  FUN_02ff9b40();
  FUN_02ffc8e6(0x1c7);
  iVar1 = FUN_02feb930(*DAT_0300eb6c,DAT_0300eb68);
  if ((iVar1 == 1) && (*DAT_0300eb70 == 3)) {
    if (*(char *)(DAT_0300eb64 + 3) != '\0') {
      *(undefined1 *)(DAT_0300eb64 + 3) = 0;
      FUN_03019cec(0xee);
      FUN_02ffc8a4(0x2b);
    }
  }
  FUN_02ffc8e6(0x1cf);
  FUN_02ffc8e6(0x1d0);
  FUN_02ffc8e6(0x1c7);
  FUN_02ffc8e6(0x1c8);
  FUN_02ffc8e6(0x1c9);
  return;
}


