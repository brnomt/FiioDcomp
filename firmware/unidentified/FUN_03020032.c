/**
 * FUN_03020032 @ 0x03020032
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03020032(uint *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = DAT_03020420;
  if ((*param_1 & 0xffffff) >> 0x10 != 1) {
    return 0xfffffffc;
  }
  FUN_02ff6420(DAT_03020420,200);
  puVar1[7] = 0;
  param_1[3] = (uint)puVar1;
  puVar1[0x19] = param_1[1];
  uVar2 = param_1[2];
  puVar1[0x22] = 0;
  puVar1[0x1a] = uVar2;
  puVar1[0x2a] = 0;
  puVar1[0x2b] = 0;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0;
  puVar1[0x30] = 0;
  puVar1[0x23] = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  *puVar1 = 1;
  puVar1[4] = 1;
  puVar1[0x17] = 0xffff;
  iVar3 = 0;
  if (puVar1[0x19] != 0) {
    iVar3 = puVar1[0x1a];
  }
  uVar2 = (uint)(puVar1[0x19] != 0 && iVar3 != 0);
  puVar1[0x18] = uVar2;
  if (uVar2 != 0) {
    puVar1[0x1d] = puVar1[0x19] + 0xf >> 4;
    puVar1[0x1e] = puVar1[0x1a] + 0xf >> 4;
    puVar1[0x1b] = puVar1[0x1d] * 0x10 + 0x80;
    puVar1[0x1c] = puVar1[0x1e] * 0x10 + 0x80;
    return 0;
  }
  return 0;
}


