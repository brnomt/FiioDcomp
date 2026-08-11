/**
 * FUN_030ef8d0 @ 0x030ef8d0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ef8d0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  bool bVar11;
  
  if (*(int *)(param_1 + 8) < 0xf96) {
    iVar1 = FUN_030ef84a(param_1,DAT_030efb48 + -0x2c);
    if (iVar1 == 0x3f) {
      uVar7 = FUN_030ef820(param_1,5);
      iVar1 = 0;
LAB_030ef900:
      if ((int)uVar7 < 0x11) goto LAB_030ef904;
      uVar2 = FUN_030ef820(param_1,0x10);
      iVar3 = FUN_030ef820(param_1,uVar7 - 0x10);
      uVar2 = uVar2 | iVar3 << 0x10;
    }
    else {
      if (*param_2 != 0) {
        uVar7 = *param_2 - 1;
        goto LAB_030ef900;
      }
      uVar7 = 0;
LAB_030ef904:
      uVar2 = FUN_030ef820(param_1,uVar7);
    }
    uVar2 = uVar2 + (iVar1 << (uVar7 & 0xff));
  }
  else {
    uVar7 = (uint)param_2[1] >> 5;
    if (uVar7 == 0) {
      uVar7 = 1;
    }
    uVar4 = FUN_030ef84a(param_1,DAT_030efb4c + -0x2c);
    if (uVar4 == 0x3f) {
      iVar1 = FUN_030ef820(param_1,0x10);
      uVar4 = FUN_030ef820(param_1,0x10);
      uVar4 = uVar4 | iVar1 << 0x10;
    }
    puVar10 = (uint *)(param_1 + 0x8960);
    puVar9 = (uint *)(param_1 + 0x8964);
    if (uVar7 < 0x10000) {
      FUN_030ef7b0(param_1);
      uVar5 = *puVar9 / uVar7;
      *puVar9 = uVar5;
      uVar2 = *puVar10 / uVar5;
      *puVar10 = *puVar10 - uVar5 * uVar2;
    }
    else {
      uVar5 = 0;
      for (uVar2 = uVar7; uVar2 >> 0x10 != 0; uVar2 = (int)uVar2 >> 1) {
        uVar5 = uVar5 + 1;
      }
      FUN_030ef7b0(param_1);
      uVar2 = *puVar9 / (uVar2 + 1);
      *puVar9 = uVar2;
      uVar8 = *puVar10 / uVar2;
      *puVar10 = *puVar10 - uVar2 * uVar8;
      FUN_030ef7b0(param_1);
      uVar6 = *puVar9 / (uint)(1 << (uVar5 & 0xff));
      *puVar9 = uVar6;
      uVar2 = *puVar10 / uVar6;
      *puVar10 = *puVar10 - uVar6 * uVar2;
      uVar2 = uVar2 + (uVar8 << (uVar5 & 0xff));
    }
    uVar2 = uVar4 * uVar7 + uVar2;
  }
  uVar7 = ((int)(uVar2 + 1) / 2 - (param_2[1] + 0x10U >> 5)) + param_2[1];
  param_2[1] = uVar7;
  iVar1 = *param_2;
  if (uVar7 < *(uint *)(DAT_030efb50 + iVar1 * 4)) {
    iVar1 = iVar1 + -1;
  }
  else {
    bVar11 = *(uint *)(DAT_030efb50 + iVar1 * 4 + 4) <= uVar7;
    iVar1 = iVar1 + (uint)bVar11;
    if (!bVar11) goto LAB_030efa38;
  }
  *param_2 = iVar1;
LAB_030efa38:
  if ((uVar2 & 1) == 0) {
    iVar1 = -((int)uVar2 >> 1);
  }
  else {
    iVar1 = ((int)uVar2 >> 1) + 1;
  }
  return iVar1;
}


