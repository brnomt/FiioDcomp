/**
 * FUN_03016e48 @ 0x03016e48
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03016e48(undefined4 param_1)

{
  int iVar1;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  
  if (*(short *)(unaff_r6 + 4) == 0xff) {
    if (**(short **)(unaff_r8 + 0x10) == 0xf6) {
      *(undefined1 *)(unaff_r7 + 0x74) = *(undefined1 *)(unaff_r6 + 8);
      func_0x030037a8(0x102);
    }
    else if (**(short **)(unaff_r8 + 0x10) == 0x138) {
      *(undefined1 *)(unaff_r7 + 0x17) = *(undefined1 *)(unaff_r6 + 0xc);
      func_0x030009f8();
    }
    iVar1 = *(int *)(unaff_r6 + 0x10) + -1;
    *(int *)(unaff_r6 + 0x10) = iVar1;
    *(undefined2 *)(DAT_03016f90 + iVar1 * 0x14 + 0xc) = *(undefined2 *)(unaff_r6 + 6);
    func_0x030037a8(199);
    return param_1;
  }
  iVar1 = func_0x030037c4(0xb8);
  if (iVar1 != 0) {
    *(int *)(unaff_r6 + 0x10) = *(int *)(unaff_r6 + 0x10) + -1;
    func_0x030037a8(0xcb);
    return param_1;
  }
  if (**(short **)(unaff_r8 + 0x10) == 0xf6) {
    *(undefined1 *)(unaff_r7 + 0x74) = *(undefined1 *)(unaff_r6 + 8);
    func_0x030037a8(0x102);
  }
  else if (**(short **)(unaff_r8 + 0x10) == 0x138) {
    *(undefined1 *)(unaff_r7 + 0x17) = *(undefined1 *)(unaff_r6 + 0xc);
    func_0x030009f8();
  }
  if (*(int *)(unaff_r6 + 0x10) == 0) {
    param_1 = 1;
  }
  else {
    *(int *)(unaff_r6 + 0x10) = *(int *)(unaff_r6 + 0x10) + -2;
    func_0x030037a8(199);
  }
  return param_1;
}


