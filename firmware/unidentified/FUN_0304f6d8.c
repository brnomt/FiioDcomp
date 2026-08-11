/**
 * FUN_0304f6d8 @ 0x0304f6d8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304f6d8(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0xffffffff) {
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != -1) {
        FUN_0304fdf0();
      }
    }
    param_1[1] = -1;
  }
  if (*param_1 == -1) {
    return;
  }
  FUN_0304ed30();
  *param_1 = -1;
  return;
}


