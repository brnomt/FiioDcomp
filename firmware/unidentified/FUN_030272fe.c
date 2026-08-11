/**
 * FUN_030272fe @ 0x030272fe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030272fe(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  
  iVar8 = mp3_bitstream_getbits(0x10);
  iVar9 = mp3_bitstream_getbits(8);
  *DAT_030273fc = iVar9;
  iVar5 = DAT_03027404;
  iVar4 = DAT_03027400;
  iVar3 = DAT_030273e4;
  piVar2 = DAT_030273e0;
  if (((iVar9 * 2 + 3 == iVar8 + -3) && (0 < iVar9)) && (iVar9 < 5)) {
    iVar15 = 0;
    iVar8 = iVar8 + -3;
    while( true ) {
      iVar16 = iVar8;
      iVar10 = mp3_bitstream_getbits(8);
      uVar11 = mp3_bitstream_getbits(8);
      iVar13 = *piVar2;
      iVar8 = 0;
      if (0 < iVar13) {
        do {
          iVar14 = *(int *)(iVar3 + iVar8 * 4);
          bVar17 = SBORROW4(iVar14,iVar10);
          iVar1 = iVar14 - iVar10;
          if (iVar14 != iVar10) {
            iVar8 = iVar8 + 1;
            bVar17 = SBORROW4(iVar8,iVar13);
            iVar1 = iVar8 - iVar13;
          }
        } while (iVar1 < 0 != bVar17);
      }
      if (iVar13 <= iVar8) break;
      *(int *)(iVar4 + iVar15 * 4) = iVar8;
      *(uint *)(iVar5 + iVar8 * 4) = (uVar11 & 0xff) >> 4;
      iVar15 = iVar15 + 1;
      *(uint *)(DAT_03027408 + iVar8 * 4) = (uVar11 & 0xf) + 4;
      iVar8 = iVar16 + -2;
      if (iVar9 <= iVar15) {
        uVar12 = mp3_bitstream_getbits(8);
        puVar6 = DAT_0302740c;
        *DAT_0302740c = uVar12;
        uVar12 = mp3_bitstream_getbits(8);
        puVar7 = DAT_03027410;
        *DAT_03027410 = uVar12;
        uVar12 = mp3_bitstream_getbits(4);
        *DAT_03027414 = uVar12;
        uVar12 = mp3_bitstream_getbits(4);
        *DAT_03027418 = uVar12;
        *puVar6 = 0;
        *puVar7 = 0x3f;
        for (iVar16 = iVar16 + -5; iVar16 != 0; iVar16 = iVar16 + -1) {
          mp3_bitstream_getbits(8);
        }
        return 0;
      }
    }
    return 0xffffff2b;
  }
  return 0xffffff2c;
}


