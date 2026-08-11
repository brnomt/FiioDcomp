/**
 * FUN_0308b604 @ 0x0308b604
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0308b604(undefined4 param_1,int param_2,int *param_3,int *param_4,int param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int aiStack_374 [101];
  int local_1e0 [99];
  int iStack_54;
  int local_50;
  int local_4c [6];
  undefined4 uStack_34;
  int local_30;
  int *local_2c;
  int *piStack_28;
  
  piStack_28 = param_4;
  local_2c = param_3;
  local_30 = param_2;
  uStack_34 = param_1;
  piVar5 = aiStack_374 + 1;
  piVar7 = aiStack_374 + 1;
  local_4c[1] = 0x40000000;
  local_50 = 0x40000000;
  aiStack_374[2] = 0x8000000;
  aiStack_374[1] = 0x8000000;
  local_4c[2] = 0;
  iVar11 = 2;
  if (0 < param_5) {
    do {
      uVar12 = 0;
      local_4c[0] = *(undefined4 *)
                     (*DAT_0308ba28 + local_4c[2] * 0x40 +
                     (uint)*(byte *)(local_30 + local_4c[2]) * 4);
      do {
        if (iVar11 <= (int)uVar12) break;
        uVar3 = 0;
        local_1e0[uVar12] = 0;
        if (0 < (int)(uVar12 + 1)) {
          piVar4 = aiStack_374 + uVar12 + 2;
          piVar6 = &iStack_54;
          if ((uVar12 & 1) == 0) {
            lVar1 = (longlong)local_50 * (longlong)aiStack_374[uVar12 + 1];
            uVar3 = (uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2;
            piVar4 = aiStack_374 + uVar12 + 1;
            piVar6 = &local_50;
          }
          iVar10 = 0;
          for (iVar2 = (int)(uVar12 + 1) >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
            uVar3 = uVar3 + ((uint)((longlong)piVar6[1] * (longlong)piVar4[-1]) >> 0x1e |
                            (int)((ulonglong)((longlong)piVar6[1] * (longlong)piVar4[-1]) >> 0x20)
                            << 2);
            piVar6 = piVar6 + 2;
            piVar4 = piVar4 + -2;
            iVar10 = iVar10 + ((uint)((longlong)*piVar6 * (longlong)*piVar4) >> 0x1e |
                              (int)((ulonglong)((longlong)*piVar6 * (longlong)*piVar4) >> 0x20) << 2
                              );
          }
          local_1e0[uVar12] = uVar3 + iVar10;
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < 3);
      local_4c[3] = iVar11 + 3;
      for (iVar10 = 3; iVar10 < (iVar11 + 3) / 2; iVar10 = iVar10 + 1) {
        piVar4 = aiStack_374 + iVar10 + 1;
        local_1e0[iVar10] = 0;
        uVar12 = (int)((ulonglong)((longlong)local_50 * (longlong)*piVar4) >> 0x20) << 2 |
                 (uint)((longlong)local_50 * (longlong)*piVar4) >> 0x1e;
        iVar8 = 0;
        iVar2 = 1;
        piVar6 = &local_50;
        do {
          uVar12 = uVar12 + ((uint)((longlong)piVar6[1] * (longlong)piVar4[-1]) >> 0x1e |
                            (int)((ulonglong)((longlong)piVar6[1] * (longlong)piVar4[-1]) >> 0x20)
                            << 2);
          piVar6 = piVar6 + 2;
          piVar4 = piVar4 + -2;
          iVar8 = iVar8 + ((uint)((longlong)*piVar6 * (longlong)*piVar4) >> 0x1e |
                          (int)((ulonglong)((longlong)*piVar6 * (longlong)*piVar4) >> 0x20) << 2);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        local_1e0[iVar10] = uVar12 + iVar8;
      }
      iVar11 = local_4c[3] + -1;
      for (iVar10 = 0; iVar10 < iVar11 / 2; iVar10 = iVar10 + 1) {
        iVar2 = local_1e0[iVar10];
        aiStack_374[iVar10 + 1] = iVar2;
        aiStack_374[iVar11 - iVar10] = iVar2;
      }
      local_4c[2] = local_4c[2] + 2;
    } while (local_4c[2] < param_5);
  }
  local_4c[2] = param_5 - (param_5 >> 0x1f);
  iVar11 = param_5 / 2;
  iVar10 = iVar11 + -1;
  if (0 < iVar10) {
    piVar4 = local_2c;
    if ((local_4c[2] & 2U) == 0) {
      piVar5 = aiStack_374 + 2;
      piVar4 = local_2c + 1;
      *piVar4 = aiStack_374[2];
    }
    iVar8 = piVar5[1];
    for (iVar2 = iVar10 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      iVar9 = piVar5[2];
      piVar4[1] = iVar8;
      iVar8 = piVar5[3];
      piVar4 = piVar4 + 2;
      *piVar4 = iVar9;
      piVar5 = piVar5 + 2;
    }
  }
  if (-1 < iVar10) {
    local_2c[iVar11] = aiStack_374[iVar11 + 1];
  }
  aiStack_374[1] = 0x8000000;
  iVar11 = 3;
  aiStack_374[2] = *(int *)(*DAT_0308ba28 + (uint)*(byte *)(local_30 + 1) * 4 + 0x40) >> 3;
  aiStack_374[3] = 0x8000000;
  local_4c[3] = 3;
  if (3 < param_5) {
    do {
      uVar12 = 0;
      local_4c[0] = *(undefined4 *)
                     (*DAT_0308ba28 + local_4c[3] * 0x40 +
                     (uint)*(byte *)(local_30 + local_4c[3]) * 4);
      do {
        if (iVar11 <= (int)uVar12) break;
        uVar3 = 0;
        local_1e0[uVar12] = 0;
        if (0 < (int)(uVar12 + 1)) {
          piVar5 = aiStack_374 + uVar12 + 2;
          piVar4 = &iStack_54;
          if ((uVar12 & 1) == 0) {
            lVar1 = (longlong)local_50 * (longlong)aiStack_374[uVar12 + 1];
            uVar3 = (uint)lVar1 >> 0x1e | (int)((ulonglong)lVar1 >> 0x20) << 2;
            piVar5 = aiStack_374 + uVar12 + 1;
            piVar4 = &local_50;
          }
          iVar10 = 0;
          for (iVar2 = (int)(uVar12 + 1) >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
            uVar3 = uVar3 + ((uint)((longlong)piVar4[1] * (longlong)piVar5[-1]) >> 0x1e |
                            (int)((ulonglong)((longlong)piVar4[1] * (longlong)piVar5[-1]) >> 0x20)
                            << 2);
            piVar4 = piVar4 + 2;
            piVar5 = piVar5 + -2;
            iVar10 = iVar10 + ((uint)((longlong)*piVar4 * (longlong)*piVar5) >> 0x1e |
                              (int)((ulonglong)((longlong)*piVar4 * (longlong)*piVar5) >> 0x20) << 2
                              );
          }
          local_1e0[uVar12] = uVar3 + iVar10;
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < 3);
      local_4c[4] = iVar11 + 3;
      for (iVar10 = 3; iVar10 < (iVar11 + 3) / 2; iVar10 = iVar10 + 1) {
        piVar5 = aiStack_374 + iVar10 + 1;
        local_1e0[iVar10] = 0;
        uVar12 = (uint)((longlong)local_50 * (longlong)*piVar5) >> 0x1e |
                 (int)((ulonglong)((longlong)local_50 * (longlong)*piVar5) >> 0x20) << 2;
        iVar8 = 0;
        iVar2 = 1;
        piVar4 = &local_50;
        do {
          uVar12 = uVar12 + ((uint)((longlong)piVar4[1] * (longlong)piVar5[-1]) >> 0x1e |
                            (int)((ulonglong)((longlong)piVar4[1] * (longlong)piVar5[-1]) >> 0x20)
                            << 2);
          piVar4 = piVar4 + 2;
          piVar5 = piVar5 + -2;
          iVar8 = iVar8 + ((uint)((longlong)*piVar4 * (longlong)*piVar5) >> 0x1e |
                          (int)((ulonglong)((longlong)*piVar4 * (longlong)*piVar5) >> 0x20) << 2);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        local_1e0[iVar10] = uVar12 + iVar8;
      }
      iVar11 = local_4c[4] + -1;
      for (iVar10 = 0; iVar2 = iVar11 / 2, iVar10 < iVar2; iVar10 = iVar10 + 1) {
        iVar2 = local_1e0[iVar10];
        aiStack_374[iVar10 + 1] = iVar2;
        aiStack_374[iVar11 - iVar10] = iVar2;
      }
      aiStack_374[iVar2 + 1] = local_1e0[iVar2];
      local_4c[3] = local_4c[3] + 2;
    } while (local_4c[3] < param_5);
  }
  if (param_5 < 2) {
    return;
  }
  if ((local_4c[2] & 2U) != 0) {
    piVar7 = aiStack_374 + 2;
    piStack_28 = piStack_28 + 1;
    *piStack_28 = aiStack_374[2] - aiStack_374[1];
    aiStack_374[1] = aiStack_374[2];
  }
  for (iVar11 = local_4c[2] >> 2; iVar11 != 0; iVar11 = iVar11 + -1) {
    iVar10 = piVar7[1];
    piStack_28[1] = iVar10 - aiStack_374[1];
    piVar7 = piVar7 + 2;
    aiStack_374[1] = *piVar7;
    piStack_28 = piStack_28 + 2;
    *piStack_28 = aiStack_374[1] - iVar10;
  }
  return;
}


