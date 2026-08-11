/**
 * FUN_03028c9e @ 0x03028c9e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03028c9e(short *param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = (*param_1 + 4 >> 3) + 0x80;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  *param_2 = (short)iVar1;
  return;
}


