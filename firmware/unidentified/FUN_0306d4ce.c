/**
 * FUN_0306d4ce @ 0x0306d4ce
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306d4ce(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if (uVar2 < 0x7f) {
    return 0;
  }
  if (uVar2 < 0x97) {
    return uVar1 >> (0x96 - uVar2 & 0xff);
  }
  return uVar1 << (uVar2 - 0x96 & 0xff);
}


