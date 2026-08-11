/**
 * FUN_030329fc @ 0x030329fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030329fc(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  pcVar2 = (char *)0x303fac4;
  uVar4 = 0xff;
  uVar3 = 0;
  bVar1 = func_0x0300b8ea(0x303fac4,0x303fac4,0x303fac4,0x303fac4,0x303fac4,param_2,0x303fac4,
                          0x303fac4);
  do {
    uVar3 = uVar3 + 3 & 0xff;
    if (((*pcVar2 == -1) && (pcVar2[1] == '0')) && (pcVar2[2] == -0x2a)) break;
    pcVar2 = pcVar2 + 3;
  } while (uVar3 <= bVar1);
  if (uVar3 <= bVar1) {
    uVar4 = uVar3 / 3;
  }
  switch(uVar4) {
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


