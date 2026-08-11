/**
 * FUN_030642f4 @ 0x030642f4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030642f4(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 extraout_r1_00;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_r8;
  undefined4 unaff_lr;
  
  iVar2 = DAT_03064490;
  puVar1 = DAT_0306448c;
  if (param_1 == 0) {
    (**(code **)(DAT_03064490 + 0xc))(*DAT_0306448c);
    FUN_030233b6(puVar1[1]);
    FUN_030233ba(puVar1[2]);
    FUN_0302344e(puVar1[3]);
    func_0x030233b0(puVar1[4]);
    FUN_0302344a(puVar1[5]);
    *(undefined4 *)(iVar2 + -0x14) = 0;
    uVar4 = extraout_r1_00;
  }
  else {
    (**(code **)(DAT_03064490 + 0xc))(DAT_0306448c[param_1 * 6]);
    FUN_030233ba(0xc);
    FUN_0302344e(puVar1[param_1 * 6 + 3]);
    func_0x030233b0(puVar1[param_1 * 6 + 4]);
    FUN_0302344a(puVar1[param_1 * 6 + 5]);
    *(int *)(iVar2 + -0x14) = param_1;
    uVar4 = extraout_r1;
  }
  pcVar5 = (char *)0x303fac4;
  uVar7 = 0xff;
  uVar6 = 0;
  bVar3 = func_0x0300b8ea(0x303fac4,0x303fac4,0x303fac4,0x303fac4,0x303fac4,uVar4,0x303fac4,
                          0x303fac4,unaff_r8,unaff_lr);
  do {
    uVar6 = uVar6 + 3 & 0xff;
    if (((*pcVar5 == -1) && (pcVar5[1] == '0')) && (pcVar5[2] == -0x2a)) break;
    pcVar5 = pcVar5 + 3;
  } while (uVar6 <= bVar3);
  if (uVar6 <= bVar3) {
    uVar7 = uVar6 / 3;
  }
  switch(uVar7) {
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


