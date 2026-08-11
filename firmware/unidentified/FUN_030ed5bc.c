/**
 * FUN_030ed5bc @ 0x030ed5bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ed5bc(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_030ed610;
  if (*param_1 != '\r') {
    uVar2 = FUN_030ee920(param_1);
    FUN_030ee8d8(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_030f19c0(DAT_030ed610,s__B__030ed614);
  iVar3 = FUN_030ee920(param_1);
  FUN_030ee8d8(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


