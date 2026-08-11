/**
 * FUN_03007824 @ 0x03007824
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03007824(void)

{
  char cVar1;
  int iVar2;
  
  FUN_02fee67c();
  iVar2 = DAT_0300797c;
  if (*(byte *)(DAT_0300797c + 0x12) < *(byte *)(DAT_0300797c + 0x1e)) {
    *(byte *)(DAT_0300797c + 0x12) = *(byte *)(DAT_0300797c + 0x12) + 1;
  }
  DSP_GOODEF_Reload(0xff,0);
  FUN_02ff2de4(0x33);
  cVar1 = '\0';
  if (*DAT_0300796c != '\0') {
    cVar1 = *(char *)(iVar2 + 0x34a);
  }
  if (*DAT_0300796c != '\0' && cVar1 != '\0') {
    *(undefined1 *)(iVar2 + 0x15) = *(undefined1 *)(iVar2 + 0x12);
  }
  else {
    *(undefined1 *)(iVar2 + 0x13) = *(undefined1 *)(iVar2 + 0x12);
  }
  return;
}


