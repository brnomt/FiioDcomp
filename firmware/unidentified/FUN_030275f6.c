/**
 * FUN_030275f6 @ 0x030275f6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030275f6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r3;
  int extraout_r3_00;
  int iVar1;
  ushort *extraout_r3_01;
  undefined4 *extraout_r3_02;
  
  iVar1 = DAT_03027874;
  if (*(int *)(DAT_03027874 + 0x58) == 0x10) {
    FUN_030275ea((*(uint *)(DAT_03027874 + 0x54) & 0xffffff) >> 0x10);
    iVar1 = extraout_r3;
    param_2 = extraout_r1;
    param_3 = extraout_r2;
  }
  if (7 < *(int *)(iVar1 + 0x58)) {
    FUN_030275ea(*(uint *)(iVar1 + 0x54) >> 0x18);
    iVar1 = extraout_r3_00;
    param_2 = extraout_r1_00;
    param_3 = extraout_r2_00;
  }
  FUN_030275ea(*(undefined1 *)(iVar1 + 0x54),param_2,param_3,(undefined1 *)(iVar1 + 0x54));
  FUN_030275ea(*extraout_r3_01 >> 8);
  extraout_r3_02[1] = 0x10;
  *extraout_r3_02 = 0;
  FUN_03027592(0x10);
  FUN_03027592(0x10);
  return;
}


