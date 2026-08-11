/**
 * FUN_030248c8 @ 0x030248c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030248c8(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_r9;
  int in_stack_0000000c;
  
  FUN_02ff8972();
  if (*(char *)(unaff_r9 + 3) == '\x03') {
    iVar2 = in_stack_0000000c * 0x1000000 + (uint)in_stack_0000000c._2_1_ * 0x100 +
            (uint)in_stack_0000000c._3_1_;
  }
  else {
    iVar2 = (uint)in_stack_0000000c._3_1_ + (in_stack_0000000c._2_1_ & 1) * 0x80;
  }
  if (0 < iVar2) {
    uVar1 = FUN_02ff89ce();
    return uVar1;
  }
  return 0xffffffff;
}


