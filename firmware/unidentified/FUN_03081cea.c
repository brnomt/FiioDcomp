/**
 * FUN_03081cea @ 0x03081cea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03081cea(uint param_1)

{
  uint uVar1;
  
  if (param_1 == 0xe) {
    uVar1 = *DAT_03081ea4 | 0x8000000;
  }
  else {
    if (param_1 != 0xf) {
      if (0xf < param_1) {
        *(int *)(&DAT_e000e280 + (param_1 - 0x10 >> 5) * 4) = 1 << (param_1 - 0x10 & 0x1f);
        return;
      }
      return;
    }
    uVar1 = *DAT_03081ea4 | 0x2000000;
  }
  *DAT_03081ea4 = uVar1;
  return;
}


