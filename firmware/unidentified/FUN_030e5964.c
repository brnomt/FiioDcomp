/**
 * FUN_030e5964 @ 0x030e5964
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e5964(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if (0xfffffff < param_3) {
    param_3 = 0xffffffff;
  }
  iVar1 = param_3 * 8;
  iVar2 = iVar1 + 7 >> 3;
  if (-1 < iVar2 && -1 < iVar1) {
    *param_1 = param_2;
    param_1[1] = param_2 + iVar2;
    param_1[2] = 0;
    param_1[3] = iVar1;
    return 0;
  }
  return 0xffffffff;
}


