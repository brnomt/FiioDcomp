/**
 * FUN_0301b398 @ 0x0301b398
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301b398(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(short *)(param_2 + 0x3c) == 0x201) {
    if (*param_1 == 0) {
      *param_1 = 1;
    }
    else {
      FUN_0301c35e();
    }
    uVar1 = 0x20;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


