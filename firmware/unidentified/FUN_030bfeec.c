/**
 * FUN_030bfeec @ 0x030bfeec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030bfeec(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_030bff40;
  if (*param_1 != '\r') {
    uVar2 = FUN_030c0fba(param_1);
    FUN_030c0f56(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_030cd99c(DAT_030bff40,s__B__030bff44);
  iVar3 = FUN_030c0fba(param_1);
  FUN_030c0f56(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


