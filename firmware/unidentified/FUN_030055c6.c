/**
 * FUN_030055c6 @ 0x030055c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x0300566c) */

void FUN_030055c6(void)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  short sStack_30;
  undefined2 uStack_2e;
  short sStack_2c;
  undefined2 uStack_2a;
  
  DAT_0301d728 = 1;
                    /* WARNING: Read-only address (ram,0x0301d750) is written */
  uRam0301d750 = 0x132;
  FUN_02fee544(1);
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    *(undefined2 *)(uVar4 * 2 + 0x301e7c8) = 0;
    iVar1 = DAT_03005a28;
    uVar4 = uVar3;
  } while (uVar3 < 0x40);
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    *(undefined2 *)(uVar4 * 2 + 0x301e7c8) = *(undefined2 *)(iVar1 + uVar4 * 2 + 0x15e);
    uVar4 = uVar3;
  } while (uVar3 < 0x50);
  *(undefined2 *)(uVar3 * 2 + 0x301e7c8) = 0;
  uStack_2a = 0x8f;
  sStack_2c = 0x76;
  uStack_2e = 0x84;
                    /* WARNING: Read-only address (ram,0x0301d750) is written */
  sStack_30 = 0x32;
  uVar4 = FUN_02fed6a6(DAT_03005a2c);
  if (uVar4 < (uint)((int)sStack_2c - (int)sStack_30)) {
    FUN_02ff2e26(0xae);
  }
  else {
    FUN_02fee326(&sStack_30,CONCAT22(uStack_2e,sStack_30),0xc0000,extraout_r3 & 0xffff0000 | 0x8c,
                 DAT_03005a2c,0x1e);
    FUN_02ff2de4(0xae);
  }
  FUN_02feda18(&sStack_30,&sStack_30,DAT_03005a2c,0);
  psVar2 = DAT_03005a30;
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    psVar2[uVar4] = 0;
    uVar4 = uVar3;
  } while (uVar3 < 0x40);
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    psVar2[uVar4] = *(short *)(iVar1 + uVar4 * 2 + 0x25c);
    uVar4 = uVar3;
  } while (uVar3 < 0x50);
  psVar2[uVar3] = 0;
  sStack_30 = 0x86;
  sStack_2c = 0xca;
  uStack_2e = 0x84;
  uStack_2a = 0x8f;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a30,0x50);
  }
  uVar4 = FUN_02fed6a6(DAT_03005a30);
  if (uVar4 < (uint)((int)sStack_2c - (int)sStack_30)) {
    FUN_02ff2e26(0xaf);
  }
  else {
    FUN_02fee3a4(&sStack_30,CONCAT22(uStack_2e,sStack_30),0xc0000,extraout_r3_00 & 0xffff0000 | 0x8c
                 ,DAT_03005a30,0x1e);
    FUN_02ff2de4(0xaf);
  }
  FUN_02feda18(&sStack_30,&sStack_30,DAT_03005a30,0);
  psVar2 = DAT_03005a34;
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    psVar2[uVar4] = 0;
    uVar4 = uVar3;
  } while (uVar3 < 0x40);
  uVar4 = 0;
  do {
    uVar3 = uVar4 + 1 & 0xffff;
    psVar2[uVar4] = *(short *)(iVar1 + uVar4 * 2 + 0x35a);
    uVar4 = uVar3;
  } while (uVar3 < 0x50);
  psVar2[uVar3] = 0;
  sStack_30 = 0xdb;
  sStack_2c = 0x11f;
  uStack_2e = 0x84;
  uStack_2a = 0x8f;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a34,0x50);
  }
  uVar4 = FUN_02fed6a6(DAT_03005a34);
  if (uVar4 < (uint)((int)sStack_2c - (int)sStack_30)) {
    FUN_02ff2e26(0xb0);
  }
  else {
    FUN_02fee43c(&sStack_30,CONCAT22(uStack_2e,sStack_30),0xc0000,extraout_r3_01 & 0xffff0000 | 0x8c
                 ,DAT_03005a34,0x1e);
    FUN_02ff2de4(0xb0);
  }
  FUN_02feda18(&sStack_30,&sStack_30,DAT_03005a34,0);
  FUN_02fee544(2);
  return;
}


