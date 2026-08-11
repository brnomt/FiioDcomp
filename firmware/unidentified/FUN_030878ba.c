/**
 * FUN_030878ba @ 0x030878ba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030878ba(int *param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int unaff_r4;
  int unaff_r5;
  int unaff_r8;
  int iVar11;
  int unaff_r9;
  int iVar12;
  int local_44;
  int local_40;
  
  iVar4 = (int)(param_3 + ((uint)((int)param_3 >> 0x1f) >> 0x1e)) >> 2;
  iVar5 = wma_floor_log2(param_3);
  piVar7 = param_1 + param_3 + -1;
  iVar11 = iVar4;
  piVar6 = param_1;
  if (param_3 - 0x40 < 0x7c1) {
    piVar8 = *(int **)(DAT_03087ab4 + ((int)param_3 >> 7) * 4);
    lVar1 = (longlong)param_2;
    lVar2 = (longlong)param_2;
    unaff_r9 = (int)((ulonglong)((longlong)param_2 * (longlong)piVar8[3]) >> 0x20) << 1;
    unaff_r8 = (int)((ulonglong)((longlong)param_2 * (longlong)piVar8[2]) >> 0x20) << 1;
    param_2 = -piVar8[10];
    local_40 = piVar8[5];
    local_44 = piVar8[4];
    unaff_r4 = (int)((ulonglong)(lVar1 * piVar8[1]) >> 0x20) << 1;
    unaff_r5 = (int)((ulonglong)(lVar2 * *piVar8) >> 0x20) * -2;
  }
  for (; iVar3 = unaff_r5, iVar10 = unaff_r4, iVar9 = iVar4, 0 < iVar11; iVar11 = iVar11 + -1) {
    iVar9 = *piVar7;
    *piVar7 = piVar6[1];
    iVar12 = *piVar6;
    piVar7 = piVar7 + -2;
    *piVar6 = ((int)((ulonglong)((longlong)iVar10 * (longlong)iVar12) >> 0x20) -
              (int)((ulonglong)((longlong)iVar3 * (longlong)iVar9) >> 0x20)) * 2;
    piVar6[1] = ((int)((ulonglong)((longlong)iVar10 * (longlong)iVar9) >> 0x20) +
                (int)((ulonglong)((longlong)iVar3 * (longlong)iVar12) >> 0x20)) * 2;
    unaff_r4 = unaff_r9 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar3) >> 0x20) * -2;
    unaff_r5 = unaff_r8 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar10) >> 0x20) * 2;
    unaff_r8 = iVar3;
    unaff_r9 = iVar10;
    piVar6 = piVar6 + 2;
  }
  for (; iVar12 = iVar3, iVar11 = iVar10, 0 < iVar9; iVar9 = iVar9 + -1) {
    iVar10 = *piVar6;
    *piVar6 = ((int)((ulonglong)((longlong)iVar11 * (longlong)iVar10) >> 0x20) -
              (int)((ulonglong)((longlong)iVar12 * (longlong)piVar6[1]) >> 0x20)) * 2;
    piVar6[1] = ((int)((ulonglong)((longlong)iVar11 * (longlong)piVar6[1]) >> 0x20) +
                (int)((ulonglong)((longlong)iVar12 * (longlong)iVar10) >> 0x20)) * 2;
    piVar6 = piVar6 + 2;
    iVar10 = unaff_r9 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar12) >> 0x20) * -2;
    iVar3 = unaff_r8 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar11) >> 0x20) * 2;
    unaff_r8 = iVar12;
    unaff_r9 = iVar11;
  }
  FUN_03087440(param_1,iVar5 + -1);
  piVar7 = param_1 + param_3;
  iVar11 = 0;
  iVar5 = 0x7fffffff;
  piVar6 = param_1;
  for (; iVar3 = iVar5, iVar10 = iVar11, 0 < iVar4; iVar4 = iVar4 + -1) {
    piVar8 = piVar7 + -2;
    iVar11 = *piVar6;
    iVar9 = *piVar8;
    iVar12 = piVar7[-1];
    *piVar6 = ((int)((ulonglong)((longlong)iVar3 * (longlong)iVar11) >> 0x20) -
              (int)((ulonglong)((longlong)iVar10 * (longlong)piVar6[1]) >> 0x20)) * 2;
    piVar7[-1] = ((int)((ulonglong)((longlong)-iVar10 * (longlong)iVar11) >> 0x20) -
                 (int)((ulonglong)((longlong)iVar3 * (longlong)piVar6[1]) >> 0x20)) * 2;
    iVar5 = local_40 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar10) >> 0x20) * -2;
    iVar11 = local_44 + (int)((ulonglong)((longlong)param_2 * (longlong)iVar3) >> 0x20) * 2;
    piVar6[1] = ((int)((ulonglong)((longlong)iVar5 * (longlong)iVar9) >> 0x20) +
                (int)((ulonglong)((longlong)iVar11 * (longlong)iVar12) >> 0x20)) * 2;
    piVar6 = piVar6 + 2;
    *piVar8 = ((int)((ulonglong)((longlong)-iVar11 * (longlong)iVar9) >> 0x20) +
              (int)((ulonglong)((longlong)iVar5 * (longlong)iVar12) >> 0x20)) * 2;
    piVar7 = piVar8;
    local_44 = iVar10;
    local_40 = iVar3;
  }
  if ((0 < (int)param_4) && (0 < (int)param_3)) {
    piVar7 = param_1 + -1;
    if ((param_3 & 1) != 0) {
      *param_1 = *param_1 << (param_4 & 0xff);
      piVar7 = param_1;
    }
    for (iVar11 = (int)param_3 >> 1; iVar11 != 0; iVar11 = iVar11 + -1) {
      piVar7[1] = piVar7[1] << (param_4 & 0xff);
      piVar6 = piVar7 + 2;
      piVar7 = piVar7 + 2;
      *piVar7 = *piVar6 << (param_4 & 0xff);
    }
  }
  return 0;
}


