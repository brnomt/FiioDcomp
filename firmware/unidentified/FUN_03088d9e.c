/**
 * FUN_03088d9e @ 0x03088d9e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03088d9e(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < (short)param_2[4]) {
    uVar1 = 8 - (int)(short)param_2[4];
    if (0 < (int)uVar1) {
      iVar3 = 0;
      uVar1 = uVar1 & 7;
      iVar2 = 0;
      if (uVar1 != 0) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined1 *)((int)param_2 + iVar3 + 8 + (int)(short)param_2[4]) = 0;
          iVar3 = iVar3 + 1;
        } while (iVar2 < (int)uVar1);
      }
      if ((int)uVar1 < 8 - (short)param_2[4]) {
        do {
          *(undefined1 *)((int)param_2 + iVar3 + 8 + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 9 + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 10 + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 0xb + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 0xc + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 0xd + (int)(short)param_2[4]) = 0;
          *(undefined1 *)((int)param_2 + iVar3 + 0xe + (int)(short)param_2[4]) = 0;
          uVar1 = uVar1 + 8;
          *(undefined1 *)((int)param_2 + iVar3 + 0xf + (int)(short)param_2[4]) = 0;
          iVar3 = iVar3 + 8;
        } while ((int)uVar1 < 8 - (short)param_2[4]);
      }
    }
    iVar2 = param_2[1];
    param_2[1] = param_2[2] + iVar2;
    uVar1 = (param_2[2] + iVar2) * *param_1;
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[1];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[2];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[3];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    iVar4 = uVar1 * param_1[4];
    param_2[1] = iVar4;
    iVar4 = iVar4 + param_1[5];
    param_2[1] = iVar4;
    iVar3 = *param_2;
    *param_2 = iVar3 + iVar4;
    param_2[1] = iVar4 + param_2[3];
    uVar1 = (iVar4 + param_2[3]) * param_1[6];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[7];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[8];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    uVar1 = uVar1 * param_1[9];
    uVar1 = uVar1 >> 0x10 | uVar1 * 0x10000;
    param_2[1] = uVar1;
    iVar2 = uVar1 * param_1[10];
    param_2[1] = iVar2;
    iVar2 = param_1[0xb] + iVar2;
    param_2[1] = iVar2;
    *param_2 = iVar2 + iVar3 + iVar4;
    *(undefined2 *)(param_2 + 4) = 0;
  }
  *param_3 = param_2[1];
  return *param_2;
}


