/**
 * FUN_030de76e @ 0x030de76e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030de76e(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = DAT_030de7fc;
  *DAT_030de7fc = '\0';
  FUN_030e086c(0x11,0,1);
  FUN_030e0898(param_3,0,1);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0dc7(1);
    iVar4 = DAT_030de7d8;
    do {
      if (*pcVar1 != '\0') goto LAB_030de7b6;
      hifi_busy_delay_ovl_0dc7(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl_0dc5(s_FLAC_FileGetSeekInfo__timeout___030de804);
  }
LAB_030de7b6:
  piVar2 = DAT_030de800;
  *pcVar1 = '\0';
  puVar3 = (undefined4 *)*piVar2;
  *param_1 = *puVar3;
  *param_2 = puVar3[1];
  return 0;
}


