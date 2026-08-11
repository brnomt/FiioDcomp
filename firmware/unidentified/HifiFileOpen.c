/**
 * HifiFileOpen @ 0x0306b9bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

undefined4 HifiFileOpen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = DAT_0306bbec;
  DAT_0306bbec[2] = param_3;
  *puVar2 = param_1;
  puVar2[1] = param_2;
  *(undefined1 *)(puVar2 + 3) = param_4;
  ipc_post_cmd(0x6d,0,2);
  ipc_post_arg(DAT_0306bbec,0,2);
  pcVar1 = DAT_0306bb8c;
  if (DAT_0306bb8c[1] == '\0') {
    return 0;
  }
  if (*DAT_0306bb8c == '\0') {
    hifi_busy_delay(1);
    iVar3 = DAT_0306bb90;
    do {
      if (*pcVar1 != '\0') goto LAB_0306ba0c;
      hifi_busy_delay(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf(s_HifiFileWrite__timeout___0306bbf0);
  }
LAB_0306ba0c:
  *pcVar1 = '\0';
  return *DAT_0306bbb4;
}
