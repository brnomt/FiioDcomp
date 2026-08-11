/**
 * FUN_030a34bc @ 0x030a34bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a34bc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_5;
  iVar2 = param_5[1];
  if (iVar2 != 1) {
    FUN_030a34bc(param_1,param_2,param_3 * iVar1);
  }
  if (iVar1 != 2) {
    if (iVar1 == 4) {
      FUN_030a2fdc(param_1,param_3,param_6,iVar2);
      return;
    }
    return;
  }
  FUN_030a2e60(param_1,param_3,param_6,iVar2);
  return;
}


