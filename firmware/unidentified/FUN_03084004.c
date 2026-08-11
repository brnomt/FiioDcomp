/**
 * FUN_03084004 @ 0x03084004
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03084004(uint *param_1,uint *param_2,int param_3,uint *param_4,uint *param_5,int param_6)

{
  int *piVar1;
  uint uVar2;
  
  *param_5 = *(uint *)(param_6 + param_3 * 4);
  *param_4 = *(uint *)(param_6 + param_3 * 4 + 4);
  *param_5 = *param_5 ^ *param_2;
  *param_4 = (*param_2 ^ *param_4) >> 4 | (*param_2 ^ *param_4) << 0x1c;
  piVar1 = DAT_030842c4;
  uVar2 = *param_1 ^ *(uint *)(*DAT_030842c4 + ((byte)*param_5 & 0xfc));
  *param_1 = uVar2;
  uVar2 = *(uint *)(((byte)*param_4 & 0xfc) + *piVar1 + 0x100) ^ uVar2;
  *param_1 = uVar2;
  uVar2 = uVar2 ^ *(uint *)((*param_5 >> 8 & 0xfc) + *piVar1 + 0x200);
  *param_1 = uVar2;
  uVar2 = uVar2 ^ *(uint *)((*param_4 >> 8 & 0xfc) + *piVar1 + 0x300);
  *param_1 = uVar2;
  uVar2 = uVar2 ^ *(uint *)((*param_5 >> 0x10 & 0xfc) + *piVar1 + 0x400);
  *param_1 = uVar2;
  uVar2 = uVar2 ^ *(uint *)((*param_4 >> 0x10 & 0xfc) + *piVar1 + 0x500);
  *param_1 = uVar2;
  uVar2 = uVar2 ^ *(uint *)((*param_5 >> 0x18 & 0xfc) + *piVar1 + 0x600);
  *param_1 = uVar2;
  *param_1 = uVar2 ^ *(uint *)(*piVar1 + (*param_4 >> 0x18 & 0xfc) + 0x700);
  return;
}


