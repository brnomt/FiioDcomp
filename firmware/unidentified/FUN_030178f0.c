/**
 * FUN_030178f0 @ 0x030178f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030178f0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStack_218 [4];
  int local_214;
  undefined1 local_20c;
  undefined1 local_208;
  undefined1 local_204;
  undefined1 local_200;
  undefined1 local_1fc;
  undefined1 local_1f0;
  undefined1 local_1ec;
  undefined1 local_1e8;
  undefined1 uStack_1e4;
  undefined1 uStack_1e0;
  undefined1 uStack_1dc;
  undefined1 uStack_1d8;
  undefined1 uStack_1d4;
  
  piVar2 = DAT_03017b24;
  func_0x03003a94(0x30000,*DAT_03017b24,0x200,auStack_218);
  func_0x03003a94(0x30000,*piVar2 + 8 + local_214 * 0x20,0x154,auStack_218);
  iVar1 = DAT_03017ae8;
  *DAT_03017af0 = local_20c;
  *(undefined1 *)(iVar1 + 0x10) = local_20c;
  *(undefined1 *)(iVar1 + 0x12) = local_208;
  *(undefined1 *)(iVar1 + 0x16) = local_204;
  *(undefined1 *)(iVar1 + 0x17) = local_200;
  func_0x030009f8();
  *(undefined1 *)(iVar1 + 0x18) = local_1fc;
  *(undefined1 *)(iVar1 + 0x2d) = 0;
  *(undefined1 *)(iVar1 + 0x1a) = 0;
  *(undefined1 *)(iVar1 + 0x1b) = 2;
  *(undefined1 *)(iVar1 + 0x6d) = local_1f0;
  *(undefined1 *)(iVar1 + 0x6f) = local_1ec;
  *(undefined1 *)(iVar1 + 0x74) = local_1e8;
  uVar6 = 0;
  do {
    iVar7 = uVar6 * 2;
    uVar6 = uVar6 + 1;
    *(undefined2 *)(iVar1 + iVar7 + 0x77) = 10;
  } while (uVar6 < 5);
  *(undefined1 *)(iVar1 + 0x358) = 0;
  func_0x030037a8(0x113);
  func_0x030037a8(0x114);
  func_0x030037a8(0x102);
  *(undefined1 *)(iVar1 + 0x1c0) = uStack_1e4;
  *(undefined1 *)(iVar1 + 0x1c1) = uStack_1e0;
  *(undefined1 *)(iVar1 + 0x216) = uStack_1dc;
  *(undefined1 *)(iVar1 + 0x219) = 2;
  *(undefined1 *)(iVar1 + 0x21a) = 1;
  *(undefined1 *)(iVar1 + 0x218) = 1;
  *(undefined1 *)(iVar1 + 0x220) = uStack_1d4;
  *(undefined1 *)(iVar1 + 0x225) = uStack_1d8;
  iVar7 = FUN_02ff2834(*DAT_03017b2c,DAT_03017b28);
  uVar3 = DAT_03017b28;
  if (iVar7 == 1) {
    *DAT_03017b30 = 0;
    FUN_02ff278c(DAT_03017b2c,uVar3);
  }
  FUN_02ff0670(DAT_03017b34,0x1000);
  iVar7 = DAT_03017b34;
  *(undefined4 *)(DAT_03017b34 + 0xfa4) = DAT_03017b38;
  *(undefined4 *)(iVar7 + 4000) = 0;
  func_0x03008e88(2,iVar7,0x1000);
  func_0x03008e88(3,DAT_03017b34,0x1000);
  *(undefined1 *)(iVar1 + 0x6c) = 0;
  *(undefined2 *)(iVar1 + 0x38) = 0;
  FUN_02fed9e4(2,7,0);
  FUN_02ff17e4(2,7,1);
  FUN_02ff181e(2,7,0);
  FUN_02fed9e4(2,0x11,0);
  FUN_02ff17e4(2,0x11,1);
  FUN_02ff181e(2,0x11,0);
  FUN_02fed9e4(2,0x10,0);
  FUN_02ff17e4(2,0x10,1);
  FUN_02ff181e(2,0x10,0);
  *(undefined1 *)(iVar1 + 0x34b) = 0;
  *(undefined1 *)(iVar1 + 0x34a) = 0;
  *(undefined1 *)(iVar1 + 0x349) = 0;
  if (0x78 < *(byte *)(iVar1 + 0x12)) {
    *(undefined1 *)(iVar1 + 0x12) = 0x1e;
  }
  *(undefined1 *)(iVar1 + 0x12) = 0x1e;
  *(undefined1 *)(iVar1 + 0x15) = 100;
  *(undefined1 *)(iVar1 + 0x13) = 0x1e;
  *(undefined1 *)(iVar1 + 0x14) = 0x28;
  *(undefined1 *)(iVar1 + 0x1e) = 0x78;
  puVar4 = DAT_03017b3c;
  *DAT_03017b3c = 0x7ea;
  *(undefined1 *)(puVar4 + 1) = 5;
  *(undefined1 *)((int)puVar4 + 3) = 0xf;
  puVar5 = DAT_03017b40;
  *DAT_03017b40 = 0xc;
  puVar5[1] = 0;
  puVar5[2] = 0;
  iVar7 = DAT_03017b44;
  *(undefined1 *)(DAT_03017b44 + 4) = 0x12;
  *(undefined1 *)(iVar7 + 3) = 0;
  *(undefined1 *)(iVar7 + 2) = 0;
  *(undefined1 *)(iVar7 + 8) = 0x26;
  *(undefined1 *)(iVar7 + 5) = 0x15;
  *(undefined1 *)(iVar7 + 7) = 5;
  *(undefined1 *)(iVar1 + 0x35c) = 0;
  *(undefined1 *)(iVar1 + 0x35d) = 0xc;
  iVar7 = FUN_02ffcda8(0);
  if (iVar7 == 0) {
    iVar7 = 0;
  }
  FUN_02ffcda8(iVar7);
  *(undefined1 *)(iVar1 + 0x1a1) = 0;
  *(undefined1 *)(iVar1 + 0x1bd) = 0;
  *(undefined1 *)(iVar1 + 0x2b) = 0;
  *(undefined1 *)(iVar1 + 0x34f) = 1;
  *(undefined1 *)(iVar1 + 0x352) = 1;
  *(undefined1 *)(iVar1 + 0x353) = 0;
  *DAT_03017f58 = 0xffff;
  *DAT_03017f5c = 0xffff;
  *DAT_03017f60 = 0x2945;
  *(undefined1 *)(iVar1 + 0x1be) = 1;
  *(undefined1 *)(iVar1 + 0x1bf) = 0;
  *(undefined1 *)(iVar1 + 0x350) = 0xb;
  *(undefined1 *)(iVar1 + 0x356) = 0;
  *(undefined1 *)(iVar1 + 0x355) = 0;
  *(undefined1 *)(iVar1 + 0x357) = 0;
  *(undefined1 *)(iVar1 + 0x359) = 1;
  *(undefined1 *)(iVar1 + 0x34c) = 0;
  *(undefined1 *)(iVar1 + 0x35a) = 0;
  *(undefined1 *)(iVar1 + 0x35e) = 1;
  return;
}


