/**
 * FUN_030e4d98 @ 0x030e4d98
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e4d98(uint param_1)

{
  uint uVar1;
  
  if (param_1 == 0xe) {
    uVar1 = *DAT_030e4f54 | 0x8000000;
  }
  else {
    if (param_1 != 0xf) {
      if (0xf < param_1) {
        *(int *)(&DAT_e000e280 + (param_1 - 0x10 >> 5) * 4) = 1 << (param_1 - 0x10 & 0x1f);
        return;
      }
      return;
    }
    uVar1 = *DAT_030e4f54 | 0x2000000;
  }
  *DAT_030e4f54 = uVar1;
  return;
}


