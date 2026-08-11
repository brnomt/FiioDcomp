/**
 * FUN_030c614a @ 0x030c614a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c614a(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  
  iVar7 = DAT_030c62e4;
  uVar17 = 0;
  uVar8 = 0;
  iVar3 = *(int *)(*(int *)(*param_1 + 0x1c) + param_1[0xc] * 4) / 2;
  if (param_3 == (int *)0x0) {
    memset_byte(param_4,0,iVar3 << 2);
    return 0;
  }
  iVar19 = 1;
  iVar16 = *param_3 * *(int *)(param_2 + 0x1a4);
  if (1 < *(int *)(param_2 + 0x1a0)) {
    do {
      uVar4 = (uint)*(byte *)(param_2 + iVar19 + 0xda);
      uVar10 = param_3[uVar4] & 0x7fff;
      uVar18 = uVar8;
      iVar11 = iVar16;
      if (param_3[uVar4] == uVar10) {
        iVar11 = *(int *)(param_2 + 0x1a4) * uVar10;
        uVar18 = (uint)*(ushort *)(param_2 + uVar4 * 2 + 0x58);
        iVar13 = iVar11 - iVar16;
        iVar12 = uVar18 - uVar8;
        iVar5 = iVar13;
        if (iVar13 < 0) {
          iVar5 = -iVar13;
        }
        iVar14 = iVar13 / iVar12;
        if (iVar13 < 0) {
          iVar13 = iVar14 + -1;
        }
        else {
          iVar13 = iVar14 + 1;
        }
        iVar15 = 0;
        iVar20 = iVar14 * iVar12;
        if (iVar20 < 0) {
          iVar20 = -iVar20;
        }
        iVar5 = iVar5 - iVar20;
        *(int *)(param_4 + uVar8 * 4) =
             (*(int *)(param_4 + uVar8 * 4) >> 6) * *(int *)(iVar7 + iVar16 * 4);
        uVar4 = uVar18 - (uVar8 + 1);
        uVar17 = uVar18;
        if (0 < (int)uVar4) {
          piVar9 = (int *)(param_4 + (uVar8 + 1) * 4);
          piVar6 = piVar9 + -1;
          if ((uVar4 & 1) != 0) {
            iVar15 = iVar5;
            iVar20 = iVar14;
            if (iVar12 <= iVar5) {
              iVar15 = iVar5 - iVar12;
              iVar20 = iVar13;
            }
            iVar16 = iVar16 + iVar20;
            *piVar9 = (*piVar9 >> 6) * *(int *)(iVar7 + iVar16 * 4);
            piVar6 = piVar9;
          }
          for (iVar20 = (int)uVar4 >> 1; iVar20 != 0; iVar20 = iVar20 + -1) {
            iVar15 = iVar15 + iVar5;
            iVar1 = iVar14;
            if (iVar12 <= iVar15) {
              iVar15 = iVar15 - iVar12;
              iVar1 = iVar13;
            }
            iVar15 = iVar15 + iVar5;
            piVar6[1] = (piVar6[1] >> 6) * *(int *)(iVar7 + (iVar16 + iVar1) * 4);
            iVar2 = iVar14;
            if (iVar12 <= iVar15) {
              iVar15 = iVar15 - iVar12;
              iVar2 = iVar13;
            }
            iVar16 = iVar16 + iVar1 + iVar2;
            piVar9 = piVar6 + 2;
            piVar6 = piVar6 + 2;
            *piVar6 = (*piVar9 >> 6) * *(int *)(iVar7 + iVar16 * 4);
          }
        }
      }
      iVar19 = iVar19 + 1;
      uVar8 = uVar18;
      iVar16 = iVar11;
    } while (iVar19 < *(int *)(param_2 + 0x1a0));
  }
  uVar8 = iVar3 - uVar17;
  if (0 < (int)uVar8) {
    piVar9 = (int *)(param_4 + uVar17 * 4);
    piVar6 = piVar9 + -1;
    if ((uVar8 & 1) != 0) {
      *piVar9 = iVar16 * *piVar9;
      piVar6 = piVar9;
    }
    for (iVar7 = (int)uVar8 >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      piVar6[1] = iVar16 * piVar6[1];
      piVar9 = piVar6 + 2;
      piVar6 = piVar6 + 2;
      *piVar6 = iVar16 * *piVar9;
    }
  }
  return 1;
}


