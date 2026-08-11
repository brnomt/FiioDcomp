/**
 * FUN_0308dc34 @ 0x0308dc34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_0308dc34(uint *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  byte *apbStack_6c [3];
  int iStack_60;
  short sStack_5c;
  short sStack_5a;
  byte bStack_58;
  byte bStack_57;
  byte bStack_56;
  byte bStack_55;
  byte bStack_54;
  byte bStack_53;
  byte bStack_52;
  byte bStack_51;
  undefined4 uStack_4c;
  uint local_40;
  uint local_3c;
  uint uStack_38;
  uint uStack_34;
  uint *puStack_2c;
  int local_28;
  
  local_3c = 0;
  local_40 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  puStack_2c = param_1;
  local_28 = param_2;
  iVar6 = FUN_0308cb4c(param_1,param_2);
  if (iVar6 != 0) {
    return iVar6;
  }
  uStack_38 = 1;
  uVar7 = param_1[4];
  uVar8 = uVar7 + 0x32;
  param_1[4] = uVar8;
  param_1[10] = uVar8;
  param_1[0xb] = 0;
  puVar5 = DAT_0308dda0;
  uVar8 = (0x31 < uVar8) - 1;
  if (param_1[1] <= uVar8 && (uint)(uVar7 <= *param_1) <= param_1[1] - uVar8) {
    do {
      apbStack_6c[0] = (byte *)0x0;
      iVar6 = wma_input_cache_read(param_1,apbStack_6c,*param_1,param_1[1]);
      if (iVar6 != 0x18) {
        return 3;
      }
      uVar7 = *param_1;
      *param_1 = uVar7 + 0x18;
      param_1[1] = param_1[1] + (uint)(0xffffffe7 < uVar7);
      iStack_60 = (uint)*apbStack_6c[0] + (uint)apbStack_6c[0][3] * 0x1000000 +
                  (uint)apbStack_6c[0][2] * 0x10000 + (uint)apbStack_6c[0][1] * 0x100;
      sStack_5c = (ushort)apbStack_6c[0][4] + (ushort)apbStack_6c[0][5] * 0x100;
      sStack_5a = (ushort)apbStack_6c[0][6] + (ushort)apbStack_6c[0][7] * 0x100;
      bStack_58 = apbStack_6c[0][8];
      bStack_57 = apbStack_6c[0][9];
      bStack_56 = apbStack_6c[0][10];
      bStack_55 = apbStack_6c[0][0xb];
      bStack_54 = apbStack_6c[0][0xc];
      bStack_53 = apbStack_6c[0][0xd];
      bStack_52 = apbStack_6c[0][0xe];
      bStack_51 = apbStack_6c[0][0xf];
      pbVar1 = apbStack_6c[0] + 0x10;
      pbVar2 = apbStack_6c[0] + 0x13;
      pbVar3 = apbStack_6c[0] + 0x11;
      pbVar4 = apbStack_6c[0] + 0x12;
      apbStack_6c[0] = apbStack_6c[0] + 0x18;
      uVar7 = (uint)*pbVar1 + (uint)*pbVar2 * 0x1000000 +
              (uint)*pbVar4 * 0x10000 + (uint)*pbVar3 * 0x100;
      if (uVar7 < 0x18) {
        return 4;
      }
      iVar6 = wma_memcmp(*DAT_0308dda4,&iStack_60,0x10);
      if (iVar6 == 0) {
        local_3c = local_3c + 1 & 0xffff;
        uVar8 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
        if (param_1[0xb] <= uVar8 &&
            (uint)(*param_1 + (uVar7 - 0x18) <= param_1[10]) <= param_1[0xb] - uVar8) {
          return 1;
        }
        iVar6 = FUN_0308cc46(param_1,uVar7,local_28);
        if (iVar6 != 0) {
          return iVar6;
        }
      }
      else {
        iVar6 = wma_memcmp(*DAT_0308dd8c,&iStack_60,0x10);
        if ((iVar6 == 0) || (iVar6 = wma_memcmp(*DAT_0308dd90,&iStack_60,0x10), iVar6 == 0)) {
          local_40 = local_40 + 1 & 0xffff;
          uVar8 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
          if (param_1[0xb] <= uVar8 &&
              (uint)(*param_1 + (uVar7 - 0x18) <= param_1[10]) <= param_1[0xb] - uVar8) {
            return 1;
          }
          iVar6 = wma_audio_parse(param_1,uVar7,local_28);
          if (iVar6 != 0) {
            return iVar6;
          }
        }
        else {
          iVar6 = wma_memcmp(*DAT_0308dda8,&iStack_60,0x10);
          if (iVar6 == 0) {
            uVar8 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
            if (param_1[0xb] <= uVar8 &&
                (uint)(*param_1 + (uVar7 - 0x18) <= param_1[10]) <= param_1[0xb] - uVar8) {
              return 1;
            }
            iVar6 = ssl_parse_record_header(param_1,uVar7);
            if (iVar6 != 0) {
              return iVar6;
            }
          }
          else {
            iVar6 = wma_memcmp(*DAT_0308e0d0,&iStack_60,0x10);
            if (iVar6 == 0) {
              uVar8 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
              if (param_1[0xb] <= uVar8 &&
                  (uint)(*param_1 + (uVar7 - 0x18) <= param_1[10]) <= param_1[0xb] - uVar8) {
                return 1;
              }
              FUN_0308d546(param_1,uVar7);
            }
            else {
              iVar6 = wma_memcmp(*DAT_0308e0d4,&iStack_60,0x10);
              if (iVar6 == 0) {
                uVar8 = *param_1 + (uVar7 - 0x18);
                uVar11 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
                if (param_1[0xb] <= uVar11 && (uint)(uVar8 <= param_1[10]) <= param_1[0xb] - uVar11)
                {
                  return 1;
                }
                if (local_28 == 0) {
                  *param_1 = uVar8;
                  param_1[1] = uVar11;
                }
                else {
                  uStack_4c = 0;
                  uVar11 = *param_1;
                  uVar10 = param_1[1];
                  uVar8 = uVar11 + uVar7;
                  wma_input_cache_read(param_1);
                  *param_1 = uVar8 - 0x18;
                  param_1[1] = uVar10 + CARRY4(uVar11,uVar7) + -1 + (uint)(0x17 < uVar8);
                }
              }
              else {
                iVar6 = wma_memcmp(*DAT_0308e0d8,&iStack_60,0x10);
                if (iVar6 == 0) {
                  uVar8 = param_1[1] + (uint)CARRY4(*param_1,uVar7 - 0x18);
                  if (param_1[0xb] <= uVar8 &&
                      (uint)(*param_1 + (uVar7 - 0x18) <= param_1[10]) <= param_1[0xb] - uVar8) {
                    return 1;
                  }
                  apbStack_6c[0] = (byte *)0x0;
                  if (param_1 == (uint *)0x0) {
                    return 2;
                  }
                  uStack_34 = uVar7 - 0x18;
                  if ((uStack_34 < 8) ||
                     (iVar6 = wma_input_cache_read(param_1,uStack_34,*param_1,param_1[1]),
                     iVar6 != 8)) {
                    return 3;
                  }
                  uVar8 = 8;
                  pbVar1 = apbStack_6c[0] + 4;
                  pbVar2 = apbStack_6c[0] + 7;
                  pbVar3 = apbStack_6c[0] + 5;
                  pbVar4 = apbStack_6c[0] + 6;
                  apbStack_6c[0] = apbStack_6c[0] + 8;
                  param_1[0x36] =
                       (uint)*pbVar4 * 0x10000 + (uint)*pbVar3 * 0x100 +
                       (uint)*pbVar1 + (uint)*pbVar2 * 0x1000000;
                  uVar7 = param_1[0x36];
                  if (uStack_34 < uVar7 + 8) {
                    return 7;
                  }
                  if (0x100 < uVar7) {
                    return 5;
                  }
                  param_1[0x37] = DAT_0308e0e0;
                  uVar11 = 0;
                  if (*puVar5 < uVar7) {
                    do {
                      uVar10 = *puVar5;
                      if (uVar7 <= uVar10) {
                        uVar10 = uVar7;
                      }
                      uVar9 = wma_input_cache_read
                                        (param_1,param_1[1],*param_1 + uVar8,
                                         param_1[1] + (uint)CARRY4(*param_1,uVar8));
                      if (uVar9 != uVar10) {
                        return 3;
                      }
                      uVar7 = uVar7 - uVar9;
                      uVar8 = uVar8 + uVar9;
                      if (param_1[0x36] < uVar11 + uVar9) {
                        return 3;
                      }
                      wma_memmove(param_1[0x37] + uVar11,apbStack_6c[0]);
                      uVar11 = uVar11 + uVar9;
                    } while (uVar7 != 0);
                  }
                  else {
                    uVar8 = *param_1;
                    uVar8 = wma_input_cache_read
                                      (param_1,uVar8,uVar8 + 8,
                                       param_1[1] + (uint)(0xfffffff7 < uVar8));
                    if (uVar8 != uVar7) {
                      return 3;
                    }
                    wma_memmove(param_1[0x37],apbStack_6c[0],uVar8);
                  }
                  param_1[1] = param_1[1] + (uint)CARRY4(*param_1,uStack_34);
                  *param_1 = *param_1 + uStack_34;
                }
                else {
                  iVar6 = wma_memcmp(*DAT_0308e0dc,&iStack_60,0x10);
                  uVar11 = *param_1;
                  uVar8 = uVar7 - 0x18;
                  if (iVar6 == 0) {
                    uVar10 = param_1[1] + (uint)CARRY4(uVar11,uVar8);
                    if (param_1[0xb] <= uVar10 &&
                        (uint)(uVar11 + uVar8 <= param_1[10]) <= param_1[0xb] - uVar10) {
                      return 1;
                    }
                    iVar6 = FUN_0308da04(param_1,uVar7,local_28);
                    if (iVar6 != 0) {
                      return iVar6;
                    }
                  }
                  else {
                    *param_1 = uVar11 + uVar8;
                    param_1[1] = param_1[1] + (uint)CARRY4(uVar11,uVar8);
                  }
                }
              }
            }
          }
        }
      }
      uVar7 = param_1[1];
      uVar8 = (param_1[0xb] - 1) + (uint)(0x31 < param_1[10]);
    } while (uVar7 <= uVar8 && (uint)(param_1[10] - 0x32 <= *param_1) <= uVar7 - uVar8);
    bVar12 = uStack_38 == 1;
    if (bVar12) {
      uStack_38 = local_3c;
    }
    if (((bVar12 && uStack_38 == 1) && (local_40 != 0)) &&
       (uVar7 == (param_1[0xb] - 1) + (uint)(0x31 < param_1[10]) && *param_1 == param_1[10] - 0x32))
    {
      return 0;
    }
  }
  return 1;
}


