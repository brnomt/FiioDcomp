/**
 * FUN_03070c78 @ 0x03070c78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03070c78(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *DAT_03071078 = param_2;
  iVar1 = FUN_0306e39c(param_1);
  if (iVar1 != 0) {
    return;
  }
  hifi_memmove(DAT_0307107c,param_1,0x48);
  return;
}


