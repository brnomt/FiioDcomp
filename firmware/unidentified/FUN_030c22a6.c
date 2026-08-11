/**
 * FUN_030c22a6 @ 0x030c22a6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c22a6(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 < 2) {
    return 4;
  }
  if (param_2 == 3) {
    param_2 = 4;
  }
  iVar1 = 0;
  for (uVar2 = param_1 * 3 - 6; uVar2 != 0; uVar2 = uVar2 >> 1) {
    iVar1 = iVar1 + 1;
  }
  if (param_2 * 4 < iVar1 + 1) {
    return param_2;
  }
  if (param_2 + 1U < 3) {
    param_2 = 1;
  }
  else {
    param_2 = param_2 / 2;
  }
  return param_2;
}


