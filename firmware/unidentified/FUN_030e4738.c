/**
 * FUN_030e4738 @ 0x030e4738
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e4738(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_030e47c0;
  if (*param_1 == '\r') {
    FUN_030e9c80(DAT_030e47c0,s__B__030e47d0);
    iVar3 = FUN_030e5ad4(param_1);
    FUN_030e5a74(iVar4 + 5,param_1 + 2,iVar3 + -2);
  }
  else {
    uVar2 = FUN_030e5ad4(param_1);
    FUN_030e5a74(iVar4 + 5,param_1,uVar2);
  }
  pcVar1 = DAT_030e47bc;
  *DAT_030e47bc = '\x01';
  FUN_030e98a4(5,0,3);
  FUN_030e98d0(DAT_030e47c0,0,3);
  if (*pcVar1 != '\x01') {
    return;
  }
  hifi_busy_delay_ovl_0e48(1);
  iVar4 = DAT_030e47c4;
  do {
    if (*pcVar1 != '\x01') {
      return;
    }
    hifi_busy_delay_ovl_0e48(1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


