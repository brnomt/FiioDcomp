/**
 * ScuClockGateCtr @ 0x03029822
 * Tags: system, clock
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_03029822(code *param_1,undefined4 param_2,undefined4 param_3,short *param_4,undefined4 *param_5)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  FUN_02ffb400(param_4,0x60);
  (*param_1)(param_4,1,0x36,*param_5);
  if (((*param_4 == 0x4d42) && (*(int *)(param_4 + 0xb) < 0x10000)) &&
     (*(int *)(param_4 + 0xb) < 0x10000)) {
    if (*(int *)(param_4 + 0xf) == 0) {
      if (((param_4[0xe] == 1) || (param_4[0xe] == 4)) || (param_4[0xe] == 8)) {
        bVar1 = true;
      }
    }
    else if ((*(int *)(param_4 + 0xf) == 1) || (*(int *)(param_4 + 0xf) == 2)) {
      return 0;
    }
    if ((bVar1) && (iVar3 = FUN_03029598(param_1,param_2,param_3,param_5,param_4), iVar3 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


