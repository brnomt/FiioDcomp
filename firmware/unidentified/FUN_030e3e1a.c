/**
 * FUN_030e3e1a @ 0x030e3e1a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030e3e1a(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar2 = DAT_030e4050;
  pcVar1 = DAT_030e4028;
  *DAT_030e4050 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_030e98a4(0x69,0,2);
  FUN_030e98d0(puVar2,0,2);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0e48(1);
    iVar4 = DAT_030e402c;
    do {
      if (*pcVar1 != '\0') goto LAB_030e3e60;
      hifi_busy_delay_ovl_0e48(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_sync_ovl_0e45(s_HifiFileSeek__timeout___030e4058);
  }
LAB_030e3e60:
  *(undefined4 *)(DAT_030e4048 + (uint)*(byte *)(puVar2 + 2) * 4) = *puVar2;
  puVar3 = DAT_030e4054;
  *pcVar1 = '\0';
  return *puVar3;
}


