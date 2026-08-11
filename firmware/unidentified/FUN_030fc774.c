/**
 * FUN_030fc774 @ 0x030fc774
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030fc774(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_030fc968;
  pcVar1 = DAT_030fc920;
  *DAT_030fc968 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_031001f0(0x6b,0,2);
  FUN_0310021c(puVar2,0,2);
  if (pcVar1[1] == '\0') {
    return 0;
  }
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0fd1(1);
    iVar3 = DAT_030fc924;
    do {
      if (*pcVar1 != '\0') goto LAB_030fc7c4;
      hifi_busy_delay_ovl_0fd1(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_030fce44(s_HifiFileRead__timeout___030fc96c);
  }
LAB_030fc7c4:
  *(undefined4 *)(DAT_030fc940 + (uint)*(byte *)(puVar2 + 2) * 4) = puVar2[1];
  puVar2 = DAT_030fc94c;
  *pcVar1 = '\0';
  return *puVar2;
}


