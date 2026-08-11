/**
 * FUN_0308ab5a @ 0x0308ab5a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308ab5a(int param_1,int *param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int local_b8;
  uint local_b4;
  int iStack_b0;
  int local_a0;
  int local_9c;
  uint local_98;
  int iStack_94;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_64;
  uint local_5c;
  int local_58;
  int iStack_54;
  int local_48;
  int local_44;
  uint local_40;
  int local_38;
  int local_34;
  int iStack_30;
  int *local_2c;
  undefined4 uStack_28;
  
  iVar10 = 0;
  iVar9 = 0;
  iVar13 = *param_2;
  local_84 = param_2[3];
  iVar11 = 0;
  iVar8 = 0;
  local_44 = param_2[5];
  local_48 = param_2[4];
  local_8c = param_2[1];
  local_38 = param_2[0x13];
  iVar12 = param_2[0x11];
  local_64 = 0;
  iStack_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  if (param_2[0x2e] == 0) {
    local_88 = 0;
  }
  else {
    local_88 = param_2[0x2f];
    if (local_88 != 0) {
      wma_memclr(local_88,100);
    }
  }
  iVar14 = (*(int *)(param_1 + 0x7c) << 6) / (int)(short)local_2c[0x20];
  local_98 = wma_floor_log2(iVar14);
  iVar2 = wma_floor_log2(*(int *)(param_1 + 0x9c) / *(int *)(param_1 + 0x7c));
  local_9c = *(int *)(param_1 + 0xec) + iVar2 * 0x74;
  iVar2 = wma_floor_log2(*(int *)(param_1 + 0x9c) / *(int *)(param_1 + 0x7c));
  iStack_b0 = *(int *)(*(int *)(param_1 + 0xe8) + iVar2 * 4);
  local_a0 = *(int *)(param_1 + 0xcc);
  local_b4 = local_98;
  local_b8 = iVar14;
  local_78 = iStack_b0;
  FUN_0308a5e2(param_1,local_2c,local_a0,local_9c);
  iVar2 = *(int *)(local_9c + 4);
  while (iVar2 <= (0 << (local_98 & 0xff)) >> 6) {
    iVar9 = iVar9 + 1;
    iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
  }
  iVar2 = *(int *)(local_a0 + 4);
  while (iVar2 < 1) {
    iVar10 = iVar10 + 1;
    iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
  }
  if (0 < *(int *)(param_1 + 0xa4)) {
    do {
      *(undefined4 *)(iVar12 + iVar8 * 4) = 0;
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0xa4));
  }
  iVar2 = *(int *)(param_1 + 0x128);
  if (iVar8 < iVar2) {
    do {
      iVar14 = *(int *)(local_9c + iVar9 * 4 + 4);
      while (iVar14 <= (iVar8 << (local_98 & 0xff)) >> 6) {
        iVar9 = iVar9 + 1;
        iVar14 = *(int *)(local_9c + iVar9 * 4 + 4);
      }
      local_7c = local_78;
      if (iVar9 < local_78) {
        local_7c = *(int *)(local_9c + iVar9 * 4 + 4);
        if ((int)local_98 < 7) {
          local_7c = local_7c << (6 - local_98 & 0xff);
        }
        else {
          local_7c = local_7c + (1 << (local_98 - 7 & 0xff)) >> (local_98 - 6 & 0xff);
        }
        if (iVar2 < local_7c) {
          local_7c = iVar2;
        }
      }
      FUN_03087aee(&local_70,param_1,local_2c,iVar9);
      iVar14 = local_6c;
      for (iVar2 = local_70 + -9; 0x23 < iVar2; iVar2 = iVar2 + -1) {
        iVar14 = iVar14 >> 1;
      }
      local_5c = iVar2 - 5;
      if (iVar8 < local_7c) {
        local_40 = -local_5c;
        do {
          iVar3 = *(int *)(param_1 + 0x17c) * DAT_0308b10c + DAT_0308b108;
          *(int *)(param_1 + 0x17c) = iVar3;
          iVar6 = (iVar3 >> 2) + (iVar3 >> 4);
          iVar3 = *(int *)(param_1 + 0x178);
          lVar1 = (longlong)DAT_0308b110;
          *(int *)(param_1 + 0x178) = iVar6;
          iVar3 = ((int)((ulonglong)((iVar6 - iVar3) * lVar1) >> 0x20) << 1) >> 0xb;
          uVar4 = *(uint *)(iVar13 + iVar11 * 4);
          uVar15 = uVar4;
          if ((int)uVar4 < 0) {
            uVar15 = -uVar4;
          }
          if ((int)uVar15 < 0x200) {
            iVar3 = (int)((ulonglong)((longlong)(int)(iVar3 + uVar4 * 0x400000) * (longlong)iVar14)
                         >> 0x20) << 1;
            if ((int)local_5c < 0) {
              iVar3 = iVar3 << (local_40 & 0xff);
            }
            else {
              iVar3 = iVar3 >> (local_5c & 0xff);
            }
            *(int *)(iVar12 + iVar8 * 4) = iVar3;
          }
          else {
            uVar5 = 0;
            uVar15 = uVar4;
            if ((int)uVar4 < 0) {
              uVar15 = -uVar4;
            }
            for (; 0x1ff < uVar15; uVar15 = uVar15 >> 1) {
              uVar5 = uVar5 + 1;
            }
            iVar6 = (int)((ulonglong)
                          ((longlong)
                           (int)((iVar3 >> (uVar5 & 0xff)) + (uVar4 << (0x16 - uVar5 & 0xff))) *
                          (longlong)iVar14) >> 0x20) << 1;
            for (iVar3 = iVar2 - uVar5; 0x23 < iVar3; iVar3 = iVar3 + -1) {
            }
            uVar15 = iVar3 - 5;
            iVar3 = uVar5 + iVar3;
            if ((int)uVar15 < 0) {
              iVar6 = iVar6 << (-uVar15 & 0xff);
            }
            else {
              iVar6 = iVar6 >> (uVar15 & 0xff);
            }
            *(int *)(iVar12 + iVar8 * 4) = iVar6;
            for (; 0x23 < iVar3; iVar3 = iVar3 + -1) {
            }
          }
          iVar3 = 0;
          if (local_88 != 0) {
            iVar3 = *(int *)(iVar13 + iVar11 * 4);
          }
          if (local_88 != 0 && iVar3 != 0) {
            *(undefined4 *)(local_88 + iVar10 * 4) = 1;
          }
          iVar8 = iVar8 + 1;
          iVar11 = iVar11 + 1;
        } while (iVar8 < local_7c);
      }
      if (*(int *)(local_9c + iVar9 * 4 + 4) <= (iVar8 + 1 << (local_98 & 0xff)) >> 6) {
        iVar9 = iVar9 + 1;
      }
      iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
      while (iVar2 <= iVar8) {
        iVar10 = iVar10 + 1;
        iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
      }
      iVar2 = *(int *)(param_1 + 0x128);
    } while (iVar8 < iVar2);
  }
  if (iVar8 < *(int *)(param_1 + 0xa8)) {
    do {
      if (*(char *)(local_84 + iVar10) == '\x01') {
        if (local_88 != 0) {
          *(undefined4 *)(local_88 + iVar10 * 4) = 1;
        }
        FUN_0308809c(&local_b8,*(undefined4 *)(local_44 + local_64 * 4),&local_34);
        if (local_34 == -1) {
          return 0xfffffff2;
        }
        piVar7 = (int *)(local_48 + local_64 * 8);
        iVar2 = *piVar7;
        lVar1 = (longlong)(int)local_b4 * (longlong)piVar7[1];
        local_6c = (int)((ulonglong)lVar1 >> 0x20) << 1;
        local_70 = local_b8 + iVar2 + -0x1f;
        FUN_03087ab8(&local_70,local_6c,iVar2,(int)lVar1);
        local_74 = local_6c;
        local_80 = *(int *)(local_a0 + iVar10 * 4 + 4);
        if (*(int *)(param_1 + 0xa8) <= local_80) {
          local_80 = *(int *)(param_1 + 0xa8);
        }
        if (iVar8 < local_80) {
          do {
            iVar2 = *(int *)(local_8c + iVar9 * 4) - local_38;
            if (iVar2 < 1) {
              if (iVar2 < -0x48) {
                iVar2 = -0x47;
              }
              iVar3 = *(int *)(*DAT_0308b2c8 + iVar2 * -4);
              iVar14 = -iVar2 >> 2;
            }
            else {
              if (0x3e < iVar2) {
                iVar2 = 0x3e;
              }
              iVar14 = -(iVar2 >> 2);
              iVar3 = *(int *)(*DAT_0308b2d4 + iVar2 * 4 + -4);
            }
            iStack_54 = (int)((ulonglong)((longlong)iVar3 * (longlong)local_74) >> 0x20) << 1;
            local_58 = iVar14 + local_70 + -3;
            FUN_03087ab8(&local_58,iStack_54,(int)((longlong)iVar3 * (longlong)local_74));
            iVar3 = DAT_0308b2cc;
            iVar14 = iStack_54;
            for (iVar2 = local_58 + -2; 0x23 < iVar2; iVar2 = iVar2 + -1) {
              iVar14 = iVar14 >> 1;
            }
            uVar15 = iVar2 - 5;
            local_6c = local_80;
            iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
            while (iVar2 <= (iVar8 << (local_98 & 0xff)) >> 6) {
              iVar9 = iVar9 + 1;
              iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
            }
            iVar2 = local_78;
            if (iVar9 < local_78) {
              iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
              if ((int)local_98 < 7) {
                iVar2 = iVar2 << (6 - local_98 & 0xff);
              }
              else {
                iVar2 = iVar2 + (1 << (local_98 - 7 & 0xff)) >> (local_98 - 6 & 0xff);
              }
              if (local_80 < iVar2) {
                iVar2 = local_80;
              }
            }
            if (iVar8 < iVar2) {
              do {
                iVar6 = *(int *)(param_1 + 0x17c) * DAT_0308b2d0 + iVar3;
                *(int *)(param_1 + 0x17c) = iVar6;
                iVar16 = (iVar6 >> 2) + (iVar6 >> 4);
                iVar6 = *(int *)(param_1 + 0x178);
                *(int *)(param_1 + 0x178) = iVar16;
                iVar6 = (int)((ulonglong)((longlong)(iVar16 - iVar6) * (longlong)iVar14) >> 0x20) <<
                        1;
                if ((int)uVar15 < 0) {
                  iVar6 = iVar6 << (-uVar15 & 0xff);
                }
                else {
                  iVar6 = iVar6 >> (uVar15 & 0xff);
                }
                *(int *)(iVar12 + iVar8 * 4) = iVar6;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar2);
            }
            if (*(int *)(local_9c + iVar9 * 4 + 4) <= (iVar8 + 1 << (local_98 & 0xff)) >> 6) {
              iVar9 = iVar9 + 1;
            }
          } while (iVar8 < local_80);
        }
        local_64 = local_64 + 1;
      }
      else {
        iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
        while (iVar2 <= (iVar8 << (local_98 & 0xff)) >> 6) {
          iVar9 = iVar9 + 1;
          iVar2 = *(int *)(local_9c + iVar9 * 4 + 4);
        }
        local_7c = local_78;
        if (iVar9 < local_78) {
          local_7c = *(int *)(local_9c + iVar9 * 4 + 4);
          if ((int)local_98 < 7) {
            local_7c = local_7c << (6 - local_98 & 0xff);
          }
          else {
            local_7c = local_7c + (1 << (local_98 - 7 & 0xff)) >> (local_98 - 6 & 0xff);
          }
          if (*(int *)(param_1 + 0xa8) < local_7c) {
            local_7c = *(int *)(param_1 + 0xa8);
          }
        }
        iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
        if (iVar2 < local_7c) {
          local_7c = iVar2;
        }
        FUN_03087aee(&local_70,param_1,local_2c,iVar9);
        iVar14 = local_6c;
        for (iVar2 = local_70 + -9; 0x23 < iVar2; iVar2 = iVar2 + -1) {
          iVar14 = iVar14 >> 1;
        }
        local_5c = iVar2 - 5;
        if (iVar8 < local_7c) {
          local_40 = -local_5c;
          do {
            iVar3 = *(int *)(param_1 + 0x17c) * DAT_0308b10c + DAT_0308b108;
            *(int *)(param_1 + 0x17c) = iVar3;
            iVar6 = (iVar3 >> 2) + (iVar3 >> 4);
            iVar3 = *(int *)(param_1 + 0x178);
            lVar1 = (longlong)DAT_0308b110;
            *(int *)(param_1 + 0x178) = iVar6;
            iVar3 = ((int)((ulonglong)((iVar6 - iVar3) * lVar1) >> 0x20) << 1) >> 0xb;
            uVar4 = *(uint *)(iVar13 + iVar11 * 4);
            uVar15 = uVar4;
            if ((int)uVar4 < 0) {
              uVar15 = -uVar4;
            }
            if ((int)uVar15 < 0x200) {
              iVar3 = (int)((ulonglong)
                            ((longlong)(int)(iVar3 + uVar4 * 0x400000) * (longlong)iVar14) >> 0x20)
                      << 1;
              if ((int)local_5c < 0) {
                iVar3 = iVar3 << (local_40 & 0xff);
              }
              else {
                iVar3 = iVar3 >> (local_5c & 0xff);
              }
              *(int *)(iVar12 + iVar8 * 4) = iVar3;
            }
            else {
              uVar5 = 0;
              uVar15 = uVar4;
              if ((int)uVar4 < 0) {
                uVar15 = -uVar4;
              }
              for (; 0x1ff < uVar15; uVar15 = uVar15 >> 1) {
                uVar5 = uVar5 + 1;
              }
              iVar6 = (int)((ulonglong)
                            ((longlong)
                             (int)((iVar3 >> (uVar5 & 0xff)) + (uVar4 << (0x16 - uVar5 & 0xff))) *
                            (longlong)iVar14) >> 0x20) << 1;
              for (iVar3 = iVar2 - uVar5; 0x23 < iVar3; iVar3 = iVar3 + -1) {
              }
              uVar15 = iVar3 - 5;
              iVar3 = uVar5 + iVar3;
              if ((int)uVar15 < 0) {
                iVar6 = iVar6 << (-uVar15 & 0xff);
              }
              else {
                iVar6 = iVar6 >> (uVar15 & 0xff);
              }
              *(int *)(iVar12 + iVar8 * 4) = iVar6;
              for (; 0x23 < iVar3; iVar3 = iVar3 + -1) {
              }
            }
            iVar3 = 0;
            if (local_88 != 0) {
              iVar3 = *(int *)(iVar13 + iVar11 * 4);
            }
            if (local_88 != 0 && iVar3 != 0) {
              *(undefined4 *)(local_88 + iVar10 * 4) = 1;
            }
            iVar8 = iVar8 + 1;
            iVar11 = iVar11 + 1;
          } while (iVar8 < local_7c);
        }
      }
      if (*(int *)(local_9c + iVar9 * 4 + 4) <= (iVar8 + 1 << (local_98 & 0xff)) >> 6) {
        iVar9 = iVar9 + 1;
      }
      iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
      while (iVar2 <= iVar8) {
        iVar10 = iVar10 + 1;
        iVar2 = *(int *)(local_a0 + iVar10 * 4 + 4);
      }
    } while (iVar8 < *(int *)(param_1 + 0xa8));
  }
  iVar10 = (int)(short)local_2c[0x20];
  if (iVar8 < iVar10) {
    iVar11 = *(int *)(local_9c + iVar9 * 4);
    while ((*(int *)(param_1 + 0xa8) + -1 << (local_98 & 0xff)) >> 6 < iVar11) {
      iVar9 = iVar9 + -1;
      iVar11 = *(int *)(local_9c + iVar9 * 4);
    }
    FUN_03087aee(&local_98,param_1,local_2c,iVar9);
    iVar13 = DAT_0308b108;
    iVar11 = (int)((ulonglong)((longlong)iStack_94 * (longlong)DAT_0308b110) >> 0x20) << 1;
    for (iVar9 = local_98 + 2; 0x23 < iVar9; iVar9 = iVar9 + -1) {
      iVar11 = iVar11 >> 1;
    }
    uVar15 = iVar9 - 5;
    if (iVar8 < iVar10) {
      do {
        iVar9 = *(int *)(param_1 + 0x17c) * DAT_0308b10c + iVar13;
        *(int *)(param_1 + 0x17c) = iVar9;
        iVar2 = (iVar9 >> 2) + (iVar9 >> 4);
        iVar9 = *(int *)(param_1 + 0x178);
        *(int *)(param_1 + 0x178) = iVar2;
        iVar9 = (int)((ulonglong)((longlong)(iVar2 - iVar9) * (longlong)iVar11) >> 0x20) << 1;
        if ((int)uVar15 < 0) {
          iVar9 = iVar9 << (-uVar15 & 0xff);
        }
        else {
          iVar9 = iVar9 >> (uVar15 & 0xff);
        }
        *(int *)(iVar12 + iVar8 * 4) = iVar9;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar10);
    }
  }
  if ((local_88 != 0) && (uVar15 = *(int *)(param_1 + 200) - 1, -1 < (int)uVar15)) {
    do {
      if ((*(int *)(local_a0 + uVar15 * 4) <= *(int *)(param_1 + 0xa8)) &&
         (*(int *)(param_1 + 0xa8) < *(int *)(local_a0 + uVar15 * 4 + 4))) {
        *(undefined4 *)(local_88 + uVar15 * 4) = 1;
        return 0;
      }
      uVar15 = uVar15 - 1;
    } while (uVar15 < 0x80000000);
  }
  return 0;
}


