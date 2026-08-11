/**
 * FUN_030e78e4 @ 0x030e78e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e78e4(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = 1;
  puVar5 = *(uint **)(DAT_030e7a7c + 0x38);
  uVar1 = *puVar5;
  uVar6 = puVar5[1];
  uVar1 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
  iVar4 = uVar1 * uVar6;
  if (uVar1 < param_3) {
    do {
      if (*(uint *)(param_2 + 0x90) <= uVar3) break;
      uVar3 = uVar3 + 1;
      uVar6 = puVar5[uVar3 * 2 + -2];
      uVar7 = puVar5[uVar3 * 2 + -1];
      uVar2 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
              uVar6 >> 0x18;
      uVar6 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
              uVar7 >> 0x18;
      uVar1 = uVar1 + uVar2;
      iVar4 = uVar2 * uVar6 + iVar4;
    } while (uVar1 < param_3);
  }
  iVar4 = iVar4 - ((uVar1 - param_3) + 1) * uVar6;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  return iVar4;
}


