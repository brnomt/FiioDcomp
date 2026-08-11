/**
 * FUN_03070d34 @ 0x03070d34
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03070d34(undefined4 param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar3 = DAT_03071090;
  piVar2 = DAT_0307108c;
  if (param_3 == 0) {
    *param_2 = *param_2 * *DAT_0307108c;
    iVar7 = piVar2[1];
    iVar5 = 0x11;
    piVar3 = param_2;
    piVar4 = piVar2;
    do {
      iVar6 = piVar4[2];
      piVar3[1] = piVar3[1] * iVar7;
      piVar1 = piVar3 + 2;
      iVar7 = piVar4[3];
      piVar3 = piVar3 + 2;
      *piVar3 = *piVar1 * iVar6;
      iVar5 = iVar5 + -1;
      piVar4 = piVar4 + 2;
    } while (iVar5 != 0);
    param_2[0x23] = piVar2[0x23] * param_2[0x23];
    return;
  }
  if (param_3 == 1) {
    piVar4 = param_2 + -1;
    piVar2 = DAT_0307108c + -1;
    iVar5 = 9;
    do {
      piVar4[1] = piVar2[1] * piVar4[1];
      piVar1 = piVar4 + 2;
      piVar2 = piVar2 + 2;
      piVar4 = piVar4 + 2;
      *piVar4 = *piVar2 * *piVar1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    param_2[0x12] = param_2[0x12] << 0xc;
    param_2[0x13] = param_2[0x13] << 0xc;
    param_2[0x14] = param_2[0x14] << 0xc;
    param_2[0x15] = param_2[0x15] << 0xc;
    param_2[0x16] = param_2[0x16] << 0xc;
    param_2[0x17] = param_2[0x17] << 0xc;
    param_2[0x18] = piVar3[6] * param_2[0x18];
    param_2[0x19] = piVar3[7] * param_2[0x19];
    param_2[0x1a] = piVar3[8] * param_2[0x1a];
    param_2[0x1b] = piVar3[9] * param_2[0x1b];
    param_2[0x1c] = piVar3[10] * param_2[0x1c];
    param_2[0x1d] = piVar3[0xb] * param_2[0x1d];
    param_2[0x1e] = 0;
    param_2[0x1f] = 0;
    param_2[0x20] = 0;
    param_2[0x21] = 0;
    param_2[0x22] = 0;
    param_2[0x23] = 0;
    return;
  }
  if (param_3 == 3) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = *piVar3 * param_2[6];
    param_2[7] = piVar3[1] * param_2[7];
    param_2[8] = piVar3[2] * param_2[8];
    param_2[9] = piVar3[3] * param_2[9];
    param_2[10] = piVar3[4] * param_2[10];
    param_2[0xb] = piVar3[5] * param_2[0xb];
    param_2[0xc] = param_2[0xc] << 0xc;
    param_2[0xd] = param_2[0xd] << 0xc;
    param_2[0xe] = param_2[0xe] << 0xc;
    param_2[0xf] = param_2[0xf] << 0xc;
    param_2[0x10] = param_2[0x10] << 0xc;
    piVar3 = param_2 + 0x11;
    *piVar3 = param_2[0x11] << 0xc;
    piVar2 = piVar2 + 0x11;
    iVar5 = 9;
    do {
      iVar5 = iVar5 + -1;
      piVar3[1] = piVar3[1] * piVar2[1];
      piVar4 = piVar3 + 2;
      piVar2 = piVar2 + 2;
      piVar3 = piVar3 + 2;
      *piVar3 = *piVar4 * *piVar2;
    } while (iVar5 != 0);
    return;
  }
  return;
}


