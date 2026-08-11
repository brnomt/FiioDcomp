/**
 * FUN_030cb9fc @ 0x030cb9fc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030cb9fc(int param_1)

{
  if (*(int *)(param_1 + 0x68) == 5) {
    FUN_030c3f8e(*(undefined4 *)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x68) = 3;
  }
  else if (*(int *)(param_1 + 0x68) < 3) {
    return 0;
  }
  FUN_030c7b12(param_1 + 0x30);
  FUN_030c7ab4(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x68) = 2;
  return 0;
}


