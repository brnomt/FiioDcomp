/**
 * FUN_030840d6 @ 0x030840d6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030840d6(uint *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined1 auStack_1c [8];
  
  uVar3 = DAT_030842c8;
  uVar2 = *param_2 >> 0x1c | *param_2 << 4;
  uVar4 = (uVar2 ^ param_2[1]) & 0xf0f0f0f0;
  uVar2 = uVar2 ^ uVar4;
  uVar4 = param_2[1] ^ uVar4;
  uVar4 = uVar4 >> 0xc | uVar4 << 0x14;
  uVar1 = (uVar2 ^ uVar4) & 0xfff0000f;
  uVar2 = uVar2 ^ uVar1;
  uVar4 = uVar4 ^ uVar1;
  uVar4 = uVar4 >> 0x12 | uVar4 << 0xe;
  uVar1 = (uVar2 ^ uVar4) & 0x33333333;
  uVar2 = uVar2 ^ uVar1;
  uVar4 = uVar4 ^ uVar1;
  uVar2 = uVar2 >> 10 | uVar2 << 0x16;
  uVar1 = (uVar2 ^ uVar4) & DAT_030842c8;
  uVar2 = uVar2 ^ uVar1;
  uVar4 = uVar4 ^ uVar1;
  local_28 = uVar2 >> 0x17 | uVar2 << 9;
  uVar2 = (local_28 ^ uVar4) & 0xaaaaaaaa;
  local_28 = local_28 ^ uVar2;
  uVar4 = uVar4 ^ uVar2;
  local_24 = uVar4 >> 0x1f | uVar4 << 1;
  local_20 = local_28;
  if (param_4 == 0) {
    FUN_03084004(&local_24,&local_20,0x1e,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0x1c,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,0x1a,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0x18,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,0x16,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0x14,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,0x12,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0x10,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,0xe,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0xc,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,10,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,8,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,6,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,4,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_24,&local_20,2,auStack_1c,&local_28,param_3);
    FUN_03084004(&local_20,&local_24,0,auStack_1c,&local_28,param_3);
  }
  uVar2 = local_20 >> 1 | local_20 << 0x1f;
  uVar4 = (local_24 ^ uVar2) & 0xaaaaaaaa;
  local_24 = local_24 ^ uVar4;
  uVar2 = uVar2 ^ uVar4;
  uVar4 = local_24 >> 9 | local_24 << 0x17;
  uVar3 = (uVar2 ^ uVar4) & uVar3;
  uVar2 = uVar2 ^ uVar3;
  uVar4 = uVar4 ^ uVar3;
  uVar4 = uVar4 >> 0x16 | uVar4 << 10;
  uVar3 = (uVar2 ^ uVar4) & 0x33333333;
  uVar2 = uVar2 ^ uVar3;
  uVar4 = uVar4 ^ uVar3;
  uVar2 = uVar2 >> 0xe | uVar2 << 0x12;
  uVar3 = (uVar2 ^ uVar4) & 0xfff0000f;
  uVar2 = uVar2 ^ uVar3;
  uVar3 = uVar3 ^ uVar4;
  uVar2 = uVar2 >> 0x14 | uVar2 << 0xc;
  uVar4 = (uVar2 ^ uVar3) & 0xf0f0f0f0;
  *param_1 = (uVar3 ^ uVar4) >> 4 | uVar3 << 0x1c;
  param_1[1] = uVar2 ^ uVar4;
  return;
}


