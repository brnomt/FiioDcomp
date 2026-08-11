/**
 * FUN_030041b4 @ 0x030041b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030041b4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  ushort *puVar2;
  char *pcVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint unaff_r8;
  bool bVar10;
  uint local_28;
  
  puVar2 = DAT_03004320;
  bVar1 = true;
  local_28 = param_4;
  if (param_1 == 0) {
    FUN_0301309e(&local_28);
    uVar8 = local_28 / 1000;
  }
  else {
    uVar8 = *(uint *)(DAT_03004320 + 8);
  }
  if ((uVar8 < *(uint *)(puVar2 + 8)) && (*(uint *)(puVar2 + 6) <= uVar8)) {
    return;
  }
  if (*DAT_03004324 == 3) {
    return;
  }
  *puVar2 = *puVar2 & 0xfffe;
  pcVar3 = DAT_03004328;
  puVar2[2] = 0;
  FUN_02fe421e(0,0,(int)*pcVar3);
  uVar4 = FUN_02fe3d26(DAT_0300432c,0x800,(int)*pcVar3);
  puVar2[1] = uVar4;
  if (uVar4 < 0x800) {
    *puVar2 = *puVar2 | 1;
  }
  uVar9 = 0;
  uVar7 = 0xffffffff;
  do {
    iVar5 = FUN_03004612(&local_28);
    if (local_28 == 0xffffffff) {
LAB_03004258:
      bVar10 = uVar8 <= local_28;
      if (local_28 <= uVar8) {
        bVar10 = local_28 <= uVar9;
      }
      if (!bVar10) {
        uVar9 = local_28;
        unaff_r8 = local_28;
      }
    }
    else {
      if (uVar8 < local_28) {
        if (local_28 < uVar7) {
          uVar7 = local_28;
        }
        if (bVar1) {
          bVar1 = false;
          uVar7 = local_28;
        }
      }
      if (local_28 != 0) goto LAB_03004258;
    }
  } while (iVar5 != -1);
  *(uint *)(puVar2 + 8) = uVar7;
  if (*(uint *)(puVar2 + 6) == unaff_r8) {
    return;
  }
  *(uint *)(puVar2 + 6) = unaff_r8;
  *puVar2 = *puVar2 & 0xfffe;
  puVar2[2] = 0;
  FUN_02fe421e(0,0,(int)*pcVar3);
  uVar4 = FUN_02fe3d26(DAT_0300432c,0x800,(int)*pcVar3);
  puVar2[1] = uVar4;
  if (uVar4 < 0x800) {
    *puVar2 = *puVar2 | 1;
  }
  FUN_03004456(unaff_r8);
  pcVar3 = DAT_03004330;
  pcVar6 = DAT_03004330 + 0x1000;
  if (puVar2[3] == 0) {
    if (*DAT_03004330 != '\0') {
      FUN_02fed304(DAT_03004334 + -0x1000,DAT_03004334,0x400);
      goto LAB_03004316;
    }
  }
  else if (*DAT_03004330 != '\0') {
    FUN_02fed118(DAT_03004330,pcVar6,0x400,3);
    goto LAB_03004316;
  }
  pcVar6[0] = ' ';
  pcVar6[1] = '\0';
  pcVar3[0x1002] = '\0';
  pcVar3[0x1003] = '\0';
LAB_03004316:
  FUN_02ff2de4(0x4f);
  return;
}


