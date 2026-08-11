/**
 * FUN_030ca4d8 @ 0x030ca4d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ca4d8(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  memset_byte(DAT_030ca8e8,0,10);
  memset_byte(DAT_030ca8ec,0,0x50);
  memset_byte(param_1,0,0x1c);
  return;
}


