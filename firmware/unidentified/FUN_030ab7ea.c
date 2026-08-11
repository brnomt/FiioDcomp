/**
 * FUN_030ab7ea @ 0x030ab7ea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ab7ea(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_030ab840;
  if (*param_1 != '\r') {
    uVar2 = FUN_030ac924(param_1);
    FUN_030ac8a8(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_030b592c(DAT_030ab840,s__B__030ab844);
  iVar3 = FUN_030ac924(param_1);
  FUN_030ac8a8(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


