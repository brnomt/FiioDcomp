/**
 * FUN_030055e8 @ 0x030055e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_030055e8(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  ushort unaff_r5;
  undefined4 unaff_r7;
  char in_OV;
  short sStack00000008;
  undefined2 uStack0000000a;
  short in_stack_0000000c;
  
  param_1 = param_1 * 0x1000;
  *(undefined4 *)(param_1 + 100) = unaff_r7;
  *(undefined1 **)(param_1 + 100) = &stack0x000000f0;
  if (param_1 != 0 && param_1 < 0 == (bool)in_OV) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *param_2 = (short)&stack0x000000f0;
  if (param_2[(int)&stack0x000000f0] == 0) {
    FUN_02fee4ba(0x18,DAT_03005a2c,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a2c);
  if (uVar3 < (uint)((int)in_stack_0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xae);
  }
  else {
    FUN_02fee326(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),unaff_r5 | 0xc0000,
                 extraout_r3 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xae);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a2c,0);
  psVar2 = DAT_03005a30;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = unaff_r5;
    uVar3 = uVar4;
  } while (uVar4 < 0x40);
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(param_1 + uVar3 * 2 + 0x25c);
    uVar3 = uVar4;
  } while (uVar4 < 0x50);
  psVar2[uVar4] = unaff_r5;
  sStack00000008 = 0x86;
  in_stack_0000000c = 0xca;
  uVar1 = (undefined2)unaff_r7;
  uStack0000000a = uVar1;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a30,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a30);
  if (uVar3 < (uint)((int)in_stack_0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xaf);
  }
  else {
    FUN_02fee3a4(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),unaff_r5 | 0xc0000,
                 extraout_r3_00 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xaf);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a30,0);
  psVar2 = DAT_03005a34;
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = unaff_r5;
    uVar3 = uVar4;
  } while (uVar4 < 0x40);
  uVar3 = 0;
  do {
    uVar4 = uVar3 + 1 & 0xffff;
    psVar2[uVar3] = *(short *)(param_1 + uVar3 * 2 + 0x35a);
    uVar3 = uVar4;
  } while (uVar4 < 0x50);
  psVar2[uVar4] = unaff_r5;
  sStack00000008 = 0xdb;
  in_stack_0000000c = 0x11f;
  uStack0000000a = uVar1;
  if (*psVar2 == 0) {
    FUN_02fee4ba(0x18,DAT_03005a34,0x50);
  }
  uVar3 = FUN_02fed6a6(DAT_03005a34);
  if (uVar3 < (uint)((int)in_stack_0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xb0);
  }
  else {
    FUN_02fee43c(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),unaff_r5 | 0xc0000,
                 extraout_r3_01 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xb0);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a34,0);
  FUN_02fee544(2);
  return;
}


