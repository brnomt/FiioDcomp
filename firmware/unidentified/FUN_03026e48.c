/**
 * FUN_03026e48 @ 0x03026e48
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026e48(void)

{
  int iVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar4 = mp3_bitstream_getbits(0x10);
  iVar1 = DAT_030273cc;
  if (uVar4 < 2) {
    return 0xffffff35;
  }
  uVar4 = uVar4 - 2;
  while( true ) {
    if (uVar4 == 0) {
      return 0;
    }
    uVar5 = mp3_bitstream_getbits(8);
    if (3 < (uVar5 & 0xf)) {
      return 0xffffff34;
    }
    iVar8 = iVar1 + (uVar5 & 0xf) * 0x80;
    if (iVar8 == 0) {
      return 0xffffff23;
    }
    iVar7 = 0;
    do {
      sVar2 = mp3_bitstream_getbits(8);
      if ((int)uVar5 >> 4 != 0) {
        sVar3 = mp3_bitstream_getbits(8);
        sVar2 = sVar3 + sVar2 * 0x100;
      }
      *(short *)(iVar8 + iVar7 * 2) = sVar2;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    uVar6 = 0x41;
    if ((int)uVar5 >> 4 != 0) {
      uVar6 = 0x81;
    }
    if (uVar4 < uVar6) break;
    uVar4 = uVar4 - uVar6;
  }
  return 0xffffff25;
}


