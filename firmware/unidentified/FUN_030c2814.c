/**
 * FUN_030c2814 @ 0x030c2814
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c2814(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int extraout_r3;
  int extraout_r3_00;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined4 extraout_r12;
  undefined4 extraout_r12_00;
  bool bVar17;
  bool bVar18;
  uint local_38;
  
  memset_byte(param_2,0,0x40);
  iVar4 = FUN_030ce7f0(param_1,0x18);
  FUN_030ce75e(param_1,0x18);
  if (iVar4 != DAT_030c2bfc) goto LAB_030c3a20;
  uVar5 = FUN_030ce7f0(param_1,0x10);
  FUN_030ce75e(param_1,0x10);
  *param_2 = uVar5;
  uVar5 = FUN_030ce7f0(param_1,0x18);
  FUN_030ce75e(param_1,0x18);
  param_2[1] = uVar5;
  if (uVar5 == 0xffffffff) goto LAB_030c3a20;
  iVar4 = FUN_030ce7f0(param_1,1);
  FUN_030ce75e(param_1,1);
  if (iVar4 == 0) {
    iVar6 = FUN_030ca4a0(param_2[1]);
    iVar4 = FUN_030ce7f0(param_1,1);
    FUN_030ce75e(param_1,1);
    if (iVar4 == 0) {
      iVar4 = 0;
      param_2[2] = param_2[1];
      if (0 < (int)param_2[1]) {
        uVar5 = *(uint *)(DAT_030c314c + 0x14);
        do {
          uVar14 = *param_1;
          uVar9 = param_1[2];
          iVar8 = uVar14 + 5;
          if (iVar8 < (int)(uVar9 * 8)) {
            pbVar11 = (byte *)param_1[1];
            unaff_r6 = (uint)(*pbVar11 >> (uVar14 & 0xff));
            if ((((8 < iVar8) &&
                 (unaff_r6 = unaff_r6 | (uint)pbVar11[1] << (8 - uVar14 & 0xff), 0x10 < iVar8)) &&
                (unaff_r6 = unaff_r6 | (uint)pbVar11[2] << (0x10 - uVar14 & 0xff), 0x18 < iVar8)) &&
               ((unaff_r6 = unaff_r6 | (uint)pbVar11[3] << (0x18 - uVar14 & 0xff), 0x20 < iVar8 &&
                (uVar14 != 0)))) {
              unaff_r6 = unaff_r6 | (uint)pbVar11[4] << (0x20 - uVar14 & 0xff);
            }
LAB_030c2e84:
            uVar9 = unaff_r6 & uVar5;
            unaff_r6 = uVar9;
          }
          else {
            pbVar11 = (byte *)param_1[1];
            piVar7 = (int *)param_1[3];
            if (-1 < (int)uVar9) {
              if (uVar14 != 0xfffffffb) {
                while (uVar9 == 0) {
                  piVar7 = (int *)piVar7[3];
                  if (piVar7 == (int *)0x0) goto LAB_030c2e36;
                  pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                  uVar9 = piVar7[2];
                }
                pbVar12 = pbVar11 + 1;
                unaff_r6 = (uint)(*pbVar11 >> (uVar14 & 0xff));
                if (8 < iVar8) {
                  iVar16 = uVar9 - 1;
                  while (iVar16 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c2e36;
                    pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                    iVar16 = piVar7[2];
                  }
                  pbVar11 = pbVar12 + 1;
                  unaff_r6 = (uint)*pbVar12 << (8 - uVar14 & 0xff) | unaff_r6;
                  if (0x10 < iVar8) {
                    iVar16 = iVar16 + -1;
                    while (iVar16 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c2e36;
                      pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                      iVar16 = piVar7[2];
                    }
                    pbVar12 = pbVar11 + 1;
                    unaff_r6 = (uint)*pbVar11 << (0x10 - uVar14 & 0xff) | unaff_r6;
                    if (0x18 < iVar8) {
                      iVar16 = iVar16 + -1;
                      while (iVar16 == 0) {
                        piVar7 = (int *)piVar7[3];
                        if (piVar7 == (int *)0x0) goto LAB_030c2e36;
                        pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                        iVar16 = piVar7[2];
                      }
                      pbVar11 = pbVar12 + 1;
                      unaff_r6 = (uint)*pbVar12 << (0x18 - uVar14 & 0xff) | unaff_r6;
                      if ((0x20 < iVar8) && (uVar14 != 0)) {
                        if (iVar16 == 1) {
                          do {
                            piVar7 = (int *)piVar7[3];
                            if (piVar7 == (int *)0x0) goto LAB_030c2e36;
                            pbVar11 = (byte *)(piVar7[1] + *piVar7);
                          } while (piVar7[2] == 0);
                        }
                        unaff_r6 = unaff_r6 | (uint)*pbVar11 << (0x20 - uVar14 & 0xff);
                      }
                    }
                  }
                }
              }
              goto LAB_030c2e84;
            }
LAB_030c2e36:
            uVar9 = 0xffffffff;
          }
          *param_1 = uVar14 + 5 & 7;
          iVar8 = (int)(uVar14 + 5) >> 3;
          param_1[2] = param_1[2] - iVar8;
          param_1[1] = param_1[1] + iVar8;
          if ((int)param_1[2] < 1) {
            uVar14 = param_1[2] - ((int)*param_1 >> 3);
            while ((int)uVar14 < 1) {
              uVar10 = *param_1 & 7;
              uVar14 = param_1[2] - ((int)*param_1 >> 3);
              *param_1 = uVar10;
              param_1[2] = uVar14;
              uVar15 = param_1[3];
              if (*(int *)(uVar15 + 0xc) == 0) {
                if ((int)(param_1[2] * 8) < (int)uVar10) {
                  param_1[2] = 0xffffffff;
                }
                break;
              }
              param_1[5] = param_1[5] + *(int *)(uVar15 + 8);
              piVar7 = *(int **)(uVar15 + 0xc);
              param_1[3] = (uint)piVar7;
              if (0 < (int)(piVar7[2] + uVar14)) {
                param_1[1] = (*piVar7 + piVar7[1]) - uVar14;
              }
              uVar14 = piVar7[2] + uVar14;
              param_1[2] = uVar14;
            }
          }
          iVar8 = uVar9 + 1;
          if (iVar8 == 0) goto LAB_030c3a20;
          *(char *)(iVar6 + iVar4) = (char)iVar8;
          uVar14 = param_2[3];
          if ((int)uVar14 < iVar8) {
            uVar14 = uVar9 + 1;
          }
          iVar4 = iVar4 + 1;
          param_2[3] = uVar14;
        } while (iVar4 < (int)param_2[1]);
      }
    }
    else {
      iVar4 = 0;
      if (0 < (int)param_2[1]) {
        uVar9 = *(uint *)(DAT_030c2c00 + 4);
        uVar5 = *(uint *)(DAT_030c2c00 + 0x14);
        do {
          uVar15 = *param_1;
          uVar14 = param_1[2];
          iVar8 = uVar15 + 1;
          if (iVar8 < (int)(uVar14 * 8)) {
            pbVar11 = (byte *)param_1[1];
            unaff_r6 = (uint)(*pbVar11 >> (uVar15 & 0xff));
            if (((8 < iVar8) &&
                (unaff_r6 = unaff_r6 | (uint)pbVar11[1] << (8 - uVar15 & 0xff), 0x10 < iVar8)) &&
               ((unaff_r6 = unaff_r6 | (uint)pbVar11[2] << (0x10 - uVar15 & 0xff), 0x18 < iVar8 &&
                ((unaff_r6 = unaff_r6 | (uint)pbVar11[3] << (0x18 - uVar15 & 0xff), 0x20 < iVar8 &&
                 (uVar15 != 0)))))) {
              unaff_r6 = unaff_r6 | (uint)pbVar11[4] << (0x20 - uVar15 & 0xff);
            }
LAB_030c2a44:
            unaff_r6 = unaff_r6 & uVar9;
            uVar14 = unaff_r6;
          }
          else {
            pbVar11 = (byte *)param_1[1];
            piVar7 = (int *)param_1[3];
            if (-1 < (int)uVar14) {
              if (uVar15 != 0xffffffff) {
                while (uVar14 == 0) {
                  piVar7 = (int *)piVar7[3];
                  if (piVar7 == (int *)0x0) goto LAB_030c29ec;
                  pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                  uVar14 = piVar7[2];
                }
                pbVar12 = pbVar11 + 1;
                unaff_r6 = (uint)(*pbVar11 >> (uVar15 & 0xff));
                if (8 < iVar8) {
                  iVar16 = uVar14 - 1;
                  while (iVar16 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c29ec;
                    pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                    iVar16 = piVar7[2];
                  }
                  pbVar11 = pbVar12 + 1;
                  unaff_r6 = (uint)*pbVar12 << (8 - uVar15 & 0xff) | unaff_r6;
                  if (0x10 < iVar8) {
                    iVar16 = iVar16 + -1;
                    while (iVar16 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c29ec;
                      pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                      iVar16 = piVar7[2];
                    }
                    pbVar12 = pbVar11 + 1;
                    unaff_r6 = (uint)*pbVar11 << (0x10 - uVar15 & 0xff) | unaff_r6;
                    if (0x18 < iVar8) {
                      iVar16 = iVar16 + -1;
                      while (iVar16 == 0) {
                        piVar7 = (int *)piVar7[3];
                        if (piVar7 == (int *)0x0) goto LAB_030c29ec;
                        pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                        iVar16 = piVar7[2];
                      }
                      pbVar11 = pbVar12 + 1;
                      unaff_r6 = (uint)*pbVar12 << (0x18 - uVar15 & 0xff) | unaff_r6;
                      if ((0x20 < iVar8) && (uVar15 != 0)) {
                        if (iVar16 == 1) {
                          do {
                            piVar7 = (int *)piVar7[3];
                            if (piVar7 == (int *)0x0) goto LAB_030c29ec;
                            pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                          } while (piVar7[2] == 0);
                        }
                        unaff_r6 = unaff_r6 | (uint)*pbVar11 << (0x20 - uVar15 & 0xff);
                      }
                    }
                  }
                }
              }
              goto LAB_030c2a44;
            }
LAB_030c29ec:
            uVar14 = 0xffffffff;
          }
          *param_1 = uVar15 + 1 & 7;
          iVar8 = (int)(uVar15 + 1) >> 3;
          param_1[2] = param_1[2] - iVar8;
          param_1[1] = param_1[1] + iVar8;
          if ((int)param_1[2] < 1) {
            uVar15 = param_1[2] - ((int)*param_1 >> 3);
            while ((int)uVar15 < 1) {
              uVar13 = *param_1 & 7;
              uVar15 = param_1[2] - ((int)*param_1 >> 3);
              *param_1 = uVar13;
              param_1[2] = uVar15;
              uVar10 = param_1[3];
              if (*(int *)(uVar10 + 0xc) == 0) {
                if ((int)(param_1[2] * 8) < (int)uVar13) {
                  param_1[2] = 0xffffffff;
                }
                break;
              }
              param_1[5] = param_1[5] + *(int *)(uVar10 + 8);
              piVar7 = *(int **)(uVar10 + 0xc);
              param_1[3] = (uint)piVar7;
              if (0 < (int)(piVar7[2] + uVar15)) {
                param_1[1] = (*piVar7 + piVar7[1]) - uVar15;
              }
              uVar15 = uVar15 + piVar7[2];
              param_1[2] = uVar15;
            }
          }
          if (uVar14 == 0) {
            *(undefined1 *)(iVar6 + iVar4) = 0;
          }
          else {
            uVar15 = *param_1;
            uVar14 = param_1[2];
            iVar8 = uVar15 + 5;
            if (iVar8 < (int)(uVar14 * 8)) {
              pbVar11 = (byte *)param_1[1];
              local_38 = (uint)(*pbVar11 >> (uVar15 & 0xff));
              if ((((8 < iVar8) &&
                   (local_38 = local_38 | (uint)pbVar11[1] << (8 - uVar15 & 0xff), 0x10 < iVar8)) &&
                  (local_38 = local_38 | (uint)pbVar11[2] << (0x10 - uVar15 & 0xff), 0x18 < iVar8))
                 && ((local_38 = local_38 | (uint)pbVar11[3] << (0x18 - uVar15 & 0xff), 0x20 < iVar8
                     && (uVar15 != 0)))) {
                local_38 = local_38 | (uint)pbVar11[4] << (0x20 - uVar15 & 0xff);
              }
LAB_030c2c7a:
              uVar14 = local_38 & uVar5;
              local_38 = uVar14;
            }
            else {
              pbVar11 = (byte *)param_1[1];
              piVar7 = (int *)param_1[3];
              if (-1 < (int)uVar14) {
                if (uVar15 != 0xfffffffb) {
                  while (uVar14 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c2c08;
                    pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                    uVar14 = piVar7[2];
                  }
                  pbVar12 = pbVar11 + 1;
                  local_38 = (uint)(*pbVar11 >> (uVar15 & 0xff));
                  if (8 < iVar8) {
                    iVar16 = uVar14 - 1;
                    while (iVar16 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c2c08;
                      pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                      iVar16 = piVar7[2];
                    }
                    pbVar11 = pbVar12 + 1;
                    local_38 = (uint)*pbVar12 << (8 - uVar15 & 0xff) | local_38;
                    if (0x10 < iVar8) {
                      iVar16 = iVar16 + -1;
                      while (iVar16 == 0) {
                        piVar7 = (int *)piVar7[3];
                        if (piVar7 == (int *)0x0) goto LAB_030c2c08;
                        pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                        iVar16 = piVar7[2];
                      }
                      pbVar12 = pbVar11 + 1;
                      local_38 = (uint)*pbVar11 << (0x10 - uVar15 & 0xff) | local_38;
                      if (0x18 < iVar8) {
                        iVar16 = iVar16 + -1;
                        while (iVar16 == 0) {
                          piVar7 = (int *)piVar7[3];
                          if (piVar7 == (int *)0x0) goto LAB_030c2c08;
                          pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                          iVar16 = piVar7[2];
                        }
                        pbVar11 = pbVar12 + 1;
                        local_38 = (uint)*pbVar12 << (0x18 - uVar15 & 0xff) | local_38;
                        if ((0x20 < iVar8) && (uVar15 != 0)) {
                          if (iVar16 == 1) {
                            do {
                              piVar7 = (int *)piVar7[3];
                              if (piVar7 == (int *)0x0) goto LAB_030c2c08;
                              pbVar11 = (byte *)(piVar7[1] + *piVar7);
                            } while (piVar7[2] == 0);
                          }
                          local_38 = (uint)*pbVar11 << (0x20 - uVar15 & 0xff) | local_38;
                        }
                      }
                    }
                  }
                }
                goto LAB_030c2c7a;
              }
LAB_030c2c08:
              uVar14 = 0xffffffff;
            }
            *param_1 = uVar15 + 5 & 7;
            iVar8 = (int)(uVar15 + 5) >> 3;
            param_1[2] = param_1[2] - iVar8;
            param_1[1] = param_1[1] + iVar8;
            if ((int)param_1[2] < 1) {
              uVar15 = param_1[2] - ((int)*param_1 >> 3);
              while ((int)uVar15 < 1) {
                uVar15 = param_1[2] - ((int)*param_1 >> 3);
                uVar13 = *param_1 & 7;
                *param_1 = uVar13;
                param_1[2] = uVar15;
                uVar10 = param_1[3];
                if (*(int *)(uVar10 + 0xc) == 0) {
                  if ((int)(uVar15 * 8) < (int)uVar13) {
                    param_1[2] = 0xffffffff;
                  }
                  break;
                }
                param_1[5] = param_1[5] + *(int *)(uVar10 + 8);
                piVar7 = *(int **)(uVar10 + 0xc);
                param_1[3] = (uint)piVar7;
                if (0 < (int)(piVar7[2] + uVar15)) {
                  param_1[1] = (*piVar7 + piVar7[1]) - uVar15;
                }
                uVar15 = piVar7[2] + uVar15;
                param_1[2] = uVar15;
              }
            }
            iVar8 = uVar14 + 1;
            if (iVar8 == 0) goto LAB_030c3a20;
            *(char *)(iVar6 + iVar4) = (char)iVar8;
            param_2[2] = param_2[2] + 1;
            uVar15 = param_2[3];
            if ((int)uVar15 < iVar8) {
              uVar15 = uVar14 + 1;
            }
            param_2[3] = uVar15;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)param_2[1]);
      }
    }
  }
  else {
    if (iVar4 != 1) goto LAB_030c3a20;
    local_38 = FUN_030ce7f0(param_1,5);
    FUN_030ce75e(param_1,5);
    param_2[2] = param_2[1];
    iVar6 = FUN_030ca4a0();
    uVar5 = param_2[1];
    iVar4 = 0;
    if (0 < (int)uVar5) {
      do {
        local_38 = local_38 + 1;
        iVar8 = 0;
        for (uVar5 = uVar5 - iVar4; uVar5 != 0; uVar5 = uVar5 >> 1) {
          iVar8 = iVar8 + 1;
        }
        uVar14 = *param_1;
        uVar5 = param_1[2];
        uVar9 = iVar8 + uVar14;
        if ((int)uVar9 < (int)(uVar5 * 8)) {
          pbVar11 = (byte *)param_1[1];
          unaff_r6 = (uint)(*pbVar11 >> (uVar14 & 0xff));
          if ((((8 < (int)uVar9) &&
               (unaff_r6 = unaff_r6 | (uint)pbVar11[1] << (8 - uVar14 & 0xff), 0x10 < (int)uVar9))
              && (unaff_r6 = unaff_r6 | (uint)pbVar11[2] << (0x10 - uVar14 & 0xff),
                 0x18 < (int)uVar9)) &&
             ((unaff_r6 = unaff_r6 | (uint)pbVar11[3] << (0x18 - uVar14 & 0xff), 0x20 < (int)uVar9
              && (uVar14 != 0)))) {
            unaff_r6 = unaff_r6 | (uint)pbVar11[4] << (0x20 - uVar14 & 0xff);
          }
LAB_030c30e8:
          uVar5 = unaff_r6 & *(uint *)(DAT_030c314c + iVar8 * 4);
          unaff_r6 = uVar5;
        }
        else {
          pbVar11 = (byte *)param_1[1];
          piVar7 = (int *)param_1[3];
          if (-1 < (int)uVar5) {
            if (uVar9 != 0) {
              while (uVar5 == 0) {
                piVar7 = (int *)piVar7[3];
                if (piVar7 == (int *)0x0) goto LAB_030c3090;
                pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                uVar5 = piVar7[2];
              }
              pbVar12 = pbVar11 + 1;
              unaff_r6 = (uint)(*pbVar11 >> (uVar14 & 0xff));
              if (8 < (int)uVar9) {
                iVar16 = uVar5 - 1;
                while (iVar16 == 0) {
                  piVar7 = (int *)piVar7[3];
                  if (piVar7 == (int *)0x0) goto LAB_030c3090;
                  pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                  iVar16 = piVar7[2];
                }
                pbVar11 = pbVar12 + 1;
                unaff_r6 = (uint)*pbVar12 << (8 - uVar14 & 0xff) | unaff_r6;
                if (0x10 < (int)uVar9) {
                  iVar16 = iVar16 + -1;
                  while (iVar16 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c3090;
                    pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                    iVar16 = piVar7[2];
                  }
                  pbVar12 = pbVar11 + 1;
                  unaff_r6 = (uint)*pbVar11 << (0x10 - uVar14 & 0xff) | unaff_r6;
                  if (0x18 < (int)uVar9) {
                    iVar16 = iVar16 + -1;
                    while (iVar16 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c3090;
                      pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                      iVar16 = piVar7[2];
                    }
                    pbVar11 = pbVar12 + 1;
                    unaff_r6 = (uint)*pbVar12 << (0x18 - uVar14 & 0xff) | unaff_r6;
                    if ((0x20 < (int)uVar9) && (uVar14 != 0)) {
                      if (iVar16 == 1) {
                        do {
                          piVar7 = (int *)piVar7[3];
                          if (piVar7 == (int *)0x0) goto LAB_030c3090;
                          pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                        } while (piVar7[2] == 0);
                      }
                      unaff_r6 = unaff_r6 | (uint)*pbVar11 << (0x20 - uVar14 & 0xff);
                    }
                  }
                }
              }
            }
            goto LAB_030c30e8;
          }
LAB_030c3090:
          uVar5 = 0xffffffff;
        }
        *param_1 = uVar9 & 7;
        param_1[2] = param_1[2] - ((int)uVar9 >> 3);
        param_1[1] = param_1[1] + ((int)uVar9 >> 3);
        if ((int)param_1[2] < 1) {
          uVar9 = param_1[2] - ((int)*param_1 >> 3);
          while ((int)uVar9 < 1) {
            uVar15 = *param_1 & 7;
            uVar9 = param_1[2] - ((int)*param_1 >> 3);
            param_1[2] = uVar9;
            *param_1 = uVar15;
            uVar14 = param_1[3];
            if (*(int *)(uVar14 + 0xc) == 0) {
              if ((int)(uVar9 * 8) < (int)uVar15) {
                param_1[2] = 0xffffffff;
              }
              break;
            }
            param_1[5] = param_1[5] + *(int *)(uVar14 + 8);
            piVar7 = *(int **)(uVar14 + 0xc);
            param_1[3] = (uint)piVar7;
            if (0 < (int)(piVar7[2] + uVar9)) {
              param_1[1] = (*piVar7 + piVar7[1]) - uVar9;
            }
            uVar9 = piVar7[2] + uVar9;
            param_1[2] = uVar9;
          }
        }
        if (uVar5 == 0xffffffff) goto LAB_030c3a20;
        iVar8 = 0;
        while( true ) {
          bVar17 = SBORROW4(iVar8,uVar5);
          iVar16 = iVar8 - uVar5;
          if (iVar8 < (int)uVar5) {
            bVar17 = SBORROW4(iVar4,param_2[1]);
            iVar16 = iVar4 - param_2[1];
          }
          if (iVar16 < 0 == bVar17) break;
          *(char *)(iVar6 + iVar4) = (char)local_38;
          iVar8 = iVar8 + 1;
          iVar4 = iVar4 + 1;
        }
        param_2[3] = local_38;
        uVar5 = param_2[1];
      } while (iVar4 < (int)uVar5);
    }
  }
  iVar4 = FUN_030ce7f0(param_1,4);
  FUN_030ce75e(param_1,4);
  if (0 < iVar4) {
    uVar14 = FUN_030ce7f0(param_1,0x20);
    FUN_030ce75e(param_1,0x20);
    uVar9 = DAT_030c3600;
    param_2[9] = ((uVar14 & 0x7fffffff) >> 0x15) - 0x314;
    uVar5 = uVar14 & 0x1fffff;
    if ((uVar14 & 0x1fffff) == 0) {
      param_2[9] = uVar9;
      uVar5 = 0;
    }
    else {
      do {
        uVar15 = uVar5;
        uVar5 = uVar15 * 2;
        param_2[9] = param_2[9] - 1;
      } while ((uVar5 & 0x40000000) == 0);
      if ((uVar14 & 0x80000000) != 0) {
        uVar5 = uVar15 * -2;
      }
    }
    param_2[8] = uVar5;
    uVar14 = FUN_030ce7f0(param_1,0x20);
    FUN_030ce75e(param_1,0x20);
    param_2[0xb] = ((uVar14 & 0x7fffffff) >> 0x15) - 0x314;
    uVar5 = uVar14 & 0x1fffff;
    if ((uVar14 & 0x1fffff) == 0) {
      param_2[0xb] = uVar9;
      uVar5 = 0;
    }
    else {
      do {
        uVar9 = uVar5;
        uVar5 = uVar9 * 2;
        param_2[0xb] = param_2[0xb] - 1;
      } while ((uVar5 & 0x40000000) == 0);
      if ((uVar14 & 0x80000000) != 0) {
        uVar5 = uVar9 * -2;
      }
    }
    param_2[10] = uVar5;
    iVar8 = FUN_030ce7f0(param_1,4);
    FUN_030ce75e(param_1,4);
    param_2[0xd] = iVar8 + 1;
    uVar5 = FUN_030ce7f0(param_1,1);
    FUN_030ce75e(param_1,1);
    param_2[0xc] = uVar5;
    param_2[10] = (int)param_2[10] >> (param_2[0xd] & 0xff);
    param_2[0xb] = param_2[0xd] + param_2[0xb];
  }
  uVar5 = DAT_030c3604;
  if (iVar4 == 0) {
    iVar4 = 0;
    for (uVar5 = param_2[1]; uVar5 != 0; uVar5 = uVar5 >> 1) {
      iVar4 = iVar4 + 1;
    }
    uVar9 = FUN_030c22a6(param_2[2],((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) + 1);
    param_2[5] = uVar9;
    iVar4 = 0;
    for (uVar5 = param_2[1]; uVar5 != 0; uVar5 = uVar5 >> 1) {
      iVar4 = iVar4 + 1;
    }
    if ((int)uVar9 < extraout_r3 + ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3)) {
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
    param_2[6] = uVar5;
    param_2[7] = 0;
    iVar4 = FUN_030c243e(param_2,iVar6,0,param_1);
joined_r0x030c331e:
    if (iVar4 != 0) goto LAB_030c3a20;
  }
  else if (iVar4 == 1) {
    iVar4 = 0;
    uVar9 = param_2[1];
    for (uVar5 = uVar9; uVar5 != 0; uVar5 = uVar5 >> 1) {
      iVar4 = iVar4 + 1;
    }
    uVar14 = *param_2;
    uVar5 = (int)uVar9 >> ((int)((uVar14 - 1) * (iVar4 + -1)) / (int)uVar14 & 0xffU);
    while( true ) {
      uVar15 = 1;
      uVar10 = 1;
      if (0 < (int)uVar14) {
        if ((uVar14 & 1) != 0) {
          uVar10 = uVar5 + 1;
          uVar15 = uVar5;
        }
        iVar4 = (int)uVar14 >> 1;
        if (iVar4 != 0) {
          do {
            uVar15 = uVar5 * uVar5 * uVar15;
            uVar10 = (uVar5 + 1) * (uVar5 + 1) * uVar10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
      bVar17 = SBORROW4(uVar9,uVar15);
      iVar4 = uVar9 - uVar15;
      uVar13 = uVar15;
      if ((int)uVar15 <= (int)uVar9) {
        bVar17 = SBORROW4(uVar10,uVar9);
        iVar4 = uVar10 - uVar9;
        uVar13 = uVar10;
      }
      if (uVar9 != uVar13 && iVar4 < 0 == bVar17) break;
      if ((int)uVar9 < (int)uVar15) {
        uVar5 = uVar5 - 1;
      }
      else {
        uVar5 = uVar5 + 1;
      }
    }
    uVar15 = param_2[0xd];
    iVar4 = uVar15 * uVar14 + 8;
    iVar8 = (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3;
    iVar4 = 0;
    for (uVar9 = uVar5 - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
      iVar4 = iVar4 + 1;
    }
    iVar4 = iVar4 * uVar14 + 8;
    iVar16 = ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) +
             ((int)(uVar15 + 7 + ((uint)((int)(uVar15 + 7) >> 0x1f) >> 0x1d)) >> 3);
    bVar18 = SBORROW4(iVar8,4);
    iVar4 = iVar8 + -4;
    bVar17 = iVar8 == 4;
    if (iVar8 < 5) {
      bVar18 = SBORROW4(iVar8,iVar16);
      iVar4 = iVar8 - iVar16;
      bVar17 = iVar8 == iVar16;
    }
    if (!bVar17 && iVar4 < 0 == bVar18) {
      param_2[0xf] = DAT_030c3604;
      if ((int)uVar15 < 9) {
        iVar4 = 0;
        if (0 < (int)uVar5) {
          do {
            uVar15 = *param_1;
            uVar9 = param_1[2];
            uVar14 = uVar15 + param_2[0xd];
            if ((int)uVar14 < (int)(uVar9 * 8)) {
              pbVar11 = (byte *)param_1[1];
              unaff_r7 = (uint)(*pbVar11 >> (uVar15 & 0xff));
              if ((((8 < (int)uVar14) &&
                   (unaff_r7 = unaff_r7 | (uint)pbVar11[1] << (8 - uVar15 & 0xff),
                   0x10 < (int)uVar14)) &&
                  (unaff_r7 = unaff_r7 | (uint)pbVar11[2] << (0x10 - uVar15 & 0xff),
                  0x18 < (int)uVar14)) &&
                 ((unaff_r7 = unaff_r7 | (uint)pbVar11[3] << (0x18 - uVar15 & 0xff),
                  0x20 < (int)uVar14 && (uVar15 != 0)))) {
                unaff_r7 = unaff_r7 | (uint)pbVar11[4] << (0x20 - uVar15 & 0xff);
              }
LAB_030c3784:
              unaff_r7 = unaff_r7 & *(uint *)(DAT_030c3a1c + param_2[0xd] * 4);
              uVar2 = (undefined1)unaff_r7;
            }
            else {
              pbVar11 = (byte *)param_1[1];
              piVar7 = (int *)param_1[3];
              if (-1 < (int)uVar9) {
                if (uVar14 != 0) {
                  while (uVar9 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c3738;
                    pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                    uVar9 = piVar7[2];
                  }
                  pbVar12 = pbVar11 + 1;
                  unaff_r7 = (uint)(*pbVar11 >> (uVar15 & 0xff));
                  if (8 < (int)uVar14) {
                    iVar8 = uVar9 - 1;
                    while (iVar8 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c3738;
                      pbVar12 = (byte *)(piVar7[1] + *piVar7);
                      iVar8 = piVar7[2];
                    }
                    pbVar11 = pbVar12 + 1;
                    unaff_r7 = (uint)*pbVar12 << (8 - uVar15 & 0xff) | unaff_r7;
                    if (0x10 < (int)uVar14) {
                      iVar8 = iVar8 + -1;
                      while (iVar8 == 0) {
                        piVar7 = (int *)piVar7[3];
                        if (piVar7 == (int *)0x0) goto LAB_030c3738;
                        pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                        iVar8 = piVar7[2];
                      }
                      pbVar12 = pbVar11 + 1;
                      unaff_r7 = (uint)*pbVar11 << (0x10 - uVar15 & 0xff) | unaff_r7;
                      if (0x18 < (int)uVar14) {
                        iVar8 = iVar8 + -1;
                        while (iVar8 == 0) {
                          piVar7 = (int *)piVar7[3];
                          if (piVar7 == (int *)0x0) goto LAB_030c3738;
                          pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                          iVar8 = piVar7[2];
                        }
                        pbVar11 = pbVar12 + 1;
                        unaff_r7 = (uint)*pbVar12 << (0x18 - uVar15 & 0xff) | unaff_r7;
                        if ((0x20 < (int)uVar14) && (uVar15 != 0)) {
                          if (iVar8 == 1) {
                            do {
                              piVar7 = (int *)piVar7[3];
                              if (piVar7 == (int *)0x0) goto LAB_030c3738;
                              pbVar11 = (byte *)(piVar7[1] + *piVar7);
                            } while (piVar7[2] == 0);
                          }
                          unaff_r7 = unaff_r7 | (uint)*pbVar11 << (0x20 - uVar15 & 0xff);
                        }
                      }
                    }
                  }
                }
                goto LAB_030c3784;
              }
LAB_030c3738:
              uVar2 = 0xff;
            }
            *param_1 = uVar14 & 7;
            param_1[2] = param_1[2] - ((int)uVar14 >> 3);
            param_1[1] = param_1[1] + ((int)uVar14 >> 3);
            if ((int)param_1[2] < 1) {
              uVar9 = param_1[2] - ((int)*param_1 >> 3);
              while ((int)uVar9 < 1) {
                uVar9 = param_1[2] - ((int)*param_1 >> 3);
                uVar14 = *param_1 & 7;
                param_1[2] = uVar9;
                *param_1 = uVar14;
                uVar15 = param_1[3];
                if (*(int *)(uVar15 + 0xc) == 0) {
                  if ((int)(uVar9 * 8) < (int)uVar14) {
                    param_1[2] = 0xffffffff;
                  }
                  break;
                }
                param_1[5] = param_1[5] + *(int *)(uVar15 + 8);
                piVar7 = *(int **)(uVar15 + 0xc);
                param_1[3] = (uint)piVar7;
                if (0 < (int)(piVar7[2] + uVar9)) {
                  param_1[1] = (*piVar7 + piVar7[1]) - uVar9;
                }
                uVar9 = piVar7[2] + uVar9;
                param_1[2] = uVar9;
              }
            }
            *(undefined1 *)(param_2[0xf] + iVar4) = uVar2;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar5);
        }
      }
      else {
        iVar4 = 0;
        if (0 < (int)uVar5) {
          do {
            uVar9 = param_2[0xd];
            uVar3 = FUN_030ce7f0(param_1,uVar9);
            FUN_030ce75e(param_1,uVar9);
            *(undefined2 *)(param_2[0xf] + iVar4 * 2) = uVar3;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar5);
        }
      }
      if ((int)param_1[2] < 0) goto LAB_030c3a20;
      uVar14 = 0;
      for (uVar9 = uVar5 - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
        uVar14 = uVar14 + 1;
      }
      param_2[0xe] = uVar14;
      param_2[7] = 2;
      iVar4 = 0;
      for (uVar9 = uVar5 - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
        iVar4 = iVar4 + 1;
      }
      iVar4 = iVar4 * *param_2 + 8;
      uVar14 = FUN_030c22a6(param_2[2],(int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3);
      param_2[5] = uVar14;
      iVar4 = 0;
      for (uVar9 = uVar5 - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
        iVar4 = iVar4 + 1;
      }
      iVar4 = iVar4 * *param_2 + 8;
      if ((int)uVar14 < (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) {
        uVar9 = 2;
      }
      else {
        uVar9 = 1;
      }
      param_2[6] = uVar9;
      iVar4 = FUN_030c243e(param_2,iVar6,uVar5,param_1);
      goto joined_r0x030c331e;
    }
    iVar4 = 0;
    param_2[0xf] = DAT_030c3604;
    if (0 < (int)uVar5) {
      do {
        uVar15 = *param_1;
        uVar9 = param_1[2];
        uVar14 = uVar15 + param_2[0xd];
        if ((int)uVar14 < (int)(uVar9 * 8)) {
          pbVar11 = (byte *)param_1[1];
          unaff_r7 = (uint)(*pbVar11 >> (uVar15 & 0xff));
          if ((((8 < (int)uVar14) &&
               (unaff_r7 = unaff_r7 | (uint)pbVar11[1] << (8 - uVar15 & 0xff), 0x10 < (int)uVar14))
              && (unaff_r7 = unaff_r7 | (uint)pbVar11[2] << (0x10 - uVar15 & 0xff),
                 0x18 < (int)uVar14)) &&
             ((unaff_r7 = unaff_r7 | (uint)pbVar11[3] << (0x18 - uVar15 & 0xff), 0x20 < (int)uVar14
              && (uVar15 != 0)))) {
            unaff_r7 = unaff_r7 | (uint)pbVar11[4] << (0x20 - uVar15 & 0xff);
          }
LAB_030c3510:
          unaff_r7 = unaff_r7 & *(uint *)(DAT_030c3608 + param_2[0xd] * 4);
          uVar3 = (undefined2)unaff_r7;
        }
        else {
          pbVar11 = (byte *)param_1[1];
          piVar7 = (int *)param_1[3];
          if (-1 < (int)uVar9) {
            if (uVar14 != 0) {
              while (uVar9 == 0) {
                piVar7 = (int *)piVar7[3];
                if (piVar7 == (int *)0x0) goto LAB_030c34c4;
                pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                uVar9 = piVar7[2];
              }
              pbVar12 = pbVar11 + 1;
              unaff_r7 = (uint)(*pbVar11 >> (uVar15 & 0xff));
              if (8 < (int)uVar14) {
                iVar8 = uVar9 - 1;
                while (iVar8 == 0) {
                  piVar7 = (int *)piVar7[3];
                  if (piVar7 == (int *)0x0) goto LAB_030c34c4;
                  pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                  iVar8 = piVar7[2];
                }
                pbVar11 = pbVar12 + 1;
                unaff_r7 = (uint)*pbVar12 << (8 - uVar15 & 0xff) | unaff_r7;
                if (0x10 < (int)uVar14) {
                  iVar8 = iVar8 + -1;
                  while (iVar8 == 0) {
                    piVar7 = (int *)piVar7[3];
                    if (piVar7 == (int *)0x0) goto LAB_030c34c4;
                    pbVar11 = (byte *)(*piVar7 + piVar7[1]);
                    iVar8 = piVar7[2];
                  }
                  pbVar12 = pbVar11 + 1;
                  unaff_r7 = (uint)*pbVar11 << (0x10 - uVar15 & 0xff) | unaff_r7;
                  if (0x18 < (int)uVar14) {
                    iVar8 = iVar8 + -1;
                    while (iVar8 == 0) {
                      piVar7 = (int *)piVar7[3];
                      if (piVar7 == (int *)0x0) goto LAB_030c34c4;
                      pbVar12 = (byte *)(*piVar7 + piVar7[1]);
                      iVar8 = piVar7[2];
                    }
                    pbVar11 = pbVar12 + 1;
                    unaff_r7 = (uint)*pbVar12 << (0x18 - uVar15 & 0xff) | unaff_r7;
                    if ((0x20 < (int)uVar14) && (uVar15 != 0)) {
                      if (iVar8 == 1) {
                        do {
                          piVar7 = (int *)piVar7[3];
                          if (piVar7 == (int *)0x0) goto LAB_030c34c4;
                          pbVar11 = (byte *)(piVar7[1] + *piVar7);
                        } while (piVar7[2] == 0);
                      }
                      unaff_r7 = unaff_r7 | (uint)*pbVar11 << (0x20 - uVar15 & 0xff);
                    }
                  }
                }
              }
            }
            goto LAB_030c3510;
          }
LAB_030c34c4:
          uVar3 = 0xffff;
        }
        *param_1 = uVar14 & 7;
        param_1[2] = param_1[2] - ((int)uVar14 >> 3);
        param_1[1] = param_1[1] + ((int)uVar14 >> 3);
        if ((int)param_1[2] < 1) {
          uVar9 = param_1[2] - ((int)*param_1 >> 3);
          while ((int)uVar9 < 1) {
            uVar9 = param_1[2] - ((int)*param_1 >> 3);
            uVar14 = *param_1 & 7;
            param_1[2] = uVar9;
            *param_1 = uVar14;
            uVar15 = param_1[3];
            if (*(int *)(uVar15 + 0xc) == 0) {
              if ((int)(uVar9 * 8) < (int)uVar14) {
                param_1[2] = 0xffffffff;
              }
              break;
            }
            param_1[5] = *(int *)(uVar15 + 8) + param_1[5];
            piVar7 = *(int **)(uVar15 + 0xc);
            param_1[3] = (uint)piVar7;
            if (0 < (int)(piVar7[2] + uVar9)) {
              param_1[1] = (*piVar7 + piVar7[1]) - uVar9;
            }
            uVar9 = piVar7[2] + uVar9;
            param_1[2] = uVar9;
          }
        }
        *(undefined2 *)(param_2[0xf] + iVar4 * 2) = uVar3;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)uVar5);
    }
    uVar9 = DAT_030c3604;
    if ((int)param_1[2] < 0) {
      param_2[0xf] = 0;
      memset_byte(uVar9,0,100);
      param_2[0xf] = 0;
      goto LAB_030c3a20;
    }
    param_2[7] = 1;
    iVar4 = *param_2 * param_2[0xd] + 8;
    uVar9 = FUN_030c22a6(param_2[2],(int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3);
    param_2[5] = uVar9;
    iVar4 = *param_2 * param_2[0xd] + 8;
    if ((int)uVar9 < (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) {
      uVar9 = 2;
    }
    else {
      uVar9 = 1;
    }
    param_2[6] = uVar9;
    iVar4 = FUN_030c243e(param_2,iVar6,uVar5,param_1);
    uVar1 = DAT_030c3a18;
    param_2[0xf] = 0;
    if (iVar4 != 0) {
      memset_byte(uVar1,0,100);
      goto LAB_030c3a20;
    }
    memset_byte(uVar1,0,100);
    param_2[0xf] = 0;
  }
  else {
    if (iVar4 != 2) goto LAB_030c3a20;
    if ((int)(param_2[0xd] * *param_2 + 8) < 0x28) {
      iVar4 = param_2[0xd] * *param_2 + 8;
      param_2[7] = 1;
      uVar5 = FUN_030c22a6(param_2[2],(int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3);
      param_2[5] = uVar5;
      iVar4 = *param_2 * param_2[0xd] + 8;
      if ((int)uVar5 < (int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
      param_2[6] = uVar5;
      iVar4 = FUN_030c243e(param_2,iVar6,extraout_r12,param_1);
      goto joined_r0x030c331e;
    }
    param_2[7] = 3;
    iVar4 = 0;
    for (uVar9 = param_2[2] - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
      iVar4 = iVar4 + 1;
    }
    uVar14 = FUN_030c22a6(param_2[2],((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3) + 1);
    param_2[5] = uVar14;
    iVar4 = 0;
    for (uVar9 = param_2[2] - 1; uVar9 != 0; uVar9 = uVar9 >> 1) {
      iVar4 = iVar4 + 1;
    }
    if ((int)uVar14 < extraout_r3_00 + ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3)) {
      uVar9 = 2;
    }
    else {
      uVar9 = 1;
    }
    param_2[6] = uVar9;
    iVar4 = FUN_030c243e(param_2,iVar6,extraout_r12_00,param_1);
    if (iVar4 != 0) goto LAB_030c3a20;
    iVar6 = 0;
    iVar4 = param_2[0xd] + 7;
    param_2[0xe] = *param_2 * ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1d)) >> 3);
    param_2[0xf] = uVar5;
    iVar4 = param_2[2] * *param_2;
    if ((int)param_2[0xd] < 9) {
      if (0 < iVar4) {
        do {
          uVar5 = param_2[0xd];
          uVar2 = FUN_030ce7f0(param_1,uVar5);
          FUN_030ce75e(param_1,uVar5);
          *(undefined1 *)(param_2[0xf] + iVar6) = uVar2;
          iVar6 = iVar6 + 1;
        } while (*param_2 * param_2[2] - iVar6 != 0 && iVar6 <= (int)(*param_2 * param_2[2]));
      }
    }
    else if (0 < iVar4) {
      do {
        uVar5 = param_2[0xd];
        uVar3 = FUN_030ce7f0(param_1,uVar5);
        FUN_030ce75e(param_1,uVar5);
        *(undefined2 *)(param_2[0xf] + iVar6 * 2) = uVar3;
        iVar6 = iVar6 + 1;
      } while (*param_2 * param_2[2] - iVar6 != 0 && iVar6 <= (int)(*param_2 * param_2[2]));
    }
  }
  if (-1 < (int)param_1[2]) {
    FUN_030ca488();
    return 0;
  }
LAB_030c3a20:
  param_2[0xf] = 0;
  memset_byte(DAT_030c3e24,0,100);
  memset_byte(param_2,0,0x40);
  FUN_030ca488();
  return 0xffffffff;
}


