/**
 * FUN_030bf680 @ 0x030bf680
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030bf680(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  puVar1 = DAT_030bf874;
  pcVar2 = (char *)(DAT_030bf874 + -0xd);
  *DAT_030bf874 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar2 = '\0';
  FUN_030cd8a4(0x6b,0,2);
  FUN_030cd8d0(puVar1,0,2);
  if (*(char *)((int)puVar1 + -0x33) == '\0') {
    return 0;
  }
  if (*pcVar2 == '\0') {
    hifi_busy_delay_ovl_0bff(1);
    iVar3 = DAT_030bf834;
    do {
      if (*pcVar2 != '\0') goto LAB_030bf6d4;
      hifi_busy_delay_ovl_0bff(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030bfd16(s_HifiFileRead__timeout___030bf878);
  }
LAB_030bf6d4:
  *(undefined4 *)(DAT_030bf850 + (uint)*(byte *)(puVar1 + 2) * 4) = puVar1[1];
  puVar1 = DAT_030bf858;
  *pcVar2 = '\0';
  return *puVar1;
}


