/**
 * FUN_0303faa8 @ 0x0303faa8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0303faa8(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  undefined1 *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  uint local_28;
  
  uVar12 = DAT_0303fe28;
  puVar5 = DAT_0303fe24;
  puVar4 = DAT_0303fe20;
  iVar3 = DAT_0303fe1c;
  if (*(short *)(DAT_0303fe1c + 0xf2) == 10) {
    uVar11 = 1;
  }
  else if (*(short *)(DAT_0303fe1c + 0xf2) == 8) {
    uVar11 = 2;
  }
  else {
    uVar11 = 3;
  }
  *DAT_0303fe20 = 0xffffffff;
  *puVar5 = *(undefined1 *)(iVar3 + 0x5c);
  local_28 = uVar12;
  uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),*(int *)(iVar3 + 0x38) + -1,uVar11
                      );
  *puVar4 = uVar9;
  if (uVar9 < 9) {
    FUN_0303f9c0(iVar3 + 0x1c,DAT_0303fe2c);
    piVar2 = DAT_0303fe14;
    iVar13 = *DAT_0303fe14;
    FUN_0300b044();
    if (*piVar2 != 3) {
      FUN_0301f6e4(iVar3 + 0x1c,*puVar4);
    }
    FUN_0303f9c0(iVar3 + 0x1c,DAT_0303fe2c);
    if (*piVar2 == 0xff) {
      if (iVar13 == 0xff) {
        FUN_03024b78(s_ERROR____CurrentCodec____0x_02x_0303fe30);
        return 0xffffffff;
      }
    }
    else {
      if (*piVar2 == 8) {
        FUN_0301ea36(0x115);
        FUN_0300b044();
        FUN_0300fe2e(0,0,(int)(char)*puVar4);
        if (*piVar2 == 8) {
          local_28 = uVar12;
          uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                               *(int *)(iVar3 + 0x38) + -1,uVar11);
          *DAT_0303fe54 = uVar9;
          if (8 < uVar9) {
            return 0xffffffff;
          }
        }
      }
      if (*piVar2 == 9) {
        FUN_0301ea36(0x115);
        FUN_0300b044();
        FUN_0300fe2e(0,0,(int)(char)*puVar4);
        if (*piVar2 == 9) {
          local_28 = uVar12;
          uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                               *(int *)(iVar3 + 0x38) + -1,uVar11);
          *DAT_0303fe58 = uVar9;
          if (8 < uVar9) {
            return 0xffffffff;
          }
        }
      }
      puVar7 = DAT_0303fe60;
      puVar6 = DAT_0303fe5c;
      if (*piVar2 == 2) {
        FUN_0301ea36(0x115);
        FUN_0300b044();
        FUN_0300fe2e(0,0,(int)(char)*puVar4);
        if (*piVar2 == 2) {
          *puVar5 = *(undefined1 *)(iVar3 + 0x5c);
          local_28 = uVar12;
          uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                               *(int *)(iVar3 + 0x38) + -1,uVar11);
          *puVar6 = uVar9;
          *puVar5 = *(undefined1 *)(iVar3 + 0x5c);
          local_28 = uVar12;
          uVar10 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                                *(int *)(iVar3 + 0x38) + -1,uVar11);
          *puVar7 = uVar10;
          uVar9 = *puVar6;
          if (*puVar6 < 9) {
            uVar9 = uVar10;
          }
          if (8 < uVar9) {
            return 0xffffffff;
          }
        }
      }
      if (*piVar2 == 7) {
        FUN_0301ea36(0x115);
        FUN_0300b044();
        FUN_0300fe2e(0,0,(int)(char)*puVar4);
        if (*piVar2 == 7) {
          *puVar5 = *(undefined1 *)(iVar3 + 0x5c);
          local_28 = uVar12;
          uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                               *(int *)(iVar3 + 0x38) + -1,uVar11);
          *puVar6 = uVar9;
          *puVar5 = *(undefined1 *)(iVar3 + 0x5c);
          local_28 = uVar12;
          uVar9 = FUN_0300f34e(iVar3 + 0x14,*(undefined4 *)(iVar3 + 0x34),
                               *(int *)(iVar3 + 0x38) + -1,uVar11);
          *puVar7 = uVar9;
          uVar12 = *puVar6;
          if (*puVar6 < 9) {
            uVar12 = uVar9;
          }
          if (8 < uVar12) {
            return 0xffffffff;
          }
        }
      }
    }
    uVar8 = DAT_0303fe64;
    bVar14 = *(int *)(iVar3 + 0x44) == 0;
    sVar1 = 0;
    if (!bVar14) {
      sVar1 = *(short *)(iVar3 + 0xf2);
    }
    if ((bVar14 || sVar1 == 10) || sVar1 == 99) {
      FUN_0301198c(*(undefined4 *)(iVar3 + 0x34),*(int *)(iVar3 + 0x38) + -1,uVar11,DAT_0303fe68);
    }
    else {
      FUN_0301ece0(DAT_0303fe64,
                   ((uint)*(ushort *)(iVar3 + 2) +
                   (uint)*(ushort *)(iVar3 + (uint)*(ushort *)(iVar3 + 0xf4) * 2 + 0x110)) * 2 +
                   *(int *)(iVar3 + 0xfc) * 0x200 + -2,2,&local_28);
      uVar12 = local_28 & 0xffff;
      FUN_0301ece0(uVar8,*(int *)(iVar3 + 0xf8) * 0x200 + uVar12 * 0x800 + 0x400,0x80,DAT_0303fe68);
      iVar13 = DAT_0303fe6c;
      FUN_0301ece0(uVar8,*(int *)(iVar3 + 0xf8) * 0x200 + uVar12 * 0x800 + 0x500,0x100,
                   DAT_0303fe6c + 0x15e);
      FUN_0301ece0(uVar8,*(int *)(iVar3 + 0xf8) * 0x200 + uVar12 * 0x800 + 0x600,0x100,
                   iVar13 + 0x25c);
    }
    return 0;
  }
  return 0xffffffff;
}


