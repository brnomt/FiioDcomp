/**
 * FUN_03083876 @ 0x03083876
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03083876(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = DAT_03083904;
  *DAT_03083904 = '\0';
  FUN_0309101c(0x11,0,1);
  FUN_03091048(param_3,0,1);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0817(1);
    iVar4 = DAT_030838e0;
    do {
      if (*pcVar1 != '\0') goto LAB_030838be;
      hifi_busy_delay_ovl_0817(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_03081592(s_FLAC_FileGetSeekInfo__timeout___0308390c);
  }
LAB_030838be:
  piVar2 = DAT_03083908;
  *pcVar1 = '\0';
  puVar3 = (undefined4 *)*piVar2;
  *param_1 = *puVar3;
  *param_2 = puVar3[1];
  return 0;
}


