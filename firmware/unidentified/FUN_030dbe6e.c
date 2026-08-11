/**
 * FUN_030dbe6e @ 0x030dbe6e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030dbe6e(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  
  puVar1 = DAT_030dc0a8;
  pcVar3 = (char *)(DAT_030dc0a8 + -10);
  *DAT_030dc0a8 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar3 = '\0';
  FUN_030e086c(0x69,0,2);
  FUN_030e0898(puVar1,0,2);
  if (*pcVar3 == '\0') {
    hifi_busy_delay_ovl_0dc7(1);
    iVar4 = DAT_030dc088;
    do {
      if (*pcVar3 != '\0') goto LAB_030dbeb8;
      hifi_busy_delay_ovl_0dc7(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl_0dc5(s_HifiFileSeek__timeout___030dc0b0);
  }
LAB_030dbeb8:
  *(undefined4 *)(DAT_030dc0a4 + (uint)*(byte *)(puVar1 + 2) * 4) = *puVar1;
  puVar2 = DAT_030dc0ac;
  *pcVar3 = '\0';
  return *puVar2;
}


