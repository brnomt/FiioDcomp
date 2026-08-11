/**
 * FUN_030f5290 @ 0x030f5290
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f5290(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_030f5318;
  if (*param_1 == '\r') {
    FUN_030f86f0(DAT_030f5318,s__B__030f5328);
    iVar3 = FUN_030f6614(param_1);
    FUN_030f65cc(iVar4 + 5,param_1 + 2,iVar3 + -2);
  }
  else {
    uVar2 = FUN_030f6614(param_1);
    FUN_030f65cc(iVar4 + 5,param_1,uVar2);
  }
  pcVar1 = DAT_030f5314;
  *DAT_030f5314 = '\x01';
  FUN_030f8618(5,0,3);
  FUN_030f8644(DAT_030f5318,0,3);
  if (*pcVar1 != '\x01') {
    return;
  }
  hifi_busy_delay_ovl_0f53(1);
  iVar4 = DAT_030f531c;
  do {
    if (*pcVar1 != '\x01') {
      return;
    }
    hifi_busy_delay_ovl_0f53(1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


