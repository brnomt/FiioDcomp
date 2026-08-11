/**
 * FUN_030903c0 @ 0x030903c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030903c0(int *param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  param_3[1] = 0;
  iVar1 = -((int)~param_2 / 2);
  *param_3 = 0;
  if ((int)~param_2 / 2 != 0 && -1 < iVar1) {
    do {
      iVar3 = param_3[1];
      iVar2 = *param_1;
      param_3[1] = iVar3 + iVar2;
      uVar4 = (iVar3 + iVar2) * *param_4;
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[1];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[2];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[3];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      iVar5 = uVar4 * param_4[4];
      param_3[1] = iVar5;
      iVar5 = iVar5 + param_4[5];
      param_3[1] = iVar5;
      iVar2 = *param_3;
      *param_3 = iVar2 + iVar5;
      iVar3 = param_1[1];
      param_1 = param_1 + 2;
      param_3[1] = iVar5 + iVar3;
      iVar1 = iVar1 + -1;
      uVar4 = (iVar5 + iVar3) * param_4[6];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[7];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[8];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      uVar4 = uVar4 * param_4[9];
      uVar4 = uVar4 >> 0x10 | uVar4 * 0x10000;
      param_3[1] = uVar4;
      iVar3 = uVar4 * param_4[10];
      param_3[1] = iVar3;
      iVar3 = iVar3 + param_4[0xb];
      param_3[1] = iVar3;
      *param_3 = iVar3 + iVar2 + iVar5;
    } while (iVar1 != 0);
    return;
  }
  return;
}


