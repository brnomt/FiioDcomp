/**
 * FUN_0306edd6 @ 0x0306edd6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306edd6(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined2 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined4 uVar11;
  
  puVar3 = DAT_0306f168;
  piVar2 = DAT_0306f164;
  iVar8 = DAT_0306f164[2];
  iVar5 = *DAT_0306f164;
  if (iVar8 == 0) {
    iVar6 = *(int *)(iVar5 + 0x2c);
    iVar5 = *(int *)(iVar5 + 0x34) << 2;
  }
  else {
    iVar6 = *(int *)(iVar5 + 0x30);
    iVar5 = *(int *)(iVar5 + iVar8 * 4 + 0x34) * 4 + iVar8 * 2;
  }
  puVar10 = (undefined2 *)(iVar5 + iVar6);
  if (DAT_0306f164[7] == 1) {
    *puVar10 = *DAT_0306f168;
    uVar11 = *(undefined4 *)(puVar3 + 2);
    iVar5 = 0xf;
    puVar9 = puVar3;
    puVar7 = puVar10;
    do {
      uVar1 = puVar9[4];
      puVar7[2] = (short)uVar11;
      uVar11 = *(undefined4 *)(puVar9 + 6);
      puVar7 = puVar7 + 4;
      *puVar7 = uVar1;
      iVar5 = iVar5 + -1;
      puVar9 = puVar9 + 4;
    } while (iVar5 != 0);
    puVar10[0x3e] = puVar3[0x3e];
  }
  else {
    *puVar10 = *DAT_0306f168;
    puVar10[1] = *puVar3;
    uVar11 = *(undefined4 *)(puVar3 + 2);
    iVar5 = 0xf;
    puVar7 = puVar3;
    puVar9 = puVar10;
    do {
      uVar1 = puVar7[4];
      puVar9[2] = (short)uVar11;
      puVar9[3] = (short)uVar11;
      uVar11 = *(undefined4 *)(puVar7 + 6);
      puVar9[4] = uVar1;
      puVar9[5] = uVar1;
      puVar9 = puVar9 + 4;
      iVar5 = iVar5 + -1;
      puVar7 = puVar7 + 4;
    } while (iVar5 != 0);
    puVar10[0x3e] = puVar3[0x3e];
    puVar10[0x3f] = puVar3[0x3e];
  }
  piVar4 = DAT_0306f16c;
  iVar8 = *piVar2;
  iVar6 = iVar8 + piVar2[2] * 4;
  iVar5 = *(int *)(iVar6 + 0x34) + 0x20;
  *(int *)(iVar6 + 0x34) = iVar5;
  if (*piVar4 == 0x480) {
    if (iVar5 < 0x480) {
      return;
    }
    *(undefined4 *)(iVar8 + piVar2[2] * 4 + 0x34) = 0;
    if (piVar2[2] == 1) {
      FUN_0306e562();
    }
    else {
      FUN_0306e538();
    }
    if (piVar2[2] == piVar2[7]) {
      FUN_0306e58c();
    }
  }
  if (*piVar4 == 0x180) {
    iVar5 = *piVar2 + piVar2[2] * 4;
    if (*(int *)(iVar5 + 0x34) < 0x180) {
      return;
    }
    *(undefined4 *)(iVar5 + 0x34) = 0;
    if (piVar2[2] == 1) {
      FUN_0306e562();
    }
    else {
      FUN_0306e538();
    }
    if (piVar2[2] == piVar2[7]) {
      FUN_0306e58c();
    }
  }
  if (*piVar4 != 0x240) {
    return;
  }
  iVar5 = *piVar2 + piVar2[2] * 4;
  if (*(int *)(iVar5 + 0x34) < 0x240) {
    return;
  }
  *(undefined4 *)(iVar5 + 0x34) = 0;
  if (piVar2[2] == 1) {
    FUN_0306e562();
  }
  else {
    FUN_0306e538();
  }
  if (piVar2[2] == piVar2[7]) {
    FUN_0306e58c();
    return;
  }
  return;
}


