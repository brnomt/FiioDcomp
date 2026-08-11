/**
 * FUN_030c4222 @ 0x030c4222
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c4222(uint param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 == 0;
  iVar1 = 0;
  if (!bVar2) {
    param_1 = param_1 - 1;
    bVar2 = param_1 == 0;
  }
  if (bVar2) {
    return 0;
  }
  do {
    iVar1 = iVar1 + 1;
    param_1 = param_1 >> 1;
  } while (param_1 != 0);
  return iVar1;
}


