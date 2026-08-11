/**
 * FUN_030cb4dc @ 0x030cb4dc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030cb4dc(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  if (*param_1 == -1) {
    return;
  }
  (*(code *)param_1[0x25])();
  param_1[2] = param_3;
  param_1[3] = param_4;
  FUN_030c6c66(param_1[6]);
  return;
}


