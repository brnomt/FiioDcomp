/**
 * FUN_030b048e @ 0x030b048e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030b048e(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = 1;
  if (*(uint *)(param_2 + 0x7c) < param_3) {
    return -1;
  }
  puVar4 = *(uint **)(DAT_030b080c + 0x44);
  uVar1 = *puVar4;
  uVar6 = puVar4[1];
  uVar1 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
  iVar3 = uVar1 * uVar6;
  if (uVar1 < param_3) {
    do {
      if (*(uint *)(param_2 + 0x94) <= uVar2) break;
      uVar2 = uVar2 + 1;
      uVar6 = puVar4[uVar2 * 2 + -2];
      uVar7 = puVar4[uVar2 * 2 + -1];
      uVar5 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
              uVar6 >> 0x18;
      uVar6 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
              uVar7 >> 0x18;
      uVar1 = uVar1 + uVar5;
      iVar3 = uVar5 * uVar6 + iVar3;
    } while (uVar1 < param_3);
  }
  iVar3 = iVar3 - ((uVar1 - param_3) + 1) * uVar6;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  return iVar3;
}


