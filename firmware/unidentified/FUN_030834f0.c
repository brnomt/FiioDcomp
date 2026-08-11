/**
 * FUN_030834f0 @ 0x030834f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030834f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03083640;
  if (param_3 == 0) {
    FUN_03083380(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_03083640 + 0x10) == 1) {
    hifi_busy_delay_ovl_0817(1);
    iVar2 = DAT_03083644;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_03083528;
      hifi_busy_delay_ovl_0817(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_03081592(s_AudioFileMhSeek2__timeout___03083648);
  }
LAB_03083528:
  HifiFileSeek_ovl(param_1,param_2,(int)(char)param_3);
  return;
}


