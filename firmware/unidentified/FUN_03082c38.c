/**
 * FUN_03082c38 @ 0x03082c38
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03082c38(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if (uVar2 < 0x7f) {
    uVar1 = 0;
  }
  else {
    if (uVar2 < 0x97) {
      uVar1 = uVar1 >> (0x96 - uVar2 & 0xff);
    }
    else {
      uVar1 = uVar1 << (uVar2 - 0x96 & 0xff);
    }
    if ((param_1 & 0x80000000) != 0) {
      return -uVar1;
    }
  }
  return uVar1;
}


