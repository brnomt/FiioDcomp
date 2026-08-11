/**
 * FUN_03064098 @ 0x03064098
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03064098(int param_1)

{
  if (param_1 == 0) {
LAB_030640bc:
    *(undefined4 *)(DAT_03064474 + 0x18) = 32000;
    return;
  }
  if (param_1 != 1) {
    if (param_1 == 2) goto LAB_030640bc;
    if (param_1 != 3) {
      if (param_1 == 4) {
        *(undefined4 *)(DAT_03064474 + 0x18) = 48000;
      }
      return;
    }
  }
  *(undefined4 *)(DAT_03064474 + 0x18) = 0xac44;
  return;
}


