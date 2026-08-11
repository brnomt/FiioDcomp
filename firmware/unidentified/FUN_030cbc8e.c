/**
 * FUN_030cbc8e @ 0x030cbc8e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030cbc8e(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  longlong lVar11;
  longlong lVar12;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int *piStack_38;
  undefined4 uStack_34;
  int local_30;
  int iStack_2c;
  
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  param_1[9] = DAT_030cc0a0;
  param_1[0xb] = DAT_030cc0a4;
  iVar7 = 0;
  piStack_38 = param_1;
  uStack_34 = param_2;
  local_30 = param_3;
  iStack_2c = param_4;
  if (param_1[7] < 1) {
LAB_030cbeb0:
    FUN_030c6e1e(&local_68);
    return;
  }
  do {
    iVar9 = iStack_2c;
    iVar6 = local_30;
    piVar1 = (int *)param_1[9];
    *piVar1 = local_30;
    piVar1[1] = iStack_2c;
    if (*param_1 != -1) {
      (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],local_30,iStack_2c,0);
      param_1[2] = iVar6;
      param_1[3] = iVar9;
      FUN_030c6c66(param_1[6]);
    }
LAB_030cbd4c:
    piVar1 = (int *)(param_1[9] + iVar7 * 8);
    if (*piVar1 != -1 || piVar1[1] != -1) {
      uVar8 = 0;
      iVar6 = 0;
      iVar9 = -1;
      FUN_030c756e(param_1[0x22],*(undefined4 *)(param_1[10] + iVar7 * 4));
      do {
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        FUN_030cb504(param_1,&local_68,0xffffffff,0xffffffff);
        lVar11 = CONCAT44(iVar6,uVar8);
        if ((extraout_r1 < 0) ||
           (iVar2 = FUN_030c6bc2(&local_68), lVar11 = CONCAT44(iVar6,uVar8),
           iVar2 != *(int *)(param_1[10] + iVar7 * 4))) goto LAB_030cbe12;
        lVar11 = FUN_030c6b9c(&local_68);
        FUN_030c7400(param_1[0x22],&local_68);
        iVar2 = iVar9;
        while( true ) {
          iVar9 = iVar2;
          iVar3 = FUN_030c775e(param_1[0x22],&local_58);
          if (iVar3 == 0) break;
          iVar2 = iVar9;
          if ((0 < iVar3) && (iVar2 = FUN_030c415a(param_1 + 0xc,&local_58), iVar9 != -1)) {
            uVar4 = iVar9 + iVar2 >> 2;
            bVar10 = CARRY4(uVar4,uVar8);
            uVar8 = uVar4 + uVar8;
            iVar6 = iVar6 + (iVar9 + iVar2 >> 0x1f) + (uint)bVar10;
          }
        }
        FUN_030c75ac(&local_58);
      } while (lVar11 == -1);
      lVar11 = lVar11 - CONCAT44(iVar6,uVar8);
LAB_030cbe12:
      if (lVar11 < 0) {
        lVar11 = 0;
      }
      *(longlong *)(param_1[0xb] + iVar7 * 0x10) = lVar11;
    }
    piVar1 = (int *)(param_1[8] + iVar7 * 8 + 8);
    iVar6 = *piVar1;
    iVar9 = piVar1[1];
    if (*param_1 != -1) {
      (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],iVar6,iVar9,0);
      param_1[2] = iVar6;
      param_1[3] = iVar9;
      FUN_030c6c66(param_1[6]);
    }
    while (lVar11 = FUN_030cb73a(param_1,&local_68), -1 < lVar11) {
      lVar12 = FUN_030c6b9c(&local_68);
      if (lVar12 != -1) {
        lVar11 = FUN_030c6b9c(&local_68);
        *(longlong *)(param_1[0xb] + iVar7 * 0x10 + 8) =
             lVar11 - *(longlong *)(param_1[0xb] + iVar7 * 0x10);
        goto LAB_030cbea6;
      }
      *(longlong *)(param_1 + 2) = lVar11;
    }
    FUN_030c7b12(param_1 + 0xc);
    FUN_030c7ab4(param_1 + 0x14);
LAB_030cbea6:
    iVar7 = iVar7 + 1;
    if (param_1[7] <= iVar7) goto LAB_030cbeb0;
  } while (iVar7 == 0);
  piVar1 = (int *)(param_1[8] + iVar7 * 8);
  iVar6 = *piVar1;
  iVar9 = piVar1[1];
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],iVar6,iVar9,0);
    param_1[2] = iVar6;
    param_1[3] = iVar9;
    FUN_030c6c66(param_1[6]);
  }
  iVar6 = FUN_030cba38(param_1,param_1 + 0xc,param_1 + 0x14,0,0);
  if (iVar6 < 0) {
    puVar5 = (undefined4 *)(param_1[9] + iVar7 * 8);
    *puVar5 = 0xffffffff;
    puVar5[1] = 0xffffffff;
  }
  else {
    iVar6 = param_1[3];
    piVar1 = (int *)(param_1[9] + iVar7 * 8);
    *piVar1 = param_1[2];
    piVar1[1] = iVar6;
  }
  goto LAB_030cbd4c;
}


