/**
 * FUN_03082cea @ 0x03082cea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03082cea(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) {
    iVar2 = ((param_2 & 0x7fffffff) >> 0x14) - 0x380;
    if (0 < iVar2) {
      uVar1 = (param_1 >> 0x1d | (param_2 & 0xfffff) << 3) + (param_2 & 0x80000000) +
              iVar2 * 0x800000;
      if (-1 < (int)(param_1 * 8)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      if ((param_1 & 0xfffffff) == 0) {
        uVar1 = uVar1 & 0xfffffffe;
      }
      return uVar1;
    }
  }
  return 0;
}


