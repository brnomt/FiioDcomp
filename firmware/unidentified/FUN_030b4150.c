/**
 * FUN_030b4150 @ 0x030b4150
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b4150(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int local_a4;
  uint *puStack_98;
  uint uStack_90;
  int local_88;
  int iStack_7c;
  int iStack_6c;
  byte *local_60;
  
  local_a4 = param_1 + param_3 * 0x1000 + 0x1048;
  iVar8 = local_a4;
  if (param_3 == 1) {
    iVar8 = *(int *)(param_1 + 0x8f0);
  }
  iVar2 = param_1;
  if (param_3 != 1 || iVar8 != 1) {
    iVar2 = param_1 + param_3 * 0x3a;
  }
  iVar8 = *DAT_030b4584 + *(int *)(*DAT_030b4580 + *(int *)(param_1 + 0x878) * 4) * 2;
  local_60 = (byte *)(param_1 + param_3 * 0x78 + 0xad4);
  local_88 = 0;
  if (*(char *)(iVar2 + 0x8ad) == '\0') {
    return;
  }
  do {
    iStack_7c = 0;
    if (*(char *)(iVar2 + 0x87f) != '\0') {
      iVar3 = local_88 + iVar2 + 0x87c;
      do {
        uStack_90 = (int)*(short *)(iVar8 + iStack_7c * 2 + 2) -
                    (int)*(short *)(iVar8 + iStack_7c * 2);
        uVar4 = (uint)*local_60;
        local_60 = local_60 + 1;
        iStack_6c = 0;
        if (*(char *)(iVar3 + 0x32) != '\0') {
          iVar21 = ((int)((-3 - uStack_90) + ((uint)((int)(-3 - uStack_90) >> 0x1f) >> 0x1e)) >> 2)
                   * -4;
          do {
            iVar9 = iVar21 >> 1;
            if (uVar4 == 0) {
              if (0 < iVar21) {
                puVar7 = (undefined4 *)(local_a4 + iStack_6c * 0x200 + -4);
                do {
                  puVar7[1] = 0;
                  puVar7 = puVar7 + 2;
                  *puVar7 = 0;
                  iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
              }
            }
            else if (uVar4 < 5) {
              puVar15 = (uint *)(local_a4 + iStack_6c * 0x200);
              iVar9 = *(int *)(*DAT_030b4588 + uVar4 * 0x1c + -0x1c) + 4;
              unaff_r7 = uStack_90;
              if (0 < (int)uStack_90) {
                do {
                  iVar5 = FUN_030b1610(param_2,iVar9);
                  uVar20 = iVar5 << (0x20U - iVar9 & 0xff);
                  iVar10 = *DAT_030b4588 + uVar4 * 0x1c;
                  iVar12 = 0;
                  iVar14 = *DAT_030b458c + *(int *)(iVar10 + -4) * 2;
                  uVar17 = 0;
                  uVar11 = 0x20;
                  pbVar6 = (byte *)(iVar10 + -0x18);
                  iVar5 = 1;
                  do {
                    iVar13 = iVar12 + uVar17;
                    iVar12 = iVar13 * 2;
                    iVar14 = iVar14 + uVar17 * 2;
                    uVar11 = uVar11 - 1;
                    uVar17 = (uint)*pbVar6;
                    uVar18 = (uVar20 >> (uVar11 & 0xff)) + iVar13 * -2;
                    if (uVar18 < uVar17) {
                      unaff_r6 = (uint)*(short *)(iVar14 + uVar18 * 2);
                      pbVar6 = pbVar6 + 1 + (-4 - (iVar10 + -0x1c));
                      goto LAB_030b42ee;
                    }
                    bVar1 = iVar5 < 0x8000;
                    pbVar6 = pbVar6 + 1;
                    iVar5 = iVar5 + 1;
                  } while (bVar1);
                  pbVar6 = (byte *)0x0;
LAB_030b42ee:
                  uVar11 = (unaff_r6 & 0x7fff) >> 0xc;
                  iVar5 = uVar20 << ((uint)pbVar6 & 0xff);
                  uVar17 = (int)(unaff_r6 << 0x14) >> 0x1d;
                  uVar20 = (int)(unaff_r6 << 0x17) >> 0x1d;
                  uVar18 = (int)(unaff_r6 << 0x1a) >> 0x1d;
                  uVar19 = (int)(unaff_r6 << 0x1d) >> 0x1d;
                  FUN_030b1682(param_2,pbVar6 + uVar11);
                  if (uVar11 != 0) {
                    if (uVar17 != 0) {
                      uVar17 = (uVar17 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                      iVar5 = iVar5 << 1;
                    }
                    if (uVar20 != 0) {
                      uVar20 = (uVar20 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                      iVar5 = iVar5 << 1;
                    }
                    if (uVar18 != 0) {
                      uVar18 = (uVar18 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                      iVar5 = iVar5 << 1;
                    }
                    if (uVar19 != 0) {
                      uVar19 = (uVar19 ^ iVar5 >> 0x1f) - (iVar5 >> 0x1f);
                    }
                  }
                  *puVar15 = uVar17;
                  unaff_r7 = unaff_r7 - 4;
                  puVar15[1] = uVar20;
                  puVar16 = puVar15 + 3;
                  puVar15[2] = uVar18;
                  puVar15 = puVar15 + 4;
                  *puVar16 = uVar19;
                } while (0 < (int)unaff_r7);
              }
            }
            else if (uVar4 < 0xb) {
              puVar15 = (uint *)(local_a4 + iStack_6c * 0x200);
              iVar9 = *(int *)(*DAT_030b4588 + uVar4 * 0x1c + -0x1c) + 2;
              if (0 < (int)uStack_90) {
                uVar11 = uStack_90;
                do {
                  iVar5 = FUN_030b1610(param_2,iVar9);
                  iVar12 = 0;
                  uVar18 = iVar5 << (0x20U - iVar9 & 0xff);
                  uVar20 = 0x20;
                  iVar10 = *DAT_030b4588 + uVar4 * 0x1c;
                  iVar14 = *DAT_030b458c + *(int *)(iVar10 + -4) * 2;
                  uVar17 = 0;
                  pbVar6 = (byte *)(iVar10 + -0x18);
                  iVar5 = 1;
                  do {
                    iVar13 = iVar12 + uVar17;
                    iVar12 = iVar13 * 2;
                    iVar14 = iVar14 + uVar17 * 2;
                    uVar20 = uVar20 - 1;
                    uVar17 = (uint)*pbVar6;
                    uVar19 = (uVar18 >> (uVar20 & 0xff)) + iVar13 * -2;
                    if (uVar19 < uVar17) {
                      unaff_r6 = (uint)*(short *)(iVar14 + uVar19 * 2);
                      pbVar6 = pbVar6 + 1 + (-4 - (iVar10 + -0x1c));
                      goto LAB_030b440a;
                    }
                    bVar1 = iVar5 < 0x8000;
                    pbVar6 = pbVar6 + 1;
                    iVar5 = iVar5 + 1;
                  } while (bVar1);
                  pbVar6 = (byte *)0x0;
LAB_030b440a:
                  uVar19 = (unaff_r6 & 0xfff) >> 10;
                  unaff_r7 = uVar18 << ((uint)pbVar6 & 0xff);
                  uVar20 = (int)(unaff_r6 << 0x16) >> 0x1b;
                  uVar17 = (int)(unaff_r6 << 0x1b) >> 0x1b;
                  FUN_030b1682(param_2,pbVar6 + uVar19);
                  if (uVar19 != 0) {
                    if (uVar20 != 0) {
                      uVar20 = (uVar20 ^ (int)unaff_r7 >> 0x1f) - ((int)unaff_r7 >> 0x1f);
                      unaff_r7 = unaff_r7 << 1;
                    }
                    if (uVar17 != 0) {
                      uVar17 = (uVar17 ^ (int)unaff_r7 >> 0x1f) - ((int)unaff_r7 >> 0x1f);
                    }
                  }
                  puVar16 = puVar15 + 1;
                  *puVar15 = uVar20;
                  uVar11 = uVar11 - 2;
                  puVar15 = puVar15 + 2;
                  *puVar16 = uVar17;
                } while (0 < (int)uVar11);
              }
            }
            else if (uVar4 == 0xb) {
              puStack_98 = (uint *)(local_a4 + iStack_6c * 0x200);
              iVar5 = 0;
              iVar9 = 0;
              iVar10 = *(int *)(*DAT_030b4588 + 0x118) + 2;
              unaff_r6 = uStack_90;
              if (0 < (int)uStack_90) {
                do {
                  iVar12 = FUN_030b1610(param_2,iVar10);
                  uVar17 = iVar12 << (0x20U - iVar10 & 0xff);
                  iVar14 = *DAT_030b4588;
                  iVar22 = 0;
                  iVar13 = *DAT_030b458c + *(int *)(iVar14 + 0x130) * 2;
                  uVar11 = 0;
                  uVar20 = 0x20;
                  pbVar6 = (byte *)(iVar14 + 0x11c);
                  iVar12 = 1;
                  do {
                    iVar23 = iVar22 + uVar11;
                    iVar13 = iVar13 + uVar11 * 2;
                    uVar20 = uVar20 - 1;
                    iVar22 = iVar23 * 2;
                    uVar11 = (uint)*pbVar6;
                    uVar18 = (uVar17 >> (uVar20 & 0xff)) + iVar23 * -2;
                    if (uVar18 < uVar11) {
                      unaff_r7 = (uint)*(short *)(iVar13 + uVar18 * 2);
                      pbVar6 = pbVar6 + 1 + (-4 - (iVar14 + 0x118));
                      goto LAB_030b45e8;
                    }
                    bVar1 = iVar12 < 0x8000;
                    pbVar6 = pbVar6 + 1;
                    iVar12 = iVar12 + 1;
                  } while (bVar1);
                  pbVar6 = (byte *)0x0;
LAB_030b45e8:
                  uVar20 = (unaff_r7 & 0x3fff) >> 0xc;
                  iVar12 = uVar17 << ((uint)pbVar6 & 0xff);
                  uVar11 = (int)(unaff_r7 << 0x14) >> 0x1a;
                  uVar17 = (int)(unaff_r7 << 0x1a) >> 0x1a;
                  FUN_030b1682(param_2,pbVar6 + uVar20);
                  if (uVar11 == 0x10) {
                    uVar11 = 4;
                    iVar13 = bitstream_getbits(param_2,1);
                    iVar14 = iVar5;
                    while ((iVar5 = iVar14, iVar13 == 1 && (iVar5 = iVar14 + 1, iVar14 < 0x8000))) {
                      uVar11 = uVar11 + 1;
                      iVar13 = bitstream_getbits(param_2,1);
                      iVar14 = iVar5;
                    }
                    iVar14 = bitstream_getbits(param_2,uVar11);
                    uVar11 = iVar14 + (1 << (uVar11 & 0xff));
                  }
                  if (uVar17 == 0x10) {
                    uVar17 = 4;
                    iVar13 = bitstream_getbits(param_2,1);
                    iVar14 = iVar9;
                    while ((iVar9 = iVar14, iVar13 == 1 && (iVar9 = iVar14 + 1, iVar14 < 0x8000))) {
                      uVar17 = uVar17 + 1;
                      iVar13 = bitstream_getbits(param_2,1);
                      iVar14 = iVar9;
                    }
                    iVar14 = bitstream_getbits(param_2,uVar17);
                    uVar17 = iVar14 + (1 << (uVar17 & 0xff));
                  }
                  if (uVar20 != 0) {
                    if (uVar11 != 0) {
                      uVar11 = (uVar11 ^ iVar12 >> 0x1f) - (iVar12 >> 0x1f);
                      iVar12 = iVar12 << 1;
                    }
                    if (uVar17 != 0) {
                      uVar17 = (uVar17 ^ iVar12 >> 0x1f) - (iVar12 >> 0x1f);
                    }
                  }
                  unaff_r6 = unaff_r6 - 2;
                  *puStack_98 = uVar11;
                  puStack_98[1] = uVar17;
                  puStack_98 = puStack_98 + 2;
                } while (0 < (int)unaff_r6);
              }
            }
            else if (0 < iVar21) {
              puVar7 = (undefined4 *)(local_a4 + iStack_6c * 0x200 + -4);
              do {
                puVar7[1] = 0;
                puVar7 = puVar7 + 2;
                *puVar7 = 0;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
            iStack_6c = iStack_6c + 1;
          } while (iStack_6c < (int)(uint)*(byte *)(iVar3 + 0x32));
        }
        local_a4 = local_a4 + uStack_90 * 4;
        iStack_7c = iStack_7c + 1;
      } while (iStack_7c < (int)(uint)*(byte *)(iVar2 + 0x87f));
    }
    iVar3 = 0;
    iVar21 = iVar2 + 0x87c + local_88;
    if (*(char *)(iVar21 + 0x32) != '\0') {
      do {
        uStack_90 = 0x80 - (int)*(short *)(iVar8 + iStack_7c * 2);
        iVar9 = ((int)((-3 - uStack_90) + ((uint)((int)(-3 - uStack_90) >> 0x1f) >> 0x1e)) >> 2) *
                -4;
        if (0 < iVar9) {
          puVar7 = (undefined4 *)(local_a4 + iVar3 * 0x200 + -4);
          iVar9 = iVar9 >> 1;
          do {
            puVar7[1] = 0;
            puVar7 = puVar7 + 2;
            *puVar7 = 0;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)*(byte *)(iVar21 + 0x32));
    }
    local_a4 = local_a4 + uStack_90 * 4 + (uint)*(byte *)(iVar21 + 0x32) * 0x200 + -0x200;
    local_88 = local_88 + 1;
    if ((int)(uint)*(byte *)(iVar2 + 0x8ad) <= local_88) {
      return;
    }
  } while( true );
}


