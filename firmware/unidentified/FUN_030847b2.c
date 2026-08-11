/**
 * FUN_030847b2 @ 0x030847b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030847b2(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = DAT_03084a24;
  iVar2 = 0;
  if (param_1[0x13] == 0) {
    if (*param_1 == 0) {
      return DAT_03084a24;
    }
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    iVar2 = (*(code *)*param_1)(param_1[1],&local_40);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_03083ec4(param_1[2],&local_40);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  if (param_2 == 0) {
    iVar3 = param_1[0xc] + param_1[8] * 8;
  }
  else {
    iVar3 = 0;
  }
  if ((uint)(iVar3 + param_1[10]) < param_3) {
    if ((param_1[0x13] != 0) && (param_2 < 2)) {
      return iVar2;
    }
    return iVar1;
  }
  return iVar2;
}


