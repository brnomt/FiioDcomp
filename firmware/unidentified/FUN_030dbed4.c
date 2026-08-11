/**
 * FUN_030dbed4 @ 0x030dbed4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030dbed4(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030dc0c8;
  pcVar2 = (char *)(DAT_030dc0c8 + -0xd);
  *DAT_030dc0c8 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar2 = '\0';
  FUN_030e086c(0x6b,0,2);
  FUN_030e0898(puVar1,0,2);
  if (*(char *)((int)puVar1 + -0x33) == '\0') {
    return 0;
  }
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0dc7(1);
    iVar3 = DAT_030dc088;
    do {
      if (*pcVar2 != '\0') goto LAB_030dbf28;
      hifi_busy_delay_ovl_0dc7(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl_0dc5(s_HifiFileRead__timeout___030dc0cc);
  }
LAB_030dbf28:
  *(undefined4 *)(DAT_030dc0a4 + (uint)*(byte *)(puVar1 + 2) * 4) = puVar1[1];
  puVar1 = DAT_030dc0ac;
  *pcVar2 = '\0';
  return *puVar1;
}


