/**
 * FUN_030c1d3e @ 0x030c1d3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c1d3e(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = DAT_030c1dcc;
  *DAT_030c1dcc = '\0';
  FUN_030cd8a4(0x11,0,1);
  FUN_030cd8d0(param_3,0,1);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0bff(1);
    iVar4 = DAT_030c1da8;
    do {
      if (*pcVar1 != '\0') goto LAB_030c1d86;
      hifi_busy_delay_ovl_0bff(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030bfd16(s_FLAC_FileGetSeekInfo__timeout___030c1dd4);
  }
LAB_030c1d86:
  piVar2 = DAT_030c1dd0;
  *pcVar1 = '\0';
  puVar3 = (undefined4 *)*piVar2;
  *param_1 = *puVar3;
  *param_2 = puVar3[1];
  return 0;
}


