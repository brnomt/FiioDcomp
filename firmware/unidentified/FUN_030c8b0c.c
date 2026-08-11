/**
 * FUN_030c8b0c @ 0x030c8b0c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030c8b0c(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  uint local_48;
  byte *local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  undefined1 *puStack_30;
  undefined1 auStack_2c [8];
  
  if (param_3 != (undefined4 *)0x0) {
    piVar9 = (int *)*param_3;
    memset_byte(&local_48,0,0x18);
    local_34 = 0;
    local_44 = (byte *)(piVar9[1] + *piVar9);
    local_40 = piVar9[2];
    local_3c = piVar9;
    iVar1 = local_40 - ((int)local_48 >> 3);
    while (iVar1 < 1) {
      local_40 = local_40 - ((int)local_48 >> 3);
      local_48 = local_48 & 7;
      if (local_3c[3] == 0) {
        if (local_40 * 8 < (int)local_48) {
          local_40 = -1;
        }
        break;
      }
      local_34 = local_34 + local_3c[2];
      local_3c = (int *)local_3c[3];
      if (0 < local_3c[2] + local_40) {
        local_44 = (byte *)((local_3c[1] + *local_3c) - local_40);
      }
      local_40 = local_3c[2] + local_40;
      iVar1 = local_40;
    }
    local_38 = piVar9;
    iVar1 = sbuf_read_bits(&local_48,8);
    memset_byte(auStack_2c,0,6);
    FUN_030c778c(&local_48,auStack_2c,6);
    iVar2 = FUN_030c0fdc(auStack_2c,s_vorbis_030c8cf4,6);
    if (iVar2 != 0) {
      return 0xffffff7c;
    }
    if (iVar1 == 1) {
      if ((param_3[2] != 0) && (param_1[2] == 0)) {
        piVar9 = (int *)param_1[7];
        if (piVar9 == (int *)0x0) {
          return 0xffffff7f;
        }
        iVar1 = sbuf_read_bits(&local_48,0x20);
        *param_1 = iVar1;
        if (iVar1 != 0) {
          return 0xffffff7a;
        }
        iVar1 = sbuf_read_bits(&local_48,8);
        param_1[1] = iVar1;
        iVar1 = sbuf_read_bits(&local_48,0x20);
        param_1[2] = iVar1;
        iVar1 = sbuf_read_bits(&local_48,0x20);
        param_1[3] = iVar1;
        iVar1 = sbuf_read_bits(&local_48,0x20);
        param_1[4] = iVar1;
        iVar1 = sbuf_read_bits(&local_48,0x20);
        param_1[5] = iVar1;
        uVar3 = sbuf_read_bits(&local_48,4);
        *piVar9 = 1 << (uVar3 & 0xff);
        uVar3 = sbuf_read_bits(&local_48,4);
        iVar1 = 1 << (uVar3 & 0xff);
        piVar9[1] = iVar1;
        iVar2 = param_1[2];
        if ((63999 < iVar2) || (iVar1 < 0x1001)) {
          if (0 < iVar2) {
            iVar2 = param_1[1];
          }
          if (0 < iVar2) {
            iVar5 = *piVar9;
            bVar10 = SBORROW4(iVar5,0x40);
            iVar2 = iVar5 + -0x40;
            if (0x3f < iVar5) {
              bVar10 = SBORROW4(iVar1,iVar5);
              iVar2 = iVar1 - iVar5;
            }
            if (((iVar2 < 0 == bVar10) && (iVar1 < 0x2001)) &&
               (iVar1 = sbuf_read_bits(&local_48,1), iVar1 == 1)) {
              return 0;
            }
          }
        }
        FUN_030c7b12(param_1);
      }
    }
    else if (iVar1 == 3) {
      if (param_1[2] != 0) {
        puStack_30 = (undefined1 *)&local_48;
        iVar1 = sbuf_read_bits(&local_48,0x20);
        if (-1 < iVar1) {
          param_2[3] = DAT_030c8cfc;
          FUN_030c778c(puStack_30);
          iVar1 = sbuf_read_bits(puStack_30,0x20);
          param_2[2] = iVar1;
          if (-1 < iVar1) {
            iVar2 = 0;
            iVar1 = DAT_030c8f7c + 0x20;
            *param_2 = DAT_030c8f7c;
            param_2[1] = iVar1;
            iVar1 = DAT_030c8f80;
            if (0 < param_2[2]) {
              do {
                iVar5 = local_48 + 0x20;
                if (iVar5 < local_40 * 8) {
                  param_1 = (int *)(uint)(*local_44 >> (local_48 & 0xff));
                  if (((8 < iVar5) &&
                      (param_1 = (int *)((uint)param_1 | (uint)local_44[1] << (8 - local_48 & 0xff))
                      , 0x10 < iVar5)) &&
                     ((param_1 = (int *)((uint)param_1 |
                                        (uint)local_44[2] << (0x10 - local_48 & 0xff)), 0x18 < iVar5
                      && ((param_1 = (int *)((uint)param_1 |
                                            (uint)local_44[3] << (0x18 - local_48 & 0xff)),
                          0x20 < iVar5 && (local_48 != 0)))))) {
                    uVar3 = (uint)local_44[4] << (0x20 - local_48 & 0xff);
LAB_030c8e4c:
                    param_1 = (int *)((uint)param_1 | uVar3);
                  }
LAB_030c8e4e:
                  piVar9 = (int *)((uint)param_1 & *(uint *)(iVar1 + 0x80));
                  param_1 = piVar9;
                }
                else {
                  if (-1 < local_40) {
                    iVar8 = local_40;
                    pbVar7 = local_44;
                    piVar9 = local_3c;
                    if (local_48 != 0xffffffe0) {
                      while (iVar8 == 0) {
                        piVar9 = (int *)piVar9[3];
                        if (piVar9 == (int *)0x0) goto LAB_030c8dfc;
                        iVar8 = piVar9[2];
                        pbVar7 = (byte *)(*piVar9 + piVar9[1]);
                      }
                      pbVar6 = pbVar7 + 1;
                      param_1 = (int *)(uint)(*pbVar7 >> (local_48 & 0xff));
                      if (8 < iVar5) {
                        iVar8 = iVar8 + -1;
                        while (iVar8 == 0) {
                          piVar9 = (int *)piVar9[3];
                          if (piVar9 == (int *)0x0) goto LAB_030c8dfc;
                          pbVar6 = (byte *)(*piVar9 + piVar9[1]);
                          iVar8 = piVar9[2];
                        }
                        pbVar7 = pbVar6 + 1;
                        param_1 = (int *)((uint)*pbVar6 << (8 - local_48 & 0xff) | (uint)param_1);
                        if (0x10 < iVar5) {
                          iVar8 = iVar8 + -1;
                          while (iVar8 == 0) {
                            piVar9 = (int *)piVar9[3];
                            if (piVar9 == (int *)0x0) goto LAB_030c8dfc;
                            pbVar7 = (byte *)(piVar9[1] + *piVar9);
                            iVar8 = piVar9[2];
                          }
                          pbVar6 = pbVar7 + 1;
                          param_1 = (int *)((uint)*pbVar7 << (0x10 - local_48 & 0xff) |
                                           (uint)param_1);
                          if (0x18 < iVar5) {
                            iVar8 = iVar8 + -1;
                            while (iVar8 == 0) {
                              piVar9 = (int *)piVar9[3];
                              if (piVar9 == (int *)0x0) goto LAB_030c8dfc;
                              pbVar6 = (byte *)(*piVar9 + piVar9[1]);
                              iVar8 = piVar9[2];
                            }
                            pbVar7 = pbVar6 + 1;
                            param_1 = (int *)((uint)*pbVar6 << (0x18 - local_48 & 0xff) |
                                             (uint)param_1);
                            if ((0x20 < iVar5) && (local_48 != 0)) {
                              if (iVar8 == 1) {
                                do {
                                  piVar9 = (int *)piVar9[3];
                                  if (piVar9 == (int *)0x0) goto LAB_030c8dfc;
                                  pbVar7 = (byte *)(*piVar9 + piVar9[1]);
                                } while (piVar9[2] == 0);
                              }
                              uVar3 = (uint)*pbVar7 << (0x20 - local_48 & 0xff);
                              goto LAB_030c8e4c;
                            }
                          }
                        }
                      }
                    }
                    goto LAB_030c8e4e;
                  }
LAB_030c8dfc:
                  piVar9 = (int *)0xffffffff;
                }
                uVar3 = local_48 + 0x20;
                local_48 = uVar3 & 7;
                iVar5 = (int)uVar3 >> 3;
                local_40 = local_40 - iVar5;
                local_44 = local_44 + iVar5;
                if (local_40 < 1) {
                  for (; local_40 < 1; local_40 = local_3c[2] + local_40) {
                    if (local_3c[3] == 0) {
                      if (local_40 * 8 < (int)local_48) {
                        local_40 = -1;
                      }
                      break;
                    }
                    local_34 = local_3c[2] + local_34;
                    local_3c = (int *)local_3c[3];
                    if (0 < local_3c[2] + local_40) {
                      local_44 = (byte *)((*local_3c + local_3c[1]) - local_40);
                    }
                  }
                }
                if ((int)piVar9 < 0) goto LAB_030c8f20;
                *(int **)(param_2[1] + iVar2 * 4) = piVar9;
                iVar5 = DAT_030c8f84 + iVar2 * 0x24;
                *(int *)(DAT_030c8f84 + 0x122 + iVar2 * 4) = iVar5;
                *(int *)(*param_2 + iVar2 * 4) = iVar5;
                FUN_030c778c(puStack_30);
                iVar2 = iVar2 + 1;
              } while (iVar2 < param_2[2]);
            }
            iVar1 = sbuf_read_bits(puStack_30,1);
            if (iVar1 == 1) {
              return 0;
            }
          }
        }
LAB_030c8f20:
        if (param_2 != (int *)0x0) {
          *param_2 = 0;
          param_2[1] = 0;
          iVar1 = DAT_030c8f84;
          param_2[3] = 0;
          memset_byte(iVar1,0,0x120);
          memset_byte(DAT_030c8f88,0,0x3a);
          memset_byte(DAT_030c8f8c,0,8);
        }
        memset_byte(param_2,0,0x10);
      }
    }
    else if ((iVar1 == 5) && (param_1[2] != 0)) {
      uVar4 = FUN_030c7bd2(param_1,&local_48);
      return uVar4;
    }
  }
  return 0xffffff7b;
}


