/**
 * FUN_0308c590 @ 0x0308c590
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308c590(int *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0308c8e8;
  wma_memclr(DAT_0308c8e8,0x1c0);
  *(undefined1 *)(iVar1 + 0xf0) = 1;
  *param_1 = iVar1;
  return 0;
}


