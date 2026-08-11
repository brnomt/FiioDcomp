/**
 * FUN_030b033e @ 0x030b033e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b033e(undefined4 param_1,int param_2,uint param_3,uint *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  
  if (*(int *)(param_2 + 0x7c) == *(int *)(param_2 + 0x74) && *(uint *)(param_2 + 0x90) == 1) {
    iVar1 = 1;
    *param_4 = param_3;
  }
  else {
    uVar9 = 0;
    uVar7 = 1;
    puVar8 = *(uint **)(DAT_030b03dc + 0x34);
    uVar2 = *puVar8;
    uVar3 = puVar8[1];
    uVar2 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18;
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    do {
      uVar4 = uVar3;
      if (uVar7 < *(uint *)(param_2 + 0x90)) {
        uVar7 = uVar7 + 1;
        uVar3 = puVar8[uVar7 * 3 + -3];
        uVar6 = puVar8[uVar7 * 3 + -2];
        uVar5 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
        iVar1 = uVar5 - uVar2;
        uVar2 = uVar5;
        uVar3 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
      }
      else {
        uVar5 = *(int *)(param_2 + 0x74) + 1;
        iVar1 = uVar5 - uVar2;
        uVar3 = uVar4;
      }
      uVar9 = uVar4 * iVar1 + uVar9;
    } while (uVar9 < param_3);
    uVar2 = (uVar9 - param_3) / uVar4;
    iVar1 = uVar4 - ((uVar9 - param_3) - uVar4 * uVar2);
    *param_4 = (uVar5 - uVar2) - 1;
  }
  *param_5 = iVar1;
  return;
}


