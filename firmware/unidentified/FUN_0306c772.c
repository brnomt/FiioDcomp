/**
 * FUN_0306c772 @ 0x0306c772
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0306c772(uint param_1)

{
  uint uVar1;
  
  if (param_1 == 4) {
    uVar1 = *DAT_0306ca30 | 0x10000;
  }
  else {
    if (param_1 != 5) {
      if (param_1 == 6) {
        *DAT_0306ca30 = *DAT_0306ca30 | 0x40000;
        return;
      }
      if (param_1 == 0xf) {
        _DAT_e000e010 = _DAT_e000e010 | 2;
        return;
      }
      if (0xf < param_1) {
        *(int *)(&DAT_e000e100 + (param_1 - 0x10 >> 5) * 4) = 1 << (param_1 - 0x10 & 0x1f);
        return;
      }
      return;
    }
    uVar1 = *DAT_0306ca30 | 0x20000;
  }
  *DAT_0306ca30 = uVar1;
  return;
}


