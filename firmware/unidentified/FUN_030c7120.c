/**
 * FUN_030c7120 @ 0x030c7120
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c7120(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_030c750c;
  memset_byte(DAT_030c750c,0,0x50);
  *(undefined4 *)(iVar1 + 0x18) = param_1;
  *(undefined4 *)(iVar1 + 0x1c) = 0xffffffff;
  return iVar1;
}


