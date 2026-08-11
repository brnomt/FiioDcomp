/**
 * FUN_030c662c @ 0x030c662c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030c662c(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)*param_1;
  piVar4 = piVar5;
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar1 = piVar4[2];
    if (param_3 <= iVar1) break;
    param_3 = param_3 - iVar1;
    piVar4 = (int *)piVar4[3];
  }
  if (param_3 == 0) {
    return (int *)0x0;
  }
  if (param_3 < iVar1) {
    iVar3 = piVar4[1];
    piVar2 = (int *)FUN_030c63f0(*(undefined4 *)(*piVar4 + 0x408));
    *param_1 = (int)piVar2;
    *piVar2 = *piVar4;
    *(int *)(*param_1 + 4) = iVar3 + param_3;
    *(int *)(*param_1 + 8) = iVar1 - param_3;
    *(int *)(*param_1 + 0xc) = piVar4[3];
    *(int *)(*(int *)*param_1 + 0x404) = *(int *)(*(int *)*param_1 + 0x404) + 1;
    if ((param_2 != (int *)0x0) && ((int *)*param_2 == piVar4)) {
      *param_2 = *param_1;
    }
    piVar4[2] = param_3;
    piVar4[3] = 0;
  }
  else if (piVar4[3] == 0) {
    *param_2 = 0;
    *param_1 = 0;
  }
  else {
    *param_1 = piVar4[3];
    piVar4[3] = 0;
  }
  return piVar5;
}


