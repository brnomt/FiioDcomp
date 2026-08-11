/**
 * FUN_0306c254 @ 0x0306c254
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306c254(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_0306c2a8;
  if (*param_1 != '\r') {
    uVar2 = FUN_0306d394(param_1);
    hifi_memmove(iVar1 + 5,param_1,uVar2);
    return;
  }
  FUN_03073d54(DAT_0306c2a8,s__B__0306c2ac);
  iVar3 = FUN_0306d394(param_1);
  hifi_memmove(iVar1 + 5,param_1 + 2,iVar3 + -2);
  return;
}


