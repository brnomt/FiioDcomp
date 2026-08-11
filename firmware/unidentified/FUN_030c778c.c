/**
 * FUN_030c778c @ 0x030c778c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c778c(uint *param_1,undefined1 *param_2,int param_3,uint param_4)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  
  if (param_3 == 0) {
    return;
  }
  uVar7 = *(uint *)(DAT_030c7b98 + 0x20);
  do {
    param_3 = param_3 + -1;
    uVar4 = *param_1;
    uVar5 = param_1[2];
    iVar3 = uVar4 + 8;
    if (iVar3 < (int)(uVar5 * 8)) {
      pbVar8 = (byte *)param_1[1];
      param_4 = (uint)(*pbVar8 >> (uVar4 & 0xff));
      if ((((8 < iVar3) && (param_4 = (uint)pbVar8[1] << (8 - uVar4 & 0xff) | param_4, 0x10 < iVar3)
           ) && (param_4 = (uint)pbVar8[2] << (0x10 - uVar4 & 0xff) | param_4, 0x18 < iVar3)) &&
         ((param_4 = (uint)pbVar8[3] << (0x18 - uVar4 & 0xff) | param_4, 0x20 < iVar3 &&
          (uVar4 != 0)))) {
        uVar5 = (uint)pbVar8[4] << (0x20 - uVar4 & 0xff);
LAB_030c78dc:
        param_4 = param_4 | uVar5;
      }
LAB_030c78de:
      param_4 = param_4 & uVar7;
      uVar2 = (undefined1)param_4;
    }
    else {
      pbVar8 = (byte *)param_1[1];
      piVar1 = (int *)param_1[3];
      if (-1 < (int)uVar5) {
        if (uVar4 != 0xfffffff8) {
          while (uVar5 == 0) {
            piVar1 = (int *)piVar1[3];
            if (piVar1 == (int *)0x0) goto LAB_030c7880;
            pbVar8 = (byte *)(*piVar1 + piVar1[1]);
            uVar5 = piVar1[2];
          }
          pbVar9 = pbVar8 + 1;
          param_4 = (uint)(*pbVar8 >> (uVar4 & 0xff));
          if (8 < iVar3) {
            iVar6 = uVar5 - 1;
            while (iVar6 == 0) {
              piVar1 = (int *)piVar1[3];
              if (piVar1 == (int *)0x0) goto LAB_030c7880;
              pbVar9 = (byte *)(*piVar1 + piVar1[1]);
              iVar6 = piVar1[2];
            }
            pbVar8 = pbVar9 + 1;
            param_4 = (uint)*pbVar9 << (8 - uVar4 & 0xff) | param_4;
            if (0x10 < iVar3) {
              iVar6 = iVar6 + -1;
              while (iVar6 == 0) {
                piVar1 = (int *)piVar1[3];
                if (piVar1 == (int *)0x0) goto LAB_030c7880;
                pbVar8 = (byte *)(piVar1[1] + *piVar1);
                iVar6 = piVar1[2];
              }
              pbVar9 = pbVar8 + 1;
              param_4 = (uint)*pbVar8 << (0x10 - uVar4 & 0xff) | param_4;
              if (0x18 < iVar3) {
                iVar6 = iVar6 + -1;
                while (iVar6 == 0) {
                  piVar1 = (int *)piVar1[3];
                  if (piVar1 == (int *)0x0) goto LAB_030c7880;
                  pbVar9 = (byte *)(*piVar1 + piVar1[1]);
                  iVar6 = piVar1[2];
                }
                pbVar8 = pbVar9 + 1;
                param_4 = (uint)*pbVar9 << (0x18 - uVar4 & 0xff) | param_4;
                if ((0x20 < iVar3) && (uVar4 != 0)) {
                  if (iVar6 == 1) {
                    do {
                      piVar1 = (int *)piVar1[3];
                      if (piVar1 == (int *)0x0) goto LAB_030c7880;
                      pbVar8 = (byte *)(piVar1[1] + *piVar1);
                    } while (piVar1[2] == 0);
                  }
                  uVar5 = (uint)*pbVar8 << (0x20 - uVar4 & 0xff);
                  goto LAB_030c78dc;
                }
              }
            }
          }
        }
        goto LAB_030c78de;
      }
LAB_030c7880:
      uVar2 = 0xff;
    }
    *param_1 = uVar4 + 8 & 7;
    iVar3 = (int)(uVar4 + 8) >> 3;
    param_1[2] = param_1[2] - iVar3;
    param_1[1] = param_1[1] + iVar3;
    if ((int)param_1[2] < 1) {
      uVar5 = param_1[2] - ((int)*param_1 >> 3);
      while ((int)uVar5 < 1) {
        uVar4 = *param_1 & 7;
        uVar5 = param_1[2] - ((int)*param_1 >> 3);
        *param_1 = uVar4;
        param_1[2] = uVar5;
        uVar10 = param_1[3];
        if (*(int *)(uVar10 + 0xc) == 0) {
          if ((int)(uVar5 * 8) < (int)uVar4) {
            param_1[2] = 0xffffffff;
          }
          break;
        }
        param_1[5] = param_1[5] + *(int *)(uVar10 + 8);
        piVar1 = *(int **)(uVar10 + 0xc);
        param_1[3] = (uint)piVar1;
        if (0 < (int)(piVar1[2] + uVar5)) {
          param_1[1] = (*piVar1 + piVar1[1]) - uVar5;
        }
        uVar5 = piVar1[2] + uVar5;
        param_1[2] = uVar5;
      }
    }
    *param_2 = uVar2;
    param_2 = param_2 + 1;
    if (param_3 == 0) {
      return;
    }
  } while( true );
}


