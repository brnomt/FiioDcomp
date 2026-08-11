/**
 * FUN_030f0d6c @ 0x030f0d6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f0d6c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030f0ebc;
  if (param_3 == 0) {
    FUN_030f0bfc(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030f0ebc + 0x10) == 1) {
    hifi_busy_delay_ovl_0ed6(1);
    iVar2 = DAT_030f0ec0;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030f0da4;
      hifi_busy_delay_ovl_0ed6(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    log_printf_ts(s_AudioFileMhSeek2__timeout___030f0ec4);
  }
LAB_030f0da4:
  FUN_030eccea(param_1,param_2,(int)(char)param_3);
  return;
}


