/**
 * FUN_030aafba @ 0x030aafba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030aafba(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  
  puVar1 = DAT_030ab1f4;
  pcVar3 = (char *)(DAT_030ab1f4 + -10);
  *DAT_030ab1f4 = param_1;
  puVar1[1] = param_2;
  *(undefined1 *)(puVar1 + 2) = param_3;
  *pcVar3 = '\0';
  FUN_030b5854(0x69,0,2);
  FUN_030b5880(puVar1,0,2);
  if (*pcVar3 == '\0') {
    hifi_busy_delay_ovl_0ab8(1);
    iVar4 = DAT_030ab1d4;
    do {
      if (*pcVar3 != '\0') goto LAB_030ab004;
      hifi_busy_delay_ovl_0ab8(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl(s_HifiFileSeek__timeout___030ab1fc);
  }
LAB_030ab004:
  *(undefined4 *)(DAT_030ab1f0 + (uint)*(byte *)(puVar1 + 2) * 4) = *puVar1;
  puVar2 = DAT_030ab1f8;
  *pcVar3 = '\0';
  return *puVar2;
}


