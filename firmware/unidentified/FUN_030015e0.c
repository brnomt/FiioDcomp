/**
 * FUN_030015e0 @ 0x030015e0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030015e0(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  uint uVar1;
  undefined2 *unaff_r5;
  undefined2 *puVar2;
  int in_r12;
  char in_ZR;
  
  if (in_ZR == '\0') {
    in_ZR = in_r12 == 4;
  }
  if (in_ZR == '\0') {
    uVar1 = 0;
    puVar2 = unaff_r5;
    do {
      uVar1 = uVar1 + 1;
      unaff_r5 = puVar2 + 1;
      *puVar2 = param_3;
      puVar2 = unaff_r5;
    } while (uVar1 < 0x80);
  }
  else {
    parse_v22_frame();
  }
  FUN_02fe2a80(unaff_r5,DAT_03001ab8);
  return 0;
}


