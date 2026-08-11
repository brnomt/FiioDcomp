/**
 * FUN_030b4fdc @ 0x030b4fdc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b4fdc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030b512c;
  if (param_3 == 0) {
    FUN_030b4e6c(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030b512c + 0x10) == 1) {
    hifi_busy_delay_ovl_0ab8(1);
    iVar2 = DAT_030b5130;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030b5014;
      hifi_busy_delay_ovl_0ab8(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    hifi_debug_printf_ovl(s_AudioFileMhSeek2__timeout___030b5134);
  }
LAB_030b5014:
  FUN_030aafba(param_1,param_2,(int)(char)param_3);
  return;
}


