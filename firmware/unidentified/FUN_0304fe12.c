/**
 * FUN_0304fe12 @ 0x0304fe12
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined1 FUN_0304fe12(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if (param_1 != 0) {
    param_2 = *(int *)(param_1 + 0x1c);
  }
  if (param_1 != 0 && param_2 != 0) {
    uVar1 = *(undefined1 *)(param_1 + 4);
  }
  else {
    uVar1 = 0xf3;
  }
  return uVar1;
}


