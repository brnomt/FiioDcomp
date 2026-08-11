/**
 * FUN_0301aa6c @ 0x0301aa6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301aa6c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0301ace0;
  if (*(short *)(DAT_0301ace0 + 4) != 0) {
    return;
  }
  if (*DAT_0301acdc == '\0') {
    *DAT_0301acdc = '\x01';
    iVar2 = FUN_0301dd4e();
    if (iVar2 != 0) {
      FUN_0301abb2(0x11f,0);
      return;
    }
    iVar2 = FUN_0301dbc8();
    if (iVar2 != 2) {
      FUN_0301ddf2();
    }
    if (*(char *)(iVar1 + 1) == '\x03') {
      *(undefined2 *)(iVar1 + 4) = 3;
      FUN_03008eb4(0x127);
    }
    else {
      *(undefined2 *)(iVar1 + 4) = 0;
    }
  }
  *DAT_0301ace8 = 2;
  FUN_03008eb4(0x23);
  *DAT_0301acf0 = *DAT_0301acec;
  return;
}


