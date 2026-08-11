/**
 * FUN_030c19b8 @ 0x030c19b8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c19b8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030c1b08;
  if (param_3 == 0) {
    FUN_030c1848(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030c1b08 + 0x10) == 1) {
    hifi_busy_delay_ovl_0bff(1);
    iVar2 = DAT_030c1b0c;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030c19f0;
      hifi_busy_delay_ovl_0bff(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_030bfd16(s_AudioFileMhSeek2__timeout___030c1b10);
  }
LAB_030c19f0:
  FUN_030bf61a(param_1,param_2,(int)(char)param_3);
  return;
}


