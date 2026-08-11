/**
 * FUN_030dc69e @ 0x030dc69e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030dc69e(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_030dc6f4;
  if (*param_1 != '\r') {
    uVar2 = FUN_030dda3c(param_1);
    FUN_030dd9f4(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_030e0c48(DAT_030dc6f4,s__B__030dc6f8);
  iVar3 = FUN_030dda3c(param_1);
  FUN_030dd9f4(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


