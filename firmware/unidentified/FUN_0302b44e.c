/**
 * FUN_0302b44e @ 0x0302b44e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0302b44e(void)

{
  int iVar1;
  
  iVar1 = DAT_0302b528;
  FUN_0302c96e(*(int *)(DAT_0302b528 + 0xc) + 4);
  *(undefined4 *)(iVar1 + 0x1ac) = 1;
  *(undefined4 *)(iVar1 + 0x1b0) = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4);
  shared_frame_epilogue_c6b4(0x106);
  return;
}


