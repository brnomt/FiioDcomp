/**
 * FUN_0304f4ac @ 0x0304f4ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304f4ac(int param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = 0;
  iVar4 = 0;
  piVar7 = *(int **)(param_1 + 4);
  iVar5 = 0;
  iVar6 = 0;
  if (piVar7 == (int *)0x0) {
    iVar1 = 0;
    iVar2 = *(int *)(param_1 + 0x14);
  }
  else {
    iVar2 = *piVar7;
    if (param_2 < iVar2) {
      iVar1 = 0;
    }
    else {
      do {
        piVar8 = piVar7;
        iVar1 = *piVar8;
        if ((iVar1 <= param_2) && (param_2 + 1 <= piVar8[1] + iVar1)) {
          iVar2 = piVar8[1];
          iVar3 = piVar8[2];
          iVar4 = piVar8[3];
          iVar5 = piVar8[4];
          iVar6 = piVar8[5];
          goto LAB_0304f526;
        }
        piVar7 = (int *)piVar8[6];
        if (piVar7 == (int *)0x0) {
          iVar2 = *(int *)(param_1 + 0x14);
          iVar1 = iVar1 + piVar8[1];
          goto LAB_0304f524;
        }
        iVar1 = iVar1 + piVar8[1] + -1;
        bVar9 = SBORROW4(iVar1,param_2);
        iVar2 = iVar1 - param_2;
        if (iVar1 < param_2) {
          bVar9 = SBORROW4(param_2,*piVar7);
          iVar2 = param_2 - *piVar7;
        }
      } while (iVar2 < 0 == bVar9);
      iVar1 = *piVar8 + piVar8[1];
      iVar2 = *piVar7;
LAB_0304f524:
      iVar2 = iVar2 - iVar1;
    }
  }
LAB_0304f526:
  if (param_3 != (int *)0x0) {
    *param_3 = iVar3;
    param_3[1] = iVar4;
    param_3[2] = iVar5;
    param_3[3] = iVar6;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar1;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar2;
  }
  return 1;
}


