/**
 * FUN_030057ac @ 0x030057ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030057ac(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint extraout_r3;
  int unaff_r4;
  ushort unaff_r5;
  int unaff_r6;
  undefined2 unaff_r7;
  int in_r12;
  short sStack00000008;
  undefined2 uStack0000000a;
  short sStack0000000c;
  
  while( true ) {
    param_1 = param_1 & 0xffff;
    *(undefined2 *)(param_3 + in_r12 * 2) = *(undefined2 *)(param_4 + 0x35a);
    if (0x4f < param_1) break;
    param_4 = unaff_r4 + param_1 * 2;
    in_r12 = param_1 + param_2;
    param_1 = param_1 + 1;
  }
  *(ushort *)(param_3 + (param_1 + param_2) * 2) = unaff_r5;
  sStack00000008 = 0xdb;
  sStack0000000c = 0x11f;
  uStack0000000a = unaff_r7;
  if (*(short *)(param_3 + param_2 * 2) == 0) {
    FUN_02fee4ba(0x18,DAT_03005a34,0x50);
  }
  uVar1 = FUN_02fed6a6(DAT_03005a34);
  if (uVar1 < (uint)((int)sStack0000000c - (int)sStack00000008)) {
    FUN_02ff2e26(0xb0);
  }
  else {
    FUN_02fee43c(&stack0x00000008,CONCAT22(uStack0000000a,sStack00000008),
                 (uint)unaff_r5 | unaff_r6 << 0x10,extraout_r3 & 0xffff0000 | 0x8c);
    FUN_02ff2de4(0xb0);
  }
  FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03005a34,0);
  FUN_02fee544(2);
  return;
}


