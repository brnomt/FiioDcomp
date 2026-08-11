/**
 * FUN_030fefaa @ 0x030fefaa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030fefaa(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030ff0f8;
  if (param_3 == 0) {
    FUN_030fee3c(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030ff0f8 + 0x10) == 1) {
    hifi_busy_delay_ovl_0fd1(1);
    iVar2 = DAT_030ff0fc;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030fefe2;
      hifi_busy_delay_ovl_0fd1(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_030fce44(s_AudioFileMhSeek2__timeout___030ff100);
  }
LAB_030fefe2:
  FUN_030fc712(param_1,param_2,(int)(char)param_3);
  return;
}


