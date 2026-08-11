/**
 * FUN_030b3256 @ 0x030b3256
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b3256(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  int iStack_a4;
  int iStack_a0;
  int *piStack_90;
  int *piStack_78;
  byte *pbStack_54;
  uint uStack_4c;
  int iStack_48;
  byte *pbStack_44;
  uint uStack_40;
  int iStack_3c;
  uint uStack_30;
  
  bVar17 = *(int *)(param_2 + 0x8f0) == 1;
  if (bVar17) {
    param_1 = *(int *)(param_1 + 0x28);
  }
  if (bVar17 && param_1 == 1) {
    if ((*(int *)(param_2 + 0xbc4) == 0) && (*(int *)(param_2 + 0xbe8) == 0)) {
      return 0;
    }
    if (*(char *)(param_2 + 0x87d) == '\x02') {
      iStack_3c = *DAT_030b3544 + *(int *)(*DAT_030b3540 + *(int *)(param_2 + 0x878) * 4) * 2;
      iVar1 = 0x80;
    }
    else {
      iStack_3c = *DAT_030b353c + *(int *)(*DAT_030b3538 + *(int *)(param_2 + 0x878) * 4) * 2;
      iVar1 = 0x400;
    }
    piStack_78 = (int *)(param_2 + 0x1048);
    piStack_90 = (int *)(param_2 + 0x2048);
    uStack_40 = 0;
    pbStack_44 = (byte *)(param_2 + 0xbc8);
    iStack_a0 = 0;
    if (*(char *)(param_2 + 0x8ad) != '\0') {
      do {
        iStack_48 = 0;
        iVar2 = param_2 + 0x87c + iStack_a0;
        if (*(char *)(iVar2 + 0x32) != '\0') {
          do {
            iVar3 = *(int *)(param_2 + 0xbc4);
            uStack_4c = uStack_40;
            uVar15 = 0;
            uVar4 = (uint)*(byte *)(param_2 + 0x87f);
            uVar13 = 0;
            piVar5 = (int *)(param_2 + 0x1040);
            iStack_a4 = 0;
            uStack_30 = (uint)(*pbStack_44 >> uStack_40);
            pbStack_54 = pbStack_44 + 1;
            piVar9 = piStack_90;
            piVar8 = piStack_78;
            if (uVar4 != 0) {
              do {
                iVar12 = (int)*(short *)(iStack_3c + iStack_a4 * 2 + 2) -
                         (int)*(short *)(iStack_3c + iStack_a4 * 2);
                if (iVar12 < 0) goto LAB_030b34de;
                uVar6 = (uint)*(byte *)(iStack_a0 * uVar4 + param_2 + 0xb4c + iStack_a4);
                if (uVar6 == 0xe || uVar6 == 0xf) {
                  if ((iVar3 == 1) && ((uStack_30 & 1) != 0)) {
                    uVar6 = uVar6 ^ 1;
                  }
                  uVar7 = -(int)*(short *)(param_2 + uVar4 * iStack_a0 * 2 + 0x9e4 + iStack_a4 * 2);
                  iVar14 = *(int *)(DAT_030b3548 + (uVar6 & 1) * 0x10 + (uVar7 & 3) * 4);
                  uVar6 = ((int)uVar7 >> 2) + 2;
                  if ((int)uVar6 < 1) {
                    do {
                      piVar11 = piVar8 + 1;
                      iVar16 = (int)((ulonglong)((longlong)*piVar8 * (longlong)iVar14) >> 0x20);
                      uVar6 = FUN_030b38f2(iVar16);
                      uVar13 = uVar13 | uVar6;
                      piVar10 = piVar9 + 1;
                      *piVar9 = iVar16;
                      iVar12 = iVar12 + -1;
                      piVar9 = piVar10;
                      piVar8 = piVar11;
                    } while (iVar12 != 0);
                  }
                  else {
                    if (0x1e < (int)uVar6) {
                      uVar6 = 0x1e;
                    }
                    do {
                      piVar11 = piVar8 + 1;
                      uVar7 = (uint)((ulonglong)((longlong)*piVar8 * (longlong)iVar14) >> 0x20);
                      if ((int)uVar7 >> (0x1f - uVar6 & 0xff) != (int)uVar7 >> 0x1f) {
                        uVar7 = (1 << (0x1f - uVar6 & 0xff)) - 1U ^ (int)uVar7 >> 0x1f;
                      }
                      iVar16 = uVar7 << (uVar6 & 0xff);
                      uVar7 = FUN_030b38f2(iVar16);
                      uVar13 = uVar13 | uVar7;
                      piVar10 = piVar9 + 1;
                      *piVar9 = iVar16;
                      iVar12 = iVar12 + -1;
                      piVar9 = piVar10;
                      piVar8 = piVar11;
                    } while (iVar12 != 0);
                  }
                }
                else {
                  if (uVar6 != 0xd) {
                    if (iVar3 == 1) {
                      if ((uStack_30 & 1) != 0) goto LAB_030b3452;
                    }
                    else if (iVar3 == 2) {
LAB_030b3452:
                      do {
                        iVar16 = *piVar8;
                        iVar14 = *piVar9;
                        piVar11 = piVar8 + 1;
                        *piVar8 = iVar16 + iVar14;
                        uVar6 = FUN_030b38f2();
                        uVar15 = uVar6 | uVar15;
                        piVar10 = piVar9 + 1;
                        *piVar9 = iVar16 - iVar14;
                        uVar6 = FUN_030b38f2();
                        uVar13 = uVar13 | uVar6;
                        iVar12 = iVar12 + -1;
                        piVar9 = piVar10;
                        piVar8 = piVar11;
                      } while (iVar12 != 0);
                      goto LAB_030b3488;
                    }
                  }
                  piVar11 = piVar8 + iVar12;
                  piVar10 = piVar9 + iVar12;
                }
LAB_030b3488:
                uStack_30 = uStack_30 >> 1;
                uStack_4c = uStack_4c + 1;
                if (uStack_4c == 8) {
                  uStack_30 = (uint)*pbStack_54;
                  pbStack_54 = pbStack_54 + 1;
                  uStack_4c = 0;
                }
                iStack_a4 = iStack_a4 + 1;
                piVar9 = piVar10;
                piVar8 = piVar11;
              } while (iStack_a4 < (int)uVar4);
            }
            iVar3 = FUN_030b38ce(uVar15);
            if (iVar3 + -1 < *piVar5) {
              *piVar5 = iVar3 + -1;
            }
            iVar3 = FUN_030b38ce(uVar13);
            iVar3 = iVar3 + -1;
            piVar8 = *(int **)(param_2 + 0x1044);
            piVar9 = piVar8;
            if (iVar3 < (int)piVar8) {
              piVar9 = piVar5;
            }
            if (iVar3 < (int)piVar8) {
              piVar9[1] = iVar3;
            }
LAB_030b34de:
            piStack_78 = piStack_78 + iVar1;
            piStack_90 = piStack_90 + iVar1;
            iStack_48 = iStack_48 + 1;
          } while (iStack_48 < (int)(uint)*(byte *)(iVar2 + 0x32));
        }
        uStack_40 = uStack_40 + *(byte *)(param_2 + 0x87f);
        pbStack_44 = pbStack_44 + ((int)uStack_40 >> 3);
        uStack_40 = uStack_40 & 7;
        iStack_a0 = iStack_a0 + 1;
      } while (iStack_a0 < (int)(uint)*(byte *)(param_2 + 0x8ad));
    }
  }
  return 0;
}


