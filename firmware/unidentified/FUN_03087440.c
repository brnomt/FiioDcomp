/**
 * FUN_03087440 @ 0x03087440
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030875a2) */

void FUN_03087440(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int local_c0;
  int local_a4;
  int local_94;
  int local_80;
  int local_78;
  int local_60;
  int local_54;
  int local_50;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  iVar10 = 1 << (param_2 & 0xff);
  iVar6 = iVar10 * 2;
  local_48 = DAT_03087850;
  if (2 < iVar10) {
    iVar16 = iVar10 / 2;
    iVar7 = 0;
    iVar22 = 0;
    while( true ) {
      iVar1 = param_1 + iVar22 * 4;
      puVar15 = (undefined4 *)(param_1 + (iVar7 + iVar10) * 4);
      uVar17 = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar1 + 8) = *puVar15;
      *puVar15 = uVar17;
      uVar17 = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = puVar15[1];
      puVar15[1] = uVar17;
      iVar1 = iVar16;
      if (iVar16 <= iVar7) {
        do {
          iVar7 = iVar7 - iVar1;
          iVar1 = iVar1 >> 1;
        } while (iVar1 <= iVar7);
      }
      iVar22 = iVar22 + 4;
      iVar7 = iVar7 + iVar1;
      if (iVar10 <= iVar22) break;
      if (iVar22 < iVar7) {
        puVar15 = (undefined4 *)(param_1 + iVar22 * 4);
        puVar13 = (undefined4 *)(param_1 + iVar7 * 4);
        uVar17 = *puVar15;
        *puVar15 = *puVar13;
        puVar14 = puVar13 + 1;
        *puVar13 = uVar17;
        uVar17 = puVar15[1];
        puVar15[1] = *puVar14;
        *puVar14 = uVar17;
        puVar15 = puVar15 + 1 + iVar10 + 1;
        puVar14 = puVar14 + iVar10 + 1;
        uVar17 = *puVar15;
        *puVar15 = *puVar14;
        *puVar14 = uVar17;
        uVar17 = puVar15[1];
        puVar15[1] = puVar14[1];
        puVar14[1] = uVar17;
      }
    }
  }
  iVar7 = 8;
  iVar16 = 0;
  if (0 < iVar6) {
    do {
      piVar2 = (int *)(param_1 + iVar16 * 4);
      iVar16 = ((iVar6 - iVar16) + iVar7 + -1) / iVar7;
      piVar8 = piVar2 + 2;
      if (0 < iVar16) {
        do {
          iVar22 = *piVar2;
          iVar1 = *piVar8;
          *piVar2 = iVar22 + iVar1;
          *piVar8 = iVar22 - iVar1;
          iVar22 = piVar2[1];
          iVar1 = piVar8[1];
          piVar2[1] = iVar22 + iVar1;
          piVar8[1] = iVar22 - iVar1;
          piVar2 = piVar2 + iVar7;
          piVar8 = piVar8 + iVar7;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      iVar16 = iVar7 * 2 + -4;
      iVar7 = iVar7 << 2;
    } while (iVar16 < iVar6);
  }
  local_80 = 2;
  local_94 = param_2 - 2;
  do {
    iVar1 = local_80 * 2 >> 2;
    iVar3 = iVar1 << 4;
    iVar11 = iVar3 >> 1;
    iVar22 = local_80 << 4;
    iVar7 = iVar11 + iVar10 * -2;
    iVar16 = iVar11;
    while (iVar16 < iVar6) {
      if (iVar7 < 0 != SBORROW4(iVar16,iVar6)) {
        do {
          if (0 < iVar11) {
            piVar2 = (int *)(param_1 + iVar16 * 4 + -4);
            for (iVar7 = iVar3 >> 2; iVar7 != 0; iVar7 = iVar7 + -1) {
              piVar2[1] = piVar2[1] >> 1;
              piVar8 = piVar2 + 2;
              piVar2 = piVar2 + 2;
              *piVar2 = *piVar8 >> 1;
            }
          }
          iVar16 = iVar16 + iVar22;
        } while (iVar16 < iVar6);
      }
      iVar16 = iVar22 * 2 - iVar11;
      iVar22 = iVar22 << 2;
      iVar7 = iVar16 + iVar10 * -2;
    }
    iVar7 = 0;
    iVar16 = iVar3;
    if (0 < iVar6) {
      do {
        piVar2 = (int *)(param_1 + iVar7 * 4);
        piVar8 = piVar2 + local_80;
        piVar4 = piVar8 + local_80;
        iVar22 = iVar16 + -1;
        piVar5 = piVar4 + local_80;
        for (; iVar7 < iVar6 + -7; iVar7 = iVar7 + iVar16) {
          iVar11 = (*piVar4 >> 1) + (*piVar5 >> 1);
          iVar18 = (*piVar4 >> 1) - (*piVar5 >> 1);
          iVar19 = (piVar4[1] >> 1) + (piVar5[1] >> 1);
          iVar20 = (piVar4[1] >> 1) - (piVar5[1] >> 1);
          iVar21 = *piVar2;
          *piVar4 = (iVar21 >> 1) - iVar11;
          piVar9 = piVar2 + 1;
          *piVar2 = iVar11 + (iVar21 >> 1);
          iVar11 = *piVar8;
          *piVar5 = (iVar11 >> 1) - iVar20;
          piVar12 = piVar8 + 1;
          *piVar8 = (iVar11 >> 1) + iVar20;
          iVar11 = *piVar9;
          piVar4[1] = (iVar11 >> 1) - iVar19;
          *piVar9 = (iVar11 >> 1) + iVar19;
          iVar11 = *piVar12;
          piVar2 = piVar9 + iVar22;
          piVar5[1] = (iVar11 >> 1) + iVar18;
          *piVar12 = (iVar11 >> 1) - iVar18;
          piVar8 = piVar12 + iVar22;
          piVar4 = piVar4 + 1 + iVar22;
          piVar5 = piVar5 + 1 + iVar22;
        }
        iVar7 = (iVar16 + local_80 * -2) * 2;
        iVar16 = iVar16 << 2;
      } while (iVar7 < iVar6);
    }
    if (1 < iVar1) {
      local_50 = *local_48;
      if (local_50 == 0) {
        local_50 = 0;
        local_60 = 0x3fffffff;
        local_54 = 0;
        local_44 = 0;
        local_40 = 0x3fffffff;
        local_78 = 0;
      }
      else {
        local_60 = local_48[1];
        local_54 = local_48[2];
        local_44 = local_48[3];
        local_40 = local_48[4];
        local_78 = local_48[5];
        local_48 = local_48 + 6;
      }
      local_30 = 0x3fffffff;
      local_34 = 0x3fffffff;
      local_38 = 0;
      local_3c = 0;
      local_c0 = 1;
      do {
        iVar7 = local_c0 * 2;
        if (iVar7 < iVar6) {
          local_a4 = iVar3;
          do {
            piVar2 = (int *)(param_1 + iVar7 * 4);
            piVar8 = piVar2 + local_80;
            piVar4 = piVar8 + local_80;
            iVar16 = local_a4 + -1;
            piVar5 = piVar4 + local_80;
            for (; iVar7 < iVar6 + -7; iVar7 = iVar7 + local_a4) {
              iVar11 = (int)((ulonglong)((longlong)(local_60 << 1) * (longlong)*piVar4) >> 0x20) +
                       (int)((ulonglong)((longlong)(local_54 << 1) * (longlong)piVar4[1]) >> 0x20);
              iVar22 = (int)((ulonglong)((longlong)(local_60 << 1) * (longlong)piVar4[1]) >> 0x20) -
                       (int)((ulonglong)((longlong)(local_54 << 1) * (longlong)*piVar4) >> 0x20);
              iVar19 = (int)((ulonglong)((longlong)(local_40 << 1) * (longlong)*piVar5) >> 0x20) +
                       (int)((ulonglong)((longlong)(local_78 << 1) * (longlong)piVar5[1]) >> 0x20);
              iVar18 = (int)((ulonglong)((longlong)(local_40 << 1) * (longlong)piVar5[1]) >> 0x20) -
                       (int)((ulonglong)((longlong)(local_78 << 1) * (longlong)*piVar5) >> 0x20);
              iVar20 = *piVar2;
              iVar21 = iVar11 + iVar19;
              *piVar4 = (iVar20 >> 1) - iVar21;
              *piVar2 = (iVar20 >> 1) + iVar21;
              iVar20 = *piVar8;
              iVar21 = iVar22 - iVar18;
              *piVar5 = (iVar20 >> 1) - iVar21;
              piVar9 = piVar8 + 1;
              *piVar8 = (iVar20 >> 1) + iVar21;
              iVar22 = iVar22 + iVar18;
              iVar18 = piVar2[1];
              piVar4[1] = (iVar18 >> 1) - iVar22;
              piVar2[1] = iVar22 + (iVar18 >> 1);
              iVar11 = iVar11 - iVar19;
              iVar22 = *piVar9;
              piVar2 = piVar2 + 1 + iVar16;
              piVar5[1] = (iVar22 >> 1) + iVar11;
              *piVar9 = (iVar22 >> 1) - iVar11;
              piVar8 = piVar9 + iVar16;
              piVar4 = piVar4 + 1 + iVar16;
              piVar5 = piVar5 + 1 + iVar16;
            }
            iVar7 = (local_c0 + local_a4 + local_80 * -2) * 2;
            local_a4 = local_a4 << 2;
          } while (iVar7 < iVar6);
        }
        if (local_c0 + 1 < iVar1) {
          iVar16 = local_3c +
                   ((uint)((longlong)local_50 * (longlong)local_60) >> 0x1e |
                   (int)((ulonglong)((longlong)local_50 * (longlong)local_60) >> 0x20) << 2);
          iVar11 = local_34 -
                   ((uint)((longlong)local_50 * (longlong)local_54) >> 0x1e |
                   (int)((ulonglong)((longlong)local_50 * (longlong)local_54) >> 0x20) << 2);
          iVar22 = local_38 +
                   ((uint)((longlong)local_44 * (longlong)local_40) >> 0x1e |
                   (int)((ulonglong)((longlong)local_44 * (longlong)local_40) >> 0x20) << 2);
          iVar7 = local_30 -
                  ((uint)((longlong)local_44 * (longlong)local_78) >> 0x1e |
                  (int)((ulonglong)((longlong)local_44 * (longlong)local_78) >> 0x20) << 2);
          local_3c = local_54;
          local_34 = local_60;
          local_38 = local_78;
          local_30 = local_40;
          local_78 = iVar22;
          local_60 = iVar11;
          local_54 = iVar16;
          local_40 = iVar7;
        }
        local_c0 = local_c0 + 1;
      } while (local_c0 < iVar1);
    }
    local_94 = local_94 + -1;
    local_80 = local_80 * 2;
  } while (local_94 != -1);
  return;
}


