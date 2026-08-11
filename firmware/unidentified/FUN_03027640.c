/**
 * FUN_03027640 @ 0x03027640
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03027640(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  
  iVar2 = DAT_0302787c;
  psVar1 = DAT_03027874;
  iVar3 = (*(int *)(DAT_03027874 + 0x1e) << 0xf) >> 0x10;
  iVar9 = (*(int *)(DAT_03027874 + 0x1e) << 0xe) >> 0x10;
  sVar14 = DAT_03027874[2];
  iVar8 = (*(int *)(DAT_03027874 + 0x20) << 0xf) >> 0x10;
  iVar12 = (int)sVar14 >> 1;
  iVar13 = *(int *)(DAT_03027874 + 0x3a);
  switch(*(undefined4 *)(DAT_03027874 + 0x16)) {
  case 1:
    iVar8 = DAT_0302787c;
    for (iVar9 = 0; iVar9 < *(int *)(psVar1 + 0x20); iVar9 = (int)(short)((short)iVar9 + 1)) {
      for (iVar4 = 0; iVar4 < *(int *)(psVar1 + 0x1e); iVar4 = (int)(short)((short)iVar4 + 1)) {
        *(undefined1 *)(iVar13 + iVar4) = *(undefined1 *)(iVar8 + iVar4 * 2);
      }
      iVar8 = iVar8 + 0x10;
      iVar13 = iVar13 + psVar1[2];
    }
    iVar2 = iVar2 + 0x80;
    iVar8 = *(int *)(psVar1 + 0x3c);
    for (iVar9 = 0; iVar9 < *(int *)(psVar1 + 0x20); iVar9 = (int)(short)((short)iVar9 + 2)) {
      for (iVar13 = 0; iVar13 < *(int *)(psVar1 + 0x1e); iVar13 = (int)(short)((short)iVar13 + 2)) {
        puVar7 = (ushort *)(iVar2 + iVar13 * 2);
        *(ushort *)(iVar8 + iVar13) = *puVar7 | (ushort)(byte)puVar7[0x40] << 8;
      }
      iVar2 = iVar2 + 0x20;
      iVar8 = iVar8 + iVar12 * 2;
    }
    goto LAB_0302794e;
  case 2:
    sVar14 = 0;
    do {
      iVar8 = iVar2;
      iVar9 = iVar13;
      for (iVar4 = 0; iVar4 < *(int *)(psVar1 + 0x20); iVar4 = (int)(short)((short)iVar4 + 1)) {
        for (iVar10 = 0; iVar10 < iVar3; iVar10 = (int)(short)((short)iVar10 + 1)) {
          *(undefined1 *)(iVar9 + iVar10) = *(undefined1 *)(iVar8 + iVar10 * 2);
        }
        iVar8 = iVar8 + 0x10;
        iVar9 = iVar9 + psVar1[2];
      }
      sVar14 = sVar14 + 1;
      iVar2 = iVar2 + 0x80;
      iVar13 = iVar13 + *(int *)(psVar1 + 0x1e) / 2;
    } while (sVar14 < 2);
    iVar8 = *(int *)(psVar1 + 0x3c);
    for (iVar9 = 0; iVar9 < *(int *)(psVar1 + 0x20); iVar9 = (int)(short)((short)iVar9 + 2)) {
      for (iVar13 = 0; iVar13 < iVar3; iVar13 = (int)(short)((short)iVar13 + 1)) {
        puVar7 = (ushort *)(iVar2 + iVar13 * 2);
        *(ushort *)(iVar8 + iVar13 * 2) = *puVar7 | (ushort)(byte)puVar7[0x40] << 8;
      }
      iVar2 = iVar2 + 0x20;
      iVar8 = iVar8 + iVar12 * 2;
    }
    *(int *)(psVar1 + 0x3a) = *(int *)(psVar1 + 0x3a) + *(int *)(psVar1 + 0x1e);
    iVar2 = *(int *)(psVar1 + 0x3c);
    goto LAB_030278b8;
  case 3:
    sVar14 = 0;
    do {
      iVar9 = iVar13;
      iVar4 = iVar2;
      for (iVar10 = 0; iVar10 < iVar8; iVar10 = (int)(short)((short)iVar10 + 1)) {
        for (iVar5 = 0; iVar5 < iVar3; iVar5 = (int)(short)((short)iVar5 + 1)) {
          *(undefined1 *)(iVar9 + iVar5) = *(undefined1 *)(iVar4 + iVar5 * 2);
        }
        iVar4 = iVar4 + 0x10;
        iVar9 = iVar9 + psVar1[2];
      }
      iVar2 = iVar2 + 0x80;
      iVar13 = iVar13 + (*(int *)(psVar1 + 0x1e) >> 1);
      sVar14 = sVar14 + 1;
    } while (sVar14 < 2);
    iVar9 = *(int *)(psVar1 + 0x3a) + ((int)psVar1[2] * *(int *)(psVar1 + 0x20) >> 1);
    sVar14 = 0;
    do {
      iVar13 = iVar2;
      iVar4 = iVar9;
      for (iVar10 = 0; iVar10 < iVar8; iVar10 = (int)(short)((short)iVar10 + 1)) {
        for (iVar5 = 0; iVar5 < iVar3; iVar5 = (int)(short)((short)iVar5 + 1)) {
          *(undefined1 *)(iVar4 + iVar5) = *(undefined1 *)(iVar13 + iVar5 * 2);
        }
        iVar13 = iVar13 + 0x10;
        iVar4 = iVar4 + psVar1[2];
      }
      sVar14 = sVar14 + 1;
      iVar2 = iVar2 + 0x80;
      iVar9 = iVar9 + (*(int *)(psVar1 + 0x1e) >> 1);
    } while (sVar14 < 2);
    iVar9 = *(int *)(psVar1 + 0x3c);
    for (iVar13 = 0; iVar13 < iVar8; iVar13 = (int)(short)((short)iVar13 + 1)) {
      for (iVar4 = 0; iVar4 < iVar3; iVar4 = (int)(short)((short)iVar4 + 1)) {
        puVar7 = (ushort *)(iVar2 + iVar4 * 2);
        *(ushort *)(iVar9 + iVar4 * 2) = *puVar7 | (ushort)(byte)puVar7[0x40] << 8;
      }
      iVar2 = iVar2 + 0x10;
      iVar9 = iVar9 + iVar12 * 2;
    }
    *(int *)(psVar1 + 0x3a) = *(int *)(psVar1 + 0x3a) + *(int *)(psVar1 + 0x1e);
    *(int *)(psVar1 + 0x3c) = *(int *)(psVar1 + 0x3c) + iVar3 * 2;
    break;
  case 4:
    sVar14 = 0;
    do {
      iVar9 = iVar2;
      iVar4 = iVar13;
      for (iVar10 = 0; iVar10 < iVar8; iVar10 = (int)(short)((short)iVar10 + 1)) {
        for (iVar5 = 0; iVar5 < *(int *)(psVar1 + 0x1e); iVar5 = (int)(short)((short)iVar5 + 1)) {
          *(undefined1 *)(iVar4 + iVar5) = *(undefined1 *)(iVar9 + iVar5 * 2);
        }
        iVar9 = iVar9 + 0x10;
        iVar4 = iVar4 + psVar1[2];
      }
      sVar14 = sVar14 + 1;
      iVar2 = iVar2 + 0x80;
      iVar13 = iVar8 * psVar1[2] + iVar13;
    } while (sVar14 < 2);
    iVar9 = *(int *)(psVar1 + 0x3c);
    for (iVar13 = 0; iVar13 < iVar8; iVar13 = (int)(short)((short)iVar13 + 1)) {
      for (iVar4 = 0; iVar4 < *(int *)(psVar1 + 0x1e); iVar4 = (int)(short)((short)iVar4 + 2)) {
        puVar7 = (ushort *)(iVar2 + iVar4 * 2);
        *(ushort *)(iVar9 + iVar4) = *puVar7 | (ushort)(byte)puVar7[0x40] << 8;
      }
      iVar2 = iVar2 + 0x10;
      iVar9 = iVar9 + iVar12 * 2;
    }
LAB_0302794e:
    *(int *)(psVar1 + 0x3a) = *(int *)(psVar1 + 0x3a) + *(int *)(psVar1 + 0x1e);
    if (*psVar1 == 1) {
      *(uint *)(psVar1 + 0x3c) = *(int *)(psVar1 + 0x3c) + *(uint *)(psVar1 + 0x14) * 2;
      *(uint *)(psVar1 + 0x14) = *(uint *)(psVar1 + 0x14) ^ 1;
    }
    else {
      iVar2 = *(int *)(psVar1 + 0x3c);
LAB_030278b8:
      *(int *)(psVar1 + 0x3c) = iVar2 + iVar3 * 2;
    }
    break;
  case 5:
    sVar11 = 0;
    do {
      iVar3 = iVar13;
      iVar8 = iVar2;
      for (iVar12 = 0; iVar12 < *(int *)(psVar1 + 0x20); iVar12 = (int)(short)((short)iVar12 + 1)) {
        for (iVar4 = 0; iVar4 < iVar9; iVar4 = (int)(short)((short)iVar4 + 1)) {
          *(undefined1 *)(iVar3 + iVar4) = *(undefined1 *)(iVar8 + iVar4 * 2);
        }
        iVar8 = iVar8 + 0x10;
        iVar3 = iVar3 + psVar1[2];
      }
      sVar11 = sVar11 + 1;
      iVar2 = iVar2 + 0x80;
      iVar13 = iVar13 + ((int)(*(int *)(psVar1 + 0x1e) +
                              ((uint)(*(int *)(psVar1 + 0x1e) >> 0x1f) >> 0x1e)) >> 2);
    } while (sVar11 < 4);
    iVar3 = *(int *)(psVar1 + 0x3c);
    for (iVar8 = 0; iVar8 < *(int *)(psVar1 + 0x20); iVar8 = (int)(short)((short)iVar8 + 1)) {
      for (iVar12 = 0; iVar12 < iVar9; iVar12 = (int)(short)((short)iVar12 + 1)) {
        puVar7 = (ushort *)(iVar2 + iVar12 * 2);
        uVar6 = *puVar7 | (ushort)(byte)puVar7[0x40] << 8;
        *(ushort *)(iVar3 + iVar12 * 2) = uVar6;
        *(ushort *)(iVar3 + iVar12 * 2 + 2) = uVar6;
      }
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + ((int)sVar14 >> 2) * 2;
    }
    *(int *)(psVar1 + 0x3a) = *(int *)(psVar1 + 0x3a) + *(int *)(psVar1 + 0x1e);
    *(int *)(psVar1 + 0x3c) = *(int *)(psVar1 + 0x3c) + iVar9 * 4;
  }
  return;
}


