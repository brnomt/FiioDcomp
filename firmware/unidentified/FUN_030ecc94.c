/**
 * FUN_030ecc94 @ 0x030ecc94
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ecc94(void)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = DAT_030ecf00;
  if (*DAT_030ecf00 == '\0') {
    hifi_busy_delay_ovl_0ed6(1);
    iVar2 = DAT_030ecf04;
    do {
      if (*pcVar1 != '\0') goto LAB_030eccb8;
      hifi_busy_delay_ovl_0ed6(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    log_printf_ts(s_HifiFileOpen__timeout___030ecf08);
  }
LAB_030eccb8:
  *pcVar1 = '\0';
  return;
}


