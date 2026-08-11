/**
 * FUN_03005604 @ 0x03005604
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030055f2) */
/* WARNING: Removing unreachable block (ram,0x030055ac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03005604(int param_1,undefined4 param_2,ushort param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,short param_8)

{
  undefined2 uVar1;
  short *psVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int unaff_r4;
  ushort unaff_r5;
  int unaff_r6;
  undefined4 unaff_r7;
  uint unaff_r11;
  char in_OV;
  
  *(char *)(param_1 + 0x1c) = (char)param_1;
  if (param_1 == 0) {
    uVar6 = 0;
    puVar4 = (undefined4 *)0x0;
    if (in_OV != '\0') {
      if (in_OV != '\0') {
        *(undefined4 *)(unaff_r4 + 100) = unaff_r7;
        *(int *)(unaff_r4 + 100) = unaff_r6;
      }
      _MasterStackPointer = (undefined2)unaff_r6;
      if (*(short *)(unaff_r6 * 2) == 0) {
        FUN_02fee4ba(0x18,DAT_03005a2c,0x50);
      }
      uVar3 = FUN_02fed6a6(DAT_03005a2c);
      unaff_r6 = 0xc;
      if (uVar3 < (uint)((int)param_8 - (int)(short)param_7)) {
        FUN_02ff2e26(0xae);
        goto LAB_030056ca;
      }
      unaff_r11 = 0x8c;
      puVar4 = &param_7;
      uVar6 = CONCAT22(param_7._2_2_,(short)param_7);
      param_4 = extraout_r3;
      param_3 = unaff_r5;
    }
    FUN_02fee326(puVar4,uVar6,(uint)param_3 | unaff_r6 << 0x10,
                 param_4 & 0xffff0000 | unaff_r11 & 0xffff);
  }
  FUN_02ff2de4(0xae);
LAB_030056ca:
  FUN_02feda18(&param_7,&param_7,DAT_03005a2c,0);
  psVar2 = DAT_03005a30;
  uVar3 = 0;
  do {
    uVar5 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = unaff_r5;
    uVar3 = uVar5;
  } while (uVar5 < 0x40);
  uVar3 = 0;
  do {
    uVar5 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(unaff_r4 + uVar3 * 2 + 0x25c);
    uVar3 = uVar5;
  } while (uVar5 < 0x50);
  psVar2[uVar5] = unaff_r5;
  param_7._0_2_ = 0x86;
  param_8 = 0xca;
  uVar1 = (undefined2)unaff_r7;
  param_7._2_2_ = uVar1;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a30,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a30);
  if (uVar3 < (uint)((int)param_8 - (int)(short)param_7)) {
    FUN_02ff2e26(0xaf);
  }
  else {
    FUN_02fee3a4(&param_7,CONCAT22(param_7._2_2_,(short)param_7),(uint)unaff_r5 | unaff_r6 << 0x10,
                 extraout_r3_00 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xaf);
  }
  FUN_02feda18(&param_7,&param_7,DAT_03005a30,0);
  psVar2 = DAT_03005a34;
  uVar3 = 0;
  do {
    uVar5 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = unaff_r5;
    uVar3 = uVar5;
  } while (uVar5 < 0x40);
  uVar3 = 0;
  do {
    uVar5 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(unaff_r4 + uVar3 * 2 + 0x35a);
    uVar3 = uVar5;
  } while (uVar5 < 0x50);
  psVar2[uVar5] = unaff_r5;
  param_7._0_2_ = 0xdb;
  param_8 = 0x11f;
  param_7._2_2_ = uVar1;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a34,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a34);
  if (uVar3 < (uint)((int)param_8 - (int)(short)param_7)) {
    FUN_02ff2e26(0xb0);
  }
  else {
    FUN_02fee43c(&param_7,CONCAT22(param_7._2_2_,(short)param_7),(uint)unaff_r5 | unaff_r6 << 0x10,
                 extraout_r3_01 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xb0);
  }
  FUN_02feda18(&param_7,&param_7,DAT_03005a34,0);
  FUN_02fee544(2);
  return;
}


