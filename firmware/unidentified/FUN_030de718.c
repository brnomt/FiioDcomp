/**
 * FUN_030de718 @ 0x030de718
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030de718(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030de7d4;
  pcVar2 = (char *)(DAT_030de7d4 + -0x14);
  DAT_030de7d4[2] = param_3;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *pcVar2 = '\0';
  FUN_030e086c(0xf,0,1);
  FUN_030e0898(puVar1,0,1);
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0dc7(1);
    iVar3 = DAT_030de7d8;
    do {
      if (*pcVar2 != '\0') goto LAB_030de760;
      hifi_busy_delay_ovl_0dc7(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl_0dc5(s_FLAC_FileSeekFast__timeout___030de7dc);
  }
LAB_030de760:
  *pcVar2 = '\0';
  return 0;
}


