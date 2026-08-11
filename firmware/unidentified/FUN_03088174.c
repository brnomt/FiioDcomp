/**
 * FUN_03088174 @ 0x03088174
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03088174(int param_1)

{
  short *psVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  iVar6 = *(int *)(param_1 + 0xd8);
  bVar8 = **(char **)(*(int *)(iVar6 + 0xc0) + 0x10) != '\0';
  uVar5 = (uint)*(ushort *)(param_1 + 0x26);
  if (uVar5 != 0) {
    piVar3 = (int *)(iVar6 + 0x30);
    uVar7 = uVar5;
    do {
      if (*piVar3 == 0) {
        bVar8 = false;
      }
      piVar3 = piVar3 + 0x3f;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  if (bVar8 && uVar5 != 0) {
    piVar3 = (int *)(iVar6 + 0x3c);
    uVar7 = uVar5;
    do {
      if (*piVar3 != 0) {
        bVar8 = false;
      }
      piVar3 = piVar3 + 0x3f;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (bVar8) {
    iVar6 = *(int *)(param_1 + 0x150);
  }
  else {
    psVar1 = *(short **)(*(int *)(iVar6 + 0xc0) + 8);
    iVar4 = (int)psVar1[-1];
    sVar2 = *psVar1;
    iVar6 = (int)sVar2;
    if (iVar4 < iVar6) {
      iVar4 = iVar4 + iVar6;
      sVar2 = (short)((uint)((iVar4 - (iVar4 >> 0x1f)) * 0x8000) >> 0x10);
    }
    iVar6 = ((int)sVar2 + *(int *)(param_1 + 0x154) / 2) - iVar6 / 2;
    *(undefined4 *)(param_1 + 0x4c) = 1;
  }
  if (uVar5 != 0) {
    uVar5 = uVar5 & 1;
    bVar8 = (*(ushort *)(param_1 + 0x26) & 1) != 0;
    if (bVar8) {
      **(int **)(param_1 + 0xfc) = iVar6;
    }
    uVar7 = (uint)bVar8;
    if (uVar5 < *(ushort *)(param_1 + 0x26)) {
      do {
        uVar5 = uVar5 + 2;
        *(int *)(*(int *)(param_1 + 0xfc) + uVar7 * 4) = iVar6;
        *(int *)(*(int *)(param_1 + 0xfc) + (uVar7 + 1) * 4) = iVar6;
        uVar7 = uVar7 + 2;
      } while ((int)uVar5 < (int)(uint)*(ushort *)(param_1 + 0x26));
    }
  }
  if (*(char *)(param_1 + 0x48) == '\x03') {
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  return;
}


