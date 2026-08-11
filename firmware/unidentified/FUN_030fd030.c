/**
 * FUN_030fd030 @ 0x030fd030
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030fd030(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_030fd0b8;
  if (*param_1 == '\r') {
    FUN_031002c8(DAT_030fd0b8,s__B__030fd0c8);
    iVar3 = FUN_030fe3b4(param_1);
    FUN_030fe36c(iVar4 + 5,param_1 + 2,iVar3 + -2);
  }
  else {
    uVar2 = FUN_030fe3b4(param_1);
    FUN_030fe36c(iVar4 + 5,param_1,uVar2);
  }
  pcVar1 = DAT_030fd0b4;
  *DAT_030fd0b4 = '\x01';
  FUN_031001f0(5,0,3);
  FUN_0310021c(DAT_030fd0b8,0,3);
  if (*pcVar1 != '\x01') {
    return;
  }
  hifi_busy_delay_ovl_0fd1(1);
  iVar4 = DAT_030fd0bc;
  do {
    if (*pcVar1 != '\x01') {
      return;
    }
    hifi_busy_delay_ovl_0fd1(1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


