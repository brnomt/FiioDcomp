/**
 * FUN_030f10f2 @ 0x030f10f2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f10f2(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = DAT_030f1180;
  *DAT_030f1180 = '\0';
  FUN_030f15e4(0x11,0,1);
  FUN_030f1610(param_3,0,1);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0ed6(1);
    iVar4 = DAT_030f115c;
    do {
      if (*pcVar1 != '\0') goto LAB_030f113a;
      hifi_busy_delay_ovl_0ed6(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    log_printf_ts(s_FLAC_FileGetSeekInfo__timeout___030f1188);
  }
LAB_030f113a:
  piVar2 = DAT_030f1184;
  *pcVar1 = '\0';
  puVar3 = (undefined4 *)*piVar2;
  *param_1 = *puVar3;
  *param_2 = puVar3[1];
  return 0;
}


