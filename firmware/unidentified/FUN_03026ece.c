/**
 * FUN_03026ece @ 0x03026ece
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026ece(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined1 local_138 [256];
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  undefined1 local_28;
  
  uVar5 = mp3_bitstream_getbits(0x10);
  iVar2 = DAT_030273d4;
  iVar1 = DAT_030273d0;
  if (uVar5 < 2) {
    return 0xffffff36;
  }
  uVar5 = uVar5 - 2;
  while( true ) {
    if (uVar5 == 0) {
      return 0;
    }
    uVar6 = mp3_bitstream_getbits(8);
    local_38 = local_38 & 0xffffff00;
    iVar8 = 0;
    iVar9 = 1;
    do {
      bVar3 = mp3_bitstream_getbits(8);
      *(byte *)((int)&local_38 + iVar9) = bVar3;
      iVar9 = iVar9 + 1;
      iVar8 = iVar8 + (uint)bVar3;
    } while (iVar9 < 0x11);
    if (0xff < iVar8) {
      return 0xffffff38;
    }
    iVar9 = 0;
    if (0 < iVar8) {
      do {
        uVar4 = mp3_bitstream_getbits(8);
        local_138[iVar9] = uVar4;
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar8);
    }
    if (uVar5 < iVar8 + 0x11U) {
      return 0xffffff36;
    }
    uVar5 = uVar5 - (iVar8 + 0x11U);
    if ((0x10 < (uVar6 & 0x10)) ||
       (iVar8 = (uVar6 & 0xf) + ((int)(uVar6 << 0x1b) >> 0x1f) * -4, 7 < iVar8)) {
      return 0xffffff37;
    }
    puVar7 = (uint *)(iVar8 * 0x11 + iVar1);
    bVar10 = puVar7 == (uint *)0x0;
    if (!bVar10) {
      iVar8 = iVar2 + iVar8 * 0x100;
      bVar10 = iVar8 == 0;
    }
    if (bVar10) break;
    *puVar7 = local_38;
    puVar7[1] = local_34;
    puVar7[2] = local_30;
    puVar7[3] = local_2c;
    *(undefined1 *)(puVar7 + 4) = local_28;
    FUN_02ff89c2(iVar8,local_138,0x100);
  }
  return 0xffffff23;
}


