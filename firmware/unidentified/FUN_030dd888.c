/**
 * FUN_030dd888 @ 0x030dd888
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dd888(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + 7 >> 3;
  if (-1 < iVar1 && -1 < param_3) {
    *param_1 = param_2;
    param_1[1] = param_2 + iVar1;
    param_1[2] = 0;
    param_1[3] = param_3;
    return 0;
  }
  return 0xffffffff;
}


