/**
 * FUN_030c3f8e @ 0x030c3f8e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c3f8e(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  memset_byte(DAT_030c4320,0,0x800);
  memset_byte(DAT_030c4324,0,0x400);
  memset_byte(DAT_030c4318,0,0x50);
  return;
}


