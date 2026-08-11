/**
 * FUN_03050c3e @ 0x03050c3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03050c3e(void)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  int extraout_r2;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint unaff_r9;
  bool bVar12;
  
  iVar4 = DAT_03050df0;
  iVar8 = *(int *)(DAT_03050e00 + 4);
  uVar10 = *(uint *)(DAT_03050df0 + 0x3c);
  bVar3 = false;
  uVar11 = uVar10 << 1;
  *(undefined2 *)(DAT_03050e04 + 2) = 0;
  if ((*(byte *)(iVar4 + 0xc) & 2) == 0) {
    return;
  }
  if ((*(byte *)(iVar4 + 10) & 2) == 0) {
    return;
  }
  iVar9 = *(int *)(iVar4 + 0x40);
  if (*(char *)(iVar4 + 2) == '\x01') {
    if (*(char *)(DAT_03050df0 + 3) != '\0') {
      unaff_r9 = DAT_03050e08[2];
      uVar7 = unaff_r9 >> 2;
      if ((unaff_r9 & 3) != 0) {
        uVar7 = uVar7 + 1;
      }
      if (*(int *)(DAT_03050e0c + 8) + unaff_r9 < 0xc001) {
        uVar6 = FUN_03032360();
        FUN_0303238c(uVar6,*DAT_03050e08,DAT_03050e14,uVar7);
        bVar3 = true;
        iVar8 = extraout_r2;
      }
    }
  }
  else if (*(char *)(DAT_03050df0 + 3) != '\0') {
    *(undefined1 *)(iVar4 + 1) = 1;
    return;
  }
  if (*(int *)(iVar4 + 0x20) == 1) {
    if (*(int *)(iVar4 + 0x14) == 3) {
      iVar8 = 0;
      uVar11 = 0;
      if (uVar10 >> 1 != 0) {
        do {
          if (*(int *)(iVar4 + 0x24) == 0xf) {
            *(undefined2 *)(iVar9 + uVar11 * 2) = *(undefined2 *)(iVar9 + iVar8 * 4);
            iVar8 = iVar8 + 1;
          }
          else {
            *(undefined4 *)(iVar9 + uVar11 * 4) = *(undefined4 *)(iVar9 + uVar11 * 8);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar10 >> 1);
      }
    }
    else {
      if (*(int *)(iVar4 + 0x14) != 4) goto LAB_03050de0;
      iVar8 = 0;
      uVar11 = 0;
      if (uVar10 >> 1 != 0) {
        do {
          if (*(int *)(iVar4 + 0x24) == 0xf) {
            iVar1 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(undefined2 *)(iVar9 + uVar11 * 2) = *(undefined2 *)(iVar9 + iVar1 + 4);
          }
          else {
            *(undefined4 *)(iVar9 + uVar11 * 4) = *(undefined4 *)(iVar9 + uVar11 * 8 + 4);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar10 >> 1);
      }
    }
    uVar11 = uVar10 & 0xfffffffe;
  }
  else if (*(int *)(iVar4 + 0x20) == 2) {
    if (*(int *)(iVar4 + 0x14) == 3) {
      uVar11 = 0;
      if (uVar10 >> 1 != 0) {
        do {
          uVar7 = *(uint *)(iVar4 + 0x24);
          bVar12 = uVar7 == 0xf;
          if (bVar12) {
            uVar7 = (uint)*(ushort *)(iVar9 + uVar11 * 4);
            iVar8 = iVar9 + uVar11 * 4;
          }
          if (bVar12) {
            *(short *)(iVar8 + 2) = (short)uVar7;
          }
          else {
            iVar8 = *(int *)(iVar9 + uVar11 * 8);
            uVar7 = iVar9 + uVar11 * 8;
          }
          if (!bVar12) {
            *(int *)(uVar7 + 4) = iVar8;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar10 >> 1);
      }
    }
    else {
      if (*(int *)(iVar4 + 0x14) != 4) goto LAB_03050de0;
      uVar11 = 0;
      if (uVar10 >> 1 != 0) {
        do {
          if (*(int *)(iVar4 + 0x24) == 0xf) {
            *(undefined2 *)(iVar9 + uVar11 * 4) = *(undefined2 *)(iVar9 + uVar11 * 4 + 4);
          }
          else {
            *(undefined4 *)(iVar9 + uVar11 * 8) = *(undefined4 *)(iVar9 + uVar11 * 8 + 4);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar10 >> 1);
      }
    }
    uVar11 = uVar10 << 1;
  }
LAB_03050de0:
  puVar5 = DAT_03051214;
  *DAT_03051214 = 0;
  uVar6 = FUN_03032360();
  *(uint *)(puVar5 + 2) = uVar11;
  FUN_0303238c(uVar6,iVar9,*(undefined4 *)(DAT_0305121c + 4),uVar11 >> 2);
  *(undefined1 *)(iVar4 + 2) = 0;
  if (bVar3) {
    sVar2 = puVar5[1];
    while (sVar2 == 0) {
      FUN_03027f38();
      sVar2 = puVar5[1];
    }
    FUN_030505f8(DAT_03051220,unaff_r9);
  }
  if (*(char *)(iVar4 + 3) != '\0') {
    FUN_030290c0(0x16);
    *(undefined4 *)(iVar4 + 0x30) = 0;
    if (*(int *)(iVar4 + 0x34) == 0) {
      FUN_03050786();
    }
    *(undefined4 *)(iVar4 + 0x34) = 1;
    FUN_03029064(0x16);
    return;
  }
  *(undefined1 *)(iVar4 + 3) = 1;
  *(undefined4 *)(iVar4 + 0x30) = 0;
  return;
}


