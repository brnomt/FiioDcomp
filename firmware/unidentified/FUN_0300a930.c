/**
 * FUN_0300a930 @ 0x0300a930
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300a930(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_0300aa64 + param_1 * 0x40;
  if (*(short *)(DAT_0300aa5c + 0x24) != 1) {
    FUN_02ff547c(param_2,param_3,8,0x10,1,iVar1);
    return;
  }
  FUN_02ff547c(param_2,param_3,6,0xc,1,iVar1);
  return;
}


