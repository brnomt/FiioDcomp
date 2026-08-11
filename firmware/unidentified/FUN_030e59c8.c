/**
 * FUN_030e59c8 @ 0x030e59c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e59c8(int *param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  iVar3 = 0;
  do {
    uVar4 = param_1[2];
    bVar2 = *(byte *)(*param_1 + (uVar4 >> 3));
    param_1[2] = uVar4 + 1;
    bVar5 = (int)(((uint)bVar2 << (uVar4 & 7)) << 0x18) < 0;
    iVar1 = 0;
    if (bVar5) {
      iVar1 = iVar3 + -8;
      iVar3 = iVar3 + 1;
    }
  } while (iVar1 < 0 != (bVar5 && SBORROW4(iVar3,9)));
  return;
}


