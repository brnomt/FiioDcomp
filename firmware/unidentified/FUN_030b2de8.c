/**
 * FUN_030b2de8 @ 0x030b2de8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b2de8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  int iStack_90;
  byte *pbStack_64;
  int iStack_58;
  int iStack_54;
  uint uStack_4c;
  int iStack_48;
  uint uStack_44;
  
  iVar11 = param_2;
  if (param_1 != (int *)0x0) {
    iVar11 = *param_1;
  }
  if (param_1 == (int *)0x0 || iVar11 == 0) {
    return 0xffffffff;
  }
  if ((param_2 != 1) || (iVar10 = iVar11, *(int *)(iVar11 + 0x8f0) != 1)) {
    iVar10 = iVar11 + param_2 * 0x3a;
  }
  iVar12 = iVar11 + param_2 * 4;
  if (*(int *)(iVar12 + 0xbd8) == 0) {
    return 0;
  }
  if (*(char *)(iVar10 + 0x87d) == '\x02') {
    iStack_58 = *DAT_030b3238 + *(int *)(*DAT_030b3234 + *(int *)(iVar11 + 0x878) * 4) * 2;
    iVar13 = 0x80;
  }
  else {
    iStack_58 = *DAT_030b3230 + *(int *)(*DAT_030b322c + *(int *)(iVar11 + 0x878) * 4) * 2;
    iVar13 = 0x400;
  }
  piVar20 = (int *)(iVar11 + param_2 * 0x1000 + 0x1048);
  iStack_54 = iVar11 + param_2 * 0x78 + 0xad4;
  iVar1 = param_1[10];
  bVar24 = iVar1 == 1;
  if (bVar24) {
    iVar1 = *(int *)(iVar11 + 0x8f0);
  }
  if (!bVar24 || iVar1 != 1) {
    iVar1 = 0;
  }
  uStack_44 = 0;
  iStack_90 = 0;
  if (*(char *)(iVar10 + 0x8ad) != '\0') {
    do {
      iStack_48 = 0;
      iVar2 = iVar10 + 0x87c + iStack_90;
      if (*(char *)(iVar2 + 0x32) != '\0') {
        do {
          iVar21 = 0;
          uVar17 = (uint)*(byte *)(iVar10 + 0x87f) * iStack_90;
          uVar22 = uVar17 & 7;
          iVar3 = iVar11 + ((int)uVar17 >> 3);
          pbStack_64 = (byte *)(iVar3 + 0xbc9);
          uStack_4c = (uint)(*(byte *)(iVar3 + 0xbc8) >> uVar22);
          if (*(byte *)(iVar10 + 0x87f) != 0) {
            do {
              iVar3 = DAT_030b323c;
              uVar17 = (int)*(short *)(iStack_58 + iVar21 * 2 + 2) -
                       (int)*(short *)(iStack_58 + iVar21 * 2);
              if (*(char *)(iStack_54 + iVar21) == '\r') {
                if (param_2 == 0) {
                  piVar4 = piVar20;
                  uVar15 = uVar17;
                  if (0 < (int)uVar17) {
                    do {
                      iVar19 = *(int *)(iVar11 + 0xbe0) * DAT_030b3240 + iVar3;
                      *(int *)(iVar11 + 0xbe0) = iVar19;
                      *piVar4 = iVar19 >> 0x10;
                      uVar15 = uVar15 - 1;
                      piVar4 = piVar4 + 1;
                    } while (uVar15 != 0);
                  }
                  if ((iVar1 != 0) &&
                     (*(char *)(iStack_90 * (uint)*(byte *)(iVar10 + 0x87f) + iVar11 +
                               iVar21 + 0xb4c) == '\r')) {
                    iVar3 = ((int)piVar20 + (-0x1048 - iVar11) & 0xfffffffcU) + iVar11;
                    piVar4 = (int *)(iVar3 + 0x2048);
                    if (0 < (int)uVar17) {
                      piVar5 = (int *)(iVar3 + 0x2044);
                      piVar14 = piVar20 + -1;
                      if ((uVar17 & 1) != 0) {
                        *piVar4 = *piVar20;
                        piVar5 = piVar4;
                        piVar14 = piVar20;
                      }
                      for (iVar3 = (int)uVar17 >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
                        piVar5[1] = piVar14[1];
                        piVar14 = piVar14 + 2;
                        piVar5 = piVar5 + 2;
                        *piVar5 = *piVar14;
                      }
                    }
                  }
                  goto LAB_030b3012;
                }
                if ((iVar1 == 0) ||
                   (*(char *)(iStack_90 * (uint)*(byte *)(iVar10 + 0x87f) + iVar11 + iVar21 + 0xad4)
                    != '\r')) {
LAB_030b2fec:
                  piVar4 = piVar20;
                  uVar15 = uVar17;
                  if (0 < (int)uVar17) {
                    do {
                      iVar19 = *(int *)(iVar11 + 0xbe0) * DAT_030b3240 + iVar3;
                      *(int *)(iVar11 + 0xbe0) = iVar19;
                      *piVar4 = iVar19 >> 0x10;
                      uVar15 = uVar15 - 1;
                      piVar4 = piVar4 + 1;
                    } while (uVar15 != 0);
                  }
                }
                else if (*(int *)(iVar11 + 0xbc4) == 1) {
                  if ((uStack_4c & 1) == 0) goto LAB_030b2fec;
                }
                else if (*(int *)(iVar11 + 0xbc4) != 2) goto LAB_030b2fec;
LAB_030b3012:
                iVar3 = 0;
                uVar15 = (uint)*(short *)(iVar11 + param_2 * 0xf0 +
                                          (iStack_90 * (uint)*(byte *)(iVar10 + 0x87f) + iVar21) * 2
                                         + 0x8f4);
                if (0 < (int)(uVar17 - 1)) {
                  piVar4 = piVar20 + -1;
                  if ((uVar17 & 1) == 0) {
                    iVar3 = *piVar20 * *piVar20 >> 8;
                    piVar4 = piVar20;
                  }
                  iVar19 = piVar4[1];
                  iVar18 = 0;
                  for (iVar16 = (int)(uVar17 - 1) >> 1; iVar16 != 0; iVar16 = iVar16 + -1) {
                    iVar3 = iVar3 + (iVar19 * iVar19 >> 8);
                    iVar23 = piVar4[2];
                    iVar19 = piVar4[3];
                    iVar18 = iVar18 + (iVar23 * iVar23 >> 8);
                    piVar4 = piVar4 + 2;
                  }
                  iVar3 = iVar3 + iVar18;
                }
                if (-1 < (int)(uVar17 - 1)) {
                  iVar3 = iVar3 + (piVar20[uVar17 - 1] * piVar20[uVar17 - 1] >> 8);
                }
                if (iVar3 == 0) {
                  uVar15 = 0;
                }
                else {
                  uVar6 = *(undefined4 *)(*DAT_030b3244 + (uVar15 & 3) * 4);
                  iVar19 = FUN_030b38ce(iVar3);
                  uVar7 = iVar19 - 2;
                  iVar3 = iVar3 << (uVar7 & 0xfe);
                  iVar19 = FUN_030b38c4(iVar3,0xc0000000);
                  iVar19 = iVar19 * 4 + 0x60000000;
                  iVar18 = 0;
                  do {
                    uVar8 = FUN_030b38c4(iVar19);
                    iVar16 = FUN_030b38c4(iVar3,uVar8);
                    iVar19 = FUN_030b38c4(iVar19,iVar16 * -4 + 0xc000000);
                    iVar19 = iVar19 << 5;
                    iVar18 = iVar18 + 1;
                  } while (iVar18 < 4);
                  if (iVar19 >> 0x1e != 0) {
                    iVar19 = 0x3fffffff;
                  }
                  iVar3 = FUN_030b38ce(iVar19);
                  uVar7 = ((((int)uVar15 >> 2) -
                           (0xf - ((int)((uVar7 & 0xfffffffe) - ((int)uVar7 >> 0x1f)) >> 1))) -
                          (iVar3 - 1U)) + 6;
                  uVar6 = FUN_030b38c4(uVar6,iVar19 << (iVar3 - 1U & 0xff));
                  uVar15 = 0;
                  if ((int)uVar7 < 0) {
                    uVar7 = -uVar7;
                    if (0x1f < (int)uVar7) {
                      uVar7 = 0x1f;
                    }
                    iVar3 = 0;
                    if (0 < (int)uVar17) {
                      do {
                        iVar19 = FUN_030b38c4(piVar20[iVar3],uVar6);
                        iVar19 = iVar19 >> (uVar7 & 0xff);
                        uVar9 = FUN_030b38f2(iVar19);
                        piVar20[iVar3] = iVar19;
                        uVar15 = uVar15 | uVar9;
                        iVar3 = iVar3 + 1;
                      } while (iVar3 < (int)uVar17);
                    }
                  }
                  else {
                    if (0x10 < (int)uVar7) {
                      uVar7 = 0x10;
                    }
                    iVar3 = 0;
                    if (0 < (int)uVar17) {
                      do {
                        iVar19 = FUN_030b38c4(piVar20[iVar3] << (uVar7 & 0xff),uVar6);
                        piVar20[iVar3] = iVar19;
                        uVar9 = FUN_030b38f2();
                        uVar15 = uVar15 | uVar9;
                        iVar3 = iVar3 + 1;
                      } while (iVar3 < (int)uVar17);
                    }
                  }
                }
                uStack_44 = uStack_44 | uVar15;
              }
              uVar22 = uVar22 + 1;
              uStack_4c = uStack_4c >> 1;
              piVar20 = piVar20 + uVar17;
              if (uVar22 == 8) {
                uVar22 = 0;
                uStack_4c = (uint)*pbStack_64;
                pbStack_64 = pbStack_64 + 1;
              }
              iVar21 = iVar21 + 1;
            } while (iVar21 < (int)(uint)*(byte *)(iVar10 + 0x87f));
          }
          piVar20 = piVar20 + (iVar13 - *(short *)(iStack_58 + (uint)*(byte *)(iVar10 + 0x87f) * 2))
          ;
          iStack_48 = iStack_48 + 1;
        } while (iStack_48 < (int)(uint)*(byte *)(iVar2 + 0x32));
      }
      iStack_54 = iStack_54 + (uint)*(byte *)(iVar10 + 0x87f);
      iStack_90 = iStack_90 + 1;
    } while (iStack_90 < (int)(uint)*(byte *)(iVar10 + 0x8ad));
  }
  iVar10 = FUN_030b38ce(uStack_44);
  iVar11 = iVar10 + -1;
  if (*(int *)(iVar12 + 0x1040) <= iVar10 + -1) {
    iVar11 = *(int *)(iVar12 + 0x1040);
  }
  *(int *)(iVar12 + 0x1040) = iVar11;
  return 0;
}


