/**
 * FUN_03026748 @ 0x03026748
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03026748(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_r4;
  int iVar9;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  int unaff_r10;
  int unaff_r11;
  
  *param_1 = unaff_r5;
  param_1 = param_1 + 1;
  while (piVar3 = DAT_030269dc, piVar2 = DAT_030269d0, piVar1 = DAT_030269c8, piVar5 = DAT_030269a4,
        param_1 = (int *)((int)param_1 + 1), (int)param_1 < param_4) {
    iVar8 = (unaff_r5 * *(int *)(unaff_r8 + (int)param_1 * 4) + unaff_r7) / param_3 + 7;
    *(int *)(unaff_r10 + (int)param_1 * 4) = (int)(iVar8 + ((uint)(iVar8 >> 0x1f) >> 0x1d)) >> 3;
    iVar8 = (unaff_r4 * *(int *)(unaff_r9 + (int)param_1 * 4) + unaff_r6) / param_2 + 7;
    *(int *)(unaff_r11 + (int)param_1 * 4) = (int)(iVar8 + ((uint)(iVar8 >> 0x1f) >> 0x1d)) >> 3;
  }
  iVar8 = *DAT_030269a0;
  if (iVar8 == 1) {
    iVar8 = *DAT_030269a4;
    *DAT_030269cc = *(int *)(unaff_r10 + iVar8 * 4);
    *piVar2 = *(int *)(unaff_r11 + iVar8 * 4);
    *piVar3 = iVar8;
    *piVar1 = 1;
    return;
  }
  *DAT_030269cc =
       (param_3 + ((int)(unaff_r5 + 7 + ((uint)(unaff_r5 + 7 >> 0x1f) >> 0x1d)) >> 3) + -1) /
       param_3;
  *piVar2 = (param_2 + ((int)(unaff_r4 + 7 + ((uint)(unaff_r4 + 7 >> 0x1f) >> 0x1d)) >> 3) + -1) /
            param_2;
  iVar9 = 0;
  *piVar1 = 0;
  if (0 < iVar8) {
    do {
      iVar7 = piVar5[iVar9];
      for (iVar4 = *(int *)(unaff_r9 + iVar7 * 4) * *(int *)(unaff_r8 + iVar7 * 4); iVar4 != 0;
          iVar4 = iVar4 + -1) {
        iVar6 = *piVar1;
        piVar3[iVar6] = iVar7;
        *piVar1 = iVar6 + 1;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar8);
  }
  iVar8 = DAT_03026a20;
  iVar9 = *piVar1;
  piVar5 = DAT_030269dc;
  do {
    iVar9 = iVar9 + -1;
    *(int *)(iVar8 + iVar9 * 4) = *piVar5;
    piVar5 = piVar5 + 1;
  } while (iVar9 != 0);
  return;
}


