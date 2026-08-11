/**
 * FUN_03087ab8 @ 0x03087ab8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03087ab8(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_1[1];
  uVar2 = uVar1;
  if ((int)uVar1 < 0) {
    uVar2 = -uVar1;
  }
  uVar4 = 0;
  iVar3 = 0;
  if (uVar2 != 0) {
    for (; uVar2 < 0x1fffffff; uVar2 = uVar2 << 2) {
      uVar4 = uVar4 + 2;
    }
    if (uVar2 < 0x3fffffff) {
      uVar4 = uVar4 + 1;
    }
    param_1[1] = uVar1 << (uVar4 & 0xff);
    iVar3 = *param_1 + uVar4;
  }
  *param_1 = iVar3;
  return;
}


