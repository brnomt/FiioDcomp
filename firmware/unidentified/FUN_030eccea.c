/**
 * FUN_030eccea @ 0x030eccea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030eccea(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  
  puVar1 = DAT_030ecf24;
  pcVar3 = (char *)(DAT_030ecf24 + -10);
  *DAT_030ecf24 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar3 = '\0';
  FUN_030f15e4(0x69,0,2);
  FUN_030f1610(puVar1,0,2);
  if (*pcVar3 == '\0') {
    hifi_busy_delay_ovl_0ed6(1);
    iVar4 = DAT_030ecf04;
    do {
      if (*pcVar3 != '\0') goto LAB_030ecd34;
      hifi_busy_delay_ovl_0ed6(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    log_printf_ts(s_HifiFileSeek__timeout___030ecf2c);
  }
LAB_030ecd34:
  *(undefined4 *)(DAT_030ecf20 + (uint)*(byte *)(puVar1 + 2) * 4) = *puVar1;
  puVar2 = DAT_030ecf28;
  *pcVar3 = '\0';
  return *puVar2;
}


