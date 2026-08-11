/**
 * FUN_03089b18 @ 0x03089b18
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03089b18(int *param_1,uint *param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  lVar2 = 0;
  lVar1 = 0;
  if (0 < (int)param_3) {
    puVar5 = param_2 + -1;
    if ((param_3 & 1) != 0) {
      lVar1 = (ulonglong)*param_2 * (ulonglong)*param_2;
      puVar5 = param_2;
    }
    lVar2 = 0;
    for (iVar8 = (int)param_3 >> 1; iVar8 != 0; iVar8 = iVar8 + -1) {
      lVar1 = (ulonglong)puVar5[1] * (ulonglong)puVar5[1] + lVar1;
      puVar5 = puVar5 + 2;
      lVar2 = (ulonglong)*puVar5 * (ulonglong)*puVar5 + lVar2;
    }
    lVar2 = lVar1 + lVar2;
  }
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  uVar7 = (uint)lVar2;
  iVar8 = 0;
  uVar4 = uVar3;
  if ((uVar3 == 0) && (iVar8 = 0x20, uVar4 = uVar7, uVar7 == 0)) {
    iVar8 = 0;
    iVar9 = 0;
  }
  else {
    for (; (uVar4 & 0xf0000000) == 0; uVar4 = uVar4 << 3) {
      iVar8 = iVar8 + 3;
    }
    for (; (uVar4 & 0xc0000000) == 0; uVar4 = uVar4 << 1) {
      iVar8 = iVar8 + 1;
    }
    iVar9 = iVar8 + 10;
    if (iVar8 < 0x21) {
      iVar8 = FUN_030827aa(uVar7,uVar3,0x20 - iVar8);
    }
    else {
      iVar8 = FUN_0308278c(uVar7,uVar3,iVar8 + -0x20);
    }
  }
  iVar6 = 0;
  for (param_3 = iVar8 / (int)param_3; param_3 < 0x1fffffff; param_3 = param_3 << 2) {
    iVar6 = iVar6 + 2;
  }
  if (param_3 < 0x3fffffff) {
    param_3 = param_3 << 1;
    iVar6 = iVar6 + 1;
  }
  *param_1 = iVar6 + iVar9;
  param_1[1] = param_3;
  return;
}


