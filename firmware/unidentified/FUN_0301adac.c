/**
 * FUN_0301adac @ 0x0301adac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301adac(void)

{
  char *pcVar1;
  char *pcVar2;
  
  FUN_0301abb2(0x11b,0);
  pcVar2 = DAT_0301aec4;
  pcVar1 = DAT_0301aebc;
  if (*(short *)(DAT_0301aec0 + 4) == 0) {
    if (*(char *)(DAT_0301aeac + 0x34a) == '\0') {
      *DAT_0301aec4 = '\x01';
      if (*DAT_0301aed0 < (uint)(*DAT_0301aec8 - *DAT_0301aecc)) {
        FUN_03008ed0(0x23);
      }
    }
    else {
      *DAT_0301aec4 = '\0';
    }
    if (*pcVar1 != *pcVar2) {
      *pcVar1 = *pcVar2;
    }
  }
  else {
    *DAT_0301aebc = -1;
  }
  return 0;
}


