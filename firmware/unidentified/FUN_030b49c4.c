/**
 * FUN_030b49c4 @ 0x030b49c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b49c4(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_30;
  int iStack_2c;
  int *piStack_28;
  
  piVar5 = param_1;
  piStack_28 = param_4;
  iStack_2c = param_3;
  local_30 = param_2;
  if (param_2 != 0) {
    do {
      for (; iVar1 = iStack_2c, piVar2 = piStack_28, param_2 != 0; param_2 = param_2 + -1) {
        for (; iVar1 != 0; iVar1 = iVar1 + -1) {
          piVar3 = piVar5 + iStack_2c * 2;
          iVar9 = (int)((ulonglong)((longlong)piVar2[1] * (longlong)(*piVar3 + piVar3[1])) >> 0x20);
          piVar4 = piVar3 + iStack_2c * 2;
          iVar7 = (int)((ulonglong)((longlong)(*piVar2 + piVar2[1] * 2) * (longlong)*piVar3) >> 0x20
                       ) - iVar9;
          iVar9 = iVar9 + (int)((ulonglong)((longlong)*piVar2 * (longlong)piVar3[1]) >> 0x20);
          iVar14 = (int)((ulonglong)((longlong)piVar2[3] * (longlong)(*piVar4 + piVar4[1])) >> 0x20)
          ;
          iVar6 = (int)((ulonglong)((longlong)(piVar2[2] + piVar2[3] * 2) * (longlong)*piVar4) >>
                       0x20) - iVar14;
          piVar3 = piVar4 + iStack_2c * 2;
          iVar14 = (int)((ulonglong)((longlong)piVar2[2] * (longlong)piVar4[1]) >> 0x20) + iVar14;
          iVar12 = (int)((ulonglong)((longlong)piVar2[5] * (longlong)(*piVar3 + piVar3[1])) >> 0x20)
          ;
          iVar11 = (int)((ulonglong)((longlong)(piVar2[4] + piVar2[5] * 2) * (longlong)*piVar3) >>
                        0x20) - iVar12;
          iVar12 = iVar12 + (int)((ulonglong)((longlong)piVar2[4] * (longlong)piVar3[1]) >> 0x20);
          iVar13 = (*piVar5 >> 2) - iVar7;
          iVar15 = (piVar5[1] >> 2) - iVar9;
          iVar7 = iVar7 + (*piVar5 >> 2);
          iVar9 = iVar9 + (piVar5[1] >> 2);
          iVar8 = iVar6 + iVar11;
          iVar10 = iVar12 - iVar14;
          iVar6 = iVar6 - iVar11;
          *piVar3 = iVar13 + iVar10;
          piVar3[1] = iVar15 + iVar6;
          piVar3 = piVar3 + iStack_2c * -2;
          iVar14 = iVar14 + iVar12;
          *piVar3 = iVar7 - iVar8;
          piVar3[1] = iVar9 - iVar14;
          piVar3 = piVar3 + iStack_2c * -2;
          *piVar3 = iVar13 - iVar10;
          piVar3[1] = iVar15 - iVar6;
          piVar3 = piVar3 + iStack_2c * -2;
          *piVar3 = iVar7 + iVar8;
          piVar3[1] = iVar9 + iVar14;
          piVar5 = piVar3 + 2;
          piVar2 = piVar2 + 6;
        }
        piVar5 = piVar5 + iStack_2c * 6;
      }
      piStack_28 = piStack_28 + iStack_2c * 6;
      iStack_2c = iStack_2c << 2;
      param_2 = local_30 >> 2;
      piVar5 = param_1;
      local_30 = param_2;
    } while (param_2 != 0);
    return;
  }
  return;
}


