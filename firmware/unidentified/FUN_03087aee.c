/**
 * FUN_03087aee @ 0x03087aee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03087aee(uint *param_1,int *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_3 + 0x4c) - *(int *)(*(int *)(param_3 + 4) + param_4 * 4);
  if (0x47 < iVar2) {
    iVar2 = 0x47;
  }
  iVar3 = (int)((ulonglong)((longlong)param_2[1] * (longlong)*(int *)(*DAT_03087b58 + iVar2 * 4)) >>
               0x20);
  uVar5 = iVar3 * 2;
  uVar4 = uVar5;
  if ((int)uVar5 < 0) {
    uVar4 = iVar3 * -2;
  }
  uVar1 = 0;
  if (uVar4 != 0) {
    for (; uVar4 < 0x1fffffff; uVar4 = uVar4 << 2) {
      uVar1 = uVar1 + 2;
    }
    if (uVar4 < 0x3fffffff) {
      uVar1 = uVar1 + 1;
    }
    uVar5 = uVar5 << (uVar1 & 0xff);
    uVar1 = uVar1 + *param_2 + (iVar2 >> 2) + -3;
  }
  *param_1 = uVar1;
  param_1[1] = uVar5;
  return;
}


