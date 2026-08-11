/**
 * FUN_030cb84a @ 0x030cb84a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_030cb84a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            uint param_6,uint param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  uint local_60;
  int local_5c;
  undefined4 uStack_58;
  uint local_54;
  undefined4 local_50;
  uint local_4c;
  int *piStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  local_60 = param_7;
  local_5c = param_8;
  uStack_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  piStack_38 = param_1;
  uStack_34 = param_2;
  local_30 = param_3;
  uStack_2c = param_4;
  lVar9 = CONCAT44(param_8,param_7);
  if ((int)((param_6 - param_8) - (uint)(param_5 < param_7)) < 0 !=
      (SBORROW4(param_6,param_8) != SBORROW4(param_6 - param_8,(uint)(param_5 < param_7)))) {
    do {
      lVar7 = CONCAT44(param_6,param_5);
      if ((int)(uint)((uint)(lVar9 - lVar7) < 0x400) <= (int)((ulonglong)(lVar9 - lVar7) >> 0x20)) {
        lVar7 = FUN_030c0ef0((int)(lVar9 + lVar7),(int)((ulonglong)(lVar9 + lVar7) >> 0x20),2,0);
      }
      if (*param_1 != -1) {
        (*(code *)param_1[0x25])
                  (*param_1,(code *)param_1[0x25],(int)lVar7,(int)((ulonglong)lVar7 >> 0x20),0);
        *(longlong *)(param_1 + 2) = lVar7;
        FUN_030c6c66(param_1[6]);
      }
      lVar8 = FUN_030cb504(param_1,&uStack_58,0xffffffff,0xffffffff);
      iVar4 = (int)((ulonglong)lVar8 >> 0x20);
      uVar10 = (uint)lVar8;
      if (lVar8 == -0x80) {
        return 0xffffff80;
      }
      if ((lVar8 < 0) || (iVar1 = FUN_030c6bc2(&uStack_58), iVar1 != param_9)) {
        if (-1 < lVar8) {
          local_60 = uVar10;
          local_5c = iVar4;
        }
      }
      else {
        param_5 = local_54 + uVar10 + local_4c;
        param_6 = iVar4 + ((int)local_54 >> 0x1f) + (uint)CARRY4(local_54,uVar10) +
                  ((int)local_4c >> 0x1f) + (uint)CARRY4(local_54 + uVar10,local_4c);
        lVar7 = lVar9;
      }
      iVar4 = (int)((ulonglong)lVar7 >> 0x20);
      FUN_030c6e1e(&uStack_58);
      bVar6 = param_5 < (uint)lVar7;
      lVar9 = lVar7;
    } while ((int)((param_6 - iVar4) - (uint)bVar6) < 0 !=
             (SBORROW4(param_6,iVar4) != SBORROW4(param_6 - iVar4,(uint)bVar6)));
  }
  if (*param_1 != -1) {
    (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],local_60,local_5c,0);
    param_1[2] = local_60;
    param_1[3] = local_5c;
    FUN_030c6c66(param_1[6]);
  }
  lVar9 = FUN_030cb504(param_1,&uStack_58,0xffffffff,0xffffffff);
  if (lVar9 == -0x80) {
    return 0xffffff80;
  }
  if (((int)((param_6 - param_8) - (uint)(param_5 < param_7)) < 0 ==
       (SBORROW4(param_6,param_8) != SBORROW4(param_6 - param_8,(uint)(param_5 < param_7)))) ||
     (lVar9 < 0)) {
    FUN_030c6e1e(&uStack_58);
    iVar4 = DAT_030cbbe4;
    param_1[10] = DAT_030cbbe8;
    param_1[7] = param_10 + 1;
    param_1[8] = iVar4;
    puVar2 = (uint *)(iVar4 + param_10 * 8 + 8);
    *puVar2 = param_5;
    puVar2[1] = param_6;
  }
  else {
    uVar3 = FUN_030c6bc2(&uStack_58);
    iVar4 = FUN_030cb84a(param_1,param_1[3],local_60,local_5c,param_1[2],param_1[3],param_7,param_8,
                         uVar3,param_10 + 1);
    FUN_030c6e1e(&uStack_58);
    if (iVar4 == -0x80) {
      return 0xffffff80;
    }
  }
  puVar5 = (undefined4 *)(param_1[8] + param_10 * 8);
  *puVar5 = local_30;
  puVar5[1] = uStack_2c;
  *(int *)(param_1[10] + param_10 * 4) = param_9;
  return 0;
}


