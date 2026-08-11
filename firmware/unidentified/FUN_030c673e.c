/**
 * FUN_030c673e @ 0x030c673e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c673e(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  do {
    iVar1 = *param_1;
    piVar4 = (int *)param_1[3];
    piVar3 = *(int **)(iVar1 + 0x408);
    iVar2 = *(int *)(iVar1 + 0x404) + -1;
    *(int *)(iVar1 + 0x404) = iVar2;
    if (iVar2 == 0) {
      piVar3[2] = piVar3[2] + -1;
      *(int *)(iVar1 + 0x408) = *piVar3;
      *piVar3 = iVar1;
    }
    piVar3[2] = piVar3[2] + -1;
    param_1[3] = piVar3[1];
    piVar3[1] = (int)param_1;
    if (piVar3[3] != 0) {
      iVar1 = *piVar3;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0x408);
        memset_byte(iVar1,0,0x400);
        iVar1 = iVar2;
      }
      *piVar3 = 0;
      for (; param_1 != (int *)0x0; param_1 = (int *)param_1[3]) {
      }
      piVar3[1] = 0;
      if (piVar3[2] == 0) {
        memset_byte(DAT_030c6b20,0,0x10);
      }
    }
    param_1 = piVar4;
  } while (piVar4 != (int *)0x0);
  return;
}


