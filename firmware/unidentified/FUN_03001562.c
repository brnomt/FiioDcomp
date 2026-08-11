/**
 * FUN_03001562 @ 0x03001562
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001562(short *param_1)

{
  uint uVar1;
  
  if (*param_1 != 0) {
    return;
  }
  uVar1 = 0;
  do {
    if (param_1[uVar1] != 0) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x80);
  if (uVar1 == 0x80) {
    FUN_02feb762(0x18,param_1,0x80);
    *DAT_0300166c = 1;
    return;
  }
  return;
}


