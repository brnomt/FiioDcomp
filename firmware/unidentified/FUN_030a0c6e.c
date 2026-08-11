/**
 * FUN_030a0c6e @ 0x030a0c6e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a0c6e(int param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  
  uVar1 = DAT_030a10b0;
  iVar11 = 0;
  if (param_2 < 1) {
    return;
  }
  do {
    sVar3 = (short)(((short)iVar11 * 0x7fff) / (int)(short)param_2);
    iVar5 = (int)sVar3;
    bVar10 = false;
    iVar6 = iVar5;
    if (0x1fff < iVar5) {
      if (iVar5 < 0x4000) {
        iVar6 = (int)(short)(0x4000 - sVar3);
        bVar10 = true;
      }
      else {
        if (iVar5 < 0x6000) {
          sVar3 = sVar3 + -0x4000;
        }
        else {
          sVar3 = -0x8000 - sVar3;
        }
        iVar6 = (int)sVar3;
        bVar10 = iVar5 < 0x6000;
      }
    }
    uVar7 = DAT_030a10b4 * iVar6 >> 0x10;
    uVar9 = uVar7 & 0x7fff;
    uVar8 = uVar9 * 4;
    if (0x10000 < uVar8) {
      uVar8 = uVar9 * -4 + 0x20000;
    }
    sVar3 = (short)uVar1;
    if ((uVar8 & 0x7fff) == 0) {
      if ((uVar8 & 0xffff) == 0) {
        iVar6 = DAT_030a10b8;
        if ((uVar8 & 0x1ffff) == 0) {
          iVar6 = 0x7fff;
        }
      }
      else {
        iVar6 = 0;
      }
    }
    else {
      sVar2 = (short)uVar8;
      if ((int)uVar8 < 0x8000) {
        iVar6 = ((int)sVar2 * (int)sVar2 + 0x4000) * 2 >> 0x10;
        iVar6 = (0x7fff - iVar6) +
                ((short)(sVar3 + (short)(((iVar6 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar6 +
                                         0x4000 >> 0xf)) * iVar6 + 0x4000 >> 0xf);
        if (0x7ffe < iVar6) {
          iVar6 = 0x7ffe;
        }
        sVar2 = (short)iVar6 + 1;
      }
      else {
        iVar6 = ((int)-sVar2 * (int)-sVar2 + 0x4000) * 2 >> 0x10;
        iVar6 = (0x7fff - iVar6) +
                ((short)(sVar3 + (short)(((iVar6 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar6 +
                                         0x4000 >> 0xf)) * iVar6 + 0x4000 >> 0xf);
        if (0x7ffe < iVar6) {
          iVar6 = 0x7ffe;
        }
        sVar2 = -((short)iVar6 + 1);
      }
      iVar6 = (int)sVar2;
    }
    uVar7 = uVar7 & 0x7fff;
    uVar9 = uVar7 * 4;
    if (0x10000 < uVar9) {
      uVar9 = uVar7 * -4 + 0x20000;
    }
    if ((uVar9 & 0x7fff) == 0) {
      if ((uVar9 & 0xffff) == 0) {
        iVar5 = DAT_030a10b8;
        if ((uVar9 & 0x1ffff) == 0) {
          iVar5 = 0x7fff;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else {
      sVar2 = (short)uVar9;
      if ((int)uVar9 < 0x8000) {
        iVar5 = ((int)sVar2 * (int)sVar2 + 0x4000) * 2 >> 0x10;
        iVar5 = (0x7fff - iVar5) +
                ((short)(sVar3 + (short)(((iVar5 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar5 +
                                         0x4000 >> 0xf)) * iVar5 + 0x4000 >> 0xf);
        if (0x7ffe < iVar5) {
          iVar5 = 0x7ffe;
        }
        sVar3 = (short)iVar5 + 1;
      }
      else {
        iVar5 = ((int)-sVar2 * (int)-sVar2 + 0x4000) * 2 >> 0x10;
        iVar5 = (0x7fff - iVar5) +
                ((short)(sVar3 + (short)(((iVar5 * -0x272 + 0x4000 >> 0xf) + 0x2055) * iVar5 +
                                         0x4000 >> 0xf)) * iVar5 + 0x4000 >> 0xf);
        if (0x7ffe < iVar5) {
          iVar5 = 0x7ffe;
        }
        sVar3 = -((short)iVar5 + 1);
      }
      iVar5 = (int)sVar3;
    }
    iVar6 = (int)(short)(0x4000 - (short)(iVar6 * 0x4000 + 0x4000 >> 0xf)) *
            (int)(short)(0x4000 - (short)(iVar5 * 0x4000 + 0x4000 >> 0xf)) * 2;
    iVar5 = iVar6 >> 0x10;
    if (bVar10) {
      iVar5 = (int)(short)(0x7fff - (short)((uint)iVar6 >> 0x10));
    }
    uVar4 = FUN_030a0b0c(iVar5 << 0xf);
    *(undefined2 *)(param_1 + iVar11 * 2) = uVar4;
    iVar11 = iVar11 + 1;
  } while (iVar11 < param_2);
  return;
}


