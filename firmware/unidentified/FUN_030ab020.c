/**
 * FUN_030ab020 @ 0x030ab020
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030ab020(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030ab214;
  pcVar2 = (char *)(DAT_030ab214 + -0xd);
  *DAT_030ab214 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar2 = '\0';
  FUN_030b5854(0x6b,0,2);
  FUN_030b5880(puVar1,0,2);
  if (*(char *)((int)puVar1 + -0x33) == '\0') {
    return 0;
  }
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0ab8(1);
    iVar3 = DAT_030ab1d4;
    do {
      if (*pcVar2 != '\0') goto LAB_030ab074;
      hifi_busy_delay_ovl_0ab8(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_ovl(s_HifiFileRead__timeout___030ab218);
  }
LAB_030ab074:
  *(undefined4 *)(DAT_030ab1f0 + (uint)*(byte *)(puVar1 + 2) * 4) = puVar1[1];
  puVar1 = DAT_030ab1f8;
  *pcVar2 = '\0';
  return *puVar1;
}


