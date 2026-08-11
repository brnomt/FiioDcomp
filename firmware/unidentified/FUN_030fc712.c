/**
 * FUN_030fc712 @ 0x030fc712
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_030fc712(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar2 = DAT_030fc948;
  pcVar1 = DAT_030fc920;
  *DAT_030fc948 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 2) = param_3;
  *pcVar1 = '\0';
  FUN_031001f0(0x69,0,2);
  FUN_0310021c(puVar2,0,2);
  if (*pcVar1 == '\0') {
    hifi_busy_delay_ovl_0fd1(1);
    iVar4 = DAT_030fc924;
    do {
      if (*pcVar1 != '\0') goto LAB_030fc758;
      hifi_busy_delay_ovl_0fd1(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030fce44(s_HifiFileSeek__timeout___030fc950);
  }
LAB_030fc758:
  *(undefined4 *)(DAT_030fc940 + (uint)*(byte *)(puVar2 + 2) * 4) = *puVar2;
  puVar3 = DAT_030fc94c;
  *pcVar1 = '\0';
  return *puVar3;
}


