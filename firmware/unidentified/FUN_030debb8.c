/**
 * FUN_030debb8 @ 0x030debb8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030debb8(int *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  
  iVar5 = *(int *)(DAT_030dee0c + 4);
  bVar1 = 0x10 < param_4;
  if (bVar1) {
    param_4 = 0x20 - param_4;
  }
  else {
    param_4 = 0x10 - param_4;
  }
  if (param_3 == 0) {
    iVar3 = 0;
    piVar4 = param_1;
    piVar10 = param_1;
    if (0 < param_5) {
      do {
        if (iVar5 == 1) {
          if (bVar1) {
            iVar6 = *(int *)(*param_2 + iVar3 * 4);
            if (param_4 == 0) {
              piVar9 = piVar4 + 1;
              *piVar4 = iVar6;
              piVar4 = piVar4 + 2;
              *piVar9 = *(int *)(*param_2 + iVar3 * 4);
            }
            else {
              puVar8 = (undefined4 *)((int)piVar10 + 3);
              *piVar10 = iVar6;
              piVar10 = (int *)((int)piVar10 + 6);
              *puVar8 = *(undefined4 *)(*param_2 + iVar3 * 4);
            }
          }
          else {
            puVar2 = (undefined2 *)((int)param_1 + 2);
            *(undefined2 *)param_1 = *(undefined2 *)(*param_2 + iVar3 * 4);
            param_1 = param_1 + 1;
            *puVar2 = *(undefined2 *)(*param_2 + iVar3 * 4);
          }
        }
        else {
          iVar6 = 0;
          piVar9 = piVar10;
          if (0 < iVar5) {
            do {
              piVar10 = piVar9;
              if (bVar1) {
                iVar7 = *(int *)(param_2[iVar6] + iVar3 * 4);
                if (param_4 == 0) {
                  *piVar4 = iVar7;
                  piVar4 = piVar4 + 1;
                }
                else {
                  piVar10 = (int *)((int)piVar9 + 3);
                  *piVar9 = iVar7;
                }
              }
              else {
                *(undefined2 *)param_1 = *(undefined2 *)(param_2[iVar6] + iVar3 * 4);
                param_1 = (int *)((int)param_1 + 2);
              }
              iVar6 = iVar6 + 1;
              piVar9 = piVar10;
            } while (iVar6 < iVar5);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  else if (param_3 == 1) {
    iVar3 = 0;
    piVar4 = param_1;
    piVar10 = param_1;
    if (0 < param_5) {
      do {
        iVar6 = *(int *)(*param_2 + iVar3 * 4);
        iVar7 = iVar6 - *(int *)(param_2[1] + iVar3 * 4);
        if (bVar1) {
          if (param_4 == 0) {
            piVar9 = piVar4 + 1;
            *piVar4 = iVar6;
            piVar4 = piVar4 + 2;
            *piVar9 = iVar7;
          }
          else {
            piVar9 = (int *)((int)piVar10 + 3);
            *piVar10 = iVar6;
            piVar10 = (int *)((int)piVar10 + 6);
            *piVar9 = iVar7;
          }
        }
        else {
          puVar2 = (undefined2 *)((int)param_1 + 2);
          *(short *)param_1 = (short)iVar6;
          param_1 = param_1 + 1;
          *puVar2 = (short)iVar7;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  else if (param_3 == 2) {
    iVar3 = 0;
    piVar4 = param_1;
    piVar10 = param_1;
    if (0 < param_5) {
      do {
        iVar6 = *(int *)(param_2[1] + iVar3 * 4);
        iVar7 = *(int *)(*param_2 + iVar3 * 4) + iVar6;
        if (bVar1) {
          if (param_4 == 0) {
            piVar9 = piVar4 + 1;
            *piVar4 = iVar7;
            piVar4 = piVar4 + 2;
            *piVar9 = iVar6;
          }
          else {
            piVar9 = (int *)((int)piVar10 + 3);
            *piVar10 = iVar7;
            piVar10 = (int *)((int)piVar10 + 6);
            *piVar9 = iVar6;
          }
        }
        else {
          puVar2 = (undefined2 *)((int)param_1 + 2);
          *(short *)param_1 = (short)iVar7;
          param_1 = param_1 + 1;
          *puVar2 = (short)iVar6;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
  }
  else if ((param_3 == 3) && (iVar3 = 0, piVar4 = param_1, piVar10 = param_1, 0 < param_5)) {
    do {
      iVar7 = *(int *)(param_2[1] + iVar3 * 4);
      iVar6 = *(int *)(*param_2 + iVar3 * 4) - (iVar7 >> 1);
      iVar7 = iVar7 + iVar6;
      if (bVar1) {
        if (param_4 == 0) {
          piVar9 = piVar4 + 1;
          *piVar4 = iVar7;
          piVar4 = piVar4 + 2;
          *piVar9 = iVar6;
        }
        else {
          piVar9 = (int *)((int)piVar10 + 3);
          *piVar10 = iVar7;
          piVar10 = (int *)((int)piVar10 + 6);
          *piVar9 = iVar6;
        }
      }
      else {
        puVar2 = (undefined2 *)((int)param_1 + 2);
        *(short *)param_1 = (short)iVar7;
        param_1 = param_1 + 1;
        *puVar2 = (short)iVar6;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5);
  }
  if (!bVar1) {
    return param_5 * iVar5 * 2;
  }
  if (param_4 == 0) {
    iVar5 = param_5 * iVar5 * 4;
  }
  else {
    iVar5 = param_5 * iVar5 * 3;
  }
  return iVar5;
}


