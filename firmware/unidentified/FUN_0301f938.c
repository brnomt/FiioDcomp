/**
 * FUN_0301f938 @ 0x0301f938
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301f938(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int *piVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  short *psVar18;
  int iVar19;
  
  iVar5 = 0;
  do {
    puVar3 = (ushort *)(param_1 + iVar5 * 0x10);
    iVar8 = (int)(short)puVar3[6];
    iVar9 = (short)puVar3[4] * 0x800;
    iVar16 = (int)(short)puVar3[2];
    iVar13 = (int)(short)puVar3[1];
    iVar10 = (int)(short)puVar3[7];
    iVar12 = (int)(short)puVar3[5];
    iVar11 = (int)(short)puVar3[3];
    if ((((((iVar9 == 0 && iVar8 == 0) && iVar16 == 0) && iVar13 == 0) && iVar10 == 0) &&
        iVar12 == 0) && iVar11 == 0) {
      uVar6 = *puVar3 << 3;
      puVar3[7] = uVar6;
      puVar3[6] = uVar6;
      puVar3[5] = uVar6;
      puVar3[4] = uVar6;
      puVar3[3] = uVar6;
      puVar3[2] = uVar6;
      puVar3[1] = uVar6;
      *puVar3 = uVar6;
    }
    else {
      iVar7 = (uint)*puVar3 * 0x800 + 0x80;
      iVar15 = (iVar13 + iVar10) * 0x235;
      iVar14 = iVar15 + iVar13 * 0x8e4;
      iVar15 = iVar15 + iVar10 * DAT_0301fcd0 * 2;
      iVar13 = (iVar12 + iVar11) * 0x968;
      iVar12 = DAT_0301fcd4 * iVar12 + iVar13;
      iVar13 = iVar11 * -0xfb1 + iVar13;
      iVar9 = iVar7 + iVar9;
      iVar7 = iVar7 + (short)puVar3[4] * -0x800;
      iVar10 = (iVar16 + iVar8) * 0x454;
      iVar8 = iVar10 + iVar8 * -0xec8;
      iVar10 = iVar10 + iVar16 * 0x620;
      iVar17 = iVar14 + iVar12;
      iVar14 = iVar14 - iVar12;
      iVar16 = iVar15 + iVar13;
      iVar15 = iVar15 - iVar13;
      iVar12 = iVar9 + iVar10;
      iVar9 = iVar9 - iVar10;
      iVar10 = iVar7 + iVar8;
      iVar7 = iVar7 - iVar8;
      iVar8 = (iVar14 + iVar15) * 0xb5 + 0x80 >> 8;
      *puVar3 = (ushort)((uint)(iVar12 + iVar17) >> 8);
      iVar11 = (iVar14 - iVar15) * 0xb5 + 0x80 >> 8;
      puVar3[1] = (ushort)((uint)(iVar10 + iVar8) >> 8);
      puVar3[2] = (ushort)((uint)(iVar7 + iVar11) >> 8);
      puVar3[3] = (ushort)((uint)(iVar9 + iVar16) >> 8);
      puVar3[4] = (ushort)((uint)(iVar9 - iVar16) >> 8);
      puVar3[5] = (ushort)((uint)(iVar7 - iVar11) >> 8);
      puVar3[6] = (ushort)((uint)(iVar10 - iVar8) >> 8);
      puVar3[7] = (ushort)((uint)(iVar12 - iVar17) >> 8);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  iVar5 = 0;
  do {
    piVar2 = DAT_0301fcd8;
    psVar18 = (short *)(param_1 + iVar5 * 2);
    puVar4 = (undefined1 *)(param_2 + iVar5);
    iVar16 = (int)psVar18[0x30];
    iVar8 = psVar18[0x20] * 0x100;
    iVar9 = (int)psVar18[0x10];
    iVar10 = (int)psVar18[8];
    iVar11 = (int)psVar18[0x38];
    iVar12 = (int)psVar18[0x28];
    iVar13 = (int)psVar18[0x18];
    if ((((((iVar8 == 0 && iVar16 == 0) && iVar9 == 0) && iVar10 == 0) && iVar11 == 0) &&
        iVar12 == 0) && iVar13 == 0) {
      uVar1 = *(undefined1 *)(*DAT_0301fcd8 + (*psVar18 + 0x20 >> 6) * 2);
      puVar4[param_3 * 7] = uVar1;
      puVar4[param_3 * 6] = uVar1;
      puVar4[param_3 * 5] = uVar1;
      puVar4[param_3 * 4] = uVar1;
      puVar4[param_3 * 3] = uVar1;
      puVar4[param_3 * 2] = uVar1;
      puVar4[param_3] = uVar1;
      *puVar4 = uVar1;
    }
    else {
      iVar19 = *psVar18 * 0x100 + 0x2000;
      iVar14 = (iVar10 + iVar11) * 0x235 + 4;
      iVar17 = (iVar12 + iVar13) * 0x968 + 4;
      iVar15 = iVar14 + iVar10 * 0x8e4 >> 3;
      iVar8 = iVar19 + iVar8;
      iVar19 = iVar19 + psVar18[0x20] * -0x100;
      iVar7 = (iVar9 + iVar16) * 0x454 + 4;
      iVar10 = iVar12 * DAT_0301fcd4 + iVar17 >> 3;
      iVar12 = iVar15 + iVar10;
      iVar15 = iVar15 - iVar10;
      iVar14 = iVar14 + iVar11 * DAT_0301fcd0 * 2 >> 3;
      iVar10 = iVar13 * -0xfb1 + iVar17 >> 3;
      iVar9 = iVar7 + iVar9 * 0x620 >> 3;
      iVar13 = iVar14 + iVar10;
      iVar14 = iVar14 - iVar10;
      iVar17 = iVar8 + iVar9;
      iVar8 = iVar8 - iVar9;
      iVar9 = iVar7 + iVar16 * -0xec8 >> 3;
      iVar11 = iVar19 + iVar9;
      iVar19 = iVar19 - iVar9;
      iVar9 = (iVar15 - iVar14) * 0xb5 + 0x80 >> 8;
      iVar10 = (iVar15 + iVar14) * 0xb5 + 0x80 >> 8;
      *puVar4 = *(undefined1 *)(*DAT_0301fcd8 + (iVar12 + iVar17 >> 0xe) * 2);
      puVar4[param_3] = *(undefined1 *)(*piVar2 + (iVar11 + iVar10 >> 0xe) * 2);
      puVar4[param_3 * 2] = *(undefined1 *)(*piVar2 + (iVar19 + iVar9 >> 0xe) * 2);
      puVar4[param_3 * 3] = *(undefined1 *)(*piVar2 + (iVar8 + iVar13 >> 0xe) * 2);
      puVar4[param_3 * 4] = *(undefined1 *)(*piVar2 + (iVar8 - iVar13 >> 0xe) * 2);
      puVar4[param_3 * 5] = *(undefined1 *)(*piVar2 + (iVar19 - iVar9 >> 0xe) * 2);
      puVar4[param_3 * 6] = *(undefined1 *)(*piVar2 + (iVar11 - iVar10 >> 0xe) * 2);
      puVar4[param_3 * 7] = *(undefined1 *)(*piVar2 + (iVar17 - iVar12 >> 0xe) * 2);
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  return;
}


