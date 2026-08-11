/**
 * FUN_03009f7e @ 0x03009f7e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03009f7e(void)

{
  int iVar1;
  
  if (*(byte *)(DAT_0300a140 + 0x12) < *(byte *)(DAT_0300a140 + 0x1e)) {
    *(byte *)(DAT_0300a140 + 0x12) = *(byte *)(DAT_0300a140 + 0x12) + 1;
  }
  iVar1 = FUN_02fe6440(*DAT_0300a15c,DAT_0300a158);
  if (iVar1 == 1) {
    FUN_03021672(0xb6,0);
  }
  FUN_02ff73b4(0x33);
  return 1;
}


