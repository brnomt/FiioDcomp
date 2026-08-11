/**
 * FUN_0306d4ac @ 0x0306d4ac
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306d4ac(uint param_1,int param_2)

{
  if ((param_1 & 0x7fffffff) != 0) {
    if ((int)-((param_1 & 0x7fffffff) >> 0x17) < param_2) {
      return param_1 + param_2 * 0x800000;
    }
    param_1 = 0;
  }
  return param_1;
}


