/**
 * FUN_030e59fa @ 0x030e59fa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e59fa(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0x80000000;
  if (param_1 == 0) {
    return;
  }
  iVar1 = 0;
  do {
    if ((uVar2 & ~param_1) == 0) {
      return;
    }
    uVar2 = uVar2 >> 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return;
}


