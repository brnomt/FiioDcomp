/**
 * FUN_0308a5e2 @ 0x0308a5e2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308a5e2(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  undefined8 uVar19;
  uint local_110 [21];
  int local_bc;
  undefined1 *local_b0;
  int local_a4;
  int local_9c;
  int local_98;
  uint *local_94;
  uint uStack_90;
  int local_8c;
  uint local_88;
  uint local_84 [11];
  uint local_58;
  int local_54;
  int local_4c;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int iStack_34;
  int iStack_30;
  int local_2c;
  int iStack_28;
  
  iStack_28 = param_4;
  local_2c = param_3;
  iStack_30 = param_2;
  iStack_34 = param_1;
  local_b0 = *(undefined1 **)(param_2 + 0xc);
  iVar16 = *(int *)(param_2 + 0x10);
  local_9c = *(int *)(param_2 + 4);
  uVar13 = 0;
  if (param_6 == 6) {
LAB_0308a61a:
    bVar17 = true;
  }
  else {
    if (*(int *)(param_1 + 0x40) != 1) {
      iVar1 = *(int *)(param_1 + 0x50);
      bVar18 = SBORROW4(iVar1,32000);
      iVar11 = iVar1 + -32000;
      bVar17 = iVar1 == 32000;
      if (31999 < iVar1) {
        bVar18 = SBORROW4(0xac44,iVar1);
        iVar11 = 0xac44 - iVar1;
        bVar17 = iVar1 == 0xac44;
      }
      if (!bVar17 && iVar11 < 0 == bVar18) goto LAB_0308a61a;
    }
    bVar17 = false;
  }
  iVar1 = 0;
  iVar15 = *(int *)(param_1 + 0x124);
  iVar11 = 0;
  if (!bVar17) {
    local_4c = (*(int *)(param_1 + 0xb0) *
               (((int)*(short *)(param_2 + 0x80) << (param_6 & 0xff)) >> 6)) /
               *(int *)(param_1 + 0x9c);
  }
  local_8c = 1 << (param_6 - 7 & 0xff);
  local_48 = param_6 - 6;
  local_58 = 6 - param_6;
  while( true ) {
    iVar4 = *(int *)(local_2c + iVar15 * 4);
    iVar2 = *(int *)(param_1 + 0x128);
    if (*(int *)(param_1 + 0x128) < iVar4) {
      iVar2 = iVar4;
    }
    iVar4 = *(int *)(param_1 + 0xa8);
    if (iVar4 <= iVar2) break;
    if (local_b0[iVar15] == '\x01') {
      iVar9 = *(int *)(param_4 + iVar11 * 4 + 4);
      while (iVar9 <= (iVar2 << (param_6 & 0xff)) >> 6) {
        iVar11 = iVar11 + 1;
        iVar9 = *(int *)(param_4 + iVar11 * 4 + 4);
      }
      if (bVar17) {
        local_84[uVar13 + 1] = *(uint *)(local_9c + iVar11 * 4);
      }
      else {
        local_bc = *(int *)(local_2c + iVar15 * 4 + 4);
        if (iVar4 < local_bc) {
          local_bc = iVar4;
        }
        iVar4 = *(int *)(param_4 + iVar11 * 4 + 4);
        if (local_4c <= iVar4) {
          iVar4 = local_4c;
        }
        iVar9 = (local_bc << (param_6 & 0xff)) >> 6;
        if (local_4c <= iVar9) {
          iVar9 = local_4c;
        }
        iVar10 = *(int *)(param_4 + iVar1 * 4 + 4);
        while (iVar10 <= iVar9 + -1) {
          iVar1 = iVar1 + 1;
          iVar10 = *(int *)(param_4 + iVar1 * 4 + 4);
        }
        if (iVar1 == iVar11) {
          iVar2 = *(int *)(local_9c + iVar11 * 4);
          if (iVar2 < 1) {
            if (iVar2 < -0x48) {
              iVar2 = -0x47;
            }
            iVar9 = *(int *)(*DAT_0308ab34 + iVar2 * -4);
            iVar4 = -iVar2 >> 2;
          }
          else {
            if (0x3e < iVar2) {
              iVar2 = 0x3e;
            }
            iVar4 = -(iVar2 >> 2);
            iVar9 = *(int *)(*DAT_0308ab38 + iVar2 * 4 + -4);
          }
          local_84[0] = (int)((ulonglong)((longlong)iVar9 * (longlong)iVar9) >> 0x20) << 1;
          local_88 = (iVar4 + 0x1c) * 2 - 0x1f;
          FUN_03087ab8(&local_88,local_84[0],(int)((longlong)iVar9 * (longlong)iVar9));
          uVar7 = local_84[0];
          local_110[uVar13 * 2] = local_88;
          local_110[uVar13 * 2 + 1] = uVar7;
        }
        else {
          if ((int)param_6 < 7) {
            local_84[0] = iVar4 << (local_58 & 0xff);
          }
          else {
            local_84[0] = iVar4 + local_8c >> (local_48 & 0xff);
          }
          iVar4 = *(int *)(local_9c + iVar11 * 4);
          if (iVar4 < 1) {
            if (iVar4 < -0x48) {
              iVar4 = -0x47;
            }
            local_94 = *(uint **)(*DAT_0308ab34 + iVar4 * -4);
            iVar9 = -iVar4 >> 2;
          }
          else {
            if (0x3e < iVar4) {
              iVar4 = 0x3e;
            }
            iVar9 = -(iVar4 >> 2);
            local_94 = *(uint **)(*DAT_0308ab38 + iVar4 * 4 + -4);
          }
          uStack_90 = iVar9 + 0x1c;
          iVar4 = *(int *)(local_9c + iVar1 * 4);
          if (iVar4 < 1) {
            if (iVar4 < -0x48) {
              iVar4 = -0x47;
            }
            local_a4 = *(int *)(*DAT_0308ab34 + iVar4 * -4);
            local_98 = -iVar4 >> 2;
          }
          else {
            if (0x3e < iVar4) {
              iVar4 = 0x3e;
            }
            local_98 = -(iVar4 >> 2);
            local_a4 = *(int *)(*DAT_0308ab38 + iVar4 * 4 + -4);
          }
          local_98 = local_98 + 0x1c;
          local_40 = local_bc - iVar2;
          local_44 = FUN_03082732((local_84[0] - iVar2) * 0x40000000,local_84[0] - iVar2 >> 2,
                                  local_40,0);
          local_54 = FUN_03082732((local_bc - local_84[0]) * 0x40000000,local_bc - local_84[0] >> 2,
                                  local_40,0);
          local_3c = (int)((ulonglong)((longlong)(int)local_94 * (longlong)(int)local_94) >> 0x20)
                     << 1;
          local_40 = uStack_90 * 2 - 0x1f;
          FUN_03087ab8(&local_40,local_3c,(int)((longlong)(int)local_94 * (longlong)(int)local_94));
          local_88 = local_40;
          local_84[0] = (uint)((longlong)local_3c * (longlong)local_44) >> 0x1e |
                        (int)((ulonglong)((longlong)local_3c * (longlong)local_44) >> 0x20) << 2;
          FUN_03087ab8(&local_88);
          local_94 = (uint *)local_84[0];
          uStack_90 = local_88;
          local_3c = (int)((ulonglong)((longlong)local_a4 * (longlong)local_a4) >> 0x20) << 1;
          local_40 = local_98 * 2 - 0x1f;
          FUN_03087ab8(&local_40,(int)((longlong)local_a4 * (longlong)local_a4));
          local_88 = local_40;
          local_84[0] = (int)((ulonglong)((longlong)local_3c * (longlong)local_54) >> 0x20) << 2 |
                        (uint)((longlong)local_3c * (longlong)local_54) >> 0x1e;
          FUN_03087ab8(&local_88);
          uVar7 = uStack_90;
          puVar5 = local_94;
          if (0x3fffffff < (int)local_94) {
            puVar5 = (uint *)((int)local_94 >> 1);
            uVar7 = uStack_90 - 1;
          }
          if (0x3fffffff < (int)local_84[0]) {
            local_84[0] = (int)local_84[0] >> 1;
            local_88 = local_88 - 1;
          }
          if ((int)uVar7 < (int)local_88) {
            local_84[0] = ((int)local_84[0] >> (local_88 - uVar7 & 0xff)) + (int)puVar5;
            local_88 = uVar7;
          }
          else {
            local_84[0] = ((int)puVar5 >> (uVar7 - local_88 & 0xff)) + local_84[0];
          }
          FUN_03087ab8(&local_88);
          uVar7 = local_84[0];
          local_110[uVar13 * 2] = local_88;
          local_110[uVar13 * 2 + 1] = uVar7;
        }
      }
      uVar13 = uVar13 + 1 & 0xff;
    }
    iVar15 = iVar15 + 1;
  }
  iVar11 = 0;
  if (0 < (int)(uVar13 - 1)) {
    local_94 = local_110 + uVar13 * 2;
    do {
      if (bVar17) {
        iVar1 = local_84[iVar11 + 1] - local_84[uVar13];
        if (iVar1 < 1) {
          if (iVar1 < -0x48) {
            iVar1 = -0x47;
          }
          iVar2 = *(int *)(*DAT_0308ab34 + iVar1 * -4);
          iVar15 = -iVar1 >> 2;
        }
        else {
          if (0x3e < iVar1) {
            iVar1 = 0x3e;
          }
          iVar15 = -(iVar1 >> 2);
          iVar2 = *(int *)(*DAT_0308ab38 + iVar1 * 4 + -4);
        }
        piVar8 = (int *)(iVar16 + iVar11 * 8);
        *piVar8 = iVar15 + 0x1c;
        piVar8[1] = iVar2;
      }
      else {
        iVar1 = 0;
        uVar14 = local_110[iVar11 * 2];
        uVar12 = local_94[-2];
        uVar7 = local_94[-1];
        if (uVar7 == 0) {
          uVar7 = 0x7fffffff;
          iVar1 = 0;
        }
        else {
          uVar19 = FUN_030826d0(0,local_110[iVar11 * 2 + 1],uVar7,(int)uVar7 >> 0x1f);
          uVar6 = (uint)((ulonglong)uVar19 >> 0x20);
          uVar3 = (uint)uVar19;
          uVar7 = uVar6;
          if (uVar6 == 0) {
            iVar1 = 0x20;
            uVar7 = uVar3;
          }
          for (; (uVar7 & 0xf0000000) == 0; uVar7 = uVar7 << 4) {
            iVar1 = iVar1 + 4;
          }
          for (; (uVar7 & 0x80000000) == 0; uVar7 = uVar7 << 1) {
            iVar1 = iVar1 + 1;
          }
          iVar15 = iVar1 + 1;
          if (iVar15 < 0x21) {
            uVar7 = FUN_030827aa(uVar3,uVar6,0x20 - iVar15);
          }
          else {
            uVar7 = FUN_0308278c(uVar3,uVar6,iVar1 + -0x1f);
          }
          iVar1 = *(int *)(*DAT_0308ab3c + (uVar7 >> 0x18) * 4);
          uVar7 = (int)((ulonglong)(uVar7 << 8) *
                        (ulonglong)
                        (uint)(*(int *)(*DAT_0308ab3c + ((uVar7 >> 0x18) + 1) * 4) - iVar1) >> 0x20)
                  + iVar1;
          if (((uVar14 + iVar15) - uVar12 & 1) == 0) {
            iVar2 = uVar14 - uVar12;
          }
          else {
            uVar7 = (uint)((ulonglong)uVar7 * (ulonglong)DAT_0308ab40 >> 0x20);
            iVar2 = (uVar14 - uVar12) + -1;
          }
          iVar1 = 0;
          for (uVar7 = uVar7 >> 1; uVar7 < 0x1fffffff; uVar7 = uVar7 << 2) {
            iVar1 = iVar1 + 2;
          }
          if (uVar7 < 0x3fffffff) {
            uVar7 = uVar7 << 1;
            iVar1 = iVar1 + 1;
          }
          iVar1 = iVar1 + iVar15 + (iVar2 >> 1) + -3;
        }
        piVar8 = (int *)(iVar16 + iVar11 * 8);
        *piVar8 = iVar1;
        piVar8[1] = uVar7;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)(uVar13 - 1));
  }
  if (uVar13 != 0) {
    iVar16 = iVar16 + uVar13 * 8;
    *(undefined4 *)(iVar16 + -4) = 0x40000000;
    *(undefined4 *)(iVar16 + -8) = 0x1e;
  }
  *local_b0 = (char)uVar13;
  return;
}


