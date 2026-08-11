/**
 * FUN_030640c4 @ 0x030640c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030640c4(void)

{
  int iVar1;
  uint extraout_r12;
  
  FUN_03064098();
  if (extraout_r12 < 2) {
    ID3_Picture_Parser(0,0xf,0,1);
  }
  else {
    ID3_Picture_Parser(0,0x17,0,1);
  }
  iVar1 = DAT_03064474;
  FUN_0303328e(*(undefined4 *)(DAT_03064474 + 0x18));
  FUN_030376b8(5);
  FUN_0303328a(3,*(undefined4 *)(iVar1 + 0x18));
  FUN_030376b8(5);
  FUN_0303328a(0,*(undefined4 *)(iVar1 + 0x18));
  FUN_03033580();
  return;
}


