/**
 * FUN_030173e8 @ 0x030173e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030173e8(int param_1)

{
  undefined4 uVar1;
  int unaff_r4;
  undefined1 unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  
  if (param_1 == 0 || param_1 == 5) {
    func_0x030037a8(199);
  }
  FUN_0301575e();
  func_0x030037a8(0x1dc);
  *(undefined1 *)(unaff_r7 + 0x357) = unaff_r6;
  if (*(int *)(unaff_r8 + 0x10) == 1) {
    *(uint *)(unaff_r8 + 0x14) = (uint)*(ushort *)(unaff_r4 + 4);
  }
  uVar1 = FUN_03016c1a(*(undefined2 *)
                        (*(int *)(unaff_r4 + 0x10) + unaff_r9 + (uint)*(ushort *)(unaff_r4 + 10) * 2
                        ));
  func_0x030037a8(0xcd);
  return uVar1;
}


