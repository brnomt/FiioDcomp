/**
 * FUN_0308f6f6 @ 0x0308f6f6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308f6f6(int *param_1,short *param_2,int *param_3,undefined4 param_4,undefined1 *param_5,
                undefined4 *param_6)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  
  puVar2 = (undefined1 *)0x0;
  if (param_1 != (int *)0x0) {
    puVar2 = param_5;
  }
  iVar7 = DAT_0308fb08;
  if ((param_1 != (int *)0x0 && puVar2 != (undefined1 *)0x0) &&
     (iVar4 = FUN_0308f364(param_2,param_3,param_4,param_6), iVar7 = iVar4, -1 < iVar4)) {
    param_1[0x75] = 0;
    iVar5 = FUN_0308eb9c();
    *param_1 = iVar5;
    iVar7 = DAT_0308fafc;
    if ((iVar5 != 0) &&
       (*(undefined4 *)(iVar5 + 0x164) = DAT_0308fae0, iVar12 = DAT_0308fae4, iVar7 = iVar4,
       *(char *)(iVar5 + 0x48) != '\x03')) {
      sVar1 = *param_2;
      if (sVar1 == 0x160) {
        uVar10 = 1;
      }
      else if (sVar1 == 0x161) {
        uVar10 = 2;
      }
      else {
        if (sVar1 != 0x162 && sVar1 != 0x163) {
          return DAT_0308fae4;
        }
        uVar10 = 3;
      }
      iVar4 = FUN_0308fb3c(*(undefined4 *)(param_2 + 2),*(int *)(param_2 + 4) << 3,param_2[1],uVar10
                           ,param_2[10]);
      iVar7 = iVar12;
      if (0 < iVar4) {
        if ((short)param_1[0x60] != 0) {
          *(ushort *)(param_1 + 0x5a) = *(ushort *)(param_1 + 0x5a) | 0x80;
        }
        uVar6 = (ushort)param_2[7] + 7 >> 3;
        if (uVar6 < (uint)param_3[4]) {
          uVar6 = param_3[4];
        }
        iVar7 = FUN_0308f178(iVar5,uVar10,iVar4,*(undefined4 *)(param_2 + 2),param_2[1],uVar6,
                             (uint)(ushort)param_2[7],*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_2 + 4),param_2[6],param_2[10],*param_3,
                             param_1 + 0x5a);
        iVar4 = DAT_0308fae8;
        if (-1 < iVar7) {
          param_1[1] = DAT_0308fae8;
          wma_memclr(iVar4,(uint)*(ushort *)(iVar5 + 0x26) * 0xfc);
          iVar4 = *param_1;
          iVar12 = param_1[1];
          param_1[2] = DAT_0308faec;
          iVar7 = 0;
          if (*(short *)(iVar4 + 0x26) != 0) {
            do {
              iVar11 = iVar12 + iVar7 * 0xfc;
              puVar8 = (undefined4 *)(DAT_0308faf0 + iVar7 * 0x18);
              *(undefined4 **)(iVar11 + 0xc0) = puVar8;
              if (puVar8 == (undefined4 *)0x0) {
                return DAT_0308fafc;
              }
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8[4] = 0;
              puVar8[5] = 0;
              iVar9 = iVar7 * 0x43 + DAT_0308faf4;
              *(int *)(*(int *)(iVar11 + 0xc0) + 4) = iVar9;
              if (iVar9 == 0) {
                return DAT_0308fafc;
              }
              wma_memclr(iVar9,*(int *)(iVar4 + 0x80) * 2 + 7);
              iVar9 = *(int *)(*(int *)(iVar11 + 0xc0) + 4) + 2;
              *(int *)(*(int *)(iVar11 + 0xc0) + 8) = iVar9;
              iVar9 = iVar9 + *(int *)(iVar4 + 0x80) * 2 + 2;
              *(int *)(*(int *)(iVar11 + 0xc0) + 0xc) = iVar9;
              *(int *)(*(int *)(iVar11 + 0xc0) + 0x10) = iVar9 + 2;
              iVar7 = (int)(short)((short)iVar7 + 1);
            } while (iVar7 < (int)(uint)*(ushort *)(iVar4 + 0x26));
          }
          iVar7 = FUN_0308f0b4(iVar5,param_1[1]);
          if (-1 < iVar7) {
            *(int *)(iVar5 + 0xd8) = param_1[1];
            iVar7 = *param_1;
            if ((*(int *)(iVar7 + 0xb4) == 0) || (*(int *)(iVar7 + 0x2c) != 0)) {
              *DAT_0308faf8 = 0;
            }
            else {
              *DAT_0308faf8 = 1;
            }
            iVar4 = 0;
            if (*(short *)(iVar7 + 0x26) != 0) {
              do {
                iVar12 = *(int *)(iVar7 + 0xd8) + iVar4 * 0xfc;
                if (*(int *)(iVar7 + 0xb4) == 0) {
                  *(int *)(iVar12 + 0x40) =
                       *(int *)(iVar7 + 0x144) + *(int *)(iVar7 + 0x9c) * iVar4 * 4;
                  iVar11 = *(int *)(iVar7 + 0x144) + *(int *)(iVar7 + 0x9c) * iVar4 * 4;
                }
                else {
                  iVar11 = iVar4 * 0xfc + 4;
                  *(undefined4 *)(iVar12 + 0x40) = *(undefined4 *)(*(int *)(iVar7 + 0xd8) + iVar11);
                  iVar11 = *(int *)(*(int *)(iVar7 + 0xd8) + iVar11);
                }
                *(int *)(iVar12 + 0xa0) = iVar11;
                iVar4 = (int)(short)((short)iVar4 + 1);
              } while (iVar4 < (int)(uint)*(ushort *)(iVar7 + 0x26));
            }
            if (*(int *)(iVar5 + 400) != 0) {
              *(undefined1 *)(param_1 + 100) = 0;
            }
            param_1[0x40] = 0;
            param_1[0x4c] = 0;
            param_1[0x42] = param_3[1];
            iVar7 = param_3[2];
            param_1[0x41] = 0;
            param_1[0x43] = iVar7;
            param_1[0x44] = *(int *)(iVar5 + 0x58);
            *(short *)(param_1 + 0x4b) = param_2[7];
            if ((param_2[7] != 0x10) && (param_3[3] == 0x10)) {
              param_1[0x41] = 1;
              *(undefined2 *)(param_1 + 0x4b) = 0x10;
              uVar6 = *(uint *)(iVar5 + 0x58);
              if (2 < uVar6) {
                uVar6 = 2;
              }
              param_1[0x44] = uVar6;
              if (uVar6 == *(uint *)(iVar5 + 0x58)) {
                param_1[0x41] = 0;
                *(short *)(param_1 + 0x4b) = param_2[7];
              }
            }
            iVar7 = *param_3;
            param_1[0x37] = 0;
            param_1[0x39] = 0;
            param_1[0x38] = 0;
            param_1[0x3c] = iVar7;
            FUN_0308f4b4(param_1);
            FUN_03090d46(param_1 + 0x21,param_1);
            if (param_6 != (undefined4 *)0x0) {
              param_1[0x21] = param_6[1];
              param_1[0x22] = param_6[2];
            }
            uVar10 = DAT_0308fb04;
            iVar7 = *(int *)(iVar5 + 0xbc);
            if (iVar7 == 3) {
              *DAT_0308fb00 = 3;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x18) = DAT_0308fb0c;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x1c) = DAT_0308fb10;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x20) = DAT_0308fb14;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x24) = uVar10;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x28) = uVar10;
            }
            else if (iVar7 == 1) {
              *DAT_0308fb00 = 1;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x18) = DAT_0308fb18;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x1c) = *DAT_0308fb1c;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x20) = *DAT_0308fb20;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x24) = DAT_0308fb24;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x28) = uVar10;
            }
            else {
              if (iVar7 != 2) {
                return DAT_0308fb08;
              }
              *DAT_0308fb00 = 2;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x18) = *DAT_0308fb28;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x1c) = *DAT_0308fb2c;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x20) = *DAT_0308fb30;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x24) = uVar10;
              *(undefined4 *)(*(int *)(iVar5 + 0xd8) + 0x28) = DAT_0308fb34;
            }
            *(undefined1 *)(iVar5 + 0x48) = 3;
            *(undefined4 *)(iVar5 + 8) = 0xfffffffe;
            if (param_6 != (undefined4 *)0x0) {
              *param_6 = 0;
            }
            iVar7 = DAT_0308fb38;
            *(undefined4 *)(iVar5 + 0x1cc) = 1;
            *(undefined4 *)(iVar5 + 0x180) = 0;
            param_1[0x18] = iVar7;
            wma_memclr(iVar7,(uint)*(ushort *)(iVar5 + 0x26) << 2);
            if (param_1[0x21] == 0) {
              uVar3 = 1;
            }
            else {
              uVar3 = 2;
            }
            *(undefined1 *)(param_1 + 0x72) = uVar3;
            param_1[0x34] = 0;
            param_1[0x73] = 1;
            param_1[0xe] = 0;
            param_1[0x10] = 0;
            param_1[0x11] = -0x80000000;
            param_1[0x12] = 0;
            param_1[0x13] = -0x80000000;
            *(undefined2 *)(param_1 + 0xf) = 0;
            if (param_5 != (undefined1 *)0x0) {
              *param_5 = uVar3;
            }
            if (*(ushort *)(iVar5 + 0x26) == 1) {
              iVar7 = 0x1e;
            }
            else {
              iVar7 = wma_floor_log2(*(ushort *)(iVar5 + 0x26) - 1);
              iVar7 = 0x1d - iVar7;
            }
            *(int *)(iVar5 + 0x1dc) = iVar7;
            iVar7 = 0;
          }
        }
      }
    }
  }
  return iVar7;
}


