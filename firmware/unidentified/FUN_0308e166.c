/**
 * FUN_0308e166 @ 0x0308e166
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308e166(byte *param_1,byte *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  puVar2 = &local_28;
  local_28 = *(undefined4 *)(param_3 + 0x80);
  local_24 = *(undefined4 *)(param_3 + 0x84);
  uStack_20 = *(undefined4 *)(param_3 + 0x88);
  local_1c = *(undefined4 *)(param_3 + 0x8c);
  if (param_4 == 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = 8;
    puVar2 = &uStack_20;
  }
  *(byte *)((int)&local_28 + iVar1) = *(byte *)((int)&local_28 + iVar1) ^ *param_2;
  *(byte *)((int)&local_28 + iVar1 + 1) = *(byte *)((int)&local_28 + iVar1 + 1) ^ param_2[1];
  *(byte *)((int)&local_28 + iVar1 + 2) = *(byte *)((int)&local_28 + iVar1 + 2) ^ param_2[2];
  *(byte *)((int)&local_28 + iVar1 + 3) = *(byte *)((int)&local_28 + iVar1 + 3) ^ param_2[3];
  *(byte *)((int)&local_24 + iVar1) = *(byte *)((int)&local_24 + iVar1) ^ param_2[4];
  *(byte *)((int)&local_24 + iVar1 + 1) = *(byte *)((int)&local_24 + iVar1 + 1) ^ param_2[5];
  *(byte *)((int)&local_24 + iVar1 + 2) = *(byte *)((int)&local_24 + iVar1 + 2) ^ param_2[6];
  *(byte *)((int)&local_24 + iVar1 + 3) = param_2[7] ^ *(byte *)((int)&local_24 + iVar1 + 3);
  FUN_030840d6(param_1,puVar2,param_3,param_4);
  if (param_4 == 1) {
    iVar1 = 8;
  }
  else {
    iVar1 = 0;
  }
  *param_1 = *param_1 ^ *(byte *)((int)&local_28 + iVar1);
  param_1[1] = param_1[1] ^ *(byte *)((int)&local_28 + iVar1 + 1);
  param_1[2] = param_1[2] ^ *(byte *)((int)&local_28 + iVar1 + 2);
  param_1[3] = param_1[3] ^ *(byte *)((int)&local_28 + iVar1 + 3);
  param_1[4] = param_1[4] ^ *(byte *)((int)&local_24 + iVar1);
  param_1[5] = param_1[5] ^ *(byte *)((int)&local_24 + iVar1 + 1);
  param_1[6] = param_1[6] ^ *(byte *)((int)&local_24 + iVar1 + 2);
  param_1[7] = *(byte *)((int)&local_24 + iVar1 + 3) ^ param_1[7];
  return;
}


