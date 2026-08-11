/**
 * FUN_030c49d8 @ 0x030c49d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030c49d8(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  uint unaff_r5;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  iVar2 = DAT_030c4d78;
  iVar13 = *(int *)(param_1 + 0x1c);
  iVar1 = *DAT_030c4d7c;
  *DAT_030c4d7c = iVar1 + 1;
  piVar8 = (int *)(iVar2 + iVar1 * 0x28);
  iVar2 = sbuf_read_bits(param_2,8);
  *piVar8 = iVar2;
  iVar2 = sbuf_read_bits(param_2,0x10);
  piVar8[1] = iVar2;
  iVar2 = sbuf_read_bits(param_2,0x10);
  piVar8[2] = iVar2;
  iVar2 = sbuf_read_bits(param_2,6);
  piVar8[3] = iVar2;
  iVar2 = sbuf_read_bits(param_2,8);
  piVar8[4] = iVar2;
  iVar2 = sbuf_read_bits(param_2,4);
  piVar8[5] = iVar2 + 1;
  iVar1 = *piVar8;
  if (0 < iVar1) {
    iVar1 = piVar8[1];
  }
  if (0 < iVar1) {
    iVar1 = piVar8[2];
  }
  if (0 < iVar1) {
    iVar1 = 0;
    if (0 < iVar2 + 1) {
      uVar12 = *(uint *)(DAT_030c4d80 + 0x20);
      do {
        uVar4 = *param_2;
        uVar9 = param_2[2];
        iVar2 = uVar4 + 8;
        if (iVar2 < (int)(uVar9 * 8)) {
          pbVar5 = (byte *)param_2[1];
          unaff_r5 = (uint)(*pbVar5 >> (uVar4 & 0xff));
          if ((((8 < iVar2) &&
               (unaff_r5 = unaff_r5 | (uint)pbVar5[1] << (8 - uVar4 & 0xff), 0x10 < iVar2)) &&
              (unaff_r5 = unaff_r5 | (uint)pbVar5[2] << (0x10 - uVar4 & 0xff), 0x18 < iVar2)) &&
             ((unaff_r5 = unaff_r5 | (uint)pbVar5[3] << (0x18 - uVar4 & 0xff), 0x20 < iVar2 &&
              (uVar4 != 0)))) {
            uVar9 = (uint)pbVar5[4] << (0x20 - uVar4 & 0xff);
LAB_030c4b7a:
            unaff_r5 = unaff_r5 | uVar9;
          }
LAB_030c4b7c:
          unaff_r5 = unaff_r5 & uVar12;
          bVar7 = (byte)unaff_r5;
        }
        else {
          pbVar5 = (byte *)param_2[1];
          piVar3 = (int *)param_2[3];
          if (-1 < (int)uVar9) {
            if (uVar4 != 0xfffffff8) {
              while (uVar9 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c4b30;
                pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                uVar9 = piVar3[2];
              }
              pbVar6 = pbVar5 + 1;
              unaff_r5 = (uint)(*pbVar5 >> (uVar4 & 0xff));
              if (8 < iVar2) {
                iVar10 = uVar9 - 1;
                while (iVar10 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c4b30;
                  pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                  iVar10 = piVar3[2];
                }
                pbVar5 = pbVar6 + 1;
                unaff_r5 = (uint)*pbVar6 << (8 - uVar4 & 0xff) | unaff_r5;
                if (0x10 < iVar2) {
                  iVar10 = iVar10 + -1;
                  while (iVar10 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c4b30;
                    pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                    iVar10 = piVar3[2];
                  }
                  pbVar6 = pbVar5 + 1;
                  unaff_r5 = (uint)*pbVar5 << (0x10 - uVar4 & 0xff) | unaff_r5;
                  if (0x18 < iVar2) {
                    iVar10 = iVar10 + -1;
                    while (iVar10 == 0) {
                      piVar3 = (int *)piVar3[3];
                      if (piVar3 == (int *)0x0) goto LAB_030c4b30;
                      pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                      iVar10 = piVar3[2];
                    }
                    pbVar5 = pbVar6 + 1;
                    unaff_r5 = (uint)*pbVar6 << (0x18 - uVar4 & 0xff) | unaff_r5;
                    if ((0x20 < iVar2) && (uVar4 != 0)) {
                      if (iVar10 == 1) {
                        do {
                          piVar3 = (int *)piVar3[3];
                          if (piVar3 == (int *)0x0) goto LAB_030c4b30;
                          pbVar5 = (byte *)(piVar3[1] + *piVar3);
                        } while (piVar3[2] == 0);
                      }
                      uVar9 = (uint)*pbVar5 << (0x20 - uVar4 & 0xff);
                      goto LAB_030c4b7a;
                    }
                  }
                }
              }
            }
            goto LAB_030c4b7c;
          }
LAB_030c4b30:
          bVar7 = 0xff;
        }
        *param_2 = uVar4 + 8 & 7;
        iVar2 = (int)(uVar4 + 8) >> 3;
        param_2[2] = param_2[2] - iVar2;
        param_2[1] = param_2[1] + iVar2;
        if ((int)param_2[2] < 1) {
          uVar9 = param_2[2] - ((int)*param_2 >> 3);
          while ((int)uVar9 < 1) {
            uVar11 = *param_2 & 7;
            uVar9 = param_2[2] - ((int)*param_2 >> 3);
            *param_2 = uVar11;
            param_2[2] = uVar9;
            uVar4 = param_2[3];
            if (*(int *)(uVar4 + 0xc) == 0) {
              if ((int)(uVar9 * 8) < (int)uVar11) {
                param_2[2] = 0xffffffff;
              }
              break;
            }
            param_2[5] = param_2[5] + *(int *)(uVar4 + 8);
            piVar3 = *(int **)(uVar4 + 0xc);
            param_2[3] = (uint)piVar3;
            if (0 < (int)(piVar3[2] + uVar9)) {
              param_2[1] = (*piVar3 + piVar3[1]) - uVar9;
            }
            uVar9 = piVar3[2] + uVar9;
            param_2[2] = uVar9;
          }
        }
        *(byte *)((int)piVar8 + iVar1 + 0x18) = bVar7;
        if (*(int *)(iVar13 + 0x18) <= (int)(uint)bVar7) goto LAB_030c4c38;
        iVar1 = iVar1 + 1;
      } while (iVar1 < piVar8[5]);
    }
    if (-1 < (int)param_2[2]) {
      return piVar8;
    }
  }
LAB_030c4c38:
  memset_byte(DAT_030c4d78,0,0x50);
  return (int *)0x0;
}


