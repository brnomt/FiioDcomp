/**
 * FUN_0300986e @ 0x0300986e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300986e(int param_1)

{
  int iVar1;
  
  FUN_02ff73f6(0xdf);
  FUN_02ff73f6(0xe0);
  FUN_02ff73b4(0x82);
  iVar1 = FUN_02fe6440(*DAT_030098d4,DAT_030098d0);
  if (iVar1 == 1) {
    FUN_02fe6398(DAT_030098d4,DAT_030098d0);
  }
  FUN_02fe15f0(2,2,0);
  FUN_02fe53f0(2,2,1);
  FUN_02fe542a(2,2,1);
  if (param_1 == 0) {
    return;
  }
  if (*(short *)(param_1 + 2) != 1) {
    return;
  }
  FUN_02ff73b4(0xa7);
  return;
}


