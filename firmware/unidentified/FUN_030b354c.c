/**
 * FUN_030b354c @ 0x030b354c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b354c(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  uint uStack_a8;
  int iStack_a4;
  uint uStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_84;
  uint uStack_78;
  int iStack_74;
  int iStack_70;
  uint uStack_48;
  uint uStack_44;
  char *pcStack_40;
  byte *pbStack_3c;
  byte *pbStack_38;
  
  iVar11 = param_2;
  if (param_1 != (int *)0x0) {
    iVar11 = *param_1;
  }
  if (param_1 == (int *)0x0 || iVar11 == 0) {
    return 0xffffffff;
  }
  if ((param_2 != 1) || (iVar23 = iVar11, *(int *)(iVar11 + 0x8f0) != 1)) {
    iVar23 = iVar11 + param_2 * 0x3a;
  }
  iVar15 = iVar11 + param_2 * 0x65;
  if (*(char *)(iVar15 + 0xc02) == '\0') {
    return 0;
  }
  if (*(char *)(iVar23 + 0x87d) == '\x02') {
    iStack_74 = 8;
    iStack_70 = 0x80;
    iVar16 = *(int *)(iVar11 + 0x878);
    bVar1 = *(byte *)(*DAT_030b38ac + iVar16);
    bVar2 = *(byte *)(*DAT_030b38b0 + param_1[0x12]);
    iStack_90 = *DAT_030b38b8 + *(int *)(*DAT_030b38b4 + iVar16 * 4) * 2;
    bVar3 = *(byte *)(*(int *)(*DAT_030b38bc + param_1[0x12] * 4) + *DAT_030b38c0 + iVar16);
  }
  else {
    iStack_74 = 1;
    iStack_70 = 0x400;
    iVar16 = *(int *)(iVar11 + 0x878);
    bVar1 = *(byte *)(*DAT_030b3890 + iVar16);
    bVar2 = *(byte *)(*DAT_030b3894 + param_1[0x12]);
    iStack_90 = *DAT_030b389c + *(int *)(*DAT_030b3898 + iVar16 * 4) * 2;
    bVar3 = *(byte *)(*(int *)(*DAT_030b38a0 + param_1[0x12] * 4) + *DAT_030b38a4 + iVar16);
  }
  uStack_48 = (uint)bVar1;
  uStack_78 = (uint)bVar2;
  uStack_a8 = (uint)bVar3;
  if (*(byte *)(iVar23 + 0x87f) < uStack_a8) {
    uStack_a8 = (uint)*(byte *)(iVar23 + 0x87f);
  }
  pbStack_38 = (byte *)(iVar15 + 0xc13);
  pbStack_3c = (byte *)(iVar15 + 0xc1b);
  pcStack_40 = (char *)(iVar15 + 0xc23);
  iStack_84 = iVar15 + 0xc2b;
  uStack_44 = 0;
  iStack_94 = iVar11 + param_2 * 0x1000 + 0x1048;
  iStack_a4 = 0;
  if (iStack_74 != 0) {
    do {
      uStack_98 = uStack_48;
      iVar23 = 0;
      uVar7 = (uint)(byte)((char *)(iVar15 + 0xc02))[iStack_a4 + 1];
      if (uVar7 != 0) {
        do {
          bVar1 = *pbStack_38;
          pbStack_38 = pbStack_38 + 1;
          uVar12 = uStack_98 - bVar1;
          if ((int)uVar12 < 1) {
            uVar12 = 0;
          }
          pbVar13 = pbStack_3c + 1;
          uVar18 = (uint)*pbStack_3c;
          if (uStack_78 <= *pbStack_3c) {
            uVar18 = uStack_78;
          }
          if (uVar18 != 0) {
            uVar21 = uStack_a8;
            if ((int)uVar12 < (int)uStack_a8) {
              uVar21 = uVar12;
            }
            iVar16 = (int)*(short *)(iStack_90 + uVar21 * 2);
            if ((int)uStack_a8 <= (int)uStack_98) {
              uStack_98 = uStack_a8;
            }
            iVar8 = (int)*(short *)(iStack_90 + uStack_98 * 2);
            iVar19 = iVar8 - iVar16;
            if (0 < iVar19) {
              cVar5 = *pcStack_40;
              if (cVar5 != '\0') {
                iVar16 = iVar8 + -1;
              }
              cVar4 = *(char *)(iVar15 + 0xc0b + iStack_a4);
              iVar8 = iVar11 + 0xccc;
              if (cVar4 == '\x03') {
                iVar22 = *DAT_030b38a8;
LAB_030b373c:
                iVar9 = 0;
                if (uVar18 != 0) {
                  do {
                    iVar24 = *(int *)(iVar22 + (*(byte *)(iStack_84 + iVar9) & 0xf) * 4);
                    iVar14 = 0;
                    if (0 < iVar9) {
                      do {
                        *(int *)(iVar11 + 0xd1c + iVar14 * 4) =
                             *(int *)(iVar8 + iVar14 * 4) -
                             (int)((ulonglong)
                                   ((longlong)iVar24 *
                                   (longlong)(*(int *)(iVar8 + (iVar9 - iVar14) * 4 + -4) << 1)) >>
                                  0x20);
                        iVar14 = iVar14 + 1;
                      } while (iVar14 < iVar9);
                    }
                    iVar14 = 0;
                    if (0 < iVar9) {
                      do {
                        *(undefined4 *)(iVar8 + iVar14 * 4) =
                             *(undefined4 *)(iVar11 + 0xd1c + iVar14 * 4);
                        iVar14 = iVar14 + 1;
                      } while (iVar14 < iVar9);
                    }
                    *(int *)(iVar8 + iVar9 * 4) = iVar24 >> 0xb;
                    iVar9 = iVar9 + 1;
                  } while (iVar9 < (int)uVar18);
                }
              }
              else if (cVar4 == '\x04') {
                iVar22 = DAT_030b38a8[1];
                goto LAB_030b373c;
              }
              puVar20 = (uint *)(iStack_94 + iVar16 * 4);
              puVar17 = (uint *)(iVar11 + 0xd1c);
              iVar16 = 0;
              if (uVar18 != 0) {
                do {
                  puVar17[iVar16] = 0;
                  iVar16 = iVar16 + 1;
                } while (iVar16 < (int)uVar18);
              }
              uVar21 = 0;
              if (0 < iVar19) {
                if (cVar5 == '\0') {
                  iVar16 = 1;
                }
                else {
                  iVar16 = -1;
                }
                do {
                  lVar6 = CONCAT44((int)*puVar20 >> 0xc,*puVar20 << 0x14);
                  uVar10 = uVar18;
                  while (uVar10 = uVar10 - 1, 0 < (int)uVar10) {
                    lVar6 = (longlong)(int)puVar17[uVar10] *
                            (longlong)((int *)(iVar11 + 0xccc))[uVar10] + lVar6;
                    puVar17[uVar10] = (puVar17 + uVar10)[-1];
                  }
                  lVar6 = (longlong)(int)*puVar17 * (longlong)*(int *)(iVar11 + 0xccc) + lVar6;
                  iVar8 = (int)((ulonglong)lVar6 >> 0x20);
                  uVar10 = iVar8 << 0xc | (uint)lVar6 >> 0x14;
                  if (iVar8 >> 0x1f != iVar8 >> 0x13) {
                    uVar10 = iVar8 >> 0x1f ^ 0x7fffffff;
                  }
                  *puVar17 = uVar10;
                  *puVar20 = uVar10;
                  puVar20 = puVar20 + iVar16;
                  uVar10 = FUN_030b38f2();
                  uVar21 = uVar10 | uVar21;
                  iVar19 = iVar19 + -1;
                } while (iVar19 != 0);
              }
              uStack_44 = uVar21 | uStack_44;
              pcStack_40 = pcStack_40 + 1;
            }
            iStack_84 = iStack_84 + uVar18;
          }
          iVar23 = iVar23 + 1;
          uStack_98 = uVar12;
          pbStack_3c = pbVar13;
        } while (iVar23 < (int)uVar7);
      }
      iStack_94 = iStack_94 + iStack_70 * 4;
      iStack_a4 = iStack_a4 + 1;
    } while (iStack_a4 < iStack_74);
  }
  iVar15 = FUN_030b38ce(uStack_44);
  iVar11 = iVar11 + param_2 * 4;
  iVar16 = *(int *)(iVar11 + 0x1040);
  iVar23 = iVar15 + -1;
  if (iVar16 <= iVar15 + -1) {
    iVar23 = iVar16;
  }
  *(int *)(iVar11 + 0x1040) = iVar23;
  return 0;
}


