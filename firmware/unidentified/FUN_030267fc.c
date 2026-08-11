/**
 * FUN_030267fc @ 0x030267fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030267fc(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int *piVar4;
  short *psVar5;
  short *psVar6;
  undefined2 *puVar7;
  short *psVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int unaff_r10;
  int iVar20;
  char cVar21;
  bool bVar22;
  
  psVar6 = DAT_03026a30;
  psVar5 = DAT_03026a2c;
  piVar4 = DAT_03026a28;
  iVar15 = (int)*DAT_03026970;
  if (iVar15 < 0x1f41) {
    sVar3 = *DAT_0302696c;
    iVar11 = (int)sVar3;
    if (iVar11 < 0x1f41) {
      iVar19 = *DAT_03026a24;
      iVar20 = *DAT_030269c0;
      iVar18 = *(int *)(iVar19 + 0xc);
      iVar17 = *DAT_030269c4;
      iVar16 = *DAT_03026a04;
      iVar1 = iVar18 * 8;
      bVar22 = SBORROW4(iVar15,iVar1);
      iVar2 = iVar15 + iVar18 * -8;
      if (iVar15 < iVar1) {
        unaff_r10 = *(int *)(iVar19 + 0x10);
      }
      if (iVar15 < iVar1) {
        bVar22 = SBORROW4(iVar11,unaff_r10 * 8);
        iVar2 = iVar11 + unaff_r10 * -8;
      }
      sVar9 = (short)iVar16;
      sVar10 = (short)*DAT_030269d0;
      if (iVar2 < 0 == bVar22) {
        *DAT_03026a2c = (short)((int)(iVar15 + 7 + ((uint)(iVar15 + 7 >> 0x1f) >> 0x1d)) >> 3);
        *psVar6 = (short)((int)(iVar11 + 7 + ((uint)(iVar11 + 7 >> 0x1f) >> 0x1d)) >> 3);
        iVar15 = (int)(iVar20 + ((uint)(iVar20 >> 0x1f) >> 0x1d)) >> 3;
        *DAT_03026a34 = iVar15;
        iVar11 = (int)(iVar17 + ((uint)(iVar17 >> 0x1f) >> 0x1d)) >> 3;
        *DAT_03026a38 = iVar11;
        *DAT_03026a3c = sVar9 * (short)iVar15;
        *DAT_03026a40 = sVar10 * (short)iVar11;
        puVar7 = DAT_03026a44;
        *piVar4 = 1;
        *puVar7 = 1;
        *DAT_03026a48 = 1;
      }
      else {
        bVar22 = SBORROW4(iVar15,iVar18 * 4);
        iVar1 = iVar15 + iVar18 * -4;
        if (iVar15 < iVar18 * 4) {
          bVar22 = SBORROW4(iVar11,unaff_r10 * 4);
          iVar1 = iVar11 + unaff_r10 * -4;
        }
        if (iVar1 < 0 == bVar22) {
          *DAT_03026a2c = (short)((int)(iVar15 + 3 + ((uint)(iVar15 + 3 >> 0x1f) >> 0x1e)) >> 2);
          *psVar6 = (short)((int)(iVar11 + 3 + ((uint)(iVar11 + 3 >> 0x1f) >> 0x1e)) >> 2);
          iVar15 = (int)(iVar20 + ((uint)(iVar20 >> 0x1f) >> 0x1e)) >> 2;
          *DAT_03026a34 = iVar15;
          iVar11 = (int)(iVar17 + ((uint)(iVar17 >> 0x1f) >> 0x1e)) >> 2;
          *DAT_03026a38 = iVar11;
          *DAT_03026a3c = sVar9 * (short)iVar15;
          *DAT_03026a40 = sVar10 * (short)iVar11;
          *piVar4 = 4;
          *DAT_03026a44 = 2;
          *DAT_03026a48 = 5;
        }
        else {
          bVar22 = SBORROW4(iVar15,iVar18 * 2);
          iVar1 = iVar15 + iVar18 * -2;
          if (iVar15 < iVar18 * 2) {
            bVar22 = SBORROW4(iVar11,unaff_r10 * 2);
            iVar1 = iVar11 + unaff_r10 * -2;
          }
          if (iVar1 < 0 == bVar22) {
            *DAT_03026a2c = (short)((iVar15 + 1) / 2);
            *psVar6 = (short)((iVar11 + 1) / 2);
            *DAT_03026a34 = iVar20 / 2;
            *DAT_03026a38 = iVar17 / 2;
            *DAT_03026a3c = sVar9 * (short)(iVar20 / 2);
            *DAT_03026a40 = sVar10 * (short)(iVar17 / 2);
            puVar7 = DAT_03026a44;
            *piVar4 = 0x10;
            *puVar7 = 4;
            *DAT_03026a48 = 0x19;
          }
          else {
            *DAT_03026a2c = *DAT_03026970;
            *psVar6 = sVar3;
            psVar8 = DAT_03026dd8;
            *DAT_03026dd0 = iVar20;
            *DAT_03026dd4 = iVar17;
            *psVar8 = sVar9 * (short)iVar20;
            *DAT_03026ddc = sVar10 * (short)iVar17;
            puVar7 = DAT_03026de0;
            *piVar4 = 0x40;
            *puVar7 = 8;
            *DAT_03026de4 = 0x40;
          }
        }
      }
      iVar15 = DAT_03026de8;
      *DAT_03026dec = DAT_03026de8;
      cVar21 = 1 < *DAT_03026df0;
      *DAT_03026df4 = *piVar4 * (*DAT_03026df0 - 2) * iVar16 + iVar15;
      uVar12 = FUN_02ff8e60((int)*psVar6);
      piVar4 = DAT_03026df8;
      uVar13 = FUN_02ff8e60(*(undefined4 *)(iVar19 + 0x10));
      uVar12 = FUN_02ff8b68(uVar13,uVar12);
      uVar13 = FUN_02ff8e60((int)*psVar5);
      uVar14 = FUN_02ff8e60(iVar18);
      uVar13 = FUN_02ff8b68(uVar14,uVar13);
      FUN_02ff8fa4(uVar13,uVar12);
      if (cVar21 == '\0') {
        uVar12 = FUN_02ff8e60((int)*psVar5);
        uVar13 = FUN_02ff8e60(*(undefined4 *)(*piVar4 + 0xc));
        uVar12 = FUN_02ff8b68(uVar13,uVar12);
      }
      else {
        uVar12 = FUN_02ff8e60((int)*psVar6);
        uVar13 = FUN_02ff8e60(*(undefined4 *)(*piVar4 + 0x10));
        uVar12 = FUN_02ff8b68(uVar13,uVar12);
      }
      sVar3 = *psVar5;
      uVar13 = FUN_02ff8e60();
      FUN_02ff8afc(uVar13,uVar12);
      sVar9 = FUN_02ff8eae();
      iVar15 = *piVar4;
      *(int *)(iVar15 + 0x14) = (int)sVar9;
      sVar9 = *psVar6;
      uVar13 = FUN_02ff8e60();
      FUN_02ff8afc(uVar13,uVar12);
      sVar10 = FUN_02ff8eae();
      *(int *)(iVar15 + 0x18) = (int)sVar10;
      *DAT_03026dfc = (int)sVar3 + 1U & 0xfffffffe;
      *DAT_03026e00 = (int)sVar9;
      return 0;
    }
  }
  return 0xffffff32;
}


