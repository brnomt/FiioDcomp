/**
 * FUN_030e82d8 @ 0x030e82d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e82d8(int param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  undefined2 *puVar11;
  int *piVar12;
  uint *puVar13;
  uint *puVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  undefined2 uVar23;
  undefined4 auStack_180 [66];
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  uint local_68 [11];
  undefined4 *local_3c;
  uint local_38;
  int iStack_34;
  undefined4 *local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  iStack_34 = param_1;
  local_30 = param_2;
  uStack_2c = param_3;
  uStack_28 = param_4;
  FUN_030e584a(param_1,4);
  FUN_030e584a(param_1,0xc);
  iVar2 = FUN_030e5852(param_1);
  iVar3 = FUN_030e57da(param_1,2);
  *(int *)(param_1 + 0x3c) = iVar3 * 8;
  local_68[10] = ((uint)*(byte *)(param_1 + 0x38) + iVar3 * -8 + param_4) - 1;
  if (local_68[10] < 0x21) {
    iVar3 = FUN_030e5852(param_1);
    if (iVar2 == 0) {
      uVar4 = *(uint *)(param_1 + 0x34);
    }
    else {
      uVar4 = FUN_030e58a0(param_1,0x20);
    }
    if ((uVar4 != 0) && (uVar4 <= *(uint *)(param_1 + 0x34))) {
      *(uint *)(param_1 + 0x40) = uVar4;
      if (iVar3 == 0) {
        local_68[3] = FUN_030e57da(param_1,8);
        local_68[2] = FUN_030e57da(param_1,8);
        iVar2 = 0;
        if (0 < (int)param_4) {
          do {
            uVar4 = FUN_030e57da(param_1,4);
            local_68[iVar2 + 4] = uVar4;
            uVar4 = FUN_030e57da(param_1,4);
            local_68[iVar2 + 6] = uVar4;
            uVar4 = FUN_030e57da(param_1,3);
            local_68[iVar2 + 8] = uVar4;
            uVar4 = FUN_030e57da(param_1,5);
            local_68[iVar2] = uVar4;
            if (*(uint *)(param_1 + 0x34) <= uVar4) {
              return 0xffffffff;
            }
            while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
              uVar5 = FUN_030e579a(param_1,0x10);
              auStack_180[iVar2 * 0x20 + uVar4] = uVar5;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)param_4);
        }
        if ((*(int *)(param_1 + 0x3c) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x40))) {
          do {
            FUN_030e6372(param_1,*(int *)(param_1 + 0x3c) * param_4);
            iVar3 = 0;
            if (0 < (int)param_4) {
              do {
                uVar5 = FUN_030e57da(param_1,*(undefined4 *)(param_1 + 0x3c));
                iVar18 = iVar3 * 4;
                iVar3 = iVar3 + 1;
                *(undefined4 *)(*(int *)(param_1 + iVar18 + 0x2c) + iVar2 * 4) = uVar5;
              } while (iVar3 < (int)param_4);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x40));
        }
        local_6c = 0;
        if (0 < (int)param_4) {
          do {
            local_70 = param_1 + local_6c * 4;
            iVar2 = *(int *)(local_70 + 0x1c);
            iVar20 = *(int *)(param_1 + 0x40);
            local_38 = local_68[10];
            uVar21 = 0;
            iVar18 = 0;
            iVar3 = (uint)*(byte *)(param_1 + 0x39) * local_68[local_6c + 8];
            local_78 = (int)(iVar3 + ((uint)(iVar3 >> 0x1f) >> 0x1e)) >> 2;
            uVar4 = (uint)*(byte *)(param_1 + 0x3a);
            if (0 < iVar20) {
              do {
                FUN_030e6372(param_1,0x20);
                iVar3 = FUN_030e59fa((uVar4 >> 9) + 3 | 1);
                uVar22 = 0x1fU - iVar3;
                if ((int)(uint)*(byte *)(param_1 + 0x3b) < (int)(0x1fU - iVar3)) {
                  uVar22 = (uint)*(byte *)(param_1 + 0x3b);
                }
                local_74 = local_38;
                iVar3 = param_1;
                uVar6 = FUN_030e59c8(param_1);
                if (uVar6 < 9) {
                  if (uVar22 != 1) {
                    iVar7 = FUN_030e581a(iVar3,uVar22);
                    uVar6 = (uVar6 << (uVar22 & 0xff)) - uVar6;
                    if (iVar7 < 2) {
                      FUN_030e584a(iVar3,uVar22 - 1);
                    }
                    else {
                      uVar6 = (iVar7 + uVar6) - 1;
                      FUN_030e584a(iVar3,uVar22);
                    }
                  }
                }
                else {
                  uVar6 = FUN_030e58a0(iVar3,local_74);
                }
                uVar6 = uVar6 + uVar21;
                uVar21 = 0;
                *(uint *)(iVar2 + iVar18 * 4) = -(uVar6 & 1) ^ uVar6 >> 1;
                if (uVar6 < 0x10000) {
                  uVar4 = uVar4 + (uVar6 * local_78 - (uVar4 * local_78 >> 9));
                  if ((uVar4 < 0x80) && (iVar18 + 1 < iVar20)) {
                    iVar3 = FUN_030e59fa(uVar4 | 1);
                    uVar4 = (iVar3 + (uVar4 + 0x10 >> 6)) - 0x18;
                    if ((int)(uint)*(byte *)(param_1 + 0x3b) < (int)uVar4) {
                      uVar4 = (uint)*(byte *)(param_1 + 0x3b);
                    }
                    uVar5 = 0x10;
                    uVar21 = FUN_030e59c8(param_1);
                    if (uVar21 < 9) {
                      if (uVar4 != 1) {
                        iVar3 = FUN_030e581a(param_1,uVar4);
                        uVar21 = (uVar21 << (uVar4 & 0xff)) - uVar21;
                        if (iVar3 < 2) {
                          FUN_030e584a(param_1,uVar4 - 1);
                        }
                        else {
                          uVar21 = (iVar3 + uVar21) - 1;
                          FUN_030e584a(param_1,uVar4);
                        }
                      }
                    }
                    else {
                      uVar21 = FUN_030e58a0(param_1,uVar5);
                    }
                    if (0 < (int)uVar21) {
                      if (iVar20 - iVar18 <= (int)uVar21) {
                        uVar21 = (iVar20 - iVar18) - 1;
                      }
                      FUN_030e422e(iVar2 + iVar18 * 4 + 4,0,uVar21 << 2);
                      iVar18 = iVar18 + uVar21;
                    }
                    uVar21 = (uint)((int)uVar21 < 0x10000);
                    uVar4 = 0;
                  }
                }
                else {
                  uVar4 = 0xffff;
                }
                iVar18 = iVar18 + 1;
              } while (iVar18 < iVar20);
            }
            uVar4 = local_68[10];
            if (local_68[local_6c + 4] == 0xf) {
              iVar2 = *(int *)(param_1 + 0x40);
              iVar3 = *(int *)(local_70 + 0x1c);
              if (1 < iVar2) {
                iVar18 = 1;
                do {
                  uVar5 = FUN_030e576a(*(int *)(iVar3 + iVar18 * 4) +
                                       *(int *)(iVar3 + iVar18 * 4 + -4),uVar4);
                  *(undefined4 *)(iVar3 + iVar18 * 4) = uVar5;
                  iVar18 = iVar18 + 1;
                } while (iVar18 < iVar2);
              }
            }
            uVar4 = *(uint *)(param_1 + 0x40);
            puVar19 = *(undefined4 **)(local_70 + 0x1c);
            puVar17 = *(undefined4 **)(local_70 + 0x24);
            local_78 = local_68[10];
            local_3c = auStack_180 + local_6c * 0x20;
            uVar21 = local_68[local_6c];
            uVar22 = local_68[local_6c + 6];
            *puVar17 = *puVar19;
            if (1 < (int)uVar4) {
              if (uVar21 == 0) {
                FUN_030e41ce(puVar17 + 1,puVar19 + 1,uVar4 * 4 + -4);
              }
              else {
                iVar2 = 1;
                if (uVar21 == 0x1f) {
                  do {
                    uVar5 = FUN_030e576a(puVar17[iVar2 + -1] + puVar19[iVar2],local_78);
                    puVar17[iVar2] = uVar5;
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < (int)uVar4);
                }
                else {
                  while( true ) {
                    uVar6 = uVar21;
                    if (iVar2 <= (int)uVar21) {
                      uVar6 = uVar4;
                    }
                    if ((int)uVar6 <= iVar2) break;
                    uVar5 = FUN_030e576a(puVar17[iVar2 + -1] + puVar19[iVar2],local_78);
                    puVar17[iVar2] = uVar5;
                    puVar19[iVar2] = uVar5;
                    iVar2 = iVar2 + 1;
                  }
                  if ((int)uVar22 < 0xc) {
                    FUN_030e9bf4(0,uVar4,0x60000000);
                    FUN_030e996e(0);
                    FUN_030e5ff8(0,uVar21,uVar22,local_78);
                    FUN_030e9984(local_3c,DAT_030e8adc,uVar21);
                    FUN_030e9bdc(0,uVar4,0x60000000);
                    FUN_030e9b4a(puVar19,DAT_030e8ae4,uVar4,DAT_030e8ae0,puVar17);
                    do {
                      iVar2 = FUN_030e99b4(0,0x8000);
                    } while (iVar2 != 0x8000);
                    FUN_030e9958(0);
                  }
                  else {
                    FUN_030e6246(puVar19,puVar17,uVar4,local_78,local_3c,0,uVar21,uVar22,0,0);
                  }
                }
              }
            }
            local_6c = local_6c + 1;
          } while (local_6c < (int)param_4);
        }
      }
      else {
        iVar2 = 0;
        if (0 < (int)uVar4) {
          do {
            FUN_030e6372(param_1,*(byte *)(param_1 + 0x38) * param_4);
            iVar3 = 0;
            if (0 < (int)param_4) {
              do {
                uVar5 = FUN_030e58e6(param_1,*(undefined1 *)(param_1 + 0x38));
                iVar18 = iVar3 * 4;
                iVar3 = iVar3 + 1;
                *(undefined4 *)(*(int *)(param_1 + iVar18 + 0x24) + iVar2 * 4) = uVar5;
              } while (iVar3 < (int)param_4);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x40));
        }
        *(undefined4 *)(param_1 + 0x3c) = 0;
        local_68[3] = 0;
        local_68[2] = 0;
      }
      if (((param_4 == 2) && (local_68[2] != 0)) && (iVar2 = *(int *)(param_1 + 0x40), 0 < iVar2)) {
        piVar8 = *(int **)(param_1 + 0x28);
        piVar12 = *(int **)(param_1 + 0x24);
        do {
          iVar3 = *piVar12 - ((int)(*piVar8 * local_68[2]) >> (local_68[3] & 0xff));
          *piVar12 = *piVar8 + iVar3;
          *piVar8 = iVar3;
          iVar2 = iVar2 + -1;
          piVar8 = piVar8 + 1;
          piVar12 = piVar12 + 1;
        } while (iVar2 != 0);
      }
      uVar4 = *(uint *)(param_1 + 0x3c);
      if (uVar4 != 0) {
        uVar21 = *(uint *)(param_1 + 0x40);
        iVar2 = 0;
        if (0 < (int)param_4) {
          do {
            if (0 < (int)uVar21) {
              puVar9 = *(uint **)(param_1 + 0x24 + iVar2 * 4);
              puVar13 = *(uint **)(param_1 + 0x2c + iVar2 * 4);
              puVar10 = puVar9 + -1;
              puVar14 = puVar13 + -1;
              if ((uVar21 & 1) != 0) {
                *puVar9 = *puVar9 << (uVar4 & 0xff) | *puVar13;
                puVar10 = puVar9;
                puVar14 = puVar13;
              }
              for (iVar3 = (int)uVar21 >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
                puVar10[1] = puVar10[1] << (uVar4 & 0xff) | puVar14[1];
                puVar9 = puVar10 + 2;
                puVar14 = puVar14 + 2;
                puVar10 = puVar10 + 2;
                *puVar10 = *puVar9 << (uVar4 & 0xff) | *puVar14;
              }
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)param_4);
        }
      }
      cVar1 = *(char *)(param_1 + 0x38);
      if (cVar1 == '\x10') {
        iVar2 = *(int *)(param_1 + 0x40);
        if (0 < iVar2) {
          puVar16 = *(undefined2 **)(param_1 + 0x24);
          puVar15 = *(undefined2 **)(param_1 + 0x28);
          do {
            puVar11 = (undefined2 *)((int)local_30 + 2);
            *(undefined2 *)local_30 = *puVar16;
            if (param_4 == 1) {
              uVar23 = *puVar16;
            }
            else {
              uVar23 = *puVar15;
            }
            local_30 = local_30 + 1;
            *puVar11 = uVar23;
            puVar16 = puVar16 + 2;
            puVar15 = puVar15 + 2;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
      else if (cVar1 == '\x18') {
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x40)) {
          uVar4 = param_4 & 1;
          do {
            if (param_4 == 1) {
              *local_30 = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 4);
              puVar17 = (undefined4 *)((int)local_30 + 6);
              *(undefined4 *)((int)local_30 + 3) =
                   *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 4);
            }
            else {
              puVar17 = local_30;
              if ((int)param_4 < 1) {
                uVar21 = 0;
              }
              else {
                uVar21 = uVar4;
                if (uVar4 == 1) {
                  puVar17 = (undefined4 *)((int)local_30 + 3);
                  *local_30 = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar2 * 4);
                }
              }
              for (; (int)uVar21 < (int)param_4; uVar21 = uVar21 + 2) {
                iVar3 = param_1 + uVar21 * 4;
                *puVar17 = *(undefined4 *)(*(int *)(iVar3 + 0x24) + iVar2 * 4);
                *(undefined4 *)((int)puVar17 + 3) =
                     *(undefined4 *)(*(int *)(iVar3 + 0x28) + iVar2 * 4);
                puVar17 = (undefined4 *)((int)puVar17 + 6);
              }
            }
            iVar2 = iVar2 + 1;
            local_30 = (undefined4 *)((int)puVar17 + (*(int *)(param_1 + 0x10) - param_4));
          } while (iVar2 < *(int *)(param_1 + 0x40));
        }
      }
      else if ((cVar1 == ' ') && (iVar2 = *(int *)(param_1 + 0x40), 0 < iVar2)) {
        puVar17 = *(undefined4 **)(param_1 + 0x24);
        puVar19 = *(undefined4 **)(param_1 + 0x28);
        do {
          *local_30 = *puVar17;
          if (param_4 == 1) {
            uVar5 = *puVar17;
          }
          else {
            uVar5 = *puVar19;
          }
          local_30[1] = uVar5;
          puVar17 = puVar17 + 1;
          puVar19 = puVar19 + 1;
          local_30 = local_30 + (*(int *)(param_1 + 0x10) - param_4) + 2;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      return 0;
    }
  }
  return 0xffffffff;
}


