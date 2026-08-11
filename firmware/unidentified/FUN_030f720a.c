/**
 * FUN_030f720a @ 0x030f720a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f720a(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_030f7358;
  if (param_3 == 0) {
    FUN_030f709c(param_1,param_2,0);
    return;
  }
  if (*(int *)(DAT_030f7358 + 0x10) == 1) {
    hifi_busy_delay_ovl_0f53(1);
    iVar2 = DAT_030f735c;
    do {
      if (*(int *)(iVar1 + 0x10) != 1) goto LAB_030f7242;
      hifi_busy_delay_ovl_0f53(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_030f50a4(s_AudioFileMhSeek2__timeout___030f7360);
  }
LAB_030f7242:
  FUN_030f4972(param_1,param_2,(int)(char)param_3);
  return;
}


