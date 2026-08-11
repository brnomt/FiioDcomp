/**
 * thunk_FUN_03000e32 @ 0x03000eae
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

undefined4 thunk_FUN_03000e32(void)

{
  short sVar1;
  undefined4 unaff_r9;
  int unaff_r10;
  int unaff_r11;
  
  rom_hw_init2();
  *(char *)(unaff_r10 + 5) = *(char *)(unaff_r10 + 5) + '\x01';
  rom_hw_init2(399);
  rom_hw_init(0x154);
  sVar1 = *(short *)(unaff_r11 + (uint)*(byte *)(unaff_r10 + 5) * 6 + 4);
  if ((sVar1 == 0 || sVar1 == 10) || sVar1 == 6) {
    rom_hw_init2(0x16f);
  }
  else {
    rom_hw_init2(0x1dc);
    unaff_r9 = WriteData_To_Flash(*(undefined2 *)
                                   (unaff_r11 + (uint)*(byte *)(unaff_r10 + 5) * 6 + 4));
  }
  return unaff_r9;
}
