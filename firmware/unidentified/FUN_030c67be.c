/**
 * FUN_030c67be @ 0x030c67be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c67be(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  while( true ) {
    piVar3 = param_1;
    if (piVar3 == (int *)0x0) {
      return;
    }
    if (param_2 < piVar3[2]) break;
    param_2 = param_2 - piVar3[2];
    iVar1 = *piVar3;
    param_1 = (int *)piVar3[3];
    piVar4 = *(int **)(iVar1 + 0x408);
    iVar2 = *(int *)(iVar1 + 0x404) + -1;
    *(int *)(iVar1 + 0x404) = iVar2;
    if (iVar2 == 0) {
      piVar4[2] = piVar4[2] + -1;
      *(int *)(iVar1 + 0x408) = *piVar4;
      *piVar4 = iVar1;
    }
    piVar4[2] = piVar4[2] + -1;
    piVar3[3] = piVar4[1];
    piVar4[1] = (int)piVar3;
    if (piVar4[3] != 0) {
      iVar1 = *piVar4;
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0x408);
        memset_byte(iVar1,0,0x400);
        iVar1 = iVar2;
      }
      *piVar4 = 0;
      for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[3]) {
      }
      piVar4[1] = 0;
      if (piVar4[2] == 0) {
        memset_byte(DAT_030c6b20,0,0x10);
      }
    }
  }
  piVar3[1] = piVar3[1] + param_2;
  piVar3[2] = piVar3[2] - param_2;
  return;
}


