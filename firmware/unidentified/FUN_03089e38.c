/**
 * FUN_03089e38 @ 0x03089e38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_03089e38(uint *param_1,int *param_2,int param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  int local_8c;
  int iStack_88;
  int local_84;
  uint uStack_6c;
  int local_68;
  int iStack_60;
  uint uStack_5c;
  int local_58;
  int local_50;
  int local_4c;
  int iStack_48;
  uint uStack_44;
  uint uStack_40;
  uint *puStack_30;
  int *local_2c;
  int iStack_28;
  
  local_8c = 0;
  iVar14 = 0;
  local_68 = 0;
  uVar3 = 0x1f - param_1[0xe];
  iVar15 = param_2[0x11];
  local_58 = *param_2;
  iVar4 = param_2[3];
  local_4c = param_2[5];
  local_50 = param_2[4];
  local_84 = 0;
  uVar11 = param_2[0x29];
  if (uVar11 == 0) {
    return DAT_0308a1c0;
  }
  iVar10 = 0xd;
  uStack_44 = 0xffffffff;
  uVar5 = uVar11;
  if (0x7ffff < uVar11) {
    for (; (uVar5 & 0xf0000000) == 0; uVar5 = uVar5 << 4) {
      iVar10 = iVar10 + -4;
    }
    for (; (uVar5 & 0x80000000) == 0; uVar5 = uVar5 << 1) {
      iVar10 = iVar10 + -1;
    }
    if (-1 < (int)(iVar10 - 1U)) {
      uVar6 = (uVar5 & 0x7fffffff) >> 0x17;
      iVar16 = *(int *)(*DAT_0308a1bc + uVar6 * 4);
      uStack_44 = (uint)(iVar16 - (int)((ulonglong)(uVar5 << 9) *
                                        (ulonglong)
                                        (uint)(iVar16 - *(int *)(*DAT_0308a1bc + (uVar6 + 1) * 4))
                                       >> 0x20)) >> (iVar10 - 1U & 0xff);
    }
  }
  uVar5 = param_1[1];
  uStack_6c = ((int)uVar5 >> 0x1f) * uStack_44 +
              (int)((ulonglong)uVar5 * (ulonglong)uStack_44 >> 0x20);
  iStack_88 = *param_1 - 2;
  if (uStack_6c != 0) {
    for (; uStack_6c < 0x1fffffff; uStack_6c = uStack_6c << 2) {
      iStack_88 = iStack_88 + 2;
    }
    if (uStack_6c < 0x3fffffff) {
      uStack_6c = uStack_6c << 1;
      iStack_88 = iStack_88 + 1;
    }
  }
  uVar6 = 0;
  if (uVar11 != 0) {
    for (; uVar11 < 0x1fffffff; uVar11 = uVar11 << 2) {
      uVar6 = uVar6 + 2;
    }
    if (uVar11 < 0x3fffffff) {
      uVar6 = uVar6 + 1;
    }
  }
  puStack_30 = param_1;
  local_2c = param_2;
  iStack_28 = param_3;
  if (param_1[0xb] == 0) {
    wma_memclr(iVar15,param_1[0x29] << 2);
    uVar11 = param_1[0x29];
    if ((int)uVar11 < (int)param_1[0x2a]) {
      do {
        iVar14 = uVar6 + 0x15;
        uVar5 = *(int *)(param_3 + uVar11 * 4) << (uVar6 & 0xff);
        if (uVar5 != 0) {
          for (; uVar5 < 0x1fffffff; uVar5 = uVar5 << 2) {
            iVar14 = iVar14 + 2;
          }
          if (uVar5 < 0x3fffffff) {
            uVar5 = uVar5 << 1;
            iVar14 = iVar14 + 1;
          }
        }
        iVar4 = (int)((ulonglong)
                      ((longlong)(*(int *)(local_58 + local_68 * 4) << (uVar3 & 0xff)) *
                      (longlong)((int)((ulonglong)uStack_6c * (ulonglong)uVar5 >> 0x20) << 1)) >>
                     0x20) << 1;
        uVar5 = (uVar3 + iStack_88 + iVar14) - 0x43;
        if ((int)uVar5 < 0) {
          iVar4 = iVar4 << (-uVar5 & 0xff);
        }
        else if ((int)uVar5 < 0x20) {
          iVar4 = iVar4 >> (uVar5 & 0xff);
        }
        else {
          iVar4 = 0;
        }
        *(int *)(iVar15 + uVar11 * 4) = iVar4;
        uVar11 = uVar11 + 1;
        local_68 = local_68 + 1;
      } while ((int)uVar11 < (int)param_1[0x2a]);
    }
    wma_memclr(iVar15 + param_1[0x2a] * 4,((int)(short)local_2c[0x20] - param_1[0x2a]) * 4);
    return 0;
  }
  if (0 < (int)param_1[0x29]) {
    uVar17 = FUN_03082c16(1 << (*param_1 & 0xff));
    uVar18 = FUN_03082c16(uVar5);
    uVar17 = FUN_03082aee((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                          (int)((ulonglong)uVar17 >> 0x20));
    do {
      uVar11 = param_1[0x5f] * DAT_0308a1b8 + DAT_0308a1b4;
      param_1[0x5f] = uVar11;
      uVar5 = ((int)uVar11 >> 2) + ((int)uVar11 >> 4);
      uVar11 = param_1[0x5e];
      param_1[0x5e] = uVar5;
      uVar7 = FUN_03082bfa(uVar5 - uVar11);
      uVar7 = FUN_030829f2(uVar7,0xffffffe3);
      iStack_60 = FUN_03082906(uVar7,param_1[0x30]);
      uVar7 = FUN_03082bfa(*(undefined4 *)(param_3 + param_1[0x29] * 4));
      uVar7 = FUN_030829f2(uVar7,0xffffffeb);
      FUN_03082c0c(local_2c[0x29]);
      uVar18 = FUN_03082cc4();
      FUN_03082906(iStack_60,uVar7);
      uVar19 = FUN_03082cc4();
      uVar19 = FUN_03082a0a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                            (int)((ulonglong)uVar17 >> 0x20));
      uVar19 = FUN_03082bcc((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x15);
      FUN_03082aee((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
      uVar7 = FUN_03082cea();
      FUN_030829f2(uVar7,5);
      uVar7 = FUN_03082c38();
      *(undefined4 *)(iVar15 + iVar14 * 4) = uVar7;
      iVar14 = iVar14 + 1;
    } while (iVar14 < (int)param_1[0x29]);
  }
  iVar10 = DAT_0308a1c4;
  if (iVar14 < (int)param_1[0x4a]) {
    do {
      uVar11 = param_1[0x5f] * DAT_0308a1b8 + DAT_0308a1b4;
      param_1[0x5f] = uVar11;
      uVar11 = ((int)uVar11 >> 2) + ((int)uVar11 >> 4);
      uVar5 = param_1[0x5e];
      param_1[0x5e] = uVar11;
      if (*(int *)(param_1[0x33] + local_8c * 4 + 4) <= iVar14) {
        local_8c = local_8c + 1;
      }
      iVar16 = uVar6 + 0x15;
      uVar8 = *(int *)(param_3 + iVar14 * 4) << (uVar6 & 0xff);
      if (uVar8 != 0) {
        for (; uVar8 < 0x1fffffff; uVar8 = uVar8 << 2) {
          iVar16 = iVar16 + 2;
        }
        if (uVar8 < 0x3fffffff) {
          uVar8 = uVar8 << 1;
          iVar16 = iVar16 + 1;
        }
      }
      iVar12 = (int)((ulonglong)uStack_6c * (ulonglong)uVar8 >> 0x20) << 1;
      iVar9 = (int)((ulonglong)
                    ((longlong)(*(int *)(local_58 + local_68 * 4) << (uVar3 & 0xff)) *
                    (longlong)iVar12) >> 0x20) << 1;
      uVar8 = (iVar16 + iStack_88 + uVar3) - 0x43;
      if ((int)uVar8 < 0) {
        iVar9 = iVar9 << (-uVar8 & 0xff);
      }
      else if ((int)uVar8 < 0x20) {
        iVar9 = iVar9 >> (uVar8 & 0xff);
      }
      else {
        iVar9 = 0;
      }
      iVar12 = (int)((ulonglong)
                     ((longlong)
                      ((int)((ulonglong)((longlong)(int)(uVar11 - uVar5) * (longlong)iVar10) >> 0x20
                            ) << 1) * (longlong)iVar12) >> 0x20) << 1;
      uVar11 = (iVar16 + iStack_88) - 0x22;
      if ((int)uVar11 < 0) {
        iVar12 = iVar12 << (-uVar11 & 0xff);
      }
      else if ((int)uVar11 < 0x20) {
        iVar12 = iVar12 >> (uVar11 & 0xff);
      }
      else {
        iVar12 = 0;
      }
      *(int *)(iVar15 + iVar14 * 4) = iVar12 + iVar9;
      iVar14 = iVar14 + 1;
      local_68 = local_68 + 1;
    } while (iVar14 < (int)param_1[0x4a]);
  }
  uVar11 = param_1[0x2a];
  if (iVar14 < (int)uVar11) {
    uStack_44 = uStack_44 >> 1;
    do {
      uVar11 = param_1[0x33];
      if (*(int *)(uVar11 + local_8c * 4 + 4) <= iVar14) {
        local_8c = local_8c + 1;
      }
      if (*(char *)(iVar4 + local_8c) == '\x01') {
        uVar5 = *(uint *)(uVar11 + local_8c * 4 + 4);
        uVar11 = param_1[0x2a];
        if ((int)uVar5 < (int)param_1[0x2a]) {
          uVar11 = uVar5;
        }
        FUN_0308809c(&iStack_60,*(undefined4 *)(local_4c + local_84 * 4),&iStack_48);
        if (iStack_48 == -1) {
          return 0xfffffff2;
        }
        piVar13 = (int *)(local_50 + local_84 * 8);
        iVar10 = *piVar13;
        lVar1 = (longlong)(int)uStack_5c * (longlong)piVar13[1];
        uStack_5c = (int)((ulonglong)lVar1 >> 0x20) << 1;
        iStack_60 = iStack_60 + iVar10 + -0x1f;
        FUN_03087ab8(&iStack_60,uStack_5c,iVar10,(int)lVar1);
        iVar10 = (int)uStack_5c >> 0x1f;
        uVar2 = (ulonglong)uStack_5c;
        uStack_5c = iStack_60 + -1;
        uStack_40 = (iVar10 * uStack_44 + (int)(uVar2 * uStack_44 >> 0x20)) * 4;
        if (uStack_40 != 0) {
          for (; uStack_40 < 0x1fffffff; uStack_40 = uStack_40 << 2) {
            uStack_5c = uStack_5c + 2;
          }
          if (uStack_40 < 0x3fffffff) {
            uStack_40 = uStack_40 << 1;
            uStack_5c = uStack_5c + 1;
          }
        }
        for (; iVar14 < (int)uVar11; iVar14 = iVar14 + 1) {
          uVar5 = param_1[0x5f] * DAT_0308a680 + DAT_0308a67c;
          param_1[0x5f] = uVar5;
          uVar8 = ((int)uVar5 >> 2) + ((int)uVar5 >> 4);
          uVar5 = param_1[0x5e];
          param_1[0x5e] = uVar8;
          uVar8 = uVar8 - uVar5;
          iVar16 = 0;
          uVar8 = (uStack_40 * ((int)uVar8 >> 0x1f) +
                  (int)((ulonglong)uStack_40 * (ulonglong)uVar8 >> 0x20)) * 2;
          iVar10 = uVar6 + 0x15;
          uVar5 = *(int *)(param_3 + iVar14 * 4) << (uVar6 & 0xff);
          if (uVar5 != 0) {
            for (; uVar5 < 0x1fffffff; uVar5 = uVar5 << 2) {
              iVar10 = iVar10 + 2;
            }
            if (uVar5 < 0x3fffffff) {
              uVar5 = uVar5 << 1;
              iVar10 = iVar10 + 1;
            }
          }
          iVar9 = (((int)uVar8 >> 0x1f) * uVar5 + (int)((ulonglong)uVar8 * (ulonglong)uVar5 >> 0x20)
                  ) * 2;
          uVar5 = (iVar10 + uStack_5c) - 0x26;
          if ((int)uVar5 < 0) {
            iVar16 = iVar9 << (-uVar5 & 0xff);
          }
          else if ((int)uVar5 < 0x20) {
            iVar16 = iVar9 >> (uVar5 & 0xff);
          }
          *(int *)(iVar15 + iVar14 * 4) = iVar16;
        }
        local_84 = local_84 + 1;
      }
      else {
        if (*(int *)(uVar11 + local_8c * 4 + 4) <= iVar14) {
          local_8c = local_8c + 1;
        }
        uVar11 = param_1[0x5f] * DAT_0308a1b8 + DAT_0308a1b4;
        param_1[0x5f] = uVar11;
        uVar5 = ((int)uVar11 >> 2) + ((int)uVar11 >> 4);
        uVar8 = param_1[0x5e];
        param_1[0x5e] = uVar5;
        iVar10 = uVar6 + 0x15;
        uVar11 = *(int *)(param_3 + iVar14 * 4) << (uVar6 & 0xff);
        if (uVar11 != 0) {
          for (; uVar11 < 0x1fffffff; uVar11 = uVar11 << 2) {
            iVar10 = iVar10 + 2;
          }
          if (uVar11 < 0x3fffffff) {
            uVar11 = uVar11 << 1;
            iVar10 = iVar10 + 1;
          }
        }
        iVar16 = (int)((ulonglong)uStack_6c * (ulonglong)uVar11 >> 0x20) << 1;
        iVar9 = (int)((ulonglong)
                      ((longlong)(*(int *)(local_58 + local_68 * 4) << (uVar3 & 0xff)) *
                      (longlong)iVar16) >> 0x20) << 1;
        uVar11 = (uVar3 + iVar10 + iStack_88) - 0x43;
        if ((int)uVar11 < 0) {
          iVar9 = iVar9 << (-uVar11 & 0xff);
        }
        else if ((int)uVar11 < 0x20) {
          iVar9 = iVar9 >> (uVar11 & 0xff);
        }
        else {
          iVar9 = 0;
        }
        *(int *)(iVar15 + iVar14 * 4) =
             iVar9 + (((int)((ulonglong)
                             ((longlong)
                              ((int)((ulonglong)
                                     ((longlong)(int)(uVar5 - uVar8) * (longlong)DAT_0308a1c4) >>
                                    0x20) << 1) * (longlong)iVar16) >> 0x20) << 1) >>
                     ((iVar10 + iStack_88) - 0x22U & 0xff));
        iVar14 = iVar14 + 1;
        local_68 = local_68 + 1;
      }
      uVar11 = param_1[0x2a];
    } while (iVar14 < (int)uVar11);
  }
  iVar10 = DAT_0308a67c;
  iVar4 = 0x15;
  uVar11 = *(uint *)(param_3 + uVar11 * 4 + -4);
  if (uVar11 != 0) {
    for (; uVar11 < 0x1fffffff; uVar11 = uVar11 << 2) {
      iVar4 = iVar4 + 2;
    }
    if (uVar11 < 0x3fffffff) {
      uVar11 = uVar11 << 1;
      iVar4 = iVar4 + 1;
    }
  }
  uVar11 = (int)((ulonglong)uStack_6c * (ulonglong)uVar11 >> 0x20) << 1;
  iVar4 = iVar4 + iStack_88 + -0x1f;
  if (uVar11 != 0) {
    for (; uVar11 < 0x1fffffff; uVar11 = uVar11 << 2) {
      iVar4 = iVar4 + 2;
    }
    if (uVar11 < 0x3fffffff) {
      uVar11 = uVar11 << 1;
      iVar4 = iVar4 + 1;
    }
  }
  iVar4 = iVar4 + 4;
  uVar11 = (int)((ulonglong)((longlong)(int)uVar11 * (longlong)DAT_0308a678) >> 0x20) << 1;
  if (uVar11 != 0) {
    for (; uVar11 < 0x1fffffff; uVar11 = uVar11 << 2) {
      iVar4 = iVar4 + 2;
    }
    if (uVar11 < 0x3fffffff) {
      uVar11 = uVar11 << 1;
      iVar4 = iVar4 + 1;
    }
  }
  if (iVar14 < (short)local_2c[0x20]) {
    do {
      uVar3 = param_1[0x5f] * DAT_0308a680 + iVar10;
      param_1[0x5f] = uVar3;
      uVar5 = ((int)uVar3 >> 2) + ((int)uVar3 >> 4);
      uVar3 = param_1[0x5e];
      param_1[0x5e] = uVar5;
      uVar5 = uVar5 - uVar3;
      iVar16 = (uVar11 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)uVar11 * (ulonglong)uVar5 >> 0x20))
               * 2;
      uVar3 = iVar4 - 7;
      if ((int)uVar3 < 0) {
        iVar16 = iVar16 << (-(iVar4 + -7) & 0xffU);
      }
      else if ((int)uVar3 < 0x20) {
        iVar16 = iVar16 >> (uVar3 & 0xff);
      }
      else {
        iVar16 = 0;
      }
      *(int *)(iVar15 + iVar14 * 4) = iVar16;
      iVar14 = iVar14 + 1;
    } while (iVar14 < (short)local_2c[0x20]);
  }
  return 0;
}


