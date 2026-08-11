/**
 * FUN_03027afa @ 0x03027afa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03027afa(void)

{
  short sVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  
  psVar2 = DAT_03027e38;
  iVar14 = 0;
  do {
    iVar13 = DAT_03027e40;
    if (*(int *)(psVar2 + 0x24) <= iVar14) {
      return 0;
    }
    if ((*(int *)(psVar2 + 0x30) != 0) && (*(int *)(psVar2 + 0x32) == 0)) {
      FUN_03027a0e();
    }
    for (iVar10 = 0; iVar10 < *(int *)(psVar2 + 0x22); iVar10 = iVar10 + 1) {
      iVar7 = DAT_03027e40 + -0xa0;
      iVar8 = *(int *)(DAT_03027e3c + -0x38 + iVar10 * 4);
      iVar6 = 0;
      do {
        puVar3 = (undefined4 *)(iVar7 + iVar6 * 0x20);
        iVar6 = iVar6 + 1;
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[7] = 0;
      } while (iVar6 < 4);
      psVar12 = (short *)(DAT_03027e40 + -0xa0);
      psVar11 = (short *)(DAT_03027e44 + *(int *)(DAT_03027e3c + -0x6c + iVar8 * 4) * 0x80);
      iVar7 = FUN_03027ab2(*(undefined4 *)
                            (DAT_03027e44 + 0x24c + *(int *)(DAT_03027e44 + 0x21c + iVar8 * 4) * 4))
      ;
      iVar6 = 0;
      if ((iVar7 != 0) && (iVar6 = FUN_03027592(), iVar6 < *(int *)(DAT_03027e48 + iVar7 * 4))) {
        iVar6 = iVar6 + *(int *)(DAT_03027e48 + 0x40 + iVar7 * 4);
      }
      iVar6 = *(int *)(DAT_03027e3c + iVar8 * 4) + iVar6;
      *(int *)(DAT_03027e3c + iVar8 * 4) = iVar6;
      iVar7 = DAT_03027e3c;
      *psVar12 = (short)iVar6 * *psVar11;
      uVar4 = *(undefined4 *)(iVar7 + -0x20 + *(int *)(iVar7 + -0x44 + iVar8 * 4) * 4);
      for (iVar6 = 1; iVar6 < psVar2[5]; iVar6 = iVar6 + 1) {
        uVar5 = FUN_03027ab2(uVar4);
        uVar9 = uVar5 & 0xf;
        if (uVar9 == 0) {
          if ((int)uVar5 >> 4 != 0xf) goto LAB_03027c40;
          iVar6 = iVar6 + 0xf;
          if (0x3f < iVar6) {
            return 0xffffff1d;
          }
        }
        else {
          iVar6 = iVar6 + ((int)uVar5 >> 4);
          if (0x3f < iVar6) {
            return 0xffffff1d;
          }
          iVar7 = FUN_03027592(uVar9);
          if (iVar7 < *(int *)(DAT_03027e48 + uVar9 * 4)) {
            iVar7 = iVar7 + *(int *)(DAT_03027e48 + 0x40 + uVar9 * 4);
          }
          psVar12[*(short *)(DAT_03027e48 + -0x80 + iVar6 * 2)] = (short)iVar7 * psVar11[iVar6];
        }
      }
      for (; iVar6 < 0x40; iVar6 = iVar6 + 1) {
        uVar5 = FUN_03027ab2(uVar4);
        if ((uVar5 & 0xf) == 0) {
          if ((int)uVar5 >> 4 != 0xf) break;
          iVar6 = iVar6 + 0xf;
          if (0x3f < iVar6) {
            return 0xffffff1d;
          }
        }
        else {
          iVar6 = iVar6 + ((int)uVar5 >> 4);
          if (0x3f < iVar6) {
            return 0xffffff1d;
          }
          FUN_03027a7c();
        }
      }
LAB_03027c40:
      sVar1 = *psVar2;
      if (sVar1 == 1) {
        FUN_03028c9e(DAT_03027e40 + -0xa0,iVar13);
      }
      else if (sVar1 == 2) {
        FUN_03028c1a(DAT_03027e40 + -0xa0,iVar13);
      }
      else if (sVar1 == 4) {
        FUN_030289e4(DAT_03027e40 + -0xa0,iVar13);
      }
      else if (sVar1 == 8) {
        FUN_03028628(DAT_03027e40 + -0xa0,iVar13);
      }
      iVar13 = iVar13 + 0x80;
    }
    FUN_03027640();
    iVar14 = iVar14 + 1;
    *(int *)(psVar2 + 0x32) = *(int *)(psVar2 + 0x32) + -1;
  } while( true );
}


