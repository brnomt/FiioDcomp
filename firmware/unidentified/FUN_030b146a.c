/**
 * FUN_030b146a @ 0x030b146a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030b146a(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_r2;
  int extraout_r3;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  
  iVar1 = DAT_030b1514;
  uVar5 = 1;
  uVar10 = *(uint *)(DAT_030b1514 + 0x70);
  if (*(uint *)(DAT_030b1514 + 0x7c) < uVar10) {
    iVar2 = -1;
  }
  else {
    puVar7 = *(uint **)(DAT_030b1518 + 0x44);
    uVar3 = *puVar7;
    uVar6 = puVar7[1];
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
            uVar6 >> 0x18;
    iVar2 = uVar3 * uVar6;
    if (uVar3 < uVar10) {
      do {
        if (*(uint *)(DAT_030b1514 + 0x94) <= uVar5) break;
        uVar5 = uVar5 + 1;
        uVar8 = puVar7[uVar5 * 2 + -2];
        uVar6 = puVar7[uVar5 * 2 + -1];
        uVar8 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
                uVar8 >> 0x18;
        uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
        uVar3 = uVar3 + uVar8;
        iVar2 = uVar8 * uVar6 + iVar2;
      } while (uVar3 < uVar10);
    }
    iVar2 = iVar2 - ((uVar3 - uVar10) + 1) * uVar6;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
  }
  uVar9 = *(undefined4 *)(DAT_030b1514 + 0xa4);
  iVar2 = FUN_030ac7ec(iVar2,0,uVar9);
  iVar4 = FUN_030ac7ec((int)((ulonglong)extraout_r2 * 1000),
                       extraout_r3 * 1000 + (int)((ulonglong)extraout_r2 * 1000 >> 0x20),uVar9,0);
  uVar5 = iVar2 * 1000 + iVar4;
  if (*(short *)(iVar1 + 0xd0) == 2) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0xb4;
  }
  if (uVar10 < uVar5) {
    uVar5 = uVar5 - uVar10;
  }
  return uVar5;
}


