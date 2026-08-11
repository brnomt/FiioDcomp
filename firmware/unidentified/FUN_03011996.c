/**
 * FUN_03011996 @ 0x03011996
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03011996(undefined1 param_1,uint param_2)

{
  uint uVar1;
  undefined1 *unaff_r4;
  undefined1 unaff_r6;
  undefined1 unaff_r8;
  int in_r12;
  
  if (param_2 < 0xe) {
    unaff_r4[8] = unaff_r8;
    uVar1 = param_2 + 1 & 0xff;
    *unaff_r4 = (char)(param_2 + 1);
    *(undefined1 *)(in_r12 + uVar1) = param_1;
    *(undefined1 *)(in_r12 + uVar1 + 1) = unaff_r6;
    FUN_03011192(1);
    FUN_02ffff38(0x33);
  }
  return;
}


