/**
 * FUN_030efe92 @ 0x030efe92
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030efe92(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(byte *)(param_1 + 0x1c) & 3) != 0) {
    FUN_030f03cc(param_1,param_2,0,param_4);
    return;
  }
  FUN_030f03cc(param_1,param_2,0);
  if (1000 < *(int *)(param_1 + 0xc)) {
    FUN_030f1934(0,param_2);
    FUN_030eeeee(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    FUN_030f191c(0,param_2);
    FUN_030f188a(param_1 + 0x954,DAT_030f02dc,param_2,DAT_030f02d8);
  }
  FUN_030efd2c(param_1,param_2);
  return;
}


