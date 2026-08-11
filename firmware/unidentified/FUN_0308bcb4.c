/**
 * FUN_0308bcb4 @ 0x0308bcb4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308bcb4(int param_1,int *param_2,int param_3)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int local_138;
  int local_134 [5];
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  uint local_108;
  int local_100;
  uint *local_ec;
  int local_e8;
  int local_e4;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int iStack_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  int *piStack_2c;
  int local_28;
  
  iVar3 = DAT_0308bed0;
  local_ec = *(uint **)(param_3 + 0x40);
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar11 = *(int *)(param_1 + 0x9c);
  }
  else {
    iVar11 = (int)*(short *)(param_3 + 0x80);
  }
  iStack_30 = param_1;
  piStack_2c = param_2;
  local_28 = param_3;
  wma_floor_log2(0x800 / iVar11);
  local_d4 = iVar11 >> 1;
  local_e4 = iVar11 >> 2;
  local_e8 = iVar11 >> 3;
  local_d8 = iVar11 >> 4;
  piVar8 = &local_138;
  local_138 = -(*param_2 >> 2);
  iVar18 = param_2[1];
  iVar9 = 4;
  piVar2 = param_2;
  do {
    iVar4 = piVar2[2];
    piVar8[1] = -(iVar18 >> 2);
    iVar18 = piVar2[3];
    piVar8 = piVar8 + 2;
    *piVar8 = -(iVar4 >> 2);
    puVar7 = local_ec;
    iVar9 = iVar9 + -1;
    piVar2 = piVar2 + 2;
  } while (iVar9 != 0);
  local_114 = -(param_2[9] >> 2);
  iVar4 = local_11c + 0x2000000;
  uVar5 = (uint)((longlong)DAT_0308bed4 * (longlong)local_134[2]) >> 0x1e |
          (int)((ulonglong)((longlong)DAT_0308bed4 * (longlong)local_134[2]) >> 0x20) << 2;
  local_90 = iVar4 + uVar5;
  iStack_4c = iVar4 - uVar5;
  local_8c = 0x2000000 - local_11c;
  local_70 = local_134[2] + local_8c;
  local_6c = local_8c - local_134[2];
  iVar18 = local_134[0] + local_114;
  uVar5 = (uint)((longlong)DAT_0308bed4 * (longlong)local_134[4]) >> 0x1e |
          (int)((ulonglong)((longlong)DAT_0308bed4 * (longlong)local_134[4]) >> 0x20) << 2;
  local_a8 = iVar18 + uVar5;
  local_64 = iVar18 - uVar5;
  local_a4 = local_134[0] + (param_2[9] >> 2);
  local_84 = local_a4 - local_134[4];
  local_88 = local_134[4] + local_a4;
  iVar9 = local_138 + local_118;
  uVar5 = (uint)((longlong)DAT_0308bed4 * (longlong)local_134[3]) >> 0x1e |
          (int)((ulonglong)((longlong)DAT_0308bed4 * (longlong)local_134[3]) >> 0x20) << 2;
  local_a0 = iVar9 + uVar5;
  local_5c = iVar9 - uVar5;
  local_9c = local_138 - local_118;
  local_80 = local_134[3] + local_9c;
  local_7c = local_9c - local_134[3];
  uVar5 = (uint)((longlong)DAT_0308bed4 * (longlong)local_120) >> 0x1e |
          (int)((ulonglong)((longlong)DAT_0308bed4 * (longlong)local_120) >> 0x20) << 2;
  local_98 = local_134[1] + uVar5;
  local_78 = local_134[1] + local_120;
  local_58 = local_134[1];
  local_54 = local_134[1] - uVar5;
  local_74 = local_134[1] - local_120;
  local_94 = local_134[1];
  iVar13 = local_134[2] + iVar4;
  iVar4 = iVar4 - local_134[2];
  iVar12 = local_134[4] + iVar18;
  lVar1 = (longlong)iVar3 * (longlong)((iVar9 - (local_134[3] - local_120)) - local_134[1]);
  uVar15 = (uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2;
  local_100 = iVar4 - uVar15;
  lVar1 = (longlong)iVar3 * (longlong)((iVar9 - (local_134[3] + local_120)) + local_134[1]);
  uVar6 = (uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2;
  iVar16 = ((local_134[3] - local_120) + iVar9) - local_134[1];
  iVar3 = iVar18 - local_134[4];
  iVar18 = local_134[4] - iVar18;
  local_68 = local_a4;
  local_60 = local_9c;
  local_50 = local_8c;
  uVar5 = FUN_0308ba56(local_134[1] + iVar9 + local_134[3] + local_120 + iVar13 + iVar12,0);
  *puVar7 = uVar5;
  puVar7 = puVar7 + local_e4;
  uVar5 = FUN_0308ba56(iVar4 + uVar15,iVar3 + uVar6);
  *puVar7 = uVar5;
  puVar7 = puVar7 + local_e4;
  uVar5 = FUN_0308ba56(iVar13 - iVar12,iVar16);
  *puVar7 = uVar5;
  puVar7 = puVar7 + local_e4;
  uVar5 = FUN_0308ba56(local_100,iVar18 + uVar6);
  *puVar7 = uVar5;
  FUN_0308bafc(local_d8,&local_a8,local_ec,local_d4,DAT_0308bedc,DAT_0308bed8);
  FUN_0308bafc(local_e8,&local_88,local_ec,local_d4,DAT_0308bee4,DAT_0308bee0);
  FUN_0308bafc(local_e8 + local_d8,&local_68,local_ec,local_d4,DAT_0308c2a8,DAT_0308c2a4);
  iVar4 = 1;
  iVar18 = *(int *)(DAT_0308c2ac + (iVar11 >> 7) * 4);
  local_3c = 0;
  local_38 = 0x40000000;
  local_44 = *(int *)(iVar18 + 0x2c) << 1;
  local_40 = 0;
  local_34 = 0x40000000;
  local_48 = *(int *)(iVar18 + 0x28) >> 1;
  iVar3 = *(int *)(iVar18 + 0x2c);
  iVar11 = *(int *)(iVar18 + 0x14) >> 1;
  iVar9 = *(int *)(iVar18 + 0x10) >> 1;
  iVar18 = *(int *)(iVar18 + 0x30);
  if (1 < local_d8) {
    do {
      iVar16 = iVar9;
      iVar13 = iVar11;
      iVar9 = ((uint)((longlong)iVar18 * (longlong)iVar3) >> 0x1e |
              (int)((ulonglong)((longlong)iVar18 * (longlong)iVar3) >> 0x20) << 2) * 2;
      iVar11 = ((uint)((longlong)iVar3 * (longlong)iVar3) >> 0x1e |
               (int)((ulonglong)((longlong)iVar3 * (longlong)iVar3) >> 0x20) << 2) * -2 + 0x40000000
      ;
      iVar17 = iVar9 - iVar11;
      iVar11 = iVar11 + iVar9;
      iVar14 = iVar3 - iVar18;
      iVar19 = iVar18 + iVar3;
      iVar12 = local_38 -
               ((uint)((longlong)local_44 * (longlong)iVar3) >> 0x1e |
               (int)((ulonglong)((longlong)local_44 * (longlong)iVar3) >> 0x20) << 2);
      iVar9 = ((uint)((longlong)local_44 * (longlong)iVar18) >> 0x1e |
              (int)((ulonglong)((longlong)local_44 * (longlong)iVar18) >> 0x20) << 2) + local_3c;
      uVar15 = (uint)((longlong)iVar11 * (longlong)local_11c) >> 0x1e |
               (int)((ulonglong)((longlong)iVar11 * (longlong)local_11c) >> 0x20) << 2;
      uVar6 = (uint)((longlong)iVar19 * (longlong)local_134[2]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar19 * (longlong)local_134[2]) >> 0x20) << 2;
      local_b0 = uVar15 + uVar6 + 0x2000000;
      uVar10 = (uint)((longlong)iVar17 * (longlong)local_11c) >> 0x1e |
               (int)((ulonglong)((longlong)iVar17 * (longlong)local_11c) >> 0x20) << 2;
      local_90 = uVar10 + uVar6 + 0x2000000;
      uVar5 = (uint)((longlong)iVar14 * (longlong)local_134[2]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar14 * (longlong)local_134[2]) >> 0x20) << 2;
      local_70 = (0x2000000 - uVar15) - uVar5;
      local_50 = (0x2000000 - uVar10) + uVar5;
      iStack_4c = (uVar15 - uVar6) + 0x2000000;
      local_6c = (uVar10 - uVar6) + 0x2000000;
      local_8c = (0x2000000 - uVar15) + uVar5;
      local_ac = (0x2000000 - uVar10) - uVar5;
      uVar15 = (uint)((longlong)iVar11 * (longlong)local_114) >> 0x1e |
               (int)((ulonglong)((longlong)iVar11 * (longlong)local_114) >> 0x20) << 2;
      uVar6 = (uint)((longlong)iVar19 * (longlong)local_134[4]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar19 * (longlong)local_134[4]) >> 0x20) << 2;
      local_c8 = local_134[0] + uVar15 + uVar6;
      uVar10 = (uint)((longlong)iVar17 * (longlong)local_114) >> 0x1e |
               (int)((ulonglong)((longlong)iVar17 * (longlong)local_114) >> 0x20) << 2;
      local_a8 = local_134[0] + uVar10 + uVar6;
      uVar5 = (uint)((longlong)iVar14 * (longlong)local_134[4]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar14 * (longlong)local_134[4]) >> 0x20) << 2;
      local_cc = local_134[0] - uVar15;
      local_88 = local_cc - uVar5;
      local_d0 = local_134[0] - uVar10;
      local_68 = local_d0 + uVar5;
      local_64 = (uVar15 + local_134[0]) - uVar6;
      local_84 = (local_134[0] + uVar10) - uVar6;
      local_a4 = local_cc + uVar5;
      local_c4 = local_d0 - uVar5;
      uVar15 = (uint)((longlong)iVar11 * (longlong)local_118) >> 0x1e |
               (int)((ulonglong)((longlong)iVar11 * (longlong)local_118) >> 0x20) << 2;
      uVar5 = (uint)((longlong)iVar19 * (longlong)local_134[3]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar19 * (longlong)local_134[3]) >> 0x20) << 2;
      local_c0 = local_138 + uVar15 + uVar5;
      uVar10 = (uint)((longlong)iVar17 * (longlong)local_118) >> 0x1e |
               (int)((ulonglong)((longlong)iVar17 * (longlong)local_118) >> 0x20) << 2;
      local_a0 = local_138 + uVar10 + uVar5;
      uVar6 = (uint)((longlong)iVar14 * (longlong)local_134[3]) >> 0x1e |
              (int)((ulonglong)((longlong)iVar14 * (longlong)local_134[3]) >> 0x20) << 2;
      local_80 = (local_138 - uVar15) - uVar6;
      local_60 = (local_138 - uVar10) + uVar6;
      local_5c = (uVar15 + local_138) - uVar5;
      local_7c = (local_138 + uVar10) - uVar5;
      local_9c = (local_138 - uVar15) + uVar6;
      local_bc = (local_138 - uVar10) - uVar6;
      uVar5 = (uint)((longlong)iVar19 * (longlong)local_120) >> 0x1e |
              (int)((ulonglong)((longlong)iVar19 * (longlong)local_120) >> 0x20) << 2;
      local_b8 = local_134[1] + uVar5;
      uVar6 = (uint)((longlong)iVar14 * (longlong)local_120) >> 0x1e |
              (int)((ulonglong)((longlong)iVar14 * (longlong)local_120) >> 0x20) << 2;
      local_74 = local_134[1] - uVar5;
      local_b4 = local_134[1] - uVar6;
      local_94 = uVar6 + local_134[1];
      local_98 = local_b8;
      local_78 = local_b4;
      local_58 = local_94;
      local_54 = local_74;
      local_3c = iVar3;
      local_38 = iVar18;
      FUN_0308bafc(iVar4,&local_c8,local_ec,local_d4,iVar16,iVar13);
      uVar15 = (uint)((longlong)DAT_0308c2b0 * (longlong)iVar13) >> 0x1e |
               (int)((ulonglong)((longlong)DAT_0308c2b0 * (longlong)iVar13) >> 0x20) << 2;
      local_108 = (uint)((longlong)DAT_0308c2b4 * (longlong)iVar16) >> 0x1e |
                  (int)((ulonglong)((longlong)DAT_0308c2b4 * (longlong)iVar16) >> 0x20) << 2;
      uVar6 = (uint)((longlong)DAT_0308c2b4 * (longlong)iVar13) >> 0x1e |
              (int)((ulonglong)((longlong)DAT_0308c2b4 * (longlong)iVar13) >> 0x20) << 2;
      uVar5 = (uint)((longlong)DAT_0308c2b0 * (longlong)iVar16) >> 0x1e |
              (int)((ulonglong)((longlong)DAT_0308c2b0 * (longlong)iVar16) >> 0x20) << 2;
      FUN_0308bafc(local_e8 - iVar4,&local_a8,local_ec,local_d4,uVar15 - local_108,uVar6 + uVar5);
      FUN_0308bafc(local_e8 + iVar4,&local_88,local_ec,local_d4,local_108 + uVar15,uVar6 - uVar5);
      uVar5 = (uint)((longlong)DAT_0308c2b8 * (longlong)iVar13) >> 0x1e |
              (int)((ulonglong)((longlong)DAT_0308c2b8 * (longlong)iVar13) >> 0x20) << 2;
      uVar6 = (uint)((longlong)DAT_0308c2b8 * (longlong)iVar16) >> 0x1e |
              (int)((ulonglong)((longlong)DAT_0308c2b8 * (longlong)iVar16) >> 0x20) << 2;
      FUN_0308bafc(local_e4 - iVar4,&local_68,local_ec,local_d4,uVar5 - uVar6,uVar5 + uVar6);
      iVar4 = iVar4 + 1;
      iVar3 = iVar9;
      iVar11 = local_34 -
               ((uint)((longlong)local_48 * (longlong)iVar16) >> 0x1e |
               (int)((ulonglong)((longlong)local_48 * (longlong)iVar16) >> 0x20) << 2);
      iVar9 = ((uint)((longlong)local_48 * (longlong)iVar13) >> 0x1e |
              (int)((ulonglong)((longlong)local_48 * (longlong)iVar13) >> 0x20) << 2) + local_40;
      iVar18 = iVar12;
      local_40 = iVar16;
      local_34 = iVar13;
    } while (iVar4 < local_d8);
  }
  uVar5 = 0;
  uVar6 = (uint)*(short *)(local_28 + 0x80);
  if (0 < (int)(uVar6 - 1)) {
    puVar7 = local_ec + -1;
    if (((uVar6 & 1) == 0) && (puVar7 = local_ec, *local_ec != 0)) {
      uVar5 = *local_ec;
    }
    uVar15 = puVar7[1];
    for (iVar3 = (int)(uVar6 - 1) >> 1; iVar3 != 0; iVar3 = iVar3 + -1) {
      uVar10 = puVar7[2];
      if (uVar5 < uVar15) {
        uVar5 = uVar15;
      }
      uVar15 = puVar7[3];
      if (uVar5 < uVar10) {
        uVar5 = uVar10;
      }
      puVar7 = puVar7 + 2;
    }
  }
  if ((-1 < (int)(uVar6 - 1)) && (uVar5 < local_ec[uVar6 - 1])) {
    uVar5 = local_ec[uVar6 - 1];
  }
  *(uint *)(local_28 + 0xa4) = uVar5;
  return 0;
}


