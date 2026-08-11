/**
 * FUN_030176e8 @ 0x030176e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030176e8(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(DAT_03017ae4 + param_1);
  *(undefined1 *)(DAT_03017ae8 + 0x10) = uVar1;
  *DAT_03017aec = uVar1;
  *DAT_03017af0 = (char)param_1;
  return 0;
}


