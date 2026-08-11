/**
 * FUN_030e9032 @ 0x030e9032
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e9032(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030e9180;
  if (param_3 == 0) {
    FUN_030e8ec4(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030e9180 + 0x10) == 1) {
    hifi_busy_delay_ovl_0e48(1);
    iVar2 = DAT_030e9184;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030e906a;
      hifi_busy_delay_ovl_0e48(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    hifi_debug_printf_sync_ovl_0e45(s_AudioFileMhSeek2__timeout___030e9188);
  }
LAB_030e906a:
  FUN_030e3e1a(param_1,param_2,(int)(char)param_3);
  return;
}


