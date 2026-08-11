/**
 * FUN_030a5f34 @ 0x030a5f34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030a5f34(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 << 0x12 < 0) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(0x20,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


