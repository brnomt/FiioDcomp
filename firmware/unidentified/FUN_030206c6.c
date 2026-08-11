/**
 * FUN_030206c6 @ 0x030206c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030206c6(undefined4 param_1,int param_2,uint *param_3)

{
  if (param_2 != 0) {
    return 0xffffffff;
  }
  if ((*param_3 & 0xffffff) >> 0x10 == 1) {
    CodeResume(1);
    return 0;
  }
  return 0xfffffffc;
}


