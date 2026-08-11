/**
 * FUN_030f109c @ 0x030f109c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f109c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030f1158;
  pcVar2 = (char *)(DAT_030f1158 + -0x14);
  DAT_030f1158[2] = param_3;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *pcVar2 = '\0';
  FUN_030f15e4(0xf,0,1);
  FUN_030f1610(puVar1,0,1);
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0ed6(1);
    iVar3 = DAT_030f115c;
    do {
      if (*pcVar2 != '\0') goto LAB_030f10e4;
      hifi_busy_delay_ovl_0ed6(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    log_printf_ts(s_FLAC_FileSeekFast__timeout___030f1160);
  }
LAB_030f10e4:
  *pcVar2 = '\0';
  return 0;
}


