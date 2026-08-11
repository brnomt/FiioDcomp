/**
 * FUN_030b3c3a @ 0x030b3c3a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b3c3a(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint *local_90;
  uint *local_84;
  int local_74;
  byte *local_54;
  
  puVar2 = (uint *)(param_1 + param_3 * 0x1000 + 0x1048);
  if ((param_3 != 1) || (iVar9 = param_1, *(int *)(param_1 + 0x8f0) != 1)) {
    iVar9 = param_1 + param_3 * 0x3a;
  }
  iVar3 = *DAT_030b4080 + *(int *)(*DAT_030b407c + *(int *)(param_1 + 0x878) * 4) * 2;
  local_54 = (byte *)(param_1 + param_3 * 0x78 + 0xad4);
  local_74 = 0;
  local_90 = puVar2;
  if (*(char *)(iVar9 + 0x87f) != '\0') {
    do {
      uVar4 = (uint)*local_54;
      local_54 = local_54 + 1;
      uVar10 = (int)*(short *)(iVar3 + local_74 * 2 + 2) - (int)*(short *)(iVar3 + local_74 * 2);
      if (uVar4 == 0) {
        iVar11 = ((int)((-3 - uVar10) + ((uint)((int)(-3 - uVar10) >> 0x1f) >> 0x1e)) >> 2) * -4;
        if (0 < iVar11) {
          puVar8 = local_90 + -1;
          iVar11 = iVar11 >> 1;
          do {
            puVar8[1] = 0;
            puVar8 = puVar8 + 2;
            *puVar8 = 0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      else if (uVar4 < 5) {
        iVar11 = *(int *)(*DAT_030b4084 + uVar4 * 0x1c + -0x1c) + 4;
        unaff_r7 = uVar10;
        if (0 < (int)uVar10) {
          puVar8 = local_90;
          do {
            iVar5 = FUN_030b1610(param_2,iVar11);
            uVar18 = iVar5 << (0x20U - iVar11 & 0xff);
            iVar12 = *DAT_030b4084 + uVar4 * 0x1c;
            iVar15 = 0;
            iVar21 = *DAT_030b4088 + *(int *)(iVar12 + -4) * 2;
            uVar6 = 0;
            uVar13 = 0x20;
            pbVar7 = (byte *)(iVar12 + -0x18);
            iVar5 = 1;
            do {
              iVar16 = iVar15 + uVar6;
              iVar15 = iVar16 * 2;
              iVar21 = iVar21 + uVar6 * 2;
              uVar13 = uVar13 - 1;
              uVar6 = (uint)*pbVar7;
              uVar19 = (uVar18 >> (uVar13 & 0xff)) + iVar16 * -2;
              if (uVar19 < uVar6) {
                unaff_r6 = (uint)*(short *)(iVar21 + uVar19 * 2);
                pbVar7 = pbVar7 + 1 + (-4 - (iVar12 + -0x1c));
                goto LAB_030b3da4;
              }
              bVar1 = iVar5 < 0x8000;
              pbVar7 = pbVar7 + 1;
              iVar5 = iVar5 + 1;
            } while (bVar1);
            pbVar7 = (byte *)0x0;
LAB_030b3da4:
            uVar6 = (unaff_r6 & 0x7fff) >> 0xc;
            iVar5 = uVar18 << ((uint)pbVar7 & 0xff);
            uVar13 = (int)(unaff_r6 << 0x14) >> 0x1d;
            uVar18 = (int)(unaff_r6 << 0x17) >> 0x1d;
            uVar19 = (int)(unaff_r6 << 0x1a) >> 0x1d;
            uVar20 = (int)(unaff_r6 << 0x1d) >> 0x1d;
            FUN_030b1682(param_2,pbVar7 + uVar6);
            if (uVar6 != 0) {
              if (uVar13 != 0) {
                uVar13 = (uVar13 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                iVar5 = iVar5 << 1;
              }
              if (uVar18 != 0) {
                uVar18 = (uVar18 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                iVar5 = iVar5 << 1;
              }
              if (uVar19 != 0) {
                uVar19 = (uVar19 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                iVar5 = iVar5 << 1;
              }
              if (uVar20 != 0) {
                uVar20 = (uVar20 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
              }
            }
            *puVar8 = uVar13;
            unaff_r7 = unaff_r7 - 4;
            puVar8[1] = uVar18;
            puVar17 = puVar8 + 3;
            puVar8[2] = uVar19;
            puVar8 = puVar8 + 4;
            *puVar17 = uVar20;
          } while (0 < (int)unaff_r7);
        }
      }
      else if (uVar4 < 0xb) {
        iVar11 = *(int *)(*DAT_030b4084 + uVar4 * 0x1c + -0x1c) + 2;
        if (0 < (int)uVar10) {
          puVar8 = local_90;
          uVar6 = uVar10;
          do {
            iVar5 = FUN_030b1610(param_2,iVar11);
            iVar15 = 0;
            uVar19 = iVar5 << (0x20U - iVar11 & 0xff);
            uVar18 = 0x20;
            iVar12 = *DAT_030b4084 + uVar4 * 0x1c;
            iVar21 = *DAT_030b4088 + *(int *)(iVar12 + -4) * 2;
            uVar13 = 0;
            pbVar7 = (byte *)(iVar12 + -0x18);
            iVar5 = 1;
            do {
              iVar16 = iVar15 + uVar13;
              iVar15 = iVar16 * 2;
              iVar21 = iVar21 + uVar13 * 2;
              uVar18 = uVar18 - 1;
              uVar13 = (uint)*pbVar7;
              uVar20 = (uVar19 >> (uVar18 & 0xff)) + iVar16 * -2;
              if (uVar20 < uVar13) {
                unaff_r6 = (uint)*(short *)(iVar21 + uVar20 * 2);
                pbVar7 = pbVar7 + 1 + (-4 - (iVar12 + -0x1c));
                goto LAB_030b3eba;
              }
              bVar1 = iVar5 < 0x8000;
              pbVar7 = pbVar7 + 1;
              iVar5 = iVar5 + 1;
            } while (bVar1);
            pbVar7 = (byte *)0x0;
LAB_030b3eba:
            uVar20 = (unaff_r6 & 0xfff) >> 10;
            unaff_r7 = uVar19 << ((uint)pbVar7 & 0xff);
            uVar13 = (int)(unaff_r6 << 0x16) >> 0x1b;
            uVar18 = (int)(unaff_r6 << 0x1b) >> 0x1b;
            FUN_030b1682(param_2,pbVar7 + uVar20);
            if (uVar20 != 0) {
              if (uVar13 != 0) {
                uVar13 = (uVar13 ^ (int)unaff_r7 >> 0x1f) - ((int)unaff_r7 >> 0x1f);
                unaff_r7 = unaff_r7 << 1;
              }
              if (uVar18 != 0) {
                uVar18 = (uVar18 ^ (int)unaff_r7 >> 0x1f) - ((int)unaff_r7 >> 0x1f);
              }
            }
            puVar17 = puVar8 + 1;
            *puVar8 = uVar13;
            uVar6 = uVar6 - 2;
            puVar8 = puVar8 + 2;
            *puVar17 = uVar18;
          } while (0 < (int)uVar6);
        }
      }
      else if (uVar4 == 0xb) {
        local_84 = local_90;
        iVar5 = 0;
        iVar11 = 0;
        iVar12 = *(int *)(*DAT_030b4084 + 0x118) + 2;
        unaff_r6 = uVar10;
        if (0 < (int)uVar10) {
          do {
            iVar15 = FUN_030b1610(param_2,iVar12);
            uVar6 = iVar15 << (0x20U - iVar12 & 0xff);
            iVar21 = *DAT_030b4084;
            iVar22 = 0;
            iVar16 = *DAT_030b4088 + *(int *)(iVar21 + 0x130) * 2;
            uVar4 = 0;
            uVar13 = 0x20;
            pbVar7 = (byte *)(iVar21 + 0x11c);
            iVar15 = 1;
            do {
              iVar23 = iVar22 + uVar4;
              iVar16 = iVar16 + uVar4 * 2;
              uVar13 = uVar13 - 1;
              iVar22 = iVar23 * 2;
              uVar4 = (uint)*pbVar7;
              uVar18 = (uVar6 >> (uVar13 & 0xff)) + iVar23 * -2;
              if (uVar18 < uVar4) {
                unaff_r7 = (uint)*(short *)(iVar16 + uVar18 * 2);
                pbVar7 = pbVar7 + 1 + (-4 - (iVar21 + 0x118));
                goto LAB_030b405e;
              }
              bVar1 = iVar15 < 0x8000;
              pbVar7 = pbVar7 + 1;
              iVar15 = iVar15 + 1;
            } while (bVar1);
            pbVar7 = (byte *)0x0;
LAB_030b405e:
            uVar13 = (unaff_r7 & 0x3fff) >> 0xc;
            iVar15 = uVar6 << ((uint)pbVar7 & 0xff);
            uVar4 = (int)(unaff_r7 << 0x14) >> 0x1a;
            uVar6 = (int)(unaff_r7 << 0x1a) >> 0x1a;
            FUN_030b1682(param_2,pbVar7 + uVar13);
            if (uVar4 == 0x10) {
              uVar4 = 4;
              iVar16 = bitstream_getbits(param_2,1);
              iVar21 = iVar5;
              while ((iVar5 = iVar21, iVar16 == 1 && (iVar5 = iVar21 + 1, iVar21 < 0x8000))) {
                uVar4 = uVar4 + 1;
                iVar16 = bitstream_getbits(param_2,1);
                iVar21 = iVar5;
              }
              iVar21 = bitstream_getbits(param_2,uVar4);
              uVar4 = iVar21 + (1 << (uVar4 & 0xff));
            }
            if (uVar6 == 0x10) {
              uVar6 = 4;
              iVar16 = bitstream_getbits(param_2,1);
              iVar21 = iVar11;
              while ((iVar11 = iVar21, iVar16 == 1 && (iVar11 = iVar21 + 1, iVar21 < 0x8000))) {
                uVar6 = uVar6 + 1;
                iVar16 = bitstream_getbits(param_2,1);
                iVar21 = iVar11;
              }
              iVar21 = bitstream_getbits(param_2,uVar6);
              uVar6 = iVar21 + (1 << (uVar6 & 0xff));
            }
            if (uVar13 != 0) {
              if (uVar4 != 0) {
                uVar4 = (uVar4 ^ iVar15 >> 0x1f) - (iVar15 >> 0x1f);
                iVar15 = iVar15 << 1;
              }
              if (uVar6 != 0) {
                uVar6 = (uVar6 ^ iVar15 >> 0x1f) - (iVar15 >> 0x1f);
              }
            }
            unaff_r6 = unaff_r6 - 2;
            *local_84 = uVar4;
            local_84[1] = uVar6;
            local_84 = local_84 + 2;
          } while (0 < (int)unaff_r6);
        }
      }
      else {
        iVar11 = ((int)((-3 - uVar10) + ((uint)((int)(-3 - uVar10) >> 0x1f) >> 0x1e)) >> 2) * -4;
        if (0 < iVar11) {
          puVar8 = local_90 + -1;
          iVar11 = iVar11 >> 1;
          do {
            puVar8[1] = 0;
            puVar8 = puVar8 + 2;
            *puVar8 = 0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
      }
      local_90 = local_90 + uVar10;
      local_74 = local_74 + 1;
    } while (local_74 < (int)(uint)*(byte *)(iVar9 + 0x87f));
  }
  FUN_030b46c6(0x400 - *(short *)(iVar3 + local_74 * 2),local_90);
  param_1 = param_3 * 0xb + param_1;
  if (*(char *)(param_1 + 0xbec) == '\0') {
    return;
  }
  iVar9 = (int)*(short *)(iVar3 + (uint)*(byte *)(param_1 + 0xbee) * 2);
  uVar4 = (uint)*(byte *)(param_1 + 0xbed);
  if (uVar4 == 0) {
    return;
  }
  pbVar14 = (byte *)(param_1 + 0xbf3);
  pbVar7 = (byte *)(param_1 + 0xbef);
  do {
    uVar10 = (uint)*pbVar14;
    iVar9 = iVar9 + (uint)*pbVar7;
    if ((int)puVar2[iVar9] < 1) {
      uVar10 = -uVar10;
    }
    puVar2[iVar9] = puVar2[iVar9] + uVar10;
    pbVar14 = pbVar14 + 1;
    uVar4 = uVar4 - 1;
    pbVar7 = pbVar7 + 1;
  } while (uVar4 != 0);
  return;
}


