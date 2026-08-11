/**
 * FUN_030f4972 @ 0x030f4972
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030f4972(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar2 = DAT_030f4ba8;
  pcVar1 = DAT_030f4b80;
  *DAT_030f4ba8 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_030f8618(0x69,0,2);
  FUN_030f8644(puVar2,0,2);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0f53(1);
    iVar4 = DAT_030f4b84;
    do {
      if (*pcVar1 != '\0') goto LAB_030f49b8;
      hifi_busy_delay_ovl_0f53(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030f50a4(s_HifiFileSeek__timeout___030f4bb0);
  }
LAB_030f49b8:
  *(undefined4 *)(DAT_030f4ba0 + (uint)*(byte *)(puVar2 + 2) * 4) = *puVar2;
  puVar3 = DAT_030f4bac;
  *pcVar1 = '\0';
  return *puVar3;
}


