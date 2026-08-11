/**
 * FUN_030c4f76 @ 0x030c4f76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c4f76(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  char cVar9;
  int iVar10;
  char cVar11;
  ushort uVar12;
  uint unaff_r6;
  uint unaff_r7;
  char cVar13;
  uint unaff_r8;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  iVar10 = DAT_030c51dc;
  local_44 = 0xffffffff;
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = *DAT_030c51e0;
  *DAT_030c51e0 = iVar2 + 1;
  iVar10 = iVar10 + iVar2 * 0x1a8;
  iVar2 = sbuf_read_bits(param_2,5);
  iVar18 = 0;
  *(int *)(iVar10 + 0x19c) = iVar2;
  if (0 < iVar2) {
    uVar21 = *(uint *)(DAT_030c51e4 + 0x10);
    do {
      uVar5 = *param_2;
      uVar14 = param_2[2];
      iVar2 = uVar5 + 4;
      if (iVar2 < (int)(uVar14 * 8)) {
        pbVar7 = (byte *)param_2[1];
        unaff_r8 = (uint)(*pbVar7 >> (uVar5 & 0xff));
        if ((((8 < iVar2) &&
             (unaff_r8 = (uint)pbVar7[1] << (8 - uVar5 & 0xff) | unaff_r8, 0x10 < iVar2)) &&
            (unaff_r8 = (uint)pbVar7[2] << (0x10 - uVar5 & 0xff) | unaff_r8, 0x18 < iVar2)) &&
           ((unaff_r8 = (uint)pbVar7[3] << (0x18 - uVar5 & 0xff) | unaff_r8, 0x20 < iVar2 &&
            (uVar5 != 0)))) {
          unaff_r8 = (uint)pbVar7[4] << (0x20 - uVar5 & 0xff) | unaff_r8;
        }
LAB_030c5112:
        uVar14 = unaff_r8 & uVar21;
        unaff_r8 = uVar14;
      }
      else {
        pbVar7 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar14) {
          if (uVar5 != 0xfffffffc) {
            while (uVar14 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c50b2;
              pbVar7 = (byte *)(piVar3[1] + *piVar3);
              uVar14 = piVar3[2];
            }
            pbVar8 = pbVar7 + 1;
            unaff_r8 = (uint)(*pbVar7 >> (uVar5 & 0xff));
            if (8 < iVar2) {
              iVar15 = uVar14 - 1;
              while (iVar15 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c50b2;
                pbVar8 = (byte *)(piVar3[1] + *piVar3);
                iVar15 = piVar3[2];
              }
              pbVar7 = pbVar8 + 1;
              unaff_r8 = (uint)*pbVar8 << (8 - uVar5 & 0xff) | unaff_r8;
              if (0x10 < iVar2) {
                iVar15 = iVar15 + -1;
                while (iVar15 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c50b2;
                  pbVar7 = (byte *)(piVar3[1] + *piVar3);
                  iVar15 = piVar3[2];
                }
                pbVar8 = pbVar7 + 1;
                unaff_r8 = (uint)*pbVar7 << (0x10 - uVar5 & 0xff) | unaff_r8;
                if (0x18 < iVar2) {
                  iVar15 = iVar15 + -1;
                  while (iVar15 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c50b2;
                    pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                    iVar15 = piVar3[2];
                  }
                  pbVar7 = pbVar8 + 1;
                  unaff_r8 = (uint)*pbVar8 << (0x18 - uVar5 & 0xff) | unaff_r8;
                  if ((0x20 < iVar2) && (uVar5 != 0)) {
                    if (iVar15 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c50b2;
                        pbVar7 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r8 = (uint)*pbVar7 << (0x20 - uVar5 & 0xff) | unaff_r8;
                  }
                }
              }
            }
          }
          goto LAB_030c5112;
        }
LAB_030c50b2:
        uVar14 = 0xffffffff;
      }
      *param_2 = uVar5 + 4 & 7;
      iVar2 = (int)(uVar5 + 4) >> 3;
      param_2[2] = param_2[2] - iVar2;
      param_2[1] = param_2[1] + iVar2;
      if ((int)param_2[2] < 1) {
        uVar5 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar5 < 1) {
          uVar16 = *param_2 & 7;
          uVar5 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar16;
          param_2[2] = uVar5;
          uVar6 = param_2[3];
          if (*(int *)(uVar6 + 0xc) == 0) {
            if ((int)(uVar5 * 8) < (int)uVar16) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar6 + 8);
          piVar3 = *(int **)(uVar6 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar5)) {
            param_2[1] = (piVar3[1] + *piVar3) - uVar5;
          }
          uVar5 = piVar3[2] + uVar5;
          param_2[2] = uVar5;
        }
      }
      *(char *)(iVar10 + iVar18 + 0x37) = (char)uVar14;
      if ((int)local_44 < (int)(uVar14 & 0xff)) {
        local_44 = uVar14 & 0xff;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < *(int *)(iVar10 + 0x19c));
    local_48 = 0;
    if (0 < (int)(local_44 + 1)) {
      uVar21 = *(uint *)(DAT_030c55e4 + 0xc);
      uVar14 = *(uint *)(DAT_030c55e4 + 8);
      uVar5 = *(uint *)(DAT_030c55e4 + 0x20);
LAB_030c51f6:
      uVar16 = *param_2;
      uVar6 = param_2[2];
      iVar2 = uVar16 + 3;
      if (iVar2 < (int)(uVar6 * 8)) {
        pbVar7 = (byte *)param_2[1];
        local_38 = (uint)(*pbVar7 >> (uVar16 & 0xff));
        if ((((8 < iVar2) &&
             (local_38 = (uint)pbVar7[1] << (8 - uVar16 & 0xff) | local_38, 0x10 < iVar2)) &&
            (local_38 = (uint)pbVar7[2] << (0x10 - uVar16 & 0xff) | local_38, 0x18 < iVar2)) &&
           ((local_38 = (uint)pbVar7[3] << (0x18 - uVar16 & 0xff) | local_38, 0x20 < iVar2 &&
            (uVar16 != 0)))) {
          local_38 = local_38 | (uint)pbVar7[4] << (0x20 - uVar16 & 0xff);
        }
LAB_030c539a:
        local_38 = local_38 & uVar21;
        cVar11 = (char)local_38;
      }
      else {
        pbVar7 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar6) {
          if (uVar16 != 0xfffffffd) {
            while (uVar6 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c5324;
              pbVar7 = (byte *)(*piVar3 + piVar3[1]);
              uVar6 = piVar3[2];
            }
            pbVar8 = pbVar7 + 1;
            local_38 = (uint)(*pbVar7 >> (uVar16 & 0xff));
            if (8 < iVar2) {
              iVar18 = uVar6 - 1;
              while (iVar18 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c5324;
                pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                iVar18 = piVar3[2];
              }
              pbVar7 = pbVar8 + 1;
              local_38 = (uint)*pbVar8 << (8 - uVar16 & 0xff) | local_38;
              if (0x10 < iVar2) {
                iVar18 = iVar18 + -1;
                while (iVar18 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c5324;
                  pbVar7 = (byte *)(piVar3[1] + *piVar3);
                  iVar18 = piVar3[2];
                }
                pbVar8 = pbVar7 + 1;
                local_38 = (uint)*pbVar7 << (0x10 - uVar16 & 0xff) | local_38;
                if (0x18 < iVar2) {
                  iVar18 = iVar18 + -1;
                  while (iVar18 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c5324;
                    pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                    iVar18 = piVar3[2];
                  }
                  pbVar7 = pbVar8 + 1;
                  local_38 = (uint)*pbVar8 << (0x18 - uVar16 & 0xff) | local_38;
                  if ((0x20 < iVar2) && (uVar16 != 0)) {
                    if (iVar18 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c5324;
                        pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                      } while (piVar3[2] == 0);
                    }
                    local_38 = (uint)*pbVar7 << (0x20 - uVar16 & 0xff) | local_38;
                  }
                }
              }
            }
          }
          goto LAB_030c539a;
        }
LAB_030c5324:
        cVar11 = -1;
      }
      *param_2 = uVar16 + 3 & 7;
      iVar2 = (int)(uVar16 + 3) >> 3;
      param_2[2] = param_2[2] - iVar2;
      param_2[1] = param_2[1] + iVar2;
      if ((int)param_2[2] < 1) {
        uVar6 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar6 < 1) {
          uVar19 = *param_2 & 7;
          uVar6 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar19;
          param_2[2] = uVar6;
          uVar16 = param_2[3];
          if (*(int *)(uVar16 + 0xc) == 0) {
            if ((int)(param_2[2] * 8) < (int)uVar19) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar16 + 8);
          piVar3 = *(int **)(uVar16 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar6)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar6;
          }
          uVar6 = piVar3[2] + uVar6;
          param_2[2] = uVar6;
        }
      }
      *(char *)(iVar10 + local_48 * 0xb) = cVar11 + '\x01';
      uVar16 = *param_2;
      uVar6 = param_2[2];
      iVar2 = uVar16 + 2;
      if (iVar2 < (int)(uVar6 * 8)) {
        pbVar7 = (byte *)param_2[1];
        local_3c = (uint)(*pbVar7 >> (uVar16 & 0xff));
        if ((((8 < iVar2) &&
             (local_3c = local_3c | (uint)pbVar7[1] << (8 - uVar16 & 0xff), 0x10 < iVar2)) &&
            (local_3c = local_3c | (uint)pbVar7[2] << (0x10 - uVar16 & 0xff), 0x18 < iVar2)) &&
           ((local_3c = local_3c | (uint)pbVar7[3] << (0x18 - uVar16 & 0xff), 0x20 < iVar2 &&
            (uVar16 != 0)))) {
          local_3c = (uint)pbVar7[4] << (0x20 - uVar16 & 0xff) | local_3c;
        }
LAB_030c55a4:
        uVar6 = local_3c & uVar14;
        local_3c = uVar6;
      }
      else {
        pbVar7 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar6) {
          if (uVar16 != 0xfffffffe) {
            while (uVar6 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c5546;
              pbVar7 = (byte *)(*piVar3 + piVar3[1]);
              uVar6 = piVar3[2];
            }
            pbVar8 = pbVar7 + 1;
            local_3c = (uint)(*pbVar7 >> (uVar16 & 0xff));
            if (8 < iVar2) {
              iVar18 = uVar6 - 1;
              while (iVar18 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c5546;
                pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                iVar18 = piVar3[2];
              }
              pbVar7 = pbVar8 + 1;
              local_3c = (uint)*pbVar8 << (8 - uVar16 & 0xff) | local_3c;
              if (0x10 < iVar2) {
                iVar18 = iVar18 + -1;
                while (iVar18 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c5546;
                  pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                  iVar18 = piVar3[2];
                }
                pbVar8 = pbVar7 + 1;
                local_3c = (uint)*pbVar7 << (0x10 - uVar16 & 0xff) | local_3c;
                if (0x18 < iVar2) {
                  iVar18 = iVar18 + -1;
                  while (iVar18 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c5546;
                    pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                    iVar18 = piVar3[2];
                  }
                  pbVar7 = pbVar8 + 1;
                  local_3c = (uint)*pbVar8 << (0x18 - uVar16 & 0xff) | local_3c;
                  if ((0x20 < iVar2) && (uVar16 != 0)) {
                    if (iVar18 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c5546;
                        pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                      } while (piVar3[2] == 0);
                    }
                    local_3c = (uint)*pbVar7 << (0x20 - uVar16 & 0xff) | local_3c;
                  }
                }
              }
            }
          }
          goto LAB_030c55a4;
        }
LAB_030c5546:
        uVar6 = 0xffffffff;
      }
      *param_2 = uVar16 + 2 & 7;
      iVar2 = (int)(uVar16 + 2) >> 3;
      param_2[2] = param_2[2] - iVar2;
      param_2[1] = param_2[1] + iVar2;
      if ((int)param_2[2] < 1) {
        uVar16 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar16 < 1) {
          uVar16 = param_2[2] - ((int)*param_2 >> 3);
          uVar20 = *param_2 & 7;
          *param_2 = uVar20;
          param_2[2] = uVar16;
          uVar19 = param_2[3];
          if (*(int *)(uVar19 + 0xc) == 0) {
            if ((int)(uVar16 * 8) < (int)uVar20) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar19 + 8);
          piVar3 = *(int **)(uVar19 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar16)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar16;
          }
          uVar16 = piVar3[2] + uVar16;
          param_2[2] = uVar16;
        }
      }
      iVar2 = local_48 * 0xb + iVar10;
      *(char *)(iVar2 + 1) = (char)uVar6;
      uVar16 = param_2[2];
      if (-1 < (int)uVar16) {
        if ((uVar6 & 0xff) != 0) {
          uVar6 = *param_2;
          iVar18 = uVar6 + 8;
          if (iVar18 < (int)(uVar16 * 8)) {
            pbVar7 = (byte *)param_2[1];
            local_40 = (uint)(*pbVar7 >> (uVar6 & 0xff));
            if (((8 < iVar18) &&
                (local_40 = local_40 | (uint)pbVar7[1] << (8 - uVar6 & 0xff), 0x10 < iVar18)) &&
               ((local_40 = local_40 | (uint)pbVar7[2] << (0x10 - uVar6 & 0xff), 0x18 < iVar18 &&
                ((local_40 = local_40 | (uint)pbVar7[3] << (0x18 - uVar6 & 0xff), 0x20 < iVar18 &&
                 (uVar6 != 0)))))) {
              local_40 = local_40 | (uint)pbVar7[4] << (0x20 - uVar6 & 0xff);
            }
          }
          else {
            pbVar7 = (byte *)param_2[1];
            piVar3 = (int *)param_2[3];
            if (uVar6 != 0xfffffff8) {
              while (uVar16 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c5762;
                pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                uVar16 = piVar3[2];
              }
              pbVar8 = pbVar7 + 1;
              local_40 = (uint)(*pbVar7 >> (uVar6 & 0xff));
              if (8 < iVar18) {
                iVar15 = uVar16 - 1;
                while (iVar15 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c5762;
                  pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                  iVar15 = piVar3[2];
                }
                pbVar7 = pbVar8 + 1;
                local_40 = (uint)*pbVar8 << (8 - uVar6 & 0xff) | local_40;
                if (0x10 < iVar18) {
                  iVar15 = iVar15 + -1;
                  while (iVar15 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c5762;
                    pbVar7 = (byte *)(piVar3[1] + *piVar3);
                    iVar15 = piVar3[2];
                  }
                  pbVar8 = pbVar7 + 1;
                  local_40 = (uint)*pbVar7 << (0x10 - uVar6 & 0xff) | local_40;
                  if (0x18 < iVar18) {
                    iVar15 = iVar15 + -1;
                    while (iVar15 == 0) {
                      piVar3 = (int *)piVar3[3];
                      if (piVar3 == (int *)0x0) goto LAB_030c5762;
                      pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                      iVar15 = piVar3[2];
                    }
                    pbVar7 = pbVar8 + 1;
                    local_40 = (uint)*pbVar8 << (0x18 - uVar6 & 0xff) | local_40;
                    if ((0x20 < iVar18) && (uVar6 != 0)) {
                      if (iVar15 == 1) {
                        do {
                          piVar3 = (int *)piVar3[3];
                          if (piVar3 == (int *)0x0) goto LAB_030c5762;
                          pbVar7 = (byte *)(piVar3[1] + *piVar3);
                        } while (piVar3[2] == 0);
                      }
                      local_40 = (uint)*pbVar7 << (0x20 - uVar6 & 0xff) | local_40;
                    }
                  }
                }
              }
            }
          }
          uVar16 = local_40 & uVar5;
          local_40 = uVar16;
          goto LAB_030c57d0;
        }
        *(char *)(iVar2 + 2) = (char)uVar6;
        uVar6 = 0;
        goto LAB_030c5872;
      }
      goto LAB_030c5dce;
    }
  }
LAB_030c5ab0:
  iVar1 = sbuf_read_bits(param_2,2);
  *(int *)(iVar10 + 0x1a4) = iVar1 + 1;
  uVar21 = sbuf_read_bits(param_2,4);
  iVar1 = *(int *)(iVar10 + 0x19c);
  if (0 < iVar1 + -1) {
    for (iVar2 = iVar1 + -1 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
    }
  }
  local_48 = 0;
  iVar2 = 0;
  local_44 = 0;
  if (0 < iVar1) {
    do {
      local_48 = local_48 +
                 (uint)*(byte *)(iVar10 + (uint)*(byte *)(local_44 + iVar10 + 0x37) * 0xb);
      for (; iVar2 < local_48; iVar2 = iVar2 + 1) {
        uVar6 = *param_2;
        uVar14 = param_2[2];
        uVar5 = uVar6 + uVar21;
        if ((int)uVar5 < (int)(uVar14 * 8)) {
          pbVar7 = (byte *)param_2[1];
          unaff_r6 = (uint)(*pbVar7 >> (uVar6 & 0xff));
          if ((((8 < (int)uVar5) &&
               (unaff_r6 = unaff_r6 | (uint)pbVar7[1] << (8 - uVar6 & 0xff), 0x10 < (int)uVar5)) &&
              (unaff_r6 = unaff_r6 | (uint)pbVar7[2] << (0x10 - uVar6 & 0xff), 0x18 < (int)uVar5))
             && ((unaff_r6 = unaff_r6 | (uint)pbVar7[3] << (0x18 - uVar6 & 0xff), 0x20 < (int)uVar5
                 && (uVar6 != 0)))) {
            unaff_r6 = unaff_r6 | (uint)pbVar7[4] << (0x20 - uVar6 & 0xff);
          }
LAB_030c5c3a:
          unaff_r6 = unaff_r6 & *(uint *)(DAT_030c5f04 + uVar21 * 4);
          uVar12 = (ushort)unaff_r6;
        }
        else {
          pbVar7 = (byte *)param_2[1];
          piVar3 = (int *)param_2[3];
          if (-1 < (int)uVar14) {
            if (uVar5 != 0) {
              while (uVar14 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c5bec;
                pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                uVar14 = piVar3[2];
              }
              pbVar8 = pbVar7 + 1;
              unaff_r6 = (uint)(*pbVar7 >> (uVar6 & 0xff));
              if (8 < (int)uVar5) {
                iVar18 = uVar14 - 1;
                while (iVar18 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c5bec;
                  pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                  iVar18 = piVar3[2];
                }
                pbVar7 = pbVar8 + 1;
                unaff_r6 = (uint)*pbVar8 << (8 - uVar6 & 0xff) | unaff_r6;
                if (0x10 < (int)uVar5) {
                  iVar18 = iVar18 + -1;
                  while (iVar18 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c5bec;
                    pbVar7 = (byte *)(*piVar3 + piVar3[1]);
                    iVar18 = piVar3[2];
                  }
                  pbVar8 = pbVar7 + 1;
                  unaff_r6 = (uint)*pbVar7 << (0x10 - uVar6 & 0xff) | unaff_r6;
                  if (0x18 < (int)uVar5) {
                    iVar18 = iVar18 + -1;
                    while (iVar18 == 0) {
                      piVar3 = (int *)piVar3[3];
                      if (piVar3 == (int *)0x0) goto LAB_030c5bec;
                      pbVar8 = (byte *)(*piVar3 + piVar3[1]);
                      iVar18 = piVar3[2];
                    }
                    pbVar7 = pbVar8 + 1;
                    unaff_r6 = (uint)*pbVar8 << (0x18 - uVar6 & 0xff) | unaff_r6;
                    if ((0x20 < (int)uVar5) && (uVar6 != 0)) {
                      if (iVar18 == 1) {
                        do {
                          piVar3 = (int *)piVar3[3];
                          if (piVar3 == (int *)0x0) goto LAB_030c5bec;
                          pbVar7 = (byte *)(piVar3[1] + *piVar3);
                        } while (piVar3[2] == 0);
                      }
                      unaff_r6 = unaff_r6 | (uint)*pbVar7 << (0x20 - uVar6 & 0xff);
                    }
                  }
                }
              }
            }
            goto LAB_030c5c3a;
          }
LAB_030c5bec:
          uVar12 = 0xffff;
        }
        *param_2 = uVar5 & 7;
        param_2[2] = param_2[2] - ((int)uVar5 >> 3);
        param_2[1] = param_2[1] + ((int)uVar5 >> 3);
        if ((int)param_2[2] < 1) {
          uVar14 = param_2[2] - ((int)*param_2 >> 3);
          while ((int)uVar14 < 1) {
            uVar14 = param_2[2] - ((int)*param_2 >> 3);
            uVar6 = *param_2 & 7;
            param_2[2] = uVar14;
            *param_2 = uVar6;
            uVar5 = param_2[3];
            if (*(int *)(uVar5 + 0xc) == 0) {
              if ((int)(uVar14 * 8) < (int)uVar6) {
                param_2[2] = 0xffffffff;
              }
              break;
            }
            param_2[5] = *(int *)(uVar5 + 8) + param_2[5];
            piVar3 = *(int **)(uVar5 + 0xc);
            param_2[3] = (uint)piVar3;
            if (0 < (int)(piVar3[2] + uVar14)) {
              param_2[1] = (*piVar3 + piVar3[1]) - uVar14;
            }
            uVar14 = piVar3[2] + uVar14;
            param_2[2] = uVar14;
          }
        }
        *(ushort *)(iVar10 + iVar2 * 2 + 0x5c) = uVar12;
        if ((int)((uint)(0 < iVar1) << (uVar21 & 0xff)) <= (int)(uint)uVar12) goto LAB_030c5dce;
      }
      local_44 = local_44 + 1;
    } while ((int)local_44 < *(int *)(iVar10 + 0x19c));
  }
  if (-1 < (int)param_2[2]) {
    *(undefined2 *)(iVar10 + 0x58) = 0;
    *(short *)(iVar10 + 0x5a) = (short)(1 << (uVar21 & 0xff));
    uVar21 = local_48 + 2;
    *(uint *)(iVar10 + 0x1a0) = uVar21;
    if (0 < (int)uVar21) {
      uVar14 = uVar21 & 1;
      if (uVar14 != 0) {
        *(undefined1 *)(iVar10 + 0xda) = 0;
      }
      uVar5 = (uint)(uVar14 != 0);
      if ((int)uVar14 < (int)uVar21) {
        do {
          uVar14 = uVar14 + 2;
          *(char *)(iVar10 + uVar5 + 0xda) = (char)uVar5;
          *(char *)(iVar10 + uVar5 + 1 + 0xda) = (char)(uVar5 + 1);
          uVar5 = uVar5 + 2;
        } while ((int)uVar14 < *(int *)(iVar10 + 0x1a0));
      }
    }
    FUN_030c4dec(iVar10 + 0xda,iVar10 + 0x58,*(undefined2 *)(iVar10 + 0x1a0));
    iVar1 = 0;
    if (0 < *(int *)(iVar10 + 0x1a0) + -2) {
      do {
        cVar11 = '\0';
        uVar5 = (uint)*(ushort *)(iVar10 + iVar1 * 2 + 0x5c);
        cVar9 = '\x01';
        uVar14 = (uint)*(ushort *)(iVar10 + 0x5a);
        uVar21 = 0;
        if (0 < iVar1 + 2) {
          puVar4 = (ushort *)(iVar10 + 0x58);
          cVar13 = '\0';
          iVar2 = iVar1 + 2;
          cVar9 = '\x01';
          do {
            uVar16 = (uint)*puVar4;
            bVar22 = SBORROW4(uVar16,uVar21);
            iVar18 = uVar16 - uVar21;
            uVar6 = uVar21;
            if (uVar21 < uVar16) {
              bVar22 = SBORROW4(uVar5,uVar16);
              iVar18 = uVar5 - uVar16;
              uVar6 = uVar5;
            }
            if (uVar16 != uVar6 && iVar18 < 0 == bVar22) {
              uVar21 = uVar16;
              cVar11 = cVar13;
            }
            bVar22 = SBORROW4(uVar16,uVar14);
            iVar18 = uVar16 - uVar14;
            if (uVar16 < uVar14) {
              bVar22 = SBORROW4(uVar5,uVar16);
              iVar18 = uVar5 - uVar16;
            }
            if (iVar18 < 0 != bVar22) {
              uVar14 = uVar16;
              cVar9 = cVar13;
            }
            puVar4 = puVar4 + 1;
            cVar13 = cVar13 + '\x01';
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        iVar2 = iVar10 + iVar1;
        iVar1 = iVar1 + 1;
        *(char *)(iVar2 + 0x15a) = cVar11;
        *(char *)(iVar2 + 0x11b) = cVar9;
      } while (iVar1 < *(int *)(iVar10 + 0x1a0) + -2);
    }
    return iVar10;
  }
LAB_030c5dce:
  memset_byte(iVar10,0,5);
  memset_byte(iVar10 + 0x37,0,0x20);
  memset_byte(iVar10 + 0x58,0,0x41);
  memset_byte(iVar10 + 0xda,0,0x41);
  memset_byte(iVar10 + 0x11b,0,0x3f);
  memset_byte(iVar10 + 0x15a,0,0x3f);
  memset_byte(DAT_030c5f08,0,0x350);
  return 0;
LAB_030c5762:
  uVar16 = 0xffffffff;
LAB_030c57d0:
  *param_2 = uVar6 + 8 & 7;
  iVar18 = (int)(uVar6 + 8) >> 3;
  param_2[2] = param_2[2] - iVar18;
  param_2[1] = param_2[1] + iVar18;
  if ((int)param_2[2] < 1) {
    uVar6 = param_2[2] - ((int)*param_2 >> 3);
    while ((int)uVar6 < 1) {
      uVar20 = *param_2 & 7;
      uVar6 = param_2[2] - ((int)*param_2 >> 3);
      *param_2 = uVar20;
      param_2[2] = uVar6;
      uVar19 = param_2[3];
      if (*(int *)(uVar19 + 0xc) == 0) {
        if ((int)(uVar6 * 8) < (int)uVar20) {
          param_2[2] = 0xffffffff;
        }
        break;
      }
      param_2[5] = param_2[5] + *(int *)(uVar19 + 8);
      piVar3 = *(int **)(uVar19 + 0xc);
      param_2[3] = (uint)piVar3;
      if (0 < (int)(piVar3[2] + uVar6)) {
        param_2[1] = (piVar3[1] + *piVar3) - uVar6;
      }
      uVar6 = piVar3[2] + uVar6;
      param_2[2] = uVar6;
    }
  }
  uVar6 = uVar16 & 0xff;
  *(char *)(iVar2 + 2) = (char)uVar16;
  if (*(int *)(iVar1 + 0x18) <= (int)uVar6) goto LAB_030c5dce;
LAB_030c5872:
  if (*(int *)(iVar1 + 0x18) <= (int)uVar6) goto LAB_030c5dce;
  iVar18 = 0;
  if (0 < 1 << *(sbyte *)(iVar2 + 1)) {
    do {
      uVar16 = *param_2;
      uVar6 = param_2[2];
      iVar15 = uVar16 + 8;
      if (iVar15 < (int)(uVar6 * 8)) {
        pbVar7 = (byte *)param_2[1];
        unaff_r7 = (uint)(*pbVar7 >> (uVar16 & 0xff));
        if ((((8 < iVar15) &&
             (unaff_r7 = unaff_r7 | (uint)pbVar7[1] << (8 - uVar16 & 0xff), 0x10 < iVar15)) &&
            (unaff_r7 = unaff_r7 | (uint)pbVar7[2] << (0x10 - uVar16 & 0xff), 0x18 < iVar15)) &&
           ((unaff_r7 = unaff_r7 | (uint)pbVar7[3] << (0x18 - uVar16 & 0xff), 0x20 < iVar15 &&
            (uVar16 != 0)))) {
          unaff_r7 = unaff_r7 | (uint)pbVar7[4] << (0x20 - uVar16 & 0xff);
        }
LAB_030c59e4:
        uVar6 = unaff_r7 & uVar5;
        unaff_r7 = uVar6;
      }
      else {
        pbVar7 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar6) {
          if (uVar16 != 0xfffffff8) {
            while (uVar6 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c598c;
              pbVar7 = (byte *)(*piVar3 + piVar3[1]);
              uVar6 = piVar3[2];
            }
            pbVar8 = pbVar7 + 1;
            unaff_r7 = (uint)(*pbVar7 >> (uVar16 & 0xff));
            if (8 < iVar15) {
              iVar17 = uVar6 - 1;
              while (iVar17 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c598c;
                pbVar8 = (byte *)(piVar3[1] + *piVar3);
                iVar17 = piVar3[2];
              }
              pbVar7 = pbVar8 + 1;
              unaff_r7 = (uint)*pbVar8 << (8 - uVar16 & 0xff) | unaff_r7;
              if (0x10 < iVar15) {
                iVar17 = iVar17 + -1;
                while (iVar17 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c598c;
                  pbVar7 = (byte *)(piVar3[1] + *piVar3);
                  iVar17 = piVar3[2];
                }
                pbVar8 = pbVar7 + 1;
                unaff_r7 = (uint)*pbVar7 << (0x10 - uVar16 & 0xff) | unaff_r7;
                if (0x18 < iVar15) {
                  iVar17 = iVar17 + -1;
                  while (iVar17 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c598c;
                    pbVar8 = (byte *)(piVar3[1] + *piVar3);
                    iVar17 = piVar3[2];
                  }
                  pbVar7 = pbVar8 + 1;
                  unaff_r7 = (uint)*pbVar8 << (0x18 - uVar16 & 0xff) | unaff_r7;
                  if ((0x20 < iVar15) && (uVar16 != 0)) {
                    if (iVar17 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c598c;
                        pbVar7 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r7 = unaff_r7 | (uint)*pbVar7 << (0x20 - uVar16 & 0xff);
                  }
                }
              }
            }
          }
          goto LAB_030c59e4;
        }
LAB_030c598c:
        uVar6 = 0xffffffff;
      }
      *param_2 = uVar16 + 8 & 7;
      iVar15 = (int)(uVar16 + 8) >> 3;
      param_2[2] = param_2[2] - iVar15;
      param_2[1] = param_2[1] + iVar15;
      if ((int)param_2[2] < 1) {
        uVar16 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar16 < 1) {
          uVar16 = param_2[2] - ((int)*param_2 >> 3);
          uVar19 = *param_2 & 7;
          param_2[2] = uVar16;
          *param_2 = uVar19;
          uVar20 = param_2[3];
          if (*(int *)(uVar20 + 0xc) == 0) {
            if ((int)(uVar16 * 8) < (int)uVar19) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar20 + 8);
          piVar3 = *(int **)(uVar20 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar16)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar16;
          }
          uVar16 = piVar3[2] + uVar16;
          param_2[2] = uVar16;
        }
      }
      uVar16 = uVar6 - 1 & 0xff;
      *(char *)(iVar2 + iVar18 + 3) = (char)(uVar6 - 1);
      if ((*(int *)(iVar1 + 0x18) <= (int)uVar16) && (uVar16 != 0xff)) goto LAB_030c5dce;
      iVar18 = iVar18 + 1;
    } while (iVar18 < 1 << *(sbyte *)(iVar2 + 1));
  }
  local_48 = local_48 + 1;
  if ((int)(local_44 + 1) <= local_48) goto LAB_030c5ab0;
  goto LAB_030c51f6;
}


