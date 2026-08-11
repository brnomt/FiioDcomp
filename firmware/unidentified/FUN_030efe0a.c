/**
 * FUN_030efe0a @ 0x030efe0a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030efe0a(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xc) < 0x3e9) {
    return;
  }
  FUN_030f1934(0,param_4,0,param_4,param_4);
  FUN_030eeeee(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  FUN_030f191c(0,param_4);
  uVar2 = DAT_030f02dc;
  uVar1 = DAT_030f02d8;
  FUN_030f188a(param_2,DAT_030f02dc,param_4,DAT_030f02d8,param_2);
  if (param_3 == 0) {
    return;
  }
  FUN_030f1934(0,param_4,0x20000000);
  FUN_030eeeee(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  FUN_030f191c(0,param_4,0x20000000);
  FUN_030f188a(param_3,uVar2,param_4,uVar1,param_3);
  return;
}


