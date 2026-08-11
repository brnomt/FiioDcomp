/**
 * FUN_030266b4 @ 0x030266b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030266b4(void)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar7 = DAT_0302699c;
  iVar14 = DAT_03026998;
  iVar10 = DAT_0302698c;
  iVar11 = DAT_03026988;
  iVar12 = 0;
  iVar13 = *DAT_03026984;
  iVar9 = 0;
  iVar6 = 0;
  if (0 < iVar13) {
    do {
      iVar15 = *(int *)(DAT_03026988 + iVar6 * 4);
      if (iVar12 < iVar15) {
        iVar12 = iVar15;
      }
      iVar15 = *(int *)(DAT_0302698c + iVar6 * 4);
      if (iVar9 < iVar15) {
        iVar9 = iVar15;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar13);
  }
  iVar6 = 0;
  sVar1 = *DAT_03026970;
  sVar2 = *DAT_0302696c;
  if (0 < iVar13) {
    do {
      iVar15 = ((int)sVar1 * *(int *)(iVar11 + iVar6 * 4) + iVar12 + -1) / iVar12 + 7;
      *(int *)(iVar14 + iVar6 * 4) = (int)(iVar15 + ((uint)(iVar15 >> 0x1f) >> 0x1d)) >> 3;
      iVar15 = ((int)sVar2 * *(int *)(iVar10 + iVar6 * 4) + iVar9 + -1) / iVar9 + 7;
      *(int *)(iVar7 + iVar6 * 4) = (int)(iVar15 + ((uint)(iVar15 >> 0x1f) >> 0x1d)) >> 3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar13);
  }
  piVar5 = DAT_030269dc;
  piVar4 = DAT_030269d0;
  piVar3 = DAT_030269c8;
  piVar8 = DAT_030269a4;
  iVar6 = *DAT_030269a0;
  if (iVar6 != 1) {
    iVar14 = sVar1 + 7;
    *DAT_030269cc = (iVar12 + ((int)(iVar14 + ((uint)(iVar14 >> 0x1f) >> 0x1d)) >> 3) + -1) / iVar12
    ;
    iVar14 = sVar2 + 7;
    *piVar4 = (iVar9 + ((int)(iVar14 + ((uint)(iVar14 >> 0x1f) >> 0x1d)) >> 3) + -1) / iVar9;
    iVar14 = 0;
    *piVar3 = 0;
    if (0 < iVar6) {
      do {
        iVar9 = piVar8[iVar14];
        for (iVar7 = *(int *)(iVar10 + iVar9 * 4) * *(int *)(iVar11 + iVar9 * 4); iVar7 != 0;
            iVar7 = iVar7 + -1) {
          iVar12 = *piVar3;
          piVar5[iVar12] = iVar9;
          *piVar3 = iVar12 + 1;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < iVar6);
    }
    iVar11 = DAT_03026a20;
    iVar10 = *piVar3;
    piVar8 = DAT_030269dc;
    do {
      iVar10 = iVar10 + -1;
      *(int *)(iVar11 + iVar10 * 4) = *piVar8;
      piVar8 = piVar8 + 1;
    } while (iVar10 != 0);
    return;
  }
  iVar11 = *DAT_030269a4;
  *DAT_030269cc = *(int *)(iVar14 + iVar11 * 4);
  *piVar4 = *(int *)(iVar7 + iVar11 * 4);
  *piVar5 = iVar11;
  *piVar3 = 1;
  return;
}


