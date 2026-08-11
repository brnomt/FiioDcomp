/**
 * FUN_030e3e7c @ 0x030e3e7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e3e7c(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_030e4070;
  pcVar1 = DAT_030e4028;
  *DAT_030e4070 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_030e98a4(0x6b,0,2);
  FUN_030e98d0(puVar2,0,2);
  if (pcVar1[1] == '\0') {
    return 0;
  }
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0e48(1);
    iVar3 = DAT_030e402c;
    do {
      if (*pcVar1 != '\0') goto LAB_030e3ecc;
      hifi_busy_delay_ovl_0e48(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_sync_ovl_0e45(s_HifiFileRead__timeout___030e4074);
  }
LAB_030e3ecc:
  *(undefined4 *)(DAT_030e4048 + (uint)*(byte *)(puVar2 + 2) * 4) = puVar2[1];
  puVar2 = DAT_030e4054;
  *pcVar1 = '\0';
  return *puVar2;
}


