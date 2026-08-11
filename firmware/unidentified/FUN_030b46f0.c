/**
 * FUN_030b46f0 @ 0x030b46f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030b46f0(int param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int *piVar29;
  int iVar30;
  int iVar31;
  int iStack_30;
  int iStack_2c;
  int *local_28;
  
  uVar14 = *(uint *)(DAT_030b4ae8[1] + param_1 * 4);
  iVar5 = *(int *)(*DAT_030b4ae8 + param_1 * 4);
  pbVar3 = (byte *)(*(int *)(*DAT_030b4aec + param_1 * 4) + *DAT_030b4af0);
  iVar6 = 1 << (uVar14 & 0xff);
  pbVar4 = pbVar3 + 1;
  bVar1 = *pbVar3;
  while( true ) {
    uVar2 = (uint)bVar1;
    uVar12 = 0;
    if (uVar2 == 0) break;
    pbVar3 = pbVar4 + 1;
    bVar1 = *pbVar4;
    piVar29 = param_2 + uVar2 * 4;
    piVar10 = param_2 + (uint)bVar1 * 4;
    iVar17 = *piVar29;
    iVar21 = piVar29[1];
    *piVar29 = *piVar10;
    piVar29[1] = piVar10[1];
    *piVar10 = iVar17;
    piVar10[1] = iVar21;
    piVar7 = param_2 + iVar6 + (uint)bVar1 * 4;
    iVar17 = piVar29[2];
    iVar21 = piVar29[3];
    piVar29[2] = *piVar7;
    piVar29[3] = piVar7[1];
    *piVar7 = iVar17;
    piVar7[1] = iVar21;
    piVar29 = param_2 + iVar6 + uVar2 * 4;
    iVar17 = *piVar29;
    iVar21 = piVar29[1];
    *piVar29 = piVar10[2];
    piVar29[1] = piVar10[3];
    piVar10[2] = iVar17;
    piVar10[3] = iVar21;
    iVar17 = piVar29[2];
    iVar21 = piVar29[3];
    piVar29[2] = piVar7[2];
    piVar29[3] = piVar7[3];
    piVar7[2] = iVar17;
    piVar7[3] = iVar21;
    pbVar4 = pbVar4 + 2;
    bVar1 = *pbVar3;
  }
  do {
    piVar7 = param_2 + iVar6 + uVar12 * 4;
    iVar17 = param_2[uVar12 * 4 + 2];
    iVar21 = param_2[uVar12 * 4 + 3];
    param_2[uVar12 * 4 + 2] = *piVar7;
    param_2[uVar12 * 4 + 3] = piVar7[1];
    *piVar7 = iVar17;
    piVar7[1] = iVar21;
    uVar12 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (uVar12 != 0);
  if ((uVar14 & 1) == 0) {
    piVar7 = param_2;
    for (iVar6 = iVar5 >> 2; 0 < iVar6; iVar6 = iVar6 + -1) {
      iVar13 = *piVar7 + piVar7[2];
      iVar25 = *piVar7 - piVar7[2];
      iVar24 = piVar7[1] + piVar7[3];
      iVar11 = piVar7[1] - piVar7[3];
      iVar21 = piVar7[4] + piVar7[6];
      iVar8 = piVar7[4] - piVar7[6];
      iVar17 = piVar7[5] + piVar7[7];
      iVar19 = piVar7[5] - piVar7[7];
      *piVar7 = iVar13 + iVar21;
      piVar7[4] = iVar13 - iVar21;
      piVar7[5] = iVar24 - iVar17;
      piVar7[1] = iVar24 + iVar17;
      piVar7[2] = iVar25 + iVar19;
      piVar7[6] = iVar25 - iVar19;
      piVar7[3] = iVar11 - iVar8;
      piVar7[7] = iVar11 + iVar8;
      piVar7 = piVar7 + 8;
    }
    iVar5 = iVar5 >> 4;
    local_28 = (int *)*DAT_030b4afc;
    iStack_2c = 4;
    piVar7 = param_2;
    iStack_30 = iVar5;
    if (iVar5 == 0) {
      return;
    }
    do {
      for (; iVar6 = iStack_2c, piVar10 = local_28, iVar5 != 0; iVar5 = iVar5 + -1) {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          piVar29 = piVar7 + iStack_2c * 2;
          iVar17 = (int)((ulonglong)((longlong)piVar10[1] * (longlong)(*piVar29 + piVar29[1])) >>
                        0x20);
          piVar9 = piVar29 + iStack_2c * 2;
          iVar25 = (int)((ulonglong)((longlong)(*piVar10 + piVar10[1] * 2) * (longlong)*piVar29) >>
                        0x20) - iVar17;
          iVar17 = iVar17 + (int)((ulonglong)((longlong)*piVar10 * (longlong)piVar29[1]) >> 0x20);
          iVar21 = (int)((ulonglong)((longlong)piVar10[3] * (longlong)(*piVar9 + piVar9[1])) >> 0x20
                        );
          iVar24 = (int)((ulonglong)((longlong)(piVar10[2] + piVar10[3] * 2) * (longlong)*piVar9) >>
                        0x20) - iVar21;
          piVar29 = piVar9 + iStack_2c * 2;
          iVar21 = (int)((ulonglong)((longlong)piVar10[2] * (longlong)piVar9[1]) >> 0x20) + iVar21;
          iVar19 = (int)((ulonglong)((longlong)piVar10[5] * (longlong)(*piVar29 + piVar29[1])) >>
                        0x20);
          iVar11 = (int)((ulonglong)((longlong)(piVar10[4] + piVar10[5] * 2) * (longlong)*piVar29)
                        >> 0x20) - iVar19;
          iVar19 = iVar19 + (int)((ulonglong)((longlong)piVar10[4] * (longlong)piVar29[1]) >> 0x20);
          iVar15 = (*piVar7 >> 2) - iVar25;
          iVar16 = (piVar7[1] >> 2) - iVar17;
          iVar25 = iVar25 + (*piVar7 >> 2);
          iVar17 = iVar17 + (piVar7[1] >> 2);
          iVar13 = iVar24 + iVar11;
          iVar8 = iVar19 - iVar21;
          iVar24 = iVar24 - iVar11;
          *piVar29 = iVar15 + iVar8;
          piVar29[1] = iVar16 + iVar24;
          piVar29 = piVar29 + iStack_2c * -2;
          iVar21 = iVar21 + iVar19;
          *piVar29 = iVar25 - iVar13;
          piVar29[1] = iVar17 - iVar21;
          piVar29 = piVar29 + iStack_2c * -2;
          *piVar29 = iVar15 - iVar8;
          piVar29[1] = iVar16 - iVar24;
          piVar29 = piVar29 + iStack_2c * -2;
          *piVar29 = iVar25 + iVar13;
          piVar29[1] = iVar17 + iVar21;
          piVar7 = piVar29 + 2;
          piVar10 = piVar10 + 6;
        }
        piVar7 = piVar7 + iStack_2c * 6;
      }
      local_28 = local_28 + iStack_2c * 6;
      iStack_2c = iStack_2c << 2;
      iVar5 = iStack_30 >> 2;
      piVar7 = param_2;
      iStack_30 = iVar5;
    } while (iVar5 != 0);
    return;
  }
  piVar7 = param_2;
  for (iVar6 = iVar5 >> 3; iVar6 != 0; iVar6 = iVar6 + -1) {
    iVar30 = *piVar7 + piVar7[2];
    iVar11 = *piVar7 - piVar7[2];
    iVar15 = piVar7[1] + piVar7[3];
    iVar8 = piVar7[1] - piVar7[3];
    iVar13 = piVar7[4] + piVar7[6];
    iVar18 = piVar7[4] - piVar7[6];
    iVar26 = piVar7[5] + piVar7[7];
    iVar22 = piVar7[5] - piVar7[7];
    iVar21 = piVar7[8] + piVar7[10];
    iVar19 = piVar7[8] - piVar7[10];
    iVar20 = piVar7[9] + piVar7[0xb];
    iVar23 = piVar7[9] - piVar7[0xb];
    iVar24 = piVar7[0xc] + piVar7[0xe];
    iVar27 = piVar7[0xc] - piVar7[0xe];
    iVar28 = piVar7[0xd] + piVar7[0xf];
    iVar31 = piVar7[0xd] - piVar7[0xf];
    iVar17 = iVar21 - iVar24 >> 1;
    iVar21 = iVar21 + iVar24 >> 1;
    iVar24 = iVar30 + iVar13 >> 1;
    iVar16 = iVar20 + iVar28 >> 1;
    piVar7[8] = iVar24 - iVar21;
    iVar25 = iVar15 + iVar26 >> 1;
    iVar20 = iVar20 - iVar28 >> 1;
    piVar7[9] = iVar25 - iVar16;
    iVar13 = iVar30 - iVar13 >> 1;
    piVar7[4] = iVar20 + iVar13;
    piVar7[0xc] = iVar13 - iVar20;
    *piVar7 = iVar21 + iVar24;
    piVar7[1] = iVar16 + iVar25;
    iVar21 = iVar15 - iVar26 >> 1;
    piVar7[5] = iVar21 - iVar17;
    piVar7[0xd] = iVar17 + iVar21;
    iVar17 = iVar19 - iVar31;
    iVar19 = iVar19 + iVar31;
    iVar21 = iVar23 + iVar27;
    iVar23 = iVar23 - iVar27;
    iVar24 = (int)((ulonglong)((longlong)DAT_030b4af4 * (longlong)(iVar17 - iVar21)) >> 0x20);
    iVar25 = (int)((ulonglong)((longlong)DAT_030b4af4 * (longlong)(iVar17 + iVar21)) >> 0x20);
    iVar21 = (int)((ulonglong)((longlong)DAT_030b4af4 * (longlong)(iVar19 - iVar23)) >> 0x20);
    iVar13 = (int)((ulonglong)((longlong)DAT_030b4af4 * (longlong)(iVar19 + iVar23)) >> 0x20);
    iVar17 = iVar11 - iVar22 >> 1;
    piVar7[6] = iVar17 - iVar24;
    piVar7[0xe] = iVar24 + iVar17;
    iVar17 = iVar8 + iVar18 >> 1;
    piVar7[7] = iVar17 - iVar25;
    piVar7[0xf] = iVar25 + iVar17;
    iVar17 = iVar11 + iVar22 >> 1;
    piVar7[2] = iVar13 + iVar17;
    piVar7[10] = iVar17 - iVar13;
    iVar17 = iVar8 - iVar18 >> 1;
    piVar7[3] = iVar17 - iVar21;
    piVar7[0xb] = iVar21 + iVar17;
    piVar7 = piVar7 + 0x10;
  }
  FUN_030b49c4(param_2,iVar5 >> 5,8,*DAT_030b4af8);
  return;
}


