/**
 * FUN_030f49d4 @ 0x030f49d4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f49d4(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_030f4bc8;
  pcVar1 = DAT_030f4b80;
  *DAT_030f4bc8 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_030f8618(0x6b,0,2);
  FUN_030f8644(puVar2,0,2);
  if (pcVar1[1] == '\0') {
    return 0;
  }
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0f53(1);
    iVar3 = DAT_030f4b84;
    do {
      if (*pcVar1 != '\0') goto LAB_030f4a24;
      hifi_busy_delay_ovl_0f53(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030f50a4(s_HifiFileRead__timeout___030f4bcc);
  }
LAB_030f4a24:
  *(undefined4 *)(DAT_030f4ba0 + (uint)*(byte *)(puVar2 + 2) * 4) = puVar2[1];
  puVar2 = DAT_030f4bac;
  *pcVar1 = '\0';
  return *puVar2;
}


