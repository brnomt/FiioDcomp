/**
 * FUN_030c7af0 @ 0x030c7af0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c7af0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  }
  return uVar1;
}


