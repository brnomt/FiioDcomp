/**
 * FUN_03085d5e @ 0x03085d5e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03085d5e(int param_1,ushort *param_2,undefined2 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  
  uVar2 = (uint)(((ulonglong)param_4 / (ulonglong)*(uint *)(param_1 + 0x58)) /
                (ulonglong)(uint)*(ushort *)(param_1 + 0x26));
  uVar5 = (uint)*(ushort *)(param_1 + 0x11c) - (uint)*(ushort *)(param_1 + 0x118) & 0xffff;
  if (*param_2 < uVar2) {
    uVar2 = (uint)*param_2;
  }
  if (0x7ffe < (int)uVar2) {
    uVar2 = 0x7fff;
  }
  if ((int)uVar5 < (int)uVar2) {
    uVar2 = uVar5;
  }
  iVar8 = *(int *)(param_1 + 0x9c);
  uVar5 = uVar2 & 0xffff;
  iVar3 = 0;
  if (uVar5 == 0) {
    *param_2 = 0;
  }
  else {
    if (*(ushort *)(param_1 + 0x26) != 0) {
      do {
        *(int *)(*(int *)(param_1 + 0xd8) + iVar3 * 0xfc + 0x48) =
             *(int *)(param_1 + 0xdc) + ((iVar8 * 3) / 2) * iVar3 * 4 + (iVar8 >> 1) * 4 +
             (*(int *)(param_1 + 0x154) >> 1) * -4 + *(int *)(param_1 + 0x118) * 4;
        do {
        } while (*(int *)(param_1 + 0x154) != iVar8);
        iVar3 = (int)(short)((short)iVar3 + 1);
      } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 0x26));
    }
    iVar3 = DAT_03086134;
    piVar9 = *(int **)(*(int *)(param_1 + 0xd8) + 0x144);
    piVar7 = *(int **)(*(int *)(param_1 + 0xd8) + 0x48);
    uVar1 = uVar5;
    if (*(short *)(param_1 + 0x26) == 1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        iVar6 = *piVar7;
        iVar4 = iVar3;
        if ((-0x8001 < iVar6) && (iVar4 = iVar6, 0x7fff < iVar6)) {
          iVar4 = 0x7fff;
        }
        *param_3 = (short)iVar4;
        param_3[1] = (short)iVar4;
        param_3 = param_3 + 2;
        piVar7 = piVar7 + 1;
      }
    }
    else {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        iVar10 = *piVar7;
        iVar6 = *piVar9;
        iVar4 = iVar3;
        if ((-0x8001 < iVar10) && (iVar4 = iVar10, 0x7fff < iVar10)) {
          iVar4 = 0x7fff;
        }
        *param_3 = (short)iVar4;
        iVar4 = iVar3;
        if ((-0x8001 < iVar6) && (iVar4 = iVar6, 0x7fff < iVar6)) {
          iVar4 = 0x7fff;
        }
        param_3[1] = (short)iVar4;
        param_3 = param_3 + 2;
        piVar9 = piVar9 + 1;
        piVar7 = piVar7 + 1;
      }
    }
    *(uint *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + uVar5;
    *param_2 = (ushort)uVar2;
    iVar3 = *(int *)(param_1 + 0x154);
    if (iVar3 <= *(int *)(param_1 + 0x118)) {
      iVar4 = *(int *)(param_1 + 0x118) - iVar3;
      *(int *)(param_1 + 0x118) = iVar4;
      *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) - iVar3;
      if (iVar4 < 0) {
        return DAT_03086138;
      }
      if (iVar3 / 2 <= iVar4) {
        return DAT_03086138;
      }
      iVar4 = 0;
      if (*(short *)(param_1 + 0x26) != 0) {
        do {
          iVar10 = ((iVar8 * 3) / 2) * iVar4 * 4 + (iVar8 >> 1) * 4 + *(int *)(param_1 + 0xdc) +
                   (iVar3 >> 1) * -4;
          iVar6 = *(int *)(param_1 + 0x118);
          wma_memmove(iVar10 + iVar6 * 4,iVar10 + *(int *)(param_1 + 0x154) * 4 + iVar6 * 4,
                      ((iVar3 >> 1) - iVar6) * 4);
          iVar4 = (int)(short)((short)iVar4 + 1);
        } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0x26));
      }
    }
  }
  if (*(char *)(param_1 + 0x48) == '\x03') {
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  return 0;
}


