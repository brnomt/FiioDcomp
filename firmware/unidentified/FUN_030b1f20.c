/**
 * FUN_030b1f20 @ 0x030b1f20
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030b1f20(int *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  int *piVar23;
  int *piVar24;
  undefined2 *puVar25;
  int iVar26;
  int *piStack_58;
  int *piStack_54;
  int iStack_50;
  int *piStack_44;
  int iStack_40;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
  }
  if (param_1 == (int *)0x0 || iVar5 == 0) {
    return 0xffffffff;
  }
  if ((param_2 != 1) || (iVar6 = iVar5, *(int *)(iVar5 + 0x8f0) != 1)) {
    iVar6 = iVar5 + param_2 * 0x3a;
  }
  puVar14 = (undefined2 *)(param_4 + param_3 * 2);
  if (*(char *)(iVar6 + 0x87d) == '\x02') {
    iVar9 = 0;
    do {
      FUN_030b38fc(0,iVar5 + param_2 * 0x1000 + iVar9 * 0x200 + 0x1048,
                   *(undefined4 *)(iVar5 + param_2 * 4 + 0x1040));
      iVar9 = iVar9 + 1;
    } while (iVar9 < 8);
  }
  else {
    FUN_030b38fc(1,iVar5 + param_2 * 0x1000 + 0x1048,*(undefined4 *)(iVar5 + param_2 * 4 + 0x1040));
  }
  cVar1 = *(char *)(iVar6 + 0x87d);
  if (cVar1 == '\0') {
    iVar9 = iVar5 + param_2 * 0x1000;
    piVar22 = (int *)(iVar9 + 0x1848);
    iVar10 = iVar5 + param_3 * 0x1000;
    piVar21 = (int *)(iVar10 + 0x3048);
    piVar24 = (int *)(iVar9 + 0x1844);
    piVar18 = (int *)(iVar10 + 0x4044);
    iVar9 = param_1[0x10];
    puVar25 = puVar14 + iVar9 * 0x3ff;
    uVar7 = *(uint *)(iVar5 + param_3 * 4 + 0x5048);
    if (uVar7 == 1) {
      piVar15 = (int *)(*DAT_030b2430 + *(int *)(*DAT_030b242c + 4) * 4);
    }
    else {
      piVar15 = (int *)(*DAT_030b2428 + *(int *)(*DAT_030b2424 + 4) * 4);
    }
    if (*(byte *)(iVar6 + 0x87e) == uVar7) {
      do {
        piVar17 = piVar15 + 1;
        iVar26 = *piVar15;
        piVar15 = piVar15 + 2;
        iVar12 = *piVar17;
        lVar3 = (longlong)iVar12 * (longlong)*piVar22;
        uVar4 = saturate_s16((*piVar21 -
                             (int)((ulonglong)((longlong)iVar26 * (longlong)*piVar22) >> 0x20)) + 4
                             >> 3,*piVar21,(int)lVar3);
        *puVar14 = uVar4;
        puVar14 = puVar14 + iVar9;
        uVar4 = saturate_s16(*piVar18 + (int)((ulonglong)lVar3 >> 0x20) + 4 >> 3);
        *puVar25 = uVar4;
        iVar10 = *piVar24;
        puVar25 = puVar25 + -iVar9;
        piVar8 = piVar18 + -1;
        *piVar18 = (int)((ulonglong)((longlong)iVar26 * (longlong)iVar10) >> 0x20);
        piVar17 = piVar21 + 1;
        *piVar21 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar10) >> 0x20);
        piVar21 = piVar17;
        piVar18 = piVar8;
        piVar22 = piVar22 + 1;
        piVar24 = piVar24 + -1;
      } while (piVar17 < piVar8);
    }
    else {
      if (*(byte *)(iVar6 + 0x87e) == 1) {
        piStack_44 = (int *)(*DAT_030b2430 + *(int *)(*DAT_030b242c + 4) * 4);
      }
      else {
        piStack_44 = (int *)(*DAT_030b2428 + *(int *)(*DAT_030b2424 + 4) * 4);
      }
      do {
        piVar17 = piVar15 + 1;
        iVar10 = *piVar15;
        piVar15 = piVar15 + 2;
        lVar3 = (longlong)iVar10 * (longlong)*piVar22;
        lVar2 = (longlong)*piVar17 * (longlong)*piVar22;
        uVar4 = saturate_s16((*piVar21 - (int)((ulonglong)lVar3 >> 0x20)) + 4 >> 3,*piVar21,
                             (int)lVar2,(int)lVar3);
        *puVar14 = uVar4;
        puVar14 = puVar14 + iVar9;
        uVar4 = saturate_s16(*piVar18 + (int)((ulonglong)lVar2 >> 0x20) + 4 >> 3);
        *puVar25 = uVar4;
        puVar25 = puVar25 + -iVar9;
        iVar12 = *piStack_44;
        iVar10 = piStack_44[1];
        piStack_44 = piStack_44 + 2;
        iVar26 = *piVar24;
        piVar8 = piVar18 + -1;
        *piVar18 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar26) >> 0x20);
        piVar17 = piVar21 + 1;
        *piVar21 = (int)((ulonglong)((longlong)iVar10 * (longlong)iVar26) >> 0x20);
        piVar21 = piVar17;
        piVar18 = piVar8;
        piVar22 = piVar22 + 1;
        piVar24 = piVar24 + -1;
      } while (piVar17 < piVar8);
    }
  }
  else if (cVar1 == '\x01') {
    iVar9 = iVar5 + param_2 * 0x1000;
    iVar10 = iVar5 + param_3 * 0x1000;
    iVar26 = param_1[0x10];
    puVar25 = puVar14 + iVar26 * 0x3ff;
    cVar1 = *(char *)(iVar6 + 0x87e);
    if (*(int *)(iVar5 + param_3 * 4 + 0x5048) == 1) {
      piVar21 = (int *)(*DAT_030b2430 + *(int *)(*DAT_030b242c + 4) * 4);
    }
    else {
      piVar21 = (int *)(*DAT_030b2428 + *(int *)(*DAT_030b2424 + 4) * 4);
    }
    piStack_54 = (int *)0x1c0;
    piVar18 = (int *)(iVar10 + 0x3048);
    piVar22 = (int *)(iVar10 + 0x4044);
    piVar24 = (int *)(iVar9 + 0x1848);
    piVar15 = (int *)(iVar9 + 0x1844);
    do {
      piVar17 = piVar21 + 1;
      iVar9 = *piVar21;
      piVar19 = piVar24 + 1;
      piVar21 = piVar21 + 2;
      lVar3 = (longlong)iVar9 * (longlong)*piVar24;
      iVar9 = (int)((ulonglong)lVar3 >> 0x20);
      iVar10 = (int)((ulonglong)((longlong)*piVar17 * (longlong)*piVar24) >> 0x20);
      uVar4 = saturate_s16((*piVar18 - iVar9) + 4 >> 3,iVar9,iVar10,(int)lVar3);
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar26;
      uVar4 = saturate_s16(*piVar22 + iVar10 + 4 >> 3);
      *puVar25 = uVar4;
      piVar16 = piVar15 + -1;
      iVar9 = *piVar15;
      piVar8 = piVar22 + -1;
      *piVar22 = 0;
      piVar17 = piVar18 + 1;
      *piVar18 = iVar9 >> 1;
      puVar25 = puVar25 + -iVar26;
      piStack_54 = (int *)((int)piStack_54 + -1);
      piVar18 = piVar17;
      piVar22 = piVar8;
      piVar24 = piVar19;
      piVar15 = piVar16;
    } while (piStack_54 != (int *)0x0);
    if (cVar1 == '\x01') {
      piStack_54 = (int *)(*DAT_030b2430 + *(int *)*DAT_030b242c * 4);
    }
    else {
      piStack_54 = (int *)(*DAT_030b2428 + *(int *)*DAT_030b2424 * 4);
    }
    do {
      piVar18 = piVar21 + 1;
      iVar9 = *piVar21;
      piVar21 = piVar21 + 2;
      lVar3 = (longlong)iVar9 * (longlong)*piVar19;
      iVar9 = (int)((ulonglong)lVar3 >> 0x20);
      lVar2 = (longlong)*piVar18 * (longlong)*piVar19;
      uVar4 = saturate_s16((*piVar17 - iVar9) + 4 >> 3,iVar9,(int)lVar2,(int)lVar3);
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar26;
      uVar4 = saturate_s16((int)((ulonglong)lVar2 >> 0x20) + *piVar8 + 4 >> 3);
      *puVar25 = uVar4;
      puVar25 = puVar25 + -iVar26;
      iVar10 = piStack_54[1];
      iVar9 = *piStack_54;
      piStack_54 = piStack_54 + 2;
      iVar12 = *piVar16;
      piVar22 = piVar8 + -1;
      *piVar8 = (int)((ulonglong)((longlong)iVar9 * (longlong)iVar12) >> 0x20);
      piVar18 = piVar17 + 1;
      *piVar17 = (int)((ulonglong)((longlong)iVar10 * (longlong)iVar12) >> 0x20);
      piVar17 = piVar18;
      piVar8 = piVar22;
      piVar19 = piVar19 + 1;
      piVar16 = piVar16 + -1;
    } while (piVar18 < piVar22);
  }
  else if (cVar1 == '\x02') {
    iVar9 = iVar5 + param_2 * 0x1000;
    iVar10 = param_1[0x10];
    if (*(int *)(iVar5 + param_3 * 4 + 0x5048) == 1) {
      piVar21 = (int *)(*DAT_030b26dc + *(int *)*DAT_030b26d8 * 4);
    }
    else {
      piVar21 = (int *)(*DAT_030b2428 + *(int *)*DAT_030b2424 * 4);
    }
    if (*(char *)(iVar6 + 0x87e) == '\x01') {
      piVar18 = (int *)(*DAT_030b26dc + *(int *)*DAT_030b26d8 * 4);
    }
    else {
      piVar18 = (int *)(*DAT_030b2428 + *(int *)*DAT_030b2424 * 4);
    }
    iVar26 = 0x1c0;
    piVar22 = (int *)(iVar5 + param_3 * 0x1000 + 0x3048);
    do {
      piVar24 = piVar22;
      iVar12 = piVar24[1];
      uVar4 = saturate_s16(*piVar24 + 4 >> 3);
      *puVar14 = uVar4;
      uVar4 = saturate_s16(iVar12 + 4 >> 3);
      puVar14[iVar10] = uVar4;
      iVar26 = iVar26 + -2;
      puVar14 = puVar14 + iVar10 + iVar10;
      piVar22 = piVar24 + 2;
    } while (iVar26 != 0);
    puVar25 = puVar14 + iVar10 * 0x7f;
    piVar15 = (int *)(iVar9 + 0x1148);
    piVar24 = piVar24 + 0x81;
    piVar17 = (int *)(iVar9 + 0x1144);
    do {
      piVar8 = piVar21 + 1;
      iVar9 = *piVar21;
      piVar19 = piVar15 + 1;
      piVar21 = piVar21 + 2;
      lVar3 = (longlong)iVar9 * (longlong)*piVar15;
      iVar9 = (int)((ulonglong)lVar3 >> 0x20);
      lVar2 = (longlong)*piVar8 * (longlong)*piVar15;
      uVar4 = saturate_s16((*piVar22 - iVar9) + 4 >> 3,iVar9,(int)lVar2,(int)lVar3);
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar10;
      uVar4 = saturate_s16((int)((ulonglong)lVar2 >> 0x20) + *piVar24 + 4 >> 3);
      *puVar25 = uVar4;
      piVar15 = piVar18 + 1;
      iVar26 = *piVar18;
      iVar12 = *piVar17;
      puVar25 = puVar25 + -iVar10;
      piVar18 = piVar18 + 2;
      iVar9 = *piVar15;
      piVar16 = piVar24 + -1;
      *piVar24 = (int)((ulonglong)((longlong)iVar26 * (longlong)iVar12) >> 0x20);
      piVar8 = piVar22 + 1;
      *piVar22 = (int)((ulonglong)((longlong)iVar9 * (longlong)iVar12) >> 0x20);
      piVar22 = piVar8;
      piVar15 = piVar19;
      piVar24 = piVar16;
      piVar17 = piVar17 + -1;
    } while (piVar8 < piVar16);
    iStack_40 = 0;
    do {
      puVar14 = puVar14 + iVar10 * 0x40;
      puVar25 = puVar14 + iVar10 * 0x7f;
      piVar21 = piVar8 + 0x40;
      piVar18 = piVar18 + -0x80;
      piVar22 = piVar19 + 0x40;
      piVar24 = piVar8 + 0xbf;
      piVar15 = piVar19 + 0x3f;
      do {
        piVar20 = piVar22;
        piVar16 = piVar18;
        piVar17 = piVar21;
        iVar12 = *piVar16;
        piVar18 = piVar16 + 2;
        iVar9 = piVar16[1];
        piVar19 = piVar20 + 1;
        iVar26 = *piVar20;
        uVar4 = saturate_s16(((piVar17[-0x80] + *piVar17) -
                             (int)((ulonglong)((longlong)iVar12 * (longlong)iVar26) >> 0x20)) + 4 >>
                             3);
        *puVar14 = uVar4;
        puVar14 = puVar14 + iVar10;
        uVar4 = saturate_s16((int)((ulonglong)((longlong)iVar9 * (longlong)iVar26) >> 0x20) +
                             *piVar24 + piVar24[-0x80] + 4 >> 3);
        *puVar25 = uVar4;
        iVar26 = *piVar15;
        puVar25 = puVar25 + -iVar10;
        piVar23 = piVar24 + -1;
        *piVar24 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar26) >> 0x20);
        piVar8 = piVar17 + 1;
        *piVar17 = (int)((ulonglong)((longlong)iVar9 * (longlong)iVar26) >> 0x20);
        piVar21 = piVar8;
        piVar22 = piVar19;
        piVar24 = piVar23;
        piVar15 = piVar15 + -1;
      } while (piVar8 < piVar23);
      iStack_40 = iStack_40 + 1;
    } while (iStack_40 < 3);
    puVar14 = puVar14 + iVar10 * 0x40;
    piVar16 = piVar16 + -0x7e;
    piVar21 = piVar17 + -0x33f;
    piVar18 = piVar20 + 0x40;
    piVar22 = piVar20 + 0x41;
    piVar24 = piVar17 + -0x2c0;
    do {
      piVar15 = piVar16 + 1;
      iVar26 = *piVar16;
      piVar17 = piVar22 + 1;
      iVar9 = *piVar22;
      piVar16 = piVar16 + 2;
      iVar12 = *piVar15;
      uVar4 = saturate_s16(((piVar21[0x300] + piVar21[0x380]) -
                           (int)((ulonglong)((longlong)iVar26 * (longlong)iVar9) >> 0x20)) + 4 >> 3)
      ;
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar10;
      piVar24[-0x80] =
           (int)((ulonglong)((longlong)iVar12 * (longlong)iVar9) >> 0x20) + piVar24[0x300];
      iVar9 = *piVar18;
      piVar8 = piVar24 + -1;
      *piVar24 = (int)((ulonglong)((longlong)iVar26 * (longlong)iVar9) >> 0x20);
      piVar15 = piVar21 + 1;
      *piVar21 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar9) >> 0x20);
      piVar21 = piVar15;
      piVar18 = piVar18 + -1;
      piVar22 = piVar17;
      piVar24 = piVar8;
    } while (piVar15 < piVar8);
    iVar9 = 0;
    do {
      piVar16 = piVar16 + -0x80;
      piVar21 = piVar15 + 0xbf;
      piVar18 = piVar17 + 0x3f;
      piVar15 = piVar15 + 0x40;
      piVar22 = piVar17 + 0x40;
      do {
        piVar8 = piVar15;
        piVar24 = piVar16 + 1;
        iVar26 = *piVar16;
        piVar17 = piVar22 + 1;
        iVar10 = *piVar22;
        piVar16 = piVar16 + 2;
        iVar12 = *piVar24;
        piVar8[-0x80] =
             piVar8[-0x80] - (int)((ulonglong)((longlong)iVar26 * (longlong)iVar10) >> 0x20);
        piVar21[-0x80] =
             piVar21[-0x80] + (int)((ulonglong)((longlong)iVar12 * (longlong)iVar10) >> 0x20);
        iVar10 = *piVar18;
        piVar24 = piVar21 + -1;
        *piVar21 = (int)((ulonglong)((longlong)iVar26 * (longlong)iVar10) >> 0x20);
        piVar15 = piVar8 + 1;
        *piVar8 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar10) >> 0x20);
        piVar21 = piVar24;
        piVar18 = piVar18 + -1;
        piVar22 = piVar17;
      } while (piVar15 < piVar24);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
    iVar9 = 0x1c0;
    piVar8 = piVar8 + 0x41;
    do {
      *piVar8 = 0;
      iVar9 = iVar9 + -4;
      piVar8[1] = 0;
      piVar21 = piVar8 + 3;
      piVar8[2] = 0;
      piVar8 = piVar8 + 4;
      *piVar21 = 0;
    } while (iVar9 != 0);
  }
  else if (cVar1 == '\x03') {
    iVar9 = iVar5 + param_2 * 0x1000;
    iVar10 = iVar5 + param_3 * 0x1000;
    iVar26 = param_1[0x10];
    puVar25 = puVar14 + iVar26 * 0x3ff;
    if (*(int *)(iVar5 + param_3 * 4 + 0x5048) == 1) {
      iVar12 = *(int *)*DAT_030b26d8;
      piStack_58 = (int *)(*DAT_030b26dc + iVar12 * 4);
    }
    else {
      iVar12 = *(int *)*DAT_030b26e0;
      piStack_58 = (int *)(*DAT_030b26e4 + iVar12 * 4);
    }
    if (*(char *)(iVar6 + 0x87e) == '\x01') {
      iVar11 = *(int *)(*DAT_030b26d8 + 4);
      piVar21 = (int *)(*DAT_030b26dc + iVar11 * 4);
    }
    else {
      iVar11 = *(int *)(*DAT_030b26e0 + 4);
      piVar21 = (int *)(*DAT_030b26e4 + iVar11 * 4);
    }
    iStack_50 = 0x1c0;
    iVar13 = param_3;
    piVar18 = (int *)(iVar10 + 0x3048);
    piVar22 = (int *)(iVar10 + 0x4044);
    piVar24 = (int *)(iVar9 + 0x1848);
    piVar15 = (int *)(iVar9 + 0x1844);
    do {
      iVar9 = *piVar24;
      uVar4 = saturate_s16(*piVar18 + 4 >> 3,iVar11,iVar12,iVar13);
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar26;
      uVar4 = saturate_s16((iVar9 >> 1) + *piVar22 + 4 >> 3);
      *puVar25 = uVar4;
      piVar17 = piVar21 + 1;
      iVar10 = *piVar21;
      iVar12 = *piVar15;
      piVar21 = piVar21 + 2;
      iVar9 = *piVar17;
      iVar13 = (int)((longlong)iVar10 * (longlong)iVar12);
      *piVar22 = (int)((ulonglong)((longlong)iVar10 * (longlong)iVar12) >> 0x20);
      iVar11 = (int)((longlong)iVar9 * (longlong)iVar12);
      *piVar18 = (int)((ulonglong)((longlong)iVar9 * (longlong)iVar12) >> 0x20);
      puVar25 = puVar25 + -iVar26;
      iStack_50 = iStack_50 + -1;
      piVar17 = piVar18 + 1;
      piVar18 = piVar18 + 1;
      piVar8 = piVar22 + -1;
      piVar22 = piVar22 + -1;
      piVar19 = piVar24 + 1;
      piVar24 = piVar24 + 1;
      piVar16 = piVar15 + -1;
      piVar15 = piVar15 + -1;
    } while (iStack_50 != 0);
    do {
      piVar18 = piStack_58 + 1;
      iVar9 = *piStack_58;
      piStack_58 = piStack_58 + 2;
      lVar3 = (longlong)iVar9 * (longlong)*piVar19;
      iVar9 = (int)((ulonglong)lVar3 >> 0x20);
      iVar10 = (int)((ulonglong)((longlong)*piVar18 * (longlong)*piVar19) >> 0x20);
      uVar4 = saturate_s16((*piVar17 - iVar9) + 4 >> 3,iVar9,iVar10,(int)lVar3);
      *puVar14 = uVar4;
      puVar14 = puVar14 + iVar26;
      uVar4 = saturate_s16(*piVar8 + iVar10 + 4 >> 3);
      *puVar25 = uVar4;
      piVar18 = piVar21 + 1;
      iVar12 = *piVar21;
      iVar9 = *piVar16;
      piVar21 = piVar21 + 2;
      iVar10 = *piVar18;
      piVar22 = piVar8 + -1;
      *piVar8 = (int)((ulonglong)((longlong)iVar12 * (longlong)iVar9) >> 0x20);
      piVar18 = piVar17 + 1;
      *piVar17 = (int)((ulonglong)((longlong)iVar10 * (longlong)iVar9) >> 0x20);
      puVar25 = puVar25 + -iVar26;
      piVar17 = piVar18;
      piVar8 = piVar22;
      piVar19 = piVar19 + 1;
      piVar16 = piVar16 + -1;
    } while (piVar18 < piVar22);
  }
  param_1[param_2 + 2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(uint *)(iVar5 + param_3 * 4 + 0x5048) = (uint)*(byte *)(iVar6 + 0x87e);
  return 0;
}


