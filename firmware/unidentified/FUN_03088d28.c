/**
 * FUN_03088d28 @ 0x03088d28
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03088d28(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                int *param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  param_5 = param_5 - (param_3 + param_6);
  uVar2 = param_2[10] * (param_6 - *(int *)(param_1 + 0x2c));
  uVar2 = param_2[9] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  uVar2 = param_2[8] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  uVar3 = param_2[7] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  iVar1 = param_2[6];
  uVar2 = param_2[4] * (param_5 - *(int *)(param_1 + 0x14));
  uVar2 = param_2[3] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  uVar2 = param_2[2] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  uVar2 = param_2[1] * (uVar2 >> 0x10 | uVar2 * 0x10000);
  *param_7 = *param_2 * (uVar2 >> 0x10 | uVar2 * 0x10000) - param_4;
  return iVar1 * (uVar3 >> 0x10 | uVar3 * 0x10000) - param_5;
}


