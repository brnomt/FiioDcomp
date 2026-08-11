/**
 * FUN_0301dc9e @ 0x0301dc9e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301dc9e(void)

{
  int iVar1;
  undefined4 unaff_r4;
  int unaff_r6;
  int unaff_r7;
  
  ape_rom_seek_thunk();
  iVar1 = DAT_0301df68;
  *(undefined4 *)(DAT_0301df68 + 0x18) = 0x400;
  *(undefined4 *)(iVar1 + 0x1c) = 0x400;
  *(undefined4 *)(unaff_r7 + 0x14) = unaff_r4;
  *(undefined4 *)(unaff_r6 + 0x14) = unaff_r4;
  *(undefined4 *)(unaff_r7 + 0x20) = 0x400;
  *(undefined4 *)(unaff_r6 + 0x20) = 0x400;
  return 0;
}


