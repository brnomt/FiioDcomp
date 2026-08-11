/**
 * FUN_030b1bc0 @ 0x030b1bc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b1bc0(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  uint auStack_78 [5];
  int iStack_64;
  int iStack_60;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  uint uStack_48;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int *local_2c;
  int iStack_28;
  
  iStack_50 = 0;
  if (param_1 != (int *)0x0) {
    iStack_50 = *param_1;
  }
  if (param_1 != (int *)0x0 && iStack_50 != 0) {
    if (param_2 == 1) {
      param_3 = *(int *)(iStack_50 + 0x8f0);
    }
    iVar5 = iStack_50;
    if (param_2 != 1 || param_3 != 1) {
      iVar5 = iStack_50 + param_2 * 0x3a;
    }
    if (*(char *)(iVar5 + 0x87d) == '\x02') {
      iStack_64 = *DAT_030b1f18 + *(int *)(*DAT_030b1f14 + *(int *)(iStack_50 + 0x878) * 4) * 2;
      iStack_4c = 0x80;
    }
    else {
      iStack_64 = *DAT_030b1f0c + *(int *)(*DAT_030b1f08 + *(int *)(iStack_50 + 0x878) * 4) * 2;
      iStack_4c = 0x400;
    }
    piVar15 = (int *)(iStack_50 + param_2 * 0x1000 + 0x1048);
    auStack_78[4] = iStack_50 + param_2 * 0xf0 + 0x8f4;
    iStack_60 = iStack_50 + param_2 * 0x78 + 0xad4;
    iStack_50 = iStack_50 + param_2 * 4;
    *(undefined4 *)(iStack_50 + 0xbe4) = 0;
    *(undefined4 *)(iStack_50 + 0xbd8) = 0;
    iStack_54 = 0;
    uStack_48 = 0;
    local_2c = param_1;
    iStack_28 = param_2;
    if (*(char *)(iVar5 + 0x8ad) != '\0') {
      do {
        iStack_3c = 0;
        iStack_38 = iVar5 + 0x87c + iStack_54;
        if (*(char *)(iStack_38 + 0x32) != '\0') {
          do {
            iVar12 = 0;
            if (*(char *)(iVar5 + 0x87f) != '\0') {
              do {
                bVar1 = *(byte *)(iStack_60 + iVar12);
                iVar6 = (int)*(short *)(iStack_64 + iVar12 * 2 + 2) -
                        (int)*(short *)(iStack_64 + iVar12 * 2);
                iStack_58 = iVar6;
                if (bVar1 < 0xc) {
                  if (iVar6 < 1) {
                    uVar14 = 0;
                  }
                  else {
                    uVar14 = (int)*(short *)(auStack_78[4] + iVar12 * 2) - 100;
                    uVar7 = uVar14 & 3;
                    iVar13 = DAT_030b1f10[1] + uVar7 * 0x40;
                    iVar8 = *(int *)(*DAT_030b1f10 + uVar7 * 4);
                    iVar17 = ((int)uVar14 >> 2) + 5;
                    uVar14 = 0x1c - iVar17;
                    if ((int)uVar14 < 0x20) {
                      if ((int)uVar14 < 1) {
                        uVar7 = -uVar14;
                        if (uVar14 != 0xffffffe1 && 0x1e < (int)uVar7) {
                          uVar7 = 0x1f;
                        }
                        iVar2 = 0;
                        do {
                          iVar16 = *(int *)(iVar13 + iVar2 * 4);
                          if ((int)(0x3fffffffU >> (uVar7 & 0xff)) < iVar16) {
                            uVar14 = 0x3fffffff;
                          }
                          else {
                            uVar14 = iVar16 << (uVar7 & 0xff);
                          }
                          auStack_78[iVar2] = uVar14;
                          iVar2 = iVar2 + 1;
                        } while (iVar2 < 4);
                      }
                      else {
                        auStack_78[0] = 0;
                        auStack_78[1] = *(int *)(iVar13 + 4) >> (uVar14 & 0xff);
                        auStack_78[2] = *(int *)(iVar13 + 8) >> (uVar14 & 0xff);
                        auStack_78[3] = *(int *)(iVar13 + 0xc) >> (uVar14 & 0xff);
                      }
                    }
                    else {
                      auStack_78[3] = 0;
                      auStack_78[2] = 0;
                      auStack_78[1] = 0;
                      auStack_78[0] = 0;
                    }
                    iStack_34 = 0x18 - iVar17;
                    uVar14 = 0;
                    piVar11 = piVar15;
                    do {
                      iVar16 = *piVar11;
                      iVar2 = FUN_030b38f2(iVar16);
                      if (iVar2 < 4) {
                        uVar7 = auStack_78[iVar2];
                      }
                      else {
                        if (iVar2 < 0x10) {
                          iVar2 = *(int *)(iVar13 + iVar2 * 4);
                          uVar7 = 0x19 - iVar17;
                        }
                        else if (iVar2 < 0x40) {
                          uVar7 = 0x15 - iVar17;
                          iVar2 = (int)((ulonglong)
                                        ((longlong)*(int *)(DAT_030b1f10[2] + iVar2 * 4 + -0x40) *
                                        (longlong)iVar8) >> 0x20);
                        }
                        else {
                          iVar4 = iVar2 * 0x20000;
                          iVar9 = 0;
                          if (iVar4 < 0x8000000) {
                            iVar4 = iVar2 << 0x15;
                            iVar9 = 4;
                          }
                          if (iVar4 < 0x20000000) {
                            iVar4 = iVar4 << 2;
                            iVar9 = iVar9 + 2;
                          }
                          if (iVar4 < 0x40000000) {
                            iVar4 = iVar4 << 1;
                            iVar9 = iVar9 + 1;
                          }
                          if (iVar4 < DAT_030b1f1c) {
                            piVar10 = (int *)DAT_030b1f10[3];
                          }
                          else {
                            piVar10 = (int *)DAT_030b1f10[4];
                          }
                          iVar2 = (int)((ulonglong)
                                        ((longlong)
                                         ((int)((ulonglong)
                                                ((longlong)
                                                 (piVar10[4] +
                                                 (int)((ulonglong)
                                                       ((longlong)
                                                        ((int)((ulonglong)
                                                               ((longlong)
                                                                ((int)((ulonglong)
                                                                       ((longlong)
                                                                        ((int)((ulonglong)
                                                                               ((longlong)*piVar10 *
                                                                               (longlong)iVar4) >>
                                                                              0x20) + piVar10[1]) *
                                                                       (longlong)iVar4) >> 0x20) +
                                                                piVar10[2]) * (longlong)iVar4) >>
                                                              0x20) + piVar10[3]) * (longlong)iVar4)
                                                      >> 0x20)) *
                                                (longlong)*(int *)(DAT_030b1f10[6] + iVar9 * 4)) >>
                                               0x20) << 3) * (longlong)iVar8) >> 0x20);
                          uVar7 = iStack_34 - *(int *)(DAT_030b1f10[5] + iVar9 * 4);
                        }
                        if ((int)uVar7 < 1) {
                          uVar3 = -uVar7;
                          if (uVar7 != 0xffffffe1 && 0x1e < (int)uVar3) {
                            uVar3 = 0x1f;
                          }
                          if ((int)(0x3fffffffU >> (uVar3 & 0xff)) < iVar2) {
                            uVar7 = 0x3fffffff;
                          }
                          else {
                            uVar7 = iVar2 << (uVar3 & 0xff);
                          }
                        }
                        else {
                          if (0x1f < (int)uVar7) {
                            uVar7 = 0x1f;
                          }
                          uVar7 = iVar2 >> (uVar7 & 0xff);
                        }
                      }
                      uVar14 = uVar14 | uVar7;
                      uVar3 = iVar16 >> 0x1f;
                      *piVar11 = (uVar7 ^ uVar3) - uVar3;
                      iVar6 = iVar6 + -1;
                      piVar11 = piVar11 + 1;
                    } while (iVar6 != 0);
                  }
                  uStack_48 = uVar14 | uStack_48;
                }
                else if (bVar1 == 0xd) {
                  *(undefined4 *)(iStack_50 + 0xbd8) = 1;
                }
                else if (bVar1 == 0xe || bVar1 == 0xf) {
                  *(undefined4 *)(iStack_50 + 0xbe4) = 1;
                }
                iVar12 = iVar12 + 1;
                piVar15 = piVar15 + iStack_58;
              } while (iVar12 < (int)(uint)*(byte *)(iVar5 + 0x87f));
            }
            piVar15 = piVar15 + (iStack_4c -
                                *(short *)(iStack_64 + (uint)*(byte *)(iVar5 + 0x87f) * 2));
            iStack_3c = iStack_3c + 1;
          } while (iStack_3c < (int)(uint)*(byte *)(iStack_38 + 0x32));
        }
        iStack_60 = iStack_60 + (uint)*(byte *)(iVar5 + 0x87f);
        auStack_78[4] = auStack_78[4] + (uint)*(byte *)(iVar5 + 0x87f) * 2;
        iStack_54 = iStack_54 + 1;
      } while (iStack_54 < (int)(uint)*(byte *)(iVar5 + 0x8ad));
    }
    local_2c[0x16] = local_2c[0x16] | *(uint *)(iStack_50 + 0xbd8);
    iVar5 = FUN_030b38ce(uStack_48);
    *(int *)(iStack_50 + 0x1040) = iVar5 + -1;
    return 0;
  }
  return 0xfffffffe;
}


