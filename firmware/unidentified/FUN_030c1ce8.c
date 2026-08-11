/**
 * FUN_030c1ce8 @ 0x030c1ce8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c1ce8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030c1da4;
  pcVar2 = (char *)(DAT_030c1da4 + -0x14);
  DAT_030c1da4[2] = param_3;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *pcVar2 = '\0';
  FUN_030cd8a4(0xf,0,1);
  FUN_030cd8d0(puVar1,0,1);
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0bff(1);
    iVar3 = DAT_030c1da8;
    do {
      if (*pcVar2 != '\0') goto LAB_030c1d30;
      hifi_busy_delay_ovl_0bff(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030bfd16(s_FLAC_FileSeekFast__timeout___030c1dac);
  }
LAB_030c1d30:
  *pcVar2 = '\0';
  return 0;
}


