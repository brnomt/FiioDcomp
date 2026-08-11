/**
 * FUN_030b38fc @ 0x030b38fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b38fc(int param_1,uint *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  
  iVar7 = *(int *)(*DAT_030b3bdc + param_1 * 4);
  piVar1 = (int *)(*DAT_030b3bd8 + *(int *)(*DAT_030b3bd4 + param_1 * 4) * 4);
  iVar8 = iVar7 >> 2;
  if (3 < param_3) {
    puVar6 = param_2 + iVar7 + -1;
    puVar5 = param_2;
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      piVar2 = piVar1 + 1;
      iVar13 = *piVar1;
      uVar9 = puVar5[1];
      uVar10 = puVar6[-1];
      uVar14 = *puVar6;
      iVar15 = (int)((ulonglong)((longlong)*piVar2 * (longlong)(int)(*puVar5 + uVar14)) >> 0x20);
      piVar3 = piVar1 + 3;
      iVar11 = piVar1[2];
      piVar1 = piVar1 + 4;
      iVar16 = *piVar3;
      puVar4 = puVar5 + 1;
      *puVar5 = (int)((ulonglong)((longlong)(iVar13 + *piVar2 * -2) * (longlong)(int)*puVar5) >>
                     0x20) + iVar15;
      iVar7 = (int)((ulonglong)((longlong)iVar16 * (longlong)(int)(uVar10 + uVar9)) >> 0x20);
      puVar5 = puVar5 + 2;
      *puVar4 = (int)((ulonglong)((longlong)iVar13 * (longlong)(int)uVar14) >> 0x20) - iVar15;
      *puVar6 = (int)((ulonglong)((longlong)iVar11 * (longlong)(int)uVar9) >> 0x20) - iVar7;
      puVar6[-1] = (int)((ulonglong)((longlong)(iVar11 + iVar16 * -2) * (longlong)(int)uVar10) >>
                        0x20) + iVar7;
      puVar6 = puVar6 + -2;
    }
    FUN_030b46f0(param_1,param_2);
    iVar7 = *(int *)(*DAT_030b3bdc + param_1 * 4);
    iVar13 = *(int *)(DAT_030b3bdc[1] + param_1 * 4);
    puVar6 = param_2 + iVar7 + -1;
    piVar1 = (int *)*DAT_030b3be0 + 1;
    iVar15 = *(int *)*DAT_030b3be0;
    iVar8 = *piVar1;
    iVar11 = iVar15 + iVar8 * -2;
    iVar7 = iVar7 >> 2;
    if (iVar7 == 0) {
      return;
    }
    do {
      piVar2 = piVar1 + iVar13;
      uVar10 = *param_2;
      iVar8 = (int)((ulonglong)((longlong)iVar8 * (longlong)(int)(uVar10 + param_2[1])) >> 0x20);
      uVar14 = puVar6[-1];
      uVar9 = *puVar6;
      *puVar6 = iVar8 - (int)((ulonglong)((longlong)iVar15 * (longlong)(int)param_2[1]) >> 0x20);
      puVar5 = param_2 + 1;
      *param_2 = iVar8 + (int)((ulonglong)((longlong)iVar11 * (longlong)(int)uVar10) >> 0x20);
      piVar1 = piVar2 + 1;
      iVar15 = *piVar2;
      iVar8 = *piVar1;
      iVar16 = (int)((ulonglong)((longlong)iVar8 * (longlong)(int)(uVar14 - uVar9)) >> 0x20);
      puVar6[-1] = iVar16 - (int)((ulonglong)((longlong)iVar15 * (longlong)(int)-uVar9) >> 0x20);
      iVar11 = iVar15 + iVar8 * -2;
      puVar6 = puVar6 + -2;
      param_2 = param_2 + 2;
      *puVar5 = iVar16 + (int)((ulonglong)((longlong)iVar11 * (longlong)(int)uVar14) >> 0x20);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    return;
  }
  uVar10 = 4 - param_3;
  puVar6 = param_2 + iVar7 + -1;
  puVar5 = param_2;
  for (; iVar8 != 0; iVar8 = iVar8 + -1) {
    piVar2 = piVar1 + 1;
    iVar18 = *piVar1;
    iVar11 = (int)*puVar5 >> (uVar10 & 0xff);
    iVar13 = (int)*puVar6 >> (uVar10 & 0xff);
    iVar15 = (int)puVar5[1] >> (uVar10 & 0xff);
    iVar16 = (int)((ulonglong)((longlong)*piVar2 * (longlong)(iVar11 + iVar13)) >> 0x20);
    piVar3 = piVar1 + 3;
    iVar7 = piVar1[2];
    piVar1 = piVar1 + 4;
    iVar19 = *piVar3;
    puVar4 = puVar5 + 1;
    *puVar5 = (int)((ulonglong)((longlong)(iVar18 + *piVar2 * -2) * (longlong)iVar11) >> 0x20) +
              iVar16;
    puVar5 = puVar5 + 2;
    *puVar4 = (int)((ulonglong)((longlong)iVar18 * (longlong)iVar13) >> 0x20) - iVar16;
    iVar13 = (int)puVar6[-1] >> (uVar10 & 0xff);
    iVar11 = (int)((ulonglong)((longlong)iVar19 * (longlong)(iVar13 + iVar15)) >> 0x20);
    *puVar6 = (int)((ulonglong)((longlong)iVar7 * (longlong)iVar15) >> 0x20) - iVar11;
    puVar6[-1] = (int)((ulonglong)((longlong)(iVar7 + iVar19 * -2) * (longlong)iVar13) >> 0x20) +
                 iVar11;
    puVar6 = puVar6 + -2;
  }
  FUN_030b46f0(param_1,param_2);
  iVar8 = *(int *)(*DAT_030b3bdc + param_1 * 4);
  iVar11 = *(int *)(DAT_030b3bdc[1] + param_1 * 4);
  puVar6 = param_2 + iVar8;
  piVar1 = (int *)*DAT_030b3be0 + 1;
  iVar13 = *(int *)*DAT_030b3be0;
  iVar7 = *piVar1;
  iVar8 = iVar8 >> 2;
  if (iVar8 != 0) {
    uVar9 = 0x1e - uVar10;
    do {
      piVar2 = piVar1 + iVar11;
      puVar5 = puVar6 + -1;
      uVar17 = *param_2;
      iVar15 = (int)((ulonglong)((longlong)iVar7 * (longlong)(int)(uVar17 + param_2[1])) >> 0x20);
      iVar16 = iVar15 - (int)((ulonglong)((longlong)iVar13 * (longlong)(int)param_2[1]) >> 0x20);
      uVar14 = *puVar5;
      if (iVar16 >> (uVar9 & 0xff) == iVar16 >> 0x1f) {
        uVar12 = iVar16 << (uVar10 & 0xff);
      }
      else {
        uVar12 = iVar16 >> 0x1f ^ 0x3fffffff;
      }
      puVar6 = puVar6 + -2;
      *puVar5 = uVar12;
      iVar15 = (int)((ulonglong)((longlong)(iVar13 + iVar7 * -2) * (longlong)(int)uVar17) >> 0x20) +
               iVar15;
      if (iVar15 >> (uVar9 & 0xff) == iVar15 >> 0x1f) {
        uVar17 = iVar15 << (uVar10 & 0xff);
      }
      else {
        uVar17 = iVar15 >> 0x1f ^ 0x3fffffff;
      }
      puVar5 = param_2 + 1;
      *param_2 = uVar17;
      piVar1 = piVar2 + 1;
      iVar13 = *piVar2;
      iVar7 = *piVar1;
      uVar17 = *puVar6;
      iVar15 = (int)((ulonglong)((longlong)iVar7 * (longlong)(int)(uVar17 - uVar14)) >> 0x20);
      iVar16 = iVar15 - (int)((ulonglong)((longlong)iVar13 * (longlong)(int)-uVar14) >> 0x20);
      if (iVar16 >> (uVar9 & 0xff) == iVar16 >> 0x1f) {
        uVar14 = iVar16 << (uVar10 & 0xff);
      }
      else {
        uVar14 = iVar16 >> 0x1f ^ 0x3fffffff;
      }
      *puVar6 = uVar14;
      iVar13 = iVar13 + iVar7 * -2;
      iVar15 = (int)((ulonglong)((longlong)iVar13 * (longlong)(int)uVar17) >> 0x20) + iVar15;
      if (iVar15 >> (uVar9 & 0xff) == iVar15 >> 0x1f) {
        uVar14 = iVar15 << (uVar10 & 0xff);
      }
      else {
        uVar14 = iVar15 >> 0x1f ^ 0x3fffffff;
      }
      param_2 = param_2 + 2;
      *puVar5 = uVar14;
      iVar13 = iVar13 + iVar7 * 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    return;
  }
  return;
}


