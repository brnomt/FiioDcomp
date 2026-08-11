/**
 * FUN_030ecd50 @ 0x030ecd50
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ecd50(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030ecf44;
  pcVar2 = (char *)(DAT_030ecf44 + -0xd);
  *DAT_030ecf44 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar2 = '\0';
  FUN_030f15e4(0x6b,0,2);
  FUN_030f1610(puVar1,0,2);
  if (*(char *)((int)puVar1 + -0x33) == '\0') {
    return 0;
  }
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0ed6(1);
    iVar3 = DAT_030ecf04;
    do {
      if (*pcVar2 != '\0') goto LAB_030ecda4;
      hifi_busy_delay_ovl_0ed6(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    log_printf_ts(s_HifiFileRead__timeout___030ecf48);
  }
LAB_030ecda4:
  *(undefined4 *)(DAT_030ecf20 + (uint)*(byte *)(puVar1 + 2) * 4) = puVar1[1];
  puVar1 = DAT_030ecf28;
  *pcVar2 = '\0';
  return *puVar1;
}


