/**
 * FUN_030de3e8 @ 0x030de3e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030de3e8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030de538;
  if (param_3 == 0) {
    FUN_030de278(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030de538 + 0x10) == 1) {
    hifi_busy_delay_ovl_0dc7(1);
    iVar2 = DAT_030de53c;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030de420;
      hifi_busy_delay_ovl_0dc7(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    hifi_debug_printf_ovl_0dc5(s_AudioFileMhSeek2__timeout___030de540);
  }
LAB_030de420:
  FUN_030dbe6e(param_1,param_2,(int)(char)param_3);
  return;
}


