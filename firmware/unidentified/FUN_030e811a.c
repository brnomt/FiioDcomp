/**
 * FUN_030e811a @ 0x030e811a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e811a(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *param_2 = *param_1;
  if (param_3 < 2) {
    return;
  }
  if (param_6 == 0) {
    FUN_030e41ce(param_2 + 1,param_1 + 1,param_3 * 4 + -4);
    return;
  }
  iVar3 = 1;
  if (param_6 == 0x1f) {
    do {
      uVar2 = FUN_030e576a(param_2[iVar3 + -1] + param_1[iVar3],param_4);
      param_2[iVar3] = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
    return;
  }
  while( true ) {
    iVar1 = param_6;
    if (iVar3 <= param_6) {
      iVar1 = param_3;
    }
    if (iVar1 <= iVar3) break;
    uVar2 = FUN_030e576a(param_2[iVar3 + -1] + param_1[iVar3],param_4);
    param_2[iVar3] = uVar2;
    param_1[iVar3] = uVar2;
    iVar3 = iVar3 + 1;
  }
  if (0xb < param_7) {
    FUN_030e6246(param_1,param_2,param_3,param_4);
    return;
  }
  FUN_030e9bf4(0,param_3,0x60000000);
  FUN_030e996e(0);
  FUN_030e5ff8(0,param_6,param_7,param_4);
  FUN_030e9984(param_5,DAT_030e8350,param_6);
  FUN_030e9bdc(0,param_3,0x60000000);
  FUN_030e9b4a(param_1,DAT_030e8358,param_3,DAT_030e8354);
  do {
    iVar3 = FUN_030e99b4(0,0x8000);
  } while (iVar3 != 0x8000);
  FUN_030e9958(0);
  return;
}


