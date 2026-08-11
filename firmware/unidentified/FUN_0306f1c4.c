/**
 * FUN_0306f1c4 @ 0x0306f1c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306f1c4(int *param_1,int param_2)

{
  if (*(short *)(param_2 + 0x3c) == 0x201) {
    if (*param_1 == 0) {
      *param_1 = 1;
    }
    else {
      FUN_0306f378();
    }
    return 0x20;
  }
  return 0;
}


