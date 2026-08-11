/**
 * FUN_030a2e06 @ 0x030a2e06
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a2e06(int *param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = param_1[0x6c1];
  if (iVar1 < 1) {
    return;
  }
  piVar2 = param_1 + 0x480;
  piVar3 = param_1 + 0x5a0;
  piVar4 = param_1 + 0x240;
  do {
    iVar1 = iVar1 + -1;
    *param_3 = (short)((uint)(((int)*(short *)(param_2 + *piVar4 * 2) * (int)(short)*piVar3 +
                               (int)(short)*piVar2 * (int)*(short *)(param_2 + *param_1 * 2) +
                              0x4000) * 2) >> 0x10);
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
    piVar2 = (int *)((int)piVar2 + 2);
    piVar3 = (int *)((int)piVar3 + 2);
    piVar4 = piVar4 + 1;
  } while (iVar1 != 0);
  return;
}


