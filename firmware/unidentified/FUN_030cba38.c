/**
 * FUN_030cba38 @ 0x030cba38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030cba38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_r1;
  longlong lVar4;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_2c = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar1 = *(int *)(param_1 + 0x68);
  if (2 < iVar1) {
    if (iVar1 == 5) {
      FUN_030c3f8e(*(undefined4 *)(param_1 + 0x8c));
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x68) = 3;
    }
    else if (iVar1 < 3) goto LAB_030cba84;
    FUN_030c7b12(param_1 + 0x30);
    FUN_030c7ab4(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x68) = 2;
  }
LAB_030cba84:
  if (param_5 == (undefined4 *)0x0) {
    lVar4 = FUN_030cb504(param_1,&local_30,0x400,0);
    if (lVar4 == -0x80) {
      return -0x80;
    }
    param_5 = &local_30;
    if (lVar4 < 0) {
      return -0x84;
    }
  }
  uVar2 = FUN_030c6bc2(param_5);
  FUN_030c756e(*(undefined4 *)(param_1 + 0x88),uVar2);
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x88) + 0x18);
  }
  FUN_030c7b00(param_2);
  FUN_030c799a(param_3);
  iVar1 = 0;
  while (FUN_030c7400(*(undefined4 *)(param_1 + 0x88),param_5), iVar1 < 2) {
    while (iVar3 = FUN_030c775e(*(undefined4 *)(param_1 + 0x88),&local_50), iVar3 != 0) {
      if (iVar3 == -1) {
        return -0x85;
      }
      iVar3 = FUN_030c8b0c(param_2,param_3,&local_50);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar1 = iVar1 + 1;
      if (1 < iVar1) goto LAB_030cbb5e;
    }
    if (1 < iVar1) break;
    FUN_030cb504(param_1,param_5,0x400,0);
    if (extraout_r1 < 0) {
      return -0x85;
    }
  }
LAB_030cbb5e:
  FUN_030c75ac(&local_50);
  FUN_030c6e1e(&local_30);
  *(undefined4 *)(param_1 + 0x68) = 4;
  return 0;
}


