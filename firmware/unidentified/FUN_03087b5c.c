/**
 * FUN_03087b5c @ 0x03087b5c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03087b5c(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  int local_38;
  int local_30;
  
  if (*(short *)(param_1 + 0x188) == 2) {
    iVar8 = *(int *)(param_1 + 0xd8) + **(short **)(param_1 + 0x18c) * 0xfc;
    iVar19 = *(int *)(param_1 + 0xd8) + (*(short **)(param_1 + 0x18c))[1] * 0xfc;
    iVar4 = (int)*(short *)(iVar8 + 0x84);
    if ((*(int *)(param_1 + 0x40) < 3) || (iVar4 == *(short *)(iVar19 + 0x84))) {
      iVar6 = *(int *)(iVar8 + 0x54);
      iVar5 = *(int *)(iVar8 + 0x58);
      iVar18 = *(int *)(iVar8 + 0x5c);
      local_38 = *(int *)(iVar8 + 0x60);
      iVar23 = (int)*(short *)(iVar8 + 0x86);
      iVar10 = *(int *)(iVar8 + 100);
      puVar13 = *(undefined4 **)(iVar8 + 0x44);
      puVar11 = *(undefined4 **)(iVar19 + 0x44);
      if (puVar13 == (undefined4 *)0x0 || puVar11 == (undefined4 *)0x0) {
        return 0;
      }
      puVar15 = puVar13 + iVar23;
      iVar21 = iVar23 / 2;
      puVar16 = puVar11 + iVar23;
      if (0 < iVar21) {
        do {
          puVar15 = puVar15 + -1;
          puVar16 = puVar16 + -1;
          uVar22 = *puVar13;
          *puVar13 = *puVar15;
          *puVar15 = uVar22;
          uVar22 = *puVar11;
          *puVar11 = *puVar16;
          *puVar16 = uVar22;
          iVar21 = iVar21 + -1;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        } while (iVar21 != 0);
      }
      iVar21 = iVar4 / 2;
      piVar17 = (int *)(*(int *)(iVar8 + 0x44) + iVar21 * -4);
      iVar20 = (iVar23 / 2) * 4 + -4;
      piVar9 = (int *)(*(int *)(iVar19 + 0x44) + iVar21 * -4);
      piVar12 = (int *)(*(int *)(iVar8 + 0x44) + iVar20);
      piVar14 = (int *)(*(int *)(iVar19 + 0x44) + iVar20);
      if (iVar23 < iVar4) {
        iVar4 = (iVar4 - iVar23) / 2;
        piVar17 = piVar17 + iVar4;
        piVar9 = piVar9 + iVar4;
        iVar21 = iVar23 / 2;
      }
      else {
        iVar4 = (iVar23 - iVar4) / 2;
        piVar12 = piVar12 + -iVar4;
        piVar14 = piVar14 + -iVar4;
      }
      iVar4 = 0;
      if (0 < iVar21) {
        do {
          iVar19 = iVar6;
          iVar8 = iVar5;
          iVar6 = *piVar17;
          iVar5 = *piVar12;
          lVar1 = (longlong)-iVar19 * (longlong)iVar5;
          lVar2 = (longlong)iVar8 * (longlong)iVar6;
          iVar4 = iVar4 + 1;
          *piVar17 = (int)(((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) +
                          ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2)) >>
                     *(sbyte *)(param_1 + 0x1c8);
          lVar1 = (longlong)iVar19 * (longlong)iVar6;
          lVar2 = (longlong)iVar8 * (longlong)iVar5;
          *piVar12 = (int)(((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) +
                          ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2)) >>
                     *(sbyte *)(param_1 + 0x1c8);
          iVar5 = *piVar14;
          iVar6 = *piVar9;
          lVar1 = (longlong)-iVar19 * (longlong)iVar5;
          lVar2 = (longlong)iVar8 * (longlong)iVar6;
          *piVar9 = (int)(((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) +
                         ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2)) >>
                    *(sbyte *)(param_1 + 0x1c8);
          lVar1 = (longlong)iVar19 * (longlong)iVar6;
          lVar2 = (longlong)iVar8 * (longlong)iVar5;
          *piVar14 = (int)(((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) +
                          ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2)) >>
                     *(sbyte *)(param_1 + 0x1c8);
          lVar1 = (longlong)iVar10 * (longlong)iVar8;
          lVar2 = (longlong)iVar10 * (longlong)iVar19;
          iVar5 = local_38 - ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2);
          iVar6 = ((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) + iVar18;
          piVar9 = piVar9 + 1;
          piVar12 = piVar12 + -1;
          piVar14 = piVar14 + -1;
          piVar17 = piVar17 + 1;
          iVar18 = iVar19;
          local_38 = iVar8;
        } while (iVar4 < iVar21);
      }
      goto LAB_03087ebe;
    }
  }
  local_38 = 0;
  if (0 < *(short *)(param_1 + 0x188)) {
    do {
      iVar6 = *(int *)(param_1 + 0xd8) + *(short *)(*(int *)(param_1 + 0x18c) + local_38 * 2) * 0xfc
      ;
      iVar18 = (int)*(short *)(iVar6 + 0x86);
      iVar4 = *(int *)(iVar6 + 0x54);
      iVar8 = *(int *)(iVar6 + 0x58);
      iVar19 = *(int *)(iVar6 + 0x5c);
      iVar5 = *(int *)(iVar6 + 0x60);
      iVar10 = *(int *)(iVar6 + 100);
      iVar23 = (int)*(short *)(iVar6 + 0x84);
      if (1 < iVar18) {
        puVar13 = *(undefined4 **)(iVar6 + 0x44) + iVar18;
        iVar21 = iVar18 / 2;
        puVar11 = *(undefined4 **)(iVar6 + 0x44);
        do {
          puVar13 = puVar13 + -1;
          uVar22 = *puVar11;
          *puVar11 = *puVar13;
          *puVar13 = uVar22;
          iVar21 = iVar21 + -1;
          puVar11 = puVar11 + 1;
        } while (iVar21 != 0);
      }
      iVar21 = iVar18 / 2;
      piVar12 = (int *)(*(int *)(iVar6 + 0x44) + (iVar23 / 2) * -4);
      piVar9 = (int *)(*(int *)(iVar6 + 0x44) + iVar21 * 4 + -4);
      if (iVar18 < iVar23) {
        piVar12 = piVar12 + (iVar23 - iVar18) / 2;
      }
      else {
        piVar9 = piVar9 + -((iVar18 - iVar23) / 2);
        iVar21 = iVar23 / 2;
      }
      iVar6 = 0;
      if (0 < iVar21) {
        do {
          iVar23 = iVar8;
          iVar18 = iVar4;
          iVar4 = *piVar9;
          lVar1 = (longlong)-iVar18 * (longlong)iVar4;
          lVar2 = (longlong)iVar23 * (longlong)*piVar12;
          lVar3 = (longlong)iVar18 * (longlong)*piVar12;
          *piVar12 = (int)(((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2) +
                          ((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2)) >>
                     *(sbyte *)(param_1 + 0x1c8);
          lVar1 = (longlong)iVar23 * (longlong)iVar4;
          *piVar9 = (int)(((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) +
                         ((int)((ulonglong)lVar3 >> 0x20) << 2 | (uint)lVar3 >> 0x1e)) >>
                    *(sbyte *)(param_1 + 0x1c8);
          lVar1 = (longlong)iVar10 * (longlong)iVar23;
          lVar2 = (longlong)iVar10 * (longlong)iVar18;
          iVar6 = iVar6 + 1;
          iVar4 = ((uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2) + iVar19;
          iVar8 = iVar5 - ((uint)lVar2 >> 0x1e | (int)((ulonglong)lVar2 >> 0x20) << 2);
          piVar9 = piVar9 + -1;
          iVar19 = iVar18;
          iVar5 = iVar23;
          piVar12 = piVar12 + 1;
        } while (iVar6 < iVar21);
      }
      local_38 = (int)(short)((short)local_38 + 1);
    } while (local_38 < *(short *)(param_1 + 0x188));
  }
LAB_03087ebe:
  iVar4 = 0;
  if (0 < *(short *)(param_1 + 0x188)) {
    do {
      iVar19 = *(int *)(param_1 + 0xd8) + *(short *)(*(int *)(param_1 + 0x18c) + iVar4 * 2) * 0xfc;
      iVar6 = (int)*(short *)(iVar19 + 0x84);
      iVar8 = (int)*(short *)(iVar19 + 0x86);
      iVar5 = (int)*(short *)(iVar19 + 0x88);
      if (iVar6 < iVar8) {
        iVar6 = iVar6 - (iVar6 >> 0x1f);
      }
      else {
        iVar6 = iVar8 - (iVar8 >> 0x1f);
      }
      if (iVar8 < iVar5) {
        iVar5 = iVar8 - (iVar8 >> 0x1f);
      }
      else {
        iVar5 = iVar5 - (iVar5 >> 0x1f);
      }
      if (*(int *)(param_1 + 0x40) < 3) {
        local_30 = iVar8 - (iVar5 >> 1);
      }
      uVar7 = local_30 - (iVar6 >> 1);
      if (0 < (int)uVar7) {
        piVar12 = (int *)(*(int *)(iVar19 + 0x44) + (iVar6 >> 1) * 4);
        piVar9 = piVar12 + -1;
        if ((uVar7 & 1) != 0) {
          *piVar12 = *piVar12 >> *(sbyte *)(param_1 + 0x1c8);
          piVar9 = piVar12;
        }
        for (iVar8 = (int)uVar7 >> 1; iVar8 != 0; iVar8 = iVar8 + -1) {
          piVar9[1] = piVar9[1] >> *(sbyte *)(param_1 + 0x1c8);
          piVar9 = piVar9 + 2;
          *piVar9 = *piVar9 >> *(sbyte *)(param_1 + 0x1c8);
        }
      }
      iVar4 = (int)(short)((short)iVar4 + 1);
    } while (iVar4 < *(short *)(param_1 + 0x188));
  }
  return 0;
}


