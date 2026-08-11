/**
 * FUN_030c6594 @ 0x030c6594
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030c6594(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  iVar2 = DAT_030c66f0;
  piVar1 = DAT_030c66e8;
  piVar6 = (int *)0x0;
  piVar5 = (int *)0x0;
  piVar7 = piVar6;
  if (param_1 != (int *)0x0) {
    do {
      iVar3 = *(int *)(*param_1 + 0x408);
      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
      piVar4 = *(int **)(iVar3 + 4);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)(iVar2 + *piVar1 * 0x10);
        memset_byte(piVar4,0,0x10);
        iVar3 = *piVar1;
        *piVar1 = iVar3 + 1;
        if (iVar3 + 1 < 0x2d) goto LAB_030c65e8;
        piVar4 = (int *)0x0;
      }
      else {
        *(int *)(iVar3 + 4) = piVar4[3];
LAB_030c65e8:
        piVar4[1] = 0;
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
      piVar7 = piVar4;
      if (piVar5 != (int *)0x0) {
        piVar5[3] = (int)piVar4;
        piVar7 = piVar6;
      }
      *piVar4 = *param_1;
      piVar4[1] = param_1[1];
      piVar4[2] = param_1[2];
      param_1 = (int *)param_1[3];
      piVar5 = piVar4;
      piVar6 = piVar7;
    } while (param_1 != (int *)0x0);
    for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
      *(int *)(*piVar6 + 0x404) = *(int *)(*piVar6 + 0x404) + 1;
    }
  }
  return piVar7;
}


