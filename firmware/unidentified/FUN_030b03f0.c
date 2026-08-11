/**
 * FUN_030b03f0 @ 0x030b03f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b03f0(undefined4 param_1,int param_2,uint *param_3,uint *param_4,uint *param_5,
                 uint *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  
  if (*(int *)(param_2 + 0x7c) == *(int *)(param_2 + 0x74) && *(uint *)(param_2 + 0x90) == 1) {
    *param_4 = 1;
    *param_5 = *param_3;
    uVar1 = *param_3;
  }
  else {
    iVar8 = 0;
    uVar5 = 1;
    puVar6 = *(uint **)(DAT_030b080c + 0x34);
    uVar1 = *puVar6;
    uVar3 = puVar6[1];
    uVar1 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
            uVar1 >> 0x18;
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    do {
      uVar4 = uVar3;
      if (uVar5 < *(uint *)(param_2 + 0x90)) {
        uVar5 = uVar5 + 1;
        uVar7 = puVar6[uVar5 * 3 + -3];
        uVar3 = puVar6[uVar5 * 3 + -2];
        uVar7 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                uVar7 >> 0x18;
        iVar2 = uVar7 - uVar1;
        uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
      }
      else {
        uVar7 = *(int *)(param_2 + 0x74) + 1;
        iVar2 = uVar7 - uVar1;
        uVar3 = uVar4;
      }
      iVar8 = uVar4 * iVar2 + iVar8;
      uVar1 = uVar7;
    } while (uVar7 < *param_3);
    *param_4 = uVar4;
    uVar1 = (*param_3 - uVar7) * uVar4 + iVar8 + 1;
    *param_5 = uVar1;
    uVar1 = uVar1 + (uVar4 - 1);
  }
  *param_6 = uVar1;
  return;
}


