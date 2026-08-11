/**
 * FUN_030c243e @ 0x030c243e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030c243e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  ushort *puVar9;
  undefined4 uVar10;
  int iVar11;
  byte bVar12;
  ushort uVar13;
  undefined4 uVar14;
  
  if (*(int *)(param_1 + 0x14) == 4) {
    iVar3 = FUN_030c22ec(param_2,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),
                         param_3,param_1,param_4,param_5);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_030ca4a0(*(int *)(param_1 + 8) * 8 + -8);
    iVar3 = FUN_030c22ec(param_2,*(undefined4 *)(param_1 + 4),puVar2,param_3,param_1,param_4,param_5
                        );
    if (iVar3 == 0) {
      puVar4 = (ushort *)
               FUN_030ca490(*(int *)(param_1 + 0x14) *
                            ((*(int *)(param_1 + 0x18) + 1) * *(int *)(param_1 + 8) + -2));
      *(ushort **)(param_1 + 0x10) = puVar4;
      if (*(int *)(param_1 + 0x18) == 1) {
        if (*(int *)(param_1 + 0x14) == 1) {
          if (0 < *(int *)(param_1 + 8) * 2 + -3) {
            *(byte *)puVar4 = (byte)((uint)*puVar2 >> 0x18) & 0x80 | (byte)*puVar2;
            iVar5 = 1;
            uVar14 = puVar2[1];
            puVar1 = puVar2;
            for (iVar3 = *(int *)(param_1 + 8) * 2 + -3 >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
              uVar10 = puVar1[2];
              iVar11 = iVar5 + 1;
              *(byte *)(*(int *)(param_1 + 0x10) + iVar5) =
                   (byte)((uint)uVar14 >> 0x18) & 0x80 | (byte)uVar14;
              uVar14 = puVar1[3];
              iVar5 = iVar5 + 2;
              *(byte *)(*(int *)(param_1 + 0x10) + iVar11) =
                   (byte)((uint)uVar10 >> 0x18) & 0x80 | (byte)uVar10;
              puVar1 = puVar1 + 2;
            }
          }
          iVar3 = *(int *)(param_1 + 8) * 2 + -3;
          if (-1 < iVar3) {
            *(byte *)(*(int *)(param_1 + 0x10) + iVar3) =
                 (byte)puVar2[iVar3] | (byte)((uint)puVar2[iVar3] >> 0x18) & 0x80;
          }
        }
        else if (*(int *)(param_1 + 0x14) == 2) {
          if (0 < *(int *)(param_1 + 8) * 2 + -3) {
            *puVar4 = (ushort)((uint)*puVar2 >> 0x10) & 0x8000 | (ushort)*puVar2;
            iVar5 = 1;
            uVar14 = puVar2[1];
            puVar1 = puVar2;
            for (iVar3 = *(int *)(param_1 + 8) * 2 + -3 >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
              uVar10 = puVar1[2];
              iVar11 = iVar5 * 2;
              *(ushort *)(*(int *)(param_1 + 0x10) + iVar5 * 2) =
                   (ushort)((uint)uVar14 >> 0x10) & 0x8000 | (ushort)uVar14;
              uVar14 = puVar1[3];
              iVar5 = iVar5 + 2;
              *(ushort *)(*(int *)(param_1 + 0x10) + iVar11 + 2) =
                   (ushort)((uint)uVar10 >> 0x10) & 0x8000 | (ushort)uVar10;
              puVar1 = puVar1 + 2;
            }
          }
          iVar3 = *(int *)(param_1 + 8) * 2 + -3;
          if (-1 < iVar3) {
            *(ushort *)(*(int *)(param_1 + 0x10) + iVar3 * 2) =
                 (ushort)puVar2[iVar3] | (ushort)((uint)puVar2[iVar3] >> 0x10) & 0x8000;
          }
        }
      }
      else {
        iVar3 = *(int *)(param_1 + 8) * 3 + -2;
        uVar6 = *(int *)(param_1 + 8) * 2 - 4;
        if (*(int *)(param_1 + 0x14) == 1) {
          if (-1 < (int)uVar6) {
            do {
              uVar7 = puVar2[uVar6];
              if ((uVar7 & 0x80000000) == 0) {
                if ((puVar2[uVar6 + 1] & 0x80000000) != 0) {
                  *(byte *)((int)puVar4 + iVar3 + -3) = *(byte *)(puVar2 + uVar7 * 2);
                  pbVar8 = (byte *)((int)puVar4 + iVar3 + -3);
                  pbVar8[1] = (byte)(((uint)*(ushort *)(puVar2 + uVar6 + 1) << 0x11) >> 0x19) | 0x80
                  ;
                  bVar12 = *(byte *)(puVar2 + uVar6 + 1);
                  goto LAB_030c26e4;
                }
                iVar5 = iVar3 + -2;
                *(byte *)((int)puVar4 + iVar5) = *(byte *)(puVar2 + uVar7 * 2);
                *(byte *)((int)puVar4 + iVar3 + -1) = *(byte *)(puVar2 + puVar2[uVar6 + 1] * 2);
              }
              else if ((puVar2[uVar6 + 1] & 0x80000000) == 0) {
                *(byte *)((int)puVar4 + iVar3 + -3) = (byte)((uVar7 << 0x11) >> 0x19) | 0x80;
                pbVar8 = (byte *)((int)puVar4 + iVar3 + -3);
                pbVar8[1] = *(byte *)(puVar2 + puVar2[uVar6 + 1] * 2);
                bVar12 = *(byte *)(puVar2 + uVar6);
LAB_030c26e4:
                iVar5 = iVar3 + -3;
                pbVar8[2] = bVar12;
              }
              else {
                iVar5 = iVar3 + -4;
                *(byte *)((int)puVar4 + iVar5) = (byte)((uVar7 << 0x11) >> 0x19) | 0x80;
                *(byte *)((int)puVar4 + iVar3 + -3) =
                     (byte)(((uint)*(ushort *)(puVar2 + uVar6 + 1) << 0x11) >> 0x19) | 0x80;
                *(byte *)((int)puVar4 + iVar3 + -2) = *(byte *)(puVar2 + uVar6);
                *(byte *)((int)puVar4 + iVar3 + -1) = *(byte *)(puVar2 + uVar6 + 1);
              }
              puVar2[uVar6] = iVar5;
              uVar6 = uVar6 - 2;
              iVar3 = iVar5;
            } while (uVar6 < 0x80000000);
          }
        }
        else if (-1 < (int)uVar6) {
          do {
            uVar7 = puVar2[uVar6];
            if ((uVar7 & 0x80000000) == 0) {
              if ((puVar2[uVar6 + 1] & 0x80000000) != 0) {
                puVar4[iVar3 + -3] = *(ushort *)(puVar2 + uVar7 * 2);
                puVar9 = puVar4 + iVar3 + -3;
                puVar9[1] = (ushort)((uint)(puVar2[uVar6 + 1] << 1) >> 0x11) | 0x8000;
                uVar13 = *(ushort *)(puVar2 + uVar6 + 1);
                goto LAB_030c2756;
              }
              iVar5 = iVar3 + -2;
              puVar4[iVar5] = *(ushort *)(puVar2 + uVar7 * 2);
              puVar4[iVar3 + -1] = *(ushort *)(puVar2 + puVar2[uVar6 + 1] * 2);
            }
            else if ((puVar2[uVar6 + 1] & 0x80000000) == 0) {
              puVar4[iVar3 + -3] = (ushort)((uVar7 << 1) >> 0x11) | 0x8000;
              puVar9 = puVar4 + iVar3 + -3;
              puVar9[1] = *(ushort *)(puVar2 + puVar2[uVar6 + 1] * 2);
              uVar13 = *(ushort *)(puVar2 + uVar6);
LAB_030c2756:
              iVar5 = iVar3 + -3;
              puVar9[2] = uVar13;
            }
            else {
              iVar5 = iVar3 + -4;
              puVar4[iVar5] = (ushort)((uVar7 << 1) >> 0x11) | 0x8000;
              puVar4[iVar3 + -3] = (ushort)((uint)(puVar2[uVar6 + 1] << 1) >> 0x11) | 0x8000;
              puVar4[iVar3 + -2] = *(ushort *)(puVar2 + uVar6);
              puVar4[iVar3 + -1] = *(ushort *)(puVar2 + uVar6 + 1);
            }
            puVar2[uVar6] = iVar5;
            uVar6 = uVar6 - 2;
            iVar3 = iVar5;
          } while (uVar6 < 0x80000000);
        }
      }
      FUN_030ca488();
      return 0;
    }
  }
  return 1;
}


