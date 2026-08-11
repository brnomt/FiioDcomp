/**
 * FUN_0302489c @ 0x0302489c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302489c(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint unaff_r6;
  undefined4 unaff_r7;
  byte bStack0000000c;
  byte bStack0000000e;
  byte bStack0000000f;
  
  iVar1 = FUN_02ffce8c();
  iVar4 = DAT_03024a2c;
  if ((uint)(iVar1 + *DAT_03024a28) < unaff_r6) {
    return unaff_r7;
  }
  uVar2 = FUN_02ffc9d6(&stack0x00000008,10);
  if (9 < uVar2) {
    FUN_02ff8972();
    if (*(char *)(iVar4 + 3) == '\x03') {
      iVar4 = (uint)bStack0000000c * 0x1000000 + (uint)bStack0000000e * 0x100 + (uint)bStack0000000f
      ;
    }
    else {
      iVar4 = (uint)bStack0000000f + (bStack0000000e & 1) * 0x80;
    }
    if (0 < iVar4) {
      uVar3 = FUN_02ff89ce();
      return uVar3;
    }
  }
  return 0xffffffff;
}


