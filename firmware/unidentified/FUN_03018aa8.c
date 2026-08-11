/**
 * FUN_03018aa8 @ 0x03018aa8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03018aa8(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_30 [16];
  
  puVar2 = DAT_030191d0;
  uVar6 = DAT_030191cc;
  iVar5 = DAT_030191a8;
  uVar7 = 0;
  uVar1 = (undefined1)param_2;
  switch(param_1) {
  case 0xea:
  case 0xeb:
    *(undefined1 *)(DAT_030191a8 + 0x35e) = uVar1;
    break;
  case 0xec:
    *DAT_030191ac = 0;
    *DAT_030191b0 = 3;
    FUN_02ff26a4(DAT_030191b8,DAT_030191b4,0);
    func_0x030037a8(0xb8);
    break;
  case 0xef:
  case 0xf0:
  case 0xf1:
    FUN_03019688(param_2);
    uVar6 = 0;
    goto LAB_03018e3a;
  case 0xf2:
    FUN_03019688(param_2);
    uVar6 = 1;
LAB_03018e3a:
    FUN_030196c0(uVar6);
    break;
  case 0xf4:
  case 0xf5:
    *(undefined1 *)(DAT_030191a8 + 0x1a1) = uVar1;
    bVar3 = *(byte *)(iVar5 + 0x6d) & 3;
    if ((param_2 & 0xff) != 0) {
      bVar3 = bVar3 + 4;
    }
    *(byte *)(iVar5 + 0x6d) = bVar3;
    uVar6 = 0x113;
    goto LAB_03019150;
  case 0xf7:
  case 0xf8:
  case 0xf9:
  case 0xfa:
  case 0xfb:
  case 0xfc:
  case 0xfd:
  case 0x1a3:
  case 0x1a4:
  case 0x1a5:
  case 0x1a6:
  case 0x1a7:
  case 0x1a8:
    FUN_0301923c(param_2);
    break;
  case 0xfe:
    FUN_0301923c(param_2);
    uVar6 = DAT_030191c4;
    *(short *)(DAT_030191c0 + (*DAT_030191bc + -1) * 0x14 + 0xc) = (short)param_2;
    FUN_02ff26a4(DAT_030191b8,uVar6,0);
    func_0x030037a8(0xb8);
    break;
  case 0x100:
  case 0x101:
  case 0x102:
  case 0x103:
  case 0x104:
    *(undefined1 *)(DAT_030191a8 + 0x358) = uVar1;
    iVar4 = FUN_02ff2834(*puVar2,uVar6);
    if (iVar4 == 1) {
      FUN_02ffc6a4(*(undefined1 *)(iVar5 + 0x358));
    }
    break;
  case 0x106:
  case 0x107:
    *(undefined1 *)(DAT_030191a8 + 0x359) = uVar1;
    iVar5 = FUN_02ff2834(*DAT_030191d0,uVar6);
    if (iVar5 == 1) {
      FUN_02ffc6e2();
    }
    break;
  case 0x109:
  case 0x10a:
  case 0x10b:
    *(undefined1 *)(DAT_030191a8 + 0x34c) = uVar1;
    break;
  case 0x10d:
  case 0x10e:
    *(undefined1 *)(DAT_030191a8 + 0x35a) = uVar1;
    break;
  case 0x110:
  case 0x111:
    *(undefined1 *)(DAT_030191a8 + 0x35c) = uVar1;
    break;
  case 0x112:
    *DAT_030191ac = 0;
    *DAT_030191b0 = 6;
    FUN_02ff26a4(DAT_030191b8,DAT_030191b4,0);
    func_0x030037a8(0xb8);
    break;
  case 0x114:
  case 0x115:
  case 0x116:
  case 0x117:
    FUN_030196e4(param_2);
    break;
  case 299:
    *DAT_030191d4 = 0xb;
    if (*(char *)(DAT_030191a8 + 0x349) == '\0') {
      uVar6 = 0x1c7;
    }
    else {
      uVar6 = 0x1cf;
    }
    func_0x030037a8(uVar6);
    goto LAB_03018fda;
  case 300:
    if (*(char *)(DAT_030191a8 + 0x34b) != '\0') {
      *DAT_030191d4 = 0;
      *(undefined1 *)(iVar5 + 0x34a) = 0;
      *(undefined1 *)(iVar5 + 0x34b) = 0;
      local_50 = 0x38;
      local_4e = 0x3c;
      local_4c = 1;
      local_4a = 0;
      local_48 = 1;
      FUN_02ff26a4(DAT_030191b8,DAT_030191d8,&local_50);
      func_0x030037a8(0xc9);
      FUN_02fed9e4(2,7,0);
      FUN_02ff17e4(2,7,1);
      FUN_02ff181e(2,7,0);
      FUN_02fed9e4(2,0x11,0);
      FUN_02ff17e4(2,0x11,1);
      FUN_02ff181e(2,0x11,0);
      FUN_02fed9e4(2,0x10,0);
      FUN_02ff17e4(2,0x10,1);
      FUN_02ff181e(2,0x10,0);
    }
    break;
  case 0x12d:
    if (*(char *)(DAT_030191a8 + 0x34b) == '\0') {
      func_0x030037a8(0xb8);
      func_0x030037a8(0xc9);
      local_50 = 0x38;
      local_4e = 0x80;
      local_4c = 1;
      local_4a = 0;
      local_48 = 1;
      FUN_02ff26a4(DAT_030191b8,DAT_030191d8,&local_50);
      break;
    }
    if (*(char *)(DAT_030191a8 + 0x34a) == '\0') {
      *(undefined1 *)(DAT_030191a8 + 0x34b) = 0;
    }
    *DAT_030191d4 = 0xd;
    func_0x030037a8(0x1c7);
LAB_03018fda:
    FUN_030039d2(0xe,0);
    uVar7 = 1;
    break;
  case 0x12e:
    if (*(char *)(DAT_030191a8 + 0x34a) == '\x01') {
      *DAT_030191d4 = 0xe;
      FUN_030039d2(0xe,0);
      uVar7 = 0xffffffff;
      break;
    }
    func_0x030037a8(0xc9);
    local_50 = 0x38;
    local_4e = 0x82;
    local_4c = 1;
    local_4a = 0;
    local_48 = 1;
    FUN_02ff26a4(DAT_030191b8,DAT_030191d8,&local_50);
    uVar6 = 0xb8;
LAB_03019150:
    func_0x030037a8(uVar6);
    break;
  case 0x131:
  case 0x132:
  case 0x133:
  case 0x134:
  case 0x135:
  case 0x136:
  case 0x137:
    FUN_030176fe(param_2);
    break;
  case 0x138:
    FUN_02ff26a4(DAT_030191b8,DAT_030191c8,0);
    func_0x030037a8(0xb8);
    break;
  case 0x139:
  case 0x13a:
  case 0x13b:
  case 0x13c:
  case 0x13d:
    FUN_03017710(param_2);
    break;
  case 0x140:
  case 0x141:
  case 0x142:
  case 0x143:
  case 0x144:
  case 0x145:
    FUN_03017724(param_2);
    break;
  case 0x147:
  case 0x148:
  case 0x149:
  case 0x14a:
    FUN_0301777e(param_2);
    break;
  case 0x14c:
    *DAT_030191ac = 0;
    *DAT_030191b0 = 4;
    FUN_02ff26a4(DAT_030191b8,DAT_030191b4,0);
    func_0x030037a8(0xb8);
    break;
  case 0x14d:
    *DAT_030191ac = 0;
    *DAT_030191b0 = 0;
    FUN_02ff26a4(DAT_030191b8,DAT_030191b4,0);
    func_0x030037a8(0xb8);
    break;
  case 0x14f:
  case 0x150:
  case 0x151:
  case 0x152:
  case 0x153:
  case 0x154:
  case 0x155:
  case 0x156:
    *(undefined1 *)(DAT_030191a8 + 0x356) = uVar1;
    break;
  case 0x158:
  case 0x159:
  case 0x15a:
  case 0x15b:
  case 0x15c:
    *(undefined1 *)(DAT_030191a8 + 0x34f) = uVar1;
    thunk_FUN_03000e32();
    break;
  case 0x15e:
  case 0x15f:
  case 0x160:
  case 0x161:
  case 0x162:
  case 0x163:
  case 0x164:
  case 0x165:
  case 0x166:
  case 0x167:
  case 0x168:
  case 0x169:
  case 0x16a:
  case 0x16b:
  case 0x16c:
  case 0x16d:
  case 0x16e:
  case 0x16f:
  case 0x170:
  case 0x171:
  case 0x172:
  case 0x1ab:
  case 0x1ac:
  case 0x1ad:
  case 0x1ae:
  case 0x1af:
  case 0x1b0:
  case 0x1b1:
  case 0x1b2:
  case 0x1b3:
  case 0x1b4:
  case 0x1b5:
  case 0x1b6:
  case 0x1b7:
  case 0x1b8:
  case 0x1b9:
  case 0x1ba:
  case 0x1bb:
  case 0x1bc:
  case 0x1bd:
  case 0x1be:
  case 0x1bf:
    FUN_030176e8(param_2);
    break;
  case 0x173:
  case 0x174:
    func_0x030037a8(0xb8);
    break;
  case 0x175:
    FUN_03017ba0(param_2);
    FUN_030191e4();
    break;
  case 0x176:
    uVar6 = 2;
    goto LAB_03018f98;
  case 0x177:
    uVar6 = 4;
LAB_03018f98:
    func_0x03004284(uVar6);
    break;
  case 0x1a1:
    func_0x030037a8(0xb8);
    *DAT_030191d4 = uVar1;
    local_30[0] = 1;
    FUN_030039d2(0xc,local_30);
    uVar7 = 1;
  }
  if (*DAT_030191dc == 0xff) {
    *DAT_030191e0 = (short)param_2;
  }
  FUN_03008eec(1);
  return uVar7;
}


