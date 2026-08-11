/**
 * FUN_030c4528 @ 0x030c4528
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c4528(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                 int param_7,int param_8)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  bool bVar19;
  
  piVar2 = (int *)FUN_030ca4a0(param_5 << 2);
  iVar10 = DAT_030c4948;
  iVar3 = 0;
  do {
    if ((((int)(uint)*(ushort *)(DAT_030c4944 + iVar3 * 2) <= param_8) &&
        (param_8 < (int)(uint)*(ushort *)(DAT_030c4944 + iVar3 * 2 + 2))) ||
       ((iVar4 = DAT_030c4944 + iVar3 * 2, (int)(uint)*(ushort *)(iVar4 + 2) <= param_8 &&
        (param_8 < (int)(uint)*(ushort *)(iVar4 + 4))))) break;
    iVar3 = iVar3 + 2;
  } while (iVar3 < 0x36);
  iVar4 = 0xd8000;
  iVar3 = 0;
  while( true ) {
    if (((int)(uint)*(ushort *)(DAT_030c4944 + iVar3 * 2) <= param_8) &&
       (param_8 < (int)(uint)*(ushort *)(DAT_030c4944 + iVar3 * 2 + 2))) goto LAB_030c45b4;
    iVar5 = DAT_030c4944 + iVar3 * 2;
    uVar12 = (uint)*(ushort *)(iVar5 + 2);
    bVar19 = SBORROW4(uVar12,param_8);
    iVar7 = uVar12 - param_8;
    if ((int)uVar12 <= param_8) {
      uVar12 = (uint)*(ushort *)(iVar5 + 4);
      bVar19 = SBORROW4(param_8,uVar12);
      iVar7 = param_8 - uVar12;
    }
    if (iVar7 < 0 != bVar19) break;
    iVar3 = iVar3 + 2;
    if (0x35 < iVar3) {
LAB_030c45b4:
      if (iVar3 != 0x36) {
        uVar12 = (uint)*(ushort *)(DAT_030c4944 + iVar3 * 2);
        iVar4 = ((0x80000000 / (*(ushort *)(DAT_030c4944 + iVar3 * 2 + 2) - uVar12)) *
                 (param_8 - uVar12) >> 0x11) + iVar3 * 0x4000;
      }
      uVar12 = (uint)(iVar4 << 0xc) / param_3;
      uVar6 = (uint)*(ushort *)(DAT_030c4944 + (uVar12 >> 0x1a) * 2);
      iVar5 = 0;
      iVar7 = uVar6 + ((*(ushort *)(DAT_030c4944 + (uVar12 >> 0x1a) * 2 + 2) - uVar6) *
                       (uVar12 >> 0xc & 0x3fff) >> 0xe);
      iVar9 = 0;
      iVar3 = 0;
      iVar4 = 0;
      if (0 < (int)param_5) {
        do {
          iVar13 = (*(int *)(param_4 + iVar9 * 4) >> 10) * 0x517d;
          uVar6 = iVar13 >> 0xe;
          bVar19 = uVar6 == 0;
          iVar13 = iVar13 >> 0x17;
          if (-1 < (int)uVar6) {
            bVar19 = iVar13 == 0x80;
          }
          if (bVar19 || (-1 >= (int)uVar6 || 0x80 < iVar13)) {
            memset_byte(param_1,0,param_2 << 2);
            FUN_030ca488();
            return;
          }
          iVar15 = *(int *)(iVar10 + iVar13 * 4);
          piVar2[iVar9] =
               iVar15 - ((int)((iVar15 - *(int *)(iVar10 + iVar13 * 4 + 4)) * (uVar6 & 0x1ff)) >> 9)
          ;
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)param_5);
      }
      iVar10 = 0;
      if (0 < param_2) {
        iVar9 = param_5 - 2;
        do {
          iVar15 = 0;
          uVar6 = iVar4 * (0x80000000 / param_3) >> 0xf;
          iVar13 = (int)uVar6 >> 9;
          iVar8 = *(int *)(DAT_030c4948 + iVar13 * 4);
          iVar8 = (int)((uVar6 & 0x1ff) * (*(int *)(DAT_030c4948 + iVar13 * 4 + 4) - iVar8) +
                       iVar8 * 0x200) >> 9;
          iVar13 = *piVar2 - iVar8;
          if (iVar13 < 0) {
            iVar13 = -iVar13;
          }
          uVar6 = iVar13 * 0xb505;
          iVar13 = piVar2[1] - iVar8;
          if (iVar13 < 0) {
            iVar13 = -iVar13;
          }
          uVar14 = iVar13 * 0xb505;
          iVar13 = 3;
          if (1 < iVar9) {
            iVar13 = iVar9 / 2;
            piVar1 = piVar2;
            do {
              uVar16 = uVar14 | uVar6;
              uVar11 = (uint)*(byte *)(DAT_030c494c + (uVar16 >> 0x19));
              if ((uVar11 == 0) &&
                 (uVar11 = (uint)*(byte *)(DAT_030c4950 + (uVar16 >> 0x13)), uVar11 == 0)) {
                uVar11 = (uint)*(byte *)(DAT_030c4954 + (uVar16 >> 0x10));
              }
              iVar17 = piVar1[2] - iVar8;
              if (iVar17 < 0) {
                iVar17 = -iVar17;
              }
              uVar6 = (uVar6 >> uVar11) * iVar17;
              iVar17 = piVar1[3] - iVar8;
              if (iVar17 < 0) {
                iVar17 = -iVar17;
              }
              uVar14 = (uVar14 >> uVar11) * iVar17;
              iVar15 = iVar15 + uVar11;
              iVar13 = iVar13 + -1;
              piVar1 = piVar1 + 2;
            } while (iVar13 != 0);
            iVar13 = (iVar9 - (iVar9 >> 0x1f) & 0xfffffffeU) + 3;
          }
          uVar16 = uVar14 | uVar6;
          uVar11 = (uint)*(byte *)(DAT_030c494c + (uVar16 >> 0x19));
          if ((uVar11 == 0) &&
             (uVar11 = (uint)*(byte *)(DAT_030c494c + 0x40 + (uVar16 >> 0x13)), uVar11 == 0)) {
            uVar11 = (uint)*(byte *)(DAT_030c494c + -0x500 + (uVar16 >> 0x10));
          }
          if ((param_5 & 1) == 0) {
            iVar15 = uVar11 + param_5 * -7 + iVar15;
            uVar6 = (iVar8 + 0x4000) * ((uVar6 >> uVar11) * (uVar6 >> uVar11) >> 0x10) +
                    (0x4000 - iVar8) * ((uVar14 >> uVar11) * (uVar14 >> uVar11) >> 0x10) >> 0xe;
          }
          else {
            iVar13 = piVar2[iVar13 + -1] - iVar8;
            if (iVar13 < 0) {
              iVar13 = -iVar13;
            }
            uVar16 = (uVar6 >> uVar11) * iVar13;
            uVar14 = (uVar14 >> uVar11) << 0xe;
            uVar6 = uVar14 | uVar16;
            uVar18 = (uint)*(byte *)(DAT_030c494c + (uVar6 >> 0x19));
            if ((uVar18 == 0) &&
               (uVar18 = (uint)*(byte *)(DAT_030c4950 + (uVar6 >> 0x13)), uVar18 == 0)) {
              uVar18 = (uint)*(byte *)(DAT_030c4954 + (uVar6 >> 0x10));
            }
            uVar16 = uVar16 >> uVar18;
            uVar14 = uVar14 >> uVar18;
            iVar15 = iVar15 + uVar11 + uVar18 + ((int)(param_5 + 1) >> 1) * -0xe;
            uVar6 = (uVar16 * uVar16 >> 0x10) +
                    ((0x4000 - (iVar8 * iVar8 >> 0xe)) * (uVar14 * uVar14 >> 0x10) >> 0xe);
          }
          uVar14 = param_5 + iVar15 * 2;
          if (uVar6 >> 0x10 == 0) {
            for (; (uVar6 != 0 && ((uVar6 & 0x8000) == 0)); uVar6 = uVar6 << 1) {
              uVar14 = uVar14 - 1;
            }
          }
          else {
            uVar6 = uVar6 >> 1;
            uVar14 = uVar14 + 1;
          }
          uVar11 = (uVar6 & 0x7fff) >> 9;
          iVar13 = ((*(int *)(DAT_030c4958 + uVar11 * 4) -
                    ((int)(*(int *)(DAT_030c4958 + 0x104 + uVar11 * 4) * (uVar6 & 0x3ff)) >> 10)) *
                    *(int *)(DAT_030c495c + (uVar14 & 1) * 4) >> (((int)uVar14 >> 1) + 0x15U & 0xff)
                   ) * param_6 + param_7 * -0x1000;
          if (iVar13 < 1) {
            if (iVar13 < -0x8c000) {
              iVar13 = 0;
            }
            else {
              iVar13 = *(int *)(DAT_030c4960 + ((iVar13 + 0x8c) * 0x1d3 >> 0x14) * 4) << 9;
            }
          }
          else {
            iVar13 = 0x7fffffff;
          }
          *(int *)(param_1 + iVar10 * 4) = (iVar13 >> 9) * (*(int *)(param_1 + iVar10 * 4) >> 6);
          iVar10 = iVar10 + 1;
          iVar15 = 1;
          iVar8 = (param_2 - iVar10) + 1;
          if (1 < iVar8) {
            do {
              iVar3 = iVar3 + (param_8 - (param_8 / param_2) * param_2);
              if (param_2 <= iVar3) {
                iVar3 = iVar3 - param_2;
                iVar5 = iVar5 + 1;
              }
              iVar5 = iVar5 + param_8 / param_2;
              if (iVar7 <= iVar5) break;
              *(int *)(param_1 + iVar10 * 4) = (*(int *)(param_1 + iVar10 * 4) >> 6) * (iVar13 >> 9)
              ;
              iVar10 = iVar10 + 1;
              iVar15 = iVar15 + 1;
            } while (iVar15 < iVar8);
          }
          do {
            iVar13 = iVar4 + 1;
            iVar7 = DAT_030c4d74;
            if ((int)param_3 <= iVar4 + 2) break;
            uVar6 = (iVar4 + 2) * uVar12;
            uVar14 = uVar6 >> 0x1a;
            uVar11 = (uint)*(ushort *)(DAT_030c4d70 + uVar14 * 2);
            iVar7 = uVar11 + ((*(ushort *)(DAT_030c4d70 + uVar14 * 2 + 2) - uVar11) *
                              (uVar6 >> 0xc & 0x3fff) >> 0xe);
            iVar4 = iVar13;
          } while (iVar7 < iVar5);
          iVar4 = iVar13;
          if ((int)param_3 <= iVar13) {
            iVar4 = param_3 - 1;
            iVar7 = DAT_030c4d74;
          }
        } while (iVar10 < param_2);
      }
      FUN_030ca488();
      return;
    }
  }
  iVar3 = iVar3 + 1;
  goto LAB_030c45b4;
}


