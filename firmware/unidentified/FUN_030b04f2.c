/**
 * FUN_030b04f2 @ 0x030b04f2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030b04f2(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_2 + 0xac);
  uVar6 = 1;
  if (uVar1 == 0) {
    uVar1 = *(uint *)(param_2 + 0xb8);
  }
  if (uVar1 < param_3) {
    return *(int *)(param_2 + 0x7c) + 1;
  }
  puVar5 = *(uint **)(DAT_030b080c + 0x44);
  uVar1 = *puVar5;
  uVar3 = puVar5[1];
  uVar2 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  uVar1 = uVar2 * uVar3;
  if (uVar1 < param_3) {
    do {
      if (*(uint *)(param_2 + 0x94) <= uVar6) break;
      uVar6 = uVar6 + 1;
      uVar3 = puVar5[uVar6 * 2 + -2];
      uVar4 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
              uVar3 >> 0x18;
      uVar3 = puVar5[uVar6 * 2 + -1];
      uVar2 = uVar2 + uVar4;
      uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
              uVar3 >> 0x18;
      uVar1 = uVar4 * uVar3 + uVar1;
    } while (uVar1 < param_3);
  }
  uVar1 = (uVar2 - (uVar1 - param_3) / uVar3) + 1;
  if (*(uint *)(param_2 + 0x7c) < uVar1) {
    uVar1 = *(uint *)(param_2 + 0x7c);
  }
  return uVar1;
}


