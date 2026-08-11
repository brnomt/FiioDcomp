/**
 * FUN_030a37e4 @ 0x030a37e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a37e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_030a341c(param_3,param_2,1);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar2 != 1) {
    FUN_030a34bc(param_3,param_2,iVar1);
  }
  if (iVar1 != 2) {
    if (iVar1 == 4) {
      FUN_030a2fdc(param_3,1,param_1,iVar2);
      return;
    }
    return;
  }
  FUN_030a2e60(param_3,1,param_1,iVar2);
  return;
}


