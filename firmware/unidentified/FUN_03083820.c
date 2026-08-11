/**
 * FUN_03083820 @ 0x03083820
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03083820(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030838dc;
  pcVar2 = (char *)(DAT_030838dc + -0x14);
  DAT_030838dc[2] = param_3;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *pcVar2 = '\0';
  FUN_0309101c(0xf,0,1);
  FUN_03091048(puVar1,0,1);
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0817(1);
    iVar3 = DAT_030838e0;
    do {
      if (*pcVar2 != '\0') goto LAB_03083868;
      hifi_busy_delay_ovl_0817(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_03081592(s_FLAC_FileSeekFast__timeout___030838e4);
  }
LAB_03083868:
  *pcVar2 = '\0';
  return 0;
}


