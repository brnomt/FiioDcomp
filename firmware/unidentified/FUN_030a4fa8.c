/**
 * FUN_030a4fa8 @ 0x030a4fa8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a4fa8(undefined4 param_1,int *param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  short asStack_30 [6];
  
  iVar3 = param_2[5];
  param_2[5] = iVar3 + 1;
  param_2[6] = 0;
  if (param_2[3] < iVar3 + 1) {
    FUN_0309f6c4(param_2[7],param_2[2] * *param_2);
    return 1;
  }
  iVar3 = (*(code *)*DAT_030a534c)(param_2[8],param_2[1],*DAT_030a5348);
  if (iVar3 == param_2[1]) {
    pbVar4 = (byte *)param_2[8];
    asStack_30[2] = (ushort)*pbVar4;
    if (*param_2 == 1) {
      asStack_30[0] = *(short *)(pbVar4 + 1);
      asStack_30[1] = 0;
      *(undefined2 *)(param_2[7] + 2) = *(undefined2 *)(pbVar4 + 3);
      *(undefined2 *)param_2[7] = *(undefined2 *)(param_2[8] + 5);
      iVar3 = 7;
    }
    else {
      asStack_30[3] = (ushort)pbVar4[1];
      asStack_30[0] = *(short *)(pbVar4 + 2);
      asStack_30[1] = *(undefined2 *)(pbVar4 + 4);
      *(undefined2 *)(param_2[7] + 4) = *(undefined2 *)(pbVar4 + 6);
      *(undefined2 *)(param_2[7] + 6) = *(undefined2 *)(param_2[8] + 8);
      *(undefined2 *)param_2[7] = *(undefined2 *)(param_2[8] + 10);
      *(undefined2 *)(param_2[7] + 2) = *(undefined2 *)(param_2[8] + 0xc);
      iVar3 = 0xe;
    }
    iVar5 = *param_2 << 1;
    if (iVar3 < param_2[1]) {
      do {
        bVar1 = *(byte *)(param_2[8] + iVar3);
        iVar3 = iVar3 + 1;
        *(ushort *)(param_2[7] + iVar5 * 2) = (ushort)(bVar1 >> 4);
        *(ushort *)(param_2[7] + (iVar5 + 1) * 2) = bVar1 & 0xf;
        iVar5 = iVar5 + 2;
      } while (iVar3 < param_2[1]);
    }
    iVar3 = DAT_030a5350;
    iVar6 = *param_2;
    iVar5 = iVar6 * 2;
    if (param_2[2] * iVar6 + iVar6 * -2 != 0 && iVar5 <= param_2[2] * iVar6) {
      iVar6 = DAT_030a5350 + 0x40;
      iVar12 = DAT_030a5350 + 0x5c;
      do {
        iVar10 = *param_2;
        if (iVar10 < 2) {
          iVar8 = 0;
        }
        else {
          iVar8 = iVar5 % 2;
        }
        iVar9 = param_2[7];
        sVar2 = asStack_30[iVar8];
        bVar1 = *(byte *)(iVar9 + iVar5 * 2);
        uVar7 = bVar1 & 0xf;
        iVar11 = *(int *)(iVar3 + uVar7 * 4) * (int)sVar2;
        asStack_30[iVar8] = (short)((uint)iVar11 >> 8);
        if (iVar11 * 0x100 >> 0x10 < 0x10) {
          asStack_30[iVar8] = 0x10;
        }
        if ((bVar1 & 8) != 0) {
          uVar7 = (uint)(short)((short)uVar7 + -0x10);
        }
        iVar10 = uVar7 * (int)sVar2 +
                 ((int)*(short *)(iVar9 + (iVar5 + iVar10 * -2) * 2) *
                  *(int *)(iVar12 + asStack_30[iVar8 + 2] * 4) +
                  (int)*(short *)(iVar9 + (iVar5 - iVar10) * 2) *
                  *(int *)(iVar6 + asStack_30[iVar8 + 2] * 4) >> 8);
        if (iVar10 < 0x8000) {
          if (iVar10 < -0x8000) {
            iVar10 = DAT_030a5354;
          }
        }
        else {
          iVar10 = 0x7fff;
        }
        *(short *)(iVar9 + iVar5 * 2) = (short)iVar10;
        iVar5 = iVar5 + 1;
      } while (*param_2 * param_2[2] - iVar5 != 0 && iVar5 <= *param_2 * param_2[2]);
    }
    return 1;
  }
  return 0;
}


