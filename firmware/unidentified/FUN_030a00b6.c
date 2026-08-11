/**
 * FUN_030a00b6 @ 0x030a00b6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030a00b6(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030a0204;
  if (param_3 == 0) {
    FUN_0309ff48(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030a0204 + 0x10) == 1) {
    hifi_busy_delay_ovl_09e3(1);
    iVar2 = DAT_030a0208;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030a00ee;
      hifi_busy_delay_ovl_09e3(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    hifi_debug_printf_ovl_09e0(s_AudioFileMhSeek2__timeout___030a020c);
  }
LAB_030a00ee:
  FUN_0309d8c2(param_1,param_2,(int)(char)param_3);
  return;
}


