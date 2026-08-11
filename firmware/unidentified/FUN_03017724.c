/**
 * FUN_03017724 @ 0x03017724
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03017724(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_28 [4];
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar3 = DAT_03017b04;
  iVar2 = DAT_03017ae8;
  local_28[0] = *DAT_03017b00;
  local_28[1] = DAT_03017b00[1];
  local_28[2] = DAT_03017b00[2];
  local_28[3] = DAT_03017b00[3];
  local_18 = DAT_03017b00[4];
  uStack_14 = DAT_03017b00[5];
  *(undefined4 *)(DAT_03017b04 + 4) = 0;
  if (*(byte *)(iVar2 + 0x1a) != param_1) {
    *(char *)(iVar2 + 0x1a) = (char)param_1;
    pcVar4 = DAT_03017b08;
    cVar1 = *DAT_03017b08;
    if (param_1 == 0) {
      if (cVar1 == '\x01') {
        FUN_03002d56(DAT_03017b04);
        *pcVar4 = '\0';
      }
    }
    else {
      *(undefined4 *)(iVar3 + 8) = local_28[param_1];
      if (cVar1 == '\0') {
        *pcVar4 = '\x01';
        FUN_03002cc0(DAT_03017b04);
      }
    }
    return 0;
  }
  return 0;
}


