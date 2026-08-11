/**
 * FUN_030c4238 @ 0x030c4238
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c4238(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar9 = *param_1;
  puVar7 = (uint *)(param_1 + 1);
  iVar10 = *param_2;
  iVar8 = *(int *)(iVar9 + 0x1c);
  memset_byte(puVar7,0,0x18);
  param_1[4] = iVar10;
  param_1[5] = iVar10;
  param_1[6] = 0;
  param_1[2] = ((int *)param_1[4])[1] + *(int *)param_1[4];
  iVar10 = *(int *)(param_1[4] + 8);
  param_1[3] = iVar10;
  iVar10 = iVar10 - ((int)*puVar7 >> 3);
  do {
    if (0 < iVar10) {
LAB_030c42d8:
      iVar10 = sbuf_read_bits(param_1 + 1,1);
      if (iVar10 != 0) {
        return 0xffffff79;
      }
      iVar10 = 0;
      uVar5 = *(uint *)(iVar8 + 8);
      bVar11 = uVar5 == 0;
      if (!bVar11) {
        uVar5 = uVar5 - 1;
        bVar11 = uVar5 == 0;
      }
      if (!bVar11) {
        do {
          iVar10 = iVar10 + 1;
          uVar5 = uVar5 >> 1;
        } while (uVar5 != 0);
      }
      iVar1 = sbuf_read_bits(param_1 + 1,iVar10);
      bVar11 = iVar1 != -1;
      iVar10 = 0;
      iVar2 = 0;
      if (bVar11) {
        iVar2 = *(int *)(iVar8 + 8);
        iVar10 = iVar2 - iVar1;
      }
      if ((bVar11 && iVar2 != iVar1) && iVar10 < 0 == (bVar11 && SBORROW4(iVar2,iVar1))) {
        param_1[0xb] = param_1[0xc];
        iVar10 = 0;
        param_1[0xc] = (uint)*(byte *)(*(int *)(iVar8 + 0x1c) + iVar1 * 2);
        if (0 < *(int *)(iVar9 + 4)) {
          do {
            FUN_030ca0ca(*(undefined4 *)(iVar8 + param_1[0xb] * 4),
                         *(undefined4 *)(param_1[7] + iVar10 * 4),
                         *(undefined4 *)(param_1[8] + iVar10 * 4));
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(iVar9 + 4));
        }
        if (param_1[0xc] != 0) {
          sbuf_read_bits(param_1 + 1,1);
          iVar10 = sbuf_read_bits(param_1 + 1,1);
          if (iVar10 == -1) {
            return 0xffffff78;
          }
        }
        if (param_3 != 0) {
          FUN_030c910a(param_1,*(int *)(iVar8 + 0x20) +
                               (uint)*(byte *)(*(int *)(iVar8 + 0x1c) + iVar1 * 2 + 1) * 0x14);
          iVar10 = param_1[9];
          param_1[9] = 0;
          if (iVar10 == -1) {
            param_1[10] = 0;
          }
          else {
            iVar10 = *(int *)(iVar8 + param_1[0xb] * 4);
            iVar9 = *(int *)(iVar8 + param_1[0xc] * 4);
            param_1[10] = ((int)(iVar10 + ((uint)(iVar10 >> 0x1f) >> 0x1e)) >> 2) +
                          ((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x1e)) >> 2);
          }
        }
        uVar5 = param_1[0x10];
        if ((uVar5 == 0xffffffff && param_1[0x11] == -1) ||
           (uVar5 - param_2[6] != -4 ||
            (param_1[0x11] - param_2[7]) - (uint)(uVar5 < (uint)param_2[6]) != -1)) {
          param_1[0xe] = -1;
          param_1[0xf] = -1;
          param_1[0x12] = -1;
          param_1[0x13] = -1;
        }
        uVar5 = param_2[6];
        iVar10 = param_2[7];
        param_1[0x10] = uVar5 - 3;
        param_1[0x11] = iVar10 + -1 + (uint)(2 < uVar5);
        uVar5 = param_1[0x12];
        if (uVar5 == 0xffffffff && param_1[0x13] == -1) {
          param_1[0x12] = 0;
          param_1[0x13] = 0;
        }
        else {
          iVar9 = *(int *)(iVar8 + param_1[0xb] * 4);
          iVar10 = *(int *)(iVar8 + param_1[0xc] * 4);
          uVar6 = ((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x1e)) >> 2) +
                  ((int)(iVar10 + ((uint)(iVar10 >> 0x1f) >> 0x1e)) >> 2);
          param_1[0x12] = uVar6 + uVar5;
          param_1[0x13] = param_1[0x13] + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar6,uVar5);
        }
        uVar5 = param_1[0xe];
        if (uVar5 == 0xffffffff && param_1[0xf] == -1) {
          uVar5 = param_2[4];
          iVar10 = param_2[5];
          if (uVar5 != 0xffffffff || iVar10 != -1) {
            param_1[0xe] = uVar5;
            param_1[0xf] = iVar10;
            uVar6 = param_1[0x12];
            iVar8 = param_1[0x13];
            if ((int)((iVar10 - iVar8) - (uint)(uVar5 < uVar6)) < 0 !=
                (SBORROW4(iVar10,iVar8) != SBORROW4(iVar10 - iVar8,(uint)(uVar5 < uVar6)))) {
              if (param_2[3] == 0) {
                iVar10 = (uVar6 - uVar5) + param_1[9];
                param_1[9] = iVar10;
                if (param_1[10] < iVar10) {
                  iVar10 = param_1[10];
                }
                param_1[9] = iVar10;
              }
              else {
                param_1[10] = param_1[10] - (uVar6 - uVar5);
              }
            }
          }
        }
        else {
          iVar9 = *(int *)(iVar8 + param_1[0xb] * 4);
          iVar10 = *(int *)(iVar8 + param_1[0xc] * 4);
          uVar4 = ((int)(iVar9 + ((uint)(iVar9 >> 0x1f) >> 0x1e)) >> 2) +
                  ((int)(iVar10 + ((uint)(iVar10 >> 0x1f) >> 0x1e)) >> 2);
          uVar6 = uVar4 + uVar5;
          iVar10 = param_1[0xf] + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar4,uVar5);
          param_1[0xe] = uVar6;
          param_1[0xf] = iVar10;
          uVar5 = param_2[4];
          iVar8 = param_2[5];
          if ((uVar5 != 0xffffffff || iVar8 != -1) && (uVar6 != uVar5 || iVar10 != iVar8)) {
            if ((int)((iVar8 - iVar10) - (uint)(uVar5 < uVar6)) < 0 !=
                (SBORROW4(iVar8,iVar10) != SBORROW4(iVar8 - iVar10,(uint)(uVar5 < uVar6)))) {
              iVar10 = uVar6 - uVar5;
              if (iVar10 != 0) {
                uVar6 = param_2[3];
              }
              if (iVar10 != 0 && uVar6 != 0) {
                param_1[10] = param_1[10] - iVar10;
              }
            }
            iVar10 = param_2[5];
            param_1[0xe] = param_2[4];
            param_1[0xf] = iVar10;
          }
        }
        return 0;
      }
      return 0xffffff78;
    }
    uVar5 = *puVar7 & 7;
    iVar10 = param_1[3] - ((int)*puVar7 >> 3);
    *puVar7 = uVar5;
    param_1[3] = iVar10;
    iVar2 = param_1[4];
    if (*(int *)(iVar2 + 0xc) == 0) {
      if (param_1[3] * 8 < (int)uVar5) {
        param_1[3] = -1;
      }
      goto LAB_030c42d8;
    }
    param_1[6] = param_1[6] + *(int *)(iVar2 + 8);
    piVar3 = *(int **)(iVar2 + 0xc);
    param_1[4] = (int)piVar3;
    if (0 < piVar3[2] + iVar10) {
      param_1[2] = (*piVar3 + piVar3[1]) - iVar10;
    }
    iVar10 = iVar10 + piVar3[2];
    param_1[3] = iVar10;
  } while( true );
}


