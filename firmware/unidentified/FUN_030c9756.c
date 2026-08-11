/**
 * FUN_030c9756 @ 0x030c9756
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c9756(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = param_1[0x10];
  iVar1 = param_1[0x11];
  param_1[0x10] = iVar1 + iVar2;
  iVar3 = param_1[0x12];
  iVar4 = param_1[0x13];
  param_1[0x12] = iVar3 + iVar4;
  iVar5 = *param_1;
  param_1[0x11] = iVar5 + param_1[1];
  iVar6 = param_1[2];
  param_1[0x13] = iVar6 + param_1[3];
  iVar1 = iVar2 - iVar1 >> 8;
  iVar2 = iVar3 - iVar4 >> 8;
  *param_1 = iVar1 * 0x62 + iVar2 * -0xed;
  iVar3 = param_1[1] - iVar5 >> 8;
  param_1[2] = iVar1 * 0xed + iVar2 * 0x62;
  iVar1 = param_1[3] - iVar6 >> 8;
  param_1[1] = iVar1 * 0x62 + iVar3 * 0xed;
  param_1[3] = iVar1 * 0xed + iVar3 * -0x62;
  iVar2 = param_1[0x14] - param_1[0x15];
  param_1[0x14] = param_1[0x15] + param_1[0x14];
  iVar3 = param_1[0x16] - param_1[0x17];
  param_1[0x16] = param_1[0x16] + param_1[0x17];
  iVar4 = param_1[5] - param_1[4];
  param_1[0x15] = param_1[5] + param_1[4];
  iVar1 = param_1[7] - param_1[6];
  param_1[0x17] = param_1[6] + param_1[7];
  param_1[4] = (iVar2 - iVar3 >> 8) * 0xb5;
  param_1[5] = (iVar1 + iVar4 >> 8) * 0xb5;
  param_1[6] = (iVar2 + iVar3 >> 8) * 0xb5;
  param_1[7] = (iVar1 - iVar4 >> 8) * 0xb5;
  iVar1 = param_1[0x18];
  iVar3 = param_1[0x19];
  param_1[0x18] = iVar1 + iVar3;
  iVar4 = param_1[0x1a];
  iVar2 = param_1[0x1b];
  param_1[0x1a] = iVar2 + iVar4;
  iVar5 = param_1[8];
  param_1[0x19] = param_1[9] + iVar5;
  iVar6 = param_1[10];
  param_1[0x1b] = iVar6 + param_1[0xb];
  iVar1 = iVar1 - iVar3 >> 8;
  iVar2 = iVar4 - iVar2 >> 8;
  param_1[8] = iVar1 * 0xed + iVar2 * -0x62;
  iVar3 = param_1[9] - iVar5 >> 8;
  param_1[10] = iVar1 * 0x62 + iVar2 * 0xed;
  iVar1 = param_1[0xb] - iVar6 >> 8;
  param_1[9] = iVar1 * 0xed + iVar3 * 0x62;
  param_1[0xb] = iVar1 * 0x62 + iVar3 * -0xed;
  iVar1 = param_1[0x1c];
  iVar3 = param_1[0x1d];
  param_1[0x1c] = iVar1 + iVar3;
  iVar4 = param_1[0x1e];
  iVar2 = param_1[0x1f];
  param_1[0x1e] = iVar2 + iVar4;
  param_1[0x1d] = param_1[0xc] + param_1[0xd];
  iVar5 = param_1[0xf];
  param_1[0xf] = param_1[0xc] - param_1[0xd];
  param_1[0xc] = iVar1 - iVar3;
  param_1[0x1f] = param_1[0xe] + iVar5;
  param_1[0xd] = iVar5 - param_1[0xe];
  param_1[0xe] = iVar4 - iVar2;
  FUN_030c9642(param_1);
  FUN_030c9642(param_1 + 0x10);
  return;
}


