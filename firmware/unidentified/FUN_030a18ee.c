/**
 * FUN_030a18ee @ 0x030a18ee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a18ee(int *param_1,short *param_2)

{
  int iVar1;
  longlong lVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  uint uVar13;
  int iVar14;
  short *psVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  short local_17e8 [599];
  short asStack_133a [601];
  int local_e88;
  uint local_e80;
  uint *local_e70;
  int local_e68;
  uint local_e64;
  int *local_e60;
  int *local_e5c;
  short *local_e58;
  short local_e50 [600];
  short local_9a0 [600];
  short local_4f0 [608];
  int *piStack_30;
  short *local_2c;
  
  uVar13 = param_1[1];
  local_e80 = uVar13 * 2 - *param_1;
  local_e64 = *param_1 - local_e80;
  local_e5c = param_1 + 0x1c00;
  piVar9 = param_1 + 0x488;
  iVar4 = param_1[0x1c94] + 1;
  param_1[0x1c94] = iVar4;
  if (20000 < iVar4) {
    iVar4 = 20000;
  }
  param_1[0x1c94] = iVar4;
  param_1[0x1c95] = param_1[0x1c95] + 1;
  iVar4 = (int)(short)(0x7fff / (int)(short)iVar4);
  if (iVar4 < 0x3d7) {
    iVar4 = 0x3d7;
  }
  iVar16 = uVar13 + 0x18;
  iVar14 = (int)(short)(0x7fff - (short)iVar4);
  if (0 < iVar16) {
    uVar5 = uVar13 & 1;
    if (uVar5 != 0) {
      param_1[0x17fc] = 0;
    }
    uVar17 = (uint)(uVar5 != 0);
    for (; (int)uVar5 < iVar16; uVar5 = uVar5 + 2) {
      param_1[uVar17 + 0x17fc] = 0;
      param_1[uVar17 + 0x17fd] = 0;
      uVar17 = uVar17 + 2;
    }
  }
  piStack_30 = param_1;
  local_2c = param_2;
  FUN_030a1286(param_1,param_2);
  FUN_030a1596(param_1);
  if ((int)uVar13 < 1) {
    uVar5 = 0;
  }
  else {
    uVar5 = uVar13 & 1;
    iVar10 = 0;
    if (uVar5 != 0) {
      do {
        if ((param_1[iVar10 + 0x1490] == 0) ||
           (param_1[iVar10 + 0x488] < param_1[iVar10 + 0x920] + 0x40 >> 7)) {
          uVar17 = param_1[iVar10 + 0x920];
          uVar17 = ((int)((uVar17 & 0x7fff) * iVar14) >> 0xf) +
                   ((int)(iVar4 * (param_1[iVar10 + 0x488] & 0xffU) * 0x80) >> 0xf) +
                   iVar4 * (short)((param_1[iVar10 + 0x488] << 7) >> 0xf) +
                   ((int)(uVar17 << 1) >> 0x10) * iVar14;
          if ((int)uVar17 < 0) {
            uVar17 = 0;
          }
          param_1[iVar10 + 0x920] = uVar17;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar5);
    }
  }
  for (; (int)uVar5 < (int)uVar13; uVar5 = uVar5 + 2) {
    if ((param_1[uVar5 + 0x1490] == 0) ||
       (param_1[uVar5 + 0x488] < param_1[uVar5 + 0x920] + 0x40 >> 7)) {
      local_e70 = (uint *)(param_1 + uVar5 + 0x920);
      uVar17 = ((int)((*local_e70 & 0x7fff) * iVar14) >> 0xf) +
               ((int)(iVar4 * (param_1[uVar5 + 0x488] & 0xffU) * 0x80) >> 0xf) +
               iVar4 * (short)((param_1[uVar5 + 0x488] << 7) >> 0xf) +
               ((int)(*local_e70 << 1) >> 0x10) * iVar14;
      if ((int)uVar17 < 0) {
        uVar17 = 0;
      }
      *local_e70 = uVar17;
    }
    if ((param_1[uVar5 + 0x1491] == 0) ||
       (param_1[uVar5 + 0x489] < param_1[uVar5 + 0x921] + 0x40 >> 7)) {
      uVar17 = param_1[uVar5 + 0x921];
      uVar17 = ((int)((uVar17 & 0x7fff) * iVar14) >> 0xf) +
               ((int)(iVar4 * (param_1[uVar5 + 0x489] & 0xffU) * 0x80) >> 0xf) +
               iVar4 * (short)((param_1[uVar5 + 0x489] << 7) >> 0xf) +
               ((int)(uVar17 << 1) >> 0x10) * iVar14;
      if ((int)uVar17 < 0) {
        uVar17 = 0;
      }
      param_1[uVar5 + 0x921] = uVar17;
    }
  }
  local_e60 = param_1 + uVar13;
  FUN_030a2d50(param_1[2],param_1 + 0x920,local_e60 + 0x920);
  if ((local_e5c[0x94] == 1) && (0 < iVar16)) {
    iVar14 = uVar13 + 0x18;
    piVar6 = piVar9;
    iVar4 = 0;
    do {
      param_1[iVar4 + 0xb78] = *piVar6;
      iVar14 = iVar14 + -1;
      piVar6 = piVar6 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar14 != 0);
  }
  iVar4 = 0;
  if (0 < iVar16) {
    do {
      iVar7 = (param_1[iVar4 + 0x920] + 0x40 >> 7) + 1 + param_1[iVar4 + 0x17fc];
      iVar14 = piVar9[iVar4];
      iVar10 = iVar7;
      if (iVar7 <= iVar14 >> 7) {
        iVar10 = 0x7fff;
      }
      if (iVar14 >> 7 < iVar7) {
        if (0x7fffff < iVar10) {
          iVar14 = iVar14 >> 8;
          iVar10 = iVar7 >> 8;
        }
        if (0x7ffff < iVar10) {
          iVar14 = iVar14 >> 4;
          iVar10 = iVar10 >> 4;
        }
        if (0x7fff < iVar10) {
          iVar14 = iVar14 >> 4;
          iVar10 = iVar10 >> 4;
        }
        iVar10 = (int)(short)((((iVar10 << 0x10) >> 0x11) + iVar14 * 0x100) / (int)(short)iVar10);
      }
      sVar3 = (short)iVar10 + -0x100;
      iVar14 = (int)sVar3;
      local_9a0[iVar4] = sVar3;
      if (0x63ff < iVar14) {
        iVar14 = 0x6400;
      }
      local_9a0[iVar4] = (short)iVar14;
      iVar8 = param_1[iVar4 + 0xb78];
      iVar11 = iVar8 + iVar7;
      iVar10 = iVar8 >> 0xf;
      iVar19 = iVar8;
      if (iVar11 <= iVar10) {
        iVar19 = 0x7fff;
      }
      iVar1 = iVar8 >> 8;
      if (iVar10 < iVar11) {
        iVar18 = iVar11;
        if (0x7fffff < iVar11) {
          iVar18 = iVar11 >> 8;
          iVar19 = iVar1;
        }
        if (0x7ffff < iVar18) {
          iVar19 = iVar19 >> 4;
          iVar18 = iVar18 >> 4;
        }
        if (0x7fff < iVar18) {
          iVar19 = iVar19 >> 4;
          iVar18 = iVar18 >> 4;
        }
        iVar19 = (int)(short)((iVar19 * 0x7fff) / (int)(short)iVar18);
      }
      if (iVar10 < iVar11) {
        iVar10 = iVar8;
        if (0x7fffff < iVar11) {
          iVar11 = iVar11 >> 8;
          iVar10 = iVar1;
        }
        if (0x7ffff < iVar11) {
          iVar10 = iVar10 >> 4;
          iVar11 = iVar11 >> 4;
        }
        if (0x7fff < iVar11) {
          iVar10 = iVar10 >> 4;
          iVar11 = iVar11 >> 4;
        }
        iVar10 = (int)(short)((iVar10 * 0x7fff) / (int)(short)iVar11);
      }
      else {
        iVar10 = 0x7fff;
      }
      sVar3 = (short)((iVar19 * iVar10 * 2 >> 0x10) * 0x71ec >> 0xf) + 0xccd;
      if (iVar8 >> 7 < iVar7) {
        if (0x7fffff < iVar7) {
          iVar7 = iVar7 >> 8;
          iVar8 = iVar1;
        }
        if (0x7ffff < iVar7) {
          iVar8 = iVar8 >> 4;
          iVar7 = iVar7 >> 4;
        }
        if (0x7fff < iVar7) {
          iVar8 = iVar8 >> 4;
          iVar7 = iVar7 >> 4;
        }
        iVar10 = (int)(short)((((iVar7 << 0x10) >> 0x11) + iVar8 * 0x100) / (int)(short)iVar7);
      }
      else {
        iVar10 = 0x7fff;
      }
      if (iVar14 < 0) {
        iVar14 = 0;
      }
      iVar14 = (sVar3 * iVar14 + (short)(0x7fff - sVar3) * iVar10 + 0x4000) * 2;
      iVar10 = iVar14 >> 0x10;
      asStack_133a[iVar4 + 1] = (short)((uint)iVar14 >> 0x10);
      if (0x63ff < iVar10) {
        iVar10 = 0x6400;
      }
      asStack_133a[iVar4 + 1] = (short)iVar10;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar16);
  }
  *(short *)(param_1 + 0x16d0) =
       (short)((uint)(((short)param_1[0x16d0] * 0x599a + asStack_133a[1] * 0x2666 + 0x4000) * 2) >>
              0x10);
  if (0 < (int)(uVar13 - 2)) {
    iVar10 = 0;
    iVar7 = uVar13 - 2;
    iVar4 = (int)asStack_133a[2];
    iVar14 = (int)asStack_133a[1];
    psVar12 = asStack_133a + 3;
    do {
      iVar19 = iVar4;
      psVar15 = (short *)((int)param_1 + iVar10 * 2 + 0x5b42);
      sVar3 = *psVar12;
      *psVar15 = (short)((uint)((iVar19 * 0x1333 + *psVar15 * 0x599a + iVar14 * 0x99a +
                                 sVar3 * 0x99a + 0x4000) * 2) >> 0x10);
      iVar10 = iVar10 + 1;
      iVar7 = iVar7 + -1;
      iVar4 = (int)sVar3;
      iVar14 = iVar19;
      psVar12 = psVar12 + 1;
    } while (iVar7 != 0);
  }
  iVar14 = 0;
  iVar4 = 0x19;
  psVar12 = asStack_133a + uVar13;
  do {
    psVar15 = (short *)((int)param_1 + (uVar13 + iVar14) * 2 + 0x5b3e);
    iVar14 = iVar14 + 1;
    *psVar15 = (short)((uint)((*psVar15 * 0x599a + *psVar12 * 0x2666 + 0x4000) * 2) >> 0x10);
    iVar4 = iVar4 + -1;
    psVar12 = psVar12 + 1;
  } while (iVar4 != 0);
  iVar14 = 0;
  psVar12 = (short *)((int)param_1 + uVar13 * 2 + 0x5b40);
  iVar4 = (int)*psVar12;
  iVar10 = 0xb;
  sVar3 = *(short *)((int)param_1 + uVar13 * 2 + 0x5b42);
  do {
    iVar4 = iVar4 + sVar3;
    sVar3 = psVar12[3];
    iVar14 = iVar14 + psVar12[2];
    iVar10 = iVar10 + -1;
    psVar12 = psVar12 + 2;
  } while (iVar10 != 0);
  lVar2 = (longlong)DAT_030a2224 *
          (longlong)(iVar4 + iVar14 + (int)*(short *)((int)param_1 + (uVar13 + 0x17) * 2 + 0x5b40));
  iVar4 = (int)(short)((short)(int)(lVar2 >> 0x22) - (short)(lVar2 >> 0x3f));
  if (iVar4 < 2) {
    iVar4 = 1;
  }
  sVar3 = (short)((short)(0xfffe00 /
                         (int)(short)((short)((uint)((short)(0x7fff / iVar4) * 0x999a) >> 0x10) +
                                     0x200)) * 0x7312 >> 0xf) + 0xccd;
  local_e88 = (int)sVar3;
  local_e58 = local_4f0 + uVar13;
  FUN_030a0f42(param_1[3],
               (local_e88 * (short)param_1[5] +
                (int)(short)(0x7fff - sVar3) * (int)(short)param_1[4] + 0x4000) * 2 >> 0x10,
               local_e60 + 0x920,local_e60 + 0x17fc,local_e58,0x18);
  uVar5 = uVar13;
  do {
    iVar4 = asStack_133a[uVar5 + 1] + 0x100;
    iVar10 = (int)(short)(((iVar4 * 0x10000 >> 0x11) + asStack_133a[uVar5 + 1] * 0x8000) /
                         (int)(short)iVar4);
    uVar17 = local_9a0[uVar5] * 8 + 0x800;
    iVar14 = ((int)uVar17 >> 0xf) * iVar10 + ((int)((uVar17 & 0x7fff) * iVar10 + 0x4000) >> 0xf);
    iVar4 = iVar14 >> 10;
    if (iVar4 < 0) {
      uVar17 = 0x7fff;
    }
    else if (iVar4 < 0x14) {
      local_e68 = (int)(short)(((short)iVar14 - (short)(iVar4 << 10)) * 0x20);
      iVar7 = FUN_030a0b0c(iVar14 * 0x8000 + 0x1a37);
      uVar17 = (int)(short)((local_e68 * *(short *)(DAT_030a222c + iVar4 * 2 + 2) +
                             (int)*(short *)(DAT_030a222c + iVar4 * 2) *
                             (int)(short)(0x7fff - (short)local_e68) + 0x40 >> 7) / iVar7) << 7;
    }
    else {
      uVar17 = (int)(short)(DAT_030a2228 / (iVar14 * 0x2000 >> 0x10)) + 0x7fff;
    }
    iVar4 = iVar10 * ((int)(uVar17 << 1) >> 0x10) + ((int)((uVar17 & 0x7fff) * iVar10) >> 0xf);
    if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    sVar3 = (short)iVar4;
    local_e50[uVar5] = sVar3;
    iVar4 = (((int)sVar3 * (int)sVar3 * 2 >> 0x10) * 0x6666 + 0x4000) * 2 >> 0x10;
    uVar17 = param_1[uVar5 + 0xb78];
    param_1[uVar5 + 0xb78] =
         ((int)(iVar4 * (piVar9[uVar5] & 0x7fffU) + 0x4000) >> 0xf) +
         ((uVar17 & 0x7fff) * 0x199a + 0x4000 >> 0xf) +
         iVar4 * ((piVar9[uVar5] << 1) >> 0x10) + ((int)(uVar17 << 1) >> 0x10) * 0x199a;
    iVar4 = (int)*(short *)((int)param_1 + uVar5 * 2 + 0x5b40);
    if (iVar4 < 2) {
      iVar4 = 1;
    }
    iVar4 = (int)(short)(0x7fff - (short)(local_e88 *
                                          (short)((short)((short)(0xfffe00 /
                                                                 (int)(short)((short)((uint)((short)
                                                  (0x7fff / iVar4) * 0x999a) >> 0x10) + 0x200)) *
                                                  0x6666 >> 0xf) + 0x1979) >> 0xf));
    if (0x7ffe < iVar14) {
      iVar14 = 0x7fff;
    }
    iVar10 = FUN_030a0b86((int)(short)-(short)iVar14);
    if (iVar10 >> 1 < 0x8000) {
      iVar14 = FUN_030a0b86((int)(short)-(short)iVar14);
      sVar3 = (short)(iVar14 >> 1);
    }
    else {
      sVar3 = 0x7fff;
    }
    iVar14 = (int)(short)(asStack_133a[uVar5 + 1] + 0x100) * (int)sVar3 * 2 >> 0x10;
    if (0x300 < iVar14) {
      iVar14 = 0x300;
    }
    iVar10 = 0x7fff - iVar4;
    local_17e8[uVar5] =
         (short)(DAT_030a2230 /
                (int)(short)((short)((uint)((short)(((iVar10 * 0x10000 >> 0x11) + iVar4 * 0x100) /
                                                   (int)(short)iVar10) * iVar14 + 0x80) >> 8) +
                            0x100));
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < iVar16);
  psVar12 = local_17e8 + uVar13;
  FUN_030a2e06(param_1[2],psVar12,local_17e8);
  FUN_030a2e06(param_1[2],local_e50 + uVar13);
  FUN_030a2e06(param_1[2],local_e58,local_4f0);
  iVar4 = 0;
  if (0 < (int)uVar13) {
    do {
      iVar14 = asStack_133a[iVar4 + 1] + 0x100;
      iVar10 = (int)(short)(((iVar14 * 0x10000 >> 0x11) + asStack_133a[iVar4 + 1] * 0x8000) /
                           (int)(short)iVar14);
      uVar5 = local_9a0[iVar4] * 8 + 0x800;
      iVar14 = ((int)uVar5 >> 0xf) * iVar10 + ((int)((uVar5 & 0x7fff) * iVar10 + 0x4000) >> 0xf);
      iVar16 = iVar14 >> 10;
      if (iVar16 < 0) {
        uVar5 = 0x7fff;
      }
      else if (iVar16 < 0x14) {
        sVar3 = (short)iVar14 - (short)(iVar16 << 10);
        iVar14 = FUN_030a0b0c(iVar14 * 0x8000 + 0x1a37);
        uVar5 = (int)(short)(((int)(short)(sVar3 * 0x20) *
                              (int)*(short *)(DAT_030a222c + iVar16 * 2 + 2) +
                              (int)*(short *)(DAT_030a222c + iVar16 * 2) *
                              (int)(short)(sVar3 * -0x20 + 0x7fff) + 0x40 >> 7) / iVar14) << 7;
      }
      else {
        uVar5 = (int)(short)(DAT_030a2228 / (iVar14 * 0x2000 >> 0x10)) + 0x7fff;
      }
      iVar14 = iVar10 * ((int)(uVar5 << 1) >> 0x10) + ((int)((uVar5 & 0x7fff) * iVar10) >> 0xf);
      if (0x7fff < iVar14) {
        iVar14 = 0x7fff;
      }
      iVar14 = (int)(short)iVar14;
      sVar3 = local_17e8[iVar4];
      if ((int)local_e50[iVar4] < iVar14 * 0x2aa0 >> 0xf) {
        iVar14 = (int)(short)(local_e50[iVar4] * 3);
      }
      local_e50[iVar4] = (short)iVar14;
      iVar14 = ((iVar14 * iVar14 * 2 >> 0x10) * 0x6666 + 0x4000) * 2 >> 0x10;
      uVar5 = param_1[iVar4 + 0xb78];
      param_1[iVar4 + 0xb78] =
           iVar14 * ((piVar9[iVar4] << 1) >> 0x10) + ((int)(uVar5 << 1) >> 0x10) * 0x199a +
           ((int)(iVar14 * (piVar9[iVar4] & 0x7fffU) + 0x4000) >> 0xf) +
           ((uVar5 & 0x7fff) * 0x199a + 0x4000 >> 0xf);
      iVar14 = (int)local_4f0[iVar4];
      if ((int)local_4f0[iVar4] < (int)local_e50[iVar4]) {
        iVar14 = (int)local_e50[iVar4];
      }
      local_e50[iVar4] = (short)iVar14;
      iVar14 = FUN_030a0b0c(iVar14 << 0xf);
      iVar16 = FUN_030a0b0c((int)local_4f0[iVar4] << 0xf);
      iVar14 = (int)(short)((short)(sVar3 * iVar14 + 0x4000 >> 0xf) +
                           (short)((short)(0x7fff - sVar3) * iVar16 + 0x4000 >> 0xf));
      local_17e8[iVar4] = (short)((uint)(iVar14 * iVar14 * 2) >> 0x10);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar13);
  }
  if (0 < (int)(uVar13 - 1)) {
    iVar4 = 0;
    psVar15 = local_17e8;
    iVar14 = uVar13 - 1;
    do {
      psVar15 = psVar15 + 1;
      sVar3 = *psVar15;
      iVar16 = iVar4 * 4;
      *(short *)(param_1 + iVar4 + 0x248) =
           (short)((uint)(((int)sVar3 * (int)(short)param_1[iVar4 + 0x248] + 0x4000) * 2) >> 0x10);
      iVar10 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(short *)((int)param_1 + iVar16 + 0x922) =
           (short)((uint)(((int)*(short *)((int)param_1 + iVar10 + 0x922) * (int)sVar3 + 0x4000) * 2
                         ) >> 0x10);
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
  }
  *(short *)((int)param_1 + 0x91e) =
       (short)((uint)(((int)*(short *)((int)param_1 + 0x91e) * (int)local_17e8[0] + 0x4000) * 2) >>
              0x10);
  *(short *)(local_e60 + 0x247) =
       (short)((uint)(((int)psVar12[-1] * (int)(short)local_e60[0x247] + 0x4000) * 2) >> 0x10);
  FUN_030a26a8(local_e5c[0x96],(int)param_1 + 0x91e,(int)param_1 + 0x1e);
  iVar4 = uVar13 * 2;
  if (0 < iVar4) {
    iVar14 = 0;
    do {
      *(short *)((int)param_1 + iVar14 * 2 + 0x1e) =
           (short)((uint)((int)*(short *)((int)param_1 + iVar14 * 2 + 0x1b80) *
                          (int)(short)((int)*(short *)((int)param_1 + iVar14 * 2 + 0x1e) +
                                       ((1 << (sbyte)local_e5c[0x98]) >> 1) >>
                                      (sbyte)local_e5c[0x98]) * 2) >> 0x10);
      iVar4 = iVar4 + -1;
      iVar14 = iVar14 + 1;
    } while (iVar4 != 0);
  }
  if (0 < (int)local_e80) {
    piVar9 = param_1 + 0x1b74;
    psVar12 = local_2c;
    uVar13 = local_e80;
    psVar15 = (short *)((int)param_1 + 0x1e);
    do {
      uVar13 = uVar13 - 1;
      *psVar12 = (short)*piVar9 + *psVar15;
      piVar9 = (int *)((int)piVar9 + 2);
      psVar12 = psVar12 + 1;
      psVar15 = psVar15 + 1;
    } while (uVar13 != 0);
  }
  if (0 < (int)local_e64) {
    local_2c = local_2c + local_e80;
    psVar12 = (short *)((int)param_1 + local_e80 * 2 + 0x1c);
    psVar15 = local_2c + -1;
    if ((local_e64 & 1) != 0) {
      psVar12 = (short *)((int)param_1 + local_e80 * 2 + 0x1e);
      *local_2c = *psVar12;
      psVar15 = local_2c;
    }
    for (iVar4 = (int)local_e64 >> 1; iVar4 != 0; iVar4 = iVar4 + -1) {
      psVar15[1] = psVar12[1];
      psVar12 = psVar12 + 2;
      psVar15 = psVar15 + 2;
      *psVar15 = *psVar12;
    }
  }
  if (0 < (int)local_e80) {
    uVar13 = local_e80 & 1;
    if (uVar13 != 0) {
      *(short *)(param_1 + 0x1b74) = *(short *)((int)param_1 + *param_1 * 2 + 0x1e);
    }
    uVar5 = (uint)(uVar13 != 0);
    for (; (int)uVar13 < (int)local_e80; uVar13 = uVar13 + 2) {
      iVar4 = uVar5 + 1;
      *(undefined2 *)((int)param_1 + uVar5 * 2 + 0x6dd0) =
           *(undefined2 *)((int)param_1 + (*param_1 + uVar5) * 2 + 0x1e);
      uVar5 = uVar5 + 2;
      *(undefined2 *)((int)param_1 + iVar4 * 2 + 0x6dd0) =
           *(undefined2 *)((int)param_1 + (*param_1 + iVar4) * 2 + 0x1e);
    }
  }
  return 1;
}


