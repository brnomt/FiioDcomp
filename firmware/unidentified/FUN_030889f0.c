/**
 * FUN_030889f0 @ 0x030889f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030889f0(int *param_1,int *param_2,int param_3,undefined1 *param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int *piVar12;
  int *piVar13;
  
  uVar3 = 0;
  if (0 < (short)param_2[4]) {
    iVar9 = 8 - (short)param_2[4];
    if (param_3 < iVar9) {
      iVar9 = param_3;
    }
    uVar3 = (uint)(short)iVar9;
    if (0 < (int)uVar3) {
      iVar4 = 0;
      uVar2 = uVar3 & 7;
      iVar5 = 0;
      puVar10 = param_4;
      puVar11 = param_4;
      if (uVar2 != 0) {
        do {
          iVar8 = iVar4 + 8;
          puVar11 = puVar10 + 1;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 1;
          *(undefined1 *)((int)param_2 + iVar8 + (short)param_2[4]) = *puVar10;
          puVar10 = puVar11;
        } while (iVar5 < (int)uVar2);
      }
      for (; (int)uVar2 < (int)uVar3; uVar2 = uVar2 + 8) {
        *(undefined1 *)((int)param_2 + iVar4 + 8 + (int)(short)param_2[4]) = *puVar11;
        *(undefined1 *)((int)param_2 + iVar4 + 9 + (int)(short)param_2[4]) = puVar11[1];
        *(undefined1 *)((int)param_2 + iVar4 + 10 + (int)(short)param_2[4]) = puVar11[2];
        *(undefined1 *)((int)param_2 + iVar4 + 0xb + (int)(short)param_2[4]) = puVar11[3];
        *(undefined1 *)((int)param_2 + iVar4 + 0xc + (int)(short)param_2[4]) = puVar11[4];
        *(undefined1 *)((int)param_2 + iVar4 + 0xd + (int)(short)param_2[4]) = puVar11[5];
        *(undefined1 *)((int)param_2 + iVar4 + 0xe + (int)(short)param_2[4]) = puVar11[6];
        iVar5 = iVar4 + 0xf;
        iVar4 = iVar4 + 8;
        *(undefined1 *)((int)param_2 + iVar5 + (short)param_2[4]) = puVar11[7];
        puVar11 = puVar11 + 8;
      }
    }
    sVar1 = (short)param_2[4] + (short)iVar9;
    *(short *)(param_2 + 4) = sVar1;
    if (sVar1 == 8) {
      iVar9 = param_2[1];
      param_2[1] = param_2[2] + iVar9;
      uVar2 = *param_1 * (param_2[2] + iVar9);
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = param_1[1] * uVar2;
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = param_1[2] * uVar2;
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = param_1[3] * uVar2;
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      iVar9 = param_1[4] * uVar2;
      param_2[1] = iVar9;
      iVar9 = iVar9 + param_1[5];
      param_2[1] = iVar9;
      iVar4 = *param_2;
      *param_2 = iVar4 + iVar9;
      param_2[1] = param_2[3] + iVar9;
      uVar2 = (param_2[3] + iVar9) * param_1[6];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[7];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[8];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[9];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      iVar5 = uVar2 * param_1[10];
      param_2[1] = iVar5;
      iVar5 = iVar5 + param_1[0xb];
      param_2[1] = iVar5;
      *param_2 = iVar5 + iVar4 + iVar9;
      *(undefined2 *)(param_2 + 4) = 0;
    }
  }
  iVar5 = (param_3 - uVar3) + ((uint)((int)(param_3 - uVar3) >> 0x1f) >> 0x1d);
  iVar9 = 1;
  iVar4 = (iVar5 * 0x2000 >> 0x10) + 1;
  piVar12 = (int *)(param_4 + uVar3);
  if (1 < iVar4) {
    do {
      piVar13 = piVar12 + 1;
      iVar8 = *piVar12;
      iVar6 = param_2[1];
      iVar9 = iVar9 + 1;
      param_2[1] = iVar8 + iVar6;
      uVar2 = (iVar8 + iVar6) * *param_1;
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[1];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[2];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[3];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      iVar8 = uVar2 * param_1[4];
      param_2[1] = iVar8;
      iVar8 = iVar8 + param_1[5];
      param_2[1] = iVar8;
      iVar7 = *param_2;
      *param_2 = iVar7 + iVar8;
      piVar12 = piVar12 + 2;
      iVar6 = *piVar13;
      param_2[1] = iVar8 + iVar6;
      uVar2 = (iVar8 + iVar6) * param_1[6];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[7];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[8];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      uVar2 = uVar2 * param_1[9];
      uVar2 = uVar2 >> 0x10 | uVar2 * 0x10000;
      param_2[1] = uVar2;
      iVar6 = uVar2 * param_1[10];
      param_2[1] = iVar6;
      iVar6 = iVar6 + param_1[0xb];
      param_2[1] = iVar6;
      *param_2 = iVar6 + iVar7 + iVar8;
    } while (iVar9 < iVar4);
  }
  iVar9 = (int)(short)(((ushort)iVar5 & 0xfff8) + (short)uVar3);
  if (iVar9 < param_3) {
    uVar3 = param_3 - iVar9;
    if (0 < (int)uVar3) {
      param_4 = param_4 + iVar9;
      iVar4 = 0;
      if (iVar9 < param_3) {
        uVar2 = uVar3 & 7;
        iVar5 = 0;
        puVar11 = param_4;
        iVar9 = iVar4;
        if (uVar2 != 0) {
          do {
            param_4 = puVar11 + 1;
            iVar4 = iVar9 + 1;
            iVar5 = iVar5 + 1;
            *(undefined1 *)((int)param_2 + iVar9 + 8) = *puVar11;
            puVar11 = param_4;
            iVar9 = iVar4;
          } while (iVar5 < (int)uVar2);
        }
      }
      else {
        uVar2 = 0;
      }
      for (; (int)uVar2 < (int)uVar3; uVar2 = uVar2 + 8) {
        *(undefined1 *)((int)param_2 + iVar4 + 8) = *param_4;
        *(undefined1 *)((int)param_2 + iVar4 + 9) = param_4[1];
        *(undefined1 *)((int)param_2 + iVar4 + 10) = param_4[2];
        *(undefined1 *)((int)param_2 + iVar4 + 0xb) = param_4[3];
        *(undefined1 *)((int)param_2 + iVar4 + 0xc) = param_4[4];
        *(undefined1 *)((int)param_2 + iVar4 + 0xd) = param_4[5];
        puVar11 = param_4 + 7;
        *(undefined1 *)((int)param_2 + iVar4 + 0xe) = param_4[6];
        param_4 = param_4 + 8;
        *(undefined1 *)((int)param_2 + iVar4 + 0xf) = *puVar11;
        iVar4 = iVar4 + 8;
      }
    }
    *(short *)(param_2 + 4) = (short)uVar3;
    return;
  }
  return;
}


