/**
 * FUN_0301e6c0 @ 0x0301e6c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301e6c0(uint *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = param_2 & 3;
  puVar2 = (uint *)(param_2 - uVar3);
  param_1[4] = (uint)(puVar2 + 2);
  param_1[5] = (uint)puVar2;
  puVar1 = DAT_0301ead8;
  *DAT_0301ead8 = (uint)(uVar3 != 0);
  uVar4 = *puVar2;
  uVar5 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  *param_1 = uVar5;
  uVar4 = puVar2[1];
  param_1[1] = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
               uVar4 >> 0x18;
  uVar4 = uVar3 * 8;
  param_1[7] = uVar4;
  param_1[3] = uVar4;
  if (uVar3 != 0) {
    uVar4 = uVar5 & -1 << (uVar3 * -8 + 0x20 & 0xff);
  }
  param_1[2] = uVar4;
  *puVar1 = (uint)(param_3 < 8);
  if (param_3 >= 8) {
    param_1[6] = param_3 - 8;
  }
  return;
}


