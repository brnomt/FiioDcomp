/**
 * FUN_030caeda @ 0x030caeda
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030caeda(int *param_1,int *param_2,undefined1 *param_3,int *param_4,uint param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  byte *pbVar10;
  char cVar11;
  undefined1 *puVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  uint uVar25;
  undefined1 local_2a0 [396];
  undefined1 auStack_114 [4];
  int local_110 [50];
  uint *local_48;
  int local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int *piStack_34;
  int *piStack_30;
  undefined1 *local_2c;
  int *piStack_28;
  
  piStack_28 = param_4;
  local_2c = param_3;
  piStack_30 = param_2;
  piStack_34 = param_1;
  local_44 = *(int *)(*param_1 + 0x1c);
  iVar17 = 0;
  local_48 = (uint *)(*(int *)(*(int *)(*param_1 + 0x1c) + 0x30) +
                     (uint)*(byte *)((int)param_2 + 0x19) * 0x40);
  uVar20 = *local_48;
  iVar21 = param_2[5];
  iVar4 = (param_2[4] - param_2[3]) / iVar21;
  if (200 < (int)(((int)(iVar4 + uVar20 + -1) / (int)uVar20) * uVar20)) {
    FUN_030cd958(s_partword_used_size__d_030cb044,iVar4 + uVar20 + -1);
  }
  if (*param_2 < 2) {
    if ((int)param_5 < 1) {
      return 0;
    }
    iVar5 = 0;
    do {
      puVar8 = (undefined1 *)0x0;
      if (*param_4 != 0) {
        *(undefined4 *)(local_2c + iVar17 * 4) = *(undefined4 *)(local_2c + iVar5 * 4);
        iVar17 = iVar17 + 1;
        puVar8 = local_2c;
      }
      iVar5 = iVar5 + 1;
      param_5 = param_5 - 1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
    if (iVar17 != 0) {
      iVar5 = 0;
    }
    if (0 < iVar17) {
      puVar8 = local_2a0;
    }
    if (iVar17 == 0) {
      return 0;
    }
    if (0 < iVar17) {
      do {
        local_110[iVar5] = (int)(puVar8 + iVar5 * 200);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar17);
    }
    uVar25 = 0;
    if (*(char *)((int)param_2 + 0x1a) != '\0') {
      iVar5 = uVar20 - 1;
      do {
        iVar18 = 0;
        if (0 < iVar4) {
          uVar16 = uVar25 & 0xff;
          do {
            if (uVar25 == 0) {
              *(undefined1 *)(local_110[0] + iVar18 + iVar5) = 1;
              iVar19 = iVar5 >> 1;
              if (0 < iVar5) {
                iVar6 = local_110[0] + iVar18 + uVar20;
                iVar7 = iVar19;
                if ((uVar20 & 1) == 0) {
                  *(char *)(iVar6 + -2) = (char)param_2[6] * *(char *)(iVar6 + -1);
                  iVar6 = iVar6 + -1;
                }
                for (; iVar7 != 0; iVar7 = iVar7 + -1) {
                  cVar11 = (char)param_2[6] * *(char *)(iVar6 + -1);
                  *(char *)(iVar6 + -2) = cVar11;
                  *(char *)(iVar6 + -3) = (char)param_2[6] * cVar11;
                  iVar6 = iVar6 + -2;
                }
              }
              iVar6 = 1;
              if (1 < iVar17) {
                iVar23 = iVar18 + uVar20;
                iVar7 = (iVar23 - iVar5) + -1;
                do {
                  if (0 < iVar5) {
                    puVar8 = (undefined1 *)(*(int *)(auStack_114 + iVar6 * 4) + iVar23);
                    puVar12 = (undefined1 *)(local_110[iVar6] + iVar23);
                    if ((uVar20 & 1) == 0) {
                      puVar8 = puVar8 + -1;
                      puVar12 = puVar12 + -1;
                      *puVar12 = *puVar8;
                    }
                    uVar1 = puVar8[-1];
                    for (iVar13 = iVar19; iVar13 != 0; iVar13 = iVar13 + -1) {
                      uVar2 = puVar8[-2];
                      puVar12[-1] = uVar1;
                      uVar1 = puVar8[-3];
                      puVar12 = puVar12 + -2;
                      *puVar12 = uVar2;
                      puVar8 = puVar8 + -2;
                    }
                  }
                  if (-1 < (int)(uVar20 - 1)) {
                    *(undefined1 *)(local_110[iVar6] + iVar7) =
                         *(undefined1 *)(*(int *)(auStack_114 + iVar6 * 4) + iVar7);
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 < iVar17);
              }
              iVar19 = 0;
              if (0 < iVar17) {
                do {
                  uVar9 = FUN_030c3a42(local_48,param_1 + 1);
                  if (param_1[3] < 0) {
                    if (iVar17 < 1) {
                      return 0;
                    }
                    iVar4 = 0;
                    do {
                      if (local_110[iVar4] != 0) {
                        local_110[iVar4] = 0;
                      }
                      iVar4 = iVar4 + 1;
                      iVar17 = iVar17 + -1;
                    } while (iVar17 != 0);
                    return 0;
                  }
                  if (0 < (int)uVar20) {
                    pbVar10 = (byte *)(local_110[iVar19] + iVar18);
                    uVar22 = uVar20;
                    do {
                      uVar22 = uVar22 - 1;
                      uVar15 = uVar9 / *pbVar10;
                      uVar9 = uVar9 - (uVar15 & 0xff) * (uint)*pbVar10;
                      *pbVar10 = (byte)uVar15;
                      pbVar10 = pbVar10 + 1;
                    } while (uVar22 != 0);
                  }
                  iVar19 = iVar19 + 1;
                } while (iVar19 < iVar17);
              }
            }
            local_110[2] = 0;
            while( true ) {
              bVar24 = SBORROW4(local_110[2],uVar20);
              iVar19 = local_110[2] - uVar20;
              if (local_110[2] < (int)uVar20) {
                bVar24 = SBORROW4(iVar18,iVar4);
                iVar19 = iVar18 - iVar4;
              }
              if (iVar19 < 0 == bVar24) break;
              iVar19 = 0;
              if (0 < iVar17) {
                do {
                  if (((uint)*(byte *)(param_2[1] + (uint)*(byte *)(local_110[iVar19] + iVar18)) &
                      1 << uVar16) != 0) {
                    if (*param_2 == 0) {
                      iVar6 = FUN_030c3c7e(*(int *)(local_44 + 0x30) +
                                           (uint)*(byte *)(param_2[2] +
                                                          uVar25 + (uint)*(byte *)(local_110[iVar19]
                                                                                  + iVar18) * 8) *
                                           0x40,*(int *)(local_2c + iVar19 * 4) +
                                                (iVar18 * iVar21 + param_2[3]) * 4,param_1 + 1,
                                           iVar21,0xfffffff8);
                      if (iVar6 == -1) goto LAB_030cb1b6;
                    }
                    else {
                      iVar6 = FUN_030c3d1c();
                      if (iVar6 + 1 == 0) {
                        local_110[0] = iVar6 + 1;
                        memset_byte(local_2a0,0,400);
                        return 0;
                      }
                    }
                  }
                  iVar19 = iVar19 + 1;
                } while (iVar19 < iVar17);
              }
              iVar18 = iVar18 + 1;
              local_110[2] = local_110[2] + 1;
            }
          } while (iVar18 < iVar4);
        }
        uVar25 = uVar25 + 1;
      } while ((int)uVar25 < (int)(uint)*(byte *)((int)param_2 + 0x1a));
    }
LAB_030cb1b6:
    local_110[0] = 0;
    uVar14 = 400;
    puVar8 = &stack0xffffffdc;
  }
  else {
    local_38 = param_2[3] / (int)param_5;
    uVar25 = 0;
    if ((int)param_5 < 1) {
      uVar9 = param_5;
      uVar16 = 0;
    }
    else {
      uVar9 = param_5 & 1;
      uVar16 = uVar9;
    }
    if (0 < (int)uVar9) {
      do {
        if (param_4[uVar25] != 0) goto LAB_030cb21c;
        uVar25 = uVar25 + 1;
      } while ((int)uVar25 < (int)uVar16);
    }
    for (; ((uVar25 = uVar16, (int)uVar16 < (int)param_5 && (param_4[uVar16] == 0)) &&
           (uVar25 = uVar16 + 1, param_4[uVar16 + 1] == 0)); uVar16 = uVar16 + 2) {
    }
LAB_030cb21c:
    if (uVar25 == param_5) {
      return 0;
    }
    uVar25 = 0;
    if (*(char *)((int)param_2 + 0x1a) != '\0') {
      local_3c = param_1 + 1;
      local_40 = uVar20 - 1;
      do {
        iVar17 = 0;
        if (0 < iVar4) {
          do {
            if (uVar25 == 0) {
              iVar5 = iVar17 + uVar20;
              auStack_114[iVar5 + 3] = 1;
              if (0 < local_40) {
                piVar3 = local_110;
                if ((uVar20 & 1) == 0) {
                  auStack_114[iVar5 + 2] = (char)param_2[6];
                  piVar3 = (int *)(auStack_114 + 3);
                }
                iVar5 = iVar5 + (int)piVar3;
                for (iVar18 = local_40 >> 1; iVar18 != 0; iVar18 = iVar18 + -1) {
                  cVar11 = (char)param_2[6] * *(char *)(iVar5 + -1);
                  *(char *)(iVar5 + -2) = cVar11;
                  *(char *)(iVar5 + -3) = (char)param_2[6] * cVar11;
                  iVar5 = iVar5 + -2;
                }
              }
              uVar16 = FUN_030c3a42(local_48,param_1 + 1);
              if (param_1[3] < 0) goto LAB_030cb2a4;
              if (0 < (int)uVar20) {
                pbVar10 = (byte *)((int)local_110 + iVar17);
                uVar9 = uVar20;
                do {
                  uVar9 = uVar9 - 1;
                  uVar22 = uVar16 / *pbVar10;
                  uVar16 = uVar16 - (uVar22 & 0xff) * (uint)*pbVar10;
                  *pbVar10 = (byte)uVar22;
                  pbVar10 = pbVar10 + 1;
                } while (uVar9 != 0);
              }
            }
            iVar5 = 0;
            while( true ) {
              bVar24 = SBORROW4(iVar5,uVar20);
              iVar18 = iVar5 - uVar20;
              if (iVar5 < (int)uVar20) {
                bVar24 = SBORROW4(iVar17,iVar4);
                iVar18 = iVar17 - iVar4;
              }
              if (iVar18 < 0 == bVar24) break;
              if ((((uint)*(byte *)(param_2[1] + (uint)*(byte *)((int)local_110 + iVar17)) &
                   1 << (uVar25 & 0xff)) != 0) &&
                 (iVar18 = FUN_030c3e2c(*(int *)(local_44 + 0x30) +
                                        (uint)*(byte *)(param_2[2] +
                                                       uVar25 + (uint)*(byte *)((int)local_110 +
                                                                               iVar17) * 8) * 0x40,
                                        local_2c,iVar17 * (iVar21 / (int)param_5) + local_38,param_5
                                        ,local_3c,iVar21 / (int)param_5,0xfffffff8), iVar18 == -1))
              goto LAB_030cb2a4;
              iVar5 = iVar5 + 1;
              iVar17 = iVar17 + 1;
            }
          } while (iVar17 < iVar4);
        }
        uVar25 = uVar25 + 1;
      } while ((int)uVar25 < (int)(uint)*(byte *)((int)param_2 + 0x1a));
    }
LAB_030cb2a4:
    uVar14 = 200;
    puVar8 = &stack0x0000016c;
  }
  memset_byte(puVar8 + -0x27c,0,uVar14);
  return 0;
}


