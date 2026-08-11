/**
 * FUN_030cc392 @ 0x030cc392
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030cc392(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  iVar3 = param_1[0x1b];
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  (*(code *)param_1[0x25])(*param_1,(code *)param_1[0x25],0,0);
  iVar1 = (*(code *)param_1[0x27])(*param_1);
  param_1[4] = iVar1;
  param_1[5] = iVar1 >> 0x1f;
  param_1[2] = iVar1;
  param_1[3] = iVar1 >> 0x1f;
  lVar6 = FUN_030cb73a(param_1,&local_38);
  if (lVar6 < 0) {
    return (int)lVar6;
  }
  iVar1 = FUN_030c6bc2(&local_38);
  FUN_030c6e1e(&local_38);
  if (iVar1 == iVar3) {
    uVar7 = FUN_030cb84a(param_1,(int)lVar6 + 1,0,0);
    uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if ((int)uVar7 == 0) goto LAB_030cc448;
  }
  else {
    uVar7 = FUN_030cb84a(param_1,0,0,0);
    uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
    if (-1 < (int)uVar7) {
LAB_030cc448:
      FUN_030cbc8e(param_1,uVar2,uVar4,uVar5);
      iVar1 = FUN_030cc030(param_1,extraout_r1,0,0);
      return iVar1;
    }
  }
  return -0x80;
}


