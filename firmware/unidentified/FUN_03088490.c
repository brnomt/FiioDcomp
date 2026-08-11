/**
 * FUN_03088490 @ 0x03088490
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03088490(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  *(undefined4 *)(param_3 + 0x3c) = 0;
  if (param_4 != 3) {
    return;
  }
  if (*(int *)(param_3 + 0x30) == 0 || param_1 == 0) {
    return;
  }
  iVar1 = 0;
  if (param_2 < 1) {
    return;
  }
  do {
    if (*(int *)(param_1 + iVar1 * 4) != 0) {
      *(undefined4 *)(param_3 + 0x3c) = 1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < param_2);
  return;
}


