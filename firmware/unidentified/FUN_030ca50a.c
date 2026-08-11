/**
 * FUN_030ca50a @ 0x030ca50a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ca50a(uint *param_1,int param_2,uint *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint unaff_r4;
  uint unaff_r7;
  uint unaff_r8;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint local_48;
  
  iVar3 = *(int *)(param_2 + 0x1c);
  memset_byte(param_1,0,0x1c);
  uVar4 = sbuf_read_bits(param_3,0x10);
  *param_1 = uVar4;
  if (uVar4 < 3) {
    uVar4 = sbuf_read_bits(param_3,0x18);
    param_1[3] = uVar4;
    uVar4 = sbuf_read_bits(param_3,0x18);
    param_1[4] = uVar4;
    iVar5 = sbuf_read_bits(param_3,0x18);
    param_1[5] = iVar5 + 1;
    cVar1 = sbuf_read_bits(param_3,6);
    *(char *)(param_1 + 6) = cVar1 + '\x01';
    bVar2 = sbuf_read_bits(param_3,8);
    *(byte *)((int)param_1 + 0x19) = bVar2;
    uVar4 = DAT_030ca8e8;
    if ((int)(uint)bVar2 < *(int *)(iVar3 + 0x18)) {
      param_1[1] = DAT_030ca8e8;
      param_1[2] = uVar4 + 10;
      iVar5 = 0;
      bVar2 = 0;
      if ((char)param_1[6] != '\0') {
        uVar7 = *(uint *)(DAT_030ca8f0 + 0xc);
        uVar8 = *(uint *)(DAT_030ca8f0 + 4);
        uVar4 = *(uint *)(DAT_030ca8f0 + 0x14);
        do {
          uVar11 = *param_3;
          uVar14 = param_3[2];
          iVar12 = uVar11 + 3;
          if (iVar12 < (int)(uVar14 * 8)) {
            pbVar9 = (byte *)param_3[1];
            unaff_r7 = (uint)(*pbVar9 >> (uVar11 & 0xff));
            if ((((8 < iVar12) &&
                 (unaff_r7 = unaff_r7 | (uint)pbVar9[1] << (8 - uVar11 & 0xff), 0x10 < iVar12)) &&
                (unaff_r7 = unaff_r7 | (uint)pbVar9[2] << (0x10 - uVar11 & 0xff), 0x18 < iVar12)) &&
               ((unaff_r7 = unaff_r7 | (uint)pbVar9[3] << (0x18 - uVar11 & 0xff), 0x20 < iVar12 &&
                (uVar11 != 0)))) {
              uVar14 = (uint)pbVar9[4] << (0x20 - uVar11 & 0xff);
LAB_030ca6ea:
              unaff_r7 = unaff_r7 | uVar14;
            }
LAB_030ca6ec:
            unaff_r7 = unaff_r7 & uVar7;
            bVar2 = (byte)unaff_r7;
          }
          else {
            pbVar9 = (byte *)param_3[1];
            piVar6 = (int *)param_3[3];
            if (-1 < (int)uVar14) {
              if (uVar11 != 0xfffffffd) {
                while (uVar14 == 0) {
                  piVar6 = (int *)piVar6[3];
                  if (piVar6 == (int *)0x0) goto LAB_030ca698;
                  pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                  uVar14 = piVar6[2];
                }
                pbVar10 = pbVar9 + 1;
                unaff_r7 = (uint)(*pbVar9 >> (uVar11 & 0xff));
                if (8 < iVar12) {
                  iVar15 = uVar14 - 1;
                  while (iVar15 == 0) {
                    piVar6 = (int *)piVar6[3];
                    if (piVar6 == (int *)0x0) goto LAB_030ca698;
                    pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                    iVar15 = piVar6[2];
                  }
                  pbVar9 = pbVar10 + 1;
                  unaff_r7 = (uint)*pbVar10 << (8 - uVar11 & 0xff) | unaff_r7;
                  if (0x10 < iVar12) {
                    iVar15 = iVar15 + -1;
                    while (iVar15 == 0) {
                      piVar6 = (int *)piVar6[3];
                      if (piVar6 == (int *)0x0) goto LAB_030ca698;
                      pbVar9 = (byte *)(piVar6[1] + *piVar6);
                      iVar15 = piVar6[2];
                    }
                    pbVar10 = pbVar9 + 1;
                    unaff_r7 = (uint)*pbVar9 << (0x10 - uVar11 & 0xff) | unaff_r7;
                    if (0x18 < iVar12) {
                      iVar15 = iVar15 + -1;
                      while (iVar15 == 0) {
                        piVar6 = (int *)piVar6[3];
                        if (piVar6 == (int *)0x0) goto LAB_030ca698;
                        pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                        iVar15 = piVar6[2];
                      }
                      pbVar9 = pbVar10 + 1;
                      unaff_r7 = (uint)*pbVar10 << (0x18 - uVar11 & 0xff) | unaff_r7;
                      if ((0x20 < iVar12) && (uVar11 != 0)) {
                        if (iVar15 == 1) {
                          do {
                            piVar6 = (int *)piVar6[3];
                            if (piVar6 == (int *)0x0) goto LAB_030ca698;
                            pbVar9 = (byte *)(piVar6[1] + *piVar6);
                          } while (piVar6[2] == 0);
                        }
                        uVar14 = (uint)*pbVar9 << (0x20 - uVar11 & 0xff);
                        goto LAB_030ca6ea;
                      }
                    }
                  }
                }
              }
              goto LAB_030ca6ec;
            }
LAB_030ca698:
            bVar2 = 0xff;
          }
          *param_3 = uVar11 + 3 & 7;
          iVar12 = (int)(uVar11 + 3) >> 3;
          param_3[2] = param_3[2] - iVar12;
          param_3[1] = param_3[1] + iVar12;
          if ((int)param_3[2] < 1) {
            uVar14 = param_3[2] - ((int)*param_3 >> 3);
            while ((int)uVar14 < 1) {
              uVar14 = param_3[2] - ((int)*param_3 >> 3);
              uVar11 = *param_3 & 7;
              param_3[2] = uVar14;
              *param_3 = uVar11;
              uVar13 = param_3[3];
              if (*(int *)(uVar13 + 0xc) == 0) {
                if ((int)(uVar14 * 8) < (int)uVar11) {
                  param_3[2] = 0xffffffff;
                }
                break;
              }
              param_3[5] = *(int *)(uVar13 + 8) + param_3[5];
              piVar6 = *(int **)(uVar13 + 0xc);
              param_3[3] = (uint)piVar6;
              if (0 < (int)(piVar6[2] + uVar14)) {
                param_3[1] = (piVar6[1] + *piVar6) - uVar14;
              }
              uVar14 = piVar6[2] + uVar14;
              param_3[2] = uVar14;
            }
          }
          uVar11 = *param_3;
          uVar14 = param_3[2];
          iVar12 = uVar11 + 1;
          pbVar9 = (byte *)param_3[1];
          if (iVar12 < (int)(uVar14 * 8)) {
            unaff_r8 = (uint)(*pbVar9 >> (uVar11 & 0xff));
            if (((8 < iVar12) &&
                (unaff_r8 = (uint)pbVar9[1] << (8 - uVar11 & 0xff) | unaff_r8, 0x10 < iVar12)) &&
               ((unaff_r8 = (uint)pbVar9[2] << (0x10 - uVar11 & 0xff) | unaff_r8, 0x18 < iVar12 &&
                ((unaff_r8 = (uint)pbVar9[3] << (0x18 - uVar11 & 0xff) | unaff_r8, 0x20 < iVar12 &&
                 (uVar11 != 0)))))) {
              unaff_r8 = (uint)pbVar9[4] << (0x20 - uVar11 & 0xff) | unaff_r8;
            }
LAB_030ca906:
            uVar14 = unaff_r8 & uVar8;
            unaff_r8 = uVar14;
          }
          else {
            piVar6 = (int *)param_3[3];
            if (-1 < (int)uVar14) {
              if (uVar11 != 0xffffffff) {
                while (uVar14 == 0) {
                  piVar6 = (int *)piVar6[3];
                  if (piVar6 == (int *)0x0) goto LAB_030ca89a;
                  pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                  uVar14 = piVar6[2];
                }
                pbVar10 = pbVar9 + 1;
                unaff_r8 = (uint)(*pbVar9 >> (uVar11 & 0xff));
                if (8 < iVar12) {
                  iVar15 = uVar14 - 1;
                  while (iVar15 == 0) {
                    piVar6 = (int *)piVar6[3];
                    if (piVar6 == (int *)0x0) goto LAB_030ca89a;
                    pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                    iVar15 = piVar6[2];
                  }
                  pbVar9 = pbVar10 + 1;
                  unaff_r8 = (uint)*pbVar10 << (8 - uVar11 & 0xff) | unaff_r8;
                  if (0x10 < iVar12) {
                    iVar15 = iVar15 + -1;
                    while (iVar15 == 0) {
                      piVar6 = (int *)piVar6[3];
                      if (piVar6 == (int *)0x0) goto LAB_030ca89a;
                      pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                      iVar15 = piVar6[2];
                    }
                    pbVar10 = pbVar9 + 1;
                    unaff_r8 = (uint)*pbVar9 << (0x10 - uVar11 & 0xff) | unaff_r8;
                    if (0x18 < iVar12) {
                      iVar15 = iVar15 + -1;
                      while (iVar15 == 0) {
                        piVar6 = (int *)piVar6[3];
                        if (piVar6 == (int *)0x0) goto LAB_030ca89a;
                        pbVar10 = (byte *)(piVar6[1] + *piVar6);
                        iVar15 = piVar6[2];
                      }
                      pbVar9 = pbVar10 + 1;
                      unaff_r8 = (uint)*pbVar10 << (0x18 - uVar11 & 0xff) | unaff_r8;
                      if ((0x20 < iVar12) && (uVar11 != 0)) {
                        if (iVar15 == 1) {
                          do {
                            piVar6 = (int *)piVar6[3];
                            if (piVar6 == (int *)0x0) goto LAB_030ca89a;
                            pbVar9 = (byte *)(piVar6[1] + *piVar6);
                          } while (piVar6[2] == 0);
                        }
                        unaff_r8 = (uint)*pbVar9 << (0x20 - uVar11 & 0xff) | unaff_r8;
                      }
                    }
                  }
                }
              }
              goto LAB_030ca906;
            }
LAB_030ca89a:
            uVar14 = 0xffffffff;
          }
          *param_3 = uVar11 + 1 & 7;
          iVar12 = (int)(uVar11 + 1) >> 3;
          param_3[2] = param_3[2] - iVar12;
          param_3[1] = param_3[1] + iVar12;
          if ((int)param_3[2] < 1) {
            uVar11 = param_3[2] - ((int)*param_3 >> 3);
            while ((int)uVar11 < 1) {
              uVar16 = *param_3 & 7;
              uVar11 = param_3[2] - ((int)*param_3 >> 3);
              *param_3 = uVar16;
              param_3[2] = uVar11;
              uVar13 = param_3[3];
              if (*(int *)(uVar13 + 0xc) == 0) {
                if ((int)(uVar11 * 8) < (int)uVar16) {
                  param_3[2] = 0xffffffff;
                }
                break;
              }
              param_3[5] = param_3[5] + *(int *)(uVar13 + 8);
              piVar6 = *(int **)(uVar13 + 0xc);
              param_3[3] = (uint)piVar6;
              if (0 < (int)(piVar6[2] + uVar11)) {
                param_3[1] = (*piVar6 + piVar6[1]) - uVar11;
              }
              uVar11 = piVar6[2] + uVar11;
              param_3[2] = uVar11;
            }
          }
          if (uVar14 != 0) {
            uVar11 = *param_3;
            uVar14 = param_3[2];
            iVar12 = uVar11 + 5;
            pbVar9 = (byte *)param_3[1];
            if (iVar12 < (int)(uVar14 * 8)) {
              local_48 = (uint)(*pbVar9 >> (uVar11 & 0xff));
              if ((((8 < iVar12) &&
                   (local_48 = (uint)pbVar9[1] << (8 - uVar11 & 0xff) | local_48, 0x10 < iVar12)) &&
                  (local_48 = (uint)pbVar9[2] << (0x10 - uVar11 & 0xff) | local_48, 0x18 < iVar12))
                 && ((local_48 = (uint)pbVar9[3] << (0x18 - uVar11 & 0xff) | local_48, 0x20 < iVar12
                     && (uVar11 != 0)))) {
                local_48 = (uint)pbVar9[4] << (0x20 - uVar11 & 0xff) | local_48;
              }
LAB_030cab82:
              uVar14 = local_48 & uVar4;
              local_48 = uVar14;
            }
            else {
              piVar6 = (int *)param_3[3];
              if (-1 < (int)uVar14) {
                if (uVar11 != 0xfffffffb) {
                  while (uVar14 == 0) {
                    piVar6 = (int *)piVar6[3];
                    if (piVar6 == (int *)0x0) goto LAB_030caafe;
                    pbVar9 = (byte *)(piVar6[1] + *piVar6);
                    uVar14 = piVar6[2];
                  }
                  pbVar10 = pbVar9 + 1;
                  local_48 = (uint)(*pbVar9 >> (uVar11 & 0xff));
                  if (8 < iVar12) {
                    iVar15 = uVar14 - 1;
                    while (iVar15 == 0) {
                      piVar6 = (int *)piVar6[3];
                      if (piVar6 == (int *)0x0) goto LAB_030caafe;
                      pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                      iVar15 = piVar6[2];
                    }
                    pbVar9 = pbVar10 + 1;
                    local_48 = (uint)*pbVar10 << (8 - uVar11 & 0xff) | local_48;
                    if (0x10 < iVar12) {
                      iVar15 = iVar15 + -1;
                      while (iVar15 == 0) {
                        piVar6 = (int *)piVar6[3];
                        if (piVar6 == (int *)0x0) goto LAB_030caafe;
                        pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                        iVar15 = piVar6[2];
                      }
                      pbVar10 = pbVar9 + 1;
                      local_48 = (uint)*pbVar9 << (0x10 - uVar11 & 0xff) | local_48;
                      if (0x18 < iVar12) {
                        iVar15 = iVar15 + -1;
                        while (iVar15 == 0) {
                          piVar6 = (int *)piVar6[3];
                          if (piVar6 == (int *)0x0) goto LAB_030caafe;
                          pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                          iVar15 = piVar6[2];
                        }
                        pbVar9 = pbVar10 + 1;
                        local_48 = (uint)*pbVar10 << (0x18 - uVar11 & 0xff) | local_48;
                        if ((0x20 < iVar12) && (uVar11 != 0)) {
                          if (iVar15 == 1) {
                            do {
                              piVar6 = (int *)piVar6[3];
                              if (piVar6 == (int *)0x0) goto LAB_030caafe;
                              pbVar9 = (byte *)(piVar6[1] + *piVar6);
                            } while (piVar6[2] == 0);
                          }
                          local_48 = (uint)*pbVar9 << (0x20 - uVar11 & 0xff) | local_48;
                        }
                      }
                    }
                  }
                }
                goto LAB_030cab82;
              }
LAB_030caafe:
              uVar14 = 0xffffffff;
            }
            *param_3 = uVar11 + 5 & 7;
            iVar12 = (int)(uVar11 + 5) >> 3;
            param_3[2] = param_3[2] - iVar12;
            param_3[1] = param_3[1] + iVar12;
            if ((int)param_3[2] < 1) {
              uVar11 = param_3[2] - ((int)*param_3 >> 3);
              while ((int)uVar11 < 1) {
                uVar16 = *param_3 & 7;
                uVar11 = param_3[2] - ((int)*param_3 >> 3);
                *param_3 = uVar16;
                param_3[2] = uVar11;
                uVar13 = param_3[3];
                if (*(int *)(uVar13 + 0xc) == 0) {
                  if ((int)(param_3[2] * 8) < (int)uVar16) {
                    param_3[2] = 0xffffffff;
                  }
                  break;
                }
                param_3[5] = param_3[5] + *(int *)(uVar13 + 8);
                piVar6 = *(int **)(uVar13 + 0xc);
                param_3[3] = (uint)piVar6;
                if (0 < (int)(piVar6[2] + uVar11)) {
                  param_3[1] = (*piVar6 + piVar6[1]) - uVar11;
                }
                uVar11 = uVar11 + piVar6[2];
                param_3[2] = uVar11;
              }
            }
            bVar2 = bVar2 | (byte)(uVar14 << 3);
          }
          *(byte *)(param_1[1] + iVar5) = bVar2;
          bVar2 = (byte)param_1[6];
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uint)bVar2);
      }
      iVar5 = 0;
      if (bVar2 != 0) {
        uVar4 = *(uint *)(DAT_030cb038 + 0x20);
        do {
          uVar7 = 0;
          do {
            if ((*(byte *)(param_1[1] + iVar5) >> (uVar7 & 0xff) & 1) == 0) {
              *(undefined1 *)(param_1[2] + uVar7 + iVar5 * 8) = 0xff;
            }
            else {
              uVar14 = *param_3;
              uVar8 = param_3[2];
              iVar12 = uVar14 + 8;
              pbVar9 = (byte *)param_3[1];
              if (iVar12 < (int)(uVar8 * 8)) {
                unaff_r4 = (uint)(*pbVar9 >> (uVar14 & 0xff));
                if ((((8 < iVar12) &&
                     (unaff_r4 = unaff_r4 | (uint)pbVar9[1] << (8 - uVar14 & 0xff), 0x10 < iVar12))
                    && (unaff_r4 = unaff_r4 | (uint)pbVar9[2] << (0x10 - uVar14 & 0xff),
                       0x18 < iVar12)) &&
                   ((unaff_r4 = unaff_r4 | (uint)pbVar9[3] << (0x18 - uVar14 & 0xff), 0x20 < iVar12
                    && (uVar14 != 0)))) {
                  uVar8 = (uint)pbVar9[4] << (0x20 - uVar14 & 0xff);
LAB_030cadb4:
                  unaff_r4 = unaff_r4 | uVar8;
                }
LAB_030cadb6:
                unaff_r4 = unaff_r4 & uVar4;
                uVar8 = unaff_r4;
              }
              else {
                piVar6 = (int *)param_3[3];
                if (-1 < (int)uVar8) {
                  if (uVar14 != 0xfffffff8) {
                    while (uVar8 == 0) {
                      piVar6 = (int *)piVar6[3];
                      if (piVar6 == (int *)0x0) goto LAB_030cad62;
                      pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                      uVar8 = piVar6[2];
                    }
                    pbVar10 = pbVar9 + 1;
                    unaff_r4 = (uint)(*pbVar9 >> (uVar14 & 0xff));
                    if (8 < iVar12) {
                      iVar15 = uVar8 - 1;
                      while (iVar15 == 0) {
                        piVar6 = (int *)piVar6[3];
                        if (piVar6 == (int *)0x0) goto LAB_030cad62;
                        pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                        iVar15 = piVar6[2];
                      }
                      pbVar9 = pbVar10 + 1;
                      unaff_r4 = (uint)*pbVar10 << (8 - uVar14 & 0xff) | unaff_r4;
                      if (0x10 < iVar12) {
                        iVar15 = iVar15 + -1;
                        while (iVar15 == 0) {
                          piVar6 = (int *)piVar6[3];
                          if (piVar6 == (int *)0x0) goto LAB_030cad62;
                          pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                          iVar15 = piVar6[2];
                        }
                        pbVar10 = pbVar9 + 1;
                        unaff_r4 = (uint)*pbVar9 << (0x10 - uVar14 & 0xff) | unaff_r4;
                        if (0x18 < iVar12) {
                          iVar15 = iVar15 + -1;
                          while (iVar15 == 0) {
                            piVar6 = (int *)piVar6[3];
                            if (piVar6 == (int *)0x0) goto LAB_030cad62;
                            pbVar10 = (byte *)(*piVar6 + piVar6[1]);
                            iVar15 = piVar6[2];
                          }
                          pbVar9 = pbVar10 + 1;
                          unaff_r4 = (uint)*pbVar10 << (0x18 - uVar14 & 0xff) | unaff_r4;
                          if ((0x20 < iVar12) && (uVar14 != 0)) {
                            if (iVar15 == 1) {
                              do {
                                piVar6 = (int *)piVar6[3];
                                if (piVar6 == (int *)0x0) goto LAB_030cad62;
                                pbVar9 = (byte *)(*piVar6 + piVar6[1]);
                              } while (piVar6[2] == 0);
                            }
                            uVar8 = (uint)*pbVar9 << (0x20 - uVar14 & 0xff);
                            goto LAB_030cadb4;
                          }
                        }
                      }
                    }
                  }
                  goto LAB_030cadb6;
                }
LAB_030cad62:
                uVar8 = 0xffffffff;
              }
              *param_3 = uVar14 + 8 & 7;
              iVar12 = (int)(uVar14 + 8) >> 3;
              param_3[2] = param_3[2] - iVar12;
              param_3[1] = param_3[1] + iVar12;
              if ((int)param_3[2] < 1) {
                uVar14 = param_3[2] - ((int)*param_3 >> 3);
                while ((int)uVar14 < 1) {
                  uVar13 = *param_3 & 7;
                  uVar14 = param_3[2] - ((int)*param_3 >> 3);
                  param_3[2] = uVar14;
                  *param_3 = uVar13;
                  uVar11 = param_3[3];
                  if (*(int *)(uVar11 + 0xc) == 0) {
                    if ((int)(uVar14 * 8) < (int)uVar13) {
                      param_3[2] = 0xffffffff;
                    }
                    break;
                  }
                  param_3[5] = param_3[5] + *(int *)(uVar11 + 8);
                  piVar6 = *(int **)(uVar11 + 0xc);
                  param_3[3] = (uint)piVar6;
                  if (0 < (int)(piVar6[2] + uVar14)) {
                    param_3[1] = (*piVar6 + piVar6[1]) - uVar14;
                  }
                  uVar14 = piVar6[2] + uVar14;
                  param_3[2] = uVar14;
                }
              }
              if (*(int *)(iVar3 + 0x18) <= (int)(uVar8 & 0xff)) goto LAB_030caeac;
              *(char *)(param_1[2] + uVar7 + iVar5 * 8) = (char)uVar8;
              bVar2 = *(byte *)((int)param_1 + 0x1a);
              if ((int)(uint)bVar2 < (int)(uVar7 + 1)) {
                bVar2 = (byte)(uVar7 + 1);
              }
              *(byte *)((int)param_1 + 0x1a) = bVar2;
            }
            uVar7 = uVar7 + 1;
          } while ((int)uVar7 < 8);
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uint)(byte)param_1[6]);
      }
      if (-1 < (int)param_3[2]) {
        return 0;
      }
    }
  }
LAB_030caeac:
  if (param_1 != (uint *)0x0) {
    param_1[1] = 0;
    param_1[2] = 0;
    memset_byte(DAT_030cb03c,0,10);
    memset_byte(DAT_030cb040,0,0x50);
    memset_byte(param_1,0,0x1c);
  }
  return 1;
}


