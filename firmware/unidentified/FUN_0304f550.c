/**
 * FUN_0304f550 @ 0x0304f550
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0304f550(int param_1,int param_2)

{
  if (param_1 != 0 && param_2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0;
    FUN_0304f366(param_1,0,*(undefined4 *)(param_1 + 0x14),param_2);
    return 1;
  }
  return 0;
}


