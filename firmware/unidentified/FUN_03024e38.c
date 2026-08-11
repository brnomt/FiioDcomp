/**
 * FUN_03024e38 @ 0x03024e38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03024e38(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_r7;
  int *unaff_r8;
  int unaff_r9;
  byte bStack0000000c;
  byte bStack0000000e;
  byte bStack0000000f;
  
  if (param_1 != 0) {
    uVar1 = FUN_02ff89ce();
    return uVar1;
  }
  iVar2 = FUN_02ffcece();
  if (iVar2 == 0) {
    uVar3 = FUN_02ffce8c();
    iVar2 = FUN_02ffce8c();
    if ((uint)(iVar2 + *unaff_r8) < uVar3) {
      return unaff_r7;
    }
    uVar3 = FUN_02ffc9d6(&stack0x00000008,10);
    if (9 < uVar3) {
      FUN_02ff8972();
      if (*(char *)(unaff_r9 + 3) == '\x03') {
        iVar2 = (uint)bStack0000000c * 0x1000000 + (uint)bStack0000000e * 0x100 +
                (uint)bStack0000000f;
      }
      else {
        iVar2 = (uint)bStack0000000f + (bStack0000000e & 1) * 0x80;
      }
      if (0 < iVar2) {
        uVar1 = FUN_02ff89ce();
        return uVar1;
      }
    }
  }
  return 0xffffffff;
}


