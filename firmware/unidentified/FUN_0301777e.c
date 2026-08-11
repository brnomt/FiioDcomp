/**
 * FUN_0301777e @ 0x0301777e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301777e(uint param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 local_18 [4];
  
  iVar2 = DAT_03017b0c;
  iVar1 = DAT_03017ae8;
  local_18[0] = *(undefined4 *)(DAT_03017b00 + 0x18);
  local_18[1] = *(undefined4 *)(DAT_03017b00 + 0x1c);
  local_18[2] = *(undefined4 *)(DAT_03017b00 + 0x20);
  local_18[3] = *(undefined4 *)(DAT_03017b00 + 0x24);
  *(undefined4 *)(DAT_03017b0c + 4) = 0;
  pcVar3 = DAT_03017b10;
  if (*(byte *)(iVar1 + 0x1b) != param_1) {
    if ('\x01' < *DAT_03017b10) {
      *DAT_03017b10 = '\x01';
    }
    *(char *)(iVar1 + 0x1b) = (char)param_1;
    if (param_1 == 0) {
      if (*pcVar3 == '\0') {
        func_0x03001a1a();
      }
    }
    else {
      *(undefined4 *)(iVar2 + 8) = local_18[param_1];
      if (*pcVar3 == '\0') {
        func_0x03001a1a();
        FUN_03001478();
      }
      else {
        FUN_03001478();
      }
    }
    return 0;
  }
  return 0;
}


