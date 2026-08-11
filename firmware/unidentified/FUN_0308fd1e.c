/**
 * FUN_0308fd1e @ 0x0308fd1e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308fd1e(uint *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  piVar1 = DAT_03090560;
  uVar3 = (*param_2 ^ param_2[1] >> 4) & 0xf0f0f0f;
  uVar5 = *param_2 ^ uVar3;
  uVar3 = param_2[1] ^ uVar3 << 4;
  uVar7 = (uVar5 ^ uVar5 << 0x12) & DAT_0309055c;
  uVar5 = uVar5 ^ uVar7 ^ uVar7 >> 0x12;
  uVar7 = (uVar3 ^ uVar3 << 0x12) & DAT_0309055c;
  uVar3 = uVar3 ^ uVar7 ^ uVar7 >> 0x12;
  uVar7 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar5 = uVar5 ^ uVar7;
  uVar3 = uVar3 ^ uVar7 << 1;
  uVar7 = (uVar3 ^ uVar5 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar7;
  uVar5 = uVar5 ^ uVar7 << 8;
  uVar7 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar5 = uVar5 ^ uVar7;
  uVar3 = uVar3 ^ uVar7 << 1;
  uVar3 = uVar5 >> 4 & 0xf000000 |
          (uVar3 & 0xffffff) >> 0x10 | uVar3 & 0xff00 | (uVar3 & 0xff) << 0x10;
  uVar5 = uVar5 & 0xfffffff;
  uVar7 = 0;
  do {
    if ((1 << (0xf - uVar7 & 0xff) & 0x3f7eU) == 0) {
      uVar4 = uVar5 >> 1 | uVar5 << 0x1b;
      uVar6 = uVar3 >> 1 | uVar3 << 0x1b;
    }
    else {
      uVar4 = uVar5 >> 2 | uVar5 << 0x1a;
      uVar6 = uVar3 >> 2 | uVar3 << 0x1a;
    }
    uVar5 = uVar4 & 0xfffffff;
    iVar8 = *piVar1;
    uVar3 = uVar6 & 0xfffffff;
    uVar9 = *(uint *)(iVar8 + (uVar5 >> 0x15 & 6 | (uVar4 & 0x1fffff) >> 0x14 | uVar5 >> 0x16 & 0x38
                              ) * 4 + 0x300) |
            *(uint *)(iVar8 + (uVar5 >> 0xe & 0x30 | (uVar4 & 0x1ffff) >> 0xd) * 4 + 0x200) |
            *(uint *)(iVar8 + (uVar5 >> 7 & 0x3c | (uVar4 & 0xff) >> 6) * 4 + 0x100) |
            *(uint *)(iVar8 + (uVar4 & 0x3f) * 4);
    uVar7 = uVar7 + 1;
    uVar4 = *(uint *)(iVar8 + (uVar3 >> 0x16 & 0x30 | (uVar6 & 0x1ffffff) >> 0x15) * 4 + 0x700) |
            *(uint *)(iVar8 + ((uVar6 & 0x1fffff) >> 0xf) * 4 + 0x600) |
            *(uint *)(iVar8 + (uVar3 >> 8 & 0x3c | (uVar6 & 0x1ff) >> 7) * 4 + 0x500) |
            *(uint *)(iVar8 + (uVar6 & 0x3f) * 4 + 0x400);
    puVar2 = param_1 + 1;
    *param_1 = (uVar4 & 0xffff) >> 0xe | (uVar9 & 0xffff | uVar4 << 0x10) << 2;
    param_1 = param_1 + 2;
    *puVar2 = uVar4 >> 0x1a | (uVar4 & 0xffff0000 | uVar9 >> 0x10) << 6;
  } while (uVar7 < 0x10);
  return;
}


