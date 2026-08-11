/**
 * FUN_030a044c @ 0x030a044c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_030a044c(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iStack_a0;
  uint auStack_98 [2];
  short *psStack_90;
  uint *puStack_88;
  int iStack_7c;
  int iStack_78;
  uint auStack_70 [7];
  uint *puStack_54;
  int iStack_4c;
  int iStack_48;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint *puStack_28;
  
  puVar10 = *(uint **)(param_1 + 0x91c);
  iStack_2c = param_3;
  puStack_28 = param_4;
  iStack_30 = param_2;
  iStack_34 = param_1;
  if (puVar10 == (uint *)0x0) {
    return 0;
  }
  do {
    if (iStack_2c < 1) break;
    iStack_78 = 0;
    iStack_a0 = 0;
    iStack_7c = iStack_2c;
    auStack_70[3] = iStack_2c;
    iStack_4c = iStack_30;
    if (0 < iStack_2c) {
      do {
        iVar11 = (puVar10[2] - puVar10[6]) * *puVar10;
        if (iStack_7c - iStack_a0 < iVar11) {
          iVar11 = iStack_7c - iStack_a0;
        }
        FUN_0309f692(puVar10[7] + puVar10[6] * *puVar10 * 2,iStack_4c + iStack_78 * 2,iVar11 << 1);
        iStack_a0 = iStack_a0 + iVar11;
        uVar3 = *puVar10;
        uVar5 = iVar11 / (int)uVar3 + puVar10[6];
        puVar10[6] = uVar5;
        iStack_78 = iStack_a0;
        if ((int)puVar10[2] <= (int)uVar5) {
          psStack_90 = (short *)puVar10[7];
          puStack_54 = auStack_70;
          puStack_88 = auStack_98;
          uVar5 = 0;
          if (uVar3 != 0) {
            iStack_48 = uVar3 * 3;
            do {
              uVar6 = 0;
              iVar11 = (int)psStack_90[uVar3 * 2];
              uVar9 = 0;
              uVar4 = 0;
              do {
                iVar13 = *(int *)(DAT_030a0818 + uVar4 * 4);
                iVar12 = *(int *)(DAT_030a081c + uVar4 * 4);
                iVar7 = iVar11 - (*psStack_90 * iVar12 + psStack_90[uVar3] * iVar13 >> 8);
                if (iVar7 < 0) {
                  iVar7 = -iVar7;
                }
                iVar14 = (int)psStack_90[uVar3 * 3] -
                         (psStack_90[uVar3] * iVar12 + iVar11 * iVar13 >> 8);
                if (iVar14 < 0) {
                  iVar14 = -iVar14;
                }
                iVar12 = (int)psStack_90[uVar3 * 4] -
                         (iVar11 * iVar12 + psStack_90[uVar3 * 3] * iVar13 >> 8);
                if (iVar12 < 0) {
                  iVar12 = -iVar12;
                }
                uVar8 = (uint)((ulonglong)DAT_030a0820 * (ulonglong)(uint)(iVar12 + iVar14 + iVar7)
                              >> 0x23);
                if ((uVar4 == 0) || (uVar8 < uVar6)) {
                  uVar6 = uVar8;
                  uVar9 = uVar4;
                }
                if (uVar8 == 0) {
                  uVar6 = 0x10;
                  goto LAB_030a0582;
                }
                uVar4 = uVar4 + 1;
              } while (uVar4 < 7);
              uVar4 = uVar9;
              if (uVar6 < 0x10) {
                uVar6 = 0x10;
              }
LAB_030a0582:
              auStack_70[uVar5] = uVar4;
              auStack_98[uVar5] = uVar6;
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar3);
          }
          uVar3 = *puVar10;
          *(char *)puVar10[8] = (char)auStack_70[0];
          uVar2 = (undefined1)(auStack_98[0] >> 8);
          if (uVar3 == 1) {
            uVar3 = 0;
            *(char *)(puVar10[8] + 1) = (char)auStack_98[0];
            iVar7 = 7;
            *(undefined1 *)(puVar10[8] + 2) = uVar2;
            *(undefined1 *)(puVar10[8] + 3) = *(undefined1 *)(puVar10[7] + 2);
            *(char *)(puVar10[8] + 4) = (char)((ushort)*(undefined2 *)(puVar10[7] + 2) >> 8);
            *(undefined1 *)(puVar10[8] + 5) = *(undefined1 *)puVar10[7];
            *(char *)(puVar10[8] + 6) = (char)((ushort)*(undefined2 *)puVar10[7] >> 8);
            iVar11 = DAT_030a0818;
            uVar5 = puVar10[2];
            uVar6 = 2;
            if (2 < (int)uVar5) {
              iVar12 = DAT_030a0818 + 0x1c;
              iVar13 = DAT_030a0818 + -0x40;
              do {
                uVar5 = puVar10[7];
                iVar14 = (int)*(short *)(uVar5 + uVar6 * 2 + -4) *
                         *(int *)(iVar12 + auStack_70[0] * 4) +
                         (int)*(short *)(uVar5 + uVar6 * 2 + -2) *
                         *(int *)(iVar11 + auStack_70[0] * 4) >> 8;
                uVar5 = (*(short *)(uVar5 + uVar6 * 2) - iVar14) / (int)auStack_98[0];
                if ((int)uVar5 < -8) {
                  uVar5 = 0xfffffff8;
                }
                else if (7 < (int)uVar5) {
                  uVar5 = 7;
                }
                iVar14 = auStack_98[0] * uVar5 + iVar14;
                if (iVar14 < 0x8000) {
                  if (iVar14 < -0x8000) {
                    iVar14 = -0x8000;
                  }
                }
                else {
                  iVar14 = 0x7fff;
                }
                if ((int)uVar5 < 0) {
                  uVar5 = uVar5 + 0x10;
                }
                iVar1 = uVar3 << 4;
                uVar3 = uVar5 & 0xf;
                if ((uVar6 & 1) != 0) {
                  *(byte *)(puVar10[8] + iVar7) = (byte)uVar3 | (byte)iVar1;
                  iVar7 = iVar7 + 1;
                  uVar3 = 0;
                }
                auStack_98[0] = (int)(auStack_98[0] * *(int *)(iVar13 + uVar5 * 4)) >> 8;
                if ((int)auStack_98[0] < 0x11) {
                  auStack_98[0] = 0x10;
                }
                *(short *)(puVar10[7] + uVar6 * 2) = (short)iVar14;
                uVar5 = puVar10[2];
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < (int)uVar5);
            }
          }
          else {
            iVar7 = 0xe;
            *(char *)(puVar10[8] + 1) = (char)auStack_70[1];
            uVar3 = 0;
            *(char *)(puVar10[8] + 2) = (char)auStack_98[0];
            *(undefined1 *)(puVar10[8] + 3) = uVar2;
            *(char *)(puVar10[8] + 4) = (char)auStack_98[1];
            *(char *)(puVar10[8] + 5) = (char)(auStack_98[1] >> 8);
            *(undefined1 *)(puVar10[8] + 6) = *(undefined1 *)(puVar10[7] + 4);
            *(char *)(puVar10[8] + 7) = (char)((ushort)*(undefined2 *)(puVar10[7] + 4) >> 8);
            *(undefined1 *)(puVar10[8] + 8) = *(undefined1 *)(puVar10[7] + 6);
            *(char *)(puVar10[8] + 9) = (char)((ushort)*(undefined2 *)(puVar10[7] + 6) >> 8);
            *(undefined1 *)(puVar10[8] + 10) = *(undefined1 *)puVar10[7];
            *(char *)(puVar10[8] + 0xb) = (char)((ushort)*(undefined2 *)puVar10[7] >> 8);
            *(undefined1 *)(puVar10[8] + 0xc) = *(undefined1 *)(puVar10[7] + 2);
            *(char *)(puVar10[8] + 0xd) = (char)((ushort)*(undefined2 *)(puVar10[7] + 2) >> 8);
            iVar11 = DAT_030a0818;
            uVar5 = puVar10[2];
            uVar6 = 4;
            if (4 < (int)(uVar5 * 2)) {
              iVar12 = DAT_030a0818 + 0x1c;
              do {
                uVar5 = puVar10[7];
                uVar4 = uVar6 & 1;
                iVar13 = (int)*(short *)(uVar5 + uVar6 * 2 + -8) *
                         *(int *)(iVar12 + auStack_70[uVar4] * 4) +
                         (int)*(short *)(uVar5 + uVar6 * 2 + -4) *
                         *(int *)(iVar11 + auStack_70[uVar4] * 4) >> 8;
                uVar5 = (*(short *)(uVar5 + uVar6 * 2) - iVar13) / (int)auStack_98[uVar4];
                if ((int)uVar5 < -8) {
                  uVar5 = 0xfffffff8;
                }
                else if (7 < (int)uVar5) {
                  uVar5 = 7;
                }
                iVar13 = auStack_98[uVar4] * uVar5 + iVar13;
                if (iVar13 < 0x8000) {
                  if (iVar13 < -0x8000) {
                    iVar13 = DAT_030a0824;
                  }
                }
                else {
                  iVar13 = 0x7fff;
                }
                if ((int)uVar5 < 0) {
                  uVar5 = uVar5 + 0x10;
                }
                iVar14 = uVar3 << 4;
                uVar3 = uVar5 & 0xf;
                if (uVar4 != 0) {
                  *(byte *)(puVar10[8] + iVar7) = (byte)uVar3 | (byte)iVar14;
                  iVar7 = iVar7 + 1;
                  uVar3 = 0;
                }
                uVar5 = (int)(auStack_98[uVar4] * *(int *)(DAT_030a0828 + uVar5 * 4)) >> 8;
                auStack_98[uVar4] = uVar5;
                if ((int)uVar5 < 0x11) {
                  uVar5 = 0x10;
                }
                auStack_98[uVar4] = uVar5;
                *(short *)(puVar10[7] + uVar6 * 2) = (short)iVar13;
                uVar5 = puVar10[2];
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < (int)(uVar5 * 2));
            }
          }
          FUN_0309f6c4(puVar10[7],uVar5 << 1);
          puVar10[5] = puVar10[5] + 1;
          puVar10[6] = 0;
        }
      } while (iStack_a0 < iStack_7c);
    }
    iStack_2c = iStack_2c - iStack_78;
  } while (iStack_78 == auStack_70[3]);
  *puStack_28 = puVar10[8];
  return puVar10[1];
}


