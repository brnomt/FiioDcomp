/**
 * FUN_030196c0 @ 0x030196c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030196c0(uint param_1)

{
  if (*(byte *)(DAT_030196e0 + 0x6f) != param_1) {
    *(char *)(DAT_030196e0 + 0x6f) = (char)param_1;
    func_0x030037a8(0x114);
  }
  return 0;
}


