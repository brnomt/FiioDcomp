/**
 * FUN_030c1f92 @ 0x030c1f92
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030c1f92(uint param_1,uint param_2,int param_3,uint *param_4,uint *param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  iVar8 = DAT_030c267c;
  uVar7 = param_4[7];
  uVar6 = 0;
  if (uVar7 == 0) {
    return param_1;
  }
  if (uVar7 == 1) {
    if (param_6 == 1) {
      uVar7 = *param_4;
      if (0 < (int)uVar7) {
        iVar8 = 0;
        do {
          uVar6 = uVar6 | (uint)*(ushort *)
                                 (param_4[0xf] + (param_1 - param_3 * ((int)param_1 / param_3)) * 2)
                          << (param_4[0xd] * iVar8 & 0xff);
          iVar8 = iVar8 + 1;
          uVar7 = uVar7 - 1;
          param_1 = (int)param_1 / param_3;
        } while (uVar7 != 0);
      }
    }
    else {
      iVar2 = 0;
      if (0 < (int)*param_4) {
        do {
          uVar11 = *param_5;
          uVar7 = param_5[2];
          uVar10 = uVar11 + param_4[0xd];
          if ((int)uVar10 < (int)(uVar7 * 8)) {
            pbVar3 = (byte *)param_5[1];
            param_2 = (uint)(*pbVar3 >> (uVar11 & 0xff));
            if ((((8 < (int)uVar10) &&
                 (param_2 = param_2 | (uint)pbVar3[1] << (8 - uVar11 & 0xff), 0x10 < (int)uVar10))
                && (param_2 = param_2 | (uint)pbVar3[2] << (0x10 - uVar11 & 0xff),
                   0x18 < (int)uVar10)) &&
               ((param_2 = param_2 | (uint)pbVar3[3] << (0x18 - uVar11 & 0xff), 0x20 < (int)uVar10
                && (uVar11 != 0)))) {
              param_2 = param_2 | (uint)pbVar3[4] << (0x20 - uVar11 & 0xff);
            }
LAB_030c2162:
            param_2 = param_2 & *(uint *)(iVar8 + param_4[0xd] * 4);
            uVar7 = param_2;
          }
          else {
            pbVar3 = (byte *)param_5[1];
            piVar1 = (int *)param_5[3];
            if (-1 < (int)uVar7) {
              if (uVar10 != 0) {
                while (uVar7 == 0) {
                  piVar1 = (int *)piVar1[3];
                  if (piVar1 == (int *)0x0) goto LAB_030c2112;
                  pbVar3 = (byte *)(*piVar1 + piVar1[1]);
                  uVar7 = piVar1[2];
                }
                pbVar4 = pbVar3 + 1;
                param_2 = (uint)(*pbVar3 >> (uVar11 & 0xff));
                if (8 < (int)uVar10) {
                  iVar5 = uVar7 - 1;
                  while (iVar5 == 0) {
                    piVar1 = (int *)piVar1[3];
                    if (piVar1 == (int *)0x0) goto LAB_030c2112;
                    pbVar4 = (byte *)(*piVar1 + piVar1[1]);
                    iVar5 = piVar1[2];
                  }
                  pbVar3 = pbVar4 + 1;
                  param_2 = (uint)*pbVar4 << (8 - uVar11 & 0xff) | param_2;
                  if (0x10 < (int)uVar10) {
                    iVar5 = iVar5 + -1;
                    while (iVar5 == 0) {
                      piVar1 = (int *)piVar1[3];
                      if (piVar1 == (int *)0x0) goto LAB_030c2112;
                      pbVar3 = (byte *)(piVar1[1] + *piVar1);
                      iVar5 = piVar1[2];
                    }
                    pbVar4 = pbVar3 + 1;
                    param_2 = (uint)*pbVar3 << (0x10 - uVar11 & 0xff) | param_2;
                    if (0x18 < (int)uVar10) {
                      iVar5 = iVar5 + -1;
                      while (iVar5 == 0) {
                        piVar1 = (int *)piVar1[3];
                        if (piVar1 == (int *)0x0) goto LAB_030c2112;
                        pbVar4 = (byte *)(*piVar1 + piVar1[1]);
                        iVar5 = piVar1[2];
                      }
                      pbVar3 = pbVar4 + 1;
                      param_2 = (uint)*pbVar4 << (0x18 - uVar11 & 0xff) | param_2;
                      if ((0x20 < (int)uVar10) && (uVar11 != 0)) {
                        if (iVar5 == 1) {
                          do {
                            piVar1 = (int *)piVar1[3];
                            if (piVar1 == (int *)0x0) goto LAB_030c2112;
                            pbVar3 = (byte *)(*piVar1 + piVar1[1]);
                          } while (piVar1[2] == 0);
                        }
                        param_2 = param_2 | (uint)*pbVar3 << (0x20 - uVar11 & 0xff);
                      }
                    }
                  }
                }
              }
              goto LAB_030c2162;
            }
LAB_030c2112:
            uVar7 = 0xffffffff;
          }
          *param_5 = uVar10 & 7;
          param_5[2] = param_5[2] - ((int)uVar10 >> 3);
          param_5[1] = param_5[1] + ((int)uVar10 >> 3);
          if ((int)param_5[2] < 1) {
            uVar10 = param_5[2] - ((int)*param_5 >> 3);
            while ((int)uVar10 < 1) {
              uVar9 = *param_5 & 7;
              uVar10 = param_5[2] - ((int)*param_5 >> 3);
              *param_5 = uVar9;
              param_5[2] = uVar10;
              uVar11 = param_5[3];
              if (*(int *)(uVar11 + 0xc) == 0) {
                if ((int)(uVar10 * 8) < (int)uVar9) {
                  param_5[2] = 0xffffffff;
                }
                break;
              }
              param_5[5] = param_5[5] + *(int *)(uVar11 + 8);
              piVar1 = *(int **)(uVar11 + 0xc);
              param_5[3] = (uint)piVar1;
              if (0 < (int)(piVar1[2] + uVar10)) {
                param_5[1] = (*piVar1 + piVar1[1]) - uVar10;
              }
              uVar10 = piVar1[2] + uVar10;
              param_5[2] = uVar10;
            }
          }
          uVar6 = uVar6 | uVar7 << (iVar2 * (uint)(byte)param_4[0xd] & 0xff);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)*param_4);
      }
    }
  }
  else {
    if (uVar7 != 2) {
      if (uVar7 != 3) {
        param_2 = 0;
      }
      return param_2;
    }
    uVar7 = *param_4;
    if (0 < (int)uVar7) {
      bVar12 = (uVar7 & 1) != 0;
      uVar10 = param_1;
      if (bVar12) {
        uVar10 = (int)param_1 / param_3;
        uVar6 = param_1 - param_3 * uVar10;
      }
      uVar11 = (uint)bVar12;
      iVar8 = (int)uVar7 >> 1;
      if (iVar8 != 0) {
        do {
          iVar5 = (int)uVar10 / param_3;
          iVar2 = uVar10 - param_3 * iVar5;
          uVar10 = iVar5 / param_3;
          uVar6 = iVar5 - param_3 * uVar10 << (param_4[0xe] * (uVar11 + 1) & 0xff) |
                  iVar2 << (param_4[0xe] * uVar11 & 0xff) | uVar6;
          uVar11 = uVar11 + 2;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
  }
  return uVar6;
}


