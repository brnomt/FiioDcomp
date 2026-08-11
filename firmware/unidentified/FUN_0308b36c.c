/**
 * FUN_0308b36c @ 0x0308b36c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308b36c(undefined4 param_1,int *param_2,uint param_3,int param_4,uint param_5,int param_6,
                 int *param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int local_1c8 [101];
  undefined4 uStack_34;
  int *piStack_30;
  uint uStack_2c;
  int local_28;
  
  local_28 = param_4;
  uStack_2c = param_3;
  piStack_30 = param_2;
  uStack_34 = param_1;
  uVar6 = 0;
  while( true ) {
    uVar1 = param_3;
    if ((int)uVar6 < (int)param_3) {
      uVar1 = param_5;
    }
    if ((int)uVar1 <= (int)uVar6) break;
    uVar1 = 0;
    local_1c8[uVar6] = 0;
    if (0 < (int)(uVar6 + 1)) {
      piVar4 = (int *)(local_28 + uVar6 * 4);
      piVar5 = piVar4 + 1;
      piVar7 = param_2 + -1;
      if ((uVar6 & 1) == 0) {
        uVar1 = (uint)((longlong)*param_2 * (longlong)*piVar4) >> 0x1e |
                (int)((ulonglong)((longlong)*param_2 * (longlong)*piVar4) >> 0x20) << 2;
        piVar5 = piVar4;
        piVar7 = param_2;
      }
      iVar2 = 0;
      for (iVar3 = (int)(uVar6 + 1) >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        uVar1 = uVar1 + ((uint)((longlong)piVar7[1] * (longlong)piVar5[-1]) >> 0x1e |
                        (int)((ulonglong)((longlong)piVar7[1] * (longlong)piVar5[-1]) >> 0x20) << 2)
        ;
        piVar7 = piVar7 + 2;
        piVar5 = piVar5 + -2;
        iVar2 = iVar2 + ((uint)((longlong)*piVar7 * (longlong)*piVar5) >> 0x1e |
                        (int)((ulonglong)((longlong)*piVar7 * (longlong)*piVar5) >> 0x20) << 2);
      }
      local_1c8[uVar6] = uVar1 + iVar2;
    }
    uVar6 = uVar6 + 1;
  }
  for (uVar6 = param_3; (int)uVar6 < (int)(param_5 + param_3) / 2; uVar6 = uVar6 + 1) {
    uVar1 = 0;
    local_1c8[uVar6] = 0;
    if (0 < (int)param_3) {
      piVar4 = (int *)(local_28 + uVar6 * 4);
      piVar5 = piVar4 + 1;
      piVar7 = param_2 + -1;
      if ((param_3 & 1) != 0) {
        uVar1 = (uint)((longlong)*param_2 * (longlong)*piVar4) >> 0x1e |
                (int)((ulonglong)((longlong)*param_2 * (longlong)*piVar4) >> 0x20) << 2;
        piVar5 = piVar4;
        piVar7 = param_2;
      }
      iVar2 = 0;
      for (iVar3 = (int)param_3 >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        uVar1 = uVar1 + ((uint)((longlong)piVar7[1] * (longlong)piVar5[-1]) >> 0x1e |
                        (int)((ulonglong)((longlong)piVar7[1] * (longlong)piVar5[-1]) >> 0x20) << 2)
        ;
        piVar7 = piVar7 + 2;
        piVar5 = piVar5 + -2;
        iVar2 = iVar2 + ((uint)((longlong)*piVar7 * (longlong)*piVar5) >> 0x1e |
                        (int)((ulonglong)((longlong)*piVar7 * (longlong)*piVar5) >> 0x20) << 2);
      }
      local_1c8[uVar6] = uVar1 + iVar2;
    }
  }
  *param_7 = param_5 + param_3 + -1;
  for (iVar2 = 0; iVar2 < *param_7 / 2; iVar2 = iVar2 + 1) {
    iVar3 = local_1c8[iVar2];
    *(int *)(param_6 + iVar2 * 4) = iVar3;
    *(int *)(param_6 + (*param_7 - iVar2) * 4 + -4) = iVar3;
  }
  *(int *)(param_6 + (*param_7 / 2) * 4) = local_1c8[*param_7 / 2];
  return;
}


