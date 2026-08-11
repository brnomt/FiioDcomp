/**
 * FUN_0303f9c0 @ 0x0303f9c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0303f9c0(char *param_1,char *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xff;
  uVar2 = 0;
  bVar1 = func_0x0300b8ea(param_2);
  do {
    uVar2 = uVar2 + 3 & 0xff;
    if (((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) break;
    param_2 = param_2 + 3;
  } while (uVar2 <= bVar1);
  if (uVar2 <= bVar1) {
    uVar3 = uVar2 / 3;
  }
  switch(uVar3) {
  default:
    *DAT_0303fe14 = 0xff;
    return;
  case 1:
  case 2:
  case 3:
    *DAT_0303fe14 = 0;
    return;
  case 4:
    *DAT_0303fe14 = 1;
    return;
  case 5:
    *DAT_0303fe14 = 3;
    return;
  case 6:
    *DAT_0303fe14 = 5;
    return;
  case 7:
    *DAT_0303fe14 = 6;
    return;
  case 8:
  case 9:
  case 0xb:
  case 0xc:
    break;
  case 10:
    *DAT_0303fe14 = 4;
    return;
  case 0xd:
    *DAT_0303fe14 = 8;
    return;
  case 0xe:
    *DAT_0303fe14 = 9;
    return;
  }
  if ((*DAT_0303fe18 != 7) && (*DAT_0303fe18 == 0xd)) {
    *DAT_0303fe14 = 7;
    return;
  }
  *DAT_0303fe14 = 2;
  return;
}


