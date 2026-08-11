/**
 * FUN_030bf61a @ 0x030bf61a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030bf61a(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  
  puVar1 = DAT_030bf854;
  pcVar3 = (char *)(DAT_030bf854 + -10);
  *DAT_030bf854 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar3 = '\0';
  FUN_030cd8a4(0x69,0,2);
  FUN_030cd8d0(puVar1,0,2);
  if (*pcVar3 == '\0') {
    hifi_busy_delay_ovl_0bff(1);
    iVar4 = DAT_030bf834;
    do {
      if (*pcVar3 != '\0') goto LAB_030bf664;
      hifi_busy_delay_ovl_0bff(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030bfd16(s_HifiFileSeek__timeout___030bf85c);
  }
LAB_030bf664:
  *(undefined4 *)(DAT_030bf850 + (uint)*(byte *)(puVar1 + 2) * 4) = *puVar1;
  puVar2 = DAT_030bf858;
  *pcVar3 = '\0';
  return *puVar2;
}


