/**
 * FUN_030a1286 @ 0x030a1286
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a1286(int *param_1,undefined2 *param_2)

{
  short *psVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  
  iVar5 = *param_1;
  uVar9 = param_1[1];
  uVar2 = uVar9 * 2 - iVar5;
  if (0 < (int)uVar2) {
    uVar6 = uVar2 & 1;
    if (uVar6 != 0) {
      *(short *)((int)param_1 + 0x1e) = (short)param_1[0x1a54];
    }
    uVar11 = (uint)(uVar6 != 0);
    for (; (int)uVar6 < (int)uVar2; uVar6 = uVar6 + 2) {
      iVar10 = uVar11 + 1;
      *(undefined2 *)((int)param_1 + uVar11 * 2 + 0x1e) =
           *(undefined2 *)((int)param_1 + uVar11 * 2 + 0x6950);
      uVar11 = uVar11 + 2;
      *(undefined2 *)((int)param_1 + iVar10 * 2 + 0x1e) =
           *(undefined2 *)((int)param_1 + iVar10 * 2 + 0x6950);
    }
  }
  iVar10 = *param_1;
  if (0 < iVar10) {
    iVar12 = 0;
    puVar7 = param_2;
    do {
      iVar13 = uVar2 + iVar12;
      iVar12 = iVar12 + 1;
      *(undefined2 *)((int)param_1 + iVar13 * 2 + 0x1e) = *puVar7;
      iVar10 = iVar10 + -1;
      puVar7 = puVar7 + 1;
    } while (iVar10 != 0);
  }
  if (0 < (int)uVar2) {
    iVar10 = 0;
    puVar7 = param_2 + (iVar5 - uVar2);
    do {
      iVar5 = iVar10 * 2;
      iVar10 = iVar10 + 1;
      *(undefined2 *)((int)param_1 + iVar5 + 0x6950) = *puVar7;
      uVar2 = uVar2 - 1;
      puVar7 = puVar7 + 1;
    } while (uVar2 != 0);
  }
  if (0 < (int)(uVar9 * 2)) {
    iVar10 = 0;
    iVar5 = 0;
    if (0 < (int)(uVar9 * 2)) {
      do {
        iVar5 = iVar5 + 2;
        *(short *)((int)param_1 + iVar10 * 2 + 0x1e) =
             (short)((uint)((int)*(short *)((int)param_1 + iVar10 * 2 + 0x1e) *
                            (int)*(short *)((int)param_1 + iVar10 * 2 + 0x1b80) * 2) >> 0x10);
        iVar12 = iVar10 + 1;
        *(short *)((int)param_1 + iVar12 * 2 + 0x1e) =
             (short)((uint)((int)*(short *)((int)param_1 + iVar12 * 2 + 0x1e) *
                            (int)*(short *)((int)param_1 + iVar12 * 2 + 0x1b80) * 2) >> 0x10);
        iVar10 = iVar10 + 2;
      } while (iVar5 < (int)(uVar9 * 2));
    }
  }
  uVar2 = 0;
  iVar5 = uVar9 * 2 + -1;
  if (0 < iVar5) {
    sVar3 = *(short *)((int)param_1 + 0x1e);
    iVar12 = (int)sVar3;
    iVar10 = iVar12;
    if (iVar12 < 0) {
      iVar10 = -iVar12;
    }
    if (0 < iVar10) {
      if (iVar12 < 0) {
        sVar3 = -sVar3;
      }
      uVar2 = (uint)sVar3;
    }
    sVar3 = (short)param_1[8];
    psVar1 = (short *)((int)param_1 + 0x1e);
    for (iVar10 = iVar5 >> 1; iVar10 != 0; iVar10 = iVar10 + -1) {
      iVar13 = (int)sVar3;
      sVar4 = psVar1[2];
      iVar8 = (int)sVar4;
      iVar12 = iVar13;
      if (iVar13 < 0) {
        iVar12 = -iVar13;
      }
      if ((int)uVar2 < iVar12) {
        if (iVar13 < 0) {
          sVar3 = -sVar3;
        }
        uVar2 = (uint)sVar3;
      }
      sVar3 = psVar1[3];
      iVar12 = iVar8;
      if (iVar8 < 0) {
        iVar12 = -iVar8;
      }
      if ((int)uVar2 < iVar12) {
        if (iVar8 < 0) {
          sVar4 = -sVar4;
        }
        uVar2 = (uint)sVar4;
      }
      psVar1 = psVar1 + 2;
    }
  }
  if (-1 < iVar5) {
    sVar3 = *(short *)((int)param_1 + iVar5 * 2 + 0x1e);
    iVar10 = (int)sVar3;
    iVar5 = iVar10;
    if (iVar10 < 0) {
      iVar5 = -iVar10;
    }
    if ((int)uVar2 < iVar5) {
      if (iVar10 < 0) {
        sVar3 = -sVar3;
      }
      uVar2 = (uint)sVar3;
    }
  }
  sVar3 = 0;
  if (0xffff < uVar2) {
    uVar2 = uVar2 >> 0x10;
    sVar3 = 0x10;
  }
  if (0xff < uVar2) {
    uVar2 = uVar2 >> 8;
    sVar3 = sVar3 + 8;
  }
  if (0xf < uVar2) {
    uVar2 = uVar2 >> 4;
    sVar3 = sVar3 + 4;
  }
  if (3 < uVar2) {
    uVar2 = uVar2 >> 2;
    sVar3 = sVar3 + 2;
  }
  param_1[0x1c98] = 0xe - (short)(sVar3 + (ushort)(1 < uVar2));
  if (0 < (int)(uVar9 * 2)) {
    iVar10 = 0;
    iVar5 = 0;
    if (0 < (int)(uVar9 * 2)) {
      do {
        *(short *)((int)param_1 + iVar10 * 2 + 0x1e) =
             *(short *)((int)param_1 + iVar10 * 2 + 0x1e) << (sbyte)param_1[0x1c98];
        iVar12 = iVar10 + 1;
        iVar10 = iVar10 + 2;
        iVar5 = iVar5 + 2;
        *(short *)((int)param_1 + iVar12 * 2 + 0x1e) =
             *(short *)((int)param_1 + iVar12 * 2 + 0x1e) << (sbyte)param_1[0x1c98];
      } while (iVar5 < (int)(uVar9 * 2));
    }
  }
  FUN_030a25d0(param_1[0x1c96],(int)param_1 + 0x1e,(int)param_1 + 0x91e);
  param_1[0x488] = (int)*(short *)((int)param_1 + 0x91e) * (int)*(short *)((int)param_1 + 0x91e);
  if (0 < (int)(uVar9 - 1)) {
    iVar5 = 0;
    if ((int)uVar9 < 2) {
      uVar2 = 0;
    }
    else {
      uVar2 = ~uVar9 & 1;
      if (uVar2 != 0) {
        param_1[0x489] =
             (int)*(short *)((int)param_1 + 0x922) * (int)*(short *)((int)param_1 + 0x922) +
             (int)(short)param_1[0x248] * (int)(short)param_1[0x248];
        iVar5 = 1;
      }
    }
    for (; (int)uVar2 < (int)(uVar9 - 1); uVar2 = uVar2 + 2) {
      iVar10 = (int)*(short *)((int)param_1 + iVar5 * 4 + 0x922);
      param_1[iVar5 + 0x489] =
           iVar10 * iVar10 + (int)(short)param_1[iVar5 + 0x248] * (int)(short)param_1[iVar5 + 0x248]
      ;
      iVar10 = (int)*(short *)((int)param_1 + (iVar5 + 1) * 4 + 0x922);
      param_1[iVar5 + 0x48a] =
           iVar10 * iVar10 + (int)(short)param_1[iVar5 + 0x249] * (int)(short)param_1[iVar5 + 0x249]
      ;
      iVar5 = iVar5 + 2;
    }
  }
  if (0 < (int)uVar9) {
    uVar2 = uVar9 & 1;
    if (uVar2 != 0) {
      param_1[0x488] =
           param_1[0x488] + ((1 << ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff)) >> 1) >>
           ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff);
    }
    uVar6 = (uint)(uVar2 != 0);
    for (; (int)uVar2 < (int)uVar9; uVar2 = uVar2 + 2) {
      param_1[uVar6 + 0x488] =
           param_1[uVar6 + 0x488] + ((1 << ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff)) >> 1) >>
           ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff);
      param_1[uVar6 + 0x489] =
           param_1[uVar6 + 0x489] + ((1 << ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff)) >> 1) >>
           ((uint)*(byte *)(param_1 + 0x1c98) << 1 & 0xff);
      uVar6 = uVar6 + 2;
    }
  }
  FUN_030a2d50(param_1[2],param_1 + 0x488,param_1 + uVar9 + 0x488);
  return;
}


