/**
 * FUN_030c6da4 @ 0x030c6da4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c6da4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    do {
      iVar3 = *(int *)(param_1 + 8);
      if (param_2 < *(int *)(param_1 + 8)) {
        iVar3 = param_2;
      }
      iVar1 = 0;
      if (0 < iVar3) {
        for (iVar2 = iVar3 >> 1; iVar1 = iVar3, iVar2 != 0; iVar2 = iVar2 + -1) {
        }
      }
      param_1 = *(int *)(param_1 + 0xc);
      param_2 = param_2 - iVar1;
    } while (param_1 != 0);
    return;
  }
  return;
}


