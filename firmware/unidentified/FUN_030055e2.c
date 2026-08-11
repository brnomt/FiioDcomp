/**
 * FUN_030055e2 @ 0x030055e2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030055e2(void)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int unaff_r6;
  short sStack00000008;
  undefined2 uStack0000000a;
  short sStack0000000c;
  undefined2 uStack0000000e;
  
  uVar3 = 0;
  do {
    iVar5 = uVar3 + unaff_r6;
    uVar3 = uVar3 + 1 & 0xffff;
    *(undefined2 *)(iVar5 * 2 + 0x301e7c8) = 0;
    iVar5 = DAT_03005a28;
  } while (uVar3 < 0x40);
  uVar3 = 0;
  do {
    iVar1 = uVar3 * 2;
    iVar6 = uVar3 + unaff_r6;
    uVar3 = uVar3 + 1 & 0xffff;
    *(undefined2 *)(iVar6 * 2 + 0x301e7c8) = *(undefined2 *)(iVar5 + iVar1 + 0x15e);
  } while (uVar3 < 0x50);
  *(undefined2 *)((uVar3 + unaff_r6) * 2 + 0x301e7c8) = 0;
  sStack00000008 = 0x32;
  sStack0000000c = 0x76;
  uStack0000000a = 0x84;
  uStack0000000e = 0x8f;
  if (*(short *)(unaff_r6 * 2 + 0x301e7c8) == 0) {
    FUN_02fee4ba(0x18,DAT_03005a2c,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a2c);
  if (uVar3 < (uint)((int)sStack0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xae);
  }
  else {
    FUN_02fee326(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),0xc0000,
                 extraout_r3 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xae);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a2c,0);
  psVar2 = DAT_03005a30;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = 0;
    uVar3 = uVar4;
  } while (uVar4 < 0x40);
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(iVar5 + uVar3 * 2 + 0x25c);
    uVar3 = uVar4;
  } while (uVar4 < 0x50);
  psVar2[uVar4] = 0;
  sStack00000008 = 0x86;
  sStack0000000c = 0xca;
  uStack0000000a = 0x84;
  uStack0000000e = 0x8f;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a30,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a30);
  if (uVar3 < (uint)((int)sStack0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xaf);
  }
  else {
    FUN_02fee3a4(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),0xc0000,
                 extraout_r3_00 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xaf);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a30,0);
  psVar2 = DAT_03005a34;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = 0;
    uVar3 = uVar4;
  } while (uVar4 < 0x40);
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(iVar5 + uVar3 * 2 + 0x35a);
    uVar3 = uVar4;
  } while (uVar4 < 0x50);
  psVar2[uVar4] = 0;
  sStack00000008 = 0xdb;
  sStack0000000c = 0x11f;
  uStack0000000a = 0x84;
  uStack0000000e = 0x8f;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a34,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a34);
  if (uVar3 < (uint)((int)sStack0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xb0);
  }
  else {
    FUN_02fee43c(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),0xc0000,
                 extraout_r3_01 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xb0);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a34,0);
  FUN_02fee544(2);
  return;
}


